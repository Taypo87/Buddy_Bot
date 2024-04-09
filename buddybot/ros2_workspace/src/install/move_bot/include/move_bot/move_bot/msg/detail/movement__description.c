// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from move_bot:msg/Movement.idl
// generated code does not contain a copyright notice

#include "move_bot/msg/detail/movement__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_move_bot
const rosidl_type_hash_t *
move_bot__msg__Movement__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x91, 0x09, 0x4f, 0x8e, 0xe3, 0xec, 0x90, 0xa1,
      0x61, 0x77, 0x18, 0xab, 0x2e, 0xa7, 0xe0, 0x36,
      0x4e, 0x23, 0xb1, 0xb7, 0x11, 0x28, 0x45, 0x0c,
      0x90, 0x6b, 0x42, 0x54, 0x48, 0x69, 0x75, 0x3f,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char move_bot__msg__Movement__TYPE_NAME[] = "move_bot/msg/Movement";

// Define type names, field names, and default values
static char move_bot__msg__Movement__FIELD_NAME__command[] = "command";
static char move_bot__msg__Movement__FIELD_NAME__speed[] = "speed";

static rosidl_runtime_c__type_description__Field move_bot__msg__Movement__FIELDS[] = {
  {
    {move_bot__msg__Movement__FIELD_NAME__command, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {move_bot__msg__Movement__FIELD_NAME__speed, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
move_bot__msg__Movement__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {move_bot__msg__Movement__TYPE_NAME, 21, 21},
      {move_bot__msg__Movement__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string command\n"
  "int32 speed";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
move_bot__msg__Movement__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {move_bot__msg__Movement__TYPE_NAME, 21, 21},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 26, 26},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
move_bot__msg__Movement__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *move_bot__msg__Movement__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
