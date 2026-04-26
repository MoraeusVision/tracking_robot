// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from robot_msgs:msg/PersonState.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_MSGS__MSG__DETAIL__PERSON_STATE__STRUCT_H_
#define ROBOT_MSGS__MSG__DETAIL__PERSON_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/PersonState in the package robot_msgs.
typedef struct robot_msgs__msg__PersonState
{
  int32_t id;
  float bbox_xyxy[4];
  int32_t last_seen;
  bool tracked;
  int32_t palm_held_seconds;
  bool visible;
} robot_msgs__msg__PersonState;

// Struct for a sequence of robot_msgs__msg__PersonState.
typedef struct robot_msgs__msg__PersonState__Sequence
{
  robot_msgs__msg__PersonState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} robot_msgs__msg__PersonState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROBOT_MSGS__MSG__DETAIL__PERSON_STATE__STRUCT_H_
