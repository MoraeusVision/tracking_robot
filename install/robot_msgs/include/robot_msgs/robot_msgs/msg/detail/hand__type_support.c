// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from robot_msgs:msg/Hand.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "robot_msgs/msg/detail/hand__rosidl_typesupport_introspection_c.h"
#include "robot_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "robot_msgs/msg/detail/hand__functions.h"
#include "robot_msgs/msg/detail/hand__struct.h"


// Include directives for member types
// Member `gesture`
#include "rosidl_runtime_c/string_functions.h"
// Member `landmarks`
#include "robot_msgs/msg/landmark.h"
// Member `landmarks`
#include "robot_msgs/msg/detail/landmark__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void robot_msgs__msg__Hand__rosidl_typesupport_introspection_c__Hand_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  robot_msgs__msg__Hand__init(message_memory);
}

void robot_msgs__msg__Hand__rosidl_typesupport_introspection_c__Hand_fini_function(void * message_memory)
{
  robot_msgs__msg__Hand__fini(message_memory);
}

size_t robot_msgs__msg__Hand__rosidl_typesupport_introspection_c__size_function__Hand__center(
  const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * robot_msgs__msg__Hand__rosidl_typesupport_introspection_c__get_const_function__Hand__center(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * robot_msgs__msg__Hand__rosidl_typesupport_introspection_c__get_function__Hand__center(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void robot_msgs__msg__Hand__rosidl_typesupport_introspection_c__fetch_function__Hand__center(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    robot_msgs__msg__Hand__rosidl_typesupport_introspection_c__get_const_function__Hand__center(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void robot_msgs__msg__Hand__rosidl_typesupport_introspection_c__assign_function__Hand__center(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    robot_msgs__msg__Hand__rosidl_typesupport_introspection_c__get_function__Hand__center(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

size_t robot_msgs__msg__Hand__rosidl_typesupport_introspection_c__size_function__Hand__landmarks(
  const void * untyped_member)
{
  const robot_msgs__msg__Landmark__Sequence * member =
    (const robot_msgs__msg__Landmark__Sequence *)(untyped_member);
  return member->size;
}

const void * robot_msgs__msg__Hand__rosidl_typesupport_introspection_c__get_const_function__Hand__landmarks(
  const void * untyped_member, size_t index)
{
  const robot_msgs__msg__Landmark__Sequence * member =
    (const robot_msgs__msg__Landmark__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robot_msgs__msg__Hand__rosidl_typesupport_introspection_c__get_function__Hand__landmarks(
  void * untyped_member, size_t index)
{
  robot_msgs__msg__Landmark__Sequence * member =
    (robot_msgs__msg__Landmark__Sequence *)(untyped_member);
  return &member->data[index];
}

void robot_msgs__msg__Hand__rosidl_typesupport_introspection_c__fetch_function__Hand__landmarks(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const robot_msgs__msg__Landmark * item =
    ((const robot_msgs__msg__Landmark *)
    robot_msgs__msg__Hand__rosidl_typesupport_introspection_c__get_const_function__Hand__landmarks(untyped_member, index));
  robot_msgs__msg__Landmark * value =
    (robot_msgs__msg__Landmark *)(untyped_value);
  *value = *item;
}

void robot_msgs__msg__Hand__rosidl_typesupport_introspection_c__assign_function__Hand__landmarks(
  void * untyped_member, size_t index, const void * untyped_value)
{
  robot_msgs__msg__Landmark * item =
    ((robot_msgs__msg__Landmark *)
    robot_msgs__msg__Hand__rosidl_typesupport_introspection_c__get_function__Hand__landmarks(untyped_member, index));
  const robot_msgs__msg__Landmark * value =
    (const robot_msgs__msg__Landmark *)(untyped_value);
  *item = *value;
}

bool robot_msgs__msg__Hand__rosidl_typesupport_introspection_c__resize_function__Hand__landmarks(
  void * untyped_member, size_t size)
{
  robot_msgs__msg__Landmark__Sequence * member =
    (robot_msgs__msg__Landmark__Sequence *)(untyped_member);
  robot_msgs__msg__Landmark__Sequence__fini(member);
  return robot_msgs__msg__Landmark__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember robot_msgs__msg__Hand__rosidl_typesupport_introspection_c__Hand_message_member_array[3] = {
  {
    "gesture",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_msgs__msg__Hand, gesture),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "center",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(robot_msgs__msg__Hand, center),  // bytes offset in struct
    NULL,  // default value
    robot_msgs__msg__Hand__rosidl_typesupport_introspection_c__size_function__Hand__center,  // size() function pointer
    robot_msgs__msg__Hand__rosidl_typesupport_introspection_c__get_const_function__Hand__center,  // get_const(index) function pointer
    robot_msgs__msg__Hand__rosidl_typesupport_introspection_c__get_function__Hand__center,  // get(index) function pointer
    robot_msgs__msg__Hand__rosidl_typesupport_introspection_c__fetch_function__Hand__center,  // fetch(index, &value) function pointer
    robot_msgs__msg__Hand__rosidl_typesupport_introspection_c__assign_function__Hand__center,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "landmarks",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_msgs__msg__Hand, landmarks),  // bytes offset in struct
    NULL,  // default value
    robot_msgs__msg__Hand__rosidl_typesupport_introspection_c__size_function__Hand__landmarks,  // size() function pointer
    robot_msgs__msg__Hand__rosidl_typesupport_introspection_c__get_const_function__Hand__landmarks,  // get_const(index) function pointer
    robot_msgs__msg__Hand__rosidl_typesupport_introspection_c__get_function__Hand__landmarks,  // get(index) function pointer
    robot_msgs__msg__Hand__rosidl_typesupport_introspection_c__fetch_function__Hand__landmarks,  // fetch(index, &value) function pointer
    robot_msgs__msg__Hand__rosidl_typesupport_introspection_c__assign_function__Hand__landmarks,  // assign(index, value) function pointer
    robot_msgs__msg__Hand__rosidl_typesupport_introspection_c__resize_function__Hand__landmarks  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers robot_msgs__msg__Hand__rosidl_typesupport_introspection_c__Hand_message_members = {
  "robot_msgs__msg",  // message namespace
  "Hand",  // message name
  3,  // number of fields
  sizeof(robot_msgs__msg__Hand),
  robot_msgs__msg__Hand__rosidl_typesupport_introspection_c__Hand_message_member_array,  // message members
  robot_msgs__msg__Hand__rosidl_typesupport_introspection_c__Hand_init_function,  // function to initialize message memory (memory has to be allocated)
  robot_msgs__msg__Hand__rosidl_typesupport_introspection_c__Hand_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t robot_msgs__msg__Hand__rosidl_typesupport_introspection_c__Hand_message_type_support_handle = {
  0,
  &robot_msgs__msg__Hand__rosidl_typesupport_introspection_c__Hand_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_robot_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robot_msgs, msg, Hand)() {
  robot_msgs__msg__Hand__rosidl_typesupport_introspection_c__Hand_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robot_msgs, msg, Landmark)();
  if (!robot_msgs__msg__Hand__rosidl_typesupport_introspection_c__Hand_message_type_support_handle.typesupport_identifier) {
    robot_msgs__msg__Hand__rosidl_typesupport_introspection_c__Hand_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &robot_msgs__msg__Hand__rosidl_typesupport_introspection_c__Hand_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
