#include "Stdafx.h"
#include "MainGame.h"

HRESULT MainGame::init(void)
{
	GameNode::init(true);

	IMAGEMANAGER->addImage("background_default", "Resources/Images/Background/background.bmp", WINSIZE_X, WINSIZE_Y);
	
	_vTextStartX = 0;
	_vTextStartY = 0;

	_vTextSpace = 20;
	_vTextIndex = 0;

	_vTextOut.push_back("민채영 - 첫번째 메세지");
	_vTextOut.push_back("민채영 - 두번째 메세지");
	
	return S_OK;
}

void MainGame::update(void)
{
	GameNode::update();
}

void MainGame::release(void)
{
	GameNode::release();
}

void MainGame::render(void)
{
	PatBlt(getMemDc(), 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);

	RECT rc = { 0,0,WINSIZE_X, WINSIZE_Y };

	IMAGEMANAGER->findImage("background_default")->render(getMemDc());

	for (_viTextOut = _vTextOut.begin(), _vTextIndex = 0; _viTextOut != _vTextOut.end(); _viTextOut++, _vTextIndex++) {
		TextOut(getMemDc(), 0, 100 + (_vTextIndex * _vTextSpace), *_viTextOut, strlen(*_viTextOut));
	}

	TIMEMANAGER->render(getMemDc());
	IMAGEMANAGER->render(getBackBufferKey(), getHdc());
}
