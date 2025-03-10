cmake_minimum_required(VERSION 3.5)
project(mpu)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclpy REQUIRED)
find_package(std_msgs REQUIRED)

# Include CMake macro for ROS 2 packages
include_directories(include)

# Install Python modules
ament_python_install_package(${PROJECT_NAME})

# Install Python executables
install(PROGRAMS
  mpu/mpupublisher.py
  mpu/mpusubscriber.py
  DESTINATION lib/${PROJECT_NAME}
)

# Install launch files.


# Export dependencies
ament_export_dependencies(rclpy)
ament_export_dependencies(std_msgs)
ament_package()
