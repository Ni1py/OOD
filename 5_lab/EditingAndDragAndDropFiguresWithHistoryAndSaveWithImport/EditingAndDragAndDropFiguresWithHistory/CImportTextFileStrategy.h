#pragma once

#include "CImportFileStrategy.h"

class CImportTextFileStrategy : public CImportFileStrategy {
public:
	CFiguresMemento Import(string filename) override;
};
