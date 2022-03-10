cmake_minimum_required(VERSION 3.17)
project(test)
add_subdirectory(./lib/googletest)
#find_package(GTest )
set(gtest_SOURCE_DIR, ./lib/googletest/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${GTEST_INCLUDE_DIRS})

set(SOURCE_FILES MainFrameTest.cpp LoadingHandlerSuite.cpp TestObserver.cpp TestObserver.h)

add_executable(test ${SOURCE_FILES})

target_link_libraries(test gtest gtest_main ${wxWidgets_LIBRARIES} core)