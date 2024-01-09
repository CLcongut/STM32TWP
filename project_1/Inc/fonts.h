#ifndef __FONTS_H
#define __FONTS_H 	

#include "main.h"
//常用ASCII表
//偏移量32
//ASCII字符集
//偏移量32
//大小:12*6
const unsigned char asc2_1024[95][48]={
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*" ",0*/
{0x00,0x00,0x04,0x04,0x04,0x04,0x04,0x04,0x00,0x04,0x00,0x00},/*"!",1*/
{0x00,0x14,0x0A,0x0A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*""",2*/
{0x00,0x00,0x14,0x14,0x3F,0x14,0x0A,0x3F,0x0A,0x0A,0x00,0x00},/*"#",3*/
{0x00,0x04,0x1E,0x15,0x05,0x06,0x0C,0x14,0x15,0x0F,0x04,0x00},/*"$",4*/
{0x00,0x00,0x12,0x15,0x0D,0x0A,0x14,0x2C,0x2A,0x12,0x00,0x00},/*"%",5*/
{0x00,0x00,0x04,0x0A,0x0A,0x1E,0x15,0x15,0x09,0x36,0x00,0x00},/*"&",6*/
{0x00,0x02,0x02,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"'",7*/
{0x00,0x20,0x10,0x08,0x08,0x08,0x08,0x08,0x08,0x10,0x20,0x00},/*"(",8*/
{0x00,0x02,0x04,0x08,0x08,0x08,0x08,0x08,0x08,0x04,0x02,0x00},/*")",9*/
{0x00,0x00,0x00,0x04,0x15,0x0E,0x0E,0x15,0x04,0x00,0x00,0x00},/*"*",10*/
{0x00,0x00,0x04,0x04,0x04,0x1F,0x04,0x04,0x04,0x00,0x00,0x00},/*"+",11*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x02,0x01},/*",",12*/
{0x00,0x00,0x00,0x00,0x00,0x1F,0x00,0x00,0x00,0x00,0x00,0x00},/*"-",13*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00},/*".",14*/
{0x00,0x10,0x08,0x08,0x08,0x04,0x04,0x02,0x02,0x02,0x01,0x00},/*"/",15*/

{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x7C,0x00,0xCC,0x00,0x86,0x00,
0x86,0x01,0x86,0x01,0x82,0x01,0x82,0x01,0x82,0x01,0x82,0x01,0x82,0x01,0x82,0x01,
0x86,0x01,0x86,0x00,0xCC,0x00,0x78,0x00,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"0",0*/
/* (10 X 24 , 楷体 )*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x30,0x00,0x38,0x00,0x3C,0x00,
0x34,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,
0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"1",1*/
/* (10 X 24 , 楷体 )*/

{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x00,0xFC,0x00,0xCE,0x00,0x86,0x01,
0x82,0x01,0x80,0x01,0x80,0x00,0xC0,0x00,0x40,0x00,0x60,0x00,0x30,0x00,0x10,0x00,
0x18,0x00,0x0C,0x00,0x06,0x00,0xFE,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"2",2*/
/* (10 X 24 , 楷体 )*/

{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0xFC,0x00,0xC4,0x00,0x86,0x01,
0x82,0x01,0x80,0x00,0xC0,0x00,0x70,0x00,0x70,0x00,0xC0,0x00,0x80,0x01,0x80,0x01,
0x82,0x01,0x86,0x01,0xCE,0x00,0xFC,0x00,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"3",3*/
/* (10 X 24 , 楷体 )*/

{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0xC0,0x00,0xE0,0x00,0xE0,0x00,
0xF0,0x00,0xD0,0x00,0xD8,0x00,0xCC,0x00,0xCC,0x00,0xC6,0x00,0xC2,0x00,0xFF,0x03,
0xFF,0x03,0xC0,0x00,0xC0,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"4",4*/
/* (10 X 24 , 楷体 )*/

{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0x00,0x04,0x00,0x04,0x00,
0x06,0x00,0x06,0x00,0x7E,0x00,0xEE,0x00,0x82,0x00,0x80,0x01,0x80,0x01,0x80,0x01,
0x83,0x01,0x82,0x01,0xC6,0x00,0x7C,0x00,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"5",5*/
/* (10 X 24 , 楷体 )*/

{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x60,0x00,0x30,0x00,0x30,0x00,
0x18,0x00,0x18,0x00,0x7C,0x00,0xFC,0x00,0x86,0x01,0x06,0x01,0x02,0x01,0x02,0x01,
0x06,0x01,0x86,0x01,0x8E,0x01,0xFC,0x00,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"6",6*/
/* (10 X 24 , 楷体 )*/

{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x01,0x80,0x01,0x80,0x01,
0x80,0x00,0xC0,0x00,0x40,0x00,0x60,0x00,0x20,0x00,0x20,0x00,0x30,0x00,0x10,0x00,
0x10,0x00,0x18,0x00,0x18,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"7",7*/
/* (10 X 24 , 楷体 )*/

{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x00,0xFC,0x00,0xC6,0x00,0x86,0x01,
0x82,0x01,0x86,0x00,0xC6,0x00,0x7C,0x00,0xFC,0x00,0xC6,0x00,0x82,0x01,0x82,0x01,
0x82,0x01,0x82,0x01,0xC6,0x00,0xFC,0x00,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"8",8*/
/* (10 X 24 , 楷体 )*/

{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x00,0xFC,0x00,0xC6,0x00,0x86,0x01,
0x83,0x01,0x83,0x01,0x83,0x01,0x82,0x00,0xC6,0x00,0xFC,0x00,0x70,0x00,0x60,0x00,
0x30,0x00,0x30,0x00,0x10,0x00,0x18,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"9",9*/
/* (10 X 24 , 楷体 )*/

{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x38,0x00,0x10,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x10,0x00,0x38,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*":",10*/
/* (10 X 24 , 楷体 )*/


{0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x04,0x04,0x00},/*";",27*/
{0x00,0x20,0x10,0x08,0x04,0x02,0x04,0x08,0x10,0x20,0x00,0x00},/*"<",28*/
{0x00,0x00,0x00,0x00,0x1F,0x00,0x00,0x1F,0x00,0x00,0x00,0x00},/*"=",29*/
{0x00,0x02,0x04,0x08,0x10,0x20,0x10,0x08,0x04,0x02,0x00,0x00},/*">",30*/
{0x00,0x00,0x0E,0x11,0x11,0x08,0x04,0x04,0x00,0x04,0x00,0x00},/*"?",31*/
{0x00,0x00,0x0E,0x11,0x19,0x15,0x15,0x1D,0x01,0x1E,0x00,0x00},/*"@",32*/
{0x00,0x00,0x04,0x04,0x0C,0x0A,0x0A,0x1E,0x12,0x33,0x00,0x00},/*"A",33*/
{0x00,0x00,0x0F,0x12,0x12,0x0E,0x12,0x12,0x12,0x0F,0x00,0x00},/*"B",34*/
{0x00,0x00,0x1E,0x11,0x01,0x01,0x01,0x01,0x11,0x0E,0x00,0x00},/*"C",35*/
{0x00,0x00,0x0F,0x12,0x12,0x12,0x12,0x12,0x12,0x0F,0x00,0x00},/*"D",36*/

{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x01,0xFE,0x01,0x06,0x00,0x06,0x00,
0x06,0x00,0x06,0x00,0x06,0x00,0xFE,0x00,0xFE,0x00,0x06,0x00,0x06,0x00,0x06,0x00,
0x06,0x00,0x06,0x00,0x06,0x00,0xFE,0x01,0xFE,0x01,0x00,0x00,0x00,0x00,0x00,0x00},/*"E",0*/
/* (10 X 24 , 楷体 )*/



{0x00,0x00,0x1F,0x12,0x0A,0x0E,0x0A,0x02,0x02,0x07,0x00,0x00},/*"F",38*/
{0x00,0x00,0x1C,0x12,0x01,0x01,0x39,0x11,0x12,0x0C,0x00,0x00},/*"G",39*/
{0x00,0x00,0x33,0x12,0x12,0x1E,0x12,0x12,0x12,0x33,0x00,0x00},/*"H",40*/

{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,
0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,
0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"I",0*/
/* (10 X 24 , 楷体 )*/
{0x00,0x00,0x3E,0x08,0x08,0x08,0x08,0x08,0x08,0x09,0x07,0x00},/*"J",42*/
{0x00,0x00,0x37,0x12,0x0A,0x06,0x0A,0x0A,0x12,0x37,0x00,0x00},/*"K",43*/
{0x00,0x00,0x07,0x02,0x02,0x02,0x02,0x02,0x22,0x3F,0x00,0x00},/*"L",44*/

{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x86,0x01,0x86,0x01,0xC6,0x01,0xCE,0x01,
0xCE,0x01,0x4E,0x01,0x4A,0x01,0x4A,0x01,0x6A,0x01,0x7A,0x01,0x7A,0x01,0x3A,0x01,
0x32,0x01,0x32,0x01,0x32,0x01,0x32,0x01,0x32,0x01,0x00,0x00,0x00,0x00,0x00,0x00},/*"M",0*/
{0x00,0x00,0x3B,0x12,0x16,0x16,0x1A,0x1A,0x12,0x17,0x00,0x00},/*"N",46*/
{0x00,0x00,0x0E,0x11,0x11,0x11,0x11,0x11,0x11,0x0E,0x00,0x00},/*"O",47*/
{0x00,0x00,0x0F,0x12,0x12,0x0E,0x02,0x02,0x02,0x07,0x00,0x00},/*"P",48*/
{0x00,0x00,0x0E,0x11,0x11,0x11,0x11,0x17,0x19,0x0E,0x18,0x00},/*"Q",49*/
{0x00,0x00,0x0F,0x12,0x12,0x0E,0x0A,0x12,0x12,0x37,0x00,0x00},/*"R",50*/
{0x00,0x00,0x1E,0x11,0x01,0x06,0x08,0x10,0x11,0x0F,0x00,0x00},/*"S",51*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x01,0xFE,0x01,0x30,0x00,0x30,0x00,
0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,
0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"T",0*/
/* (10 X 24 , 楷体 )*/
{0x00,0x00,0x33,0x12,0x12,0x12,0x12,0x12,0x12,0x0C,0x00,0x00},/*"U",53*/
{0x00,0x00,0x33,0x12,0x12,0x0A,0x0A,0x0C,0x04,0x04,0x00,0x00},/*"V",54*/
{0x00,0x00,0x15,0x15,0x15,0x0E,0x0A,0x0A,0x0A,0x0A,0x00,0x00},/*"W",55*/
{0x00,0x00,0x1B,0x0A,0x0A,0x04,0x04,0x0A,0x0A,0x1B,0x00,0x00},/*"X",56*/
{0x00,0x00,0x1B,0x0A,0x0A,0x04,0x04,0x04,0x04,0x0E,0x00,0x00},/*"Y",57*/
{0x00,0x00,0x1F,0x09,0x08,0x04,0x04,0x02,0x12,0x1F,0x00,0x00},/*"Z",58*/
{0x00,0x1C,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x1C,0x00},/*"[",59*/
{0x00,0x02,0x02,0x02,0x04,0x04,0x08,0x08,0x08,0x10,0x00,0x00},/*"\",60*/
{0x00,0x0E,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x0E,0x00},/*"]",61*/
{0x00,0x04,0x0A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"^",62*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F},/*"_",63*/
{0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"`",64*/
{0x00,0x00,0x00,0x00,0x00,0x0C,0x12,0x1C,0x12,0x3C,0x00,0x00},/*"a",65*/
{0x00,0x00,0x03,0x02,0x02,0x0E,0x12,0x12,0x12,0x0E,0x00,0x00},/*"b",66*/
{0x00,0x00,0x00,0x00,0x00,0x1C,0x12,0x02,0x02,0x1C,0x00,0x00},/*"c",67*/
{0x00,0x00,0x18,0x10,0x10,0x1C,0x12,0x12,0x12,0x3C,0x00,0x00},/*"d",68*/
{0x00,0x00,0x00,0x00,0x00,0x0C,0x12,0x1E,0x02,0x1C,0x00,0x00},/*"e",69*/
{0x00,0x00,0x38,0x04,0x04,0x1E,0x04,0x04,0x04,0x1E,0x00,0x00},/*"f",70*/
{0x00,0x00,0x00,0x00,0x00,0x3C,0x12,0x0C,0x02,0x1E,0x22,0x1C},/*"g",71*/
{0x00,0x00,0x03,0x02,0x02,0x0E,0x12,0x12,0x12,0x37,0x00,0x00},/*"h",72*/
{0x00,0x00,0x04,0x00,0x00,0x06,0x04,0x04,0x04,0x0E,0x00,0x00},/*"i",73*/
{0x00,0x00,0x08,0x00,0x00,0x0C,0x08,0x08,0x08,0x08,0x08,0x07},/*"j",74*/
{0x00,0x00,0x03,0x02,0x02,0x3A,0x0A,0x0E,0x12,0x37,0x00,0x00},/*"k",75*/
{0x00,0x00,0x07,0x04,0x04,0x04,0x04,0x04,0x04,0x1F,0x00,0x00},/*"l",76*/
{0x00,0x00,0x00,0x00,0x00,0x0F,0x15,0x15,0x15,0x15,0x00,0x00},/*"m",77*/
{0x00,0x00,0x00,0x00,0x00,0x0F,0x12,0x12,0x12,0x37,0x00,0x00},/*"n",78*/
{0x00,0x00,0x00,0x00,0x00,0x0C,0x12,0x12,0x12,0x0C,0x00,0x00},/*"o",79*/
{0x00,0x00,0x00,0x00,0x00,0x0F,0x12,0x12,0x12,0x0E,0x02,0x07},/*"p",80*/
{0x00,0x00,0x00,0x00,0x00,0x1C,0x12,0x12,0x12,0x1C,0x10,0x38},/*"q",81*/
{0x00,0x00,0x00,0x00,0x00,0x1B,0x06,0x02,0x02,0x07,0x00,0x00},/*"r",82*/
{0x00,0x00,0x00,0x00,0x00,0x1E,0x02,0x0C,0x10,0x1E,0x00,0x00},/*"s",83*/
{0x00,0x00,0x00,0x04,0x04,0x0E,0x04,0x04,0x04,0x18,0x00,0x00},/*"t",84*/
{0x00,0x00,0x00,0x00,0x00,0x1B,0x12,0x12,0x12,0x3C,0x00,0x00},/*"u",85*/
{0x00,0x00,0x00,0x00,0x00,0x37,0x12,0x0A,0x0C,0x04,0x00,0x00},/*"v",86*/
{0x00,0x00,0x00,0x00,0x00,0x15,0x15,0x0E,0x0A,0x0A,0x00,0x00},/*"w",87*/
{0x00,0x00,0x00,0x00,0x00,0x1B,0x0A,0x04,0x0A,0x1B,0x00,0x00},/*"x",88*/
{0x00,0x00,0x00,0x00,0x00,0x37,0x12,0x0A,0x0C,0x04,0x04,0x03},/*"y",89*/
{0x00,0x00,0x00,0x00,0x00,0x1E,0x08,0x04,0x04,0x1E,0x00,0x00},/*"z",90*/
{0x00,0x18,0x08,0x08,0x08,0x04,0x08,0x08,0x08,0x08,0x18,0x00},/*"{",91*/
{0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08},/*"|",92*/
{0x00,0x06,0x04,0x04,0x04,0x08,0x04,0x04,0x04,0x04,0x06,0x00},/*"}",93*/
{0x02,0x25,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00} /*"~",94*/
}; 
const unsigned char asc2_1608[95][18]={
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*" ",0*/
{0x00,0x00,0x00,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x00,0x00,0x18,0x18,0x00,0x00},/*"!",1*/
{0x00,0x48,0x6C,0x24,0x12,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*""",2*/
{0x00,0x00,0x00,0x24,0x24,0x24,0x7F,0x12,0x12,0x12,0x7F,0x12,0x12,0x12,0x00,0x00},/*"#",3*/
{0x00,0x00,0x08,0x1C,0x2A,0x2A,0x0A,0x0C,0x18,0x28,0x28,0x2A,0x2A,0x1C,0x08,0x08},/*"$",4*/
{0x00,0x00,0x00,0x22,0x25,0x15,0x15,0x15,0x2A,0x58,0x54,0x54,0x54,0x22,0x00,0x00},/*"%",5*/
{0x00,0x00,0x00,0x0C,0x12,0x12,0x12,0x0A,0x76,0x25,0x29,0x11,0x91,0x6E,0x00,0x00},/*"&",6*/
{0x00,0x06,0x06,0x04,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"'",7*/
{0x00,0x40,0x20,0x10,0x10,0x08,0x08,0x08,0x08,0x08,0x08,0x10,0x10,0x20,0x40,0x00},/*"(",8*/
{0x00,0x02,0x04,0x08,0x08,0x10,0x10,0x10,0x10,0x10,0x10,0x08,0x08,0x04,0x02,0x00},/*")",9*/
{0x00,0x00,0x00,0x00,0x08,0x08,0x6B,0x1C,0x1C,0x6B,0x08,0x08,0x00,0x00,0x00,0x00},/*"*",10*/
{0x00,0x00,0x00,0x00,0x08,0x08,0x08,0x08,0x7F,0x08,0x08,0x08,0x08,0x00,0x00,0x00},/*"+",11*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x06,0x04,0x03},/*",",12*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"-",13*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x06,0x00,0x00},/*".",14*/
{0x00,0x00,0x80,0x40,0x40,0x20,0x20,0x10,0x10,0x08,0x08,0x04,0x04,0x02,0x02,0x00},/*"/",15*/
{0x00,0x00,0x00,0x18,0x24,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x24,0x18,0x00,0x00},/*"0",16*/
{0x00,0x00,0x00,0x08,0x0E,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x3E,0x00,0x00},/*"1",17*/
{0x00,0x00,0x00,0x3C,0x42,0x42,0x42,0x20,0x20,0x10,0x08,0x04,0x42,0x7E,0x00,0x00},/*"2",18*/
{0x00,0x00,0x00,0x3C,0x42,0x42,0x20,0x18,0x20,0x40,0x40,0x42,0x22,0x1C,0x00,0x00},/*"3",19*/
{0x00,0x00,0x00,0x20,0x30,0x28,0x24,0x24,0x22,0x22,0x7E,0x20,0x20,0x78,0x00,0x00},/*"4",20*/
{0x00,0x00,0x00,0x7E,0x02,0x02,0x02,0x1A,0x26,0x40,0x40,0x42,0x22,0x1C,0x00,0x00},/*"5",21*/
{0x00,0x00,0x00,0x38,0x24,0x02,0x02,0x1A,0x26,0x42,0x42,0x42,0x24,0x18,0x00,0x00},/*"6",22*/
{0x00,0x00,0x00,0x7E,0x22,0x22,0x10,0x10,0x08,0x08,0x08,0x08,0x08,0x08,0x00,0x00},/*"7",23*/	 
{0x00,0x00,0x00,0x3C,0x42,0x42,0x42,0x24,0x18,0x24,0x42,0x42,0x42,0x3C,0x00,0x00},/*"8",24*/
{0x00,0x00,0x00,0x18,0x24,0x42,0x42,0x42,0x64,0x58,0x40,0x40,0x24,0x1C,0x00,0x00},/*"9",25*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00},/*":",26*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x08,0x08,0x04},/*";",27*/
{0x00,0x00,0x00,0x40,0x20,0x10,0x08,0x04,0x02,0x04,0x08,0x10,0x20,0x40,0x00,0x00},/*"<",28*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x00,0x00,0x00,0x7F,0x00,0x00,0x00,0x00,0x00},/*"=",29*/
{0x00,0x00,0x00,0x02,0x04,0x08,0x10,0x20,0x40,0x20,0x10,0x08,0x04,0x02,0x00,0x00},/*">",30*/
{0x00,0x00,0x00,0x3C,0x42,0x42,0x46,0x40,0x20,0x10,0x10,0x00,0x18,0x18,0x00,0x00},/*"?",31*/
{0x00,0x00,0x00,0x1C,0x22,0x5A,0x55,0x55,0x55,0x55,0x2D,0x42,0x22,0x1C,0x00,0x00},/*"@",32*/
{0x00,0x00,0x00,0x08,0x08,0x18,0x14,0x14,0x24,0x3C,0x22,0x42,0x42,0xE7,0x00,0x00},/*"A",33*/
{0x00,0x00,0x00,0x1F,0x22,0x22,0x22,0x1E,0x22,0x42,0x42,0x42,0x22,0x1F,0x00,0x00},/*"B",34*/
{0x00,0x00,0x00,0x7C,0x42,0x42,0x01,0x01,0x01,0x01,0x01,0x42,0x22,0x1C,0x00,0x00},/*"C",35*/
{0x00,0x00,0x00,0x1F,0x22,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x22,0x1F,0x00,0x00},/*"D",36*/
{0x00,0x00,0x00,0x3F,0x42,0x12,0x12,0x1E,0x12,0x12,0x02,0x42,0x42,0x3F,0x00,0x00},/*"E",37*/
{0x00,0x00,0x00,0x3F,0x42,0x12,0x12,0x1E,0x12,0x12,0x02,0x02,0x02,0x07,0x00,0x00},/*"F",38*/
{0x00,0x00,0x00,0x3C,0x22,0x22,0x01,0x01,0x01,0x71,0x21,0x22,0x22,0x1C,0x00,0x00},/*"G",39*/
{0x00,0x00,0x00,0xE7,0x42,0x42,0x42,0x42,0x7E,0x42,0x42,0x42,0x42,0xE7,0x00,0x00},/*"H",40*/
{0x00,0x00,0x00,0x3E,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x3E,0x00,0x00},/*"I",41*/
{0x00,0x00,0x00,0x7C,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x11,0x0F},/*"J",42*/
{0x00,0x00,0x00,0x77,0x22,0x12,0x0A,0x0E,0x0A,0x12,0x12,0x22,0x22,0x77,0x00,0x00},/*"K",43*/
{0x00,0x00,0x00,0x07,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x42,0x7F,0x00,0x00},/*"L",44*/
{0x00,0x00,0x00,0x77,0x36,0x36,0x36,0x36,0x2A,0x2A,0x2A,0x2A,0x2A,0x6B,0x00,0x00},/*"M",45*/
{0x00,0x00,0x00,0xE3,0x46,0x46,0x4A,0x4A,0x52,0x52,0x52,0x62,0x62,0x47,0x00,0x00},/*"N",46*/
{0x00,0x00,0x00,0x1C,0x22,0x41,0x41,0x41,0x41,0x41,0x41,0x41,0x22,0x1C,0x00,0x00},/*"O",47*/
{0x00,0x00,0x00,0x3F,0x42,0x42,0x42,0x42,0x3E,0x02,0x02,0x02,0x02,0x07,0x00,0x00},/*"P",48*/
{0x00,0x00,0x00,0x1C,0x22,0x41,0x41,0x41,0x41,0x41,0x4D,0x53,0x32,0x1C,0x60,0x00},/*"Q",49*/
{0x00,0x00,0x00,0x3F,0x42,0x42,0x42,0x3E,0x12,0x12,0x22,0x22,0x42,0xC7,0x00,0x00},/*"R",50*/
{0x00,0x00,0x00,0x7C,0x42,0x42,0x02,0x04,0x18,0x20,0x40,0x42,0x42,0x3E,0x00,0x00},/*"S",51*/
{0x00,0x00,0x00,0x7F,0x49,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x1C,0x00,0x00},/*"T",52*/
{0x00,0x00,0x00,0xE7,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x3C,0x00,0x00},/*"U",53*/
{0x00,0x00,0x00,0xE7,0x42,0x42,0x22,0x24,0x24,0x14,0x14,0x18,0x08,0x08,0x00,0x00},/*"V",54*/
{0x00,0x00,0x00,0x6B,0x49,0x49,0x49,0x49,0x55,0x55,0x36,0x22,0x22,0x22,0x00,0x00},/*"W",55*/
{0x00,0x00,0x00,0xE7,0x42,0x24,0x24,0x18,0x18,0x18,0x24,0x24,0x42,0xE7,0x00,0x00},/*"X",56*/
{0x00,0x00,0x00,0x77,0x22,0x22,0x14,0x14,0x08,0x08,0x08,0x08,0x08,0x1C,0x00,0x00},/*"Y",57*/
{0x00,0x00,0x00,0x7E,0x21,0x20,0x10,0x10,0x08,0x04,0x04,0x42,0x42,0x3F,0x00,0x00},/*"Z",58*/
{0x00,0x78,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x78,0x00},/*"[",59*/
{0x00,0x00,0x02,0x02,0x04,0x04,0x08,0x08,0x08,0x10,0x10,0x20,0x20,0x20,0x40,0x40},/*"\",60*/
{0x00,0x1E,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x1E,0x00},/*"]",61*/
{0x00,0x38,0x44,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"^",62*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF},/*"_",63*/
{0x00,0x06,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"`",64*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x42,0x78,0x44,0x42,0x42,0xFC,0x00,0x00},/*"a",65*/
{0x00,0x00,0x00,0x03,0x02,0x02,0x02,0x1A,0x26,0x42,0x42,0x42,0x26,0x1A,0x00,0x00},/*"b",66*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x44,0x02,0x02,0x02,0x44,0x38,0x00,0x00},/*"c",67*/
{0x00,0x00,0x00,0x60,0x40,0x40,0x40,0x78,0x44,0x42,0x42,0x42,0x64,0xD8,0x00,0x00},/*"d",68*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x42,0x7E,0x02,0x02,0x42,0x3C,0x00,0x00},/*"e",69*/
{0x00,0x00,0x00,0xF0,0x88,0x08,0x08,0x7E,0x08,0x08,0x08,0x08,0x08,0x3E,0x00,0x00},/*"f",70*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x22,0x22,0x1C,0x02,0x3C,0x42,0x42,0x3C},/*"g",71*/
{0x00,0x00,0x00,0x03,0x02,0x02,0x02,0x3A,0x46,0x42,0x42,0x42,0x42,0xE7,0x00,0x00},/*"h",72*/
{0x00,0x00,0x00,0x0C,0x0C,0x00,0x00,0x0E,0x08,0x08,0x08,0x08,0x08,0x3E,0x00,0x00},/*"i",73*/
{0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x38,0x20,0x20,0x20,0x20,0x20,0x20,0x22,0x1E},/*"j",74*/
{0x00,0x00,0x00,0x03,0x02,0x02,0x02,0x72,0x12,0x0A,0x16,0x12,0x22,0x77,0x00,0x00},/*"k",75*/
{0x00,0x00,0x00,0x0E,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x3E,0x00,0x00},/*"l",76*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0x92,0x92,0x92,0x92,0x92,0xB7,0x00,0x00},/*"m",77*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3B,0x46,0x42,0x42,0x42,0x42,0xE7,0x00,0x00},/*"n",78*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x42,0x42,0x42,0x42,0x42,0x3C,0x00,0x00},/*"o",79*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1B,0x26,0x42,0x42,0x42,0x22,0x1E,0x02,0x07},/*"p",80*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x44,0x42,0x42,0x42,0x44,0x78,0x40,0xE0},/*"q",81*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x77,0x4C,0x04,0x04,0x04,0x04,0x1F,0x00,0x00},/*"r",82*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7C,0x42,0x02,0x3C,0x40,0x42,0x3E,0x00,0x00},/*"s",83*/
{0x00,0x00,0x00,0x00,0x00,0x08,0x08,0x3E,0x08,0x08,0x08,0x08,0x08,0x30,0x00,0x00},/*"t",84*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x63,0x42,0x42,0x42,0x42,0x62,0xDC,0x00,0x00},/*"u",85*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE7,0x42,0x24,0x24,0x14,0x08,0x08,0x00,0x00},/*"v",86*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xEB,0x49,0x49,0x55,0x55,0x22,0x22,0x00,0x00},/*"w",87*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x76,0x24,0x18,0x18,0x18,0x24,0x6E,0x00,0x00},/*"x",88*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE7,0x42,0x24,0x24,0x14,0x18,0x08,0x08,0x07},/*"y",89*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0x22,0x10,0x08,0x08,0x44,0x7E,0x00,0x00},/*"z",90*/
{0x00,0xC0,0x20,0x20,0x20,0x20,0x20,0x10,0x20,0x20,0x20,0x20,0x20,0x20,0xC0,0x00},/*"{",91*/
{0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10},/*"|",92*/
{0x00,0x06,0x08,0x08,0x08,0x08,0x08,0x10,0x08,0x08,0x08,0x08,0x08,0x08,0x06,0x00},/*"}",93*/
{0x0C,0x32,0xC2,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"~",94*/
};  

//阴码 逐列式 顺向 16*16
const uint8_t tfont16[][16]=
{
{0x00,0x00,0x00,0x00,0x00,0x10,0x09,0x10,0x0F,0xE0,0x00,0x20,0x00,0x24,0x1F,0xC8},
{0x10,0x30,0x17,0xF8,0x10,0x24,0x1F,0xC4,0x10,0x04,0x00,0x04,0x00,0x0C,0x00,0x00},/*"现",0*/
/* (16 X 16 , 楷体 ) */

{0x00,0x00,0x00,0x08,0x00,0x10,0x00,0x20,0x04,0xFE,0x05,0x04,0x06,0x04,0x78,0x44},
{0x08,0x48,0x0B,0xF8,0x08,0x48,0x00,0x88,0x00,0x88,0x00,0x08,0x00,0x08,0x00,0x00},/*"在",1*/
/* (16 X 16 , 楷体 ) */

{0x00,0x00,0x00,0x00,0x0F,0xF8,0x08,0x90,0x08,0x90,0x0F,0xF8,0x02,0x00,0x02,0x80},
{0x02,0x40,0x02,0x04,0x3F,0xC6,0x22,0x38,0x02,0x00,0x02,0x00,0x00,0x00,0x00,0x00},/*"时",2*/
/* (16 X 16 , 楷体 ) */

{0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xF8,0x20,0x00,0x30,0x00,0x03,0xE0,0x12,0xA0},
{0x14,0xA0,0x17,0xF0,0x10,0x00,0x20,0x04,0x3F,0xFE,0x00,0x00,0x00,0x00,0x00,0x00},/*"间",3*/
/* (16 X 16 , 楷体 ) */



{0x02,0x00,0x42,0x02,0x42,0x04,0x42,0x08,0x42,0x30,0x7F,0xC0,0x42,0x00,0x42,0x00},
{0x42,0x00,0x42,0x00,0x7F,0xFE,0x42,0x00,0x42,0x00,0x42,0x00,0x42,0x00,0x00,0x00},/*"开",0*/

{0x00,0x02,0x08,0x04,0x7C,0x08,0x08,0x11,0x08,0xE1,0x0F,0x82,0xF9,0x62,0x09,0x14},
{0x09,0x08,0x49,0x14,0x29,0xE4,0x38,0x02,0x08,0x03,0x08,0x02,0x08,0x00,0x00,0x00},/*"发",1*/

{0x08,0x20,0x08,0xC0,0x0B,0x00,0xFF,0xFE,0x0A,0x00,0x09,0x88,0x00,0x70,0x7F,0x82},
{0x46,0x04,0x45,0x88,0x44,0x50,0x84,0x70,0x85,0x8C,0x86,0x06,0x00,0x04,0x00,0x00},/*"板",2*/

{0x08,0x20,0x06,0x20,0x80,0x7E,0x61,0x80,0x06,0x02,0x20,0x04,0x38,0x04,0x27,0x08},
{0x20,0xD0,0x20,0x20,0x20,0xD0,0x27,0x08,0x38,0x0C,0x20,0x06,0x00,0x04,0x00,0x00},/*"汉",3*/

{0x00,0x00,0x08,0x40,0x30,0x40,0x24,0x40,0x24,0x40,0x24,0x42,0xA4,0x41,0x64,0xFE},
{0x25,0x40,0x26,0x40,0x24,0x40,0x20,0x40,0x28,0x40,0x30,0x40,0x00,0x40,0x00,0x00},/*"字",4*/

{0x10,0x20,0x8C,0x3F,0x61,0xC0,0x06,0x00,0x00,0x01,0x7F,0xE2,0x40,0x0C,0x4F,0xF0},
{0x40,0x08,0x7F,0xE6,0x00,0x00,0x1F,0xE0,0x00,0x02,0x00,0x01,0xFF,0xFE,0x00,0x00},/*"测",5*/

{0x02,0x00,0x42,0x00,0x3B,0xFE,0x10,0x04,0x00,0x08,0x09,0x04,0x09,0x04,0x09,0xF8},						   
{0x09,0x08,0x09,0x08,0xFF,0x80,0x08,0x60,0x48,0x18,0x38,0x04,0x08,0x1E,0x00,0x00},/*"试",6*/ 

};
//PCtolcd2002 设置->点阵：24 ，其他设置同OLED实验。
//阴码 逐列式 逆向 24*24
const uint8_t tfont24[][24]=
{ 

{0x00,0x00,0x00,0x08,0x00,0x00,0x08,0x04,0x0C,0x08,0x04,0x0C,0x08,0x04,0x04,0xF8,0xFF,0x03,0x08,0x04,0x02,0x08,0x04,0x41},
{0x08,0x04,0x21,0x00,0x00,0x20,0x00,0x00,0x10,0xFC,0x7F,0x08,0x04,0x00,0x04,0x04,0x80,0x03,0xC4,0xFF,0x01,0xC4,0x1F,0x00},
{0x04,0xE0,0x3F,0x04,0x20,0x20,0x04,0x00,0x20,0xFC,0x3F,0x20,0x00,0x00,0x20,0x00,0x00,0x3E,0x00,0x00,0x30,0x00,0x00,0x00},/*"现",0*/
/* (24 X 24 , 宋体 ) */

{0x00,0x00,0x00,0x00,0x80,0x00,0x20,0x40,0x00,0x20,0x40,0x00,0x20,0x30,0x00,0x20,0xF8,0x7F,0x20,0x0C,0x00,0x20,0x07,0x10},
{0xA0,0x11,0x10,0xF0,0x10,0x10,0x3E,0x10,0x10,0x24,0x10,0x10,0x20,0x10,0x10,0xA0,0xFF,0x1F,0xA0,0xFF,0x1F,0x20,0x10,0x10},
{0x20,0x10,0x10,0x20,0x10,0x10,0x20,0x10,0x10,0x20,0x18,0x10,0x30,0x10,0x18,0x20,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x00},/*"在",1*/
/* (24 X 24 , 宋体 ) */

{0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0xFF,0x0F,0x10,0x04,0x02,0x10,0x04,0x02,0x10,0x04,0x02,0x10,0x04,0x02,0xF0,0xFF,0x0F},
{0xF0,0xFF,0x07,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x08,0x00,0x80,0x30,0x00,0x80,0x70,0x10,0x80,0x00,0x20,0x80,0x00,0x20},
{0x80,0x00,0x60,0xFE,0xFF,0x3F,0x84,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"时",2*/
/* (24 X 24 , 宋体 ) */

{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0xFF,0x7F,0x20,0x00,0x00,0x06,0x00,0x00,0x1C,0x00,0x00,0x18,0x00,0x00},
{0x80,0xFF,0x03,0x88,0x10,0x01,0x88,0x10,0x01,0x88,0x10,0x01,0x88,0x10,0x01,0x88,0x10,0x01,0x88,0xFF,0x03,0x88,0x80,0x03},
{0x08,0x00,0x10,0x08,0x00,0x20,0x08,0x00,0x60,0x08,0x00,0x70,0xF8,0xFF,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"间",3*/
/* (24 X 24 , 宋体 ) */

{0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x10,0x40,0x00,0x10,0x20,0x00,0x10,0x18,0x00,0x10,0x0E,0x00,0xF0,0x03,0xFC,0xD7,0x02},
{0x24,0x12,0x04,0x24,0x12,0x08,0x24,0x12,0x10,0x24,0x12,0x10,0x24,0xF2,0x3F,0x24,0x12,0x21,0x24,0x12,0x21,0x24,0x12,0x21},
{0xFC,0x17,0x21,0x08,0x10,0x61,0x00,0x10,0x61,0x00,0x10,0x61,0x00,0x18,0x60,0x00,0x10,0x20,0x00,0x00,0x00,0x00,0x00,0x00},/*"是",4*/
/* (24 X 24 , 宋体 ) */



{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x08,0x08,0x02,0x08,0x08,0x04,0x08,0x08,0x08,0x08,0x08,0x10,0x08,0x08,0xE0},
{0x0F,0xFF,0x80,0x08,0x08,0x00,0x08,0x08,0x00,0x08,0x08,0x00,0x08,0x08,0x00,0x08,0x08,0x00,0x08,0x08,0x00,0x0F,0xFF,0xFE},
{0x0F,0xFF,0xFE,0x08,0x08,0x00,0x08,0x08,0x00,0x10,0x08,0x00,0x10,0x10,0x00,0x00,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"开",4*/
{0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x04,0x01,0x80,0x08,0x0F,0x00,0x10,0x1C,0x80,0x60,0x00,0x81,0xC2,0x00,0x87,0x02},
{0x00,0xFC,0x02,0x1F,0xF0,0x04,0x3C,0x9C,0x08,0x20,0x92,0x08,0x00,0x91,0x90,0x00,0x90,0x70,0x00,0x90,0x60,0x20,0x91,0x90},
{0x10,0x93,0x18,0x1C,0x9C,0x08,0x0C,0x98,0x0C,0x00,0x80,0x04,0x01,0x00,0x06,0x01,0x00,0x04,0x00,0x00,0x04,0x00,0x00,0x00},/*"发",5*/
{0x00,0x00,0x00,0x00,0x00,0xC0,0x01,0x01,0x00,0x01,0x0E,0x00,0x01,0xF8,0x00,0x3F,0xFF,0xFE,0x21,0x20,0x00,0x01,0x10,0x02},
{0x02,0x0C,0x0E,0x00,0x00,0x12,0x00,0x07,0xE4,0x0F,0xFE,0x04,0x08,0x40,0x08,0x08,0x78,0x10,0x08,0x47,0x30,0x08,0x41,0xE0},
{0x10,0x41,0xE0,0x10,0x47,0x30,0x30,0x7C,0x18,0x30,0xE0,0x0C,0x10,0x00,0x0C,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00},/*"板",6*/
{0x00,0x00,0x00,0x00,0x80,0x40,0x00,0xC0,0x40,0x00,0x70,0xFC,0x10,0x01,0xFE,0x0C,0x07,0x02,0x04,0x38,0x02,0x01,0xC0,0x02},
{0x02,0x00,0x04,0x08,0x00,0x04,0x0E,0x00,0x08,0x09,0xE0,0x10,0x08,0x1C,0x20,0x08,0x03,0x40,0x08,0x01,0x80,0x08,0x07,0x40},
{0x08,0x1C,0x30,0x08,0xF0,0x10,0x0F,0x80,0x18,0x08,0x00,0x0C,0x00,0x00,0x0E,0x00,0x00,0x04,0x00,0x00,0x04,0x00,0x00,0x00},/*"汉",7*/
{0x00,0x00,0x00,0x00,0x02,0x00,0x01,0x02,0x00,0x03,0x02,0x00,0x0E,0x02,0x00,0x04,0x42,0x00,0x04,0x42,0x00,0x04,0x42,0x00},
{0x04,0x42,0x04,0x04,0x42,0x04,0x04,0x42,0x06,0x24,0x4F,0xFE,0x38,0x4F,0xFC,0x04,0x52,0x00,0x04,0x62,0x00,0x04,0x62,0x00},
{0x04,0xC2,0x00,0x04,0xC2,0x00,0x05,0x42,0x00,0x0E,0x02,0x00,0x0C,0x06,0x00,0x00,0x06,0x00,0x00,0x02,0x00,0x00,0x00,0x00},/*"字",8*/
{0x00,0x00,0x00,0x01,0x00,0x80,0x00,0x80,0x80,0x20,0xE0,0xFC,0x18,0x03,0xFC,0x0C,0x3C,0x00,0x00,0xC0,0x02,0x3F,0xFF,0x84},
{0x1F,0xFF,0x88,0x10,0x00,0x30,0x13,0xFF,0xC0,0x11,0xFC,0x20,0x10,0x00,0x20,0x10,0x00,0x18,0x1F,0xFF,0x0C,0x00,0x00,0x00},
{0x00,0x00,0x00,0x07,0xFF,0xC4,0x00,0x00,0x04,0x00,0x00,0x06,0x3F,0xFF,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"测",9*/
{0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x10,0x00,0x10,0x10,0x00,0x0C,0x10,0x00,0x06,0x3F,0xFC,0x00,0x00,0x08,0x00,0x00,0x10},
{0x01,0x00,0x68,0x01,0x08,0x48,0x01,0x08,0x18,0x01,0x08,0x10,0x01,0x0F,0xF0,0x01,0x08,0x10,0x01,0x10,0x20,0x01,0x10,0x20},
{0x3F,0xFC,0x00,0x11,0x07,0x80,0x11,0x00,0xE0,0x19,0x00,0x38,0x0D,0x00,0x0C,0x03,0x00,0x3E,0x01,0x00,0x46,0x00,0x00,0x00},/*"试",10*/

};
#endif
