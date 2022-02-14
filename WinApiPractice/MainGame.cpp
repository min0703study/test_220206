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

	_vTextOut.push_back("민채영 - 안녕하세요! 팀포폴 열심히 같이 해봐요!");
	_vTextOut.push_back("임지혁 - 잘 부탁드립니다 ~");
	_vTextOut.push_back("박정호 - 2주간 열심히할게요 ~");

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
		if (_vTextIndex < 30) {
			TextOut(getMemDc(), _vTextIndex * 50 , 100 + (_vTextIndex * _vTextSpace), *_viTextOut, strlen(*_viTextOut));
		}
		else {
			TextOut(getMemDc(), WINSIZE_X - (_vTextIndex - 50) * 50, 100 + ((_vTextIndex - 50) * _vTextSpace), *_viTextOut, strlen(*_viTextOut));
		}
	}

	TIMEMANAGER->render(getMemDc());
	IMAGEMANAGER->render(getBackBufferKey(), getHdc());
}
