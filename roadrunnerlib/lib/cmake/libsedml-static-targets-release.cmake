#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "libsedml-static" for configuration "Release"
set_property(TARGET libsedml-static APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(libsedml-static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libsedml-staticmd.lib"
  )

list(APPEND _cmake_import_check_targets libsedml-static )
list(APPEND _cmake_import_check_files_for_libsedml-static "${_IMPORT_PREFIX}/lib/libsedml-staticmd.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
