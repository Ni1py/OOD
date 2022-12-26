#pragma once

#include "CSaveFileStrategy.h"

class CSaveBinaryFileStrategy : public CSaveFileStrategy {
public:
	void Save(string filename, vector<CFigureMovementDecorator*> figures) override;
};
