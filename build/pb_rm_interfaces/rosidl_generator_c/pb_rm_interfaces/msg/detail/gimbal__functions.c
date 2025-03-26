// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from pb_rm_interfaces:msg/Gimbal.idl
// generated code does not contain a copyright notice
#include "pb_rm_interfaces/msg/detail/gimbal__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
pb_rm_interfaces__msg__Gimbal__init(pb_rm_interfaces__msg__Gimbal * msg)
{
  if (!msg) {
    return false;
  }
  // pitch
  // yaw
  // pitch_min_range
  // pitch_max_range
  // yaw_min_range
  // yaw_max_range
  return true;
}

void
pb_rm_interfaces__msg__Gimbal__fini(pb_rm_interfaces__msg__Gimbal * msg)
{
  if (!msg) {
    return;
  }
  // pitch
  // yaw
  // pitch_min_range
  // pitch_max_range
  // yaw_min_range
  // yaw_max_range
}

bool
pb_rm_interfaces__msg__Gimbal__are_equal(const pb_rm_interfaces__msg__Gimbal * lhs, const pb_rm_interfaces__msg__Gimbal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // pitch
  if (lhs->pitch != rhs->pitch) {
    return false;
  }
  // yaw
  if (lhs->yaw != rhs->yaw) {
    return false;
  }
  // pitch_min_range
  if (lhs->pitch_min_range != rhs->pitch_min_range) {
    return false;
  }
  // pitch_max_range
  if (lhs->pitch_max_range != rhs->pitch_max_range) {
    return false;
  }
  // yaw_min_range
  if (lhs->yaw_min_range != rhs->yaw_min_range) {
    return false;
  }
  // yaw_max_range
  if (lhs->yaw_max_range != rhs->yaw_max_range) {
    return false;
  }
  return true;
}

bool
pb_rm_interfaces__msg__Gimbal__copy(
  const pb_rm_interfaces__msg__Gimbal * input,
  pb_rm_interfaces__msg__Gimbal * output)
{
  if (!input || !output) {
    return false;
  }
  // pitch
  output->pitch = input->pitch;
  // yaw
  output->yaw = input->yaw;
  // pitch_min_range
  output->pitch_min_range = input->pitch_min_range;
  // pitch_max_range
  output->pitch_max_range = input->pitch_max_range;
  // yaw_min_range
  output->yaw_min_range = input->yaw_min_range;
  // yaw_max_range
  output->yaw_max_range = input->yaw_max_range;
  return true;
}

pb_rm_interfaces__msg__Gimbal *
pb_rm_interfaces__msg__Gimbal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pb_rm_interfaces__msg__Gimbal * msg = (pb_rm_interfaces__msg__Gimbal *)allocator.allocate(sizeof(pb_rm_interfaces__msg__Gimbal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pb_rm_interfaces__msg__Gimbal));
  bool success = pb_rm_interfaces__msg__Gimbal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
pb_rm_interfaces__msg__Gimbal__destroy(pb_rm_interfaces__msg__Gimbal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    pb_rm_interfaces__msg__Gimbal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
pb_rm_interfaces__msg__Gimbal__Sequence__init(pb_rm_interfaces__msg__Gimbal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pb_rm_interfaces__msg__Gimbal * data = NULL;

  if (size) {
    data = (pb_rm_interfaces__msg__Gimbal *)allocator.zero_allocate(size, sizeof(pb_rm_interfaces__msg__Gimbal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pb_rm_interfaces__msg__Gimbal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pb_rm_interfaces__msg__Gimbal__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
pb_rm_interfaces__msg__Gimbal__Sequence__fini(pb_rm_interfaces__msg__Gimbal__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      pb_rm_interfaces__msg__Gimbal__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

pb_rm_interfaces__msg__Gimbal__Sequence *
pb_rm_interfaces__msg__Gimbal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pb_rm_interfaces__msg__Gimbal__Sequence * array = (pb_rm_interfaces__msg__Gimbal__Sequence *)allocator.allocate(sizeof(pb_rm_interfaces__msg__Gimbal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = pb_rm_interfaces__msg__Gimbal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
pb_rm_interfaces__msg__Gimbal__Sequence__destroy(pb_rm_interfaces__msg__Gimbal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    pb_rm_interfaces__msg__Gimbal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
pb_rm_interfaces__msg__Gimbal__Sequence__are_equal(const pb_rm_interfaces__msg__Gimbal__Sequence * lhs, const pb_rm_interfaces__msg__Gimbal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pb_rm_interfaces__msg__Gimbal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pb_rm_interfaces__msg__Gimbal__Sequence__copy(
  const pb_rm_interfaces__msg__Gimbal__Sequence * input,
  pb_rm_interfaces__msg__Gimbal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pb_rm_interfaces__msg__Gimbal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    pb_rm_interfaces__msg__Gimbal * data =
      (pb_rm_interfaces__msg__Gimbal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pb_rm_interfaces__msg__Gimbal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          pb_rm_interfaces__msg__Gimbal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pb_rm_interfaces__msg__Gimbal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
