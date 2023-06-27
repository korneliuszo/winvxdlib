add_library(hello SHARED hello.cpp)
target_link_options(hello PRIVATE -Wl,-Map=$<TARGET_FILE_DIR:hello>/mapfile.map)
target_link_libraries(hello win311headers win311crt)

create_386(hello HELLO)