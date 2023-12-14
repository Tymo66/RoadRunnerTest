#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "libsbml-static" for configuration "Release"
set_property(TARGET libsbml-static APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(libsbml-static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C;CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libsbml-staticmd.lib"
  )

list(APPEND _cmake_import_check_targets libsbml-static )
list(APPEND _cmake_import_check_files_for_libsbml-static "${_IMPORT_PREFIX}/lib/libsbml-staticmd.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
