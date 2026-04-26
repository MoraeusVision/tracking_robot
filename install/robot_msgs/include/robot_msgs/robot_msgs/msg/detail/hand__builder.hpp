// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_msgs:msg/Hand.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_MSGS__MSG__DETAIL__HAND__BUILDER_HPP_
#define ROBOT_MSGS__MSG__DETAIL__HAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_msgs/msg/detail/hand__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_msgs
{

namespace msg
{

namespace builder
{

class Init_Hand_landmarks
{
public:
  explicit Init_Hand_landmarks(::robot_msgs::msg::Hand & msg)
  : msg_(msg)
  {}
  ::robot_msgs::msg::Hand landmarks(::robot_msgs::msg::Hand::_landmarks_type arg)
  {
    msg_.landmarks = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_msgs::msg::Hand msg_;
};

class Init_Hand_center
{
public:
  explicit Init_Hand_center(::robot_msgs::msg::Hand & msg)
  : msg_(msg)
  {}
  Init_Hand_landmarks center(::robot_msgs::msg::Hand::_center_type arg)
  {
    msg_.center = std::move(arg);
    return Init_Hand_landmarks(msg_);
  }

private:
  ::robot_msgs::msg::Hand msg_;
};

class Init_Hand_gesture
{
public:
  Init_Hand_gesture()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Hand_center gesture(::robot_msgs::msg::Hand::_gesture_type arg)
  {
    msg_.gesture = std::move(arg);
    return Init_Hand_center(msg_);
  }

private:
  ::robot_msgs::msg::Hand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_msgs::msg::Hand>()
{
  return robot_msgs::msg::builder::Init_Hand_gesture();
}

}  // namespace robot_msgs

#endif  // ROBOT_MSGS__MSG__DETAIL__HAND__BUILDER_HPP_
