#include "Save.h"
#include "ApplicationManager.h"
#include "GUI\Output.h"
#include "GUI\Input.h"

Save::Save(ApplicationManager* pApp) : Action(pApp) {}

Save::~Save() {}

void Save::ReadActionParameters()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    pOut->PrintMsg("Enter file name to save:");
    m_Filename = pIn->GetString(pOut);

    pOut->ClearStatusBar();
}

void Save::Execute()
{
    ReadActionParameters();
    pManager->SaveCircuit(m_Filename);   // <-- you implement this in ApplicationManager
}

void Save::Undo() {}
void Save::Redo() {}


