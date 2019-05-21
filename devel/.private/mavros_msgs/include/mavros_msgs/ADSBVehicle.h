// Generated by gencpp from file mavros_msgs/ADSBVehicle.msg
// DO NOT EDIT!


#ifndef MAVROS_MSGS_MESSAGE_ADSBVEHICLE_H
#define MAVROS_MSGS_MESSAGE_ADSBVEHICLE_H


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
struct ADSBVehicle_
{
  typedef ADSBVehicle_<ContainerAllocator> Type;

  ADSBVehicle_()
    : header()
    , ICAO_address(0)
    , callsign()
    , latitude(0.0)
    , longitude(0.0)
    , altitude(0.0)
    , heading(0.0)
    , hor_velocity(0.0)
    , ver_velocity(0.0)
    , altitude_type(0)
    , emitter_type(0)
    , tslc()
    , flags(0)
    , squawk(0)  {
    }
  ADSBVehicle_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , ICAO_address(0)
    , callsign(_alloc)
    , latitude(0.0)
    , longitude(0.0)
    , altitude(0.0)
    , heading(0.0)
    , hor_velocity(0.0)
    , ver_velocity(0.0)
    , altitude_type(0)
    , emitter_type(0)
    , tslc()
    , flags(0)
    , squawk(0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef uint32_t _ICAO_address_type;
  _ICAO_address_type ICAO_address;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _callsign_type;
  _callsign_type callsign;

   typedef double _latitude_type;
  _latitude_type latitude;

   typedef double _longitude_type;
  _longitude_type longitude;

   typedef float _altitude_type;
  _altitude_type altitude;

   typedef float _heading_type;
  _heading_type heading;

   typedef float _hor_velocity_type;
  _hor_velocity_type hor_velocity;

   typedef float _ver_velocity_type;
  _ver_velocity_type ver_velocity;

   typedef uint8_t _altitude_type_type;
  _altitude_type_type altitude_type;

   typedef uint8_t _emitter_type_type;
  _emitter_type_type emitter_type;

   typedef ros::Duration _tslc_type;
  _tslc_type tslc;

   typedef uint16_t _flags_type;
  _flags_type flags;

   typedef uint16_t _squawk_type;
  _squawk_type squawk;



  enum {
    ALT_PRESSURE_QNH = 0u,
    ALT_GEOMETRIC = 1u,
    EMITTER_NO_INFO = 0u,
    EMITTER_LIGHT = 1u,
    EMITTER_SMALL = 2u,
    EMITTER_LARGE = 3u,
    EMITTER_HIGH_VORTEX_LARGE = 4u,
    EMITTER_HEAVY = 5u,
    EMITTER_HIGHLY_MANUV = 6u,
    EMITTER_ROTOCRAFT = 7u,
    EMITTER_UNASSIGNED = 8u,
    EMITTER_GLIDER = 9u,
    EMITTER_LIGHTER_AIR = 10u,
    EMITTER_PARACHUTE = 11u,
    EMITTER_ULTRA_LIGHT = 12u,
    EMITTER_UNASSIGNED2 = 13u,
    EMITTER_UAV = 14u,
    EMITTER_SPACE = 15u,
    EMITTER_UNASSGINED3 = 16u,
    EMITTER_EMERGENCY_SURFACE = 17u,
    EMITTER_SERVICE_SURFACE = 18u,
    EMITTER_POINT_OBSTACLE = 19u,
    FLAG_VALID_COORDS = 1u,
    FLAG_VALID_ALTITUDE = 2u,
    FLAG_VALID_HEADING = 4u,
    FLAG_VALID_VELOCITY = 8u,
    FLAG_VALID_CALLSIGN = 16u,
    FLAG_VALID_SQUAWK = 32u,
    FLAG_SIMULATED = 64u,
  };


  typedef boost::shared_ptr< ::mavros_msgs::ADSBVehicle_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::mavros_msgs::ADSBVehicle_<ContainerAllocator> const> ConstPtr;

}; // struct ADSBVehicle_

typedef ::mavros_msgs::ADSBVehicle_<std::allocator<void> > ADSBVehicle;

typedef boost::shared_ptr< ::mavros_msgs::ADSBVehicle > ADSBVehiclePtr;
typedef boost::shared_ptr< ::mavros_msgs::ADSBVehicle const> ADSBVehicleConstPtr;

// constants requiring out of line definition

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::mavros_msgs::ADSBVehicle_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::mavros_msgs::ADSBVehicle_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::mavros_msgs::ADSBVehicle_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mavros_msgs::ADSBVehicle_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mavros_msgs::ADSBVehicle_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mavros_msgs::ADSBVehicle_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mavros_msgs::ADSBVehicle_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mavros_msgs::ADSBVehicle_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::mavros_msgs::ADSBVehicle_<ContainerAllocator> >
{
  static const char* value()
  {
    return "f71cc75a8e9e7b77d92f98d9a5315fd1";
  }

  static const char* value(const ::mavros_msgs::ADSBVehicle_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xf71cc75a8e9e7b77ULL;
  static const uint64_t static_value2 = 0xd92f98d9a5315fd1ULL;
};

template<class ContainerAllocator>
struct DataType< ::mavros_msgs::ADSBVehicle_<ContainerAllocator> >
{
  static const char* value()
  {
    return "mavros_msgs/ADSBVehicle";
  }

  static const char* value(const ::mavros_msgs::ADSBVehicle_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::mavros_msgs::ADSBVehicle_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# The location and information of an ADSB vehicle\n"
"#\n"
"# https://mavlink.io/en/messages/common.html#ADSB_VEHICLE\n"
"\n"
"# [[[cog:\n"
"# from pymavlink.dialects.v20 import common\n"
"#\n"
"# def decl_enum(ename, pfx='', bsz=8):\n"
"#     enum = sorted(common.enums[ename].items())\n"
"#     enum.pop() # remove ENUM_END\n"
"#\n"
"#     cog.outl(\"# \" + ename)\n"
"#     for k, e in enum:\n"
"#         sn = e.name[len(ename) + 1:]\n"
"#         l = \"uint{bsz} {pfx}{sn} = {k}\".format(**locals())\n"
"#         if e.description:\n"
"#             l += ' ' * (40 - len(l)) + ' # ' + e.description\n"
"#         cog.outl(l)\n"
"#\n"
"# decl_enum('ADSB_ALTITUDE_TYPE', 'ALT_')\n"
"# decl_enum('ADSB_EMITTER_TYPE', 'EMITTER_')\n"
"# decl_enum('ADSB_FLAGS', 'FLAG_', 16)\n"
"# ]]]\n"
"# ADSB_ALTITUDE_TYPE\n"
"uint8 ALT_PRESSURE_QNH = 0               # Altitude reported from a Baro source using QNH reference\n"
"uint8 ALT_GEOMETRIC = 1                  # Altitude reported from a GNSS source\n"
"# ADSB_EMITTER_TYPE\n"
"uint8 EMITTER_NO_INFO = 0\n"
"uint8 EMITTER_LIGHT = 1\n"
"uint8 EMITTER_SMALL = 2\n"
"uint8 EMITTER_LARGE = 3\n"
"uint8 EMITTER_HIGH_VORTEX_LARGE = 4\n"
"uint8 EMITTER_HEAVY = 5\n"
"uint8 EMITTER_HIGHLY_MANUV = 6\n"
"uint8 EMITTER_ROTOCRAFT = 7\n"
"uint8 EMITTER_UNASSIGNED = 8\n"
"uint8 EMITTER_GLIDER = 9\n"
"uint8 EMITTER_LIGHTER_AIR = 10\n"
"uint8 EMITTER_PARACHUTE = 11\n"
"uint8 EMITTER_ULTRA_LIGHT = 12\n"
"uint8 EMITTER_UNASSIGNED2 = 13\n"
"uint8 EMITTER_UAV = 14\n"
"uint8 EMITTER_SPACE = 15\n"
"uint8 EMITTER_UNASSGINED3 = 16\n"
"uint8 EMITTER_EMERGENCY_SURFACE = 17\n"
"uint8 EMITTER_SERVICE_SURFACE = 18\n"
"uint8 EMITTER_POINT_OBSTACLE = 19\n"
"# ADSB_FLAGS\n"
"uint16 FLAG_VALID_COORDS = 1\n"
"uint16 FLAG_VALID_ALTITUDE = 2\n"
"uint16 FLAG_VALID_HEADING = 4\n"
"uint16 FLAG_VALID_VELOCITY = 8\n"
"uint16 FLAG_VALID_CALLSIGN = 16\n"
"uint16 FLAG_VALID_SQUAWK = 32\n"
"uint16 FLAG_SIMULATED = 64\n"
"# [[[end]]] (checksum: e35e77be43548bd572a3cb24138fc2fd)\n"
"\n"
"std_msgs/Header header\n"
"\n"
"uint32 ICAO_address\n"
"string callsign\n"
"\n"
"float64 latitude\n"
"float64 longitude\n"
"float32 altitude 	# AMSL\n"
"\n"
"float32 heading		# deg [0..360)\n"
"float32 hor_velocity	# m/s\n"
"float32 ver_velocity	# m/s\n"
"\n"
"uint8 altitude_type	# Type from ADSB_ALTITUDE_TYPE enum\n"
"uint8 emitter_type	# Type from ADSB_EMITTER_TYPE enum\n"
"\n"
"duration tslc		# Duration from last communication, seconds [0..255]\n"
"uint16 flags		# ADSB_FLAGS bit field\n"
"uint16 squawk		# Squawk code\n"
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

  static const char* value(const ::mavros_msgs::ADSBVehicle_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::mavros_msgs::ADSBVehicle_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.ICAO_address);
      stream.next(m.callsign);
      stream.next(m.latitude);
      stream.next(m.longitude);
      stream.next(m.altitude);
      stream.next(m.heading);
      stream.next(m.hor_velocity);
      stream.next(m.ver_velocity);
      stream.next(m.altitude_type);
      stream.next(m.emitter_type);
      stream.next(m.tslc);
      stream.next(m.flags);
      stream.next(m.squawk);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ADSBVehicle_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::mavros_msgs::ADSBVehicle_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::mavros_msgs::ADSBVehicle_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "ICAO_address: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.ICAO_address);
    s << indent << "callsign: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.callsign);
    s << indent << "latitude: ";
    Printer<double>::stream(s, indent + "  ", v.latitude);
    s << indent << "longitude: ";
    Printer<double>::stream(s, indent + "  ", v.longitude);
    s << indent << "altitude: ";
    Printer<float>::stream(s, indent + "  ", v.altitude);
    s << indent << "heading: ";
    Printer<float>::stream(s, indent + "  ", v.heading);
    s << indent << "hor_velocity: ";
    Printer<float>::stream(s, indent + "  ", v.hor_velocity);
    s << indent << "ver_velocity: ";
    Printer<float>::stream(s, indent + "  ", v.ver_velocity);
    s << indent << "altitude_type: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.altitude_type);
    s << indent << "emitter_type: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.emitter_type);
    s << indent << "tslc: ";
    Printer<ros::Duration>::stream(s, indent + "  ", v.tslc);
    s << indent << "flags: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.flags);
    s << indent << "squawk: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.squawk);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MAVROS_MSGS_MESSAGE_ADSBVEHICLE_H
