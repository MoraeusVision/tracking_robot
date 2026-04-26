// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from robot_msgs:msg/Prediction.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "robot_msgs/msg/detail/prediction__rosidl_typesupport_introspection_c.h"
#include "robot_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "robot_msgs/msg/detail/prediction__functions.h"
#include "robot_msgs/msg/detail/prediction__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `persons`
#include "robot_msgs/msg/person.h"
// Member `persons`
#include "robot_msgs/msg/detail/person__rosidl_typesupport_introspection_c.h"
// Member `hands`
#include "robot_msgs/msg/hand.h"
// Member `hands`
#include "robot_msgs/msg/detail/hand__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__Prediction_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  robot_msgs__msg__Prediction__init(message_memory);
}

void robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__Prediction_fini_function(void * message_memory)
{
  robot_msgs__msg__Prediction__fini(message_memory);
}

size_t robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__size_function__Prediction__persons(
  const void * untyped_member)
{
  const robot_msgs__msg__Person__Sequence * member =
    (const robot_msgs__msg__Person__Sequence *)(untyped_member);
  return member->size;
}

const void * robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__get_const_function__Prediction__persons(
  const void * untyped_member, size_t index)
{
  const robot_msgs__msg__Person__Sequence * member =
    (const robot_msgs__msg__Person__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__get_function__Prediction__persons(
  void * untyped_member, size_t index)
{
  robot_msgs__msg__Person__Sequence * member =
    (robot_msgs__msg__Person__Sequence *)(untyped_member);
  return &member->data[index];
}

void robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__fetch_function__Prediction__persons(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const robot_msgs__msg__Person * item =
    ((const robot_msgs__msg__Person *)
    robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__get_const_function__Prediction__persons(untyped_member, index));
  robot_msgs__msg__Person * value =
    (robot_msgs__msg__Person *)(untyped_value);
  *value = *item;
}

void robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__assign_function__Prediction__persons(
  void * untyped_member, size_t index, const void * untyped_value)
{
  robot_msgs__msg__Person * item =
    ((robot_msgs__msg__Person *)
    robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__get_function__Prediction__persons(untyped_member, index));
  const robot_msgs__msg__Person * value =
    (const robot_msgs__msg__Person *)(untyped_value);
  *item = *value;
}

bool robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__resize_function__Prediction__persons(
  void * untyped_member, size_t size)
{
  robot_msgs__msg__Person__Sequence * member =
    (robot_msgs__msg__Person__Sequence *)(untyped_member);
  robot_msgs__msg__Person__Sequence__fini(member);
  return robot_msgs__msg__Person__Sequence__init(member, size);
}

size_t robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__size_function__Prediction__hands(
  const void * untyped_member)
{
  const robot_msgs__msg__Hand__Sequence * member =
    (const robot_msgs__msg__Hand__Sequence *)(untyped_member);
  return member->size;
}

const void * robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__get_const_function__Prediction__hands(
  const void * untyped_member, size_t index)
{
  const robot_msgs__msg__Hand__Sequence * member =
    (const robot_msgs__msg__Hand__Sequence *)(untyped_member);
  return &member->data[index];
}

void * robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__get_function__Prediction__hands(
  void * untyped_member, size_t index)
{
  robot_msgs__msg__Hand__Sequence * member =
    (robot_msgs__msg__Hand__Sequence *)(untyped_member);
  return &member->data[index];
}

void robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__fetch_function__Prediction__hands(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const robot_msgs__msg__Hand * item =
    ((const robot_msgs__msg__Hand *)
    robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__get_const_function__Prediction__hands(untyped_member, index));
  robot_msgs__msg__Hand * value =
    (robot_msgs__msg__Hand *)(untyped_value);
  *value = *item;
}

void robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__assign_function__Prediction__hands(
  void * untyped_member, size_t index, const void * untyped_value)
{
  robot_msgs__msg__Hand * item =
    ((robot_msgs__msg__Hand *)
    robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__get_function__Prediction__hands(untyped_member, index));
  const robot_msgs__msg__Hand * value =
    (const robot_msgs__msg__Hand *)(untyped_value);
  *item = *value;
}

bool robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__resize_function__Prediction__hands(
  void * untyped_member, size_t size)
{
  robot_msgs__msg__Hand__Sequence * member =
    (robot_msgs__msg__Hand__Sequence *)(untyped_member);
  robot_msgs__msg__Hand__Sequence__fini(member);
  return robot_msgs__msg__Hand__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__Prediction_message_member_array[3] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_msgs__msg__Prediction, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "persons",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_msgs__msg__Prediction, persons),  // bytes offset in struct
    NULL,  // default value
    robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__size_function__Prediction__persons,  // size() function pointer
    robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__get_const_function__Prediction__persons,  // get_const(index) function pointer
    robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__get_function__Prediction__persons,  // get(index) function pointer
    robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__fetch_function__Prediction__persons,  // fetch(index, &value) function pointer
    robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__assign_function__Prediction__persons,  // assign(index, value) function pointer
    robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__resize_function__Prediction__persons  // resize(index) function pointer
  },
  {
    "hands",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_msgs__msg__Prediction, hands),  // bytes offset in struct
    NULL,  // default value
    robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__size_function__Prediction__hands,  // size() function pointer
    robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__get_const_function__Prediction__hands,  // get_const(index) function pointer
    robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__get_function__Prediction__hands,  // get(index) function pointer
    robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__fetch_function__Prediction__hands,  // fetch(index, &value) function pointer
    robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__assign_function__Prediction__hands,  // assign(index, value) function pointer
    robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__resize_function__Prediction__hands  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__Prediction_message_members = {
  "robot_msgs__msg",  // message namespace
  "Prediction",  // message name
  3,  // number of fields
  sizeof(robot_msgs__msg__Prediction),
  robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__Prediction_message_member_array,  // message members
  robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__Prediction_init_function,  // function to initialize message memory (memory has to be allocated)
  robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__Prediction_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__Prediction_message_type_support_handle = {
  0,
  &robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__Prediction_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_robot_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robot_msgs, msg, Prediction)() {
  robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__Prediction_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__Prediction_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robot_msgs, msg, Person)();
  robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__Prediction_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, robot_msgs, msg, Hand)();
  if (!robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__Prediction_message_type_support_handle.typesupport_identifier) {
    robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__Prediction_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &robot_msgs__msg__Prediction__rosidl_typesupport_introspection_c__Prediction_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
