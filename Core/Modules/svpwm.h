/*
 * @Descripttion: 
 * @version: V1.0.0
 * @Author: LeonHe
 * @Date: 2021-01-03 18:55:23
 * @LastEditTime: 2021-01-04 15:47:18
 */
#ifndef __SVPWM_H_
#define __SVPWM_H_

typedef struct StPwmDuty
{
    float pwmDutyPresent[3];
}StPwmDuty_t;

void svpwmCal(float theta, float kp, StPwmDuty_t* output);

#endif
