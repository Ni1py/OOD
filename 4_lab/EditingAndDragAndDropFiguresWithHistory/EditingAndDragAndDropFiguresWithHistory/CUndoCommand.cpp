#include "CUndoCommand.h"

CUndoCommand::CUndoCommand(CToolbar* toolbar)
	:m_toolbar(toolbar) {}

void CUndoCommand::Execute() const {
	m_toolbar->m_figuresHandler->UndoHistory();
}