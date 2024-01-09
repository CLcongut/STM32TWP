#ifndef      __BSP_ILI9341_LCD_H
#define	     __BSP_ILI9341_LCD_H



/////////////////////////////////////用户配置区///////////////////////////////////	 
//以下2个宏定义，定义屏幕的显示方式及IO速度
#define USE_HORIZONTAL  0	//定义是否使用横屏 		0,不使用.1,使用.
#define LCD_FAST_IO     1 	//定义是否使用快速IO	0,不实用.1,使用
/////////////////////////                                                                                                                                /////////////////////////////////////////////////////////	 
#include "main.h"
#include "gpio.h"
//TFTLCD部分外要调用的函数		   
extern uint16_t  POINT_COLOR;//默认红色    
extern uint16_t  BACK_COLOR; //背景颜色.默认为白色
//定义LCD的尺寸
#if USE_HORIZONTAL==1	//使用横屏
#define LCD_W 320
#define LCD_H 240
#else
#define LCD_W 240
#define LCD_H 320
#endif
#define 			ILI9341_LESS_PIXEL	  							240			//液晶屏较短方向的像素宽度
#define 			ILI9341_MORE_PIXEL	 								320			//液晶屏较长方向的像素宽度

////////////////////////////////////////////////////////////////////
//-----------------LCD端口定义---------------- 

#define	LCD_LED(X) HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2,X)

#ifdef LCD_FAST_IO //快速IO

#define	LCD_CS_SET  HAL_GPIO_WritePin( GPIOB,GPIO_PIN_8,GPIO_PIN_SET)//GPIOB->BSRR=1<<8    //片选端口  	PD8(GND)
#define	LCD_RS_SET	HAL_GPIO_WritePin( GPIOB,GPIO_PIN_1,GPIO_PIN_SET)//GPIOB->BSRR=1<<1    //数据/命令   	PD1
#define	LCD_WR_SET	HAL_GPIO_WritePin( GPIOB,GPIO_PIN_9,GPIO_PIN_SET)//GPIOB->BSRR=1<<9    //写数据		PD9
#define	LCD_RD_SET	HAL_GPIO_WritePin( GPIOB,GPIO_PIN_0,GPIO_PIN_SET)//GPIOB->BSRR=1<<0    //读数据		PD0(VCC)
#define	LCD_RST_SET	HAL_GPIO_WritePin( GPIOB,GPIO_PIN_10,GPIO_PIN_SET)//GPIOB->BSRR=1<<10   //复位			PD10
#define	LCD_RST_BL	HAL_GPIO_WritePin( GPIOB,GPIO_PIN_2,GPIO_PIN_SET)//GPIOB->BSRR=1<<2    //背光			PD2
	
#define	LCD_CS_CLR 	HAL_GPIO_WritePin( GPIOB,GPIO_PIN_8,GPIO_PIN_RESET)//GPIOB->BRR=1<<8     //片选端口
#define	LCD_RS_CLR	HAL_GPIO_WritePin( GPIOB,GPIO_PIN_1,GPIO_PIN_RESET)//GPIOB->BRR=1<<1     //数据/命令
#define	LCD_WR_CLR	HAL_GPIO_WritePin( GPIOB,GPIO_PIN_9,GPIO_PIN_RESET)//GPIOB->BRR=1<<9     //写数据
#define	LCD_RD_CLR	HAL_GPIO_WritePin( GPIOB,GPIO_PIN_0,GPIO_PIN_RESET)//GPIOB->BRR=1<<0     //读数据
#define	LCD_RST_CLR	HAL_GPIO_WritePin( GPIOB,GPIO_PIN_10,GPIO_PIN_RESET)//GPIOB->BRR=1<<10    //复位
		  

#else //慢速IO

#define	LCD_CS(X) GPIO_WriteBit(GPIOB, GPIO_PIN_8, (BitAction)X)    //片选端口
#define	LCD_RS(X) GPIO_WriteBit(GPIOB, GPIO_PIN_1, (BitAction)X)    //数据/命令
#define	LCD_WR(X) GPIO_WriteBit(GPIOB, GPIO_PIN_9, (BitAction)X)	//写数据
#define	LCD_RD(X) GPIO_WriteBit(GPIOB, GPIO_PIN_0, (BitAction)X)	//读数据
#define	LCD_RST(X) GPIO_WriteBit(GPIOB, GPIO_PIN_10, (BitAction)X)	//复位
#endif


//PD4作为移位寄存器时钟线SCK，PD3是数据输入SI,PD11是输出存储时钟
#define DATAOUT(x){\
 Write_u16_data(GPIOB,GPIO_ReadOutputData(GPIOB)&0X07ff);\
if(x>>15)	  	HAL_GPIO_WritePin( GPIOB,GPIO_PIN_3,GPIO_PIN_SET);else HAL_GPIO_WritePin( GPIOB,GPIO_PIN_3,GPIO_PIN_RESET);HAL_GPIO_WritePin( GPIOB,GPIO_PIN_4,GPIO_PIN_SET);HAL_GPIO_WritePin( GPIOB,GPIO_PIN_4,GPIO_PIN_RESET);\
if((x>>14)&1) HAL_GPIO_WritePin( GPIOB,GPIO_PIN_3,GPIO_PIN_SET);else HAL_GPIO_WritePin( GPIOB,GPIO_PIN_3,GPIO_PIN_RESET);HAL_GPIO_WritePin( GPIOB,GPIO_PIN_4,GPIO_PIN_SET);HAL_GPIO_WritePin( GPIOB,GPIO_PIN_4,GPIO_PIN_RESET);\
if((x>>13)&1) HAL_GPIO_WritePin( GPIOB,GPIO_PIN_3,GPIO_PIN_SET);else HAL_GPIO_WritePin( GPIOB,GPIO_PIN_3,GPIO_PIN_RESET);HAL_GPIO_WritePin( GPIOB,GPIO_PIN_4,GPIO_PIN_SET);HAL_GPIO_WritePin( GPIOB,GPIO_PIN_4,GPIO_PIN_RESET);\
if((x>>12)&1) HAL_GPIO_WritePin( GPIOB,GPIO_PIN_3,GPIO_PIN_SET);else HAL_GPIO_WritePin( GPIOB,GPIO_PIN_3,GPIO_PIN_RESET);HAL_GPIO_WritePin( GPIOB,GPIO_PIN_4,GPIO_PIN_SET);HAL_GPIO_WritePin( GPIOB,GPIO_PIN_4,GPIO_PIN_RESET);\
if((x>>11)&1) HAL_GPIO_WritePin( GPIOB,GPIO_PIN_3,GPIO_PIN_SET);else HAL_GPIO_WritePin( GPIOB,GPIO_PIN_3,GPIO_PIN_RESET);HAL_GPIO_WritePin( GPIOB,GPIO_PIN_4,GPIO_PIN_SET);HAL_GPIO_WritePin( GPIOB,GPIO_PIN_4,GPIO_PIN_RESET);\
if((x>>10)&1) HAL_GPIO_WritePin( GPIOB,GPIO_PIN_3,GPIO_PIN_SET);else HAL_GPIO_WritePin( GPIOB,GPIO_PIN_3,GPIO_PIN_RESET);HAL_GPIO_WritePin( GPIOB,GPIO_PIN_4,GPIO_PIN_SET);HAL_GPIO_WritePin( GPIOB,GPIO_PIN_4,GPIO_PIN_RESET);\
if((x>>9)&1)  HAL_GPIO_WritePin( GPIOB,GPIO_PIN_3,GPIO_PIN_SET);else HAL_GPIO_WritePin( GPIOB,GPIO_PIN_3,GPIO_PIN_RESET);HAL_GPIO_WritePin( GPIOB,GPIO_PIN_4,GPIO_PIN_SET);HAL_GPIO_WritePin( GPIOB,GPIO_PIN_4,GPIO_PIN_RESET);\
if((x>>8)&1)  HAL_GPIO_WritePin( GPIOB,GPIO_PIN_3,GPIO_PIN_SET);else HAL_GPIO_WritePin( GPIOB,GPIO_PIN_3,GPIO_PIN_RESET);HAL_GPIO_WritePin( GPIOB,GPIO_PIN_4,GPIO_PIN_SET);HAL_GPIO_WritePin( GPIOB,GPIO_PIN_4,GPIO_PIN_RESET);\
if((x>>7)&1)  HAL_GPIO_WritePin( GPIOB,GPIO_PIN_3,GPIO_PIN_SET);else HAL_GPIO_WritePin( GPIOB,GPIO_PIN_3,GPIO_PIN_RESET);HAL_GPIO_WritePin( GPIOB,GPIO_PIN_4,GPIO_PIN_SET);HAL_GPIO_WritePin( GPIOB,GPIO_PIN_4,GPIO_PIN_RESET);\
if((x>>6)&1)  HAL_GPIO_WritePin( GPIOB,GPIO_PIN_3,GPIO_PIN_SET);else HAL_GPIO_WritePin( GPIOB,GPIO_PIN_3,GPIO_PIN_RESET);HAL_GPIO_WritePin( GPIOB,GPIO_PIN_4,GPIO_PIN_SET);HAL_GPIO_WritePin( GPIOB,GPIO_PIN_4,GPIO_PIN_RESET);\
if((x>>5)&1)  HAL_GPIO_WritePin( GPIOB,GPIO_PIN_3,GPIO_PIN_SET);else HAL_GPIO_WritePin( GPIOB,GPIO_PIN_3,GPIO_PIN_RESET);HAL_GPIO_WritePin( GPIOB,GPIO_PIN_4,GPIO_PIN_SET);HAL_GPIO_WritePin( GPIOB,GPIO_PIN_4,GPIO_PIN_RESET);\
if((x>>4)&1)  HAL_GPIO_WritePin( GPIOB,GPIO_PIN_3,GPIO_PIN_SET);else HAL_GPIO_WritePin( GPIOB,GPIO_PIN_3,GPIO_PIN_RESET);HAL_GPIO_WritePin( GPIOB,GPIO_PIN_4,GPIO_PIN_SET);HAL_GPIO_WritePin( GPIOB,GPIO_PIN_4,GPIO_PIN_RESET);\
if((x>>3)&1)  HAL_GPIO_WritePin( GPIOB,GPIO_PIN_3,GPIO_PIN_SET);else HAL_GPIO_WritePin( GPIOB,GPIO_PIN_3,GPIO_PIN_RESET);HAL_GPIO_WritePin( GPIOB,GPIO_PIN_4,GPIO_PIN_SET);HAL_GPIO_WritePin( GPIOB,GPIO_PIN_4,GPIO_PIN_RESET);\
if((x>>2)&1)  HAL_GPIO_WritePin( GPIOB,GPIO_PIN_3,GPIO_PIN_SET);else HAL_GPIO_WritePin( GPIOB,GPIO_PIN_3,GPIO_PIN_RESET);HAL_GPIO_WritePin( GPIOB,GPIO_PIN_4,GPIO_PIN_SET);HAL_GPIO_WritePin( GPIOB,GPIO_PIN_4,GPIO_PIN_RESET);\
if((x>>1)&1)  HAL_GPIO_WritePin( GPIOB,GPIO_PIN_3,GPIO_PIN_SET);else HAL_GPIO_WritePin( GPIOB,GPIO_PIN_3,GPIO_PIN_RESET);HAL_GPIO_WritePin( GPIOB,GPIO_PIN_4,GPIO_PIN_SET);HAL_GPIO_WritePin( GPIOB,GPIO_PIN_4,GPIO_PIN_RESET);\
if((x>>0)&1)  HAL_GPIO_WritePin( GPIOB,GPIO_PIN_3,GPIO_PIN_SET);else HAL_GPIO_WritePin( GPIOB,GPIO_PIN_3,GPIO_PIN_RESET);HAL_GPIO_WritePin( GPIOB,GPIO_PIN_4,GPIO_PIN_SET);HAL_GPIO_WritePin( GPIOB,GPIO_PIN_4,GPIO_PIN_RESET);\
HAL_GPIO_WritePin( GPIOB,GPIO_PIN_11,GPIO_PIN_SET);\
}

//////////////////////////////////////////////////////////////////////
//画笔颜色
#define WHITE         	 0xFFFF
#define BLACK         	 0x0000	  
#define BLUE         	 0x001F  
#define BRED             0XF81F
#define GRED 			 0XFFE0
#define GBLUE			 0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			 0XBC40 //棕色
#define BRRED 			 0XFC07 //棕红色
#define GRAY  			 0X8430 //灰色
//GUI颜色

#define DARKBLUE      	 0X01CF	//深蓝色
#define LIGHTBLUE      	 0X7D7C	//浅蓝色  
#define GRAYBLUE       	 0X5458 //灰蓝色
//以上三色为PANEL的颜色 
 
#define LIGHTGREEN     	 0X841F //浅绿色
//#define LIGHTGRAY      0XEF5B //浅灰色(PANNEL)
#define LGRAY 			 0XC618 //浅灰色(PANNEL),窗体背景色

#define LGRAYBLUE        0XA651 //浅灰蓝色(中间层颜色)
#define LBBLUE           0X2B12 //浅棕蓝色(选择条目的反色)
	    															  
extern uint16_t BACK_COLOR, POINT_COLOR ;  
uint16_t GPIO_ReadOutputData(GPIO_TypeDef* GPIOx);
void Write_u16_data(GPIO_TypeDef* GPIOx,uint16_t data);
void LCD_Init(void);
void LCD_DisplayOn(void);
void LCD_DisplayOff(void);
void LCD_Clear(uint16_t Color);	 
void LCD_DrawPoint(uint16_t x,uint16_t y);	//画点
uint16_t  LCD_ReadPoint(uint16_t x,uint16_t y); 	//读点
void Draw_Circle(uint16_t x0,uint16_t y0,uint8_t r);
void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
void LCD_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);		   
void LCD_Fill(uint16_t xsta,uint16_t ysta,uint16_t xend,uint16_t yend,uint16_t color);
void LCD_ShowChar(uint16_t x,uint16_t y,uint8_t num,uint8_t size,uint8_t mode);	//显示一个字符
void LCD_ShowNum(uint16_t x,uint16_t y,uint32_t num,uint8_t len,uint8_t size);  	//显示一个数字
void LCD_Show2Num(uint16_t x,uint16_t y,uint16_t num,uint8_t len,uint8_t size,uint8_t mode);//显示2个数字
void LCD_ShowString(uint16_t x,uint16_t y,const uint8_t *p);		 	//显示一个字符串,16字体
void LCD_SetCursor(uint16_t xsta, uint16_t ysta,uint16_t xend,uint16_t yend);
void ILI9341_DrawPixel ( uint16_t usX, uint16_t usY, uint16_t uColor );
void LCD_WriteReg(uint8_t LCD_Reg, uint16_t LCD_RegValue);
uint16_t LCD_ReadReg(uint8_t LCD_Reg);
void LCD_WriteRAM_Prepare(void);
void LCD_WriteRAM(uint16_t RGB_Code);
void TEST_FONT(void);
void Test_Show_CH_Font16(uint16_t x,uint16_t y,uint8_t index,uint16_t color);
void Test_Show_CH_Font24(uint16_t x,uint16_t y,uint8_t index,uint16_t color);		
uint16_t LCD_ReadRAM(void);		   
uint16_t LCD_BGR2RGB(uint16_t c);


//写8位数据函数
//用宏定义,提高速度.
#if LCD_FAST_IO==1 //快速IO
#define LCD_WR_DATA(data){\
LCD_RS_SET;\
LCD_CS_CLR;\
DATAOUT(data);\
LCD_WR_CLR;\
LCD_WR_SET;\
LCD_CS_SET;\
} 
#else//正常IO
#define LCD_WR_DATA(data){\
LCD_RS=1;\
LCD_CS=0;\
DATAOUT(data);\
LCD_WR=0;\
LCD_WR=1;\
LCD_CS=1;\
} 	
#endif	

#define LCD_WR_TDATA(data){\
LCD_RS=1;\
LCD_CS=0;\
DATAOUT(data & 0xFF00);\
LCD_WR=0;\
LCD_WR=1;\
DATAOUT(data << 8);\
LCD_WR=0;\
LCD_WR=1;\
LCD_CS=1;\
}																			 
							  		 

	 






#endif /* __BSP_ILI9341_ILI9341_H */


