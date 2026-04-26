// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from robot_msgs:msg/Hand.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "robot_msgs/msg/detail/hand__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace robot_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Hand_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) robot_msgs::msg::Hand(_init);
}

void Hand_fini_function(void * message_memory)
{
  auto typed_message = static_cast<robot_msgs::msg::Hand *>(message_memory);
  typed_message->~Hand();
}

size_t size_function__Hand__center(const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * get_const_function__Hand__center(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 2> *>(untyped_member);
  return &member[index];
}

void * get_function__Hand__center(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 2> *>(untyped_member);
  return &member[index];
}

void fetch_function__Hand__center(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__Hand__center(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__Hand__center(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__Hand__center(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

size_t size_function__Hand__landmarks(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<robot_msgs::msg::Landmark> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Hand__landmarks(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<robot_msgs::msg::Landmark> *>(untyped_member);
  return &member[index];
}

void * get_function__Hand__landmarks(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<robot_msgs::msg::Landmark> *>(untyped_member);
  return &member[index];
}

void fetch_function__Hand__landmarks(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const robot_msgs::msg::Landmark *>(
    get_const_function__Hand__landmarks(untyped_member, index));
  auto & value = *reinterpret_cast<robot_msgs::msg::Landmark *>(untyped_value);
  value = item;
}

void assign_function__Hand__landmarks(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<robot_msgs::msg::Landmark *>(
    get_function__Hand__landmarks(untyped_member, index));
  const auto & value = *reinterpret_cast<const robot_msgs::msg::Landmark *>(untyped_value);
  item = value;
}

void resize_function__Hand__landmarks(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<robot_msgs::msg::Landmark> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Hand_message_member_array[3] = {
  {
    "gesture",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_msgs::msg::Hand, gesture),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "center",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(robot_msgs::msg::Hand, center),  // bytes offset in struct
    nullptr,  // default value
    size_function__Hand__center,  // size() function pointer
    get_const_function__Hand__center,  // get_const(index) function pointer
    get_function__Hand__center,  // get(index) function pointer
    fetch_function__Hand__center,  // fetch(index, &value) function pointer
    assign_function__Hand__center,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "landmarks",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<robot_msgs::msg::Landmark>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_msgs::msg::Hand, landmarks),  // bytes offset in struct
    nullptr,  // default value
    size_function__Hand__landmarks,  // size() function pointer
    get_const_function__Hand__landmarks,  // get_const(index) function pointer
    get_function__Hand__landmarks,  // get(index) function pointer
    fetch_function__Hand__landmarks,  // fetch(index, &value) function pointer
    assign_function__Hand__landmarks,  // assign(index, value) function pointer
    resize_function__Hand__landmarks  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Hand_message_members = {
  "robot_msgs::msg",  // message namespace
  "Hand",  // message name
  3,  // number of fields
  sizeof(robot_msgs::msg::Hand),
  Hand_message_member_array,  // message members
  Hand_init_function,  // function to initialize message memory (memory has to be allocated)
  Hand_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Hand_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Hand_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace robot_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<robot_msgs::msg::Hand>()
{
  return &::robot_msgs::msg::rosidl_typesupport_introspection_cpp::Hand_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robot_msgs, msg, Hand)() {
  return &::robot_msgs::msg::rosidl_typesupport_introspection_cpp::Hand_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
