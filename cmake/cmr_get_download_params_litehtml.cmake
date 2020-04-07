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

# Part of "LibCMaker/cmake/cmr_get_download_params.cmake".

  if(version VERSION_EQUAL "0.5.20200407")
    set(arch_file_sha
      "b3e38125f0044852b936fa4550e6b197b2aa20b0c21096af35176dbaff2b9471")
    set(src_commit
      "90555f175861b6f84b2d3311c6643394ec425bb9")
  endif()

  set(base_url "https://github.com/litehtml/litehtml/archive")
  set(src_dir_name    "v${version}")
  set(arch_file_name  "${src_dir_name}.tar.gz")
  set(unpack_to_dir   "${unpacked_dir}/litehtml-${version}")

  set(${out_ARCH_SRC_URL}   "${base_url}/${arch_file_name}" PARENT_SCOPE)
  set(${out_ARCH_DST_FILE}  "${download_dir}/litehtml-${arch_file_name}" PARENT_SCOPE)
  set(${out_ARCH_FILE_SHA}  "${arch_file_sha}" PARENT_SCOPE)
  set(${out_SHA_ALG}        "SHA256" PARENT_SCOPE)
  set(${out_UNPACK_TO_DIR}  "${unpack_to_dir}" PARENT_SCOPE)
  set(${out_UNPACKED_SOURCES_DIR}
    "${unpack_to_dir}/litehtml-${version}" PARENT_SCOPE
  )
  set(${out_VERSION_BUILD_DIR} "${build_dir}/${src_dir_name}" PARENT_SCOPE)

  if(src_commit)
    set(${out_ARCH_SRC_URL} "${base_url}/${src_commit}.tar.gz" PARENT_SCOPE)
    set(${out_UNPACKED_SOURCES_DIR}
      "${unpack_to_dir}/litehtml-${src_commit}" PARENT_SCOPE
    )
  endif()
