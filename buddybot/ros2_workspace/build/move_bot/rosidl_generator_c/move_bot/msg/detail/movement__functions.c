// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from move_bot:msg/Movement.idl
// generated code does not contain a copyright notice
#include "move_bot/msg/detail/movement__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `command`
#include "rosidl_runtime_c/string_functions.h"

bool
move_bot__msg__Movement__init(move_bot__msg__Movement * msg)
{
  if (!msg) {
    return false;
  }
  // command
  if (!rosidl_runtime_c__String__init(&msg->command)) {
    move_bot__msg__Movement__fini(msg);
    return false;
  }
  // speed
  return true;
}

void
move_bot__msg__Movement__fini(move_bot__msg__Movement * msg)
{
  if (!msg) {
    return;
  }
  // command
  rosidl_runtime_c__String__fini(&msg->command);
  // speed
}

bool
move_bot__msg__Movement__are_equal(const move_bot__msg__Movement * lhs, const move_bot__msg__Movement * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // command
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->command), &(rhs->command)))
  {
    return false;
  }
  // speed
  if (lhs->speed != rhs->speed) {
    return false;
  }
  return true;
}

bool
move_bot__msg__Movement__copy(
  const move_bot__msg__Movement * input,
  move_bot__msg__Movement * output)
{
  if (!input || !output) {
    return false;
  }
  // command
  if (!rosidl_runtime_c__String__copy(
      &(input->command), &(output->command)))
  {
    return false;
  }
  // speed
  output->speed = input->speed;
  return true;
}

move_bot__msg__Movement *
move_bot__msg__Movement__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  move_bot__msg__Movement * msg = (move_bot__msg__Movement *)allocator.allocate(sizeof(move_bot__msg__Movement), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(move_bot__msg__Movement));
  bool success = move_bot__msg__Movement__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
move_bot__msg__Movement__destroy(move_bot__msg__Movement * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    move_bot__msg__Movement__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
move_bot__msg__Movement__Sequence__init(move_bot__msg__Movement__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  move_bot__msg__Movement * data = NULL;

  if (size) {
    data = (move_bot__msg__Movement *)allocator.zero_allocate(size, sizeof(move_bot__msg__Movement), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = move_bot__msg__Movement__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        move_bot__msg__Movement__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
move_bot__msg__Movement__Sequence__fini(move_bot__msg__Movement__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      move_bot__msg__Movement__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

move_bot__msg__Movement__Sequence *
move_bot__msg__Movement__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  move_bot__msg__Movement__Sequence * array = (move_bot__msg__Movement__Sequence *)allocator.allocate(sizeof(move_bot__msg__Movement__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = move_bot__msg__Movement__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
move_bot__msg__Movement__Sequence__destroy(move_bot__msg__Movement__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    move_bot__msg__Movement__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
move_bot__msg__Movement__Sequence__are_equal(const move_bot__msg__Movement__Sequence * lhs, const move_bot__msg__Movement__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!move_bot__msg__Movement__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
move_bot__msg__Movement__Sequence__copy(
  const move_bot__msg__Movement__Sequence * input,
  move_bot__msg__Movement__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(move_bot__msg__Movement);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    move_bot__msg__Movement * data =
      (move_bot__msg__Movement *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!move_bot__msg__Movement__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          move_bot__msg__Movement__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!move_bot__msg__Movement__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
