/*
 * @Descripttion: 
 * @version: V1.0.0
 * @Author: LeonHe
 * @Date: 2021-01-03 18:55:10
 * @LastEditTime: 2021-04-25 00:20:21
 */
#include "svpwm.h"
#include <math.h>

#define PI 3.14159265

/**
 * @descript: 
 * @param {float} theta
 * @param {float} kp
 * @param {StPwmDuty_t} output
 * @return {*}
 */
void svpwmCal(float theta, float kp, StPwmDuty_t* output)
{
    float k;
    float ctParam[4] = {0};//ABCD参数
	float P1,P2;//两个相的时间占比
	//对幅度K做限幅
    if(kp > 100.0)
    {
        k = 100.0;
    }
    else if(kp < 0)
    {
        k = 0.0;
    }
    else
    {
        k = kp;
    }
	k = k/100.0;
    k = k*0.8660254;//Umax = Udc * (3^0.5)/2
	//对电角度求余，并转换弧度
    theta = fmod(theta, 360.0);
    if(theta < 0.0)
    {
        theta += 360.0;
    }
    float rad = theta/180.0*PI;
	
	//计算各象限的参数
    if(theta < 60.0)//[0~60)
    {
        ctParam[0] = cos(  0.0/180.0*PI);//A=cosU1
        ctParam[1] = cos( 60.0/180.0*PI);//B=cosU2
        ctParam[2] = sin(  0.0/180.0*PI);//C=sinU1
        ctParam[3] = sin( 60.0/180.0*PI);//D=sinU2

		//计算合成占比
		P1 = k*(cos(rad)*ctParam[3] - sin(rad)*ctParam[1])/(ctParam[0]*ctParam[3] - ctParam[1]*ctParam[2]);
		P2 = k*(sin(rad)*ctParam[0] - cos(rad)*ctParam[2])/(ctParam[0]*ctParam[3] - ctParam[1]*ctParam[2]);

		output->pwmDutyPresent[0] = (1 - P1 - P2)/2;
		output->pwmDutyPresent[1] = output->pwmDutyPresent[0]+P1;
		output->pwmDutyPresent[2] = output->pwmDutyPresent[0]+P1+P2;
    }
    else if(theta < 120.0)//[60~120)
    {
        ctParam[0] = cos( 60.0/180.0*PI);//A=cosU1
        ctParam[1] = cos(120.0/180.0*PI);//B=cosU2
        ctParam[2] = sin( 60.0/180.0*PI);//C=sinU1
        ctParam[3] = sin(120.0/180.0*PI);//D=sinU2

		//计算合成占比
		P1 = k*(cos(rad)*ctParam[3] - sin(rad)*ctParam[1])/(ctParam[0]*ctParam[3] - ctParam[1]*ctParam[2]);
		P2 = k*(sin(rad)*ctParam[0] - cos(rad)*ctParam[2])/(ctParam[0]*ctParam[3] - ctParam[1]*ctParam[2]);

		output->pwmDutyPresent[1] = (1 - P1 - P2)/2;
		output->pwmDutyPresent[0] = output->pwmDutyPresent[1]+P2;
		output->pwmDutyPresent[2] = output->pwmDutyPresent[1]+P1+P2;

    }
    else if(theta < 180.0)//[120~180)
    {
        ctParam[0] = cos(120.0/180.0*PI);//A=cosU1
        ctParam[1] = cos(180.0/180.0*PI);//B=cosU2
        ctParam[2] = sin(120.0/180.0*PI);//C=sinU1
        ctParam[3] = sin(180.0/180.0*PI);//D=sinU2

		//计算合成占比
		P1 = k*(cos(rad)*ctParam[3] - sin(rad)*ctParam[1])/(ctParam[0]*ctParam[3] - ctParam[1]*ctParam[2]);
		P2 = k*(sin(rad)*ctParam[0] - cos(rad)*ctParam[2])/(ctParam[0]*ctParam[3] - ctParam[1]*ctParam[2]);

		output->pwmDutyPresent[1] = (1 - P1 - P2)/2;
		output->pwmDutyPresent[2] = output->pwmDutyPresent[1]+P1;
		output->pwmDutyPresent[0] = output->pwmDutyPresent[1]+P1+P2;
    }
    else if(theta < 240.0)//[180~240)
    {
        ctParam[0] = cos(180.0/180.0*PI);//A=cosU1
        ctParam[1] = cos(240.0/180.0*PI);//B=cosU2
        ctParam[2] = sin(180.0/180.0*PI);//C=sinU1
        ctParam[3] = sin(240.0/180.0*PI);//D=sinU2

		//计算合成占比
		P1 = k*(cos(rad)*ctParam[3] - sin(rad)*ctParam[1])/(ctParam[0]*ctParam[3] - ctParam[1]*ctParam[2]);
		P2 = k*(sin(rad)*ctParam[0] - cos(rad)*ctParam[2])/(ctParam[0]*ctParam[3] - ctParam[1]*ctParam[2]);

		output->pwmDutyPresent[2] = (1 - P1 - P2)/2;
		output->pwmDutyPresent[1] = output->pwmDutyPresent[2]+P2;
		output->pwmDutyPresent[0] = output->pwmDutyPresent[2]+P1+P2;
    }
    else if(theta < 300.0)//[240~300)
    {
        ctParam[0] = cos(240.0/180.0*PI);//A=cosU1
        ctParam[1] = cos(300.0/180.0*PI);//B=cosU2
        ctParam[2] = sin(240.0/180.0*PI);//C=sinU1
        ctParam[3] = sin(300.0/180.0*PI);//D=sinU2
        
		//计算合成占比
		P1 = k*(cos(rad)*ctParam[3] - sin(rad)*ctParam[1])/(ctParam[0]*ctParam[3] - ctParam[1]*ctParam[2]);
		P2 = k*(sin(rad)*ctParam[0] - cos(rad)*ctParam[2])/(ctParam[0]*ctParam[3] - ctParam[1]*ctParam[2]);

		output->pwmDutyPresent[2] = (1 - P1 - P2)/2;
		output->pwmDutyPresent[0] = output->pwmDutyPresent[2]+P1;
		output->pwmDutyPresent[1] = output->pwmDutyPresent[2]+P1+P2;
    }
    else//[300~360)
    {
        ctParam[0] = cos(300.0/180.0*PI);//A=cosU1
        ctParam[1] = cos(  0.0/180.0*PI);//B=cosU2
        ctParam[2] = sin(300.0/180.0*PI);//C=sinU1
        ctParam[3] = sin(  0.0/180.0*PI);//D=sinU2
        
		//计算合成占比
		P1 = k*(cos(rad)*ctParam[3] - sin(rad)*ctParam[1])/(ctParam[0]*ctParam[3] - ctParam[1]*ctParam[2]);
		P2 = k*(sin(rad)*ctParam[0] - cos(rad)*ctParam[2])/(ctParam[0]*ctParam[3] - ctParam[1]*ctParam[2]);

		output->pwmDutyPresent[0] = (1 - P1 - P2)/2;
		output->pwmDutyPresent[2] = output->pwmDutyPresent[0]+P2;
		output->pwmDutyPresent[1] = output->pwmDutyPresent[0]+P1+P2;
    }
    

}

