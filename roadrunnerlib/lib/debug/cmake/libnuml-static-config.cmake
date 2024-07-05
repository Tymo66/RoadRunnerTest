get_filename_component(LIBSBML_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
include(CMakeFindDependencyMacro)

list(APPEND CMAKE_MODULE_PATH "D:/a/1/s/install-azure/Release/share/cmake/Modules")

set(LIBSBML_LIBRARY_NAME $<TARGET_LINKER_FILE:libsbml-static>)
if(FIND_LIBSBML)
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

if(NOT TARGET libnuml-static)
    include("${LIBSBML_CMAKE_DIR}/libnuml-static-targets.cmake")
endif()

set(LIBNUML_LIBRARIES libnuml-static)
