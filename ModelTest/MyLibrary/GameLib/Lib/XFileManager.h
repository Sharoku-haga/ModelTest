﻿/**
* @file		XFileManager.h
* @brief	XFileManagerクラスヘッダ
* @author	haga
*/
#ifndef XFILE_MANAGER_H
#define XFILE_MANAGER_H

#include <d3dx9.h>
#include <map>

class XFile;

/**
* Xファイルを一括で扱うクラス
*/
class XFileManager
{
public:
	/**コンストラクタ*/
	XFileManager();
	/**デストラクタ*/
	~XFileManager();

	/**
	* Xファイルをロードする関数
	* @param[in] key 登録するキー
	* @param[in] pFilePath ファイル名
	*/
	void Load(int key,LPCTSTR pFilePath);

	/**
	* Xファイルを描画する関数
	* @param[in] key 登録したキー
	*/
	void Draw(int key);

	/**
	* Xファイルを解放する関数
	* @param[in] key 登録したキー
	*/
	void Release(int key);

	/**
	* マネージャーが管理しているすべてのファイルを解放する関数
	*/
	void ReleaseALL();

private:
	std::map<int, XFile>  m_xFile;	//!< Xファイルを格納する変数
};

#endif	// XFILE_MANAGER_H

