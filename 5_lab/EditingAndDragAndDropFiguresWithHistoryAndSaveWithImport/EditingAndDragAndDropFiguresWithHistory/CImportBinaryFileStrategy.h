#pragma once

#include "CImportFileStrategy.h"

class CImportBinaryFileStrategy : public CImportFileStrategy {
public:
	CFiguresMemento Import(string filename) override;
};
