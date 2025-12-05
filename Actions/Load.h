#pragma once
#ifndef _LOAD_H
#define _LOAD_H

#include "Action.h"

class Load : 
    public Action
{
private:
    string m_Filename;

public:
    Load(ApplicationManager* pApp);
    virtual ~Load(void);

    virtual void ReadActionParameters();
    virtual void Execute();
    virtual void Undo();
    virtual void Redo();
};

#endif
