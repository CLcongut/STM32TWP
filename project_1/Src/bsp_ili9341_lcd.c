/***************************************************/
/**********本程序适配控制器ILI9341******************/
/***************************************************/
#include "bsp_ili9341_lcd.h"
#include "fonts.h" 
#include "tim.h"
//画笔颜色,背景颜色
uint16_t POINT_COLOR = 0x0000,BACK_COLOR = 0xFFFF;  
uint16_t DeviceCode;	 
uint16_t LCD_X_LENGTH = ILI9341_LESS_PIXEL;
uint16_t LCD_Y_LENGTH = ILI9341_MORE_PIXEL;

/*******************************************************
功　能：GPIOD写入u16数据
参　数：无
返回值：无
********************************************************/
void Write_u16_data(GPIO_TypeDef* GPIOx,uint16_t data)
{
	uint16_t buff;
	buff = ~data;
	GPIOx->BSRR = (buff<<16)|data;
	
}
/*******************************************************
功　能：读取GPIO输出数据
参　数：无
返回值：无
********************************************************/
uint16_t GPIO_ReadOutputData(GPIO_TypeDef* GPIOx)
{
  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));

  return ((uint16_t)GPIOx->ODR);
}
#if LCD_FAST_IO==1 //快速IO

/*******************************************************
功　能：LCD复位
参　数：无
返回值：无
********************************************************/
void LCD_RESET(void)
{ 
	LCD_RST_SET;//高电平  
 	TIM_Delay_ms(1);
	LCD_RST_CLR;//低电平
	TIM_Delay_ms(20);
	LCD_RST_SET;//高电平  
	TIM_Delay_ms(20);
}
#else//正常IO

/*******************************************************
功　能：LCD复位
参　数：无
返回值：无
********************************************************/
void LCD_RESET(void)
{ 
	LCD_RST(1);  
 	TIM_Delay_ms(1);
	LCD_RST(0);//低电平
	TIM_Delay_ms(20);
	LCD_RST(1);//高电平  
	TIM_Delay_ms(20);
} 	
#endif

#if LCD_FAST_IO==1 //快速IO

/*******************************************************
功　能：写寄存器函数
参　数：data：寄存器值
返回值：无
********************************************************/
void LCD_WR_REG(uint8_t data)
{ 
	LCD_RS_CLR;//写地址  
 	LCD_CS_CLR; 
	DATAOUT(data); 
	LCD_WR_CLR; 
	LCD_WR_SET; 
 	LCD_CS_SET;   
}
#else//正常IO

/*******************************************************
功　能：写寄存器函数
参　数：data：寄存器值
返回值：无
********************************************************/
void LCD_WR_REG(uint8_t data)
{ 
	LCD_RS(0);//写地址  
 	LCD_CS(0); 
	DATAOUT(data); 
	LCD_WR(0); 
	LCD_WR(1); 
 	LCD_CS(1);   
} 	
#endif	

/*******************************************************
功　能：写寄存器
参　数：LCD_Reg:寄存器地址
	    LCD_RegValue:要写入的数据
返回值：无
********************************************************/
void LCD_WriteReg(uint8_t LCD_Reg, uint16_t LCD_RegValue)
{	
	LCD_WR_REG(LCD_Reg);  
	LCD_WR_DATA(LCD_RegValue);	    		 
}	   
 
/*******************************************************
功　能：开始写GRAM
参　数：无
返回值：无
********************************************************/
void LCD_WriteRAM_Prepare(void)
{
	LCD_WR_REG(0x2c);
}	 


/*******************************************************
功　能：LCD写GRAM
参　数：RGB_Code:颜色值
返回值：无
********************************************************/
void LCD_WriteRAM(uint16_t RGB_Code)
{							    
	LCD_WR_DATA(RGB_Code);//写十六位GRAM
}



/*******************************************************
功　能：从ILI93xx读出的数据为GBR格式，而我们写入
		的时候为RGB格式，通过该函数转换
参　数：c:GBR格式的颜色值
返回值：RGB格式的颜色值
********************************************************/
uint16_t LCD_BGR2RGB(uint16_t c)
{
	uint16_t  r,g,b,rgb;   
	b=(c>>0)&0x1f;
	g=(c>>5)&0x3f;
	r=(c>>11)&0x1f;	 
	rgb=(b<<11)+(g<<5)+(r<<0);		 
	return(rgb);
}		 


/*******************************************************
功　能：设置光标位置
参　数：Xpos:横坐标
		Ypos:纵坐标
返回值：
********************************************************/
__inline void LCD_SetCursor(uint16_t xsta, uint16_t ysta,uint16_t xend,uint16_t yend)
{ 


	LCD_WR_REG(0x2a);
	LCD_WR_DATA(xsta>>8);
	LCD_WR_DATA(xsta);
	LCD_WR_DATA(xend>>8);
	LCD_WR_DATA(xend);

	LCD_WR_REG(0x2b);
	LCD_WR_DATA(ysta>>8);
	LCD_WR_DATA(ysta);
	LCD_WR_DATA(yend>>8);
	LCD_WR_DATA(yend);

	LCD_WriteRAM_Prepare();     //开始写入GRAM
}


/*******************************************************
功　能：画点
参　数：x:0~239
		y:0~319
		POINT_COLOR:此点的颜色
返回值：无
********************************************************/
void LCD_DrawPoint(uint16_t x,uint16_t y)
{
	LCD_SetCursor(x,y,x,y);
	LCD_WR_DATA(POINT_COLOR); 
}

/*******************************************************
功　能：初始化lcd
参　数：无
返回值：无
备  注：该初始化函数可以初始化各种ILI93XX液晶,但是其他函数
	    是基于ILI9320的!在其他型号的驱动芯片上没有测试! 
********************************************************/
void LCD_Init(void)
{ 


	LCD_RESET();//复位
	LCD_RST_BL;  					 
	TIM_Delay_ms(5); // TIM_Delay_ms 5 ms 
	LCD_WriteReg(0x0000,0x0001);
	TIM_Delay_ms(5); // TIM_Delay_ms 5 ms 
 
	//************* Start Initial Sequence **********//   ILI9341+IVO2.8
	LCD_WR_REG(0xCF);  
	LCD_WR_DATA(0x00); 
	LCD_WR_DATA(0xD9); 
	LCD_WR_DATA(0X30); 
	 
	LCD_WR_REG(0xED);  
	LCD_WR_DATA(0x64); 
	LCD_WR_DATA(0x03); 
	LCD_WR_DATA(0X12); 
	LCD_WR_DATA(0X81); 
	 
	LCD_WR_REG(0xE8);  
	LCD_WR_DATA(0x85); 
	LCD_WR_DATA(0x10); 
	LCD_WR_DATA(0x78); 
	 
	LCD_WR_REG(0xCB);  
	LCD_WR_DATA(0x39); 
	LCD_WR_DATA(0x2C); 
	LCD_WR_DATA(0x00); 
	LCD_WR_DATA(0x34); 
	LCD_WR_DATA(0x02); 
	 
	LCD_WR_REG(0xF7);  
	LCD_WR_DATA(0x20); 
	 
	LCD_WR_REG(0xEA);  
	LCD_WR_DATA(0x00); 
	LCD_WR_DATA(0x00); 
	 
	LCD_WR_REG(0xC0);    //Power control 
	LCD_WR_DATA(0x21);   //VRH[5:0] 
	 
	LCD_WR_REG(0xC1);    //Power control 
	LCD_WR_DATA(0x12);   //SAP[2:0];BT[3:0] 
	 
	LCD_WR_REG(0xC5);    //VCM control 
	LCD_WR_DATA(0x32); 
	LCD_WR_DATA(0x3C); 
	 
	LCD_WR_REG(0xC7);    //VCM control2 
	LCD_WR_DATA(0XC1); 
	 
	LCD_WR_REG(0x36);    // Memory Access Control 
	LCD_WR_DATA(0x08); 
	 
	LCD_WR_REG(0x3A);   
	LCD_WR_DATA(0x55); 
	
	LCD_WR_REG(0xB1);   
	LCD_WR_DATA(0x00);   
	LCD_WR_DATA(0x18); 
	 
	LCD_WR_REG(0xB6);    // Display Function Control 
	LCD_WR_DATA(0x0A); 
	LCD_WR_DATA(0xA2); 
	 
	LCD_WR_REG(0xF2);    // 3Gamma Function Disable 
	LCD_WR_DATA(0x00); 
	 
	LCD_WR_REG(0x26);    //Gamma curve selected 
	LCD_WR_DATA(0x01); 
	 
	LCD_WR_REG(0xE0);    //Set Gamma 
	LCD_WR_DATA(0x0F); 
	LCD_WR_DATA(0x20); 
	LCD_WR_DATA(0x1E); 
	LCD_WR_DATA(0x09); 
	LCD_WR_DATA(0x12); 
	LCD_WR_DATA(0x0B); 
	LCD_WR_DATA(0x50); 
	LCD_WR_DATA(0XBA); 
	LCD_WR_DATA(0x44); 
	LCD_WR_DATA(0x09); 
	LCD_WR_DATA(0x14); 
	LCD_WR_DATA(0x05); 
	LCD_WR_DATA(0x23); 
	LCD_WR_DATA(0x21); 
	LCD_WR_DATA(0x00); 
	 
	LCD_WR_REG(0XE1);    //Set Gamma 
	LCD_WR_DATA(0x00); 
	LCD_WR_DATA(0x19); 
	LCD_WR_DATA(0x19); 
	LCD_WR_DATA(0x00); 
	LCD_WR_DATA(0x12); 
	LCD_WR_DATA(0x07); 
	LCD_WR_DATA(0x2D); 
	LCD_WR_DATA(0x28); 
	LCD_WR_DATA(0x3F); 
	LCD_WR_DATA(0x02); 
	LCD_WR_DATA(0x0A); 
	LCD_WR_DATA(0x08); 
	LCD_WR_DATA(0x25); 
	LCD_WR_DATA(0x2D); 
	LCD_WR_DATA(0x0F); 
	 
	LCD_WR_REG(0x11);    //Exit Sleep 
	TIM_Delay_ms(120); 
	LCD_WR_REG(0x29);    //Display on 

	LCD_LED(GPIO_PIN_SET);//点亮背光	 
	LCD_Clear(WHITE);
}  		  
  

/*******************************************************
功　能：清屏函数
参　数：Color:要清屏的填充色
返回值：无
********************************************************/
void LCD_Clear(uint16_t Color)
{
    LCD_Fill(0,0,239,319,Color);
}  


/*******************************************************
功　能：在指定区域内填充指定颜色
参　数：区域大小:(xend-xsta)*(yend-ysta)
返回值：无
********************************************************/
void LCD_Fill(uint16_t xsta,uint16_t ysta,uint16_t xend,uint16_t yend,uint16_t color)
{          
	uint16_t i,j;
	uint16_t xlen=0;
	LCD_SetCursor(xsta,ysta,xend,yend);
	
#if USE_HORIZONTAL==1
	xlen=yend-ysta+1;	   
	for(i=xsta;i<=xend;i++)
	{  
		for(j=0;j<xlen;j++)LCD_WR_DATA(color);//?????? 	  
	}
#else
	xlen=xend-xsta+1;	   
	for(i=ysta;i<=yend;i++)
	{ 
		for(j=0;j<xlen;j++)LCD_WR_DATA(color);//?????? 	    
	}
#endif						  	    
}  


/*******************************************************
功　能：画线
参　数：x1,y1:起点坐标
		x2,y2:终点坐标 
返回值：无
********************************************************/
void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
	uint16_t t; 
	int xerr=0,yerr=0,delta_x,delta_y,distance; 
	int incx,incy,uRow,uCol; 

	delta_x=x2-x1; //计算坐标增量 
	delta_y=y2-y1; 
	uRow=x1; 
	uCol=y1; 
	if(delta_x>0)incx=1; //设置单步方向 
	else if(delta_x==0)incx=0;//垂直线 
	else {incx=-1;delta_x=-delta_x;} 
	if(delta_y>0)incy=1; 
	else if(delta_y==0)incy=0;//水平线 
	else{incy=-1;delta_y=-delta_y;} 
	if( delta_x>delta_y)distance=delta_x; //选取基本增量坐标轴 
	else distance=delta_y; 
	for(t=0;t<=distance+1;t++ )//画线输出 
	{  
		LCD_DrawPoint(uRow,uCol);//画点 
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


/*******************************************************
功　能：画矩形
参　数：x1,y1:起点坐标
		x2,y2:终点坐标 
返回值：无
********************************************************/
void LCD_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)
{
	LCD_DrawLine(x1,y1,x2,y1);
	LCD_DrawLine(x1,y1,x1,y2);
	LCD_DrawLine(x1,y2,x2,y2);
	LCD_DrawLine(x2,y1,x2,y2);
}



/*******************************************************
功　能：在指定位置画一个指定大小的圆
参　数：（x,y):中心点
		r    :半径
返回值：无
********************************************************/
void Draw_Circle(uint16_t x0,uint16_t y0,uint8_t r)
{
	int a,b;
	int di;
	a=0;b=r;	  
	di=3-(r<<1);             //判断下个点位置的标志
	while(a<=b)
	{
		LCD_DrawPoint(x0-b,y0-a);             //3           
		LCD_DrawPoint(x0+b,y0-a);             //0           
		LCD_DrawPoint(x0-a,y0+b);             //1       
		LCD_DrawPoint(x0-b,y0-a);             //7           
		LCD_DrawPoint(x0-a,y0-b);             //2             
		LCD_DrawPoint(x0+b,y0+a);             //4               
		LCD_DrawPoint(x0+a,y0-b);             //5
		LCD_DrawPoint(x0+a,y0+b);             //6 
		LCD_DrawPoint(x0-b,y0+a);             
		a++;
		//使用Bresenham算法画圆     
		if(di<0)di +=4*a+6;	  
		else
		{
			di+=10+4*(a-b);   
			b--;
		} 
		LCD_DrawPoint(x0+a,y0+b);
	}
} 


/*******************************************************
功　能：在指定位置显示一个字符
参　数：x:0~234
		y:0~308
		num:要显示的字符:" "--->"~"
		size:字体大小 12/16
		mode:叠加方式(1)还是非叠加方式(0)
		在指定位置显示一个字符
		x:0~234
		y:0~308
		num:要显示的字符:" "--->"~"
		size:字体大小 12/16
		mode:叠加方式(1)还是非叠加方式(0)
返回值：无
********************************************************/
void LCD_ShowChar(uint16_t x,uint16_t y,uint8_t num,uint8_t size,uint8_t mode)
{  
#if USE_HORIZONTAL==1
//#ifdef USE_HORIZONTAL
#define MAX_CHAR_POSX 312
#define MAX_CHAR_POSY 232 
#else     
#define MAX_CHAR_POSX 232
#define MAX_CHAR_POSY 312
#endif 
    uint8_t temp;
    uint8_t pos,t;
	uint16_t x0=x;
	uint16_t colortemp=POINT_COLOR;      
    if(x>MAX_CHAR_POSX||y>MAX_CHAR_POSY)return;	    
	//设置窗口		   
	num=num-' ';//得到偏移后的值
	if(!mode) //非叠加方式
	{
		for(pos=0;pos<size;pos++)
		{
			if(size==48)temp=asc2_1024[num][pos];//调用1206字体
			else temp=asc2_1608[num][pos];		 //调用1608字体
			for(t=0;t<size/2;t++)
		    {                 
		        if(temp&0x01)POINT_COLOR=colortemp;
				else POINT_COLOR=BACK_COLOR;
				LCD_DrawPoint(x,y);	
				temp>>=1; 
				x++;
		    }
			x=x0;
			y++;
		}	
	}else//叠加方式
	{
		for(pos=0;pos<size;pos++)
		{
			if(size==48)temp=asc2_1024[num][pos];//调用1206字体
			else temp=asc2_1608[num][pos];		 //调用1608字体
			for(t=0;t<size/2;t++)
		    {                 
		        if(temp&0x01)LCD_DrawPoint(x+t,y+pos);//画一个点     
		        temp>>=1; 
		    }
		}
	}
	POINT_COLOR=colortemp;	    	   	 	  
}   



/*******************************************************
功　能：m^n函数
参　数：m:底数
		n:次方
返回值：无
********************************************************/
uint32_t mypow(uint8_t m,uint8_t n)
{
	uint32_t result=1;	 
	while(n--)result*=m;    
	return result;
}			 


/*******************************************************
功　能：显示数字，高位为0,则不显示
参　数：x,y :起点坐标	 
		len :数字的位数
		size:字体大小
		color:颜色
		num:数值(0~4294967295);
返回值：无
********************************************************/
void LCD_ShowNum(uint16_t x,uint16_t y,uint32_t num,uint8_t len,uint8_t size)
{         	
	uint8_t t,temp;
	uint8_t enshow=0;						   
	for(t=0;t<len;t++)
	{
		temp=(num/mypow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				LCD_ShowChar(x+(size/2)*t,y,' ',size,0);
				continue;
			}else enshow=1; 
		 	 
		}
	 	LCD_ShowChar(x+(size/2)*t,y,temp+'0',size,0); 
	}
} 
	

/*******************************************************
功　能：显示数字,高位为0,还是显示
参　数：x,y :起点坐标	 
		len :数字的位数
		size:字体大小
		color:颜色
		num:数值(0~4294967295);
		mode:
			[7]:0,不填充;1,填充0.
			[6:1]:保留
			[0]:0,非叠加显示;1,叠加显示
返回值：无
********************************************************/
void LCD_Show2Num(uint16_t x,uint16_t y,uint16_t num,uint8_t len,uint8_t size,uint8_t mode)
{         	
	uint8_t t,temp;	
	uint8_t enshow=0;	
	for(t=0;t<len;t++)
	{
		temp=(num/mypow(10,len-t-1))%10;
	 	if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				if(mode&0X80)LCD_ShowChar(x+(size/2)*t,y,'0',size,mode&0X01);  
				else LCD_ShowChar(x+(size/2)*t,y,' ',size,mode&0X01);  
 				continue;
			}else enshow=1; 
		 	 
		}
	 	LCD_ShowChar(x+(size/2)*t,y,temp+'0',size,mode&0X01); 
	}
} 


/*******************************************************
功　能：显示字符串
参　数：x,y:起点坐标  	 
		*p:字符串起始地址
返回值：无
备  注：用16字体
********************************************************/
void LCD_ShowString(uint16_t x,uint16_t y,const uint8_t *p)
{         
    while(*p!='\0')
    {       
        if(x>MAX_CHAR_POSX){x=0;y+=16;}
        if(y>MAX_CHAR_POSY){y=x=0;LCD_Clear(WHITE);}
        LCD_ShowChar(x,y,*p,16,0);
        x+=8;
        p++;
    }  
}

/**
 * @brief  对ILI9341显示器的某一点以某种颜色进行填充
 * @param  usX ：在特定扫描方向下该点的X坐标
 * @param  usY ：在特定扫描方向下该点的Y坐标
 * @note 可使用LCD_SetBackColor、LCD_SetTextColor、LCD_SetColors函数设置颜色
 * @retval 无
 */
void ILI9341_DrawPixel ( uint16_t usX, uint16_t usY, uint16_t uColor )
{
    if ( ( usX < LCD_X_LENGTH ) && ( usY < LCD_Y_LENGTH ) )
    {
        LCD_SetCursor ( usX,usY,1,1);
				LCD_Fill( usX ,usY,1,1,uColor);
    }
}

/*******************************************************
功　能：在LCD上处画点
参　数：x，y：画点坐标
		color：点的颜色
返回值：无
********************************************************/
void LCD_Draw_Point(uint16_t x,uint16_t y,uint16_t color)
{
	uint16_t temp;
	temp=POINT_COLOR;
	POINT_COLOR=color;
	LCD_DrawPoint(x,y);
	POINT_COLOR=temp;
}


/*******************************************************
功　能：在指定位置 显示1个16*16的汉字
参　数：x，y：汉字显示的位置
		index:tfont数组里面的第几个汉字
		color:这个汉字的颜色
返回值：无
********************************************************/
void Test_Show_CH_Font16(uint16_t x,uint16_t y,uint8_t index,uint16_t color)
{   			    
	uint8_t temp,t,t1;
	uint16_t y0=y;				   
    for(t=0;t<32;t++)//每个16*16的汉字点阵 有32个字节
    {   
		if(t<16)temp=tfont16[index*2][t];      //前16个字节
		else temp=tfont16[index*2+1][t-16];    //后16个字节	                          
        for(t1=0;t1<8;t1++)
		{
			if(temp&0x80)LCD_Draw_Point(x,y,color);//画实心点
			else LCD_Draw_Point(x,y,BACK_COLOR);   //画空白点（使用背景色）
			temp<<=1;
			y++;
			if((y-y0)==16)
			{
				y=y0;
				x++;
				break;
			}
		}  	 
    }          
}


/*******************************************************
功　能：在指定位置 显示1个24*24的汉字
参　数：x，y：汉字显示的位置
		index:tfont数组里面的第几个汉字
		color:这个汉字的颜色
返回值：无
********************************************************/
void Test_Show_CH_Font24(uint16_t x,uint16_t y,uint8_t index,uint16_t color)
{   			    
	uint8_t temp,t,t1;
	uint16_t y0=y;				   
    for(t=0;t<72;t++)//每个24*24的汉字点阵 有72个字节
    {   
		if(t<24)temp=tfont24[index*3][t];           //前24个字节
		else if(t<48)temp=tfont24[index*3+1][t-24]; //中24个字节	                          
        else temp=tfont24[index*3+2][t-48];         //后24个字节
	    for(t1=0;t1<8;t1++)
		{
			if(temp&0x80)LCD_Draw_Point(x,y,color);//画实心点
			else LCD_Draw_Point(x,y,BACK_COLOR);   //画空白点（使用背景色）
			temp<<=1;
			y++;
			if((y-y0)==48)
			{
				y=y0;
				x++;
				break;
			}
		}  	 
    }          
}


/*******************************************************
功　能：显示汉字
参　数：无
返回值：无
********************************************************/
void TEST_FONT(void)
{
	uint8_t t;
	uint8_t x,x1;
	x=20;
	x1=0;
	for(t=0;6;t++)//11个汉字
	{
		if(t==1)Test_Show_CH_Font24(50,50,10,0);
		else     Test_Show_CH_Font24(x1,50,t,0);
		x+=16;
		x1+=24;
		
	}
}



