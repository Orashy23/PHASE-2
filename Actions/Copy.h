#pragma once
#ifndef _COPY_H
#define _COPY_H

#include "Action.h"

class Copy : public Action
{
private:
    int CompIDToCopy; // store the ID of the component to copy

public:
    Copy(ApplicationManager* pApp);
    virtual ~Copy();

    virtual void ReadActionParameters();
    virtual void Execute();
    virtual void Undo();
    virtual void Redo();

    Component* GetCopiedComponent(); // returns pointer to copied component
};

#endif