// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from robot_msgs:msg/Prediction.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "robot_msgs/msg/detail/prediction__struct.hpp"
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

void Prediction_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) robot_msgs::msg::Prediction(_init);
}

void Prediction_fini_function(void * message_memory)
{
  auto typed_message = static_cast<robot_msgs::msg::Prediction *>(message_memory);
  typed_message->~Prediction();
}

size_t size_function__Prediction__persons(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<robot_msgs::msg::Person> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Prediction__persons(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<robot_msgs::msg::Person> *>(untyped_member);
  return &member[index];
}

void * get_function__Prediction__persons(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<robot_msgs::msg::Person> *>(untyped_member);
  return &member[index];
}

void fetch_function__Prediction__persons(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const robot_msgs::msg::Person *>(
    get_const_function__Prediction__persons(untyped_member, index));
  auto & value = *reinterpret_cast<robot_msgs::msg::Person *>(untyped_value);
  value = item;
}

void assign_function__Prediction__persons(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<robot_msgs::msg::Person *>(
    get_function__Prediction__persons(untyped_member, index));
  const auto & value = *reinterpret_cast<const robot_msgs::msg::Person *>(untyped_value);
  item = value;
}

void resize_function__Prediction__persons(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<robot_msgs::msg::Person> *>(untyped_member);
  member->resize(size);
}

size_t size_function__Prediction__hands(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<robot_msgs::msg::Hand> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Prediction__hands(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<robot_msgs::msg::Hand> *>(untyped_member);
  return &member[index];
}

void * get_function__Prediction__hands(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<robot_msgs::msg::Hand> *>(untyped_member);
  return &member[index];
}

void fetch_function__Prediction__hands(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const robot_msgs::msg::Hand *>(
    get_const_function__Prediction__hands(untyped_member, index));
  auto & value = *reinterpret_cast<robot_msgs::msg::Hand *>(untyped_value);
  value = item;
}

void assign_function__Prediction__hands(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<robot_msgs::msg::Hand *>(
    get_function__Prediction__hands(untyped_member, index));
  const auto & value = *reinterpret_cast<const robot_msgs::msg::Hand *>(untyped_value);
  item = value;
}

void resize_function__Prediction__hands(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<robot_msgs::msg::Hand> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Prediction_message_member_array[3] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_msgs::msg::Prediction, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "persons",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<robot_msgs::msg::Person>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_msgs::msg::Prediction, persons),  // bytes offset in struct
    nullptr,  // default value
    size_function__Prediction__persons,  // size() function pointer
    get_const_function__Prediction__persons,  // get_const(index) function pointer
    get_function__Prediction__persons,  // get(index) function pointer
    fetch_function__Prediction__persons,  // fetch(index, &value) function pointer
    assign_function__Prediction__persons,  // assign(index, value) function pointer
    resize_function__Prediction__persons  // resize(index) function pointer
  },
  {
    "hands",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<robot_msgs::msg::Hand>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_msgs::msg::Prediction, hands),  // bytes offset in struct
    nullptr,  // default value
    size_function__Prediction__hands,  // size() function pointer
    get_const_function__Prediction__hands,  // get_const(index) function pointer
    get_function__Prediction__hands,  // get(index) function pointer
    fetch_function__Prediction__hands,  // fetch(index, &value) function pointer
    assign_function__Prediction__hands,  // assign(index, value) function pointer
    resize_function__Prediction__hands  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Prediction_message_members = {
  "robot_msgs::msg",  // message namespace
  "Prediction",  // message name
  3,  // number of fields
  sizeof(robot_msgs::msg::Prediction),
  Prediction_message_member_array,  // message members
  Prediction_init_function,  // function to initialize message memory (memory has to be allocated)
  Prediction_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Prediction_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Prediction_message_members,
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
get_message_type_support_handle<robot_msgs::msg::Prediction>()
{
  return &::robot_msgs::msg::rosidl_typesupport_introspection_cpp::Prediction_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robot_msgs, msg, Prediction)() {
  return &::robot_msgs::msg::rosidl_typesupport_introspection_cpp::Prediction_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
