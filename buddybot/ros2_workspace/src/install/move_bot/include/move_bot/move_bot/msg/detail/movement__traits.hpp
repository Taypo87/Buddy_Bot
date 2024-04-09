// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from move_bot:msg/Movement.idl
// generated code does not contain a copyright notice

#ifndef MOVE_BOT__MSG__DETAIL__MOVEMENT__TRAITS_HPP_
#define MOVE_BOT__MSG__DETAIL__MOVEMENT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "move_bot/msg/detail/movement__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace move_bot
{

namespace msg
{

inline void to_flow_style_yaml(
  const Movement & msg,
  std::ostream & out)
{
  out << "{";
  // member: command
  {
    out << "command: ";
    rosidl_generator_traits::value_to_yaml(msg.command, out);
    out << ", ";
  }

  // member: speed
  {
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Movement & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: command
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "command: ";
    rosidl_generator_traits::value_to_yaml(msg.command, out);
    out << "\n";
  }

  // member: speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Movement & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace move_bot

namespace rosidl_generator_traits
{

[[deprecated("use move_bot::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const move_bot::msg::Movement & msg,
  std::ostream & out, size_t indentation = 0)
{
  move_bot::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use move_bot::msg::to_yaml() instead")]]
inline std::string to_yaml(const move_bot::msg::Movement & msg)
{
  return move_bot::msg::to_yaml(msg);
}

template<>
inline const char * data_type<move_bot::msg::Movement>()
{
  return "move_bot::msg::Movement";
}

template<>
inline const char * name<move_bot::msg::Movement>()
{
  return "move_bot/msg/Movement";
}

template<>
struct has_fixed_size<move_bot::msg::Movement>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<move_bot::msg::Movement>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<move_bot::msg::Movement>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MOVE_BOT__MSG__DETAIL__MOVEMENT__TRAITS_HPP_
