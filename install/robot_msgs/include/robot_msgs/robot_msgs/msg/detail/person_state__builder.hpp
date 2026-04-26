// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from robot_msgs:msg/PersonState.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_MSGS__MSG__DETAIL__PERSON_STATE__BUILDER_HPP_
#define ROBOT_MSGS__MSG__DETAIL__PERSON_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "robot_msgs/msg/detail/person_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace robot_msgs
{

namespace msg
{

namespace builder
{

class Init_PersonState_visible
{
public:
  explicit Init_PersonState_visible(::robot_msgs::msg::PersonState & msg)
  : msg_(msg)
  {}
  ::robot_msgs::msg::PersonState visible(::robot_msgs::msg::PersonState::_visible_type arg)
  {
    msg_.visible = std::move(arg);
    return std::move(msg_);
  }

private:
  ::robot_msgs::msg::PersonState msg_;
};

class Init_PersonState_palm_held_seconds
{
public:
  explicit Init_PersonState_palm_held_seconds(::robot_msgs::msg::PersonState & msg)
  : msg_(msg)
  {}
  Init_PersonState_visible palm_held_seconds(::robot_msgs::msg::PersonState::_palm_held_seconds_type arg)
  {
    msg_.palm_held_seconds = std::move(arg);
    return Init_PersonState_visible(msg_);
  }

private:
  ::robot_msgs::msg::PersonState msg_;
};

class Init_PersonState_tracked
{
public:
  explicit Init_PersonState_tracked(::robot_msgs::msg::PersonState & msg)
  : msg_(msg)
  {}
  Init_PersonState_palm_held_seconds tracked(::robot_msgs::msg::PersonState::_tracked_type arg)
  {
    msg_.tracked = std::move(arg);
    return Init_PersonState_palm_held_seconds(msg_);
  }

private:
  ::robot_msgs::msg::PersonState msg_;
};

class Init_PersonState_last_seen
{
public:
  explicit Init_PersonState_last_seen(::robot_msgs::msg::PersonState & msg)
  : msg_(msg)
  {}
  Init_PersonState_tracked last_seen(::robot_msgs::msg::PersonState::_last_seen_type arg)
  {
    msg_.last_seen = std::move(arg);
    return Init_PersonState_tracked(msg_);
  }

private:
  ::robot_msgs::msg::PersonState msg_;
};

class Init_PersonState_bbox_xyxy
{
public:
  explicit Init_PersonState_bbox_xyxy(::robot_msgs::msg::PersonState & msg)
  : msg_(msg)
  {}
  Init_PersonState_last_seen bbox_xyxy(::robot_msgs::msg::PersonState::_bbox_xyxy_type arg)
  {
    msg_.bbox_xyxy = std::move(arg);
    return Init_PersonState_last_seen(msg_);
  }

private:
  ::robot_msgs::msg::PersonState msg_;
};

class Init_PersonState_id
{
public:
  Init_PersonState_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PersonState_bbox_xyxy id(::robot_msgs::msg::PersonState::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_PersonState_bbox_xyxy(msg_);
  }

private:
  ::robot_msgs::msg::PersonState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::robot_msgs::msg::PersonState>()
{
  return robot_msgs::msg::builder::Init_PersonState_id();
}

}  // namespace robot_msgs

#endif  // ROBOT_MSGS__MSG__DETAIL__PERSON_STATE__BUILDER_HPP_
