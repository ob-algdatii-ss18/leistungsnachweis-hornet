add_executable(TestGraph TestGraph.cpp)

add_dependencies(TestGraph gtest)

target_include_directories(TestGraph PRIVATE
        ${PROJECT_SOURCE_DIR}/lib/include
        ${GTEST_SOURCE_DIR}/googletest/include
        ${GTEST_SOURCE_DIR}/googlemock/include)


target_link_libraries(TestGraph
        pthread
        ${GTEST_BINARY_DIR}/googlemock/gtest/libgtest.a
        ${GTEST_BINARY_DIR}/googlemock/gtest/libgtest_main.a)

add_test(NAME graphColorTest COMMAND TestGraph)