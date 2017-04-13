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

#define     DEFAULT_Kp  0 //default P coefficient
#define     DEFAULT_Ki  0 //default I coefficient
#define     DEFAULT_Kd  0 //default D coefficient

#define     DT          10 //wait time for encoder reads (ms)
#define     DT_MS       (((double)DT)/1000 )//wait time for encoder reads (s) - this is used in PID - 

unsigned int encoder_res; //encoder ticks/rev
double wheel_diam; //wheel diameter
double resolution; //encoder resoltion unit/tick

volatile double kp[4], ki[4], kd[4]; //PID coefficients for each motor
volatile double sp[4]; //PID set points for each motor
volatile double pv[4]; //PID process variables
volatile byte pw[4]; //PID process outputs (pulse widths for speed control)
volatile double iterm[4]; //accumulated I-term error
volatile double lastin[4]; //last input received
volatile double err[4]; //the computed error term
volatile double dInp[4]; //change in input state

void setServo(byte num, hword pw);
void stopServo(byte num);
void startServo(byte num);
void setMotor(byte num, byte dir, byte pw);
void stopMotor(byte num);
void startMotor(byte num);
void pid(byte num);

/* [] END OF FILE */
