cmake_minimum_required(VERSION 3.10)

project(dl-playground VERSION 1.0.0 DESCRIPTION "Various dynamic linker projects.")

include(GNUInstallDirs)

add_library(clib SHARED src/clib/clib.c)
set_target_properties(clib PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    PUBLIC_HEADER "src/clib/clib.h")

# add_library(alib SHARED src/alib.c)
# set_target_properties(alib PROPERTIES
#     VERSION ${PROJECT_VERSION}
#     SOVERSION 1
#     PUBLIC_HEADER "src/alib.h")

# add_executable(atest src/atest.c)
# target_link_libraries(atest dl)

# install(TARGETS alib atest
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
#     PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
