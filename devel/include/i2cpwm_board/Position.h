// Generated by gencpp from file i2cpwm_board/Position.msg
// DO NOT EDIT!


#ifndef I2CPWM_BOARD_MESSAGE_POSITION_H
#define I2CPWM_BOARD_MESSAGE_POSITION_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace i2cpwm_board
{
template <class ContainerAllocator>
struct Position_
{
  typedef Position_<ContainerAllocator> Type;

  Position_()
    : servo(0)
    , position(0)  {
    }
  Position_(const ContainerAllocator& _alloc)
    : servo(0)
    , position(0)  {
  (void)_alloc;
    }



   typedef int16_t _servo_type;
  _servo_type servo;

   typedef int16_t _position_type;
  _position_type position;





  typedef boost::shared_ptr< ::i2cpwm_board::Position_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::i2cpwm_board::Position_<ContainerAllocator> const> ConstPtr;

}; // struct Position_

typedef ::i2cpwm_board::Position_<std::allocator<void> > Position;

typedef boost::shared_ptr< ::i2cpwm_board::Position > PositionPtr;
typedef boost::shared_ptr< ::i2cpwm_board::Position const> PositionConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::i2cpwm_board::Position_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::i2cpwm_board::Position_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace i2cpwm_board

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg'], 'i2cpwm_board': ['/home/ros/Git/Mercury-2020/src/ros-i2cpwmboard-master/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::i2cpwm_board::Position_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::i2cpwm_board::Position_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::i2cpwm_board::Position_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::i2cpwm_board::Position_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::i2cpwm_board::Position_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::i2cpwm_board::Position_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::i2cpwm_board::Position_<ContainerAllocator> >
{
  static const char* value()
  {
    return "46d1769fd9d3e30e5c4274bd2f84d885";
  }

  static const char* value(const ::i2cpwm_board::Position_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x46d1769fd9d3e30eULL;
  static const uint64_t static_value2 = 0x5c4274bd2f84d885ULL;
};

template<class ContainerAllocator>
struct DataType< ::i2cpwm_board::Position_<ContainerAllocator> >
{
  static const char* value()
  {
    return "i2cpwm_board/Position";
  }

  static const char* value(const ::i2cpwm_board::Position_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::i2cpwm_board::Position_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# the position message is used when configuring drive mode to\n"
"# assign a  servo to a specific wheel positon in the drive system\n"
"# postions are specific toe the desired drive mode\n"
"# ackerman has only one position\n"
"# 1 = drive\n"
"# differential has two positons\n"
"# 1 = left, 2 = right\n"
"# mecanum has four positions\n"
"# 1 = front left, 2 = front right, 3 = rear left, 4 = rear right\n"
"# multiple servos/motors may be used for each positon\n"
"\n"
"int16 servo\n"
"int16 position\n"
;
  }

  static const char* value(const ::i2cpwm_board::Position_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::i2cpwm_board::Position_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.servo);
      stream.next(m.position);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Position_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::i2cpwm_board::Position_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::i2cpwm_board::Position_<ContainerAllocator>& v)
  {
    s << indent << "servo: ";
    Printer<int16_t>::stream(s, indent + "  ", v.servo);
    s << indent << "position: ";
    Printer<int16_t>::stream(s, indent + "  ", v.position);
  }
};

} // namespace message_operations
} // namespace ros

#endif // I2CPWM_BOARD_MESSAGE_POSITION_H
