// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from robot_msgs:msg/PersonState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "robot_msgs/msg/detail/person_state__rosidl_typesupport_introspection_c.h"
#include "robot_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "robot_msgs/msg/detail/person_state__functions.h"
#include "robot_msgs/msg/detail/person_state__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void robot_msgs__msg__PersonState__rosidl_typesupport_introspection_c__PersonState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  robot_msgs__msg__PersonState__init(message_memory);
}

void robot_msgs__msg__PersonState__rosidl_typesupport_introspection_c__PersonState_fini_function(void * message_memory)
{
  robot_msgs__msg__PersonState__fini(message_memory);
}

size_t robot_msgs__msg__PersonState__rosidl_typesupport_introspection_c__size_function__PersonState__bbox_xyxy(
  const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * robot_msgs__msg__PersonState__rosidl_typesupport_introspection_c__get_const_function__PersonState__bbox_xyxy(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * robot_msgs__msg__PersonState__rosidl_typesupport_introspection_c__get_function__PersonState__bbox_xyxy(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void robot_msgs__msg__PersonState__rosidl_typesupport_introspection_c__fetch_function__PersonState__bbox_xyxy(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    robot_msgs__msg__PersonState__rosidl_typesupport_introspection_c__get_const_function__PersonState__bbox_xyxy(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void robot_msgs__msg__PersonState__rosidl_typesupport_introspection_c__assign_function__PersonState__bbox_xyxy(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    robot_msgs__msg__PersonState__rosidl_typesupport_introspection_c__get_function__PersonState__bbox_xyxy(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember robot_msgs__msg__PersonState__rosidl_typesupport_introspection_c__PersonState_message_member_array[6] = {
  {
    "id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_msgs__msg__PersonState, id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "bbox_xyxy",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(robot_msgs__msg__PersonState, bbox_xyxy),  // bytes offset in struct
    NULL,  // default value
    robot_msgs__msg__PersonState__rosidl_typesupport_introspection_c__size_function__PersonState__bbox_xyxy,  // size() function pointer
    robot_msgs__msg__PersonState__rosidl_typesupport_introspection_c__get_const_function__PersonState__bbox_xyxy,  // get_const(index) function pointer
    robot_msgs__msg__PersonState__rosidl_typesupport_introspection_c__get_function__PersonState__bbox_xyxy,  // get(index) function pointer
    robot_msgs__msg__PersonState__rosidl_typesupport_introspection_c__fetch_function__PersonState__bbox_xyxy,  // fetch(index, &value) function pointer
    robot_msgs__msg__PersonState__rosidl_typesupport_introspection_c__assign_function__PersonState__bbox_xyxy,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "last_seen",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_msgs__msg__PersonState, last_seen),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "tracked",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_msgs__msg__PersonState, tracked),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "palm_held_seconds",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_msgs__msg__PersonState, palm_held_seconds),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "visible",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_msgs__msg__PersonState, visible),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers robot_msgs__msg__PersonState__rosidl_typesupport_introspection_c__PersonState_message_members = {
  "robot_msgs__msg",  // message namespace
  "PersonState",  // message name
  6,  // number of fields
  sizeof(robot_msgs__msg__PersonState),
  robot_msgs__msg__PersonState__rosidl_typesupport_introspection_c__PersonState_message_member_array,  // message members
  robot_msgs__msg__PersonState__rosidl_typesupport_introspection_c__PersonState_init_function,  // function to initialize message memory (memory has to be allocated)
  robot_msgs__msg__PersonState__rosidl_typesupport_introspection_c__PersonState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t robot_msgs__msg__PersonState__rosidl_typesupport_introspection_c__PersonState_message_type_support_handle = {
  0,
  &robot_msgs__msg__PersonState__rosidl_typesupport_introspection_c__PersonState_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_robot_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robot_msgs, msg, PersonState)() {
  if (!robot_msgs__msg__PersonState__rosidl_typesupport_introspection_c__PersonState_message_type_support_handle.typesupport_identifier) {
    robot_msgs__msg__PersonState__rosidl_typesupport_introspection_c__PersonState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &robot_msgs__msg__PersonState__rosidl_typesupport_introspection_c__PersonState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
