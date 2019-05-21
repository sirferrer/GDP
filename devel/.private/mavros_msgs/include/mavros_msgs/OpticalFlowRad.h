// Generated by gencpp from file mavros_msgs/OpticalFlowRad.msg
// DO NOT EDIT!


#ifndef MAVROS_MSGS_MESSAGE_OPTICALFLOWRAD_H
#define MAVROS_MSGS_MESSAGE_OPTICALFLOWRAD_H


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
struct OpticalFlowRad_
{
  typedef OpticalFlowRad_<ContainerAllocator> Type;

  OpticalFlowRad_()
    : header()
    , integration_time_us(0)
    , integrated_x(0.0)
    , integrated_y(0.0)
    , integrated_xgyro(0.0)
    , integrated_ygyro(0.0)
    , integrated_zgyro(0.0)
    , temperature(0)
    , quality(0)
    , time_delta_distance_us(0)
    , distance(0.0)  {
    }
  OpticalFlowRad_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , integration_time_us(0)
    , integrated_x(0.0)
    , integrated_y(0.0)
    , integrated_xgyro(0.0)
    , integrated_ygyro(0.0)
    , integrated_zgyro(0.0)
    , temperature(0)
    , quality(0)
    , time_delta_distance_us(0)
    , distance(0.0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef uint32_t _integration_time_us_type;
  _integration_time_us_type integration_time_us;

   typedef float _integrated_x_type;
  _integrated_x_type integrated_x;

   typedef float _integrated_y_type;
  _integrated_y_type integrated_y;

   typedef float _integrated_xgyro_type;
  _integrated_xgyro_type integrated_xgyro;

   typedef float _integrated_ygyro_type;
  _integrated_ygyro_type integrated_ygyro;

   typedef float _integrated_zgyro_type;
  _integrated_zgyro_type integrated_zgyro;

   typedef int16_t _temperature_type;
  _temperature_type temperature;

   typedef uint8_t _quality_type;
  _quality_type quality;

   typedef uint32_t _time_delta_distance_us_type;
  _time_delta_distance_us_type time_delta_distance_us;

   typedef float _distance_type;
  _distance_type distance;





  typedef boost::shared_ptr< ::mavros_msgs::OpticalFlowRad_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::mavros_msgs::OpticalFlowRad_<ContainerAllocator> const> ConstPtr;

}; // struct OpticalFlowRad_

typedef ::mavros_msgs::OpticalFlowRad_<std::allocator<void> > OpticalFlowRad;

typedef boost::shared_ptr< ::mavros_msgs::OpticalFlowRad > OpticalFlowRadPtr;
typedef boost::shared_ptr< ::mavros_msgs::OpticalFlowRad const> OpticalFlowRadConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::mavros_msgs::OpticalFlowRad_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::mavros_msgs::OpticalFlowRad_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::mavros_msgs::OpticalFlowRad_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mavros_msgs::OpticalFlowRad_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mavros_msgs::OpticalFlowRad_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mavros_msgs::OpticalFlowRad_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mavros_msgs::OpticalFlowRad_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mavros_msgs::OpticalFlowRad_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::mavros_msgs::OpticalFlowRad_<ContainerAllocator> >
{
  static const char* value()
  {
    return "65d93e03c6188c7ee30415b2a39ad40d";
  }

  static const char* value(const ::mavros_msgs::OpticalFlowRad_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x65d93e03c6188c7eULL;
  static const uint64_t static_value2 = 0xe30415b2a39ad40dULL;
};

template<class ContainerAllocator>
struct DataType< ::mavros_msgs::OpticalFlowRad_<ContainerAllocator> >
{
  static const char* value()
  {
    return "mavros_msgs/OpticalFlowRad";
  }

  static const char* value(const ::mavros_msgs::OpticalFlowRad_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::mavros_msgs::OpticalFlowRad_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# OPTICAL_FLOW_RAD message data\n"
"\n"
"std_msgs/Header header\n"
"\n"
"uint32 integration_time_us\n"
"float32 integrated_x\n"
"float32 integrated_y\n"
"float32 integrated_xgyro\n"
"float32 integrated_ygyro\n"
"float32 integrated_zgyro\n"
"int16 temperature\n"
"uint8 quality\n"
"uint32 time_delta_distance_us\n"
"float32 distance\n"
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

  static const char* value(const ::mavros_msgs::OpticalFlowRad_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::mavros_msgs::OpticalFlowRad_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.integration_time_us);
      stream.next(m.integrated_x);
      stream.next(m.integrated_y);
      stream.next(m.integrated_xgyro);
      stream.next(m.integrated_ygyro);
      stream.next(m.integrated_zgyro);
      stream.next(m.temperature);
      stream.next(m.quality);
      stream.next(m.time_delta_distance_us);
      stream.next(m.distance);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct OpticalFlowRad_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::mavros_msgs::OpticalFlowRad_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::mavros_msgs::OpticalFlowRad_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "integration_time_us: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.integration_time_us);
    s << indent << "integrated_x: ";
    Printer<float>::stream(s, indent + "  ", v.integrated_x);
    s << indent << "integrated_y: ";
    Printer<float>::stream(s, indent + "  ", v.integrated_y);
    s << indent << "integrated_xgyro: ";
    Printer<float>::stream(s, indent + "  ", v.integrated_xgyro);
    s << indent << "integrated_ygyro: ";
    Printer<float>::stream(s, indent + "  ", v.integrated_ygyro);
    s << indent << "integrated_zgyro: ";
    Printer<float>::stream(s, indent + "  ", v.integrated_zgyro);
    s << indent << "temperature: ";
    Printer<int16_t>::stream(s, indent + "  ", v.temperature);
    s << indent << "quality: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.quality);
    s << indent << "time_delta_distance_us: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.time_delta_distance_us);
    s << indent << "distance: ";
    Printer<float>::stream(s, indent + "  ", v.distance);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MAVROS_MSGS_MESSAGE_OPTICALFLOWRAD_H
