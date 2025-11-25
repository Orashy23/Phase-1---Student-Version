#include "GUI\Input.h"
#include "GUI\Output.h"

//This is a test code to test the Input and Output classes

void prntlocation(int& x, int &y, Output * pOut, Input* pIn)
{
	while (x < 80 || x > 1800 || y < 80 || y > 600) // to prevent adding gate outside drawing area
	{
	
		pOut->PrintMsg("Invalid location, please click inside the drawing area");
		pIn->GetPointClicked(x, y);
	}
}

int main()
{
	int x, y;

	//Create Input and Output objects to test
	Output* pOut = new Output();;
	Input* pIn = pOut->CreateInput();

	
	//Starting the test
	pOut->PrintMsg("This demo is to test input and output classes, Click anywhere to start the test");
	pIn->GetPointClicked(x, y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 1:	Create The FULL Tool bar, the drawing area and the status bar	
	//			This has already been done through the constrcutor of class Output
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMsg("TEST1: Drawing Tool bar and Status bar, Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 2:	Drawing all the Components with all possible states: Normal, highlighted
	//			
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMsg("TEST2: Now we will show that Output class can draw any Component in any state, Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	GraphicsInfo GfxInfo;  //to be used with draw function of the class Ouput

	/// 2.1- AND2 Gate test
	pOut->PrintMsg("Drawing 2-input AND gate, Normal and Highlighted,  Click to continue");

	//Drawing Normal AND2 gate
	GfxInfo.x1 = 100;	GfxInfo.y1 = 100;
	pOut->DrawAND2(GfxInfo);

	//Drawing Highlighted AND2 gate
	GfxInfo.x1 = 100;	GfxInfo.y1 = 200;
	pOut->DrawAND2(GfxInfo, true);

	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawingArea();

	/// 2.2- NAND2 Gate test
	pOut->PrintMsg("Drawing 2-input NAND gate, Normal and Highlighted,  Click to continue");

	///TODO: Add code to draw 2-input NAND gate, Normal and Highlighted

	GfxInfo.x1 = 100;	GfxInfo.y1 = 100;
	pOut->DrawNAND2(GfxInfo);

	//Drawing Highlighted NAND2 gate
	GfxInfo.x1 = 100;	GfxInfo.y1 = 200;
	pOut->DrawNAND2(GfxInfo, true);

	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawingArea();

	/// 2.3- OR2 and NOR2 Gates test
	pOut->PrintMsg("Drawing 2-input OR and NOR gates, Normal and Highlighted,  Click to continue");

	///TODO: Add code to draw 2-input OR and NOR gates, Normal and Highlighted for each

	GfxInfo.x1 = 100;	GfxInfo.y1 = 100;
	pOut->DrawOR2(GfxInfo);

	//Drawing Highlighted OR2 gate
	GfxInfo.x1 = 100;	GfxInfo.y1 = 200;
	pOut->DrawOR2(GfxInfo, true);



	GfxInfo.x1 = 300;	GfxInfo.y1 = 100;
	pOut->DrawNOR2(GfxInfo);

	//Drawing Highlighted NOR2 gate
	GfxInfo.x1 = 300;	GfxInfo.y1 = 200;
	pOut->DrawNOR2(GfxInfo, true);

	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawingArea();





	/// 2.4- XOR2 and XNOR2 Gates test
	pOut->PrintMsg("Drawing 2-input XOR and XNOR gates, Normal and Highlighted,  Click to continue");

	///TODO: Add code to draw 2-input XOR and XNOR gates, Normal and Highlighted for each

	GfxInfo.x1 = 100;	GfxInfo.y1 = 100;
	pOut->DrawXOR2(GfxInfo);

	//Drawing Highlighted XOR2 gate
	GfxInfo.x1 = 100;	GfxInfo.y1 = 200;
	pOut->DrawXOR2(GfxInfo, true);

	GfxInfo.x1 = 300;	GfxInfo.y1 = 100;
	pOut->DrawXNOR2(GfxInfo);


	//Drawing Highlighted XNOR2 gate
	GfxInfo.x1 = 300;	GfxInfo.y1 = 200;
	pOut->DrawXNOR2(GfxInfo, true);

	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawingArea();

	/// 2.5- Buffer and Inverter Gates test
	pOut->PrintMsg("Drawing Buffer and Inverter Gates, Normal and Highlighted,  Click to continue");

	///TODO: Add code to draw Buffer and Inverter Gates, Normal and Highlighted for each

	GfxInfo.x1 = 100;	GfxInfo.y1 = 100;
	pOut->DrawBUFF(GfxInfo);

	//Drawing Highlighted BUFF gate
	GfxInfo.x1 = 100;	GfxInfo.y1 = 200;
	pOut->DrawBUFF(GfxInfo, true);

	GfxInfo.x1 = 300;	GfxInfo.y1 = 100;
	pOut->DrawINV(GfxInfo);


	//Drawing Highlighted INV gate
	GfxInfo.x1 = 300;	GfxInfo.y1 = 200;
	pOut->DrawINV(GfxInfo, true);


	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawingArea();


	/// 2.6- AND3, NOR3, and XOR3 Gates test
	pOut->PrintMsg("Drawing 3-input AND, NOR, XOR Gates, Normal and Highlighted,  Click to continue");

	///TODO: Add code to draw 3-input AND, NOR, and XOR Gates, Normal and Highlighted for each

	GfxInfo.x1 = 100;	GfxInfo.y1 = 100;
	pOut->DrawAND3(GfxInfo);

	//Drawing Highlighted AND3 gate

	GfxInfo.x1 = 100;	GfxInfo.y1 = 200;
	pOut->DrawAND3(GfxInfo, true);



	GfxInfo.x1 = 300;	GfxInfo.y1 = 100;
	pOut->DrawNOR3(GfxInfo);

	//Drawing Highlighted NOR3 gate

	GfxInfo.x1 = 300;	GfxInfo.y1 = 200;
	pOut->DrawNOR3(GfxInfo, true);

	GfxInfo.x1 = 500;	GfxInfo.y1 = 100;
	pOut->DrawXOR3(GfxInfo);

	//Drawing Highlighted XOR3 gate
	GfxInfo.x1 = 500;	GfxInfo.y1 = 200;
	pOut->DrawXOR3(GfxInfo, true);



	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawingArea();

	/// 2.7- Switch and LED test
	pOut->PrintMsg("Drawing Switch and LED, Normal and Highlighted,  Click to continue");

	///TODO: Add code to draw Switch and LED, Normal and Highlighted for each

	GfxInfo.x1 = 100;	GfxInfo.y1 = 100;
	pOut->DrawSWITCH(GfxInfo);

	//Drawing Highlighted SWITCH gate
	GfxInfo.x1 = 100;	GfxInfo.y1 = 200;
	pOut->DrawSWITCH(GfxInfo, true);


	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawingArea();


	/// 2.8- Connections
	pOut->PrintMsg("Drawing connections, Normal, Highlighted, straight, and broken,  Click to continue");

	///TODO: Add code to draw connections, Normal, Highlighted, straight, and broken (all combinations) 

	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawingArea();






	///////////////////////////////////////////////////////////////////////////////////
	// TEST 3: Read strings from the user
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMsg("TEST3: Now Time to test class Input, Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	pOut->PrintMsg("Testing Input ability to read strings");

	///TODO: Add code here to 
	// 1- Read a string from the user on the status bar and print it inside the drawing area


	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawingArea();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 4: Check for the user action
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMsg("TEST4: Testing Input ability to detect User Action, click anywhere");

	ActionType ActType;

	///TODO:  You must add a case for each action
	//Add cases for the missing actions below
	
	do
	{
		ActType = pIn->GetUserAction();
		
		switch (ActType)
		{
		case ADD_BUFF:
		{
			pOut->PrintMsg("Action: add a buffer gate , Click anywhere");
			pIn->GetPointClicked(x, y);
			GraphicsInfo GfxInfo = {};
			prntlocation(x, y, pOut, pIn);
			GfxInfo.x1 = x;
			GfxInfo.y1 = y;
			pOut->ChangeTitle("Buffer Gate Added at (" + to_string(x) + "," + to_string(y) + ")");
			pOut->DrawBUFF(GfxInfo, false);
		}
		break;

		case ADD_INV:

		{
			pOut->PrintMsg("Action: add an inverter gate , Click anywhere");
			pIn->GetPointClicked(x, y);
			GraphicsInfo GfxInfo = {};
			prntlocation(x, y, pOut, pIn);
			GfxInfo.x1 = x;
			GfxInfo.y1 = y;
			pOut->ChangeTitle("Inverter Gate Added at (" + to_string(x) + "," + to_string(y) + ")");
			pOut->DrawINV(GfxInfo, false);

		}
		break;

		case ADD_AND_GATE_2:

		{
			pOut->PrintMsg("Action: add 2-input AND gate , Click anywhere");
			pIn->GetPointClicked(x, y);
			GraphicsInfo GfxInfo = {};
			prntlocation(x, y, pOut, pIn);
			GfxInfo.x1 = x;
			GfxInfo.y1 = y;
			pOut->ChangeTitle("2 input AND Gate Added at (" + to_string(x) + "," + to_string(y) + ")");
			pOut->DrawAND2(GfxInfo, false);


		}
		break;

		case ADD_NAND_GATE_2:
		{
			pOut->PrintMsg("Action: add 2-input NAND gate , Click anywhere");
			pIn->GetPointClicked(x, y);
			GraphicsInfo GfxInfo = {};
			prntlocation(x, y, pOut, pIn);
			GfxInfo.x1 = x;
			GfxInfo.y1 = y;
			pOut->ChangeTitle("2 input NAND Gate Added at (" + to_string(x) + "," + to_string(y) + ")");
			pOut->DrawNAND2(GfxInfo, false);


		}

		break;
		case ADD_OR_GATE_2:
		{
			pOut->PrintMsg("Action: add 2-input OR gate , Click anywhere");
			pIn->GetPointClicked(x, y);
			GraphicsInfo GfxInfo = {};
			prntlocation(x, y, pOut, pIn);
			GfxInfo.x1 = x;
			GfxInfo.y1 = y;
			pOut->ChangeTitle("2 input OR Gate Added at (" + to_string(x) + "," + to_string(y) + ")");
			pOut->DrawOR2(GfxInfo, false);

		}
		break;

		case ADD_NOR_GATE_2:
		{
			pOut->PrintMsg("Action: add 2-input NOR gate , Click anywhere");
			pIn->GetPointClicked(x, y);
			GraphicsInfo GfxInfo = {};
			prntlocation(x, y, pOut, pIn);
			GfxInfo.x1 = x;
			GfxInfo.y1 = y;
			pOut->ChangeTitle("2 input NAND Gate Added at (" + to_string(x) + "," + to_string(y) + ")");
			pOut->DrawNOR2(GfxInfo, false);

		}
		break;

		case ADD_XOR_GATE_2:
		{
			pOut->PrintMsg("Action: add 2-input XOR gate , Click anywhere");
			pIn->GetPointClicked(x, y);
			GraphicsInfo GfxInfo = {};
			prntlocation(x, y, pOut, pIn);
			GfxInfo.x1 = x;
			GfxInfo.y1 = y;
			pOut->ChangeTitle("2 input XOR Gate Added at (" + to_string(x) + "," + to_string(y) + ")");
			pOut->DrawXOR2(GfxInfo, false);
		}
		break;

		case ADD_XNOR_GATE_2:
		{
			pOut->PrintMsg("Action: add 2-input XNOR gate , Click anywhere");
			pIn->GetPointClicked(x, y);
			GraphicsInfo GfxInfo = {};
			prntlocation(x, y, pOut, pIn);
			GfxInfo.x1 = x;
			GfxInfo.y1 = y;
			pOut->ChangeTitle("2 input XNOR Gate Added at (" + to_string(x) + "," + to_string(y) + ")");
			pOut->DrawXNOR2(GfxInfo, false);

		}
		break;



		case ADD_AND_GATE_3:
		{
			pOut->PrintMsg("Action: add 2-input XNOR gate , Click anywhere");
			pIn->GetPointClicked(x, y);
			GraphicsInfo GfxInfo = {};
			prntlocation(x, y, pOut, pIn);
			GfxInfo.x1 = x;
			GfxInfo.y1 = y;
			pOut->ChangeTitle("3 input AND Gate Added at (" + to_string(x) + "," + to_string(y) + ")");
			pOut->DrawAND3(GfxInfo, false);

		}
		break;
		case ADD_XOR_GATE_3:
		{
			pOut->PrintMsg("Action: add 2-input XNOR gate , Click anywhere");
			pIn->GetPointClicked(x, y);
			GraphicsInfo GfxInfo = {};
			prntlocation(x, y, pOut, pIn);
			GfxInfo.x1 = x;
			GfxInfo.y1 = y;
			pOut->ChangeTitle("3 input XOR Gate Added at (" + to_string(x) + "," + to_string(y) + ")");
			pOut->DrawXOR3(GfxInfo, false);

		}
		break;

		case ADD_NOR_GATE_3:
		{
			pOut->PrintMsg("Action: add 2-input XNOR gate , Click anywhere");
			pIn->GetPointClicked(x, y);
			GraphicsInfo GfxInfo = {};
			prntlocation(x, y, pOut, pIn);
			GfxInfo.x1 = x;
			GfxInfo.y1 = y;
			pOut->ChangeTitle("3 input NOR Gate Added at (" + to_string(x) + "," + to_string(y) + ")");
			pOut->DrawNOR3(GfxInfo, false);

		}
		break;

		case ADD_LED:
		{
			pOut->PrintMsg("Action: add LED gate , Click anywhere");
			pIn->GetPointClicked(x, y);
			GraphicsInfo GfxInfo = {};
			prntlocation(x, y, pOut, pIn);
			GfxInfo.x1 = x;
			GfxInfo.y1 = y;
			pOut->ChangeTitle("LED Gate Added at (" + to_string(x) + "," + to_string(y) + ")");
			pOut->DrawLED(GfxInfo, false);

		}
		break;




		case ADD_SWITCH:
		{
			pOut->PrintMsg("Action: add switch , Click anywhere");
			pIn->GetPointClicked(x, y);
			GraphicsInfo GfxInfo = {};
			prntlocation(x, y, pOut, pIn);
			GfxInfo.x1 = x;
			GfxInfo.y1 = y;
			pOut->ChangeTitle("Switch Added at (" + to_string(x) + "," + to_string(y) + ")");
			pOut->DrawSWITCH(GfxInfo, false);

		}
		break;

		case SELECT:
		{
			pOut->PrintMsg("Action: a click on the Drawing area, Click anywhere");


			break;

		}
		case STATUS_BAR:
		{
			pOut->PrintMsg("Action: a click on the Status Bar, Click anywhere");


			break;
		}

		case DSN_TOOL:
		{
			pOut->PrintMsg("Action: a click on empty area in the Design Tool Bar, Click anywhere");


			break;
		}

		case SIM_MODE:
		{
			pOut->PrintMsg("Action: Switch to Simulation Mode, creating simualtion tool bar");


			pOut->CreateSimulationToolBar();
			break;
		}

		case DSN_MODE:
		{
			pOut->PrintMsg("Action: Switch to Design Mode, creating Design tool bar");


			pOut->CreateDesignToolBar();
			break;
		}


		case EXIT:
		{
			break;
		}


		case ADD_CONNECTION: 
		
		{
			pOut->PrintMsg("Action: Add Connection - Click on the START point");
			int x1, y1, x2, y2;

			pIn->GetPointClicked(x1, y1);
			prntlocation(x1, y1, pOut, pIn);

			pOut->PrintMsg("Action: Add Connection - Now click on the END point");

			pIn->GetPointClicked(x2, y2);
			prntlocation(x2, y2, pOut, pIn);

			GraphicsInfo GfxInfo = {};
			GfxInfo.x1 = x1;
			GfxInfo.y1 = y1;
			GfxInfo.x2 = x2;
			GfxInfo.y2 = y2;

			pOut->ChangeTitle("Connection Added from (" + to_string(x1) + "," + to_string(y1) +") to (" + to_string(x2) + "," + to_string(y2) + ")");
			pOut->DrawConnection(GfxInfo, false);
		}
		break;


		}
		}while (ActType != EXIT); //mmken tet4al


		/// Exiting
		pOut->PrintMsg("Action: EXIT, test is finished");
		

		

		delete pIn;
		delete pOut;

		return 0;
	}
	
	

	
