// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_msgs:msg/Prediction.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_MSGS__MSG__DETAIL__PREDICTION__BUILDER_HPP_
#define ROBOT_MSGS__MSG__DETAIL__PREDICTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_msgs/msg/detail/prediction__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_msgs
{

namespace msg
{

namespace builder
{

class Init_Prediction_hands
{
public:
  explicit Init_Prediction_hands(::robot_msgs::msg::Prediction & msg)
  : msg_(msg)
  {}
  ::robot_msgs::msg::Prediction hands(::robot_msgs::msg::Prediction::_hands_type arg)
  {
    msg_.hands = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_msgs::msg::Prediction msg_;
};

class Init_Prediction_persons
{
public:
  explicit Init_Prediction_persons(::robot_msgs::msg::Prediction & msg)
  : msg_(msg)
  {}
  Init_Prediction_hands persons(::robot_msgs::msg::Prediction::_persons_type arg)
  {
    msg_.persons = std::move(arg);
    return Init_Prediction_hands(msg_);
  }

private:
  ::robot_msgs::msg::Prediction msg_;
};

class Init_Prediction_header
{
public:
  Init_Prediction_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Prediction_persons header(::robot_msgs::msg::Prediction::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Prediction_persons(msg_);
  }

private:
  ::robot_msgs::msg::Prediction msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_msgs::msg::Prediction>()
{
  return robot_msgs::msg::builder::Init_Prediction_header();
}

}  // namespace robot_msgs

#endif  // ROBOT_MSGS__MSG__DETAIL__PREDICTION__BUILDER_HPP_
