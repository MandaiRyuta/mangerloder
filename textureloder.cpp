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
	//テクスチャ探索
	TextureTable::const_iterator it = m_Texture_.find(key);

	//探索して見つからなかった場合はテクスチャ情報を読み込む
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
	/*テクスチャーを検索し、テクスチャーが見つかった場合は返す、見つからない場合はマップへ挿入する*/
	if (it != m_Texture_.end())
	{
		//テクスチャーを返す
		return it->second;
	}
	else
	{
		MessageBox(NULL, "テクスチャが見つかりませんでした。", "Texture NONE", MB_OK);
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
		MessageBox(NULL, "テクスチャの解放処理ができませんでした。", "Release Error", MB_OK);
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
