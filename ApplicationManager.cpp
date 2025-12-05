#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include <fstream>

//==============================
// Constructor
//==============================
ApplicationManager::ApplicationManager()
{
    CompCount = 0;

    for (int i = 0; i < MaxCompCount; i++)
        CompList[i] = NULL;

    OutputInterface = new Output();
    InputInterface = OutputInterface->CreateInput();
}

//==============================
// Add Component
//==============================
void ApplicationManager::AddComponent(Component* pComp)
{
    CompList[CompCount++] = pComp;
}

//==============================
// Get User Action
//==============================
ActionType ApplicationManager::GetUserAction()
{
    return InputInterface->GetUserAction();
}

//==============================
// Execute Action
//==============================
void ApplicationManager::ExecuteAction(ActionType ActType)
{
    Action* pAct = NULL;
    switch (ActType)
    {
    case ADD_AND_GATE_2:
        pAct = new AddANDgate2(this);
        break;

    case ADD_CONNECTION:
        // TODO
        break;

    case EXIT:
        // TODO
        break;
		
	case SAVE:
		//TODO: Create Save Action here
		pAct = new Save(this);
		break;
    }

    if (pAct)
    {
        pAct->Execute();
        delete pAct;
        pAct = NULL;
    }
}

//==============================
// Draw All Components
//==============================
void ApplicationManager::UpdateInterface()
{
    for (int i = 0; i < CompCount; i++)
        CompList[i]->Draw(OutputInterface);
}

//==============================
// Getters
//==============================
Input* ApplicationManager::GetInput()
{
    return InputInterface;
}

Output* ApplicationManager::GetOutput()
{
    return OutputInterface;
}

//==============================
// Destructor
//==============================
ApplicationManager::~ApplicationManager()
{
    for (int i = 0; i < CompCount; i++)
        delete CompList[i];

    delete OutputInterface;
    delete InputInterface;
}


//==============================
// Clear Circuit
//==============================
void ApplicationManager::ClearCircuit()
{
    for (int i = 0; i < CompCount; i++)
    {
        delete CompList[i];
        CompList[i] = NULL;
    }
    CompCount = 0;
}


//==============================
// Save Components
//==============================
void ApplicationManager::SaveAllComponents(ofstream& out)
{
    out << CompCount << endl;     // Save count first

    for (int i = 0; i < CompCount; i++)
    {
        CompList[i]->Save(out);   // Call component Save()
    }
}


//==============================
// Load Components
//==================
void ApplicationManager::LoadAllComponents(ifstream& in)
{
    int count;
    in >> count;

    for (int i = 0; i < count; i++)
    {
        string type;
        in >> type;

        if (type == "AND2")
        {
            AND2* A = new AND2;
            A->Load(in);
            AddComponent(A);
        }

        // YOU can add more (OR, NAND, etc.)
    }
}


//==============================
// Save Connections 
//==============================
void ApplicationManager::SaveAllConnections(ofstream& out)
{
   
	// Same — fill later when connections exist
}


//==============================
// Load Connections 
//==============================
void ApplicationManager::LoadAllConnections(ifstream& in)
{
    // Same — fill later when connections exist
}

