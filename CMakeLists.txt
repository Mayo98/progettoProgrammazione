cmake_minimum_required(VERSION 3.17)
project(progetto)

set(CMAKE_CXX_STANDARD 14)

add_executable(progetto main.cpp frame.cpp frame.h)

find_package(wxWidgets COMPONENTS ${WX_COMPONENTS} REQUIRED)

# wxWidgets include (this will do all the magic to configure everything)
include( "${wxWidgets_USE_FILE}" )

# Add source files
#set(SOURCE_FILES Frame.cpp Frame.h Application.cpp Application.h)

# If we build for windows systems, we also include the resource file
# containing the manifest, icon and other resources
if(WIN32)
    set(SOURCE_FILES ${SOURCE_FILES} sample.rc)
endif(WIN32)

# the above paths and defines will be used in this build
#add_executable(${CMAKE_PROJECT_NAME} WIN32 ${SOURCE_FILES})

# Add to forty to the wxWidgets libraries. These are
# set for  by the find script. Other needed libraries can be added here
target_link_libraries(${CMAKE_PROJECT_NAME} ${wxWidgets_LIBRARIES})
