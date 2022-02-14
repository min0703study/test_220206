#pragma once
#include "GameNode.h"

class MainGame: public GameNode
{
private:
	vector<LPCSTR> _vTextOut;
	vector<LPCSTR>::iterator _viTextOut;

	int _vTextStartX;
	int _vTextStartY;

	int _vTextSpace;
	int _vTextIndex;
public:
	HRESULT init(void);
	virtual void update(void);
	virtual void release(void);
	virtual void render(void);
};

