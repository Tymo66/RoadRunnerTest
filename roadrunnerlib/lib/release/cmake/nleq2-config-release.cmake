#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "nleq2::nleq2-static" for configuration "Release"
set_property(TARGET nleq2::nleq2-static APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(nleq2::nleq2-static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/nleq2-static.lib"
  )

list(APPEND _cmake_import_check_targets nleq2::nleq2-static )
list(APPEND _cmake_import_check_files_for_nleq2::nleq2-static "${_IMPORT_PREFIX}/lib/nleq2-static.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
