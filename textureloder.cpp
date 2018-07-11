#include "textureloder.h"

typedef std::map<std::string, TEXTUREWRAP> TextureTable;
TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
}

bool TextureManager::Load(std::string key,TEXTURESIZE* texturesize)
{
	//�e�N�X�`���T��
	TextureTable::const_iterator it = m_Texture_.find(key);

	//�T�����Č�����Ȃ������ꍇ�̓e�N�X�`������ǂݍ���
	if (it == m_Texture_.end())
	{
		HRESULT hr = NULL;
		LPDIRECT3DTEXTURE9 pTexture = nullptr;
		hr = D3DXCreateTextureFromFile(
			m_pDevice_,
			key.c_str(),
			&pTexture
		);

		if (FAILED(hr)) {
			MessageBox(NULL, "Texture LoadError", "LoadError!", MB_OK);
			return false;
		}
		TEXTUREWRAP Infomation;
		Infomation.pTexture = pTexture;
		Infomation.size = texturesize;
		m_Texture_.insert(TextureTable::value_type(key, Infomation));
	}
	return true;
}

TEXTUREWRAP TextureManager::GetTexture(std::string key)
{
	TextureTable::const_iterator it = m_Texture_.find(key);
	/*�e�N�X�`���[���������A�e�N�X�`���[�����������ꍇ�͕Ԃ��A������Ȃ��ꍇ�̓}�b�v�֑}������*/
	if (it != m_Texture_.end())
	{
		//�e�N�X�`���[��Ԃ�
		return it->second;
	}
	else
	{
		MessageBox(NULL, "�e�N�X�`����������܂���ł����B", "Texture NONE", MB_OK);
		PostQuitMessage(0);
	}

	return TEXTUREWRAP();
}

bool TextureManager::Release(std::string key)
{
	TextureTable::const_iterator it = m_Texture_.find(key);
	if (it != m_Texture_.end())
	{
		it->second.pTexture->Release();
	}
	else
	{
		MessageBox(NULL, "�e�N�X�`���̉���������ł��܂���ł����B", "Release Error", MB_OK);
		PostQuitMessage(0);
		return false;
	}
	return true;
}

bool TextureManager::AllRelease()
{
	TextureTable::const_iterator it = m_Texture_.begin();
	it->second.pTexture->Release();
	m_Texture_.clear();
	return true;
}

void TextureManager::SetD3DDevice(LPDIRECT3DDEVICE9 device)
{
	this->m_pDevice_ = device;
}
