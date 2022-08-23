// PROCDLG.cpp : 実装ファイル
//

#include "pch.h"
#include "scriptTool.h"
#include "PROCDLG.h"
#include "afxdialogex.h"


// PROCDLG ダイアログ

IMPLEMENT_DYNAMIC(PROCDLG, CDialogEx)

PROCDLG::PROCDLG(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PROCESS_DLG, pParent)
{

}

PROCDLG::~PROCDLG()
{
}

void PROCDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(PROCDLG, CDialogEx)
END_MESSAGE_MAP()


// PROCDLG メッセージ ハンドラー
