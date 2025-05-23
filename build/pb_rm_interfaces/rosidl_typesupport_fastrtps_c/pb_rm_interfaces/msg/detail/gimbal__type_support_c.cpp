// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from pb_rm_interfaces:msg/Gimbal.idl
// generated code does not contain a copyright notice
#include "pb_rm_interfaces/msg/detail/gimbal__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "pb_rm_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "pb_rm_interfaces/msg/detail/gimbal__struct.h"
#include "pb_rm_interfaces/msg/detail/gimbal__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _Gimbal__ros_msg_type = pb_rm_interfaces__msg__Gimbal;

static bool _Gimbal__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Gimbal__ros_msg_type * ros_message = static_cast<const _Gimbal__ros_msg_type *>(untyped_ros_message);
  // Field name: pitch
  {
    cdr << ros_message->pitch;
  }

  // Field name: yaw
  {
    cdr << ros_message->yaw;
  }

  // Field name: pitch_min_range
  {
    cdr << ros_message->pitch_min_range;
  }

  // Field name: pitch_max_range
  {
    cdr << ros_message->pitch_max_range;
  }

  // Field name: yaw_min_range
  {
    cdr << ros_message->yaw_min_range;
  }

  // Field name: yaw_max_range
  {
    cdr << ros_message->yaw_max_range;
  }

  return true;
}

static bool _Gimbal__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Gimbal__ros_msg_type * ros_message = static_cast<_Gimbal__ros_msg_type *>(untyped_ros_message);
  // Field name: pitch
  {
    cdr >> ros_message->pitch;
  }

  // Field name: yaw
  {
    cdr >> ros_message->yaw;
  }

  // Field name: pitch_min_range
  {
    cdr >> ros_message->pitch_min_range;
  }

  // Field name: pitch_max_range
  {
    cdr >> ros_message->pitch_max_range;
  }

  // Field name: yaw_min_range
  {
    cdr >> ros_message->yaw_min_range;
  }

  // Field name: yaw_max_range
  {
    cdr >> ros_message->yaw_max_range;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pb_rm_interfaces
size_t get_serialized_size_pb_rm_interfaces__msg__Gimbal(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Gimbal__ros_msg_type * ros_message = static_cast<const _Gimbal__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name pitch
  {
    size_t item_size = sizeof(ros_message->pitch);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name yaw
  {
    size_t item_size = sizeof(ros_message->yaw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pitch_min_range
  {
    size_t item_size = sizeof(ros_message->pitch_min_range);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name pitch_max_range
  {
    size_t item_size = sizeof(ros_message->pitch_max_range);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name yaw_min_range
  {
    size_t item_size = sizeof(ros_message->yaw_min_range);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name yaw_max_range
  {
    size_t item_size = sizeof(ros_message->yaw_max_range);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Gimbal__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_pb_rm_interfaces__msg__Gimbal(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_pb_rm_interfaces
size_t max_serialized_size_pb_rm_interfaces__msg__Gimbal(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: pitch
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: yaw
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: pitch_min_range
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: pitch_max_range
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: yaw_min_range
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: yaw_max_range
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = pb_rm_interfaces__msg__Gimbal;
    is_plain =
      (
      offsetof(DataType, yaw_max_range) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _Gimbal__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_pb_rm_interfaces__msg__Gimbal(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Gimbal = {
  "pb_rm_interfaces::msg",
  "Gimbal",
  _Gimbal__cdr_serialize,
  _Gimbal__cdr_deserialize,
  _Gimbal__get_serialized_size,
  _Gimbal__max_serialized_size
};

static rosidl_message_type_support_t _Gimbal__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Gimbal,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, pb_rm_interfaces, msg, Gimbal)() {
  return &_Gimbal__type_support;
}

#if defined(__cplusplus)
}
#endif
