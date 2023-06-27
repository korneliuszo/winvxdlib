cmake_minimum_required(VERSION 3.26)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/toolchain.cmake)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_COMPILE_WARNING_AS_ERROR ON)
set(CMAKE_C_FLAGS -O3)
set(CMAKE_CXX_FLAGS -O3)

enable_language(ASM)

project(winvxdlib)

SET_PROPERTY(GLOBAL PROPERTY TARGET_SUPPORTS_SHARED_LIBS true)

add_custom_target(
   objconv
   COMMAND make
   WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/objconv
)

function(create_386 tgt modname)
	set(OBJFILE ${CMAKE_CURRENT_BINARY_DIR}/${tgt}.obj)
	set(MODNAME ${modname})
	set(OUTFILE ${CMAKE_CURRENT_BINARY_DIR}/${tgt})
	set(in   $<TARGET_FILE_NAME:${tgt}>)
	add_custom_target( ${tgt}.obj
		DEPENDS ${tgt} objconv
		COMMAND ${CMAKE_CURRENT_FUNCTION_LIST_DIR}/objconv/objconv
			-fomf -nd ${in} ${OBJFILE}	
	)
	configure_file(
		${CMAKE_CURRENT_FUNCTION_LIST_DIR}/wlink.scr
		${tgt}.lscr
		@ONLY
	)
	add_custom_target( ${tgt}.386 ALL
		DEPENDS ${tgt}.lscr ${tgt}.obj
		COMMAND wlink 
			@${CMAKE_CURRENT_BINARY_DIR}/${tgt}.lscr
	)
endfunction()

add_subdirectory(headers)

if(PROJECT_IS_TOP_LEVEL)
add_subdirectory(helloworld)
endif()
