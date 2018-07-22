#pragma once
#ifndef _GAME_H_
#define _GAME_H_
#include <windows.h>
#include <d3d9.h>
#include "Global.h"
#include <dinput.h>
class Game
{
public:
	Game();
	~Game();
	Game(int _nCmdShow);
	void InitGame();
	void GameRun();
	void GameEnd();
protected:
	int nCmdShow;
	static LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	int InitWindow(int nCmdShow);
	int InitDirectX();
	void InitKeyboard();
	void ProcessKeyboard();
	
	//Render Image
	void RenderFrame();
	virtual void RenderFrame(LPDIRECT3DDEVICE9 d3ddv, int Delta);
	virtual void LoadResources(LPDIRECT3DDEVICE9 d3ddv);
	//Input Keyboard
	virtual void ProcessInput(LPDIRECT3DDEVICE9 d3ddv, int Delta);
	virtual void OnKeyUp(int KeyCode);
	virtual void OnKeyDown(int KeyCode);
	int IsKeyDown(int KeyCode);
	void GameDraw(int DeltaTime);
	
	DWORD _DeltaTime;
	BYTE _KeyStates[256]; // DirectInput from Keyboard

	DIDEVICEOBJECTDATA _KeyEvents[GL_KEY_BUFFER_SIZE]; //Buffered keyboard data
};

#endif