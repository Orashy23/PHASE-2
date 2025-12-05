#include "Paste.h"
#include "ApplicationManager.h"
#include "Components\Component.h"
#include "GUI\Output.h"
#include "GUI\Input.h"

Paste::Paste(ApplicationManager* pApp) : Action(pApp) {}
Paste::~Paste() {}

void Paste::ReadActionParameters()
{
    Output* pOut = pManager->GetOutput();
    pOut->PrintMsg("Click where to paste the component");
}

void Paste::Execute()
{
    ReadActionParameters();

    Component* copied = pManager->GetCopiedComponent();
    if (!copied) {
        pManager->GetOutput()->PrintMsg("No component to paste");
        return;
    }

    // Create a new copy (using component's own Clone/Copy constructor)
    Component* newComp = copied->Clone();

    // Set new position (optional: get click from Input)
    Input* pIn = pManager->GetInput();
    int x, y;
    pIn->GetClickedCoordinates(x, y);  // implement in Input class
    newComp->SetPosition(x, y);

    pManager->AddComponent(newComp);

    pManager->GetOutput()->PrintMsg("Component pasted");
}

void Paste::Undo() {}
void Paste::Redo() {}