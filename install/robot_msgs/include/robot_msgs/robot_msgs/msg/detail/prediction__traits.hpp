// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robot_msgs:msg/Prediction.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_MSGS__MSG__DETAIL__PREDICTION__TRAITS_HPP_
#define ROBOT_MSGS__MSG__DETAIL__PREDICTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robot_msgs/msg/detail/prediction__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'persons'
#include "robot_msgs/msg/detail/person__traits.hpp"
// Member 'hands'
#include "robot_msgs/msg/detail/hand__traits.hpp"

namespace robot_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Prediction & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: persons
  {
    if (msg.persons.size() == 0) {
      out << "persons: []";
    } else {
      out << "persons: [";
      size_t pending_items = msg.persons.size();
      for (auto item : msg.persons) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: hands
  {
    if (msg.hands.size() == 0) {
      out << "hands: []";
    } else {
      out << "hands: [";
      size_t pending_items = msg.hands.size();
      for (auto item : msg.hands) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Prediction & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: persons
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.persons.size() == 0) {
      out << "persons: []\n";
    } else {
      out << "persons:\n";
      for (auto item : msg.persons) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: hands
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.hands.size() == 0) {
      out << "hands: []\n";
    } else {
      out << "hands:\n";
      for (auto item : msg.hands) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Prediction & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace robot_msgs

namespace rosidl_generator_traits
{

[[deprecated("use robot_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robot_msgs::msg::Prediction & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const robot_msgs::msg::Prediction & msg)
{
  return robot_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<robot_msgs::msg::Prediction>()
{
  return "robot_msgs::msg::Prediction";
}

template<>
inline const char * name<robot_msgs::msg::Prediction>()
{
  return "robot_msgs/msg/Prediction";
}

template<>
struct has_fixed_size<robot_msgs::msg::Prediction>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<robot_msgs::msg::Prediction>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<robot_msgs::msg::Prediction>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROBOT_MSGS__MSG__DETAIL__PREDICTION__TRAITS_HPP_
