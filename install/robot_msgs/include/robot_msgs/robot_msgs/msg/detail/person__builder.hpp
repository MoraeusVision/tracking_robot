// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_msgs:msg/Person.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_MSGS__MSG__DETAIL__PERSON__BUILDER_HPP_
#define ROBOT_MSGS__MSG__DETAIL__PERSON__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_msgs/msg/detail/person__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_msgs
{

namespace msg
{

namespace builder
{

class Init_Person_bbox_xyxy
{
public:
  explicit Init_Person_bbox_xyxy(::robot_msgs::msg::Person & msg)
  : msg_(msg)
  {}
  ::robot_msgs::msg::Person bbox_xyxy(::robot_msgs::msg::Person::_bbox_xyxy_type arg)
  {
    msg_.bbox_xyxy = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_msgs::msg::Person msg_;
};

class Init_Person_id
{
public:
  Init_Person_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Person_bbox_xyxy id(::robot_msgs::msg::Person::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_Person_bbox_xyxy(msg_);
  }

private:
  ::robot_msgs::msg::Person msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_msgs::msg::Person>()
{
  return robot_msgs::msg::builder::Init_Person_id();
}

}  // namespace robot_msgs

#endif  // ROBOT_MSGS__MSG__DETAIL__PERSON__BUILDER_HPP_
