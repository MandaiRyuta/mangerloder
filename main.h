#pragma once

#include <Windows.h>
#include <time.h>
#include <crtdbg.h>
#include <d3dx9.h>
#include <string>

//必要なライブラリファイルのロード
#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")
#ifndef _DEBUG
#pragma comment(lib,"d3dx9d.lib")
#endif
#pragma comment(lib,"Winmm.lib")
#pragma comment(lib,"dinput8.lib")
#pragma comment(lib,"dxguid.lib")
#pragma comment(lib,"XAudio2.lib")

namespace windows_rect
{
	constexpr int D3D_SCREEN_WIDTH = 1800;
	constexpr int D3D_SCREEN_HEIGHT = 1300;
	constexpr int SCREEN_WIDTH = 800;
	constexpr int SCREEN_HEIGHT = 600;
}

#define FVF_VERTEX_2D (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)

namespace TEXTURERS
{
	const std::string BACKGROUND = "haikei227.jpg";
}


LPDIRECT3DDEVICE9 GetDevice(void);