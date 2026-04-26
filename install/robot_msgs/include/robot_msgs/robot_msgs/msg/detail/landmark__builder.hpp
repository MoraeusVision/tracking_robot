// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_msgs:msg/Landmark.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_MSGS__MSG__DETAIL__LANDMARK__BUILDER_HPP_
#define ROBOT_MSGS__MSG__DETAIL__LANDMARK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_msgs/msg/detail/landmark__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_msgs
{

namespace msg
{

namespace builder
{

class Init_Landmark_z
{
public:
  explicit Init_Landmark_z(::robot_msgs::msg::Landmark & msg)
  : msg_(msg)
  {}
  ::robot_msgs::msg::Landmark z(::robot_msgs::msg::Landmark::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_msgs::msg::Landmark msg_;
};

class Init_Landmark_y
{
public:
  explicit Init_Landmark_y(::robot_msgs::msg::Landmark & msg)
  : msg_(msg)
  {}
  Init_Landmark_z y(::robot_msgs::msg::Landmark::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Landmark_z(msg_);
  }

private:
  ::robot_msgs::msg::Landmark msg_;
};

class Init_Landmark_x
{
public:
  Init_Landmark_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Landmark_y x(::robot_msgs::msg::Landmark::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Landmark_y(msg_);
  }

private:
  ::robot_msgs::msg::Landmark msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_msgs::msg::Landmark>()
{
  return robot_msgs::msg::builder::Init_Landmark_x();
}

}  // namespace robot_msgs

#endif  // ROBOT_MSGS__MSG__DETAIL__LANDMARK__BUILDER_HPP_
