#include "Output.h"

Output::Output()
{
	//Initialize user interface parameters

	UI.AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = BLUE;
	UI.ConnColor = RED;
	UI.MsgColor = BLUE;
	UI.BkGrndColor = WHITE;

	//Initilaize colors for the toolbar
	 UI.ToolBarBackgroundColor = LIGHTGRAY;    
    UI.ToolBarBorderColor = BLACK;
	
	//Create the drawing window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);	
	ChangeTitle("Programming Techniques Project");

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar
	CreateLeftToolBar();    // Create the left tool bar

}

Input* Output::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	Input* pIn = new Input(pWind);
	return pIn;
}


//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, UI.height-UI.StatusBarHeight, UI.width, UI.height-UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
    pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial"); 
	pWind->SetPen(UI.MsgColor); 
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(MsgX, UI.height - MsgY, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (desgin) area
void Output::ClearDrawingArea() const
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(UI.LeftToolBarWidth, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight); //start drawing after the left toolbar and top toolbar
	
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void Output::CreateDesignToolBar() const
{
	UI.AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_AND2] = "..\\Images\\Menu\\Menu_AND2.jpg";
	MenuItemImages[ITM_OR2]  = "..\\Images\\Menu\\Menu_OR2.jpg";
	MenuItemImages[ITM_EXIT] = "..\\Images\\Menu\\Menu_Exit.jpg";
	MenuItemImages[ITM_NAND2] = "..\\Images\\Menu\\Menu_NAND2.jpg";
	MenuItemImages[ITM_NOR2] = "..\\Images\\Menu\\Menu_NOR2.jpg";
	MenuItemImages[ITM_XOR2] = "..\\Images\\Menu\\Menu_XOR2.jpg";
	MenuItemImages[ITM_XNOR2] = "..\\Images\\Menu\\Menu_XNOR2.jpg";
	MenuItemImages[ITM_AND3] = "..\\Images\\Menu\\Menu_AND3.jpg";
	MenuItemImages[ITM_NOR3] = "..\\Images\\Menu\\Menu_NOR3.jpg";
	MenuItemImages[ITM_XOR3] = "..\\Images\\Menu\\Menu_XOR3.jpg"; 
	MenuItemImages[ITM_INV] = "..\\Images\\Menu\\Menu_INV.jpg";
	MenuItemImages[ITM_BUFF] = "..\\Images\\Menu\\Menu_BUFF.jpg";
	MenuItemImages[ITM_SWITCH] = "..\\Images\\Menu\\Menu_SWITCH.jpg"; 
	MenuItemImages[ITM_CONNECTION] = "..\\Images\\Menu\\Menu_connection.jpg";
	MenuItemImages[ITM_LED] = "..\\Images\\Menu\\Menu_LED.jpg"; //recheck 3a4an fi errors
	//MenuItemImages[ITM_SIM_MODE] = "..\\Images\\Menu\\Menu_Simulation.jpg";
	//MenuItemImages[ITM_DSN_MODE] = "..\\Images\\Menu\\Menu_Design.jpg";*/

	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < ITM_DSN_CNT; i++) //ba3d ma n7ot ba2i el swar nebadel el 5 di bel ITM_DSN_CNT
		pWind->DrawImage(MenuItemImages[i],i*UI.ToolItemWidth,0,UI.ToolItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(RED,3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}

void Output::CreateLeftToolBar() const 
{
    int x = 0;
    int y = UI.ToolBarHeight;
    int buttonWidth  = UI.LeftToolBarWidth;
    int buttonHeight = UI.LeftButtonHeight;

    // Background
    pWind->SetBrush(UI.ToolBarBackgroundColor);
    pWind->SetPen(UI.ToolBarBorderColor, 2);
    pWind->DrawRectangle(x, y, x + buttonWidth, UI.height - UI.StatusBarHeight);

    // Images now come from a separate "Toolbar" folder
    string LeftToolImages[] =
    {
        "..\\Toolbar\\Toolbar_Save.jpg",
        "..\\Toolbar\\Toolbar_Redo.jpg",
        "..\\Toolbar\\Toolbar_Undo.jpg",
        "..\\Toolbar\\Toolbar_Delete.jpg",
        "..\\Toolbar\\Toolbar_Copy.jpg",
        "..\\Toolbar\\Toolbar_Paste.jpg",
        "..\\Toolbar\\Toolbar_Edit.jpg",
        "..\\Toolbar\\Toolbar_Cut.jpg",
        // "..\\Toolbar\\Toolbar_SimulationMode.jpg", //lesa hadawarlohom ala sowar
        // "..\\Toolbar\\Toolbar_DesignMode.jpg"
    };

    int numButtons = sizeof(LeftToolImages) / sizeof(LeftToolImages[0]);

    // Draw buttons
    for (int i = 0; i < numButtons; i++)
    {
        pWind->DrawImage(LeftToolImages[i], x, y + i * buttonHeight, buttonWidth, buttonHeight);

        pWind->SetPen(BLACK, 2);
        pWind->DrawRectangle(x, 
                             y + i * buttonHeight,
                             x + buttonWidth,
                             y + (i + 1) * buttonHeight);
    }

    // Separator line
    pWind->SetPen(RED, 3);
    pWind->DrawLine(buttonWidth, UI.ToolBarHeight, buttonWidth, UI.height - UI.StatusBarHeight);
}

// Detect which left toolbar button was clicked 
ActionType Output::GetLeftToolbarAction(int x, int y) const 
{
    int buttonWidth  = UI.LeftToolBarWidth; 
    int buttonHeight = UI.LeftButtonHeight; 
    int startY = UI.ToolBarHeight;

    // Check if click is inside the left toolbar
    if (x < buttonWidth && y > startY && y < UI.height - UI.StatusBarHeight)
    {
        int index = (y - startY) / buttonHeight;
        if (index >= 0 && index < LEFT_TOOLBAR_CNT)
            return LeftToolbarActions[index];
    }

    return STATUS_BAR; // default if outside toolbar
}







//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void Output::CreateSimulationToolBar() const
{
	UI.AppMode = SIMULATION;	//Simulation Mode

	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)


}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	// use highlighted image when selected
		GateImage = "..\\Images\\Gates\\Gate_AND2_Hi.jpg";
	else
		GateImage = "..\\Images\\Gates\\Gate_AND2.jpg";

	// Draw AND2 gate at the top-left corner specified in r_GfxInfo

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
	

}

void Output::DrawOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)
		GateImage = "..\\Images\\Gates\\Gate_OR2.jpg";
	else
		GateImage = "..\\Images\\Gates\\Gate_OR2.jpg";

	// Draw OR2 gate
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.OR2_Width, UI.OR2_Height);
}

void Output::DrawXOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)
		GateImage = "..\\Images\\Gates\\Gate_XOR2_Hi.jpg";
	else
		GateImage = "..\\Images\\Gates\\Gate_XOR2.jpg";

	// Draw XOR2 gate
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.XOR2_Width, UI.XOR2_Height);
}

void Output::DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)
		GateImage = "..\\Images\\Gates\\Gate_XNOR2_Hi.jpg";
	else
		GateImage = "..\\Images\\Gates\\Gate_XNOR2.jpg";

	// Draw XNOR2 gate
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.XNOR2_Width, UI.XNOR2_Height);
}


void Output::DrawLED(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage = "..\\Images\\Gates\\LED.jpg";  

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.LED_Width, UI.LED_Height);
}



void Output::DrawNAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)
		GateImage = "..\\Images\\Gates\\Gate_NAND2_Hi.jpg";
	else
		GateImage = "..\\Images\\Gates\\Gate_NAND2.jpg";

	// Draw NAND2 gate
	//mari
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NAND2_Width, UI.NAND2_Height);
}

void Output::DrawNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)
		GateImage = "..\\Images\\Gates\\Gate_NOR2_Hi.jpg";
	else
		GateImage = "..\\Images\\Gates\\Gate_NOR2.jpg";

	// Draw NOR2 gate
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.OR2_Width, UI.OR2_Height);
}

void Output::DrawXOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)
		GateImage = "..\\Images\\Gates\\Gate_XOR3_Hi.jpg";
	else
		GateImage = "..\\Images\\Gates\\Gate_XOR3.jpg";

	// Draw XOR3 gate
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.OR2_Width, UI.OR2_Height);
}

void Output::DrawAND3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)
		GateImage = "..\\Images\\Gates\\Gate_AND3_Hi.jpg";
	else
		GateImage = "..\\Images\\Gates\\Gate_AND3.jpg";

	// Draw AND3 gate
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.OR2_Width, UI.OR2_Height);
}

void Output::DrawNOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)
		GateImage = "..\\Images\\Gates\\Gate_NOR3_Hi.jpg";
	else
		GateImage = "..\\Images\\Gates\\Gate_NOR3.jpg";

	// Draw NOR3 gate
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.OR2_Width, UI.OR2_Height);
}

//omar

void Output::DrawINV(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)
		GateImage = "..\\Images\\Gates\\Gate_INV_Hi.jpg";
	else
		GateImage = "..\\Images\\Gates\\Gate_INV.jpg";

	// Draw INV gate
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.OR2_Width, UI.OR2_Height);
}

void Output::DrawBUFF(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)
		GateImage = "..\\Images\\Gates\\Gate_BUFF_Hi.jpg";
	else
		GateImage = "..\\Images\\Gates\\Gate_BUFF.jpg";

	// Draw BUFF gate
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.OR2_Width, UI.OR2_Height);
}

void Output::DrawSWITCH(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)
		GateImage = "..\\Images\\Gates\\Gate_SWITCH_Hi.jpg";
	else
		GateImage = "..\\Images\\Gates\\Gate_SWITCH.jpg";

	// Draw BUFF gate
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.OR2_Width, UI.OR2_Height);
}






void Output::DrawConnection(GraphicsInfo r_GfxInfo, bool selected) const
{

	// set pen color based on selection
	if (selected)
		pWind->SetPen(UI.SelectColor, 3);
	else
		pWind->SetPen(UI.ConnColor, 3);

	// draw an l-shaped connection
	// this simple logic handles straight horizontal, straight vertical, and broken lines

	if (r_GfxInfo.x1 == r_GfxInfo.x2 || r_GfxInfo.y1 == r_GfxInfo.y2) {
		pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y2);
		return;
	}

	int midx = (r_GfxInfo.x1 + r_GfxInfo.x2) / 2;
	pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, midx, r_GfxInfo.y1);
	pWind->DrawLine(midx, r_GfxInfo.y1, midx, r_GfxInfo.y2);
	pWind->DrawLine(midx, r_GfxInfo.y2, r_GfxInfo.x2, r_GfxInfo.y2);

}





void Output::DrawString(int x, int y, string msg) const
{
	pWind->SetPen(UI.MsgColor);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(x, y, msg);
}


Output::~Output()
{
	delete pWind;
}

// omda ba2oloko check keda el draw connection mazbota wala eh

//mariam
