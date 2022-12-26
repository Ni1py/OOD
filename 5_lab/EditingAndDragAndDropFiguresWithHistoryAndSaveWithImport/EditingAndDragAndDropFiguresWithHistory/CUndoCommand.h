#pragma once
#include "ICommand.h"
#include "CToolbar.h"

class CUndoCommand : public ICommand {
public:
	CUndoCommand(CToolbar* toolbar);
	void Execute() const override;
private:
	CToolbar* m_toolbar;
};
