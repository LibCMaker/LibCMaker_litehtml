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

#-----------------------------------------------------------------------
# The file is an example of the convenient script for the library build.
#-----------------------------------------------------------------------

#-----------------------------------------------------------------------
# Lib's name, version, paths
#-----------------------------------------------------------------------

set(LITEHTML_lib_NAME "litehtml")
set(LITEHTML_lib_VERSION "0.5.20200407" CACHE STRING "LITEHTML_lib_VERSION")
set(LITEHTML_lib_DIR "${CMAKE_CURRENT_LIST_DIR}" CACHE PATH "LITEHTML_lib_DIR")

# To use our Find<LibName>.cmake.
list(APPEND CMAKE_MODULE_PATH "${LITEHTML_lib_DIR}/cmake/modules")


#-----------------------------------------------------------------------
# LibCMaker_<LibName> specific vars and options
#-----------------------------------------------------------------------

option(COPY_LITEHTML_CMAKE_BUILD_SCRIPTS "COPY_LITEHTML_CMAKE_BUILD_SCRIPTS" ON)


#-----------------------------------------------------------------------
# Library specific vars and options
#-----------------------------------------------------------------------

if(WIN32 OR WINCE)
  set(_LITEHTML_UTF8 ON)
else()
  set(_LITEHTML_UTF8 OFF)
endif()

option(LITEHTML_UTF8
  "Build litehtml with UTF-8 text conversion functions." ${_LITEHTML_UTF8}
)


#-----------------------------------------------------------------------
# Build, install and find the library
#-----------------------------------------------------------------------

cmr_find_package(
  LibCMaker_DIR   ${LibCMaker_DIR}
  NAME            ${LITEHTML_lib_NAME}
  VERSION         ${LITEHTML_lib_VERSION}
  LIB_DIR         ${LITEHTML_lib_DIR}
  REQUIRED
)
