#include "Copy.h"
#include "ApplicationManager.h"
#include "GUI\Output.h"
#include "GUI\Input.h"

Copy::Copy(ApplicationManager* pApp) : Action(pApp), CompIDToCopy(-1) {}
Copy::~Copy() {}

void Copy::ReadActionParameters()
{
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    pOut->PrintMsg("Click on component to copy");
    CompIDToCopy = pIn->GetClickedComponentID();  // Implement in Input class
    pOut->ClearStatusBar();
}

void Copy::Execute()
{
    ReadActionParameters();

    if (CompIDToCopy < 0) {
        pManager->GetOutput()->PrintMsg("No component selected to copy");
    }
    else {
        pManager->SetCopiedComponent(pManager->GetComponent(CompIDToCopy));
        pManager->GetOutput()->PrintMsg("Component copied");
    }
}

void Copy::Undo() {}
void Copy::Redo() {}

Component* Copy::GetCopiedComponent()
{
    return pManager->GetCopiedComponent();
}