#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Actions\Action.h"
#include "Components\Component.h"

//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components	

private:
	int CompCount;		//Actual number of Components
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)
Component* CopiedComponent; // stores the last copied component


	Output* OutputInterface; //pointer to the Output Clase Interface
	Input* InputInterface; //pointer to the Input Clase Interface


public:
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();

	//Creates an action and executes it
	void ExecuteAction(ActionType);

	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to Input / Output Object
	Output* GetOutput();
	Input* GetInput();

	//Adds a new component to the list of components
	void AddComponent(Component* pComp);


	// -------------------------------
	//  ADDED:  Save & Load Functions
	// -------------------------------

	void ClearCircuit();                        // remove all components
	void SaveAllComponents(ofstream& out);      // write components to file
	void LoadAllComponents(ifstream& in);       // read components from file
    void SetCopiedComponent(Component* comp) { CopiedComponent = comp; }
    Component* GetCopiedComponent() { return CopiedComponent; }


	// (Optional for wires/connections if your project uses them)
	void SaveAllConnections(ofstream& out);
	void LoadAllConnections(ifstream& in);


	//destructor
	~ApplicationManager();
};

#endif

