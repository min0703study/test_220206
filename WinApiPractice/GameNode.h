#pragma once
#define UPDATE_TIMER_ID		1

static string _backBufferKey = "backBuffer";
static Image* _backBuffer = IMAGEMANAGER->addImage(_backBufferKey, WINSIZE_X, WINSIZE_Y);

class GameNode
{
private:
	HDC _hdc;
	bool _managerInit;
public:
	virtual HRESULT init(void);
	virtual HRESULT init(bool managerInit);

	virtual void update(void);
	virtual void release(void);
	virtual void render(void);

	Image* getBackBuffer(void) { return _backBuffer; }
	string getBackBufferKey(void) { return _backBufferKey; }


	HDC getMemDc() { return getBackBuffer()->getMemDC(); }
	HDC getHdc() { return _hdc; }
	
	LRESULT MainProc(HWND, UINT, WPARAM, LPARAM);

	GameNode() {};
	virtual ~GameNode() {};

protected:
	virtual void addTimer(int sec, int timerId);
	virtual void deleteTimer(int timerId);

};

