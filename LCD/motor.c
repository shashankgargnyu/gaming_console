#include "motor.h"
#include "delay.h"
#include "lcd.h"
#include "usart.h"

char reagent_sta;
u8 motor1,motor2,motor3,motor4,reagent_name;
u16 step_num1,step_num2,step_num3,arr=80;
//////////////////////////////////////////////////////////////////////////////

void motor_Init(void)//******************************************��������������ų�ʼ��
{	
	GPIO_InitTypeDef  GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE|RCC_AHB1Periph_GPIOC|RCC_AHB1Periph_GPIOA, ENABLE);	 //ʹ��PA�˿�ʱ��->�������
RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);//�ⲿ�ж�
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;	
	GPIO_Init(GPIOC, &GPIO_InitStructure);	
	GPIO_SetBits(GPIOC,GPIO_Pin_All); 						 //PC ����� 

	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6;//->�������ź�
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; //���ó���������
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOE, &GPIO_InitStructure);
	
  	GPIO_InitStructure.GPIO_Pin  =GPIO_Pin_0;//->�����ź�
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; //���ó���������
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
  
		SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, GPIO_PinSource5);
		SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, GPIO_PinSource6);
		EXTI_ClearITPendingBit(EXTI_Line5);
		EXTI_ClearITPendingBit(EXTI_Line6);		 
	  EXTI_InitStructure.EXTI_Line = EXTI_Line5|EXTI_Line6;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;    	
	  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; 
    EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStructure);
	
    NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x0f;//���ȼ����
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x0e;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
	//GPIO_SetBits(GPIOE,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4);
}
//////////////////////////////////////////////////////////////////////////////
void Step1(void)	 //********************************************�������1ʱ�� 
{
	static u8 ucRunStep1=9;
	
	switch(motor1)
	{	
		case 0:
		 {ucRunStep1=9;MT_1_OFF();}
		break;

		case 2:
		if(++ucRunStep1>=9)
		  	ucRunStep1=1;
		break;

		case 1:
		if((ucRunStep1-=1)<1)
		  	ucRunStep1=8;
		break;

		default:
		break;
	  }
	
	switch(ucRunStep1)
	{
		case 1:
		MT_1_STEP1_SET();
		  break;
		case 2:
		MT_1_STEP2_SET();
		  break;
		case 3:
		MT_1_STEP3_SET();
		  break;
		case 4:
		MT_1_STEP4_SET();
		  break;
		case 5:
		MT_1_STEP5_SET();
		  break;
		case 6:
		MT_1_STEP6_SET();
		  break;
		case 7:
		MT_1_STEP7_SET();
		  break;
		case 8:
		MT_1_STEP8_SET();
		  break;
		default:
		break;
	  }
}
//////////////////////////////////////////////////////////////////////////////
void Step2(void)   //********************************************�������2ʱ�� 
{
	static u8 ucRunStep2=9;
	
	switch(motor2)
	{
		case 0:
		{ucRunStep2=9;MT_2_OFF();}
		break;

		case 2:
			if(++ucRunStep2>=9)
		  	ucRunStep2=1;	
		break;

		case 1:
		  if((ucRunStep2-=1)<1)
		  ucRunStep2=8;
		   break;

		default:
		break;
	  }
	
	switch(ucRunStep2)
	{
		case 1:
		MT_2_STEP1_SET();
		  break;
		case 2:
		MT_2_STEP2_SET();
		  break;
		case 3:
		MT_2_STEP3_SET();
		  break;
		case 4:
		MT_2_STEP4_SET();
		  break;
		case 5:
		MT_2_STEP5_SET();
		  break;
		case 6:
		MT_2_STEP6_SET();
		  break;
		case 7:
		MT_2_STEP7_SET();
		  break;
		case 8:
		MT_2_STEP8_SET();
		  break;
		default:
		break;
  }
}

//////////////////////////////////////////////////////////////////////////////
void Step3(void)   //********************************************�������3ʱ�� 
{
	static u8 ucRunStep3=9;
	
	switch(motor3)
	{
		case 0:
		{ucRunStep3=9;MT_3_OFF();}
		break;

		case 2:
			if(++ucRunStep3>=9)
		  	ucRunStep3=1;	
		break;

		case 1:
		  if((ucRunStep3-=1)<1)
		  ucRunStep3=8;
		   break;

		default:
		break;
	  }
	
	switch(ucRunStep3)
	{
		case 1:
		MT_3_STEP1_SET();
		  break;
		case 2:
		MT_3_STEP2_SET();
		  break;
		case 3:
		MT_3_STEP3_SET();
		  break;
		case 4:
		MT_3_STEP4_SET();
		  break;
		case 5:
		MT_3_STEP5_SET();
		  break;
		case 6:
		MT_3_STEP6_SET();
		  break;
		case 7:
		MT_3_STEP7_SET();
		  break;
		case 8:
		MT_3_STEP8_SET();
		  break;
		default:
		break;
  }
}
//////////////////////////////////////////////////////////////////////////////
void Step4(void) //**********************************************�������4ʱ�� 
{
	static u8 ucRunStep4=9;
	
	switch(motor4)
	{
		case 0:
		{ucRunStep4=9;MT_4_OFF();}
		break;

		case 2:
			if(++ucRunStep4>=9)
		  	ucRunStep4=1;	
		break;

		case 1:
		  if((ucRunStep4-=1)<1)
		  ucRunStep4=8;
		   break;

		default:
		break;
	  }
	
	switch(ucRunStep4)
	{
		case 1:
		MT_4_STEP1_SET();
		  break;
		case 2:
		MT_4_STEP2_SET();
		  break;
		case 3:
		MT_4_STEP3_SET();
		  break;
		case 4:
		MT_4_STEP4_SET();
		  break;
		case 5:
		MT_4_STEP5_SET();
		  break;
		case 6:
		MT_4_STEP6_SET();
		  break;
		case 7:
		MT_4_STEP7_SET();
		  break;
		case 8:
		MT_4_STEP8_SET();
		  break;
		default:
		break;
  }
}
//////////////////////////////////////////////////////////////////////////////
void reset_reagent()//*******************************************��ʼ��ת��λ��0��
{	
	EXTI->IMR &= 0xFFFFFF5F;//�����ж���5
	if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_6)==1)motor4 = 1;
	else
	{
		reagent_sta = 0;
		EXTI->IMR |= 0x20;//���ж���5
	}
}
//////////////////////////////////////////////////////////////////////////////
void reset_motor(void) //****************************************��ʼ����е��λ��
{
	
	motor1 = motor2 = motor3 = 1;
	do	
		{
		if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2)==0)motor1=0;
		if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)==0)motor2=0;
		if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)==0)motor3=0;
		display();
		}
	while(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2)==1 || GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)==1 || GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)==1); //��������λ 
	motor1 = motor2 = motor3 = 0;
		delay_ms(300);
		arr=300;
	step_num1 = 16000;
	step_num2 = 8500;
	motor1 = motor2 = 2;
	while(step_num1!=0)display();
	}

void reagent_run(u8 name)//**************************************�Լ���ת
{	
	static s8 i;
	i = name - reagent_sta;
	if(i<0)i=i+8;
	if(0==i)motor4 = 0;
	else if(i<=4)motor4 = 2;
	else
		motor4 = 1;
	reagent_name = name;
}
//////////////////////////////////////////////////////////////////////////////
void jion1(u8 name,u16 mach)//**************************************ע���Լ�����
{
		senddata(0,1);//���ͷ�æ��־
//  	reagent_run(name);
//  	while(reagent_sta!=name)display();
 	motor1 = 2;
	step_num1 = 4000;
	while(0!=step_num1)display();
	motor2 = 1;delay_ms(1000);delay_ms(1000);motor2 = 0;
	motor3 = 2;//ѹס�Լ�
	step_num3 = 6500;
	while(0!=step_num3)display();
	motor2 = 1;//�����Լ�
	while(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)==1)display();
	motor2 = 0;
	motor1 = 1;//�����ձ�
	while(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2)==1)display();
	motor1 = 0;
	motor2 = 2;//�½��Լ� 
	step_num2 = 4000;
	while(step_num2!=0)display();
	motor3 = 2;
	step_num3 = mach;
	while(step_num3!=0)display();//�������
}
//////////////////////////////////////////////////////////////////////////////////
void jion2(u16 rstep)//**************************************���ز���
{
	motor1 = motor2 =  1;
	do	
		{
		if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2)==0)motor1=0;
		if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)==0)motor2=0;
		display();
		}
	while(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2)==1 | GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)==1); //��������λ 
	motor2 = 0;
		delay_ms(300);
		arr=300;
	step_num1 = rstep;
	motor1 = 2;
	while(step_num1!=0)display();
	motor2 = 2;//����ע����
	step_num2 = 8500;
	while(step_num2>500)display();
	motor3 = 1;//�ͷŻ���
	while(step_num2!=0){if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)==0)motor3=0;display();}
	motor2 = 0;
	while(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)==1);motor3=0;
	motor1 = 1;
	step_num1 = 4000;//���˵ȴ�
	while(step_num1!=0)display();
	senddata(0,0);//�己æ��־
}
void jion_reagent(u8 name,u16 mach)//****************************�����Լ�
{
	jion1(name,mach);
	jion2(20000);
	
}
//////////////////////////////////////////////////////////////////////////////
void TIM2_IRQHandler(void)   //**********************************TIM2�жϣ�����1�ŵ��
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update)!=RESET) //���ָ����TIM�жϷ������:TIM �ж�Դ 
		{
				TIM_ClearITPendingBit(TIM2, TIM_IT_Update );  //���TIMx���жϴ�����λ:TIM �ж�Դ 
		
 		if(step_num1>=10000&&TIM3->ARR>100&&motor1==2)arr--;
		if(arr>400)arr = 400;
			
		//	dog--;
		//	if(0==dog)NVIC_SystemReset();
				 

		}
}
//////////////////////////////////////////////////////////////////////////////
void TIM3_IRQHandler(void)   //**********************************TIM3�жϣ�����1�ŵ��
{
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET) //���ָ����TIM�жϷ������:TIM �ж�Դ 
		{
			Step1();
			if(step_num1!=0)
			{
				step_num1--;
				if(step_num1==0)motor1 = 0;	
			}

			TIM3->ARR=arr;
			TIM_ClearITPendingBit(TIM3, TIM_IT_Update  );  //���TIMx���жϴ�����λ:TIM �ж�Դ 

		}
}
//////////////////////////////////////////////////////////////////////////////
void TIM4_IRQHandler(void)   //**********************************TIM4�ж�	������2,3��4�ŵ��
{  
	static u8 i;
	if (TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET) //���ָ����TIM�жϷ������:TIM �ж�Դ 
		{
		TIM_ClearITPendingBit(TIM4, TIM_IT_Update  );  //���TIMx���жϴ�����λ:TIM �ж�Դ 
		 
		 Step2();
		 Step3();
		 if(step_num2!=0)
		 	{
				step_num2--;
				if(step_num2==0)motor2=0;
			}
		 if(step_num3!=0)
		 	{
				step_num3--;
				if(step_num3==0)motor3=0;
			}
		 i++;
		 if(i>=12)
		 	{
				Step4();
				i=0;
			}
		}
}


//////////////////////////////////////////////////////////////////////////////
void EXTI9_5_IRQHandler(void)//********************************�ⲿ�ж�5~6�����->ת�̴����� 
{
	Delay(0xFFFFF);
	if(EXTI_GetITStatus(EXTI_Line5)!=RESET)	 	 //
	{	
		if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_5)==0)
		{
			if(motor4==2)reagent_sta++;
			else if(motor4==1)reagent_sta--;
			if(reagent_sta<0)reagent_sta = 7;
			else if(reagent_sta>7)reagent_sta = 0;
			if(reagent_sta==reagent_name)motor4 = 0;
		}
		EXTI_ClearITPendingBit(EXTI_Line5); //���LINE13�ϵ��жϱ�־λ	
	}
	 
  if(EXTI_GetITStatus(EXTI_Line6)!=RESET)	 	 //��ʼλ��
	{				 
		motor4=0;
		reagent_sta = 0;
		EXTI_ClearITPendingBit(EXTI_Line6); //���LINE11�ϵ��жϱ�־λ
		EXTI->IMR &= 0xFFFFFFBF;//�����ж���6
		EXTI->IMR |= 0x20;
	}
}
void display(void)
{	LCD_Num(10,60,motor1,1,0x7FFF);LCD_Num(10,90,motor2,1,0x7FFF);LCD_Num(10,120,motor3,1,0x7FFF);LCD_Num(60,60,step_num1,5,MAGENTA);LCD_Num(60,90,step_num2,5,MAGENTA);LCD_Num(60,120,step_num3,5,MAGENTA);
LCD_Num(150,60,arr,3,0x7FFF);}

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
