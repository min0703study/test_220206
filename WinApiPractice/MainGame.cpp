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

	_vTextOut.push_back("��ä�� - �ȳ��ϼ���! ������ ������ ���� �غ���!");
	_vTextOut.push_back("������ - �� ��Ź�帳�ϴ� ~");
	_vTextOut.push_back("����ȣ - 2�ְ� �������ҰԿ� ~");

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
