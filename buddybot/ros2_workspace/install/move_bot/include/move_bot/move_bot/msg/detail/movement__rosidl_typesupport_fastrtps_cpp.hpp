// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from move_bot:msg/Movement.idl
// generated code does not contain a copyright notice

#ifndef MOVE_BOT__MSG__DETAIL__MOVEMENT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define MOVE_BOT__MSG__DETAIL__MOVEMENT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "move_bot/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "move_bot/msg/detail/movement__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace move_bot
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_move_bot
cdr_serialize(
  const move_bot::msg::Movement & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_move_bot
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  move_bot::msg::Movement & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_move_bot
get_serialized_size(
  const move_bot::msg::Movement & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_move_bot
max_serialized_size_Movement(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace move_bot

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_move_bot
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, move_bot, msg, Movement)();

#ifdef __cplusplus
}
#endif

#endif  // MOVE_BOT__MSG__DETAIL__MOVEMENT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
