#pragma once


// PROCDLG ダイアログ

class PROCDLG : public CDialogEx
{
	DECLARE_DYNAMIC(PROCDLG)

public:
	PROCDLG(CWnd* pParent = nullptr);   // 標準コンストラクター
	virtual ~PROCDLG();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROCESS_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()
};
