// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from move_bot:msg/Movement.idl
// generated code does not contain a copyright notice

#ifndef MOVE_BOT__MSG__DETAIL__MOVEMENT__STRUCT_HPP_
#define MOVE_BOT__MSG__DETAIL__MOVEMENT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__move_bot__msg__Movement __attribute__((deprecated))
#else
# define DEPRECATED__move_bot__msg__Movement __declspec(deprecated)
#endif

namespace move_bot
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Movement_
{
  using Type = Movement_<ContainerAllocator>;

  explicit Movement_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command = "";
      this->speed = 0l;
    }
  }

  explicit Movement_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : command(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command = "";
      this->speed = 0l;
    }
  }

  // field types and members
  using _command_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _command_type command;
  using _speed_type =
    int32_t;
  _speed_type speed;

  // setters for named parameter idiom
  Type & set__command(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->command = _arg;
    return *this;
  }
  Type & set__speed(
    const int32_t & _arg)
  {
    this->speed = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    move_bot::msg::Movement_<ContainerAllocator> *;
  using ConstRawPtr =
    const move_bot::msg::Movement_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<move_bot::msg::Movement_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<move_bot::msg::Movement_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      move_bot::msg::Movement_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<move_bot::msg::Movement_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      move_bot::msg::Movement_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<move_bot::msg::Movement_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<move_bot::msg::Movement_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<move_bot::msg::Movement_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__move_bot__msg__Movement
    std::shared_ptr<move_bot::msg::Movement_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__move_bot__msg__Movement
    std::shared_ptr<move_bot::msg::Movement_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Movement_ & other) const
  {
    if (this->command != other.command) {
      return false;
    }
    if (this->speed != other.speed) {
      return false;
    }
    return true;
  }
  bool operator!=(const Movement_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Movement_

// alias to use template instance with default allocator
using Movement =
  move_bot::msg::Movement_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace move_bot

#endif  // MOVE_BOT__MSG__DETAIL__MOVEMENT__STRUCT_HPP_
