/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include <project.h>
#include "globaldefs.h"

#define     MAXPW       4500 //Max pulse width for a servo 
#define     MINPW       1500 //min pulse width for a servo
#define     MAXSPD      255 //max pulse width for a motor PWM
#define     MINSPD      0 //min pulse width for a motor PWM

#define     DEFAULT_Kp  0
#define     DEFAULT_Ki  0
#define     DEFAULT_Kd  0

double kp[4], ki[4], kd[4]; //PID coefficients for each motor
double target[4]; //PID targets for each motor

void setServo(byte num, hword pw);
void stopServo(byte num);
void startServo(byte num);
void setMotor(byte num, byte dir, byte pw);
void stopMotor(byte num);
void startMotor(byte num);
void pid(byte num);

/* [] END OF FILE */
