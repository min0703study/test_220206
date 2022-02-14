#pragma once
#include "SingletonBase.h"
#include "Image.h"

class Animation;
class ImageManager : public SingletonBase <ImageManager>
{
private:
	//맵으로 만든 이미지 목룍
	typedef map<string, Image*> mapImageList;

	//맵으로 만든 이미지 목록의 반복자
	typedef map<string, Image*>::iterator mapImageIter;;
private:
	mapImageList _mImageList;
public:
	HRESULT init(void);
	void release(void);

	Image* addImage(string strKey, int width, int height);
	Image* addImage(string strKey, const char* fileName, int width, int height, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));//리소스가 아니라 파일맵으로 가져올거야
	Image* addImage(string strKey, const char* fileName, float x, float y, int width, int height, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));
	Image* addFrameImage(string strKey, const char* fileName, int width, int height, int maxFrameX, int maxFrameY, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));
	Image* addFrameImage(string strKey, const char* fileName, float x, float y, int width, int height, int maxFrameX, int maxFrameY, BOOL isTrans = FALSE, COLORREF transColor = RGB(0, 0, 0));
	//이미지 키값으로 찾기
	Image* findImage(string strKey);
	//이미지 키값으로 삭제
	bool deleteImage(string strKey);

	//이미지 전체 삭제
	bool deleteAll();

	//랜더
	void render(string strKey, HDC hdc);
	void render(string strKey, HDC hdc, int destX, int destY);
	void render(string strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);

	//알파 렌더
	void alphaRender(string strKey, HDC hdc, BYTE alpha);      //배경
	void alphaRender(string strKey, HDC hdc, int destX, int destY, BYTE alpha);//배경캐릭더 다
	void alphaRender(string strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha);//클리핑알파렌더

	//프레임 렌더
	void frameRender(string strKey, HDC hdc, int destX, int destY);
	void frameRender(string strKey, HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);

	//루프 렌더
	void loopRender(string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY);
	void loopAlphaRender(string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY, BYTE alpha);
public:
	ImageManager();
	~ImageManager();
};