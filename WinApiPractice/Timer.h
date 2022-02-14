#pragma once

/*
- ������ ����� API ���� �Լ�
GetTickCount()
GetTickCount64()
*/

/*
Timer
- �ð��� �����ϴ� �Լ����� ������ ���� �⺻������ �����찡 ���۵� ���� ���� �ð���  Milli Second ������ ��ȯ
- ���� Ÿ�̸Ӹ� ������ �� �˾Ƶ־� �� ������ �ػ󵵿� Ŭ��

�ػ�?
- �پ��� �ð� �Լ����� �ð��� �����ϱ� ���� �������� Tick �������� �ִ�.
	�� 1���� �������� �󸶳� ���� ���������� ���� �� �ִ����� ���Ѵ�.
- 1�� ���� �󸶳� ����Tick���� ������ �ð��� ��Ȯ���� ���̴��Ŀ� ���� ���ػ󵵿� ���ػ󵵷� ������.

 Clock (������)
 -	Ÿ�̸ӿ��� ����ϴ� Ŭ���� CPU Ŭ��(Clock)�� �ǹ��Ѵ�.
 -	Ŭ�� ��ü�� ������ ȸ���� ������ ���� ���̸� Hz�� ǥ��
	�� 1Hz: 1�ʶ�� �����Ͽ� ��ȣ(0 or 1)�� �� �� �ش�
	   �� 1��Ʈ�� �ѹ� �ű�ٴ� �ǹ�

		i5-8500 CPU @ 3.00GHz	3.00GHz

- 1GHz (10�� ������) ->10���
- 3.00 GHz ->30���
	�� 1�ʿ� 30�ﰳ�� ��Ʈ�� �ű� �� �ִ�.

�� ���� Ÿ�̸��� ��� ���� ��� ��Ű�� ���ؼ��� ��ø�� �ʿ��ϴ�
	�� �뷫 9�󸸺��� 1�ʱ��� ����

- �⺻������ �����ϰ� ����� �� �鸸���� 1�ʱ��� ���� ����
*/

class Timer
{
private:
	float _timeScale;		//����ð� ����
	float _timeElapsed;		//������ �ð��� ����ð��� �����
	bool _isHardware;		//���� Ÿ�̸� ���� ����

	__int64 _curTime;			// ���� �ð�
	__int64 _lastTime;			// ���� �ð�
	__int64 _periodFrequency;	// �ð� �ֱ�

	unsigned long _frameRate;
	unsigned long _FPSFrameCount;
	float _FPSTimeElapsed;
	float _worldTime;
public:
	HRESULT init(void);
	// ���� �ð��� ���
	void tick(float lockFPS = 0.0f);

	// ���� FPS
	unsigned long getFrameRate(char* str = nullptr) const;
	// ������ �ð��� ���� �ð��� �����
	inline float getElapsedTime(void) const { return _timeElapsed; }
	// ��ü ��� �ð�
	inline float getWorldTime(void) const { return _worldTime; }

	Timer() {}
	~Timer() {}
};