#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "roadrunner_c_api::roadrunner_c_api" for configuration "Release"
set_property(TARGET roadrunner_c_api::roadrunner_c_api APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(roadrunner_c_api::roadrunner_c_api PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/roadrunner_c_api.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/roadrunner_c_api.dll"
  )

list(APPEND _cmake_import_check_targets roadrunner_c_api::roadrunner_c_api )
list(APPEND _cmake_import_check_files_for_roadrunner_c_api::roadrunner_c_api "${_IMPORT_PREFIX}/lib/roadrunner_c_api.lib" "${_IMPORT_PREFIX}/bin/roadrunner_c_api.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
