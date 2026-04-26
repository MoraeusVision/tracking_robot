// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_msgs:msg/Context.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_MSGS__MSG__DETAIL__CONTEXT__BUILDER_HPP_
#define ROBOT_MSGS__MSG__DETAIL__CONTEXT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_msgs/msg/detail/context__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_msgs
{

namespace msg
{

namespace builder
{

class Init_Context_persons
{
public:
  explicit Init_Context_persons(::robot_msgs::msg::Context & msg)
  : msg_(msg)
  {}
  ::robot_msgs::msg::Context persons(::robot_msgs::msg::Context::_persons_type arg)
  {
    msg_.persons = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_msgs::msg::Context msg_;
};

class Init_Context_header
{
public:
  Init_Context_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Context_persons header(::robot_msgs::msg::Context::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Context_persons(msg_);
  }

private:
  ::robot_msgs::msg::Context msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_msgs::msg::Context>()
{
  return robot_msgs::msg::builder::Init_Context_header();
}

}  // namespace robot_msgs

#endif  // ROBOT_MSGS__MSG__DETAIL__CONTEXT__BUILDER_HPP_
