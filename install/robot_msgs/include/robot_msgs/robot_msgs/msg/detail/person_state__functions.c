// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from robot_msgs:msg/PersonState.idl
// generated code does not contain a copyright notice
#include "robot_msgs/msg/detail/person_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
robot_msgs__msg__PersonState__init(robot_msgs__msg__PersonState * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // bbox_xyxy
  // last_seen
  // tracked
  // palm_held_seconds
  // visible
  return true;
}

void
robot_msgs__msg__PersonState__fini(robot_msgs__msg__PersonState * msg)
{
  if (!msg) {
    return;
  }
  // id
  // bbox_xyxy
  // last_seen
  // tracked
  // palm_held_seconds
  // visible
}

bool
robot_msgs__msg__PersonState__are_equal(const robot_msgs__msg__PersonState * lhs, const robot_msgs__msg__PersonState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // bbox_xyxy
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->bbox_xyxy[i] != rhs->bbox_xyxy[i]) {
      return false;
    }
  }
  // last_seen
  if (lhs->last_seen != rhs->last_seen) {
    return false;
  }
  // tracked
  if (lhs->tracked != rhs->tracked) {
    return false;
  }
  // palm_held_seconds
  if (lhs->palm_held_seconds != rhs->palm_held_seconds) {
    return false;
  }
  // visible
  if (lhs->visible != rhs->visible) {
    return false;
  }
  return true;
}

bool
robot_msgs__msg__PersonState__copy(
  const robot_msgs__msg__PersonState * input,
  robot_msgs__msg__PersonState * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  output->id = input->id;
  // bbox_xyxy
  for (size_t i = 0; i < 4; ++i) {
    output->bbox_xyxy[i] = input->bbox_xyxy[i];
  }
  // last_seen
  output->last_seen = input->last_seen;
  // tracked
  output->tracked = input->tracked;
  // palm_held_seconds
  output->palm_held_seconds = input->palm_held_seconds;
  // visible
  output->visible = input->visible;
  return true;
}

robot_msgs__msg__PersonState *
robot_msgs__msg__PersonState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robot_msgs__msg__PersonState * msg = (robot_msgs__msg__PersonState *)allocator.allocate(sizeof(robot_msgs__msg__PersonState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(robot_msgs__msg__PersonState));
  bool success = robot_msgs__msg__PersonState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
robot_msgs__msg__PersonState__destroy(robot_msgs__msg__PersonState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    robot_msgs__msg__PersonState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
robot_msgs__msg__PersonState__Sequence__init(robot_msgs__msg__PersonState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robot_msgs__msg__PersonState * data = NULL;

  if (size) {
    data = (robot_msgs__msg__PersonState *)allocator.zero_allocate(size, sizeof(robot_msgs__msg__PersonState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = robot_msgs__msg__PersonState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        robot_msgs__msg__PersonState__fini(&data[i - 1]);
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
robot_msgs__msg__PersonState__Sequence__fini(robot_msgs__msg__PersonState__Sequence * array)
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
      robot_msgs__msg__PersonState__fini(&array->data[i]);
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

robot_msgs__msg__PersonState__Sequence *
robot_msgs__msg__PersonState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  robot_msgs__msg__PersonState__Sequence * array = (robot_msgs__msg__PersonState__Sequence *)allocator.allocate(sizeof(robot_msgs__msg__PersonState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = robot_msgs__msg__PersonState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
robot_msgs__msg__PersonState__Sequence__destroy(robot_msgs__msg__PersonState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    robot_msgs__msg__PersonState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
robot_msgs__msg__PersonState__Sequence__are_equal(const robot_msgs__msg__PersonState__Sequence * lhs, const robot_msgs__msg__PersonState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!robot_msgs__msg__PersonState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
robot_msgs__msg__PersonState__Sequence__copy(
  const robot_msgs__msg__PersonState__Sequence * input,
  robot_msgs__msg__PersonState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(robot_msgs__msg__PersonState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    robot_msgs__msg__PersonState * data =
      (robot_msgs__msg__PersonState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!robot_msgs__msg__PersonState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          robot_msgs__msg__PersonState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!robot_msgs__msg__PersonState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
