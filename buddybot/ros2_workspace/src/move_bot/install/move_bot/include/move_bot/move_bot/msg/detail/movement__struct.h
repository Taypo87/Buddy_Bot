// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from move_bot:msg/Movement.idl
// generated code does not contain a copyright notice

#ifndef MOVE_BOT__MSG__DETAIL__MOVEMENT__STRUCT_H_
#define MOVE_BOT__MSG__DETAIL__MOVEMENT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'command'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Movement in the package move_bot.
typedef struct move_bot__msg__Movement
{
  rosidl_runtime_c__String command;
  int32_t speed;
} move_bot__msg__Movement;

// Struct for a sequence of move_bot__msg__Movement.
typedef struct move_bot__msg__Movement__Sequence
{
  move_bot__msg__Movement * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} move_bot__msg__Movement__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MOVE_BOT__MSG__DETAIL__MOVEMENT__STRUCT_H_
