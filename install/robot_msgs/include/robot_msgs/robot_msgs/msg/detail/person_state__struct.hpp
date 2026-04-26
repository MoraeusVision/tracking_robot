// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robot_msgs:msg/PersonState.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_MSGS__MSG__DETAIL__PERSON_STATE__STRUCT_HPP_
#define ROBOT_MSGS__MSG__DETAIL__PERSON_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__robot_msgs__msg__PersonState __attribute__((deprecated))
#else
# define DEPRECATED__robot_msgs__msg__PersonState __declspec(deprecated)
#endif

namespace robot_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PersonState_
{
  using Type = PersonState_<ContainerAllocator>;

  explicit PersonState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      std::fill<typename std::array<float, 4>::iterator, float>(this->bbox_xyxy.begin(), this->bbox_xyxy.end(), 0.0f);
      this->last_seen = 0l;
      this->tracked = false;
      this->palm_held_seconds = 0l;
      this->visible = false;
    }
  }

  explicit PersonState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : bbox_xyxy(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      std::fill<typename std::array<float, 4>::iterator, float>(this->bbox_xyxy.begin(), this->bbox_xyxy.end(), 0.0f);
      this->last_seen = 0l;
      this->tracked = false;
      this->palm_held_seconds = 0l;
      this->visible = false;
    }
  }

  // field types and members
  using _id_type =
    int32_t;
  _id_type id;
  using _bbox_xyxy_type =
    std::array<float, 4>;
  _bbox_xyxy_type bbox_xyxy;
  using _last_seen_type =
    int32_t;
  _last_seen_type last_seen;
  using _tracked_type =
    bool;
  _tracked_type tracked;
  using _palm_held_seconds_type =
    int32_t;
  _palm_held_seconds_type palm_held_seconds;
  using _visible_type =
    bool;
  _visible_type visible;

  // setters for named parameter idiom
  Type & set__id(
    const int32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__bbox_xyxy(
    const std::array<float, 4> & _arg)
  {
    this->bbox_xyxy = _arg;
    return *this;
  }
  Type & set__last_seen(
    const int32_t & _arg)
  {
    this->last_seen = _arg;
    return *this;
  }
  Type & set__tracked(
    const bool & _arg)
  {
    this->tracked = _arg;
    return *this;
  }
  Type & set__palm_held_seconds(
    const int32_t & _arg)
  {
    this->palm_held_seconds = _arg;
    return *this;
  }
  Type & set__visible(
    const bool & _arg)
  {
    this->visible = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_msgs::msg::PersonState_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_msgs::msg::PersonState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_msgs::msg::PersonState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_msgs::msg::PersonState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_msgs::msg::PersonState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_msgs::msg::PersonState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_msgs::msg::PersonState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_msgs::msg::PersonState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_msgs::msg::PersonState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_msgs::msg::PersonState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_msgs__msg__PersonState
    std::shared_ptr<robot_msgs::msg::PersonState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_msgs__msg__PersonState
    std::shared_ptr<robot_msgs::msg::PersonState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PersonState_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->bbox_xyxy != other.bbox_xyxy) {
      return false;
    }
    if (this->last_seen != other.last_seen) {
      return false;
    }
    if (this->tracked != other.tracked) {
      return false;
    }
    if (this->palm_held_seconds != other.palm_held_seconds) {
      return false;
    }
    if (this->visible != other.visible) {
      return false;
    }
    return true;
  }
  bool operator!=(const PersonState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PersonState_

// alias to use template instance with default allocator
using PersonState =
  robot_msgs::msg::PersonState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace robot_msgs

#endif  // ROBOT_MSGS__MSG__DETAIL__PERSON_STATE__STRUCT_HPP_
