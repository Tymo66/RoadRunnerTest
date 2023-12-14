get_filename_component(LIBSBML_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
include(CMakeFindDependencyMacro)

list(APPEND CMAKE_MODULE_PATH "D:/a/1/s/install-azure/Release/share/cmake/Modules")

foreach (library ZLIB::ZLIB;EXPAT::EXPAT )

    string(FIND "${library}" "::" index)

    if (${index} GREATER 0)
      # found dependent library
      string(SUBSTRING "${library}" 0 ${index} DEPENDENT_NAME)
      message(VERBOSE "Looking for dependent library: ${DEPENDENT_NAME}")
      find_dependency(${DEPENDENT_NAME})
    endif()

endforeach()

if(NOT TARGET libsbml-static)
    include("${LIBSBML_CMAKE_DIR}/libsbml-static-targets.cmake")
endif()

set(LIBSBML_LIBRARIES libsbml-static)
