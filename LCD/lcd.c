#include "lcd.h"
#include "delay.h"

/*Pin Description
**CS->PD7
**RS->PD11
**WR->PD5
**RD->PD4
**LCD _D[0~15]->FSMC_D15~FSMC_D0¼´PD14,PD15,PD0,PD1,PE7~PE15,PD8~PD10
*/
void LCD_LineConf(void)//**********************************************GPIO initialization
{
  	GPIO_InitTypeDef GPIO_InitStructure;

  	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD | RCC_AHB1Periph_GPIOE, ENABLE);
  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_4 | GPIO_Pin_5 |
                   GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_14 | GPIO_Pin_15;
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
  	GPIO_Init(GPIOD, &GPIO_InitStructure);
  	GPIO_PinAFConfig(GPIOD, GPIO_PinSource0, GPIO_AF_FSMC);
  	GPIO_PinAFConfig(GPIOD, GPIO_PinSource1, GPIO_AF_FSMC);
  	GPIO_PinAFConfig(GPIOD, GPIO_PinSource4, GPIO_AF_FSMC);
  	GPIO_PinAFConfig(GPIOD, GPIO_PinSource5, GPIO_AF_FSMC);
  	GPIO_PinAFConfig(GPIOD, GPIO_PinSource8, GPIO_AF_FSMC);
  	GPIO_PinAFConfig(GPIOD, GPIO_PinSource9, GPIO_AF_FSMC);
  	GPIO_PinAFConfig(GPIOD, GPIO_PinSource10, GPIO_AF_FSMC);
  	GPIO_PinAFConfig(GPIOD, GPIO_PinSource14, GPIO_AF_FSMC);
  	GPIO_PinAFConfig(GPIOD, GPIO_PinSource15, GPIO_AF_FSMC);
  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 |
    GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
    //GPIO_SetBits(GPIOD,GPIO_Pin_All);/////////////////////////////////////////////
  	GPIO_Init(GPIOE, &GPIO_InitStructure);
  	GPIO_PinAFConfig(GPIOE, GPIO_PinSource7 , GPIO_AF_FSMC);
  	GPIO_PinAFConfig(GPIOE, GPIO_PinSource8 , GPIO_AF_FSMC);
  	GPIO_PinAFConfig(GPIOE, GPIO_PinSource9 , GPIO_AF_FSMC);
  	GPIO_PinAFConfig(GPIOE, GPIO_PinSource10 , GPIO_AF_FSMC);
  	GPIO_PinAFConfig(GPIOE, GPIO_PinSource11 , GPIO_AF_FSMC);
  	GPIO_PinAFConfig(GPIOE, GPIO_PinSource12 , GPIO_AF_FSMC);
  	GPIO_PinAFConfig(GPIOE, GPIO_PinSource13 , GPIO_AF_FSMC);
  	GPIO_PinAFConfig(GPIOE, GPIO_PinSource14 , GPIO_AF_FSMC);
  	GPIO_PinAFConfig(GPIOE, GPIO_PinSource15 , GPIO_AF_FSMC);
  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;//(RS)
  	GPIO_Init(GPIOD, &GPIO_InitStructure);  
  	GPIO_PinAFConfig(GPIOD, GPIO_PinSource11, GPIO_AF_FSMC);	   
  	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;//(CS) 
  	GPIO_Init(GPIOD, &GPIO_InitStructure);
  	GPIO_PinAFConfig(GPIOD, GPIO_PinSource7, GPIO_AF_FSMC);
		
		/* ili9481 RST Pin config*/
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;	
  	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  	GPIO_Init(GPIOD, &GPIO_InitStructure);
    printf("GPIO_config\n");
}

void LCD_FSMCConf(void)//**********************************************FSMC initialization
{
  	FSMC_NORSRAMInitTypeDef  FSMC_NORSRAMInitStructure;
  	FSMC_NORSRAMTimingInitTypeDef  p;

  	RCC_AHB3PeriphClockCmd(RCC_AHB3Periph_FSMC, ENABLE);
  	p.FSMC_AddressSetupTime = 5;
  	p.FSMC_AddressHoldTime = 0;
  	p.FSMC_DataSetupTime = 9;
  	p.FSMC_BusTurnAroundDuration = 0;
  	p.FSMC_CLKDivision = 0;
  	p.FSMC_DataLatency = 0;
  	p.FSMC_AccessMode = FSMC_AccessMode_A;
  	FSMC_NORSRAMInitStructure.FSMC_Bank = FSMC_Bank1_NORSRAM1;
  	FSMC_NORSRAMInitStructure.FSMC_DataAddressMux = FSMC_DataAddressMux_Disable;
  	FSMC_NORSRAMInitStructure.FSMC_MemoryType = FSMC_MemoryType_SRAM;
  	FSMC_NORSRAMInitStructure.FSMC_MemoryDataWidth = FSMC_MemoryDataWidth_16b;
  	FSMC_NORSRAMInitStructure.FSMC_BurstAccessMode = FSMC_BurstAccessMode_Disable;
  	FSMC_NORSRAMInitStructure.FSMC_AsynchronousWait = FSMC_AsynchronousWait_Disable;
  	FSMC_NORSRAMInitStructure.FSMC_WaitSignalPolarity = FSMC_WaitSignalPolarity_Low;
  	FSMC_NORSRAMInitStructure.FSMC_WrapMode = FSMC_WrapMode_Disable;
  	FSMC_NORSRAMInitStructure.FSMC_WaitSignalActive = FSMC_WaitSignalActive_BeforeWaitState;
  	FSMC_NORSRAMInitStructure.FSMC_WriteOperation = FSMC_WriteOperation_Enable;
  	FSMC_NORSRAMInitStructure.FSMC_WaitSignal = FSMC_WaitSignal_Disable;
  	FSMC_NORSRAMInitStructure.FSMC_ExtendedMode = FSMC_ExtendedMode_Disable;
  	FSMC_NORSRAMInitStructure.FSMC_WriteBurst = FSMC_WriteBurst_Disable;
  	FSMC_NORSRAMInitStructure.FSMC_ReadWriteTimingStruct = &p;
  	FSMC_NORSRAMInitStructure.FSMC_WriteTimingStruct = &p;
  	FSMC_NORSRAMInit(&FSMC_NORSRAMInitStructure);   
  	FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM1, ENABLE);
    printf("fsmc_config\n");
}

void LCD_WriteReg(u8 Reg, u16 Value)//*********************************write REG
{
  	LCD_REG=Reg;
  	LCD_RAM=Value;
}

u16 LCD_ReadReg(u8 Reg)//**********************************************read REG
{
  	LCD_REG=Reg;
  	return (LCD_RAM);
}

void LCD_WriteRAM(u16 RGB_Code)//**************************************write RAM
{
  	LCD_RAM=RGB_Code;
}

u16 LCD_ReadRAM(void)//************************************************read RAM
{
  	LCD_REG=0x22; 
  	return LCD_RAM;
}
void ili9481_Reset(void)
{
    printf("reached inside\n");
    //GPIO_SetBits(GPIOD,GPIO_Pin_6);
	RST_HIGH();
	delay_ms(1);
	//GPIO_ResetBits(GPIOD,GPIO_Pin_6);
	RST_LOW();
	delay_ms(1);
	//GPIO_SetBits(GPIOD,GPIO_Pin_6);
	RST_HIGH();
	delay_ms(1);
    printf("Reset_inside\n");
}

void LCD_Init(void)//***********************id=0x1260***************************LCD initialization
{ 
 
   	LCD_LineConf();
  	LCD_FSMCConf();
    printf("out of fsmc\n");
  	delay_ms(5);
    printf("delay over\n");
	ili9481_Reset();
    printf("reset_done\n");
 
/*
	LCD_WriteReg(0x11,0x2004);		
	LCD_WriteReg(0x13,0xCC00);		
	LCD_WriteReg(0x15,0x2600);	
	LCD_WriteReg(0x14,0x252A);	
		
	LCD_WriteReg(0x12,0x0033);		
	LCD_WriteReg(0x13,0xCC04);		
	delay_ms(1); 
	LCD_WriteReg(0x13,0xCC06);		
	delay_ms(1); 
	LCD_WriteReg(0x13,0xCC4F);		
	delay_ms(1); 
	LCD_WriteReg(0x13,0x674F);
	LCD_WriteReg(0x11,0x2003);
	delay_ms(1); 	
	LCD_WriteReg(0x30,0x2609);		
	LCD_WriteReg(0x31,0x242C);		
	LCD_WriteReg(0x32,0x1F23);		
	LCD_WriteReg(0x33,0x2425);		
	LCD_WriteReg(0x34,0x2226);		
	LCD_WriteReg(0x35,0x2523);		
	LCD_WriteReg(0x36,0x1C1A);		
	LCD_WriteReg(0x37,0x131D);		
	LCD_WriteReg(0x38,0x0B11);		
	LCD_WriteReg(0x39,0x1210);		
	LCD_WriteReg(0x3A,0x1315);		
	LCD_WriteReg(0x3B,0x3619);		
	LCD_WriteReg(0x3C,0x0D00);		
	LCD_WriteReg(0x3D,0x000D);		
	LCD_WriteReg(0x16,0x0007);		
	LCD_WriteReg(0x02,0x0013);		
	LCD_WriteReg(0x03,0x0008);		//////////////
	LCD_WriteReg(0x01,0x0127);		
	delay_ms(1); 
	LCD_WriteReg(0x08,0x0303);		
	LCD_WriteReg(0x0A,0x000B);		
	LCD_WriteReg(0x0B,0x0003);   
	LCD_WriteReg(0x0C,0x0000);   
	LCD_WriteReg(0x41,0x0000);    
	LCD_WriteReg(0x50,0x0000);   
	LCD_WriteReg(0x60,0x0005);    
    LCD_WriteReg(0x70,0x000B);
	LCD_WriteReg(0x71,0x0000);    
	LCD_WriteReg(0x78,0x0000);    
	LCD_WriteReg(0x7A,0x0000);   
	LCD_WriteReg(0x79,0x0007);		
// 	LCD_WriteReg(0x07,0x0051);   
// 	delay_ms(1); 	
	LCD_WriteReg(0x07,0x0053);		
	LCD_WriteReg(0x79,0x0000);
//	LCD_WR_REG(0x0022);
	LCD_REG=0x0022;
 
	
	LCD_Font(&Font16x24);
//	LCD_Mode(5);
*/

    LCD_WriteReg(0x0000,0x0001);// Enable LCD Oscillator
    delay_ms(50);
    LCD_WriteReg(0x0003,0xA8A4);// Power Control
    delay_ms(50);
    LCD_WriteReg(0x000C,0x0000);
    delay_ms(50);
    LCD_WriteReg(0x000D,0x080C);
    delay_ms(50);
    LCD_WriteReg(0x000E,0x2B00);
    delay_ms(50);
    LCD_WriteReg(0x001E,0x00B0);
    delay_ms(50);
    LCD_WriteReg(0x0001,0x2B3F);// Output Control
    /* 320*240 0x2B3F */
    delay_ms(50);
    LCD_WriteReg(0x0002,0x0600);// LCD Driving waveform Control
    delay_ms(50);
    LCD_WriteReg(0x0010,0x0000);
    delay_ms(50);
    LCD_WriteReg(0x0011,0x6070);
    delay_ms(50);
    LCD_WriteReg(0x0005,0x0000);
    delay_ms(50);
    LCD_WriteReg(0x0006,0x0000);
    delay_ms(50);
    LCD_WriteReg(0x0016,0xEF1C);
    delay_ms(50);
    LCD_WriteReg(0x0017,0x0003);
    delay_ms(50);
    LCD_WriteReg(0x0007,0x0133);
    delay_ms(50);
    LCD_WriteReg(0x000B,0x0000);
    delay_ms(50);
    LCD_WriteReg(0x000F,0x0000);
    delay_ms(50);
    LCD_WriteReg(0x0041,0x0000);
    delay_ms(50);
    LCD_WriteReg(0x0042,0x0000);
    delay_ms(50);
    LCD_WriteReg(0x0048,0x0000);
    delay_ms(50);
    LCD_WriteReg(0x0049,0x013F);
    delay_ms(50);
    LCD_WriteReg(0x004A,0x0000);
    delay_ms(50);
    LCD_WriteReg(0x004B,0x0000);
    delay_ms(50);
    LCD_WriteReg(0x0044,0xEF00);
    delay_ms(50);
    LCD_WriteReg(0x0045,0x0000);
    delay_ms(50);
    LCD_WriteReg(0x0046,0x013F);
    delay_ms(50);
    LCD_WriteReg(0x0030,0x0707);
    delay_ms(50);
    LCD_WriteReg(0x0031,0x0204);
    delay_ms(50);
    LCD_WriteReg(0x0032,0x0204);
    delay_ms(50);
    LCD_WriteReg(0x0033,0x0502);
    delay_ms(50);
    LCD_WriteReg(0x0034,0x0507);
    delay_ms(50);
    LCD_WriteReg(0x0035,0x0204);
    delay_ms(50);
    LCD_WriteReg(0x0036,0x0204);
    delay_ms(50);
    LCD_WriteReg(0x0037,0x0502);
    delay_ms(50);
    LCD_WriteReg(0x003A,0x0302);
    delay_ms(50);
    LCD_WriteReg(0x003B,0x0302);
    delay_ms(50);
    LCD_WriteReg(0x0023,0x0000);
    delay_ms(50);
    LCD_WriteReg(0x0024,0x0000);
    delay_ms(50);
    LCD_WriteReg(0x0025,0x8000);
    delay_ms(50);
    LCD_WriteReg(0x004f,0);
    LCD_WriteReg(0x004e,0);
    /* delay_ms 50 ms */
    delay_ms(1000);
    //LCD_Clear(BLACK);
    delay_ms(1000);
    printf("LCD_config\n");
    delay_ms(1000);
    u16 lcdid;
    lcdid=LCD_ReadReg(0x00);
    if (lcdid==0x8989) {
        printf("yes\n");
    }
    

}

void LCD_Font(sFONT *font)//*******************************************Set the font 16*24 12*12 8*12 8*8
{
  	Efont=font;
}

void LCD_Cursor(u16 Xpos, u16 Ypos)//**********************************Set the cursor
{
  	LCD_WriteReg(0x4E, Xpos);
  	LCD_WriteReg(0x4F, Ypos);
}


void LCD_Window(u16 Xpos, u16 Ypos, u16 Height, u16 Width)//X,Y Coordinates for the lower left corner of the window,
                                                          //Note window after setting the coordinates do not exceed this range
{
  	if(Xpos>=Height)LCD_WriteReg(0x50,(Xpos-Height+1));
  	else LCD_WriteReg(0x50,0);
  	LCD_WriteReg(0x51,Xpos);
  	if(Ypos>=Width)LCD_WriteReg(0x52,(Ypos-Width+1)); 
  	else LCD_WriteReg(0x52,0);
  	LCD_WriteReg(0x53,Ypos);
  	LCD_Cursor(Xpos,Ypos);
}


void LCD_Mode(u8 mode)//***********************************************Setting refresh mode
{
	switch(mode)//Common 4 ( landscape ) and 7 ( portrait )
	{
		case 1:LCD_WriteReg(0x03,0x00);break;//Left up : ¡û ¨I
		case 2:LCD_WriteReg(0x03,0x01);break;//Up Left : ¡ü ¨I
		case 3:LCD_WriteReg(0x03,0x02);break;//Right up : ¡ú ¨J
		case 4:LCD_WriteReg(0x03,0x03);break;//Up right : ¡ü ¨J
		case 5:LCD_WriteReg(0x03,0x08);break;//Left down : ¡û ¨L
		case 6:LCD_WriteReg(0x03,0x09);break;//Down Left : ¡ý ¨L
		case 7:LCD_WriteReg(0x03,0x0a);break;//Right down : ¡ú ¨K
		case 8:LCD_WriteReg(0x03,0x0b);break;//Down right : ¡ý ¨K
	}
}

void LCD_Clear(u16 Color)//********************************************Clear screen
{
  	u32 index=0;
 
  	LCD_Cursor(0x00, 0x00); 
  	LCD_REG=0x22;//WriteRAM_Prepare 
  	for(index=0;index<76800;index++)LCD_RAM=Color;
}

void LCD_Point(u16 xpos, u16 ypos,u16 color)//*************************Stippled
{
	LCD_Cursor(xpos,ypos);
	LCD_REG=0x22;//WriteRAM_Prepare 
	LCD_RAM=color;
}

void LCD_Line(u16 x1, u16 y1, u16 x2, u16 y2, u16 color)//*************Draw lines
{
	u16 t; 
	int xerr=0,yerr=0,delta_x,delta_y,distance; 
	int incx,incy,uRow,uCol; 

	delta_x=x2-x1; //Calculating the coordinates Incremental 
	delta_y=y2-y1; 
	uRow=x1; 
	uCol=y1; 
	if(delta_x>0)incx=1; //Set single-step directions 
	else if(delta_x==0)incx=0;//Vertical line 
	else {incx=-1;delta_x=-delta_x;} 
	if(delta_y>0)incy=1; 
	else if(delta_y==0)incy=0;//Level 
	else{incy=-1;delta_y=-delta_y;} 
	if( delta_x>delta_y)distance=delta_x; //Select the basic incremental axis 
	else distance=delta_y; 
	for(t=0;t<=distance+1;t++ )//Drawing a line output 
	{  
		LCD_Point(uRow,uCol,color);//Stippled 
		xerr+=delta_x ; 
		yerr+=delta_y ; 
		if(xerr>distance) 
		{ 
			xerr-=distance; 
			uRow+=incx; 
		} 
		if(yerr>distance) 
		{ 
			yerr-=distance; 
			uCol+=incy; 
		} 
	}  
}

void LCD_Rect(u16 x1, u16 y1, u16 x2, u16 y2, u16 color)//*************Setting area
{
	LCD_Line(x1,y1,x2,y1,color);
	LCD_Line(x1,y1,x1,y2,color);
	LCD_Line(x1,y2,x2,y2,color);
	LCD_Line(x2,y1,x2,y2,color);
}

void LCD_Circle(u16 Xpos, u16 Ypos, u16 Radius, u16 color)//***********Circle
{
  	s32  Dec;
  	u32  CurX;
  	u32  CurY;
	 
  	CurX=0;
  	CurY=Radius;   
  	Dec=3-(Radius<<1);
  	while(CurX<=CurY)
  	{
		LCD_Point(Xpos+CurX,Ypos+CurY,color);
		LCD_Point(Xpos+CurX,Ypos-CurY,color);
		LCD_Point(Xpos-CurX,Ypos+CurY,color);
		LCD_Point(Xpos-CurX,Ypos-CurY,color);
		LCD_Point(Xpos+CurY,Ypos+CurX,color);
		LCD_Point(Xpos+CurY,Ypos-CurX,color);
		LCD_Point(Xpos-CurY,Ypos+CurX,color);
		LCD_Point(Xpos-CurY,Ypos-CurX,color);
		if(Dec<0)Dec+=(CurX<<2)+6;
	    else
	    {
	      	Dec+=((CurX-CurY)<<2)+10;
	      	CurY--;
	    }
	    CurX++;
  	}
}


void LCD_Fill(u16 x1, u16 y1, u16 x2, u16 y2, u16 color)//*************Fill Color
{
    
	u16 i,j,k,l;
	u16 xlen=0;
	u16 ylen=0;
	

	xlen=y2-y1+1;	   
	for(i=x1;i<=x2;i++)
	{
	 	LCD_Cursor(i,y2);
		LCD_REG=0x22;      	  
		for(j=0;j<xlen;j++)LCD_WriteRAM(color); 	  
	}
     //ylen=x2-x1+1;	   
	/* for(k=y1;k<=x2;k++)
	{
	 	LCD_Cursor(x2,k);
		LCD_REG=0x22;      	  
		for(l=0;l<ylen;l++)LCD_WriteRAM(color); 	  
	} */ 
}  

void LCD_Char(u16 Xpos, u16 Ypos, u8 Ascii, u16 color)//***************Display character
{
    printf("inside char\n");
    const u16 *c;
  	u16 Xaddr=0; 
  	u32 index=0,i=0;
					 
  	Xaddr=Xpos;
	c=&Efont->table[(Ascii-32)*Efont->Height]; 
  	LCD_Cursor(Xaddr, Ypos);  
  	for(index=0;index<Efont->Height;index++)
  	{
    	LCD_REG=0x22;//WriteRAM_Prepare
    	for(i=0;i<Efont->Width;i++)
    	{  
			if((((c[index]&((0x80<<((Efont->Width/12)*8))>>i))==0x00)&&(Efont->Width<=12))
			||(((c[index]&(0x1<<i))==0x00)&&(Efont->Width>12)))LCD_WriteRAM(BLUE);
      		else LCD_WriteRAM(color); 
    	}
    	Xaddr++;
    	LCD_Cursor(Xaddr, Ypos);
  	}
    printf("char done\n");
}

void LCD_String(u16 xpos, u16 ypos, u8 *ptr, u16 color)//**************Display string
{
  	u16 refypos=LCD_WIDTH-xpos;

  	while((*ptr!=0)&(((refypos+1)&0xFFFF)>=Efont->Width))
  	{
    	LCD_Char(ypos,refypos,*ptr,color);
    	refypos-=Efont->Width;
    	ptr++;
  	}
}


u32 mypow(u8 m,u8 n)//*************************************************m ^ n function
{
	uint32_t result=1;	 
	while(n--)result*=m;    
	return result;
}			 
	 
void LCD_Num(u16 x, u16 y, s32 num, u8 len, u16 color)//***************Digital Display
{         	
	u8 t,temp;
	u8 enshow=0;
	t=0;
	if(num<0)
	{
		LCD_Char(y,LCD_WIDTH-x-(Efont->Width)*t,'-',color);
		num=-num;
		t++;
	}						   
	for(;t<len;t++)
	{
		temp=(num/mypow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				LCD_Char(y,LCD_WIDTH-x-(Efont->Width)*t,' ',color);
				continue;
			}else enshow=1; 		 	 
		}
	 	LCD_Char(y,LCD_WIDTH-x-(Efont->Width)*t,temp+'0',color); 
	}
} 

