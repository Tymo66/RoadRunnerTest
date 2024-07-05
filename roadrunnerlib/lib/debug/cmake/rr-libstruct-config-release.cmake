#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rr-libstruct::rr-libstruct-static" for configuration "Release"
set_property(TARGET rr-libstruct::rr-libstruct-static APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(rr-libstruct::rr-libstruct-static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/rr-libstruct-staticmd.lib"
  )

list(APPEND _cmake_import_check_targets rr-libstruct::rr-libstruct-static )
list(APPEND _cmake_import_check_files_for_rr-libstruct::rr-libstruct-static "${_IMPORT_PREFIX}/lib/rr-libstruct-staticmd.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
