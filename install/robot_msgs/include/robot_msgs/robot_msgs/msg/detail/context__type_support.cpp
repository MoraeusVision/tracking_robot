// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from robot_msgs:msg/Context.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "robot_msgs/msg/detail/context__struct.hpp"
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

void Context_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) robot_msgs::msg::Context(_init);
}

void Context_fini_function(void * message_memory)
{
  auto typed_message = static_cast<robot_msgs::msg::Context *>(message_memory);
  typed_message->~Context();
}

size_t size_function__Context__persons(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<robot_msgs::msg::PersonState> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Context__persons(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<robot_msgs::msg::PersonState> *>(untyped_member);
  return &member[index];
}

void * get_function__Context__persons(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<robot_msgs::msg::PersonState> *>(untyped_member);
  return &member[index];
}

void fetch_function__Context__persons(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const robot_msgs::msg::PersonState *>(
    get_const_function__Context__persons(untyped_member, index));
  auto & value = *reinterpret_cast<robot_msgs::msg::PersonState *>(untyped_value);
  value = item;
}

void assign_function__Context__persons(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<robot_msgs::msg::PersonState *>(
    get_function__Context__persons(untyped_member, index));
  const auto & value = *reinterpret_cast<const robot_msgs::msg::PersonState *>(untyped_value);
  item = value;
}

void resize_function__Context__persons(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<robot_msgs::msg::PersonState> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Context_message_member_array[2] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_msgs::msg::Context, header),  // bytes offset in struct
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
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<robot_msgs::msg::PersonState>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(robot_msgs::msg::Context, persons),  // bytes offset in struct
    nullptr,  // default value
    size_function__Context__persons,  // size() function pointer
    get_const_function__Context__persons,  // get_const(index) function pointer
    get_function__Context__persons,  // get(index) function pointer
    fetch_function__Context__persons,  // fetch(index, &value) function pointer
    assign_function__Context__persons,  // assign(index, value) function pointer
    resize_function__Context__persons  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Context_message_members = {
  "robot_msgs::msg",  // message namespace
  "Context",  // message name
  2,  // number of fields
  sizeof(robot_msgs::msg::Context),
  Context_message_member_array,  // message members
  Context_init_function,  // function to initialize message memory (memory has to be allocated)
  Context_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Context_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Context_message_members,
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
get_message_type_support_handle<robot_msgs::msg::Context>()
{
  return &::robot_msgs::msg::rosidl_typesupport_introspection_cpp::Context_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, robot_msgs, msg, Context)() {
  return &::robot_msgs::msg::rosidl_typesupport_introspection_cpp::Context_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
