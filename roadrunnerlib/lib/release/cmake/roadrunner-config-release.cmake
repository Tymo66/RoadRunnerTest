#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "roadrunner::roadrunner" for configuration "Release"
set_property(TARGET roadrunner::roadrunner APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(roadrunner::roadrunner PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/roadrunner.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/roadrunner.dll"
  )

list(APPEND _cmake_import_check_targets roadrunner::roadrunner )
list(APPEND _cmake_import_check_files_for_roadrunner::roadrunner "${_IMPORT_PREFIX}/lib/roadrunner.lib" "${_IMPORT_PREFIX}/bin/roadrunner.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
