// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robot_msgs:msg/PersonState.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_MSGS__MSG__DETAIL__PERSON_STATE__TRAITS_HPP_
#define ROBOT_MSGS__MSG__DETAIL__PERSON_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robot_msgs/msg/detail/person_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace robot_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const PersonState & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: bbox_xyxy
  {
    if (msg.bbox_xyxy.size() == 0) {
      out << "bbox_xyxy: []";
    } else {
      out << "bbox_xyxy: [";
      size_t pending_items = msg.bbox_xyxy.size();
      for (auto item : msg.bbox_xyxy) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: last_seen
  {
    out << "last_seen: ";
    rosidl_generator_traits::value_to_yaml(msg.last_seen, out);
    out << ", ";
  }

  // member: tracked
  {
    out << "tracked: ";
    rosidl_generator_traits::value_to_yaml(msg.tracked, out);
    out << ", ";
  }

  // member: palm_held_seconds
  {
    out << "palm_held_seconds: ";
    rosidl_generator_traits::value_to_yaml(msg.palm_held_seconds, out);
    out << ", ";
  }

  // member: visible
  {
    out << "visible: ";
    rosidl_generator_traits::value_to_yaml(msg.visible, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PersonState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: bbox_xyxy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.bbox_xyxy.size() == 0) {
      out << "bbox_xyxy: []\n";
    } else {
      out << "bbox_xyxy:\n";
      for (auto item : msg.bbox_xyxy) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: last_seen
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "last_seen: ";
    rosidl_generator_traits::value_to_yaml(msg.last_seen, out);
    out << "\n";
  }

  // member: tracked
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tracked: ";
    rosidl_generator_traits::value_to_yaml(msg.tracked, out);
    out << "\n";
  }

  // member: palm_held_seconds
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "palm_held_seconds: ";
    rosidl_generator_traits::value_to_yaml(msg.palm_held_seconds, out);
    out << "\n";
  }

  // member: visible
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "visible: ";
    rosidl_generator_traits::value_to_yaml(msg.visible, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PersonState & msg, bool use_flow_style = false)
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
  const robot_msgs::msg::PersonState & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const robot_msgs::msg::PersonState & msg)
{
  return robot_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<robot_msgs::msg::PersonState>()
{
  return "robot_msgs::msg::PersonState";
}

template<>
inline const char * name<robot_msgs::msg::PersonState>()
{
  return "robot_msgs/msg/PersonState";
}

template<>
struct has_fixed_size<robot_msgs::msg::PersonState>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<robot_msgs::msg::PersonState>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<robot_msgs::msg::PersonState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROBOT_MSGS__MSG__DETAIL__PERSON_STATE__TRAITS_HPP_
