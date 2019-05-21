// Generated by gencpp from file mavros_msgs/State.msg
// DO NOT EDIT!


#ifndef MAVROS_MSGS_MESSAGE_STATE_H
#define MAVROS_MSGS_MESSAGE_STATE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace mavros_msgs
{
template <class ContainerAllocator>
struct State_
{
  typedef State_<ContainerAllocator> Type;

  State_()
    : header()
    , connected(false)
    , armed(false)
    , guided(false)
    , mode()
    , system_status(0)  {
    }
  State_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , connected(false)
    , armed(false)
    , guided(false)
    , mode(_alloc)
    , system_status(0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef uint8_t _connected_type;
  _connected_type connected;

   typedef uint8_t _armed_type;
  _armed_type armed;

   typedef uint8_t _guided_type;
  _guided_type guided;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _mode_type;
  _mode_type mode;

   typedef uint8_t _system_status_type;
  _system_status_type system_status;





  typedef boost::shared_ptr< ::mavros_msgs::State_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::mavros_msgs::State_<ContainerAllocator> const> ConstPtr;

}; // struct State_

typedef ::mavros_msgs::State_<std::allocator<void> > State;

typedef boost::shared_ptr< ::mavros_msgs::State > StatePtr;
typedef boost::shared_ptr< ::mavros_msgs::State const> StateConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::mavros_msgs::State_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::mavros_msgs::State_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace mavros_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'geographic_msgs': ['/opt/ros/melodic/share/geographic_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/melodic/share/sensor_msgs/cmake/../msg'], 'mavros_msgs': ['/home/pablo/GDP_Git/src/mavros/mavros_msgs/msg'], 'geometry_msgs': ['/opt/ros/melodic/share/geometry_msgs/cmake/../msg'], 'uuid_msgs': ['/opt/ros/melodic/share/uuid_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::mavros_msgs::State_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mavros_msgs::State_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mavros_msgs::State_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mavros_msgs::State_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mavros_msgs::State_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mavros_msgs::State_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::mavros_msgs::State_<ContainerAllocator> >
{
  static const char* value()
  {
    return "63d9a29b6abd9e0beeba06109556d062";
  }

  static const char* value(const ::mavros_msgs::State_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x63d9a29b6abd9e0bULL;
  static const uint64_t static_value2 = 0xeeba06109556d062ULL;
};

template<class ContainerAllocator>
struct DataType< ::mavros_msgs::State_<ContainerAllocator> >
{
  static const char* value()
  {
    return "mavros_msgs/State";
  }

  static const char* value(const ::mavros_msgs::State_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::mavros_msgs::State_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Current autopilot state\n"
"#\n"
"# Known modes listed here:\n"
"# http://wiki.ros.org/mavros/CustomModes\n"
"#\n"
"# For system_status values\n"
"# see https://mavlink.io/en/messages/common.html#MAV_STATE\n"
"#\n"
"\n"
"std_msgs/Header header\n"
"bool connected\n"
"bool armed\n"
"bool guided\n"
"string mode\n"
"uint8 system_status\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
;
  }

  static const char* value(const ::mavros_msgs::State_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::mavros_msgs::State_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.connected);
      stream.next(m.armed);
      stream.next(m.guided);
      stream.next(m.mode);
      stream.next(m.system_status);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct State_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::mavros_msgs::State_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::mavros_msgs::State_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "connected: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.connected);
    s << indent << "armed: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.armed);
    s << indent << "guided: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.guided);
    s << indent << "mode: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.mode);
    s << indent << "system_status: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.system_status);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MAVROS_MSGS_MESSAGE_STATE_H
