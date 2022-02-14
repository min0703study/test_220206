#include "Stdafx.h"
#include "MainGame.h"

HRESULT MainGame::init(void)
{
	GameNode::init(true);

	IMAGEMANAGER->addImage("background_default", "Resources/Images/Background/background.bmp", WINSIZE_X, WINSIZE_Y);

	_vTextStartX = 0;
	_vTextStartY = 0;

	_vTextSpace = 50;
	_vTextIndex = 0;

	_vTextOut.push_back("��ä�� - �ȳ��ϼ���! ������ ������ ���� �غ���!");
	_vTextOut.push_back("������ - �� ��Ź�帳�ϴ� ~");
	_vTextOut.push_back("����ȣ - 2�ְ� �������ҰԿ� ~");
	_vTextOut.push_back("������ - 2�ְ� ������ ������ �غ��ô�!");
	_vTextOut.push_back("��ä�� - until we die ���� ���ǳ׿�!");
	_vTextOut.push_back("������ - ���˴ϴ� ������ ����");
	_vTextOut.push_back("����ȣ - �������� ��ȹ�� ���ؼ�");
	_vTextOut.push_back("����ȣ - ���Ǹ� �� �غ���");
	_vTextOut.push_back("����ȣ - ����־ȿ� �����Ǹ� ���ٳ���");
	_vTextOut.push_back("������ - �ڵ�� ���̰� DX�� �����̴�!");
	_vTextOut.push_back("������ - untile we die�� �����Դϴ�.");
	_vTextOut.push_back("������ - ������ �̹��� �׸����� �;��....");
	_vTextOut.push_back("��ä�� - ���� �� ���� ���ƿ� �ʹ� ��վ� ������");
	_vTextOut.push_back("��ä�� - �ִϸ��̼� ó���� ����̳׿�");
	_vTextOut.push_back("��ä�� - ��������Ʈ ���ҽ� ���� ������ �Ӹ��� ���Ŀ�");

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
		if (_vTextIndex < 15) {
			TextOut(getMemDc(), _vTextIndex * 80 , 100 + (_vTextIndex * _vTextSpace), *_viTextOut, strlen(*_viTextOut));
		}
		else {
			TextOut(getMemDc(), WINSIZE_X - 200- (_vTextIndex - 15) * 80, 100 + ((_vTextIndex - 15) * _vTextSpace), *_viTextOut, strlen(*_viTextOut));
		}
	}

	TIMEMANAGER->render(getMemDc());
	IMAGEMANAGER->render(getBackBufferKey(), getHdc());
}
