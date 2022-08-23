
// scriptToolDlg.h : ヘッダー ファイル
//

#pragma once

#include "../IMAS.General.Lib/IMAS.General.Lib.Main.h"


// CscriptToolDlg ダイアログ
class CscriptToolDlg : public CDialogEx
{
// コンストラクション
public:
	CscriptToolDlg(CWnd* pParent = nullptr);	// 標準コンストラクター

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SCRIPTTOOL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート


// 実装
protected:
	HICON m_hIcon;
	CBitmap m_hLogoMain;
	LIB_NEW_CORE;
	LIB_NEW_COREIMAGE;
	LIB_NEW_COREUTIL;
	LIB_NEW_INITSTR;
	LIB_NEW_MAINSTR;

	// 生成された、メッセージ割り当て関数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg void OnDestroy();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CStatic m_hReadStatus, m_hFileFullName, m_hFileFullPath;
	CString READ_SCRIPT, READ_SRC, DECODE_PATH, ENCODE_PATH;
	afx_msg void OnBnClickedButtonDecode();
	afx_msg void OnBnClickedButtonEncode();
	afx_msg void OnOpenscript();
	afx_msg void OnOpensrc();
	afx_msg void OnExit();
	afx_msg void OnAbout();
	afx_msg void OnUpdate();
	afx_msg void OnOpenallscript();
	afx_msg void OnOpenallsrc();
	afx_msg void OnBnClickedButtonAllDecode();
	afx_msg void OnBnClickedButtonAllEncode();
};
