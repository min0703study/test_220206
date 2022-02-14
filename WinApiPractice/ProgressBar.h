#pragma once
#include "GameNode.h"
/*
#include "Image.h"
class ProgressBar: public GameNode
{
private:
	Image* _img;

	float _x;
	float _y;

	float _width;
	float _height;

	float _maxValue;
	float _currentValue;

	bool _isShowing;

	RECT _rc;
public:
	ProgressBar(float x, float y, float width, float height, int maxValue, int currentValue);
	~ProgressBar();

	HRESULT init();
	void render();
	void release();

	void setShowing(bool isShowing) { _isShowing = isShowing; }
	void setValue(int value) { _currentValue = value; }
};*/

class ProgressBar : public GameNode
{
 private:
	Image* _progressBarUp;
	Image* _progressBarDown;

	float _x;
	float _y;

	float _width;
	float _height;

	float _maxValue;
	float _currentValue;

	bool _isShowing;

	RECT _rc;
public:
	ProgressBar() {};
	~ProgressBar() {};

	HRESULT init(int x, int y, int width, int height);
	void release(void);
	void render();
	void update();

	void setX(float x) { _x = x; };
	void setY(float y) { _y = y; };

	void setGauge(float currentScore, float maxScore);
};
