# Install script for directory: /home/taylor/Buddy_Bot/buddybot/ros2_workspace/src/tfmini_ros

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/taylor/Buddy_Bot/buddybot/ros2_workspace/src/install/tfmini_ros")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/package_run_dependencies" TYPE FILE FILES "/home/taylor/Buddy_Bot/buddybot/ros2_workspace/src/build/tfmini_ros/ament_cmake_index/share/ament_index/resource_index/package_run_dependencies/tfmini_ros")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/parent_prefix_path" TYPE FILE FILES "/home/taylor/Buddy_Bot/buddybot/ros2_workspace/src/build/tfmini_ros/ament_cmake_index/share/ament_index/resource_index/parent_prefix_path/tfmini_ros")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/tfmini_ros/environment" TYPE FILE FILES "/home/taylor/ros2_iron/install/ament_cmake_core/share/ament_cmake_core/cmake/environment_hooks/environment/ament_prefix_path.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/tfmini_ros/environment" TYPE FILE FILES "/home/taylor/Buddy_Bot/buddybot/ros2_workspace/src/build/tfmini_ros/ament_cmake_environment_hooks/ament_prefix_path.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/tfmini_ros/environment" TYPE FILE FILES "/home/taylor/ros2_iron/install/ament_cmake_core/share/ament_cmake_core/cmake/environment_hooks/environment/path.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/tfmini_ros/environment" TYPE FILE FILES "/home/taylor/Buddy_Bot/buddybot/ros2_workspace/src/build/tfmini_ros/ament_cmake_environment_hooks/path.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/tfmini_ros" TYPE FILE FILES "/home/taylor/Buddy_Bot/buddybot/ros2_workspace/src/build/tfmini_ros/ament_cmake_environment_hooks/local_setup.bash")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/tfmini_ros" TYPE FILE FILES "/home/taylor/Buddy_Bot/buddybot/ros2_workspace/src/build/tfmini_ros/ament_cmake_environment_hooks/local_setup.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/tfmini_ros" TYPE FILE FILES "/home/taylor/Buddy_Bot/buddybot/ros2_workspace/src/build/tfmini_ros/ament_cmake_environment_hooks/local_setup.zsh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/tfmini_ros" TYPE FILE FILES "/home/taylor/Buddy_Bot/buddybot/ros2_workspace/src/build/tfmini_ros/ament_cmake_environment_hooks/local_setup.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/tfmini_ros" TYPE FILE FILES "/home/taylor/Buddy_Bot/buddybot/ros2_workspace/src/build/tfmini_ros/ament_cmake_environment_hooks/package.dsv")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/packages" TYPE FILE FILES "/home/taylor/Buddy_Bot/buddybot/ros2_workspace/src/build/tfmini_ros/ament_cmake_index/share/ament_index/resource_index/packages/tfmini_ros")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/tfmini_ros/cmake" TYPE FILE FILES
    "/home/taylor/Buddy_Bot/buddybot/ros2_workspace/src/build/tfmini_ros/ament_cmake_core/tfmini_rosConfig.cmake"
    "/home/taylor/Buddy_Bot/buddybot/ros2_workspace/src/build/tfmini_ros/ament_cmake_core/tfmini_rosConfig-version.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/tfmini_ros" TYPE FILE FILES "/home/taylor/Buddy_Bot/buddybot/ros2_workspace/src/tfmini_ros/package.xml")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/tfmini_ros/tfmini_ros_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/tfmini_ros/tfmini_ros_node")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/tfmini_ros/tfmini_ros_node"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/tfmini_ros" TYPE EXECUTABLE FILES "/home/taylor/Buddy_Bot/buddybot/ros2_workspace/src/build/tfmini_ros/tfmini_ros_node")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/tfmini_ros/tfmini_ros_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/tfmini_ros/tfmini_ros_node")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/tfmini_ros/tfmini_ros_node"
         OLD_RPATH "/home/taylor/ros2_iron/install/rclcpp/lib:/home/taylor/ros2_iron/install/sensor_msgs/lib:/home/taylor/ros2_iron/install/libstatistics_collector/lib:/home/taylor/ros2_iron/install/rcl/lib:/home/taylor/ros2_iron/install/rcl_logging_interface/lib:/home/taylor/ros2_iron/install/rmw_implementation/lib:/home/taylor/ros2_iron/install/ament_index_cpp/lib:/home/taylor/ros2_iron/install/type_description_interfaces/lib:/home/taylor/ros2_iron/install/rcl_interfaces/lib:/home/taylor/ros2_iron/install/rcl_yaml_param_parser/lib:/home/taylor/ros2_iron/install/rosgraph_msgs/lib:/home/taylor/ros2_iron/install/statistics_msgs/lib:/home/taylor/ros2_iron/install/tracetools/lib:/home/taylor/ros2_iron/install/geometry_msgs/lib:/home/taylor/ros2_iron/install/std_msgs/lib:/home/taylor/ros2_iron/install/service_msgs/lib:/home/taylor/ros2_iron/install/builtin_interfaces/lib:/home/taylor/ros2_iron/install/rosidl_typesupport_fastrtps_c/lib:/home/taylor/ros2_iron/install/rosidl_typesupport_fastrtps_cpp/lib:/home/taylor/ros2_iron/install/fastcdr/lib:/home/taylor/ros2_iron/install/rmw/lib:/home/taylor/ros2_iron/install/rosidl_dynamic_typesupport/lib:/home/taylor/ros2_iron/install/rosidl_typesupport_introspection_cpp/lib:/home/taylor/ros2_iron/install/rosidl_typesupport_introspection_c/lib:/home/taylor/ros2_iron/install/rosidl_typesupport_cpp/lib:/home/taylor/ros2_iron/install/rosidl_typesupport_c/lib:/home/taylor/ros2_iron/install/rcpputils/lib:/home/taylor/ros2_iron/install/rosidl_runtime_c/lib:/home/taylor/ros2_iron/install/rcutils/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/tfmini_ros/tfmini_ros_node")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/" TYPE DIRECTORY FILES "/home/taylor/Buddy_Bot/buddybot/ros2_workspace/src/tfmini_ros/include/")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/tfmini_ros/launch" TYPE DIRECTORY FILES "/home/taylor/Buddy_Bot/buddybot/ros2_workspace/src/tfmini_ros/launch/")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/taylor/Buddy_Bot/buddybot/ros2_workspace/src/build/tfmini_ros/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
