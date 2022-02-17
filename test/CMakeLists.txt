cmake_minimum_required(VERSION 3.17)
project(test)
add_subdirectory(./lib/googletest)
#find_package(GTest )
set(gtest_SOURCE_DIR, ./lib/googletest/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${GTEST_INCLUDE_DIRS})
set(SOURCE_FILES MainFrameTest.cpp)

add_executable(test ${SOURCE_FILES})

target_link_libraries(test core gtest gtest_main)

include_directories(${GTEST_INCLUDE_DIRS})
#target_link_libraries(MainFrameTest.cpp ${GTEST_BOTH_LIBRARIES}
#        core)