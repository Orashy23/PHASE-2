#ifndef _SAVE_H
#define _SAVE_H

#include "Action.h"

class Save :
    public Action
{
private:
    string m_Filename;    // The file where we will save

public:
    Save(ApplicationManager* pApp);
    virtual ~Save(void);

    //Reads parameters required for action to execute
    virtual void ReadActionParameters();

    //Execute action (code depends on action type)
    virtual void Execute();

    virtual void Undo();
    virtual void Redo();
};

#endif
