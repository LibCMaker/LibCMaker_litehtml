# ****************************************************************************
#  Project:  LibCMaker_litehtml
#  Purpose:  A CMake build script for litehtml library
#  Author:   NikitaFeodonit, nfeodonit@yandex.com
# ****************************************************************************
#    Copyright (c) 2017-2020 NikitaFeodonit
#
#    This file is part of the LibCMaker_litehtml project.
#
#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published
#    by the Free Software Foundation, either version 3 of the License,
#    or (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
#    See the GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program. If not, see <http://www.gnu.org/licenses/>.
# ****************************************************************************

set(LibCMaker_LIB_DIR "${CMAKE_CURRENT_LIST_DIR}/libs")
set(LibCMaker_DIR "${LibCMaker_LIB_DIR}/LibCMaker")

include("${LibCMaker_DIR}/cmake/cmr_get_cmake_min_ver.cmake" NO_POLICY_SCOPE)
cmr_get_cmake_min_ver()
cmake_minimum_required(VERSION ${cmr_CMAKE_MIN_VER})

include("${LibCMaker_DIR}/samples/cmr_samples_common_macros.cmake")
cmr_common_sample_part__before_project()

project(LibCMaker_litehtml_Compile_Test CXX)

cmr_common_sample_part__project_settings()


#-----------------------------------------------------------------------
# Common sample part
#-----------------------------------------------------------------------

cmr_common_sample_part__add_executable()


#-----------------------------------------------------------------------
# Download, configure, build, install and find the required libraries
#-----------------------------------------------------------------------

include(${LibCMaker_LIB_DIR}/LibCMaker_litehtml/cmr_build_litehtml.cmake)


#-----------------------------------------------------------------------
# Build the executable of the example
#-----------------------------------------------------------------------

set(example_src_DIR "${CMAKE_CURRENT_LIST_DIR}/src")

target_sources(${PROJECT_NAME}
  PRIVATE
    ${example_src_DIR}/containers/test/container_test.cpp
    ${example_src_DIR}/test/contextTest.cpp
    ${example_src_DIR}/test/cssTest.cpp
    ${example_src_DIR}/test/documentTest.cpp
    ${example_src_DIR}/test/layoutGlobalTest.cpp
    ${example_src_DIR}/test/mediaQueryTest.cpp
    ${example_src_DIR}/test/webColorTest.cpp
    ${example_src_DIR}/example.cpp
)
set_target_properties(${PROJECT_NAME} PROPERTIES
  CXX_STANDARD 11
)
target_include_directories(${PROJECT_NAME} PRIVATE ${example_src_DIR})


#-----------------------------------------------------------------------
# Link to the libraries
#-----------------------------------------------------------------------

# litehtml
target_link_libraries(${PROJECT_NAME} PRIVATE litehtml::litehtml)


#-----------------------------------------------------------------------
# Testing
#-----------------------------------------------------------------------

set(test_src_DIR "${CMAKE_CURRENT_LIST_DIR}/src")
add_subdirectory(test)
