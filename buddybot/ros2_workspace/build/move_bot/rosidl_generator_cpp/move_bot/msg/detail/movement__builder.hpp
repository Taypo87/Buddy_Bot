// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from move_bot:msg/Movement.idl
// generated code does not contain a copyright notice

#ifndef MOVE_BOT__MSG__DETAIL__MOVEMENT__BUILDER_HPP_
#define MOVE_BOT__MSG__DETAIL__MOVEMENT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "move_bot/msg/detail/movement__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace move_bot
{

namespace msg
{

namespace builder
{

class Init_Movement_speed
{
public:
  explicit Init_Movement_speed(::move_bot::msg::Movement & msg)
  : msg_(msg)
  {}
  ::move_bot::msg::Movement speed(::move_bot::msg::Movement::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::move_bot::msg::Movement msg_;
};

class Init_Movement_command
{
public:
  Init_Movement_command()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Movement_speed command(::move_bot::msg::Movement::_command_type arg)
  {
    msg_.command = std::move(arg);
    return Init_Movement_speed(msg_);
  }

private:
  ::move_bot::msg::Movement msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::move_bot::msg::Movement>()
{
  return move_bot::msg::builder::Init_Movement_command();
}

}  // namespace move_bot

#endif  // MOVE_BOT__MSG__DETAIL__MOVEMENT__BUILDER_HPP_
