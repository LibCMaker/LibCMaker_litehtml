find_path(litehtml_INCLUDE_DIR
  NAMES litehtml/litehtml.h
  NO_CMAKE_ENVIRONMENT_PATH
  NO_SYSTEM_ENVIRONMENT_PATH
  NO_CMAKE_SYSTEM_PATH
)

find_library(litehtml_LIBRARY
  NAMES litehtml litehtmld
  NO_CMAKE_ENVIRONMENT_PATH
  NO_SYSTEM_ENVIRONMENT_PATH
  NO_CMAKE_SYSTEM_PATH
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(litehtml
  REQUIRED_VARS litehtml_INCLUDE_DIR litehtml_LIBRARY
)

mark_as_advanced(
  litehtml_INCLUDE_DIR
  litehtml_LIBRARY
)

if(litehtml_FOUND AND NOT (TARGET litehtml::litehtml))
  add_library(litehtml::litehtml UNKNOWN IMPORTED)
  set_target_properties(litehtml::litehtml PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${litehtml_INCLUDE_DIR}"
    IMPORTED_LINK_INTERFACE_LANGUAGES "CXX"
    IMPORTED_LOCATION "${litehtml_LIBRARY}"
  )

  if(NOT BUILD_SHARED_LIBS)
    find_package(gumbo REQUIRED)
    set_property(TARGET litehtml::litehtml APPEND PROPERTY
      INTERFACE_LINK_LIBRARIES gumbo::gumbo
    )
  endif()
endif()
