cmake_minimum_required(VERSION 3.8)
project(movement)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find packages
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# Generate custom interfaces
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Movement.msg"
)

# Add executable
add_executable(move_node src/move_bot.cpp src/movements.c)
ament_target_dependencies(move_node
  rclcpp
  std_msgs
)
# Link the generated message interfaces to the executable
rosidl_target_interfaces(move_node
  ${PROJECT_NAME} "rosidl_typesupport_cpp"
)

# Install executable
install(TARGETS
  move_node
  DESTINATION lib/${PROJECT_NAME}
)

# Add testing if necessary
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

# Package configuration
ament_package()
