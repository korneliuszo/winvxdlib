

add_library(win311headers INTERFACE)
target_include_directories(win311headers INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_options(win311headers INTERFACE -fvisibility=hidden)
target_compile_options(win311headers INTERFACE -fno-asynchronous-unwind-tables)
target_compile_options(win311headers INTERFACE -ffunction-sections -fdata-sections)
target_link_options(win311headers INTERFACE -r -flinker-output=nolto-rel -nostartfiles)
target_link_options(win311headers INTERFACE -Wl,--no-warn-rwx-segments)
target_link_options(win311headers INTERFACE -T ${CMAKE_CURRENT_SOURCE_DIR}/link.ld)
add_dependencies(win311headers ${CMAKE_CURRENT_SOURCE_DIR}/link.ld)

add_library(win311crt OBJECT vmm.cpp control_proc.S)
target_link_libraries(win311crt win311headers)