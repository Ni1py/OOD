#pragma once

#include <SFML/Graphics.hpp>
#include "CFigureMovementDecorator.h"
#include "CFiguresHandler.h"
#include "CSaveFileStrategy.h"

class CFileHandler {
public:
	CFileHandler(string filename, CFiguresHandler* figuresHandler, CSaveFileStrategy* saveFileStrategy);
	void Save();
	//void Import();
	void SetSaveFileStrategy(CSaveFileStrategy* saveFileStrategy);

	string GetTypeSaveFileStrategy();
	//string GetTypeImportFileStrategy();

	CFiguresHandler* m_figuresHandler;
private:
	CSaveFileStrategy* m_saveFileStrategy;
	string m_filename;
};