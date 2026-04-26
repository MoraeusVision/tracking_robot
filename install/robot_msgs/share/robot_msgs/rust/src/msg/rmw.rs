#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "robot_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__robot_msgs__msg__Context() -> *const std::ffi::c_void;
}

#[link(name = "robot_msgs__rosidl_generator_c")]
extern "C" {
    fn robot_msgs__msg__Context__init(msg: *mut Context) -> bool;
    fn robot_msgs__msg__Context__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Context>, size: usize) -> bool;
    fn robot_msgs__msg__Context__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Context>);
    fn robot_msgs__msg__Context__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Context>, out_seq: *mut rosidl_runtime_rs::Sequence<Context>) -> bool;
}

// Corresponds to robot_msgs__msg__Context
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Context {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub persons: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Person>,

}



impl Default for Context {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !robot_msgs__msg__Context__init(&mut msg as *mut _) {
        panic!("Call to robot_msgs__msg__Context__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Context {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_msgs__msg__Context__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_msgs__msg__Context__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_msgs__msg__Context__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Context {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Context where Self: Sized {
  const TYPE_NAME: &'static str = "robot_msgs/msg/Context";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__robot_msgs__msg__Context() }
  }
}


#[link(name = "robot_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__robot_msgs__msg__Landmark() -> *const std::ffi::c_void;
}

#[link(name = "robot_msgs__rosidl_generator_c")]
extern "C" {
    fn robot_msgs__msg__Landmark__init(msg: *mut Landmark) -> bool;
    fn robot_msgs__msg__Landmark__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Landmark>, size: usize) -> bool;
    fn robot_msgs__msg__Landmark__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Landmark>);
    fn robot_msgs__msg__Landmark__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Landmark>, out_seq: *mut rosidl_runtime_rs::Sequence<Landmark>) -> bool;
}

// Corresponds to robot_msgs__msg__Landmark
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Landmark {

    // This member is not documented.
    #[allow(missing_docs)]
    pub x: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub y: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub z: f32,

}



impl Default for Landmark {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !robot_msgs__msg__Landmark__init(&mut msg as *mut _) {
        panic!("Call to robot_msgs__msg__Landmark__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Landmark {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_msgs__msg__Landmark__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_msgs__msg__Landmark__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_msgs__msg__Landmark__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Landmark {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Landmark where Self: Sized {
  const TYPE_NAME: &'static str = "robot_msgs/msg/Landmark";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__robot_msgs__msg__Landmark() }
  }
}


#[link(name = "robot_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__robot_msgs__msg__Person() -> *const std::ffi::c_void;
}

#[link(name = "robot_msgs__rosidl_generator_c")]
extern "C" {
    fn robot_msgs__msg__Person__init(msg: *mut Person) -> bool;
    fn robot_msgs__msg__Person__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Person>, size: usize) -> bool;
    fn robot_msgs__msg__Person__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Person>);
    fn robot_msgs__msg__Person__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Person>, out_seq: *mut rosidl_runtime_rs::Sequence<Person>) -> bool;
}

// Corresponds to robot_msgs__msg__Person
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Person {

    // This member is not documented.
    #[allow(missing_docs)]
    pub id: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bbox_xyxy: [f32; 4],

}



impl Default for Person {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !robot_msgs__msg__Person__init(&mut msg as *mut _) {
        panic!("Call to robot_msgs__msg__Person__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Person {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_msgs__msg__Person__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_msgs__msg__Person__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_msgs__msg__Person__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Person {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Person where Self: Sized {
  const TYPE_NAME: &'static str = "robot_msgs/msg/Person";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__robot_msgs__msg__Person() }
  }
}


#[link(name = "robot_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__robot_msgs__msg__Hand() -> *const std::ffi::c_void;
}

#[link(name = "robot_msgs__rosidl_generator_c")]
extern "C" {
    fn robot_msgs__msg__Hand__init(msg: *mut Hand) -> bool;
    fn robot_msgs__msg__Hand__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Hand>, size: usize) -> bool;
    fn robot_msgs__msg__Hand__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Hand>);
    fn robot_msgs__msg__Hand__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Hand>, out_seq: *mut rosidl_runtime_rs::Sequence<Hand>) -> bool;
}

// Corresponds to robot_msgs__msg__Hand
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Hand {

    // This member is not documented.
    #[allow(missing_docs)]
    pub gesture: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub center: [f32; 2],


    // This member is not documented.
    #[allow(missing_docs)]
    pub landmarks: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Landmark>,

}



impl Default for Hand {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !robot_msgs__msg__Hand__init(&mut msg as *mut _) {
        panic!("Call to robot_msgs__msg__Hand__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Hand {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_msgs__msg__Hand__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_msgs__msg__Hand__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_msgs__msg__Hand__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Hand {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Hand where Self: Sized {
  const TYPE_NAME: &'static str = "robot_msgs/msg/Hand";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__robot_msgs__msg__Hand() }
  }
}


#[link(name = "robot_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__robot_msgs__msg__Prediction() -> *const std::ffi::c_void;
}

#[link(name = "robot_msgs__rosidl_generator_c")]
extern "C" {
    fn robot_msgs__msg__Prediction__init(msg: *mut Prediction) -> bool;
    fn robot_msgs__msg__Prediction__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Prediction>, size: usize) -> bool;
    fn robot_msgs__msg__Prediction__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Prediction>);
    fn robot_msgs__msg__Prediction__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Prediction>, out_seq: *mut rosidl_runtime_rs::Sequence<Prediction>) -> bool;
}

// Corresponds to robot_msgs__msg__Prediction
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Prediction {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub persons: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Person>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub hands: rosidl_runtime_rs::Sequence<super::super::msg::rmw::Hand>,

}



impl Default for Prediction {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !robot_msgs__msg__Prediction__init(&mut msg as *mut _) {
        panic!("Call to robot_msgs__msg__Prediction__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Prediction {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_msgs__msg__Prediction__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_msgs__msg__Prediction__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { robot_msgs__msg__Prediction__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Prediction {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Prediction where Self: Sized {
  const TYPE_NAME: &'static str = "robot_msgs/msg/Prediction";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__robot_msgs__msg__Prediction() }
  }
}


