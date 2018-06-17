file(GLOB SRCS *.cpp)

add_executable(colorGraphTest TestGraph.cpp ../graph/ColorGraph.cpp ../graph/ColorGraph.h)

target_link_libraries(colorGraphTest gtest gtest_main)

include_directories("..")

add_test(NAME colorGraphTest COMMAND colorGraphTest)