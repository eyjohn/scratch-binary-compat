cmake_minimum_required(VERSION 3.10)

project(scratch-binary-compat VERSION 1.0.0 DESCRIPTION "Applications for testing binary compatibility of compiled modules.")

include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 17)

add_library(clib SHARED src/clib/clib.c)
set_target_properties(clib PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    PUBLIC_HEADER "src/clib/clib.h")

# add_library(cpplib SHARED src/cpplib/cpplib.cpp)
add_library(cpplib INTERFACE)
target_include_directories(cpplib INTERFACE src/clib)
target_link_libraries(cpplib INTERFACE clib)
# set_target_properties(cpplib PROPERTIES
#     # VERSION ${PROJECT_VERSION}
#     # SOVERSION 1
#     PUBLIC_HEADER "src/cpplib/cpplib.h")

add_executable(capp src/capp.c)
target_link_libraries(capp clib)
target_include_directories(capp PUBLIC src/clib)

add_executable(cppapp src/cppapp.cpp)
target_link_libraries(cppapp clib)
target_include_directories(cppapp PUBLIC src/cpplib src/clib)

install(TARGETS clib cpplib capp cppapp
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
