#include "Stdafx.h"
#include "ProgressBar.h"

/*
ProgressBar::ProgressBar(float x, float y, float width, float height, int maxValue, int currentValue)
	:_x(x),
	_y(y),
	_width(width),
	_height(height),
	_maxValue(maxValue),
	_currentValue(currentValue),
	_isShowing(false)
{
	_img = IMAGEMANAGER->findImage("프로그래스바");
}

ProgressBar::~ProgressBar()
{
}

HRESULT ProgressBar::init()
{
	return S_OK;
}

void ProgressBar::render()
{
	if (!_isShowing) return;
	_img->render(getMemDc(), _x, _y);
	for (int i = 0; i < _currentValue / 10; i++) {
		IMAGEMANAGER->findImage("게이지")->render(getMemDc(), _x + (i * (_img->getWidth() / 10)), _y);
	}
}

void ProgressBar::release()
{
}
*/

HRESULT ProgressBar::init(int x, int y, int width, int height)
{
	_x = x;
	_y = y;

	_rc = RectMakeCenter(_x, _y, width, height);

	_progressBarUp = IMAGEMANAGER->addImage("BarUp", "Resources/Images/Objects/HpBarUp.bmp", 52, 4, width, height, true, RGB(255, 0, 255));
	_progressBarDown = IMAGEMANAGER->addImage("BarDown", "Resources/Images/Objects/HpBarDown.bmp",52, 4, width, height, true, RGB(255, 0, 255));

	_width = _progressBarUp->getWidth();

	return S_OK;
}

void ProgressBar::release(void)
{
}

void ProgressBar::render()
{
	_progressBarDown->render(getMemDc(), _rc.left + _progressBarDown->getWidth() / 2, _y + _progressBarDown->getHeight() / 2, 0, 0, _progressBarDown->getWidth(), _progressBarDown->getHeight());

	_progressBarUp->render(getMemDc(), 
		_rc.left + _progressBarDown->getWidth() / 2,
		_y + _progressBarDown->getHeight() / 2, 
		0, 0, _width, _progressBarDown->getHeight());
}

void ProgressBar::update()
{
	_rc = RectMakeCenter(_x, _y, _progressBarDown->getWidth(), _progressBarDown->getHeight());
}

void ProgressBar::setGauge(float currentScore, float maxScore)
{
	_width = (currentScore / maxScore) * _progressBarDown->getWidth();
}
