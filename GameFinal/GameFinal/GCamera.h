﻿#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "Global.h"
#include "GSprite.h"


class GCamera
{
public:
	D3DXVECTOR2 viewport;		//Thiết lập tọa độ của camera	
	int _maxSize, _minSize;

	//Biến bổ sung vào

	///////////////////////////////////////////////////
	float _VCameraX, _VCameraY;//Vận tốc camera = vận tốc của simon(Là khoảng cách dịch chuyển chứ không phải lấy s/t)
	float _FolowPosX;//Tọa độ của simon khi di chuyển
	float _FolowPosY;//Tọa độ của simon khi di chuyển
	void UpdateCamera();
	int GetMaxSize();
	int GetMinSize();
	void SetVCam(float vcamX, float vcamY);
	void SetFolowPos(float x, float y);
	//////////////////////////////////////////////////(Tiền updated)
	GCamera(int x, int State);
	D3DXVECTOR3 CenterSprite(int x, int y);	//Tìm tọa độ center của sprite
	void UpdateCamerax(int x);
	void UpdateCameray(int x);
	void UpdateCamera(int &w, int &h);
	void SetSizeMap(int _max, int _min);
	D3DXVECTOR2 Transform(int x, int y);		//Hàm transform, chuyển tọa độ viewport về tọa độ world
};

#endif