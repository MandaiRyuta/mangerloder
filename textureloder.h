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
	//�e�N�X�`���[�ǂݍ���
	bool Load(std::string key, TEXTURESIZE* textureinfo);
	//�e�N�X�`���[�擾
	TEXTUREWRAP GetTexture(std::string key);
	//���
	bool Release(std::string key);
	//�S���
	bool AllRelease();
	//�f�o�C�X�̃|�C���^�[���󂯎��
	void SetD3DDevice(LPDIRECT3DDEVICE9 device);

private:
	std::map<std::string, TEXTUREWRAP> m_Texture_;
	LPDIRECT3DDEVICE9 m_pDevice_;

};