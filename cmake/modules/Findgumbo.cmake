find_path(gumbo_INCLUDE_DIR
  NAMES gumbo/gumbo.h
  NO_CMAKE_ENVIRONMENT_PATH
  NO_SYSTEM_ENVIRONMENT_PATH
  NO_CMAKE_SYSTEM_PATH
)

find_library(gumbo_LIBRARY
  NAMES gumbo gumbod
  NO_CMAKE_ENVIRONMENT_PATH
  NO_SYSTEM_ENVIRONMENT_PATH
  NO_CMAKE_SYSTEM_PATH
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(gumbo
  REQUIRED_VARS gumbo_INCLUDE_DIR gumbo_LIBRARY
)

mark_as_advanced(
  gumbo_INCLUDE_DIR
  gumbo_LIBRARY
)

if(gumbo_FOUND AND NOT (TARGET gumbo::gumbo))
  add_library(gumbo::gumbo UNKNOWN IMPORTED)
  set_target_properties(gumbo::gumbo PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${gumbo_INCLUDE_DIR}"
    IMPORTED_LINK_INTERFACE_LANGUAGES "C"
    IMPORTED_LOCATION "${gumbo_LIBRARY}"
  )
endif()
