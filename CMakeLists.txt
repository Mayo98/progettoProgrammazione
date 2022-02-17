cmake_minimum_required(VERSION 3.17)
project(progetto)

set(CMAKE_CXX_STANDARD 14)

add_executable(progetto main.cpp Frame.cpp Frame.h MainFrame.cpp MainFrame.h AbstractSubject.cpp AbstractSubject.h LoadingHandler.cpp LoadingHandler.h Observer.h test/MainFrameTest.cpp)

find_package(wxWidgets COMPONENTS ${WX_COMPONENTS} REQUIRED)

# wxWidgets include (this will do all the magic to configure everything)
include( "${wxWidgets_USE_FILE}" )



add_subdirectory(test)

set(SOURCE_FILES main.cpp Frame.cpp Frame.h AbstractSubject.cpp AbstractSubject.h Observer.h LoadingHandler.cpp LoadingHandler.h)

if(WIN32)
    set(SOURCE_FILES ${SOURCE_FILES} sample.rc)
endif(WIN32)
add_library(core ${SOURCE_FILES})

target_link_libraries(progetto ${wxWidgets_LIBRARIES})
target_link_libraries(progetto core)
