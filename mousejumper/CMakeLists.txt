add_library(mousej SHARED mousej.cpp)
target_link_options(mousej PRIVATE -Wl,-Map=$<TARGET_FILE_DIR:mousej>/mapfile.map)
target_link_libraries(mousej mouse win311headers win311crt c)

create_386(mousej MOUSEJ)