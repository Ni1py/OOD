#pragma once

#include "CSaveFileStrategy.h"

class CSaveTextFileStrategy : public CSaveFileStrategy {
public:
	void Save(string filename, vector<CFigureMovementDecorator*> figures) override;
};
