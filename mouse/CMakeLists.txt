add_library(mouse STATIC mouse.cpp)
target_include_directories(mouse PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(mouse win311headers)
