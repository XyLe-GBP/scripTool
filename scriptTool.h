
// scriptTool.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'pch.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CscriptToolApp:
// このクラスの実装については、scriptTool.cpp を参照してください
//

class CscriptToolApp : public CWinApp
{
public:
	CscriptToolApp();

// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CscriptToolApp theApp;
