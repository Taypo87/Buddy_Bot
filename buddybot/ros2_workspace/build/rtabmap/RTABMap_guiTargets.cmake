# Generated by CMake

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.8)
   message(FATAL_ERROR "CMake >= 2.8.0 required")
endif()
if(CMAKE_VERSION VERSION_LESS "2.8.3")
   message(FATAL_ERROR "CMake >= 2.8.3 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 2.8.3...3.23)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_cmake_targets_defined "")
set(_cmake_targets_not_defined "")
set(_cmake_expected_targets "")
foreach(_cmake_expected_target IN ITEMS rtabmap::gui)
  list(APPEND _cmake_expected_targets "${_cmake_expected_target}")
  if(TARGET "${_cmake_expected_target}")
    list(APPEND _cmake_targets_defined "${_cmake_expected_target}")
  else()
    list(APPEND _cmake_targets_not_defined "${_cmake_expected_target}")
  endif()
endforeach()
unset(_cmake_expected_target)
if(_cmake_targets_defined STREQUAL _cmake_expected_targets)
  unset(_cmake_targets_defined)
  unset(_cmake_targets_not_defined)
  unset(_cmake_expected_targets)
  unset(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT _cmake_targets_defined STREQUAL "")
  string(REPLACE ";" ", " _cmake_targets_defined_text "${_cmake_targets_defined}")
  string(REPLACE ";" ", " _cmake_targets_not_defined_text "${_cmake_targets_not_defined}")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_cmake_targets_defined_text}\nTargets not yet defined: ${_cmake_targets_not_defined_text}\n")
endif()
unset(_cmake_targets_defined)
unset(_cmake_targets_not_defined)
unset(_cmake_expected_targets)


# Create imported target rtabmap::gui
add_library(rtabmap::gui SHARED IMPORTED)

set_target_properties(rtabmap::gui PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "/home/taylor/Buddy_Bot/buddybot/ros2_workspace/src/rtabmap/guilib/src/../include;/home/taylor/Buddy_Bot/buddybot/ros2_workspace/build/rtabmap/guilib/src/include;/usr/include/aarch64-linux-gnu/qt5/;/usr/include/aarch64-linux-gnu/qt5/QtWidgets;/usr/include/aarch64-linux-gnu/qt5/QtGui;/usr/include/aarch64-linux-gnu/qt5/QtCore;/usr/lib/aarch64-linux-gnu/qt5//mkspecs/linux-g++;/usr/include/aarch64-linux-gnu/qt5/;/usr/include/aarch64-linux-gnu/qt5/QtCore;/usr/lib/aarch64-linux-gnu/qt5//mkspecs/linux-g++;/usr/include/aarch64-linux-gnu/qt5/;/usr/include/aarch64-linux-gnu/qt5/QtGui;/usr/include/aarch64-linux-gnu/qt5/QtCore;/usr/lib/aarch64-linux-gnu/qt5//mkspecs/linux-g++;/usr/include/aarch64-linux-gnu/qt5/;/usr/include/aarch64-linux-gnu/qt5/QtOpenGL;/usr/include/aarch64-linux-gnu/qt5/QtWidgets;/usr/include/aarch64-linux-gnu/qt5/QtGui;/usr/include/aarch64-linux-gnu/qt5/QtCore;/usr/lib/aarch64-linux-gnu/qt5//mkspecs/linux-g++"
  INTERFACE_LINK_LIBRARIES "rtabmap::core;Qt5::Widgets;Qt5::Core;Qt5::Gui;Qt5::OpenGL"
)

# Import target "rtabmap::gui" for configuration "Release"
set_property(TARGET rtabmap::gui APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(rtabmap::gui PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "Qt5::PrintSupport;Qt5::Svg"
  IMPORTED_LOCATION_RELEASE "/home/taylor/Buddy_Bot/buddybot/ros2_workspace/build/rtabmap/bin/librtabmap_gui.so.0.21.4"
  IMPORTED_SONAME_RELEASE "librtabmap_gui.so.0.21"
  )

# Make sure the targets which have been exported in some other
# export set exist.
unset(${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE_targets)
foreach(_target "rtabmap::core" )
  if(NOT TARGET "${_target}" )
    set(${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE_targets "${${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE_targets} ${_target}")
  endif()
endforeach()

if(DEFINED ${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE_targets)
  if(CMAKE_FIND_PACKAGE_NAME)
    set( ${CMAKE_FIND_PACKAGE_NAME}_FOUND FALSE)
    set( ${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE "The following imported targets are referenced, but are missing: ${${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE_targets}")
  else()
    message(FATAL_ERROR "The following imported targets are referenced, but are missing: ${${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE_targets}")
  endif()
endif()
unset(${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE_targets)

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)
