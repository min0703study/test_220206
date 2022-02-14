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

	_vTextOut.push_back("민채영 - 안녕하세요! 팀포폴 열심히 같이 해봐요!");
	_vTextOut.push_back("임지혁 - 잘 부탁드립니다 ~");
	_vTextOut.push_back("박정호 - 2주간 열심히할게요 ~");
	_vTextOut.push_back("김현석 - 2주간 팀포폴 열심히 해봅시다!");
	_vTextOut.push_back("민채영 - until we die 게임 기대되네요!");
	_vTextOut.push_back("임지혁 - 기대됩니다 불지옥 여행");
	_vTextOut.push_back("박정호 - 앞으로의 계획에 대해서");
	_vTextOut.push_back("박정호 - 상의를 좀 해보고");
	_vTextOut.push_back("박정호 - 요번주안에 결정되면 좋겟내여");
	_vTextOut.push_back("김현석 - 코드는 신이고 DX는 무적이다!");
	_vTextOut.push_back("김현석 - untile we die는 갓겜입니다.");
	_vTextOut.push_back("김현석 - 프레임 이미지 그만쓰고 싶어요....");
	_vTextOut.push_back("민채영 - 게임 잘 고른거 같아요 너무 재밌어 보여요");
	_vTextOut.push_back("민채영 - 애니메이션 처리가 고민이네요");
	_vTextOut.push_back("민채영 - 스프라이트 리소스 보고 있으면 머리가 아파요");

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
