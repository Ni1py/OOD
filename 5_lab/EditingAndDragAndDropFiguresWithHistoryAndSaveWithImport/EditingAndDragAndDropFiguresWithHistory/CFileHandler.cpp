#include "CFileHandler.h"

CFileHandler::CFileHandler(string filename, CFiguresHandler* figuresHandler, CSaveFileStrategy* saveFileStrategy)
	:m_filename(filename),
	m_figuresHandler(figuresHandler),
	m_saveFileStrategy(saveFileStrategy) {}

void CFileHandler::Save() {
	m_saveFileStrategy->Save(m_filename, m_figuresHandler->GetFigures());
}

void CFileHandler::SetSaveFileStrategy(CSaveFileStrategy* saveFileStrategy) {
	m_saveFileStrategy = saveFileStrategy;
}

string CFileHandler::GetTypeSaveFileStrategy() {
	return typeid(*m_saveFileStrategy).name();
}