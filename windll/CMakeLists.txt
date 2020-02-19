cmake_minimum_required(VERSION 3.10)

project(windll VERSION 1.0.0 DESCRIPTION "Windows dynamic loading test libraries and applications.")

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(liba SHARED liba.c)
set_target_properties(liba PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    PUBLIC_HEADER "liba.h")

add_library(libb SHARED libb.c)
set_target_properties(libb PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    PUBLIC_HEADER "libb.h")
target_link_libraries(libb liba)

add_library(libc SHARED libc.c)
set_target_properties(libc PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    PUBLIC_HEADER "libc.h")
target_link_libraries(libc liba)

add_executable(app app.c)
if (UNIX)
    target_link_libraries(app dl)
endif (UNIX)
