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
#include "motors.h"

#ifdef DEBUGGING
    #include "comm.h"
    char dummy[4];
#endif

/* setServo(byte, hword)
 * byte num: The servo number that was selected.
 * hword pw: The pulse width to write to the servo PWM register.
 * This function will set a servo PWM register to a provided pulse width.
 * The function ensures a pulse width too far outside normal operational
 * range of a servo motor is not allowed.
*/
void setServo(byte num, hword pw)
{
    if(pw > MAXPW)
        pw = MAXPW;
    else if(pw < MINPW)
        pw = MINPW;
    
    #ifdef DEBUGGING
    writeUART("Servo ", strlen("Servo "));
    writeUART(num+48, 1);
    writeUART(" pulse width: ", strlen(" pulse width: "));
    writeUART(itoa(pw, dummy, 10), 4);
    writeUART("\r\n", 2);
    #endif
    
    switch(num)
    {
        case 0:
            SRV0_WriteCompare(pw);
            break;
        case 1:
            SRV1_WriteCompare(pw);
            break;
        case 2:
            SRV2_WriteCompare(pw);
            break;
        case 3:
            SRV3_WriteCompare(pw);
            break;
    }
}

/* stopServo(byte)
 * byte num: The servo number that was selected.
 * Disables the PWM output on the given servo.
*/
void stopServo(byte num)
{    
    #ifdef DEBUGGING
    writeUART("Servo ", strlen("Servo "));
    writeUART(num+48, 1);
    writeUART("started.\r\n", strlen("started.\r\n"));
    #endif
    switch(num)
    {
        case 0:
            SRV0_Stop();
            break;
        case 1:
            SRV1_Stop();
            break;
        case 2:
            SRV2_Stop();
            break;
        case 3:
            SRV3_Stop();
            break;
    }
}

/* startServo(byte)
 * byte num: The servo number that was selected.
 * Enables the PWM output on the given servo.
*/
void startServo(byte num)
{
    #ifdef DEBUGGING
    writeUART("Servo ", strlen("Servo "));
    writeUART(num+48, 1);
    writeUART("stopped.\r\n", strlen("stopped.\r\n"));
    #endif
    switch(num)
    {
        case 0:
            SRV0_Start();
            break;
        case 1:
            SRV1_Start();
            break;
        case 2:
            SRV2_Start();
            break;
        case 3:
            SRV3_Start();
            break;
    }
}

/* setMotor(byte, byte, byte)
 * byte num: The motor number ot be set.
 * byte dir: The direction to turn (1 = CW 0 = CCW)
 * byte pw: The pulse width to write to the motor PWM register.
 * This function writes a pulse width to a chosen PWM register to
 * control motor speed.
*/
void setMotor(byte num, byte dir, double target)
{
    switch(num)
    {
        case 0:
            //M0PWM_WriteCompare(pw);
            sp[num] = target;
            if(dir) 
            {
                M0DIRA_DR |= M0DIRA_MASK;
                M0DIRB_DR &= ~M0DIRB_MASK;
            #ifdef DEBUGGING
                writeUART("F", 1);
                writeUART("\r\n", 2);
            #endif
            }
            else 
            {
                M0DIRA_DR &= ~M0DIRA_MASK;
                M0DIRB_DR |= M0DIRB_MASK;
            #ifdef DEBUGGING
                writeUART("R", 1);
                writeUART("\r\n", 2);
            #endif
            }
            break;
        case 1:
            //M1PWM_WriteCompare(pw);
            sp[num] = target;
            if(dir) 
            {
                M1DIRA_DR |= M1DIRA_MASK;
                M1DIRB_DR &= ~M1DIRB_MASK;
            #ifdef DEBUGGING
                writeUART("F", 1);
                writeUART("\r\n", 2);
            #endif
            }
            else 
            {
                M1DIRA_DR &= ~M1DIRA_MASK;
                M1DIRB_DR |= M1DIRB_MASK;
            #ifdef DEBUGGING
                writeUART("R", 1);
                writeUART("\r\n", 2);
            #endif
            }
            break;
        case 2:
            //M2PWM_WriteCompare(pw);
            sp[num] = target;
            if(dir) 
            {
                M2DIRA_DR |= M2DIRA_MASK;
                M2DIRB_DR &= ~M2DIRB_MASK;
            #ifdef DEBUGGING
                writeUART("F", 1);
                writeUART("\r\n", 2);
            #endif
            }
            else 
            {
                M2DIRA_DR &= ~M2DIRA_MASK;
                M2DIRB_DR |= M2DIRB_MASK;
            #ifdef DEBUGGING
                writeUART("R", 1);
                writeUART("\r\n", 2);
            #endif
            }
            break;
        case 3:
            //M3PWM_WriteCompare(pw);
            sp[num] = target;
            if(dir) 
            {
                M3DIRA_DR |= M3DIRA_MASK;
                M3DIRB_DR &= ~M3DIRB_MASK;
            #ifdef DEBUGGING
                writeUART("F", 1);
                writeUART("\r\n", 2);
            #endif
            }
            else 
            {
                M3DIRA_DR &= ~M3DIRA_MASK;
                M3DIRB_DR |= M3DIRB_MASK;
            #ifdef DEBUGGING
                writeUART("R", 1);
                writeUART("\r\n", 2);
            #endif
            }
            break;
    }
}

/* stopMotor(byte)
 * byte num: The motor number to be disabled.
 * This function diables the PWM output of a selected motor channel.
 * Additionally, it resets the pulse width to 0.
*/
void stopMotor(byte num)
{
    #ifdef DEBUGGING
    writeUART("Motor ", strlen("Motor "));
    writeUART(num+48, 1);
    writeUART("stopped\r\n", strlen("stopped\r\n"));
    #endif
    switch(num)
    {
        case 0:
            M0PWM_Stop();
            M0PWM_WriteCompare(0);
            break;
        case 1:
            M1PWM_Stop();
            M1PWM_WriteCompare(0);
            break;
        case 2:
            M2PWM_Stop();
            M2PWM_WriteCompare(0);
            break;
        case 3:
            M3PWM_Stop();
            M3PWM_WriteCompare(0);
            break;
    }
}

/* startMotor(byte)
 * byte num: The motor number to be enabled.
 * This function enables the PWM output of a selected motor channel.
*/
void startMotor(byte num)
{
    #ifdef DEBUGGING
    writeUART("Motor ", strlen("Motor "));
    writeUART(num+48, 1);
    writeUART("started.\r\n", strlen("started.\r\n"));
    #endif
    switch(num)
    {
        case 0:
            M0PWM_Start();
            M0PWM_Enable();
            break;
        case 1:
            M1PWM_Start();
            M1PWM_Enable();
            break;
        case 2:
            M2PWM_Start();
            M2PWM_Enable();
            break;
        case 3:
            M3PWM_Start();
            M3PWM_Enable();
            break;
    }
}

/* pid(byte)
 * byte num: The motor channel to compute the PID for.
 * This function will compute the next PID algorithm iteration for a selected
 * motor channel. This function should be called in a loop.
*/
void pid(byte num)
{
    /* Collect input
     * Read the quadrature decoder register, wait a fixed time and read again.
     * Velocity = dx/dt, we have constant dt so compute dx.
     * dx = x(t) - x(t-1) = (QD reg count) - (prev QD reg count)
     * compute velocity = dx*(encoder resolution)/dt
    */
    pv[num] = QD0_ReadCounter();
    CyDelay(DT);
    pv[num] = QD0_ReadCounter() - pv[num];
    
    pv[num] = pv[num]*resolution/(DT_MS);
    
    /* Compute PID error terms
     * err = current error (P term error)
     * iterm = accumulated error (I term error)
     * dInp = rate of change in error (D term error)
    */
    err[num] = sp[num] - pv[num];
    iterm[num] += ki[num] * err[num];
    if(iterm[num] > MAXSPD)
        iterm[num] = MAXSPD;
    else if(iterm[num] < MINSPD)
        iterm[num] = MINSPD;
    
    dInp[num] = pv[num] - lastin[num];
    
    /* Compute PID output
     * Output is sum of weighted errors.
     * Keep output within register limits.
    */
    pw[num] = kp[num]*err[num] + iterm[num] - kd[num]*dInp[num];
    if(pw[num] > MAXSPD)
        pw[num] = MAXSPD;
    else if(pw[num] < MINSPD)
        pw[num] = MINSPD;
        
    /* Save input
     * Previous input needed to compute error rate of change for D term.
    */
    lastin[num] = pv[num];
}
/* [] END OF FILE */
