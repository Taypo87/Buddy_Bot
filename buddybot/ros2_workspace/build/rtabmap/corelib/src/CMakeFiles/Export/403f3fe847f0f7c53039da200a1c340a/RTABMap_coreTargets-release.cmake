#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rtabmap::core" for configuration "Release"
set_property(TARGET rtabmap::core APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(rtabmap::core PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/librtabmap_core.so.0.21.4"
  IMPORTED_SONAME_RELEASE "librtabmap_core.so.0.21"
  )

list(APPEND _cmake_import_check_targets rtabmap::core )
list(APPEND _cmake_import_check_files_for_rtabmap::core "${_IMPORT_PREFIX}/lib/librtabmap_core.so.0.21.4" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
