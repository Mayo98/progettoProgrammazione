cmake_minimum_required(VERSION 3.17)
project(progetto)

set(CMAKE_CXX_STANDARD 14)

find_package(wxWidgets COMPONENTS ${WX_COMPONENTS} REQUIRED)
# wxWidgets include (this will do all the magic to configure everything)
include( "${wxWidgets_USE_FILE}" )

add_subdirectory(test)

set(SOURCE_FILES MainFrame.h MainFrame.cpp Frame.cpp Frame.h AbstractSubject.cpp AbstractSubject.h Observer.h LoadingHandler.cpp LoadingHandler.h)

add_executable(progetto main.cpp)
add_library(core ${SOURCE_FILES})

if(WIN32)
    set(SOURCE_FILES ${SOURCE_FILES} sample.rc)
endif(WIN32)

target_link_libraries(progetto ${wxWidgets_LIBRARIES} core)
