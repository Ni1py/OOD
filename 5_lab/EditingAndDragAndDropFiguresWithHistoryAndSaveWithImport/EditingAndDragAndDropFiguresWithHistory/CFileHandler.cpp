#include "CFileHandler.h"

CFileHandler::CFileHandler(string filename, CFiguresHandler* figuresHandler, CSaveFileStrategy* saveFileStrategy, CImportFileStrategy* importFileStrategy)
	:m_filename(filename),
	m_figuresHandler(figuresHandler),
	m_saveFileStrategy(saveFileStrategy),
	m_importFileStrategy(importFileStrategy) {}

void CFileHandler::Save() {
	m_saveFileStrategy->Save(m_filename, m_figuresHandler->GetFigures());
}

CFiguresMemento CFileHandler::Import() {
	return m_importFileStrategy->Import(m_filename);
}

void CFileHandler::SetSaveFileStrategy(CSaveFileStrategy* saveFileStrategy) {
	m_saveFileStrategy = saveFileStrategy;
}

void CFileHandler::SetImportFileStrategy(CImportFileStrategy* importFileStrategy) {
	m_importFileStrategy = importFileStrategy;
}

string CFileHandler::GetTypeSaveFileStrategy() {
	return typeid(*m_saveFileStrategy).name();
}

string CFileHandler::GetTypeImportFileStrategy() {
	return typeid(*m_importFileStrategy).name();
}