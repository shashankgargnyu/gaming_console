#ifndef __motor_H
#define __motor_H
#include "stm32f4xx_conf.h"
 
/*
���1����
*/
#define MT_1_A1 GPIO_Pin_0
#define MT_1_B1 GPIO_Pin_1
#define MT_1_A2 GPIO_Pin_2
#define MT_1_B2 GPIO_Pin_3
/*

���2����
*/
#define MT_2_A1 GPIO_Pin_4
#define MT_2_B1 GPIO_Pin_5
#define MT_2_A2 GPIO_Pin_6
#define MT_2_B2 GPIO_Pin_7
/*

���3����
*/
#define MT_3_A1 GPIO_Pin_8
#define MT_3_B1 GPIO_Pin_9
#define MT_3_A2 GPIO_Pin_10
#define MT_3_B2 GPIO_Pin_11
/*

���3����
*/
#define MT_4_A1 GPIO_Pin_12
#define MT_4_B1 GPIO_Pin_13
#define MT_4_A2 GPIO_Pin_14
#define MT_4_B2 GPIO_Pin_15
/*
*���1ʱ��궨��
*/
#define MT_1_OFF() GPIO_SetBits(GPIOC,MT_1_A1|MT_1_B1|MT_1_A2|MT_1_B2)

#define MT_1_STEP1_SET() GPIO_ResetBits(GPIOC,MT_1_B1|MT_1_A2|MT_1_B2); \
                           GPIO_SetBits(GPIOC,MT_1_A1);
 
#define MT_1_STEP2_SET() GPIO_ResetBits(GPIOC,MT_1_A2|MT_1_B2); \
                           GPIO_SetBits(GPIOC,MT_1_A1|MT_1_B1);
 
#define MT_1_STEP3_SET() GPIO_ResetBits(GPIOC,MT_1_A1|MT_1_A2|MT_1_B2); \
                           GPIO_SetBits(GPIOC,MT_1_B1);
 
#define MT_1_STEP4_SET() GPIO_ResetBits(GPIOC,MT_1_A1|MT_1_B2); \
                           GPIO_SetBits(GPIOC,MT_1_B1|MT_1_A2);
 
#define MT_1_STEP5_SET() GPIO_ResetBits(GPIOC,MT_1_A1|MT_1_B1|MT_1_B2); \
                           GPIO_SetBits(GPIOC,MT_1_A2);
 															   
#define MT_1_STEP6_SET() GPIO_ResetBits(GPIOC,MT_1_A1|MT_1_B1); \
                           GPIO_SetBits(GPIOC,MT_1_A2|MT_1_B2);
 
#define MT_1_STEP7_SET() GPIO_ResetBits(GPIOC,MT_1_A1|MT_1_B1|MT_1_A2); \
                           GPIO_SetBits(GPIOC,MT_1_B2);
 
#define MT_1_STEP8_SET() GPIO_ResetBits(GPIOC,MT_1_B1|MT_1_A2); \
                           GPIO_SetBits(GPIOC,MT_1_B2|MT_1_A1);

/*

////////////////////////////////////���3ʱ��궨�� ///////////////////////////////////////////

*/
#define MT_2_OFF() GPIO_SetBits(GPIOC,MT_2_A1|MT_2_B1|MT_2_A2|MT_2_B2)

#define MT_2_STEP1_SET() GPIO_ResetBits(GPIOC,MT_2_B1|MT_2_A2|MT_2_B2); \
                           GPIO_SetBits(GPIOC,MT_2_A1);
 
#define MT_2_STEP2_SET() GPIO_ResetBits(GPIOC,MT_2_A2|MT_2_B2); \
                           GPIO_SetBits(GPIOC,MT_2_A1|MT_2_B1);
 
#define MT_2_STEP3_SET() GPIO_ResetBits(GPIOC,MT_2_A1|MT_2_A2|MT_2_B2); \
                           GPIO_SetBits(GPIOC,MT_2_B1);
 
#define MT_2_STEP4_SET() GPIO_ResetBits(GPIOC,MT_2_A1|MT_2_B2); \
                           GPIO_SetBits(GPIOC,MT_2_B1|MT_2_A2);
 
#define MT_2_STEP5_SET() GPIO_ResetBits(GPIOC,MT_2_A1|MT_2_B1|MT_2_B2); \
                           GPIO_SetBits(GPIOC,MT_2_A2);
 															   
#define MT_2_STEP6_SET() GPIO_ResetBits(GPIOC,MT_2_A1|MT_2_B1); \
                           GPIO_SetBits(GPIOC,MT_2_A2|MT_2_B2);
 
#define MT_2_STEP7_SET() GPIO_ResetBits(GPIOC,MT_2_A1|MT_2_B1|MT_2_A2); \
                           GPIO_SetBits(GPIOC,MT_2_B2);
 
#define MT_2_STEP8_SET() GPIO_ResetBits(GPIOC,MT_2_B1|MT_2_A2); \
                           GPIO_SetBits(GPIOC,MT_2_B2|MT_2_A1);

/*

////////////////////////////////////���3ʱ��궨�� ///////////////////////////////////////////

*/
#define MT_3_OFF() GPIO_SetBits(GPIOC,MT_3_A1|MT_3_B1|MT_3_A2|MT_3_B2)

#define MT_3_STEP1_SET() GPIO_ResetBits(GPIOC,MT_3_B1|MT_3_A2|MT_3_B2); \
                           GPIO_SetBits(GPIOC,MT_3_A1);
 
#define MT_3_STEP2_SET() GPIO_ResetBits(GPIOC,MT_3_A2|MT_3_B2); \
                           GPIO_SetBits(GPIOC,MT_3_A1|MT_3_B1);
 
#define MT_3_STEP3_SET() GPIO_ResetBits(GPIOC,MT_3_A1|MT_3_A2|MT_3_B2); \
                           GPIO_SetBits(GPIOC,MT_3_B1);
 
#define MT_3_STEP4_SET() GPIO_ResetBits(GPIOC,MT_3_A1|MT_3_B2); \
                           GPIO_SetBits(GPIOC,MT_3_B1|MT_3_A2);
 
#define MT_3_STEP5_SET() GPIO_ResetBits(GPIOC,MT_3_A1|MT_3_B1|MT_3_B2); \
                           GPIO_SetBits(GPIOC,MT_3_A2);
 															   
#define MT_3_STEP6_SET() GPIO_ResetBits(GPIOC,MT_3_A1|MT_3_B1); \
                           GPIO_SetBits(GPIOC,MT_3_A2|MT_3_B2);
 
#define MT_3_STEP7_SET() GPIO_ResetBits(GPIOC,MT_3_A1|MT_3_B1|MT_3_A2); \
                           GPIO_SetBits(GPIOC,MT_3_B2);
 
#define MT_3_STEP8_SET() GPIO_ResetBits(GPIOC,MT_3_B1|MT_3_A2); \
                           GPIO_SetBits(GPIOC,MT_3_B2|MT_3_A1);

/*

////////////////////////////////////���4ʱ��궨�� ///////////////////////////////////////////

*/
#define MT_4_OFF() GPIO_SetBits(GPIOC,MT_4_B1|MT_4_A2|MT_4_B2);\
														GPIO_ResetBits(GPIOC,MT_4_A1);

#define MT_4_STEP1_SET() GPIO_ResetBits(GPIOC,MT_4_B1|MT_4_A2|MT_4_B2); \
                           GPIO_SetBits(GPIOC,MT_4_A1);
 
#define MT_4_STEP2_SET() GPIO_ResetBits(GPIOC,MT_4_A2|MT_4_B2); \
                           GPIO_SetBits(GPIOC,MT_4_A1|MT_4_B1);
 
#define MT_4_STEP3_SET() GPIO_ResetBits(GPIOC,MT_4_A1|MT_4_A2|MT_4_B2); \
                           GPIO_SetBits(GPIOC,MT_4_B1);
 
#define MT_4_STEP4_SET() GPIO_ResetBits(GPIOC,MT_4_A1|MT_4_B2); \
                           GPIO_SetBits(GPIOC,MT_4_B1|MT_4_A2);
 
#define MT_4_STEP5_SET() GPIO_ResetBits(GPIOC,MT_4_A1|MT_4_B1|MT_4_B2); \
                           GPIO_SetBits(GPIOC,MT_4_A2);
 															   
#define MT_4_STEP6_SET() GPIO_ResetBits(GPIOC,MT_4_A1|MT_4_B1); \
                           GPIO_SetBits(GPIOC,MT_4_A2|MT_4_B2);
 
#define MT_4_STEP7_SET() GPIO_ResetBits(GPIOC,MT_4_A1|MT_4_B1|MT_4_A2); \
                           GPIO_SetBits(GPIOC,MT_4_B2);
 
#define MT_4_STEP8_SET() GPIO_ResetBits(GPIOC,MT_4_B1|MT_4_A2); \
                           GPIO_SetBits(GPIOC,MT_4_B2|MT_4_A1);

extern u8 motor1,motor2,motor3,motor4; 
extern u16 step_num1,step_num2,step_num3;

void motor_Init(void);//****************************************��ʼ�����IO��
void reset_motor(void);  //*************************************��ʼ��λ��
void reagent_run(u8 name);//************************************�Լ���ת
void jion_reagent(u8 name,u16 mach);//**************************�����Լ�
void display(void);
void reset_reagent(void);//*******************************************��ʼ��ת��λ��0��
#endif
