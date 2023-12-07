#!/usr/bin/perl
#
# vxddef2hdr.pl <basename>
#
# example:
#
# vxddef2hdr.pl dev_vxd_dev_vmm
#
# to compile dev_vxd_dev_vmm.vxdcalls and dev_vxd_dev_vmm.vxddef
#
# spits header to stdout
use Data::Dumper;

my $basename = shift @ARGV;
die "Need basename" unless defined($basename);

my $defname = "$basename.vxddef";
die "Missing vxddef" unless -f $defname;

my $callsname = "$basename.vxdcalls";
# not required to exist

my $section = undef;

# what to gather (header)
my $vxddevname = undef;
my $deviceid = undef;
my $minwinver = undef;
my $description = "";

my $maxnamelen = 0;

# read def
open(DEF,"<",$defname) || die "Unable to open vxddef";

# read header
while (my $line = <DEF>) {
    chomp $line;
    $line =~ s/^[ \t]*//; # eat leading whitespace
    $line =~ s/[ \t]*#.*$//; # eat comments
    $line =~ s/[ \t]*$//; # eat trailing whitespace
    next if $line eq "";

    if ($line =~ s/^%[ \t]*//) {
        $section = lc($line); # s/// modified it in place
        last if $section eq "endheader";
        next;
    }

    if ($section eq "header") {
        my @a = split(/[ \t]+/,$line);

        next if @a == 0;

        $try = lc($a[0]);
        if ($try eq "vxddevname") {
            $vxddevname = $a[1];
            die "invalid VXD name $vxddevname" unless $vxddevname =~ m/^[a-zA-Z0-9]+$/i;
        }
        elsif ($try eq "deviceid") {
            $deviceid = $a[1];
            die "invalid VXD device ID $deviceid" unless ($deviceid =~ m/^0x[0-9a-fA-F]+$/i && length($deviceid) <= (2+4)); # 0xABCD
        }
        elsif ($try eq "minwinver") {
            $minwinver = $a[1];
            die "invalid min win ver $minwinver" unless $minwinver =~ m/^[34]\.[0-9]+$/;
        }
        elsif ($try eq "description") {
            $description .= "\n" if $description ne "";
            for ($i=1;$i < @a;$i++) {
                $description .= " " if $i > 1;
                $description .= $a[$i];
            }
        }
    }
}

# required field verification
die "Missing header fields. Required: VXDDEVNAME, DEVICEID, and MINWINVER" unless (defined($vxddevname) && defined($deviceid) && defined($minwinver));

$x = length($vxddevname."_Device_ID");
$maxnamelen = $x if $maxnamelen < $x;

# VXD calls
if (open(CALLS,"<",$callsname)) {
    while (my $line = <CALLS>) {
        chomp $line;

# 3.0+     0001H 0000H  Get_VMM_Version
# version  dev   serv   name
        my @a = split(/[ \t]+/,$line);
        next if @a < 3; # name is optional

        die "invalid win ver $a[0] in call" unless $a[0] =~ m/^[34]\.[0-9]+\+{0,1}$/i;

        die "invalid dev $a[1] in call" unless $a[1] =~ m/^[0-9a-fA-F]{4}H$/i;

        die "invalid srv $a[2] in call" unless $a[2] =~ m/^[0-9a-fA-F]{4}H$/i;

        if (defined($a[3]) && $a[3] ne "") {
            die "invalid name $a[3] in call" unless $a[3] =~ m/^[0-9a-zA-Z_]{1,128}$/i;
        }

        $x = $a[1];
        $x =~ s/H$//i; # remove trailing H
        $x = "0x".$x;
        die "dev $x does not match $deviceid" unless lc($x) eq lc($deviceid);

        my @x;

        $x = $a[2];
        $x =~ s/H$//i; # remove trailing H
        $x = "0x".$x;
        $a[2] = $x;

        $a[3] = "" unless defined($a[3]);

        push(@x,$a[0]);
        push(@x,$a[2]);
        push(@x,$a[3]);

        $x = length($vxddevname."_snr_".$a[3]);
        $maxnamelen = $x if $maxnamelen < $x;

        push(@calls,\@x);
    }
    close(CALLS);
}

my $padname = 8;
$maxnamelen += $padname;

sub reg2gccspec($) {
    my $v = shift @_;

    return "\@ccz" if $v =~ m/^zf$/i;
    return "\@ccnz" if $v =~ m/^\!zf$/i;

    return "\@ccc" if $v =~ m/^cf$/i;
    return "\@ccnc" if $v =~ m/^\!cf$/i;

    return "a" if $v =~ m/^(al|ax|eax)$/i;
    return "b" if $v =~ m/^(bl|bx|ebx)$/i;
    return "c" if $v =~ m/^(cl|cx|ecx)$/i;
    return "d" if $v =~ m/^(dl|dx|edx)$/i;
    return "S" if $v =~ m/^(si|esi)$/i;
    return "D" if $v =~ m/^(di|edi)$/i;
    return "ebp" if $v =~ m/^(bp|ebp)$/i;

    return "";
}

sub reg2type($) {
    my $v = shift @_;

    $v =~ s/^\!//; # remove !

    return "_Bool" if $v =~ m/^(zf|cf)$/i;

    return "uint8_t" if $v =~ m/^(al|ah|bl|bh|cl|ch|dl|dh)$/i;

    return "uint16_t" if $v =~ m/^(ax|bx|cx|dx|si|di|bp)$/i;

    return "uint32_t" if $v =~ m/^(eax|ebx|ecx|edx|esi|edi|ebp)$/i;

    return "uint32_t" if $v =~ m/^__cdecl/i;

    return "unsigned int";
}

print "/* auto-generated from $defname, do not edit. */\n";
print "#pragma once\n";
print "\n";

if ($description ne "") {
    my @a = split(/\n/,$description);

    my $maxcol = 0;

    for ($i=0;$i < @a;$i++) {
        $len = length($a[$i]);
        $maxcol = $len if $maxcol < $len;
    }

    for ($i=0;$i < @a;$i++) {
        print "/* ".substr($a[$i].(' ' x $maxcol),0,$maxcol)." */\n";
    }

    print "\n";
}

print "/* VXD device ID. Combine with service call ID when using VMMCall/VMMJmp */\n";
$x = $vxddevname."_Device_ID".(' ' x $maxnamelen);
print "#define ".substr($x,0,$maxnamelen)." ".$deviceid."\n";
print "\n";

if (@calls > 0) {
    print "/* VXD services (total: ".@calls.", ".sprintf("0x%04X",@calls - 1).") */\n";
    for ($i=0;$i < @calls;$i++) {
        my $r = $calls[$i];
        my @ar = @{$r};

        if ($ar[2] ne "") {
            $x = $vxddevname."_snr_".$ar[2].(' ' x $maxnamelen);
            print "#define ".substr($x,0,$maxnamelen)."     ".$ar[1]."    ";
        }
        else {
            $x = "no name".(' ' x $maxnamelen);
            print "/*      ".substr($x,0,$maxnamelen)."     ".$ar[1]." */ ";
        }

        print "/* ver $ar[0] */";

        print "\n";
    }

    print "\n";
}

print "/* NOTE: Some VxD calls are defined static inline to return a struct. As long as you simply read the */\n";
print "/*       structure members, GCC's optimizer will boil it down to direct register access of the values */\n";
print "/*       returned by the call and direct testing of the CPU flags. */\n";
print "\n";

print "/* NOTE: Some VxD calls may be listed as 'asynchronous', which is Microsoft's term to mean a VxD call */\n";
print "/*       that can be safely called from a hardware (asynchronous) interrupt. Non-asynchronous calls are */\n";
print "/*       not reentrant and can cause problems if called in a reentrant manner. */\n";
print "\n";

# function defs
print "#if defined(__GNUC__) /* GCC only, for now */\n";
print "# if defined(GCC_INLINE_ASM_SUPPORTS_cc_OUTPUT) /* we require GCC 6.1 or higher with support for CPU flags as output */\n";
my %funcdef;
while (my $line = <DEF>) {
    chomp $line;
    $oline = $line;
    $line =~ s/^[ \t]*//; # eat leading whitespace
    $line =~ s/[ \t]*#.*$//; # eat comments
    $line =~ s/[ \t]*$//; # eat trailing whitespace

    if ($section eq "defcode") {
    }
    else {
        next if $line eq "";
    }

    if ($line =~ s/^%[ \t]*//) {
        $was_section = $section;
        $section = lc($line); # s/// modified it in place

        if ($section eq "enddef" && $was_section eq "defcode") {
            print "/*-------------------------------------------------------------*/\n";
            print "\n";
        }
        elsif ($section eq "enddef" && $was_section eq "defconstenum") {
            print "/*-------------------------------------------------------------*/\n";
            if (exists($funcdef{description})) {
                my $maxcol = 0;
                my @b = split(/\n/,$funcdef{description});
                print "/* description: */\n";

                for ($i=0;$i < @b;$i++) {
                    $len = length($b[$i]);
                    $maxcol = $len if $maxcol < $len;
                }

                for ($i=0;$i < @b;$i++) {
                    print "/*   ".substr($b[$i].(' ' x $maxcol),0,$maxcol)." */\n";
                }
            }

            if (exists($funcdef{bf})) {
                my @cord = split(/ +/,$funcdef{bforder});

                my $maxconst = 0;

                for ($i=0;$i < @cord;$i++) {
                    $const = $cord[$i];
                    $length = length($const);
                    $maxconst = $length if $maxconst < $length;
                }

                for ($i=0;$i < @cord;$i++) {
                    $const = $cord[$i];
                    $pvalue = $value = $funcdef{bf}{$const};
                    $ovalue = $value = $funcdef{bfo}{$const};
                    $valshift = $funcdef{bfshift}{$const};
                    $comment = $funcdef{bfcomment}{$const};

                    if ($pvalue > 0xFFFFFFFF) {
                        $psuffix = "ULL";
                    }
                    elsif (($pvalue << $valshift) > 0xFFFFFFFF) {
                        $psuffix = "ULL";
                    }
                    else {
                        $psuffix = "UL";
                    }

                    print "#define ".substr($const.(' 'x$maxconst),0,$maxconst)." ".sprintf("0x%08X",$pvalue << $valshift).$psuffix." ";
                    print "/* $ovalue ";
                    print " << $valshift " if $valshift > 0;
                    print "$comment " if (defined($comment) && $comment ne '');
                    print "*/";
                    print "\n";
                }
            }

            print "\n";

            # start again
            undef %funcdef;
        }
        elsif ($section eq "enddef" && $was_section eq "defconstbitfield") {
            print "/*-------------------------------------------------------------*/\n";
            if (exists($funcdef{description})) {
                my $maxcol = 0;
                my @b = split(/\n/,$funcdef{description});
                print "/* description: */\n";

                for ($i=0;$i < @b;$i++) {
                    $len = length($b[$i]);
                    $maxcol = $len if $maxcol < $len;
                }

                for ($i=0;$i < @b;$i++) {
                    print "/*   ".substr($b[$i].(' ' x $maxcol),0,$maxcol)." */\n";
                }
            }

            if (exists($funcdef{bf})) {
                my @cord = split(/ +/,$funcdef{bforder});

                my $maxconst = 0;

                for ($i=0;$i < @cord;$i++) {
                    $const = $cord[$i];
                    $length = length($const);

                    my $suffix = undef;
                    if (exists($funcdef{bitdefsuffix})) {
                        $suffix = $funcdef{bitdefsuffix}{$const};
                    }
                    $suffix = '' unless defined($suffix);
                    $length += length($suffix);

                    $maxconst = $length if $maxconst < $length;
                }

                for ($i=0;$i < @cord;$i++) {
                    $const = $cord[$i];
                    $bitpos = $funcdef{bf}{$const};
                    $bitwidth = $funcdef{bfwidth}{$const};
                    $comment = $funcdef{bfcomment}{$const};
                    $bitval = $funcdef{bfval}{$const};

                    die "Invalid $bitwidth == 0" if $bitwidth == 0;
                    die "Bit value out of range, $bitval > ".((1 << $bitwidth) - 1) if $bitval > ((1 << $bitwidth) - 1);

                    $suffix = "U";
                    $suffix = "UL" if (($bitwidth+$bitpos) >= 32);

                    if ($bitwidth > 2) {
                        $bwstr = sprintf("0x%X",$bitval).$suffix;
                    }
                    else {
                        $bwstr = $bitval.$suffix;
                    }

                    if ($suffix eq "UL") {
                        $bvalue = sprintf("0x%016X",$bitval << $bitpos).$suffix;
                    }
                    else {
                        $bvalue = sprintf("0x%08X",$bitval << $bitpos).$suffix;
                    }

                    print "#define ".substr($const.(' 'x$maxconst),0,$maxconst)." $bvalue ";
                    print "/* $bwstr << $bitpos".$suffix." ";
                    if ($bitwidth > 1) {
                        print "bits[".($bitpos+$bitwidth-1).":".$bitpos."] ";
                    }
                    else {
                        print "bit[".$bitpos."] ";
                    }
                    print "$comment " if (defined($comment) && $comment ne '');
                    print "*/";
                    print "\n";

                    my $suffix = undef;
                    if (exists($funcdef{bitdefsuffix})) {
                        $suffix = $funcdef{bitdefsuffix}{$const};
                    }
                    $suffix = '' unless defined($suffix);

                    if ($suffix ne '') {
                        print "#define ".substr($const.$suffix.(' 'x$maxconst),0,$maxconst)." $bitpos";
                        print "\n";
                    }
                }
            }

            print "\n";

            # start again
            undef %funcdef;
        }
        elsif ($section eq "enddef" && $was_section eq "defcall") {
            #print Dumper(\%funcdef);

            # check: we allow '.' as an output struct member IF it's the only output
            if (exists($funcdef{struct})) {
                my %x = %{$funcdef{struct}};

                if (exists($x{'.'})) {
                    die "only one output allowed if default '.' output is defined" if (scalar(keys %x) > 1);
                }
            }

            # okay, generate the code
            my $serviceid = undef;
            my $funcname = undef;
            my $winver = undef;
            if (exists($funcdef{byname})) {
                $funcname = $funcdef{byname};

                for ($i=0;$i < @calls;$i++) {
                    my $r = $calls[$i];
                    my @ar = @{$r};

                    if ($ar[2] eq $funcname) {
                        $serviceid = $ar[1];
                        $winver = $ar[0];
                        last;
                    }
                }

                die "cannot locate service id for $funcname" unless defined($serviceid);
            }
            else {
                die "Cannot determine name for function";
            }

            # emit
            print "/*-------------------------------------------------------------*/\n";
            print "/* $vxddevname $funcname (VMMCall dev=$deviceid serv=$serviceid) ";
            print "WINVER=$winver " if (defined($winver) && $winver ne '');
            print "*/\n";
            print "\n";
            if (exists($funcdef{description})) {
                my $maxcol = 0;
                my @b = split(/\n/,$funcdef{description});
                print "/* description: */\n";

                for ($i=0;$i < @b;$i++) {
                    $len = length($b[$i]);
                    $maxcol = $len if $maxcol < $len;
                }

                for ($i=0;$i < @b;$i++) {
                    print "/*   ".substr($b[$i].(' ' x $maxcol),0,$maxcol)." */\n";
                }

                print "\n";
            }
            if (exists($funcdef{in})) {
                my %f = %{$funcdef{in}};
                print "/* inputs: */\n";

                my @pord = split(/ +/,$funcdef{paramorder});

                for ($i=0;$i < @pord;$i++) {
                    $key = $pord[$i];
                    $value = $f{$key};

                    print "/*   ".uc($key)." = ".$value." ";
                    if (exists($funcdef{incomment})) {
                        if (exists($funcdef{incomment}{$key})) {
                            print "(".$funcdef{incomment}{$key}.") ";
                        }
                    }
                    print "*/\n";
                }
                print "\n";
            }
            else {
                print "/* inputs: */\n";
                print "/*   None */\n";
                print "\n";
            }
            if (exists($funcdef{out})) {
                my %f = %{$funcdef{out}};
                print "/* outputs: */\n";
                while (($key,$value) = each %f) {
                    if ($value eq '.') {
                        print "/*   ".uc($key)." = ";
                        if (exists($funcdef{outcomment})) {
                            if (exists($funcdef{outcomment}{$key})) {
                                print $funcdef{outcomment}{$key}." ";
                            }
                        }
                        print "*/\n";
                    }
                    else {
                        print "/*   ".uc($key)." = ".$value." ";
                        if (exists($funcdef{outcomment})) {
                            if (exists($funcdef{outcomment}{$key})) {
                                print "(".$funcdef{outcomment}{$key}.") ";
                            }
                        }
                        print "*/\n";
                    }
                }
                print "\n";
            }
            else {
                print "/* outputs: */\n";
                print "/*   None */\n";
                print "\n";
            }

            if (exists($funcdef{return})) {
                my @f = split(/\n/,$funcdef{return});
                print "/* returns: */\n";
                for ($i=0;$i < @f;$i++) {
                    print "/*   ".$f[$i]." */\n";
                }
                print "\n";
            }

            if (exists($funcdef{async})) {
                my $maxcol = 0;
                my @b = split(/\n/,$funcdef{async});
                print "/* asynchronous: */\n";

                for ($i=0;$i < @b;$i++) {
                    $len = length($b[$i]);
                    $maxcol = $len if $maxcol < $len;
                }

                for ($i=0;$i < @b;$i++) {
                    print "/*   ".substr($b[$i].(' ' x $maxcol),0,$maxcol)." */\n";
                }

                print "\n";
            }

            $gccindex = 0;
            my $params = "void";
            if (exists($funcdef{in})) {
                my %f = %{$funcdef{in}};
                my $fc = 0;

                my @pord = split(/ +/,$funcdef{paramorder});

                for ($i=0;$i < @pord;$i++) {
                    $key = $pord[$i];
                    $value = $f{$key};

                    $params = "" if $fc == 0;

                    $ptype = $funcdef{paramtype}{$value};
                    if (defined($ptype) && $ptype ne "") {
                        $ptype = $ptype." const";
                    }
                    else {
                        $ptype = reg2type($key)." const";
                    }

                    $params .= "," unless $params eq "";
                    $params .= $ptype." ".$value."/*".$key."*/";

                    $fc++;
                }
            }

            $directreg = 0;
            my $rettype = "void";
            if (exists($funcdef{out})) {
                if (exists($funcdef{struct}{'.'})) {
                    $ptype = $funcdef{structtype}{'.'};
                    if (defined($ptype) && $ptype ne "") {
                        $ptype = $ptype;
                    }
                    else {
                        $ptype = reg2type($funcdef{struct}{'.'});
                    }

                    $gccindex++; # %0, %1, etc. count outputs too

                    $rettype = $ptype;
                    $directreg = 1;
                }
                else {
                    # declare a struct of the same name, as return value.
                    # GCC is smart enough to optimize access to members down
                    # to direct register access.
                    $structname = $funcname."__response";
                    $directreg = 0;

                    print "typedef struct $structname {\n";

                    my @sord = split(/ +/,$funcdef{structorder});

                    my %f = %{$funcdef{struct}};
                    for ($i=0;$i < @sord;$i++) {
                        $key = $sord[$i];
                        $value = $f{$key};

                        $ptype = $funcdef{structtype}{$key};
                        if (defined($ptype) && $ptype ne "") {
                            $ptype = $ptype;
                        }
                        else {
                            $ptype = reg2type($value);
                        }

                        $gccindex++; # %0, %1, etc. count outputs too

                        print "    ".$ptype;
                        print " ".$key;
                        print "; /* ".uc($value)." */";
                        print "\n";
                    }

                    print "} $structname;\n";
                    print "\n";

                    $rettype = $structname;
                }
            }

            print "static inline $rettype $funcname($params) {\n";
            if ($rettype ne "void") {
                print "    register $rettype r;\n";
                print "\n";
            }
            print "    __asm__ (\n";

            my $cdecl_base = $gccindex;
            my $cdecl_pop = 0;

            if (exists($funcdef{in})) {
                my %f = %{$funcdef{in}};

                my @pushes = ( );
                my @pord = split(/ +/,$funcdef{paramorder});

                my @cdeclv = ( );
                if (exists($funcdef{cdecl})) {
                    @cdeclv = split(/ +/,$funcdef{cdecl});
                }

                for ($i=0;$i < @pord;$i++) {
                    $key = $pord[$i];
                    $value = $f{$key};

                    if ($key =~ m/^__cdecl/) {
                        push(@pushes,"push %".$gccindex);
                        $cdecl_pop += 4;

                        # also validate that the order matches what was given in the "cdecl" directive
                        die "cdecl input order must match cdecl specification. ".$cdeclv[$gccindex-$cdecl_base]." vs ".$value if $cdeclv[$gccindex-$cdecl_base] ne $value;

                        $gccindex++;
                    }
                }

                # NTS: __cdecl pushes parameters right to left
                #
                #    a b c
                #
                #    becomes
                #
                #    push c
                #    push b
                #    push a
                for ($i=@pushes-1;$i >= 0;$i--) {
                    $what = $pushes[$i];
                    print "        \"$what\\n\"\n";
                }
            }
 
            print "        VXD_AsmCall(".$vxddevname."_Device_ID,".$vxddevname."_snr_".$funcname.")\n";

            if ($cdecl_pop > 0) {
                print "        \"addl \$".$cdecl_pop.",%%esp\\n\"\n";
            }

            print "        : /* outputs */";
            if ($directreg) {
                print " \"=".reg2gccspec($funcdef{struct}{'.'})."\" (r)";
            }
            elsif (exists($funcdef{out})) {
                my %f = %{$funcdef{out}};
                $fc = 0;
                while (($key,$value) = each %f) {
                    print "," if $fc > 0;
                    print " \"=".reg2gccspec($key)."\" (r.$value)";
                    $fc++;
                }
            }
            print "\n";

            print "        : /* inputs */";
            if (exists($funcdef{in})) {
                my %f = %{$funcdef{in}};
                my $fc = 0;

                my @pord = split(/ +/,$funcdef{paramorder});

                for ($i=0;$i < @pord;$i++) {
                    $key = $pord[$i];
                    $value = $f{$key};

                    print "," if $fc > 0;

                    if ($key =~ m/^__cdecl/) {
                        print " \"g\" ($value)";
                        $cdecl_base++;
                    }
                    else {
                        print " \"".reg2gccspec($key)."\" ($value)";
                    }

                    $fc++;
                }
            }
            print "\n";

            print "        : /* clobbered */";
            print "\n";
 
            print "    );\n";

            if ($rettype ne "void") {
                print "\n";
                print "    return r;\n";
            }

            print "}\n";

            print "\n";

            # start again
            undef %funcdef;
        }
        elsif ($section eq "defcall" || $section eq "defconstbitfield" || $section eq "defconstenum") {
        }
        elsif ($section eq "defcode") {
            print "/*-------------------------------------------------------------*/\n";
        }
        else {
            die "I don't know section $section from $was_section";
        }

        next;
    }

    if ($section eq "defcode") {
        print "$oline\n";
    }
    elsif ($section eq "defconstenum") {
        my @a = split(/[ \t]+/,$line);

        next if @a < 1;

        if ($a[0] eq "def") {
            $i = index($line,';');
            my $comment = '';
            if ($i >= 0) {
                $comment = substr($line,$i+1);
                $comment =~ s/^[ \t]+//;
                $line = substr($line,0,$i);
            }
            my @a = split(/[ \t]+/,$line);

            if (!exists($funcdef{bf})) {
                $funcdef{bf} = { };
            }
            if (!exists($funcdef{bforder})) {
                $funcdef{bforder} = "";
            }

            # def constant value [shift or 0 if not given]
            # def constant bitpos [bitwidth, or 1 if not given]
            my $constname = $a[1];
            my $value = $a[2];
            my $valshift = 0;
            $valshift = $a[3] if (defined($a[3]) && $a[3] ne '');

            die "invalid constant $constname" unless $constname =~ m/^[0-9a-zA-Z_]+$/i;
            die "invalid value $value" unless ($value eq '' || $value =~ m/^[0-9a-fA-Fx]+$/i);
            die "invalid valueshift $valshift" unless ($valshift eq '' || $valshift =~ m/^\d+$/i);
            $valshift = 0 if $valshift eq '';
            $valshift = int($valshift + 0);

            $ovalue = $value;

            if ($value eq '') {
                $value = $funcdef{nextenum};
                $value = 0 if (!defined($value) || $value eq '');
                $ovalue = $value;
            }
            elsif ($value =~ m/^0/) {
                $value = oct($value);
            }
            else {
                $value = int($value);
            }

            $funcdef{nextenum} = $value + 1;

            die "$constname already defined" if exists($funcdef{bf}{$constname});

            $funcdef{bforder} .= ' ' if $funcdef{bforder} ne '';
            $funcdef{bforder} .= $constname;

            $funcdef{bf}{$constname} = $value;
            $funcdef{bfo}{$constname} = $ovalue;
            $funcdef{bfcomment}{$constname} = $comment;
            $funcdef{bfshift}{$constname} = $valshift;
        }
        elsif ($a[0] eq "description") {
            if (exists($funcdef{description})) {
                $funcdef{description} .= "\n";
            }
            else {
                $funcdef{description} = "";
            }

            for ($i=1;$i < @a;$i++) {
                $funcdef{description} .= " " if $i > 1;
                $funcdef{description} .= $a[$i];
            }
        }
        else {
            die "Don't know what $a[0] is";
        }
    }
    elsif ($section eq "defconstbitfield") {
        my @a = split(/[ \t]+/,$line);

        next if @a < 1;

        if ($a[0] eq "def") {
            $i = index($line,';');
            my $comment = '';
            if ($i >= 0) {
                $comment = substr($line,$i+1);
                $comment =~ s/^[ \t]+//;
                $line = substr($line,0,$i);
            }
            my @a = split(/[ \t]+/,$line);

            if (!exists($funcdef{bf})) {
                $funcdef{bf} = { };
            }
            if (!exists($funcdef{bforder})) {
                $funcdef{bforder} = "";
            }
            if (!exists($funcdef{bitdefsuffix})) {
                $funcdef{bitdefsuffix} = { };
            }

            # def constant bitpos [bitwidth, or 1 if not given]
            my $constname = $a[1];
            my $bitpos = $a[2];
            my $bitwidth = 1;
            my $bitval = undef;
            $bitwidth = $a[3] if (defined($a[3]) && $a[3] ne '');
            $bitval = $a[4] if (defined($a[4]) && $a[4] ne '');

            die "invalid constant $constname" unless $constname =~ m/^[0-9a-zA-Z_]+$/i;
            die "invalid bitpos $bitpos" unless $bitpos =~ m/^\d+$/i;
            die "invalid bitwidth $bitwidth" unless ($bitwidth eq '' || $bitwidth =~ m/^\d+$/i);
            $bitwidth = 1 if $bitwidth eq '';
            $bitwidth = int($bitwidth + 0);
            $bitpos = int($bitpos + 0);

            $bitval = ((1 << $bitwidth) - 1) unless defined($bitval);

            die "$constname already defined" if exists($funcdef{bf}{$constname});

            $funcdef{bforder} .= ' ' if $funcdef{bforder} ne '';
            $funcdef{bforder} .= $constname;

            $funcdef{bitdefsuffix}{$constname} = $funcdef{bitdefsuffixcurrent};

            $funcdef{bf}{$constname} = $bitpos;
            $funcdef{bfwidth}{$constname} = $bitwidth;
            $funcdef{bfcomment}{$constname} = $comment;
            $funcdef{bfval}{$constname} = $bitval;
        }
        elsif ($a[0] eq "description") {
            if (exists($funcdef{description})) {
                $funcdef{description} .= "\n";
            }
            else {
                $funcdef{description} = "";
            }

            for ($i=1;$i < @a;$i++) {
                $funcdef{description} .= " " if $i > 1;
                $funcdef{description} .= $a[$i];
            }
        }
        elsif ($a[0] eq "bitdefsuffix") {
            $funcdef{bitdefsuffixcurrent} = $a[1];
        }
        else {
            die "Don't know what $a[0] is";
        }
    }
    elsif ($section eq "defcall") {
        my @a = split(/[ \t]+/,$line);

        next if @a < 1;

        if ($a[0] eq "return") {
            if (exists($funcdef{return})) {
                $funcdef{return} .= "\n";
            }
            else {
                $funcdef{return} = "";
            }

            for ($i=1;$i < @a;$i++) {
                $funcdef{return} .= " " if $i > 1;
                $funcdef{return} .= $a[$i];
            }
        }
        elsif ($a[0] eq "byname") {
            $funcdef{byname} = $a[1];
        }
        elsif ($a[0] eq "description") {
            if (exists($funcdef{description})) {
                $funcdef{description} .= "\n";
            }
            else {
                $funcdef{description} = "";
            }

            for ($i=1;$i < @a;$i++) {
                $funcdef{description} .= " " if $i > 1;
                $funcdef{description} .= $a[$i];
            }
        }
        elsif ($a[0] eq "async") {
            if (exists($funcdef{async})) {
                $funcdef{async} .= "\n";
            }
            else {
                $funcdef{async} = "";
            }

            for ($i=1;$i < @a;$i++) {
                $funcdef{async} .= " " if $i > 1;
                $funcdef{async} .= $a[$i];
            }
        }
        elsif ($a[0] eq "cdecl") {
            $funcdef{cdecl} = "";
            for ($i=1;$i < @a;$i++) {
                $a[$i] =~ s/,[ \t]*$//;
                $a[$i] =~ s/^[ \t]*//;

                $funcdef{cdecl} .= " " if $i > 1;
                $funcdef{cdecl} .= $a[$i];
            }
        }
        elsif ($a[0] eq "in") {
            $i = index($line,';');
            my $comment = '';
            if ($i >= 0) {
                $comment = substr($line,$i+1);
                $comment =~ s/^[ \t]+//;
                $line = substr($line,0,$i);
            }
            my @a = split(/[ \t]+/,$line);

            if (!exists($funcdef{in})) {
                $funcdef{in} = { };
            }

            if (!exists($funcdef{param})) {
                $funcdef{param} = { };
            }

            if (!exists($funcdef{paramorder})) {
                $funcdef{paramorder} = "";
            }

            if (!exists($funcdef{paramcomment})) {
                $funcdef{paramcomment} = { };
            }

            my $type = '';

            $i = index($a[1],'=');
            if ($i >= 0) {
                $type = substr($a[1],$i+1);
                $type =~ s/\+/ /g;
                $a[1] = substr($a[1],0,$i);
            }

# the name '.' is allowed to mean no name if it's the ONLY return value
# out             AX        version                                 ; major, minor (example: 0x030A = 3.10)
# out             register  name                                    ; comment
            $a[1] = lc($a[1]);
#            $a[2] = lc($a[2]);

            die "register $a[1] already allocated" if exists($funcdef{in}{$a[1]});
            die "param already has name $a[2]" if exists($funcdef{param}{$a[2]});

            if ($a[1] eq "__cdecl") {
                $x = $funcdef{cdeclindex};
                $x = 0 unless defined($x);

                $a[1] .= $x;

                $x++;
                $funcdef{cdeclindex} = $x;
            }

            $funcdef{paramorder} .= " " if $funcdef{paramorder} ne "";
            $funcdef{paramorder} .= $a[1];
            $funcdef{incomment}{$a[1]} = $comment;
            $funcdef{in}{$a[1]} = $a[2];

            $funcdef{param}{$a[2]} = $a[1];
            $funcdef{paramcomment}{$a[2]} = $comment;
            $funcdef{paramtype}{$a[2]} = $type;
        }
        elsif ($a[0] eq "out") {
            $i = index($line,';');
            my $comment = '';
            if ($i >= 0) {
                $comment = substr($line,$i+1);
                $comment =~ s/^[ \t]+//;
                $line = substr($line,0,$i);
            }
            my @a = split(/[ \t]+/,$line);

            if (!exists($funcdef{out})) {
                $funcdef{out} = { };
            }

            if (!exists($funcdef{struct})) {
                $funcdef{struct} = { };
            }

            if (!exists($funcdef{structorder})) {
                $funcdef{structorder} = "";
            }

            if (!exists($funcdef{structcomment})) {
                $funcdef{structcomment} = { };
            }

            my $type = '';

            $i = index($a[1],'=');
            if ($i >= 0) {
                $type = substr($a[1],$i+1);
                $type =~ s/\+/ /g;
                $a[1] = substr($a[1],0,$i);
            }

# the name '.' is allowed to mean no name if it's the ONLY return value
# out             AX        version                                 ; major, minor (example: 0x030A = 3.10)
# out             register  name                                    ; comment
            $a[1] = lc($a[1]);
            die "__cdecl not allowed for output" if $a[1] eq "__cdecl";
#            $a[2] = lc($a[2]);

            die "register $a[1] already allocated" if exists($funcdef{out}{$a[1]});
            die "struct already has name $a[2]" if exists($funcdef{struct}{$a[2]});

            $funcdef{structorder} .= " " if $funcdef{structorder} ne "";
            $funcdef{structorder} .= $a[2];

            $funcdef{out}{$a[1]} = $a[2];
            $funcdef{struct}{$a[2]} = $a[1];
            $funcdef{outcomment}{$a[1]} = $comment;
            $funcdef{structcomment}{$a[2]} = $comment;
            $funcdef{structtype}{$a[2]} = $type;
        }
        else {
            die "Unknown defcall $a[0]";
        }
    }
}
print "# endif /*GCC_INLINE_ASM_SUPPORTS_cc_OUTPUT*/\n";
print "#endif /*defined(__GNUC__)*/\n";

close(DEF);

