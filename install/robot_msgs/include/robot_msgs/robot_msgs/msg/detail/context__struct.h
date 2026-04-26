// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_msgs:msg/Context.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_MSGS__MSG__DETAIL__CONTEXT__STRUCT_H_
#define ROBOT_MSGS__MSG__DETAIL__CONTEXT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'persons'
#include "robot_msgs/msg/detail/person__struct.h"

/// Struct defined in msg/Context in the package robot_msgs.
typedef struct robot_msgs__msg__Context
{
  std_msgs__msg__Header header;
  robot_msgs__msg__Person__Sequence persons;
} robot_msgs__msg__Context;

// Struct for a sequence of robot_msgs__msg__Context.
typedef struct robot_msgs__msg__Context__Sequence
{
  robot_msgs__msg__Context * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_msgs__msg__Context__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_MSGS__MSG__DETAIL__CONTEXT__STRUCT_H_
