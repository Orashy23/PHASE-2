#include "Load.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"

/*
#include "..\Components\AND2.h"
#include "..\Components\BUFF1.h"
#include "..\Components\Component.h"
#include "..\Components\Connection.h"
#include "..\Components\Gate.h"
#include "..\Components\InputPin.h"
#include "..\Components\INV1.h"
#include "..\Components\Led.h"
#include "..\Components\NAND2.h"
#include "..\Components\NOR2.h"
#include "..\Components\OR2.h"
#include "..\Components\OutputPin.h"
#include "..\Components\Pin.h"
#include "..\Components\Switch.h"
#include "..\Components\XNOR2.h"
#include "..\Components\XOR2.h"
#include "AddANDgate2.h"
*/

Load::Load(ApplicationManager* pApp) : Action(pApp) {}
Load::~Load() {}

void Load::ReadActionParameters()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    pOut->PrintMsg("Enter file name to load: ");
    m_Filename = pIn->GetString(pOut);

    pOut->ClearStatusBar();
}

void Load::Execute()
{
    ReadActionParameters();
    pManager->LoadCircuit(m_Filename);
}

void Load::Undo() {}
void Load::Redo() {}
