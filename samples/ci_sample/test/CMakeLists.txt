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

# Testing with Google Test.
if(BUILD_TESTING)
  cmr_common_test_part()

  target_sources(${test_NAME}
    PRIVATE
      ${example_src_DIR}/containers/test/container_test.cpp
      ${example_src_DIR}/test/contextTest.cpp
      ${example_src_DIR}/test/cssTest.cpp
      ${example_src_DIR}/test/documentTest.cpp
      ${example_src_DIR}/test/layoutGlobalTest.cpp
      ${example_src_DIR}/test/mediaQueryTest.cpp
      ${example_src_DIR}/test/webColorTest.cpp
      ${test_src_DIR}/example_test.cpp
  )
  set_target_properties(${test_NAME} PROPERTIES
    CXX_STANDARD 11
  )
  target_include_directories(${test_NAME} PRIVATE ${example_src_DIR})

  # litehtml
  target_link_libraries(${test_NAME} PRIVATE litehtml::litehtml)
endif()
