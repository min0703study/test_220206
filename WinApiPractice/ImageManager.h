#pragma once
#include "SingletonBase.h"
#include "Image.h"

class Animation;
class ImageManager : public SingletonBase <ImageManager>
{
private:
	//������ ���� �̹��� ��
	typedef map<string, Image*> mapImageList;

	//������ ���� �̹��� ����� �ݺ���
	typedef map<string, Image*>::iterator mapImageIter;;
private:
	mapImageList _mImageList;
public:
	HRESULT init(void);
	void release(void);

	Image* addImage(string strKey, int width, int height);
	Image* addImage(string strKey, const char* fileName, int width, int height, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));//���ҽ��� �ƴ϶� ���ϸ����� �����ðž�
	Image* addImage(string strKey, const char* fileName, float x, float y, int width, int height, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));
	Image* addFrameImage(string strKey, const char* fileName, int width, int height, int maxFrameX, int maxFrameY, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));
	Image* addFrameImage(string strKey, const char* fileName, float x, float y, int width, int height, int maxFrameX, int maxFrameY, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));
	//�̹��� Ű������ ã��
	Image* findImage(string strKey);
	//�̹��� Ű������ ����
	bool deleteImage(string strKey);

	//�̹��� ��ü ����
	bool deleteAll();

	//����
	void render(string strKey, HDC hdc);
	void render(string strKey, HDC hdc, int destX, int destY);
	void render(string strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);

	//���� ����
	void alphaRender(string strKey, HDC hdc, BYTE alpha);      //���
	void alphaRender(string strKey, HDC hdc, int destX, int destY, BYTE alpha);//���ĳ���� ��
	void alphaRender(string strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha);//Ŭ���ξ��ķ���

	//������ ����
	void frameRender(string strKey, HDC hdc, int destX, int destY);
	void frameRender(string strKey, HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);

	//���� ����
	void loopRender(string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY);
	void loopAlphaRender(string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY, BYTE alpha);
public:
	ImageManager();
	~ImageManager();
};