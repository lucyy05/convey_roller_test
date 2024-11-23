#include <cstdint>
#include "pros/motors.hpp"
#include "pros/adi.hpp"
#include "pros/rotation.hpp"
#include <cmath>
#include <sstream>
#include <vector>
#include "pros/imu.hpp"

#define CONVEYOR_MOTOR 8
#define ROLLER_MOTOR 3

pros::Controller master(pros::E_CONTROLLER_MASTER);

// CONVEYOR AND ROLLER
pros::Motor conveyor(CONVEYOR_MOTOR, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor roller(ROLLER_MOTOR, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_DEGREES);