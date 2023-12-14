get_filename_component(LIBSEDML_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
include(CMakeFindDependencyMacro)

list(APPEND CMAKE_MODULE_PATH "D:/a/1/s/install-azure/Release/share/cmake/Modules")

set(LIBNUML_LIBRARY_NAME $<TARGET_LINKER_FILE:libnuml-static>)
if (FIND_LIBNUML)
  find_dependency(LIBNUML)
endif()

set(LIBSBML_LIBRARY_NAME $<TARGET_LINKER_FILE:libsbml-static>)
if (FIND_LIBSBML)
  find_dependency(LIBSBML)
endif()

foreach (library $<TARGET_LINKER_FILE:expat>;$<TARGET_LINKER_FILE:zlibstatic>)

  string(FIND "${library}" "::" index)

  if (${index} GREATER 0)
    # found dependent library
    string(SUBSTRING "${library}" 0 ${index} DEPENDENT_NAME)
    message(VERBOSE "Looking for dependent library: ${DEPENDENT_NAME}")
    find_dependency(${DEPENDENT_NAME})
  endif()

endforeach()

if(NOT TARGET libsedml-static)
    include("${LIBSEDML_CMAKE_DIR}/libsedml-static-targets.cmake")
endif()

set(LIBSEDML_LIBRARIES libsedml-static)
