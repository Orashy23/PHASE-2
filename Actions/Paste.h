#pragma once
#ifndef _PASTE_H
#define _PASTE_H

#include "Action.h"

class Paste : public Action
{
public:
    Paste(ApplicationManager* pApp);
    virtual ~Paste();

    virtual void ReadActionParameters();
    virtual void Execute();
    virtual void Undo();
    virtual void Redo();
};

#endif