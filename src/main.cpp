#include "main.h" 
#include "pros/motors.h" 
#include "definitions.h"
 
void disabled() {} 
void competition_initialize() {} 
void autonomous() {} 


void initialize() { 
  pros::lcd::initialize(); 

  conveyor.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE); 
  roller.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE); 

  master.clear(); 
} 
 
void opcontrol() {
  while (true) {
	// R1 FORWARD, R2 BACKWARD FOR CONVEYOR
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) { 
		pros::lcd::print(0, "R1 pressed, CONVEYOR FORWARD\n");
		conveyor.move(110); 

    } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) { 
		pros::lcd::print(0, "R2 pressed, CONVEYOR BACKWARD\n");
		conveyor.move(-110);

    } else { 
		pros::lcd::print(0, "CONVEYOR STOPPED\n");
      	conveyor.move(0);
    } 


	// L1 FORWARD, L2 BACKWARD FOR ROLLER (missing hardware)
	// when L1 is pressed, rollers move forward with NEGATIVE velocity??
    if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) { 
		pros::lcd::print(0, "L2: ROLLER backward, +ve velocity??\n");
		roller.move(110); 

    } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) { 
		pros::lcd::print(0, "L1: ROLLER forward, -ve velocity??\n");
		roller.move(-110);

    } else {
		pros::lcd::print(0, "ROLLER STOPPED\n");
		roller.move(0); 
    }
	
	   pros::delay(100); 
  } 
  pros::delay(100); 
}