#ifndef UI_INFO_H
#define UI_INFO_H
#include <iostream>
using namespace std;
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface
const int x = 50;
const int y = 50;
__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	MODE AppMode;		//Application Mode (design or simulation)
	
	static const int	width = 1900, height = 655,	//Window width and height
						wx = 15 , wy = 15,			//Window starting coordinates
						StatusBarHeight = 50,	//Status Bar Height
						ToolBarHeight = 80,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
						ToolItemWidth = 80;		//Width of each item in toolbar menu

	color DrawColor;		//Drawing color
	color SelectColor;		//Highlighting color
	color ConnColor;		//Connector color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Back ground color

	
	//This should be calculated accurately because it will be used later to create connections between gates
	//For now, we will assume that rect width = 50 and height = 50
	static const int	AND2_Width = x,		//A2 Gate Image default width
						AND2_Height = y;		//AND2 Gate Image default height
	static const int	OR2_Width = x,		//OR2 Gate Image default width
		OR2_Height = y;		//OR2 Gate Image default height
	static const int	XOR2_Width = x,		//XOR2 Gate Image default width
		XOR2_Height = y;		//XOR2 Gate Image default height
	static const int	XNOR2_Width = x,		//XNOR2 Gate Image default width
		XNOR2_Height = y;		//XNOR2 Gate Image default height
	static const int	AND3_Width = x,		//AND3 Gate Image default width
		AND3_Height = y;		//AND3 Gate Image default height
	static const int	NOR3_Width = x,		//NOR3 Gate Image default width
		NOR3_Height = y;		//NOR3 Gate Image default height
	static const int	XOR3_Width = x,		//XOR3 Gate Image default width
		XOR3_Height = y;		//XOR3 Gate Image default height
	static const int    INV_Width = x,        //INV Gate Image default width
		INV_Height = y;       //INV Gate Image default height
	static const int    BUFF_Width = x,       //BUFF Gate Image default width
		BUFF_Height = y;      //BUFF Gate Image default height
	static const int    NAND2_Width = x,      //NAND2 Gate Image default width
		NAND2_Height = y;     //NAND2 Gate Image default height
	static const int    NOR2_Width = x,       //NOR2 Gate Image default width
		NOR2_Height = y;      //NOR2 Gate Image default height


	
}UI;	//create a single global object UI

#endif