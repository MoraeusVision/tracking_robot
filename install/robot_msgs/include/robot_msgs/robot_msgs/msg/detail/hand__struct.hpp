// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from robot_msgs:msg/Hand.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_MSGS__MSG__DETAIL__HAND__STRUCT_HPP_
#define ROBOT_MSGS__MSG__DETAIL__HAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'landmarks'
#include "robot_msgs/msg/detail/landmark__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__robot_msgs__msg__Hand __attribute__((deprecated))
#else
# define DEPRECATED__robot_msgs__msg__Hand __declspec(deprecated)
#endif

namespace robot_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Hand_
{
  using Type = Hand_<ContainerAllocator>;

  explicit Hand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->gesture = "";
      std::fill<typename std::array<float, 2>::iterator, float>(this->center.begin(), this->center.end(), 0.0f);
    }
  }

  explicit Hand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : gesture(_alloc),
    center(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->gesture = "";
      std::fill<typename std::array<float, 2>::iterator, float>(this->center.begin(), this->center.end(), 0.0f);
    }
  }

  // field types and members
  using _gesture_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _gesture_type gesture;
  using _center_type =
    std::array<float, 2>;
  _center_type center;
  using _landmarks_type =
    std::vector<robot_msgs::msg::Landmark_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robot_msgs::msg::Landmark_<ContainerAllocator>>>;
  _landmarks_type landmarks;

  // setters for named parameter idiom
  Type & set__gesture(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->gesture = _arg;
    return *this;
  }
  Type & set__center(
    const std::array<float, 2> & _arg)
  {
    this->center = _arg;
    return *this;
  }
  Type & set__landmarks(
    const std::vector<robot_msgs::msg::Landmark_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<robot_msgs::msg::Landmark_<ContainerAllocator>>> & _arg)
  {
    this->landmarks = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    robot_msgs::msg::Hand_<ContainerAllocator> *;
  using ConstRawPtr =
    const robot_msgs::msg::Hand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<robot_msgs::msg::Hand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<robot_msgs::msg::Hand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      robot_msgs::msg::Hand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<robot_msgs::msg::Hand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      robot_msgs::msg::Hand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<robot_msgs::msg::Hand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<robot_msgs::msg::Hand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<robot_msgs::msg::Hand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__robot_msgs__msg__Hand
    std::shared_ptr<robot_msgs::msg::Hand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__robot_msgs__msg__Hand
    std::shared_ptr<robot_msgs::msg::Hand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Hand_ & other) const
  {
    if (this->gesture != other.gesture) {
      return false;
    }
    if (this->center != other.center) {
      return false;
    }
    if (this->landmarks != other.landmarks) {
      return false;
    }
    return true;
  }
  bool operator!=(const Hand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Hand_

// alias to use template instance with default allocator
using Hand =
  robot_msgs::msg::Hand_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace robot_msgs

#endif  // ROBOT_MSGS__MSG__DETAIL__HAND__STRUCT_HPP_
