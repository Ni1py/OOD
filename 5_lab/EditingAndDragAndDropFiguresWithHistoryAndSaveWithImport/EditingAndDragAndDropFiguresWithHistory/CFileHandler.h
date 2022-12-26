#pragma once

#include <SFML/Graphics.hpp>
#include "CFigureMovementDecorator.h"
#include "CFiguresHandler.h"
#include "CSaveFileStrategy.h"
#include "CImportFileStrategy.h"

class CFileHandler {
public:
	CFileHandler(string filename, CFiguresHandler* figuresHandler, CSaveFileStrategy* saveFileStrategy, CImportFileStrategy* importFileStrategy);
	void Save();
	CFiguresMemento Import();
	void SetSaveFileStrategy(CSaveFileStrategy* saveFileStrategy);
	void SetImportFileStrategy(CImportFileStrategy* importFileStrategy);

	string GetTypeSaveFileStrategy();
	string GetTypeImportFileStrategy();

	CFiguresHandler* m_figuresHandler;
private:
	CSaveFileStrategy* m_saveFileStrategy;
	CImportFileStrategy* m_importFileStrategy;
	string m_filename;
};