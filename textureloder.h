#pragma once
#include <string>
#include <map>
#include <d3dx9.h>
struct TEXTURESIZE {
	int width;
	int height;
};
struct TEXTUREWRAP {
	LPDIRECT3DTEXTURE9 pTexture;
	TEXTURESIZE* size;
};
class TextureManager {
public:
	TextureManager();
	~TextureManager();
	//テクスチャー読み込み
	bool Load(std::string key, TEXTURESIZE* textureinfo);
	//テクスチャー取得
	TEXTUREWRAP GetTexture(std::string key);
	//解放
	bool Release(std::string key);
	//全解放
	bool AllRelease();
	//デバイスのポインターを受け取る
	void SetD3DDevice(LPDIRECT3DDEVICE9 device);

private:
	std::map<std::string, TEXTUREWRAP> m_Texture_;
	LPDIRECT3DDEVICE9 m_pDevice_;

};