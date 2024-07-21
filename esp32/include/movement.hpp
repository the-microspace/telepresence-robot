#include "common.hpp"

#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP

// Positive = forward, negative = backward
void move(float distance_in_inches);
// Positive = turn right, negative = turn left
void rotate(int angle_in_degrees);
void stop(bool hold_position);

#endif
