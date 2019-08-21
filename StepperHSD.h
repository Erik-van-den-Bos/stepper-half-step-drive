/*
 * StepperHSD.h - Stepper library for Wiring/Arduino - Version 0.1
 *
 * Altered library         (0.1)   by Erik van den Bos
 *
 * Based on Stepper.h
 * Original library        (0.1)   by Tom Igoe.
 * Two-wire modifications  (0.2)   by Sebastian Gassner
 * Combination version     (0.3)   by Tom Igoe and David Mellis
 * Bug fix for four-wire   (0.4)   by Tom Igoe, bug fix from Noah Shibley
 * High-speed stepping mod         by Eugene Kozlenko
 * Timer rollover fix              by Eugene Kozlenko
 * Five phase five wire    (1.1.0) by Ryan Orendorff
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 *
 * Drives a unipolar four phase stepper motor in half step drive.
 *
 * The sequence of control signals for 4 phase, 4 control wires is as follows:
 *       D  B  A  C
 * Step C0 C1 C2 C3
 *    1  1  0  1  0
 *    2  0  0  1  0
 *    3  0  1  1  0
 *    4  0  1  0  0
 *    5  0  1  0  1
 *    6  0  0  0  1
 *    7  1  0  0  1
 *    8  1  0  0  0
 *
 * The circuits can be found at
 *
 * http://www.arduino.cc/en/Tutorial/Stepper
 */

// ensure this library description is only included once
#ifndef StepperHSD_h
#define StepperHSD_h

// library interface description
class StepperHSD {
  public:
    // constructor:
    StepperHSD(int number_of_steps, int motor_pin_1, int motor_pin_2,
                                    int motor_pin_3, int motor_pin_4);

    // speed setter method:
    void setSpeed(long whatSpeed);

    // mover method:
    void step(int number_of_steps);

    int version(void);

  private:
    void stepMotor(int this_step);

    int direction;            // Direction of rotation
    unsigned long step_delay; // delay between steps, in ms, based on speed
    int number_of_steps;      // total number of steps this motor can take
    int step_number;          // which step the motor is on

    // motor pin numbers:
    int motor_pin_1;
    int motor_pin_2;
    int motor_pin_3;
    int motor_pin_4;

    unsigned long last_step_time; // time stamp in us of when the last step was taken
};

#endif
