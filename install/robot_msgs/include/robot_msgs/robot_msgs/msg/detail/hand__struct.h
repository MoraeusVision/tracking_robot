// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_msgs:msg/Hand.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_MSGS__MSG__DETAIL__HAND__STRUCT_H_
#define ROBOT_MSGS__MSG__DETAIL__HAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'gesture'
#include "rosidl_runtime_c/string.h"
// Member 'landmarks'
#include "robot_msgs/msg/detail/landmark__struct.h"

/// Struct defined in msg/Hand in the package robot_msgs.
typedef struct robot_msgs__msg__Hand
{
  rosidl_runtime_c__String gesture;
  float center[2];
  robot_msgs__msg__Landmark__Sequence landmarks;
} robot_msgs__msg__Hand;

// Struct for a sequence of robot_msgs__msg__Hand.
typedef struct robot_msgs__msg__Hand__Sequence
{
  robot_msgs__msg__Hand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_msgs__msg__Hand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_MSGS__MSG__DETAIL__HAND__STRUCT_H_
