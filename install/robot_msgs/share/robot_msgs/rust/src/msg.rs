#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to robot_msgs__msg__Context

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Context {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub persons: Vec<super::msg::PersonState>,

}



impl Default for Context {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Context::default())
  }
}

impl rosidl_runtime_rs::Message for Context {
  type RmwMsg = super::msg::rmw::Context;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        persons: msg.persons
          .into_iter()
          .map(|elem| super::msg::PersonState::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        persons: msg.persons
          .iter()
          .map(|elem| super::msg::PersonState::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      persons: msg.persons
          .into_iter()
          .map(super::msg::PersonState::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to robot_msgs__msg__Landmark

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Landmark::default())
  }
}

impl rosidl_runtime_rs::Message for Landmark {
  type RmwMsg = super::msg::rmw::Landmark;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        x: msg.x,
        y: msg.y,
        z: msg.z,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      x: msg.x,
      y: msg.y,
      z: msg.z,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      x: msg.x,
      y: msg.y,
      z: msg.z,
    }
  }
}


// Corresponds to robot_msgs__msg__Person

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Person::default())
  }
}

impl rosidl_runtime_rs::Message for Person {
  type RmwMsg = super::msg::rmw::Person;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        id: msg.id,
        bbox_xyxy: msg.bbox_xyxy,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      id: msg.id,
        bbox_xyxy: msg.bbox_xyxy,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      id: msg.id,
      bbox_xyxy: msg.bbox_xyxy,
    }
  }
}


// Corresponds to robot_msgs__msg__PersonState

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PersonState {

    // This member is not documented.
    #[allow(missing_docs)]
    pub id: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub bbox_xyxy: [f32; 4],


    // This member is not documented.
    #[allow(missing_docs)]
    pub last_seen: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub tracked: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub palm_held_seconds: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub visible: bool,

}



impl Default for PersonState {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::PersonState::default())
  }
}

impl rosidl_runtime_rs::Message for PersonState {
  type RmwMsg = super::msg::rmw::PersonState;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        id: msg.id,
        bbox_xyxy: msg.bbox_xyxy,
        last_seen: msg.last_seen,
        tracked: msg.tracked,
        palm_held_seconds: msg.palm_held_seconds,
        visible: msg.visible,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      id: msg.id,
        bbox_xyxy: msg.bbox_xyxy,
      last_seen: msg.last_seen,
      tracked: msg.tracked,
      palm_held_seconds: msg.palm_held_seconds,
      visible: msg.visible,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      id: msg.id,
      bbox_xyxy: msg.bbox_xyxy,
      last_seen: msg.last_seen,
      tracked: msg.tracked,
      palm_held_seconds: msg.palm_held_seconds,
      visible: msg.visible,
    }
  }
}


// Corresponds to robot_msgs__msg__Hand

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Hand {

    // This member is not documented.
    #[allow(missing_docs)]
    pub gesture: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub center: [f32; 2],


    // This member is not documented.
    #[allow(missing_docs)]
    pub landmarks: Vec<super::msg::Landmark>,

}



impl Default for Hand {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Hand::default())
  }
}

impl rosidl_runtime_rs::Message for Hand {
  type RmwMsg = super::msg::rmw::Hand;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        gesture: msg.gesture.as_str().into(),
        center: msg.center,
        landmarks: msg.landmarks
          .into_iter()
          .map(|elem| super::msg::Landmark::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        gesture: msg.gesture.as_str().into(),
        center: msg.center,
        landmarks: msg.landmarks
          .iter()
          .map(|elem| super::msg::Landmark::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      gesture: msg.gesture.to_string(),
      center: msg.center,
      landmarks: msg.landmarks
          .into_iter()
          .map(super::msg::Landmark::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to robot_msgs__msg__Prediction

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Prediction {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub persons: Vec<super::msg::Person>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub hands: Vec<super::msg::Hand>,

}



impl Default for Prediction {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Prediction::default())
  }
}

impl rosidl_runtime_rs::Message for Prediction {
  type RmwMsg = super::msg::rmw::Prediction;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        persons: msg.persons
          .into_iter()
          .map(|elem| super::msg::Person::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        hands: msg.hands
          .into_iter()
          .map(|elem| super::msg::Hand::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        persons: msg.persons
          .iter()
          .map(|elem| super::msg::Person::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        hands: msg.hands
          .iter()
          .map(|elem| super::msg::Hand::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      persons: msg.persons
          .into_iter()
          .map(super::msg::Person::from_rmw_message)
          .collect(),
      hands: msg.hands
          .into_iter()
          .map(super::msg::Hand::from_rmw_message)
          .collect(),
    }
  }
}


