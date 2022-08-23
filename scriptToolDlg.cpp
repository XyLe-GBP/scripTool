
// scriptToolDlg.cpp : 実装ファイル
//
//#pragma warning(disable:4996)

#include "pch.h"
#include "framework.h"
#include "scriptTool.h"
#include "scriptToolDlg.h"
#include "afxdialogex.h"
#include <random>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "WAITDIALOG.h"
#include "PROCDLG.h"



// アプリケーションのバージョン情報に使われる CAboutDlg ダイアログ

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	virtual HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	virtual BOOL OnInitDialog();

// 実装
protected:
	LIB_NEW_CORE;
	LIB_NEW_COREIMAGE;
	LIB_NEW_VERSIONSTR;
	DECLARE_MESSAGE_MAP()
public:
	CStatic m_hVERSION, m_hHYPER1, m_hHYPER2, ICON;
	COLORREF m_hyperlink;
	CFont m_hlfont;
	afx_msg void OnStnClickedStaticHyper1();
	afx_msg void OnStnClickedStaticHyper2();
	afx_msg void OnStnClickedStaticIcon();
	afx_msg void OnDestroy();
	afx_msg void OnNMClickSyslink1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnNMClickSyslink2(NMHDR* pNMHDR, LRESULT* pResult);
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
	m_hyperlink = NULL;
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_VERSION, m_hVERSION);
	DDX_Control(pDX, IDC_STATIC_HYPER1, m_hHYPER1);
	DDX_Control(pDX, IDC_STATIC_HYPER2, m_hHYPER2);
	DDX_Control(pDX, IDC_STATIC_ICON, ICON);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_CTLCOLOR()
	ON_WM_SETCURSOR()
	ON_WM_DESTROY()
	ON_STN_CLICKED(IDC_STATIC_HYPER1, &CAboutDlg::OnStnClickedStaticHyper1)
	ON_STN_CLICKED(IDC_STATIC_HYPER2, &CAboutDlg::OnStnClickedStaticHyper2)
	ON_STN_CLICKED(IDC_STATIC_ICON, &CAboutDlg::OnStnClickedStaticIcon)
END_MESSAGE_MAP()


BOOL CAboutDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	LIB_CORE->LoadImageLibrary();

	this->m_hVERSION.SetWindowText(SCRIPTOOL_VER);
	m_hyperlink = RGB(0, 0, 255);
	CFont* pFont = m_hHYPER1.GetFont();
	LOGFONT lFont;
	pFont->GetLogFont(&lFont);
	lFont.lfUnderline = (TRUE);
	m_hlfont.CreateFontIndirect(&lFont);
	m_hHYPER1.SetFont(&m_hlfont, TRUE);
	m_hHYPER2.SetFont(&m_hlfont, TRUE);

	LOGO_MAIN.Attach((HBITMAP)::LoadBitmap(LIB_CORE->hinst, MAKEINTRESOURCE(101)));
	LOGO_PROJECTIMAS.Attach((HBITMAP)::LoadBitmap(LIB_CORE->hinst, MAKEINTRESOURCE(102)));

	CStatic* boxsub = (CStatic*)GetDlgItem(IDC_STATIC_LOGOIMG1);
	CStatic* boxmain = (CStatic*)GetDlgItem(IDC_STATIC_LOGOIMG2);
	boxmain->SetBitmap(LOGO_MAIN);
	boxmain->InvalidateRect(NULL, 1);
	boxsub->SetBitmap(LOGO_PROJECTIMAS);
	boxsub->InvalidateRect(NULL, 1);

	return TRUE;
}


BOOL CAboutDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	if (pWnd == &this->m_hHYPER1)
	{
		CURSOR_CUR = LoadCursor(LIB_CORE->hinst, MAKEINTRESOURCE(108));
		::SetCursor(CURSOR_CUR);
		return TRUE;
	}
	if (pWnd == &this->m_hHYPER2)
	{
		CURSOR_CUR = LoadCursor(LIB_CORE->hinst, MAKEINTRESOURCE(108));
		::SetCursor(CURSOR_CUR);
		return TRUE;
	}
	if (pWnd == &this->ICON)
	{
		CURSOR_CUR = LoadCursor(LIB_CORE->hinst, MAKEINTRESOURCE(108));
		::SetCursor(CURSOR_CUR);
		return TRUE;
	}
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}

HBRUSH CAboutDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	if (pWnd == &this->m_hHYPER1) {
		pDC->SetTextColor(m_hyperlink);
	}
	if (pWnd == &this->m_hHYPER2) {
		pDC->SetTextColor(m_hyperlink);
	}
	return hbr;
}


void CAboutDlg::OnStnClickedStaticHyper1()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	ShellExecute(NULL, _T("open"), _T("https://xyle-official.com"), NULL, NULL, SW_SHOWNORMAL);
}


void CAboutDlg::OnStnClickedStaticHyper2()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	ShellExecute(NULL, _T("open"), _T("https://imas.arc.xyle-official.com/main/tools/sp_scriptool"), NULL, NULL, SW_SHOWNORMAL);
}


void CAboutDlg::OnStnClickedStaticIcon()
{
	random_device rnd;
	UINT RND = rnd();
	if (RND < 0x7FFFFFFF) {
		if (RND <= 0x3B9AC9FF) {
			PlaySound(MAKEINTRESOURCE(110), LIB_CORE->hinst, SND_RESOURCE | SND_ASYNC);
			MessageBox(_T("ドームですよっ！ドームっ！"), _T(""), MB_ICONMASK | MB_OK);
			return;
		}
		else {
			PlaySound(MAKEINTRESOURCE(113), LIB_CORE->hinst, SND_RESOURCE | SND_ASYNC);
			MessageBox(_T("プロデューサーさんっ！悪用厳禁ですよっ、悪用厳禁っ！"), _T(""), MB_ICONMASK | MB_OK);
			return;
		}
	}
	if (RND > 0x80000000) {
		if (RND > 0xA0000000) {
			PlaySound(MAKEINTRESOURCE(109), LIB_CORE->hinst, SND_RESOURCE | SND_ASYNC);
			MessageBox(_T("えっ？だっ、誰？"), _T(""), MB_ICONMASK | MB_OK);
			return;
		}
		else {
			PlaySound(MAKEINTRESOURCE(113), LIB_CORE->hinst, SND_RESOURCE | SND_ASYNC);
			MessageBox(_T("プロデューサーさんっ！ツールですよっ、ツールっ！"), _T(""), MB_ICONMASK | MB_OK);
			return;
		}
	}
}


void CAboutDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: ここにメッセージ ハンドラー コードを追加します。
	OutputDebugString(_T("OnDestroy\n"));
	LIB_FREE_LIB;
	LIB_DEL_CORE;
	LOGO_MAIN.Detach();
	LOGO_PROJECTIMAS.Detach();
	LIB_DEL_COREIMAGE;
	LIB_DEL_VERSIONSTR;
}
// CscriptToolDlg ダイアログ



CscriptToolDlg::CscriptToolDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SCRIPTTOOL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CscriptToolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_STATUS, m_hReadStatus);
	DDX_Control(pDX, IDC_STATIC_NAME, m_hFileFullName);
	DDX_Control(pDX, IDC_STATIC_PATH, m_hFileFullPath);
}

BEGIN_MESSAGE_MAP(CscriptToolDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON_DECODE, &CscriptToolDlg::OnBnClickedButtonDecode)
	ON_BN_CLICKED(IDC_BUTTON_ENCODE, &CscriptToolDlg::OnBnClickedButtonEncode)
	ON_COMMAND(ID_OpenScript, &CscriptToolDlg::OnOpenscript)
	ON_COMMAND(ID_OpenSrc, &CscriptToolDlg::OnOpensrc)
	ON_COMMAND(ID_32772, &CscriptToolDlg::OnExit)
	ON_COMMAND(ID_ABOUT_ABOUTSCRIPTOOL, &CscriptToolDlg::OnAbout)
	ON_COMMAND(ID_UPDATE, &CscriptToolDlg::OnUpdate)
	ON_COMMAND(ID_OpenALLScript, &CscriptToolDlg::OnOpenallscript)
	ON_COMMAND(ID_OpenALLSrc, &CscriptToolDlg::OnOpenallsrc)
	ON_BN_CLICKED(IDC_BUTTON_ALL_DECODE, &CscriptToolDlg::OnBnClickedButtonAllDecode)
	ON_BN_CLICKED(IDC_BUTTON_ALL_ENCODE, &CscriptToolDlg::OnBnClickedButtonAllEncode)
END_MESSAGE_MAP()


// CscriptToolDlg メッセージ ハンドラー

BOOL CscriptToolDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// "バージョン情報..." メニューをシステム メニューに追加します。

	// IDM_ABOUTBOX は、システム コマンドの範囲内になければなりません。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。
	OutputDebugString(_T("OnInitDialog\n"));

	LIB_CORE->LoadImageLibrary();
	LIB_COREUTIL->checkExistenceOfFolder(".\\Resources");
	LIB_CORE->SCRIPTOOL_LoadResource();

	CFileFind init;

	OutputDebugString(_T("Initializing...\n"));
	OutputDebugString(_T("Checking if perl is installed...\n"));
	if (init.FindFile(PERL_DIR)) {
		OutputDebugString(_T("Perl is installed in the following directory: ( ") + PERL_DIR + _T(" )\n"));
		OutputDebugString(_T("Checking if the script exists...\n"));
		if (init.FindFile(DECODE_SCRIPT)) {
			OutputDebugString(_T("Decode script found: ( ") + DECODE_SCRIPT + _T(" )\n"));
			if (init.FindFile(ENCODE_SCRIPT)) {
				OutputDebugString(_T("Encode script found: ( ") + ENCODE_SCRIPT + _T(" )\n"));
				if (init.FindFile(STRING_SCRIPT)) {
					OutputDebugString(_T("String script found: ( ") + STRING_SCRIPT + _T(" )\n"));
					if (init.FindFile(UTILS_SCRIPT)) {
						OutputDebugString(_T("Utils script found: ( ") + UTILS_SCRIPT + _T(" )\n"));
						OutputDebugString(_T("All initialization is complete!\n"));
						CStatic* STATIC_IMG = (CStatic*)GetDlgItem(IDC_STATIC_IMG);
						LOGO_MAIN.Attach((HBITMAP)::LoadBitmap(LIB_CORE->hinst, MAKEINTRESOURCE(101)));
						STATIC_IMG->SetBitmap(LOGO_MAIN);
						STATIC_IMG->InvalidateRect(NULL, 1);
						return TRUE;
					}
					else {
						OutputDebugString(_T("Error! utils script not found. \n"));
						AfxGetMainWnd()->DestroyWindow();
					}
				}
				else {
					OutputDebugString(_T("Error! string script not found. \n"));
					AfxGetMainWnd()->DestroyWindow();
				}
			}
			else {
				OutputDebugString(_T("Error! encode script not found. \n"));
				AfxGetMainWnd()->DestroyWindow();
			}
		}
		else {
			OutputDebugString(_T("Error! decode script not found. \n"));
			AfxGetMainWnd()->DestroyWindow();
		}
	}
	else {
		OutputDebugString(_T("Error! perl is not installed. \n"));
		AfxGetMainWnd()->DestroyWindow();
	}

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

void CscriptToolDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CscriptToolDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// クライアントの四角形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンの描画
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ユーザーが最小化したウィンドウをドラッグしているときに表示するカーソルを取得するために、
//  システムがこの関数を呼び出します。
HCURSOR CscriptToolDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CAboutDlg::OnNMClickSyslink1(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	ShellExecute(NULL, _T("open"), _T("https://xyle-official.com/"), NULL, NULL, SW_SHOWNORMAL);
	*pResult = 0;
}


void CAboutDlg::OnNMClickSyslink2(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	ShellExecute(NULL, _T("open"), _T("https://imas.arc.xyle-official.com/main/tools/sp_scriptool/"), NULL, NULL, SW_SHOWNORMAL);
	*pResult = 0;
}


void CscriptToolDlg::OnBnClickedButtonDecode()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	OutputDebugString(_T("OnBnClickedButtonDecode\n"));

	CFileFind find;
	CButton* BUTTON_DECODE = (CButton*)GetDlgItem(IDC_BUTTON_DECODE);
	CButton* BUTTON_ENCODE = (CButton*)GetDlgItem(IDC_BUTTON_ENCODE);

	if (READ_SCRIPT.GetLength() == 0)
	{
		MessageBox(_T("ファイルが選択されていません。"), _T("エラー"), MB_ICONERROR | MB_OK);
		this->m_hReadStatus.SetWindowText(DEFAULTTEXT);
		this->m_hFileFullName.SetWindowText(DEFAULTTEXT);
		this->m_hFileFullPath.SetWindowText(DEFAULTTEXT);
		BUTTON_DECODE->EnableWindow(FALSE);
		BUTTON_ENCODE->EnableWindow(FALSE);
		READ_SCRIPT.Empty();
		DECODE_PATH.Empty();
	}
	else if (READ_SCRIPT.GetLength() > MAX_PATH)
	{
		MessageBox(_T("ファイルへのパスが長すぎます。"), _T("エラー"), MB_ICONERROR | MB_OK);
		this->m_hReadStatus.SetWindowText(DEFAULTTEXT);
		this->m_hFileFullName.SetWindowText(DEFAULTTEXT);
		this->m_hFileFullPath.SetWindowText(DEFAULTTEXT);
		BUTTON_DECODE->EnableWindow(FALSE);
		BUTTON_ENCODE->EnableWindow(FALSE);
		READ_SCRIPT.Empty();
		DECODE_PATH.Empty();
	}
	else {
		if (find.FindFile(DECODE_SCRIPT)) {
			TCHAR crDir[MAX_PATH + 1];
			GetCurrentDirectory(MAX_PATH + 1, crDir);
			wchar_t Drive[10] = { NULL }, Dir[MAX_PATH] = { NULL }, Name[MAX_PATH] = { NULL }, Ext[MAX_PATH] = { NULL };
			wchar_t Drive2[10] = { NULL }, Dir2[MAX_PATH] = { NULL }, Name2[MAX_PATH] = { NULL }, Ext2[MAX_PATH] = { NULL };
			CString DRIVE, DIR, NAME, EXT, FNAME;
			CString DRIVE2, DIR2, NAME2, EXT2;

			FNAME = READ_SCRIPT.Right(READ_SCRIPT.GetLength() - READ_SCRIPT.ReverseFind(_T('\\')) - 1);
			FNAME = FNAME.Left(FNAME.ReverseFind(_T('.')));
			CString filter("SRC ファイル (*.src)|*.src;||");
			CFileDialog selDlg(FALSE, _T("src"), FNAME, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST, filter, this);
			INT_PTR ret = selDlg.DoModal();
			if (ret == IDOK) {
				DECODE_PATH = selDlg.GetPathName();
				if (!DECODE_PATH) {
					MessageBox(_T("不明なエラーが発生しました"), _T("エラー"), MB_ICONERROR | MB_OK);
					this->m_hReadStatus.SetWindowText(DEFAULTTEXT);
					this->m_hFileFullName.SetWindowText(DEFAULTTEXT);
					this->m_hFileFullPath.SetWindowText(DEFAULTTEXT);
					BUTTON_DECODE->EnableWindow(FALSE);
					BUTTON_ENCODE->EnableWindow(FALSE);
					READ_SCRIPT.Empty();
					DECODE_PATH.Empty();
					return;
				}
				_tsplitpath_s(READ_SCRIPT, Drive, Dir, Name, Ext);
				_tsplitpath_s(DECODE_PATH, Drive2, Dir2, Name2, Ext2);
				DRIVE = Drive, DIR = Dir, NAME = Name, EXT = Ext;
				DRIVE2 = Drive2, DIR2 = Dir2, NAME2 = Name2, EXT2 = Ext2;
				CString SRCOUTFULLPATH = DRIVE2 + DIR2 + NAME2 + _T(".src");
				CString TXTOUTFULLPATH = DRIVE2 + DIR2 + NAME2 + _T(".txt");
				CString lpPath = _T("perl ") + DECODE_SCRIPT + _T(" ") + READ_SCRIPT;

				if (find.FindFile(DRIVE2 + DIR2 + NAME2 + _T(".src"))) {
					OutputDebugString(_T("File: ( ") + DRIVE2 + DIR2 + NAME2 + _T(".src ) Found.\n"));
					DeleteFile(DRIVE2 + DIR2 + NAME2 + _T(".src"));
				}
				if (find.FindFile(DRIVE2 + DIR2 + NAME2 + _T(".txt"))) {
					OutputDebugString(_T("File: ( ") + DRIVE2 + DIR2 + NAME2 + _T(".txt ) Found.\n"));
					DeleteFile(DRIVE2 + DIR2 + NAME2 + _T(".txt"));
				}

				TCHAR* lpPathT = (TCHAR*)malloc(sizeof(TCHAR) * 512); // Convert CString to TCHAR.
				if (NULL == lpPathT) {
					perror("can not malloc");
					OutputDebugString(_T("TCHAR syntax (lpPath) malloc failed.\n"));
					return;
				}
				else {
					ZeroMemory(&lpPathT[0], 512);
					_tcscpy_s(&lpPathT[0], 512, lpPath);
				}
				WAITDIALOG* waitDlg = new WAITDIALOG;

				AfxGetMainWnd()->EnableWindow(FALSE);
				waitDlg->Create(IDD_DIALOG1);
				waitDlg->ShowWindow(SW_SHOW);

				STARTUPINFO si;
				memset(&si, 0, sizeof(STARTUPINFO));
				PROCESS_INFORMATION pi;
				memset(&pi, 0, sizeof(PROCESS_INFORMATION));
				si.dwFlags = STARTF_USESHOWWINDOW;
				si.wShowWindow = SW_HIDE;
				::CreateProcess(NULL, lpPathT, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
				CloseHandle(pi.hThread);	// CloseHandleでhThreadを閉じる.
				MSG msg;
				while (::PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE)) {
					if (!AfxGetApp()->PumpMessage())
					{
						::PostQuitMessage(0);
						break;
					}
				}
				WaitForSingleObject(pi.hProcess, INFINITE);
				CloseHandle(pi.hProcess);
				free(lpPathT);

				waitDlg->DestroyWindow();
				AfxGetMainWnd()->EnableWindow(TRUE);
				delete waitDlg;

				if (find.FindFile(DRIVE + DIR + NAME + _T(".src"))) {
					OutputDebugString(_T("File: ( ") + DRIVE + DIR + NAME + _T(".src ) Found.\n"));
					MoveFile(DRIVE + DIR + NAME + _T(".src"), SRCOUTFULLPATH);
				}
				else {
					OutputDebugString(_T("File: ( ") + DRIVE + DIR + NAME + _T(".src ) Not found.\n"));
					MessageBox(_T("デコードに失敗しました。"), _T("エラー"), MB_ICONERROR | MB_OK);
					this->m_hReadStatus.SetWindowText(DEFAULTTEXT);
					this->m_hFileFullName.SetWindowText(DEFAULTTEXT);
					this->m_hFileFullPath.SetWindowText(DEFAULTTEXT);
					BUTTON_DECODE->EnableWindow(FALSE);
					BUTTON_ENCODE->EnableWindow(FALSE);
					READ_SCRIPT.Empty();
					DECODE_PATH.Empty();
					return;
				}
				if (find.FindFile(DRIVE + DIR + NAME + _T(".txt"))) {
					OutputDebugString(_T("File: ( ") + DRIVE + DIR + NAME + _T(".txt ) Found.\n"));
					MoveFile(DRIVE + DIR + NAME + _T(".txt"), TXTOUTFULLPATH);
				}
				else {
					OutputDebugString(_T("File: ( ") + DRIVE + DIR + NAME + _T(".txt ) Not found.\n"));
					MessageBox(_T("デコードに失敗しました。"), _T("エラー"), MB_ICONERROR | MB_OK);
					this->m_hReadStatus.SetWindowText(DEFAULTTEXT);
					this->m_hFileFullName.SetWindowText(DEFAULTTEXT);
					this->m_hFileFullPath.SetWindowText(DEFAULTTEXT);
					BUTTON_DECODE->EnableWindow(FALSE);
					BUTTON_ENCODE->EnableWindow(FALSE);
					READ_SCRIPT.Empty();
					DECODE_PATH.Empty();
					return;
				}

				if (find.FindFile(SRCOUTFULLPATH)) {
					OutputDebugString(_T("File: ( ") + SRCOUTFULLPATH + _T(" ) Found.\n"));
					if (find.FindFile(TXTOUTFULLPATH)) {
						OutputDebugString(_T("File: ( ") + TXTOUTFULLPATH + _T(" ) Found.\n"));
						OutputDebugString(_T("Decoded.\n"));
						MessageBox(_T("デコード完了"), _T("完了"), MB_ICONINFORMATION | MB_OK);
						ShellExecute(NULL, _T("open"), DRIVE2 + DIR2, NULL, NULL, SW_SHOWNORMAL);
						this->m_hReadStatus.SetWindowText(DEFAULTTEXT);
						this->m_hFileFullName.SetWindowText(DEFAULTTEXT);
						this->m_hFileFullPath.SetWindowText(DEFAULTTEXT);
						BUTTON_DECODE->EnableWindow(FALSE);
						BUTTON_ENCODE->EnableWindow(FALSE);
						READ_SCRIPT.Empty();
						DECODE_PATH.Empty();
						return;
					}
					else {
						OutputDebugString(_T("Warning: file: ( ") + TXTOUTFULLPATH + _T(" ) Not found.\n"));
						OutputDebugString(_T("Warning: Some files could not be decoded.\n"));
						OutputDebugString(_T("Partially decoded.\n"));
						MessageBox(_T("一部のファイルのデコードに失敗しました。"), _T("警告"), MB_ICONWARNING | MB_OK);
						ShellExecute(NULL, _T("open"), DRIVE2 + DIR2, NULL, NULL, SW_SHOWNORMAL);
						this->m_hReadStatus.SetWindowText(DEFAULTTEXT);
						this->m_hFileFullName.SetWindowText(DEFAULTTEXT);
						this->m_hFileFullPath.SetWindowText(DEFAULTTEXT);
						BUTTON_DECODE->EnableWindow(FALSE);
						BUTTON_ENCODE->EnableWindow(FALSE);
						READ_SCRIPT.Empty();
						DECODE_PATH.Empty();
						return;
					}
				}
				else if (find.FindFile(TXTOUTFULLPATH)) {
					OutputDebugString(_T("Warning: file: ( ") + SRCOUTFULLPATH + _T(" ) Not found.\n"));
					OutputDebugString(_T("File: ( ") + TXTOUTFULLPATH + _T(" ) Found.\n"));
					OutputDebugString(_T("Warning: Some files could not be decoded.\n"));
					OutputDebugString(_T("Partially decoded.\n"));
					MessageBox(_T("一部のファイルのデコードに失敗しました。"), _T("警告"), MB_ICONWARNING | MB_OK);
					ShellExecute(NULL, _T("open"), DRIVE2 + DIR2, NULL, NULL, SW_SHOWNORMAL);
					this->m_hReadStatus.SetWindowText(DEFAULTTEXT);
					this->m_hFileFullName.SetWindowText(DEFAULTTEXT);
					this->m_hFileFullPath.SetWindowText(DEFAULTTEXT);
					BUTTON_DECODE->EnableWindow(FALSE);
					BUTTON_ENCODE->EnableWindow(FALSE);
					READ_SCRIPT.Empty();
					DECODE_PATH.Empty();
					return;
				}
				else {
					OutputDebugString(_T("Warning: file: ( ") + SRCOUTFULLPATH + _T(" ) Not found.\n"));
					OutputDebugString(_T("Warning: file: ( ") + TXTOUTFULLPATH + _T(" ) Not found.\n"));
					OutputDebugString(_T("Error! script decode failed.\n"));
					MessageBox(_T("デコードに失敗しました。"), _T("エラー"), MB_ICONERROR | MB_OK);
					this->m_hReadStatus.SetWindowText(DEFAULTTEXT);
					this->m_hFileFullName.SetWindowText(DEFAULTTEXT);
					this->m_hFileFullPath.SetWindowText(DEFAULTTEXT);
					BUTTON_DECODE->EnableWindow(FALSE);
					BUTTON_ENCODE->EnableWindow(FALSE);
					READ_SCRIPT.Empty();
					DECODE_PATH.Empty();
					return;
				}
			}
			else if (ret == IDCANCEL) {
				OutputDebugString(_T("Was canceled.\n"));
				MessageBox(_T("キャンセルされました。"), _T("キャンセル"), MB_ICONWARNING | MB_OK);
				this->m_hReadStatus.SetWindowText(DEFAULTTEXT);
				this->m_hFileFullName.SetWindowText(DEFAULTTEXT);
				this->m_hFileFullPath.SetWindowText(DEFAULTTEXT);
				BUTTON_DECODE->EnableWindow(FALSE);
				BUTTON_ENCODE->EnableWindow(FALSE);
				READ_SCRIPT.Empty();
				DECODE_PATH.Empty();
				return;
			}
			else {
				OutputDebugString(_T("Exception occured.\n"));
				this->m_hReadStatus.SetWindowText(DEFAULTTEXT);
				this->m_hFileFullName.SetWindowText(DEFAULTTEXT);
				this->m_hFileFullPath.SetWindowText(DEFAULTTEXT);
				BUTTON_DECODE->EnableWindow(FALSE);
				BUTTON_ENCODE->EnableWindow(FALSE);
				READ_SCRIPT.Empty();
				DECODE_PATH.Empty();
				return;
			}
		}
		else {
			OutputDebugString(_T("Error! perl script: ( ") + DECODE_SCRIPT + _T(" ) Not found."));
			MessageBox(_T("実行可能ファイルが見つかりません。"), _T("エラー"), MB_ICONERROR | MB_OK);
			this->m_hReadStatus.SetWindowText(DEFAULTTEXT);
			this->m_hFileFullName.SetWindowText(DEFAULTTEXT);
			this->m_hFileFullPath.SetWindowText(DEFAULTTEXT);
			BUTTON_DECODE->EnableWindow(FALSE);
			BUTTON_ENCODE->EnableWindow(FALSE);
			READ_SCRIPT.Empty();
			DECODE_PATH.Empty();
			return;
		}
	}
}


void CscriptToolDlg::OnBnClickedButtonEncode()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	OutputDebugString(_T("OnBnClickedButtonEncode\n"));

	CFileFind find;
	CButton* BUTTON_DECODE = (CButton*)GetDlgItem(IDC_BUTTON_DECODE);
	CButton* BUTTON_ENCODE = (CButton*)GetDlgItem(IDC_BUTTON_ENCODE);

	if (READ_SRC.GetLength() == 0)
	{
		MessageBox(_T("ファイルが選択されていません。"), _T("エラー"), MB_ICONERROR | MB_OK);
		this->m_hReadStatus.SetWindowText(DEFAULTTEXT);
		this->m_hFileFullName.SetWindowText(DEFAULTTEXT);
		this->m_hFileFullPath.SetWindowText(DEFAULTTEXT);
		BUTTON_DECODE->EnableWindow(FALSE);
		BUTTON_ENCODE->EnableWindow(FALSE);
		READ_SRC.Empty();
		ENCODE_PATH.Empty();
	}
	else if (READ_SRC.GetLength() > MAX_PATH)
	{
		MessageBox(_T("ファイルへのパスが長すぎます。"), _T("エラー"), MB_ICONERROR | MB_OK);
		this->m_hReadStatus.SetWindowText(DEFAULTTEXT);
		this->m_hFileFullName.SetWindowText(DEFAULTTEXT);
		this->m_hFileFullPath.SetWindowText(DEFAULTTEXT);
		BUTTON_DECODE->EnableWindow(FALSE);
		BUTTON_ENCODE->EnableWindow(FALSE);
		READ_SRC.Empty();
		ENCODE_PATH.Empty();
	}
	else {
		if (find.FindFile(ENCODE_SCRIPT)) {
			TCHAR crDir[MAX_PATH + 1];
			GetCurrentDirectory(MAX_PATH + 1, crDir);
			wchar_t Drive[10] = { NULL }, Dir[MAX_PATH] = { NULL }, Name[MAX_PATH] = { NULL }, Ext[MAX_PATH] = { NULL };
			wchar_t Drive2[10] = { NULL }, Dir2[MAX_PATH] = { NULL }, Name2[MAX_PATH] = { NULL }, Ext2[MAX_PATH] = { NULL };
			CString DRIVE, DIR, NAME, EXT, FNAME;
			CString DRIVE2, DIR2, NAME2, EXT2;

			FNAME = READ_SRC.Right(READ_SRC.GetLength() - READ_SRC.ReverseFind(_T('\\')) - 1);
			FNAME = FNAME.Left(FNAME.ReverseFind(_T('.')));
			CString filter("アイマスSP スクリプトファイル (*.script)|*.script;||");
			CFileDialog selDlg(FALSE, _T("script"), FNAME, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST, filter, this);
			INT_PTR ret = selDlg.DoModal();
			if (ret == IDOK) {
				ENCODE_PATH = selDlg.GetPathName();
				if (!ENCODE_PATH) {
					MessageBox(_T("不明なエラーが発生しました"), _T("エラー"), MB_ICONERROR | MB_OK);
					this->m_hReadStatus.SetWindowText(DEFAULTTEXT);
					this->m_hFileFullName.SetWindowText(DEFAULTTEXT);
					this->m_hFileFullPath.SetWindowText(DEFAULTTEXT);
					BUTTON_DECODE->EnableWindow(FALSE);
					BUTTON_ENCODE->EnableWindow(FALSE);
					READ_SRC.Empty();
					ENCODE_PATH.Empty();
					return;
				}
				_tsplitpath_s(READ_SRC, Drive, Dir, Name, Ext);
				_tsplitpath_s(ENCODE_PATH, Drive2, Dir2, Name2, Ext2);
				DRIVE = Drive, DIR = Dir, NAME = Name, EXT = Ext;
				DRIVE2 = Drive2, DIR2 = Dir2, NAME2 = Name2, EXT2 = Ext2;
				CString TXTFULLPATH = DRIVE + DIR + NAME + _T(".txt");
				if (find.FindFile(TXTFULLPATH)) {
					OutputDebugString(_T("Script text file: ( ") + TXTFULLPATH + _T(" ) Found.\n"));
					CString lpPath = _T("perl ") + ENCODE_SCRIPT + _T(" ") + DRIVE + DIR + NAME + _T(".script");

					if (find.FindFile(DRIVE2 + DIR2 + NAME2 + _T(".script"))) {
						OutputDebugString(_T("File: ( ") + DRIVE2 + DIR2 + NAME2 + _T(".script ) Found.\n"));
						DeleteFile(DRIVE2 + DIR2 + NAME2 + _T(".script"));
					}

					TCHAR* lpPathT = (TCHAR*)malloc(sizeof(TCHAR) * 512); // Convert CString to TCHAR.
					if (NULL == lpPathT) {
						perror("can not malloc");
						OutputDebugString(_T("TCHAR syntax (lpPath) malloc failed.\n"));
						return;
					}
					else {
						ZeroMemory(&lpPathT[0], 512);
						_tcscpy_s(&lpPathT[0], 512, lpPath);
					}
					WAITDIALOG* waitDlg = new WAITDIALOG;

					AfxGetMainWnd()->EnableWindow(FALSE);
					waitDlg->Create(IDD_DIALOG1);
					waitDlg->ShowWindow(SW_SHOW);

					STARTUPINFO si;
					memset(&si, 0, sizeof(STARTUPINFO));
					PROCESS_INFORMATION pi;
					memset(&pi, 0, sizeof(PROCESS_INFORMATION));
					si.dwFlags = STARTF_USESHOWWINDOW;
					si.wShowWindow = SW_HIDE;
					::CreateProcess(NULL, lpPathT, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
					CloseHandle(pi.hThread);	// CloseHandleでhThreadを閉じる.
					MSG msg;
					while (::PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE)) {
						if (!AfxGetApp()->PumpMessage())
						{
							::PostQuitMessage(0);
							break;
						}
					}
					WaitForSingleObject(pi.hProcess, INFINITE);
					CloseHandle(pi.hProcess);
					free(lpPathT);

					waitDlg->DestroyWindow();
					AfxGetMainWnd()->EnableWindow(TRUE);
					delete waitDlg;

					if (find.FindFile(DRIVE + DIR + NAME + _T(".script"))) {
						OutputDebugString(_T("File: ( ") + DRIVE + DIR + NAME + _T(".script ) Found.\n"));
						MoveFile(DRIVE + DIR + NAME + _T(".script"), ENCODE_PATH);
					}
					else {
						OutputDebugString(_T("File: ( ") + DRIVE + DIR + NAME + _T(".script ) Not found.\n"));
						MessageBox(_T("エンコードに失敗しました。"), _T("エラー"), MB_ICONERROR | MB_OK);
						this->m_hReadStatus.SetWindowText(DEFAULTTEXT);
						this->m_hFileFullName.SetWindowText(DEFAULTTEXT);
						this->m_hFileFullPath.SetWindowText(DEFAULTTEXT);
						BUTTON_DECODE->EnableWindow(FALSE);
						BUTTON_ENCODE->EnableWindow(FALSE);
						READ_SRC.Empty();
						ENCODE_PATH.Empty();
						return;
					}

					if (find.FindFile(ENCODE_PATH)) {
						OutputDebugString(_T("File: ( ") + ENCODE_PATH + _T(" ) Found.\n"));
						OutputDebugString(_T("Encoded.\n"));
						MessageBox(_T("エンコード完了"), _T("完了"), MB_ICONINFORMATION | MB_OK);
						ShellExecute(NULL, _T("open"), DRIVE2 + DIR2, NULL, NULL, SW_SHOWNORMAL);
						this->m_hReadStatus.SetWindowText(DEFAULTTEXT);
						this->m_hFileFullName.SetWindowText(DEFAULTTEXT);
						this->m_hFileFullPath.SetWindowText(DEFAULTTEXT);
						BUTTON_DECODE->EnableWindow(FALSE);
						BUTTON_ENCODE->EnableWindow(FALSE);
						READ_SRC.Empty();
						ENCODE_PATH.Empty();
						return;
					}
					else {
						OutputDebugString(_T("Warning: file: ( ") + ENCODE_PATH + _T(" ) Not found.\n"));
						OutputDebugString(_T("Error! src encode failed.\n"));
						MessageBox(_T("エンコードに失敗しました。"), _T("エラー"), MB_ICONERROR | MB_OK);
						this->m_hReadStatus.SetWindowText(DEFAULTTEXT);
						this->m_hFileFullName.SetWindowText(DEFAULTTEXT);
						this->m_hFileFullPath.SetWindowText(DEFAULTTEXT);
						BUTTON_DECODE->EnableWindow(FALSE);
						BUTTON_ENCODE->EnableWindow(FALSE);
						READ_SRC.Empty();
						ENCODE_PATH.Empty();
						return;
					}
				}
				else {
					OutputDebugString(_T("Warning: script text file: ( ") + TXTFULLPATH + _T(" ) Not found.\n"));
					MessageBox(_T("テキストファイルが見つかりません。"), _T("エラー"), MB_ICONERROR | MB_OK);
					this->m_hReadStatus.SetWindowText(DEFAULTTEXT);
					this->m_hFileFullName.SetWindowText(DEFAULTTEXT);
					this->m_hFileFullPath.SetWindowText(DEFAULTTEXT);
					BUTTON_DECODE->EnableWindow(FALSE);
					BUTTON_ENCODE->EnableWindow(FALSE);
					READ_SRC.Empty();
					ENCODE_PATH.Empty();
					return;
				}
			}
			else if (ret == IDCANCEL) {
				OutputDebugString(_T("Was canceled.\n"));
				MessageBox(_T("キャンセルされました。"), _T("キャンセル"), MB_ICONWARNING | MB_OK);
				this->m_hReadStatus.SetWindowText(DEFAULTTEXT);
				this->m_hFileFullName.SetWindowText(DEFAULTTEXT);
				this->m_hFileFullPath.SetWindowText(DEFAULTTEXT);
				BUTTON_DECODE->EnableWindow(FALSE);
				BUTTON_ENCODE->EnableWindow(FALSE);
				READ_SRC.Empty();
				ENCODE_PATH.Empty();
				return;
			}
			else {
				OutputDebugString(_T("Exception occured.\n"));
				this->m_hReadStatus.SetWindowText(DEFAULTTEXT);
				this->m_hFileFullName.SetWindowText(DEFAULTTEXT);
				this->m_hFileFullPath.SetWindowText(DEFAULTTEXT);
				BUTTON_DECODE->EnableWindow(FALSE);
				BUTTON_ENCODE->EnableWindow(FALSE);
				READ_SRC.Empty();
				ENCODE_PATH.Empty();
				return;
			}
		}
		else {
			OutputDebugString(_T("Error! perl script: ( ") + ENCODE_SCRIPT + _T(" ) Not found."));
			MessageBox(_T("実行可能ファイルが見つかりません。"), _T("エラー"), MB_ICONERROR | MB_OK);
			this->m_hReadStatus.SetWindowText(DEFAULTTEXT);
			this->m_hFileFullName.SetWindowText(DEFAULTTEXT);
			this->m_hFileFullPath.SetWindowText(DEFAULTTEXT);
			BUTTON_DECODE->EnableWindow(FALSE);
			BUTTON_ENCODE->EnableWindow(FALSE);
			READ_SRC.Empty();
			ENCODE_PATH.Empty();
			return;
		}
	}
}


void CscriptToolDlg::OnBnClickedButtonAllDecode()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	OutputDebugString(_T("OnBnClickedButtonAllDecode\n"));
	CFileFind Find;
	CButton* button1 = (CButton*)GetDlgItem(IDC_BUTTON_DECODE);
	CButton* button2 = (CButton*)GetDlgItem(IDC_BUTTON_ENCODE);
	CButton* button3 = (CButton*)GetDlgItem(IDC_BUTTON_ALL_DECODE);
	CButton* button4 = (CButton*)GetDlgItem(IDC_BUTTON_ALL_ENCODE);
	PROCDLG* PROCDlg = new PROCDLG;

	TCHAR crDir[MAX_PATH + 1];
	GetCurrentDirectory(MAX_PATH + 1, crDir);

	wchar_t name[MAX_PATH]{}, dir[MAX_PATH]{};
	BROWSEINFO  binfo{};
	LPITEMIDLIST idlist;

	binfo.hwndOwner = NULL;
	binfo.pidlRoot = NULL;
	binfo.pszDisplayName = (LPWSTR)name;
	binfo.lpszTitle = L"保存フォルダの選択";
	binfo.ulFlags = BIF_RETURNONLYFSDIRS;
	binfo.lpfn = NULL;
	binfo.lParam = 0;
	binfo.iImage = 0;

	if ((idlist = SHBrowseForFolder(&binfo)) == NULL)
	{
		MessageBox(L"キャンセルされました", L"キャンセル", MB_ICONWARNING | MB_OK);
		PROCDlg->Create(IDD_PROCESS_DLG);
		PROCDlg->ShowWindow(SW_SHOW);
		button1->EnableWindow(FALSE);
		button2->EnableWindow(FALSE);
		button3->EnableWindow(FALSE);
		button4->EnableWindow(FALSE);
		this->m_hReadStatus.SetWindowText(DEFAULTTEXT);
		this->m_hFileFullName.SetWindowText(DEFAULTTEXT);
		this->m_hFileFullPath.SetWindowText(DEFAULTTEXT);
		PROCDlg->DestroyWindow();
		delete PROCDlg;
		PROCDlg = NULL;
		return;
	}
	else
	{
		SHGetPathFromIDList(idlist, (LPWSTR)dir);
		DECODE_PATH = (LPCTSTR)dir;
		CoTaskMemFree(idlist);
	}

	CString CurrentDir = crDir;
	CString ResDir = CurrentDir + _T("\\Resources");
	CString FindPath1 = ResDir + _T("\\decode.plx");

	if (DECODE_PATH.GetLength() == 0)
	{
		MessageBox(_T("フォルダが選択されていません。"), _T("エラー"), MB_ICONERROR | MB_OK);
		PROCDlg->Create(IDD_PROCESS_DLG);
		PROCDlg->ShowWindow(SW_SHOW);
		button1->EnableWindow(FALSE);
		button2->EnableWindow(FALSE);
		button3->EnableWindow(FALSE);
		button4->EnableWindow(FALSE);
		this->m_hReadStatus.SetWindowText(DEFAULTTEXT);
		this->m_hFileFullName.SetWindowText(DEFAULTTEXT);
		this->m_hFileFullPath.SetWindowText(DEFAULTTEXT);
		PROCDlg->DestroyWindow();
		delete PROCDlg;
		PROCDlg = NULL;
	}
	else {
		if (DECODE_PATH.GetLength() > MAX_PATH)
		{
			MessageBox(_T("ファイルへのパスが長すぎます。"), _T("エラー"), MB_ICONERROR | MB_OK);
			PROCDlg->Create(IDD_PROCESS_DLG);
			PROCDlg->ShowWindow(SW_SHOW);
			button1->EnableWindow(FALSE);
			button2->EnableWindow(FALSE);
			button3->EnableWindow(FALSE);
			button4->EnableWindow(FALSE);
			this->m_hReadStatus.SetWindowText(DEFAULTTEXT);
			this->m_hFileFullName.SetWindowText(DEFAULTTEXT);
			this->m_hFileFullPath.SetWindowText(DEFAULTTEXT);
			PROCDlg->DestroyWindow();
			delete PROCDlg;
			PROCDlg = NULL;
			return;
		}
		else
		{
			if (Find.FindFile(FindPath1)) {
				std::ifstream fin(_T(".\\list.index"));

				if (!fin) {
					OutputDebugString(_T("ifstream failed.\n"));
					return;
				}
				std::string ss;
				WAITDIALOG* waitDlg = new WAITDIALOG;

				AfxGetMainWnd()->EnableWindow(FALSE);
				waitDlg->Create(IDD_DIALOG1);
				waitDlg->ShowWindow(SW_SHOW);

				STARTUPINFO si/* = { sizeof(STARTUPINFO) }*/;
				memset(&si, 0, sizeof(STARTUPINFO));
				PROCESS_INFORMATION pi;
				memset(&pi, 0, sizeof(PROCESS_INFORMATION));
				si.dwFlags = STARTF_USESHOWWINDOW;
				si.wShowWindow = SW_SHOW;
				while (getline(fin, ss, '\n')) {
					CString RET;
					RET = ss.c_str();
					wchar_t Drive[10], Dir[MAX_PATH], Name[MAX_PATH], Ext[MAX_PATH];
					_wsplitpath_s(RET, Drive, Dir, Name, Ext);
					CString DRIVE = Drive, DIR = Dir, NAME = Name, EXT = Ext;
					CString lpPath = _T("perl .\\Resources\\decode.plx ") + RET + _T(" ") + DECODE_PATH + _T("\\") + NAME + EXT;
					OutputDebugString(_T("Decoded file: ") + RET + _T("\n"));
					OutputDebugString(_T("Output file: ") + DECODE_PATH + _T("\\") + NAME + _T(".src") + _T("\n"));
					OutputDebugString(_T("Output file: ") + DECODE_PATH + _T("\\") + NAME + _T(".txt") + _T("\n"));
					TCHAR* lpPathT = (TCHAR*)malloc(sizeof(TCHAR) * 512); // Convert CString to TCHAR.
					if (NULL == lpPathT) {
						perror("can not malloc");
						OutputDebugString(_T("TCHAR syntax (lpPath) malloc failed.\n"));
						return;
					}
					else {
						ZeroMemory(&lpPathT[0], 512);
						_tcscpy_s(&lpPathT[0], 512, lpPath);
					}
					::CreateProcess(NULL, lpPathT, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
					CloseHandle(pi.hThread);	// CloseHandleでhThreadを閉じる.
					MSG msg;
					while (::PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE)) {
						if (!AfxGetApp()->PumpMessage())
						{
							::PostQuitMessage(0);
							break;
						}
					}
					WaitForSingleObject(pi.hProcess, INFINITE);
					CloseHandle(pi.hProcess);
					free(lpPathT);
					MoveFile(DRIVE + DIR + NAME + _T(".src"), DECODE_PATH + _T("\\") + NAME + _T(".src"));
					MoveFile(DRIVE + DIR + NAME + _T(".txt"), DECODE_PATH + _T("\\") + NAME + _T(".txt"));
				}
				fin.close();

				waitDlg->DestroyWindow();
				delete waitDlg;
				AfxGetMainWnd()->EnableWindow(TRUE);

				fin.open(_T(".\\list.index"));
				ss = "";
				while (getline(fin, ss, '\n')) {
					CString RET;
					RET = ss.c_str();
					wchar_t Drive[10], Dir[MAX_PATH], Name[MAX_PATH], Ext[MAX_PATH];
					_wsplitpath_s(RET, Drive, Dir, Name, Ext);
					CString DRIVE = Drive, DIR = Dir, NAME = Name, EXT = Ext;
					if (Find.FindFile(DECODE_PATH + _T("\\") + NAME + _T(".src"))) {
						OutputDebugString(_T("File found: ") + DECODE_PATH + _T("\\") + NAME + _T(".src") + _T("\n"));
					}
					else {
						OutputDebugString(_T("File not found: ") + DECODE_PATH + _T("\\") + NAME + _T(".src") + _T("\n"));
					}
					if (Find.FindFile(DECODE_PATH + _T("\\") + NAME + _T(".txt"))) {
						OutputDebugString(_T("File found: ") + DECODE_PATH + _T("\\") + NAME + _T(".txt") + _T("\n"));
					}
					else {
						OutputDebugString(_T("File not found: ") + DECODE_PATH + _T("\\") + NAME + _T(".txt") + _T("\n"));
					}
				}
				fin.close();

				CStdioFile log(_T(".\\decoded.log"), CFile::modeCreate | CFile::modeWrite | CFile::typeText);
				fin.open(_T(".\\list.index"));
				ss = "";
				while (getline(fin, ss, '\n')) {
					CString RET;
					RET = ss.c_str();
					wchar_t Drive[10], Dir[MAX_PATH], Name[MAX_PATH], Ext[MAX_PATH];
					_tsplitpath_s(RET, Drive, Dir, Name, Ext);
					CString DRIVE = Drive, DIR = Dir, NAME = Name, EXT = Ext;
					if (Find.FindFile(DECODE_PATH + _T("\\") + NAME + _T(".src"))) {
						OutputDebugString(_T("Decoded file: ") + DECODE_PATH + _T("\\") + NAME + _T(".src") + _T("\n"));
						log.WriteString(_T("Decoded: ") + DECODE_PATH + _T("\\") + NAME + _T(".src") + _T("\n"));
					}
					else {
						OutputDebugString(_T("Decode error file: ") + DECODE_PATH + _T("\\") + NAME + _T(".src") + _T("\n"));
						log.WriteString(_T("Decoded error: ") + DECODE_PATH + _T("\\") + NAME + _T(".src") + _T("\n"));
					}
					if (Find.FindFile(DECODE_PATH + _T("\\") + NAME + _T(".txt"))) {
						OutputDebugString(_T("Decoded file: ") + DECODE_PATH + _T("\\") + NAME + _T(".txt") + _T("\n"));
						log.WriteString(_T("Decoded: ") + DECODE_PATH + _T("\\") + NAME + _T(".txt") + _T("\n"));
					}
					else {
						OutputDebugString(_T("Decode error file: ") + DECODE_PATH + _T("\\") + NAME + _T(".txt") + _T("\n"));
						log.WriteString(_T("Decoded error: ") + DECODE_PATH + _T("\\") + NAME + _T(".txt") + _T("\n"));
					}
				}
				fin.close();
				log.Close();
				DeleteFile(_T(".\\list.index"));

				MessageBox(_T("全てのデコードが完了しました。詳細情報は decoded.log ファイルを参照してください。"), _T("完了"), MB_ICONINFORMATION | MB_OK);
				ShellExecute(NULL, _T("open"), DECODE_PATH, NULL, NULL, SW_SHOWNORMAL);
				PROCDlg->Create(IDD_PROCESS_DLG);
				PROCDlg->ShowWindow(SW_SHOW);
				button1->EnableWindow(FALSE);
				button2->EnableWindow(FALSE);
				button3->EnableWindow(FALSE);
				button4->EnableWindow(FALSE);
				this->m_hReadStatus.SetWindowText(DEFAULTTEXT);
				this->m_hFileFullName.SetWindowText(DEFAULTTEXT);
				this->m_hFileFullPath.SetWindowText(DEFAULTTEXT);
				PROCDlg->DestroyWindow();
				delete PROCDlg;
				PROCDlg = NULL;
				return;
			}
			else
			{
				MessageBox(_T("実行可能ファイルが見つかりません。"), _T("エラー"), MB_ICONERROR | MB_OK);
				PROCDlg->Create(IDD_PROCESS_DLG);
				PROCDlg->ShowWindow(SW_SHOW);
				button1->EnableWindow(FALSE);
				button2->EnableWindow(FALSE);
				button3->EnableWindow(FALSE);
				button4->EnableWindow(FALSE);
				this->m_hReadStatus.SetWindowText(DEFAULTTEXT);
				this->m_hFileFullName.SetWindowText(DEFAULTTEXT);
				this->m_hFileFullPath.SetWindowText(DEFAULTTEXT);
				PROCDlg->DestroyWindow();
				delete PROCDlg;
				PROCDlg = NULL;
				return;
			}
		}
	}
}


void CscriptToolDlg::OnBnClickedButtonAllEncode()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	OutputDebugString(_T("OnBnClickedButtonAllEncode\n"));
	CFileFind Find;
	CButton* button1 = (CButton*)GetDlgItem(IDC_BUTTON_DECODE);
	CButton* button2 = (CButton*)GetDlgItem(IDC_BUTTON_ENCODE);
	CButton* button3 = (CButton*)GetDlgItem(IDC_BUTTON_ALL_DECODE);
	CButton* button4 = (CButton*)GetDlgItem(IDC_BUTTON_ALL_ENCODE);
	PROCDLG* PROCDlg = new PROCDLG;

	TCHAR crDir[MAX_PATH + 1];
	GetCurrentDirectory(MAX_PATH + 1, crDir);

	wchar_t name[MAX_PATH]{}, dir[MAX_PATH]{};
	BROWSEINFO  binfo{};
	LPITEMIDLIST idlist;

	binfo.hwndOwner = NULL;
	binfo.pidlRoot = NULL;
	binfo.pszDisplayName = (LPWSTR)name;
	binfo.lpszTitle = L"保存フォルダの選択";
	binfo.ulFlags = BIF_RETURNONLYFSDIRS;
	binfo.lpfn = NULL;
	binfo.lParam = 0;
	binfo.iImage = 0;

	if ((idlist = SHBrowseForFolder(&binfo)) == NULL)
	{
		MessageBox(L"キャンセルされました", L"キャンセル", MB_ICONWARNING | MB_OK);
		PROCDlg->Create(IDD_PROCESS_DLG);
		PROCDlg->ShowWindow(SW_SHOW);
		button1->EnableWindow(FALSE);
		button2->EnableWindow(FALSE);
		button3->EnableWindow(FALSE);
		button4->EnableWindow(FALSE);
		this->m_hReadStatus.SetWindowText(DEFAULTTEXT);
		this->m_hFileFullName.SetWindowText(DEFAULTTEXT);
		this->m_hFileFullPath.SetWindowText(DEFAULTTEXT);
		PROCDlg->DestroyWindow();
		delete PROCDlg;
		PROCDlg = NULL;
		return;
	}
	else
	{
		SHGetPathFromIDList(idlist, (LPWSTR)dir);
		ENCODE_PATH = (LPCTSTR)dir;
		CoTaskMemFree(idlist);
	}

	CString CurrentDir = crDir;
	CString ResDir = CurrentDir + _T("\\Resources");
	CString FindPath1 = ResDir + _T("\\encode.plx");

	if (ENCODE_PATH.GetLength() == 0)
	{
		MessageBox(_T("フォルダが選択されていません。"), _T("エラー"), MB_ICONERROR | MB_OK);
		PROCDlg->Create(IDD_PROCESS_DLG);
		PROCDlg->ShowWindow(SW_SHOW);
		button1->EnableWindow(FALSE);
		button2->EnableWindow(FALSE);
		button3->EnableWindow(FALSE);
		button4->EnableWindow(FALSE);
		this->m_hReadStatus.SetWindowText(DEFAULTTEXT);
		this->m_hFileFullName.SetWindowText(DEFAULTTEXT);
		this->m_hFileFullPath.SetWindowText(DEFAULTTEXT);
		PROCDlg->DestroyWindow();
		delete PROCDlg;
		PROCDlg = NULL;
	}
	else {
		if (ENCODE_PATH.GetLength() > MAX_PATH)
		{
			MessageBox(_T("ファイルへのパスが長すぎます。"), _T("エラー"), MB_ICONERROR | MB_OK);
			PROCDlg->Create(IDD_PROCESS_DLG);
			PROCDlg->ShowWindow(SW_SHOW);
			button1->EnableWindow(FALSE);
			button2->EnableWindow(FALSE);
			button3->EnableWindow(FALSE);
			button4->EnableWindow(FALSE);
			this->m_hReadStatus.SetWindowText(DEFAULTTEXT);
			this->m_hFileFullName.SetWindowText(DEFAULTTEXT);
			this->m_hFileFullPath.SetWindowText(DEFAULTTEXT);
			PROCDlg->DestroyWindow();
			delete PROCDlg;
			PROCDlg = NULL;
			return;
		}
		else
		{
			if (Find.FindFile(FindPath1)) {
				std::ifstream fin(_T(".\\list.index"));

				if (!fin) {
					OutputDebugString(_T("ifstream failed.\n"));
					return;
				}
				std::string ss;
				WAITDIALOG* waitDlg = new WAITDIALOG;

				AfxGetMainWnd()->EnableWindow(FALSE);
				waitDlg->Create(IDD_DIALOG1);
				waitDlg->ShowWindow(SW_SHOW);

				STARTUPINFO si/* = { sizeof(STARTUPINFO) }*/;
				memset(&si, 0, sizeof(STARTUPINFO));
				PROCESS_INFORMATION pi;
				memset(&pi, 0, sizeof(PROCESS_INFORMATION));
				si.dwFlags = STARTF_USESHOWWINDOW;
				si.wShowWindow = SW_SHOW;
				while (getline(fin, ss, '\n')) {
					CString RET;
					RET = ss.c_str();
					wchar_t Drive[10], Dir[MAX_PATH], Name[MAX_PATH], Ext[MAX_PATH];
					_wsplitpath_s(RET, Drive, Dir, Name, Ext);
					CString DRIVE = Drive, DIR = Dir, NAME = Name, EXT = Ext;
					CString lpPath = _T("perl .\\Resources\\encode.plx ") + DRIVE + DIR + NAME + _T(".script");
					OutputDebugString(_T("Encoded file: ") + RET + _T("\n"));
					OutputDebugString(_T("Output file: ") + ENCODE_PATH + _T("\\") + NAME + _T(".script") + _T("\n"));
					TCHAR* lpPathT = (TCHAR*)malloc(sizeof(TCHAR) * 512); // Convert CString to TCHAR.
					if (NULL == lpPathT) {
						perror("can not malloc");
						OutputDebugString(_T("TCHAR syntax (lpPath) malloc failed.\n"));
						return;
					}
					else {
						ZeroMemory(&lpPathT[0], 512);
						_tcscpy_s(&lpPathT[0], 512, lpPath);
					}
					::CreateProcess(NULL, lpPathT, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
					CloseHandle(pi.hThread);	// CloseHandleでhThreadを閉じる.
					MSG msg;
					while (::PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE)) {
						if (!AfxGetApp()->PumpMessage())
						{
							::PostQuitMessage(0);
							break;
						}
					}
					WaitForSingleObject(pi.hProcess, INFINITE);
					CloseHandle(pi.hProcess);
					free(lpPathT);
					MoveFile(DRIVE + DIR + NAME + _T(".script"), ENCODE_PATH + _T("\\") + NAME + _T(".script"));
				}
				fin.close();

				waitDlg->DestroyWindow();
				delete waitDlg;
				AfxGetMainWnd()->EnableWindow(TRUE);

				fin.open(_T(".\\list.index"));
				ss = "";
				while (getline(fin, ss, '\n')) {
					CString RET;
					RET = ss.c_str();
					wchar_t Drive[10], Dir[MAX_PATH], Name[MAX_PATH], Ext[MAX_PATH];
					_wsplitpath_s(RET, Drive, Dir, Name, Ext);
					CString DRIVE = Drive, DIR = Dir, NAME = Name, EXT = Ext;
					if (Find.FindFile(ENCODE_PATH + _T("\\") + NAME + _T(".script"))) {
						OutputDebugString(_T("File found: ") + ENCODE_PATH + _T("\\") + NAME + _T(".script") + _T("\n"));
					}
					else {
						OutputDebugString(_T("File not found: ") + ENCODE_PATH + _T("\\") + NAME + _T(".script") + _T("\n"));
					}
				}
				fin.close();

				CStdioFile log(_T(".\\encoded.log"), CFile::modeCreate | CFile::modeWrite | CFile::typeText);
				fin.open(_T(".\\list.index"));
				ss = "";
				while (getline(fin, ss, '\n')) {
					CString RET;
					RET = ss.c_str();
					wchar_t Drive[10], Dir[MAX_PATH], Name[MAX_PATH], Ext[MAX_PATH];
					_tsplitpath_s(RET, Drive, Dir, Name, Ext);
					CString DRIVE = Drive, DIR = Dir, NAME = Name, EXT = Ext;
					if (Find.FindFile(ENCODE_PATH + _T("\\") + NAME + _T(".script"))) {
						OutputDebugString(_T("Encoded file: ") + ENCODE_PATH + _T("\\") + NAME + _T(".script") + _T("\n"));
						log.WriteString(_T("Encoded: ") + ENCODE_PATH + _T("\\") + NAME + _T(".script") + _T("\n"));
					}
					else {
						OutputDebugString(_T("Encode error file: ") + ENCODE_PATH + _T("\\") + NAME + _T(".script") + _T("\n"));
						log.WriteString(_T("Encoded error: ") + ENCODE_PATH + _T("\\") + NAME + _T(".script") + _T("\n"));
					}
				}
				fin.close();
				log.Close();
				DeleteFile(_T(".\\list.index"));

				MessageBox(_T("全てのエンコードが完了しました。詳細情報は encoded.log ファイルを参照してください。"), _T("完了"), MB_ICONINFORMATION | MB_OK);
				ShellExecute(NULL, _T("open"), ENCODE_PATH, NULL, NULL, SW_SHOWNORMAL);
				PROCDlg->Create(IDD_PROCESS_DLG);
				PROCDlg->ShowWindow(SW_SHOW);
				button1->EnableWindow(FALSE);
				button2->EnableWindow(FALSE);
				button3->EnableWindow(FALSE);
				button4->EnableWindow(FALSE);
				this->m_hReadStatus.SetWindowText(DEFAULTTEXT);
				this->m_hFileFullName.SetWindowText(DEFAULTTEXT);
				this->m_hFileFullPath.SetWindowText(DEFAULTTEXT);
				PROCDlg->DestroyWindow();
				delete PROCDlg;
				PROCDlg = NULL;
				return;
			}
			else
			{
				MessageBox(_T("実行可能ファイルが見つかりません。"), _T("エラー"), MB_ICONERROR | MB_OK);
				PROCDlg->Create(IDD_PROCESS_DLG);
				PROCDlg->ShowWindow(SW_SHOW);
				button1->EnableWindow(FALSE);
				button2->EnableWindow(FALSE);
				button3->EnableWindow(FALSE);
				button4->EnableWindow(FALSE);
				this->m_hReadStatus.SetWindowText(DEFAULTTEXT);
				this->m_hFileFullName.SetWindowText(DEFAULTTEXT);
				this->m_hFileFullPath.SetWindowText(DEFAULTTEXT);
				PROCDlg->DestroyWindow();
				delete PROCDlg;
				PROCDlg = NULL;
				return;
			}
		}
	}
}



void CscriptToolDlg::OnOpenscript()
{
	// TODO: ここにコマンド ハンドラー コードを追加します。
	OutputDebugString(_T("OnOpenscript\n"));
	DWORD size;
	PROCDLG* PROCDlg = new PROCDLG;
	CButton* BUTTON_DECODE = (CButton*)GetDlgItem(IDC_BUTTON_DECODE);
	CButton* BUTTON_ENCODE = (CButton*)GetDlgItem(IDC_BUTTON_ENCODE);
	CButton* BUTTON_ALL_DECODE = (CButton*)GetDlgItem(IDC_BUTTON_ALL_DECODE);
	CButton* BUTTON_ALL_ENCODE = (CButton*)GetDlgItem(IDC_BUTTON_ALL_ENCODE);
	wchar_t Drive[10] = { NULL }, Dir[MAX_PATH] = { NULL }, Name[MAX_PATH] = { NULL }, Ext[MAX_PATH] = { NULL };
	CString DRIVE, DIR, NAME, EXT, SIZE;
	CString filter("アイマスSP スクリプトファイル (*.script)|*.script||");
	CFileDialog selDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, filter);
	INT_PTR ret = selDlg.DoModal();

	if (ret == IDOK)
	{
		READ_SCRIPT = selDlg.GetPathName();
		if (!READ_SCRIPT) {
			MessageBox(_T("ファイルを開けませんでした"), _T("エラー"), MB_ICONERROR | MB_OK);
			return;
		}
		PROCDlg->Create(IDD_PROCESS_DLG);
		PROCDlg->ShowWindow(SW_SHOW);
		_tsplitpath_s(READ_SCRIPT, Drive, Dir, Name, Ext);
		DRIVE = Drive, DIR = Dir, NAME = Name, EXT = Ext;
		size = Utility->GetFileSizeStat(READ_SCRIPT);
		SIZE.Format(_T("%u バイト"), size);
		this->m_hReadStatus.SetWindowText(READEDTEXT);
		this->m_hFileFullName.SetWindowText(_T("ファイル名：") + NAME + EXT +_T("　　　ファイルサイズ：") + SIZE);
		this->m_hFileFullPath.SetWindowText(_T("絶対パス：") + DRIVE + DIR + NAME + EXT);
		BUTTON_DECODE->EnableWindow(TRUE);
		BUTTON_ENCODE->EnableWindow(FALSE);
		BUTTON_ALL_DECODE->EnableWindow(FALSE);
		BUTTON_ALL_ENCODE->EnableWindow(FALSE);
		PROCDlg->DestroyWindow();
		delete PROCDlg;
		return;
	}
	else if (ret == IDCANCEL)
	{
		PROCDlg->Create(IDD_PROCESS_DLG);
		PROCDlg->ShowWindow(SW_SHOW);
		this->m_hReadStatus.SetWindowText(DEFAULTTEXT);
		this->m_hFileFullName.SetWindowText(DEFAULTTEXT);
		this->m_hFileFullPath.SetWindowText(DEFAULTTEXT);
		BUTTON_DECODE->EnableWindow(FALSE);
		BUTTON_ENCODE->EnableWindow(FALSE);
		BUTTON_ALL_DECODE->EnableWindow(FALSE);
		BUTTON_ALL_ENCODE->EnableWindow(FALSE);
		PROCDlg->DestroyWindow();
		delete PROCDlg;
		return;
	}
	else
	{
		PROCDlg->Create(IDD_PROCESS_DLG);
		PROCDlg->ShowWindow(SW_SHOW);
		this->m_hReadStatus.SetWindowText(DEFAULTTEXT);
		this->m_hFileFullName.SetWindowText(DEFAULTTEXT);
		this->m_hFileFullPath.SetWindowText(DEFAULTTEXT);
		BUTTON_DECODE->EnableWindow(FALSE);
		BUTTON_ENCODE->EnableWindow(FALSE);
		BUTTON_ALL_DECODE->EnableWindow(FALSE);
		BUTTON_ALL_ENCODE->EnableWindow(FALSE);
		PROCDlg->DestroyWindow();
		delete PROCDlg;
		return;
	}
}


void CscriptToolDlg::OnOpensrc()
{
	// TODO: ここにコマンド ハンドラー コードを追加します。
	OutputDebugString(_T("OnOpensrc\n"));
	DWORD size;
	PROCDLG* PROCDlg = new PROCDLG;
	CButton* BUTTON_DECODE = (CButton*)GetDlgItem(IDC_BUTTON_DECODE);
	CButton* BUTTON_ENCODE = (CButton*)GetDlgItem(IDC_BUTTON_ENCODE);
	CButton* BUTTON_ALL_DECODE = (CButton*)GetDlgItem(IDC_BUTTON_ALL_DECODE);
	CButton* BUTTON_ALL_ENCODE = (CButton*)GetDlgItem(IDC_BUTTON_ALL_ENCODE);
	wchar_t Drive[10] = { NULL }, Dir[MAX_PATH] = { NULL }, Name[MAX_PATH] = { NULL }, Ext[MAX_PATH] = { NULL };
	CString DRIVE, DIR, NAME, EXT, SIZE;
	CString filter("SRC ファイル (*.src)|*.src||");
	CFileDialog selDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, filter);
	INT_PTR ret = selDlg.DoModal();

	if (ret == IDOK)
	{
		READ_SRC = selDlg.GetPathName();
		if (!READ_SRC) {
			MessageBox(_T("ファイルを開けませんでした"), _T("エラー"), MB_ICONERROR | MB_OK);
			return;
		}
		PROCDlg->Create(IDD_PROCESS_DLG);
		PROCDlg->ShowWindow(SW_SHOW);
		_tsplitpath_s(READ_SRC, Drive, Dir, Name, Ext);
		DRIVE = Drive, DIR = Dir, NAME = Name, EXT = Ext;
		size = Utility->GetFileSizeStat(READ_SRC);
		SIZE.Format(_T("%u バイト"), size);
		this->m_hReadStatus.SetWindowText(READEDTEXT);
		this->m_hFileFullName.SetWindowText(_T("ファイル名：") + NAME + EXT + _T("　　　ファイルサイズ：") + SIZE);
		this->m_hFileFullPath.SetWindowText(_T("絶対パス：") + DRIVE + DIR + NAME + EXT);
		BUTTON_DECODE->EnableWindow(FALSE);
		BUTTON_ENCODE->EnableWindow(TRUE);
		BUTTON_ALL_DECODE->EnableWindow(FALSE);
		BUTTON_ALL_ENCODE->EnableWindow(FALSE);
		PROCDlg->DestroyWindow();
		delete PROCDlg;
		return;
	}
	else if (ret == IDCANCEL)
	{
		PROCDlg->Create(IDD_PROCESS_DLG);
		PROCDlg->ShowWindow(SW_SHOW);
		this->m_hReadStatus.SetWindowText(DEFAULTTEXT);
		this->m_hFileFullName.SetWindowText(DEFAULTTEXT);
		this->m_hFileFullPath.SetWindowText(DEFAULTTEXT);
		BUTTON_DECODE->EnableWindow(FALSE);
		BUTTON_ENCODE->EnableWindow(FALSE);
		BUTTON_ALL_DECODE->EnableWindow(FALSE);
		BUTTON_ALL_ENCODE->EnableWindow(FALSE);
		PROCDlg->DestroyWindow();
		delete PROCDlg;
		return;
	}
	else
	{
		PROCDlg->Create(IDD_PROCESS_DLG);
		PROCDlg->ShowWindow(SW_SHOW);
		this->m_hReadStatus.SetWindowText(DEFAULTTEXT);
		this->m_hFileFullName.SetWindowText(DEFAULTTEXT);
		this->m_hFileFullPath.SetWindowText(DEFAULTTEXT);
		BUTTON_DECODE->EnableWindow(FALSE);
		BUTTON_ENCODE->EnableWindow(FALSE);
		BUTTON_ALL_DECODE->EnableWindow(FALSE);
		BUTTON_ALL_ENCODE->EnableWindow(FALSE);
		PROCDlg->DestroyWindow();
		delete PROCDlg;
		return;
	}
}


void CscriptToolDlg::OnOpenallscript()
{
	// TODO: ここにコマンド ハンドラー コードを追加します。
	OutputDebugString(_T("OnOpenallscript\n"));
	PROCDLG* PROCDlg = new PROCDLG;
	CButton* BUTTON_DECODE = (CButton*)GetDlgItem(IDC_BUTTON_DECODE);
	CButton* BUTTON_ENCODE = (CButton*)GetDlgItem(IDC_BUTTON_ENCODE);
	CButton* BUTTON_ALL_DECODE = (CButton*)GetDlgItem(IDC_BUTTON_ALL_DECODE);
	CButton* BUTTON_ALL_ENCODE = (CButton*)GetDlgItem(IDC_BUTTON_ALL_ENCODE);
	UINT_PTR size = 0;
	UINT fin = 0;

	wchar_t name[MAX_PATH]{}, dir[MAX_PATH]{};
	BROWSEINFO  binfo{};
	LPITEMIDLIST idlist;

	binfo.hwndOwner = NULL;
	binfo.pidlRoot = NULL;
	binfo.pszDisplayName = (LPWSTR)name;
	binfo.lpszTitle = L"スクリプトフォルダの選択";
	binfo.ulFlags = BIF_RETURNONLYFSDIRS;
	binfo.lpfn = NULL;
	binfo.lParam = 0;
	binfo.iImage = 0;

	if ((idlist = SHBrowseForFolder(&binfo)) == NULL)
	{
		MessageBox(L"キャンセルされました", L"キャンセル", MB_ICONWARNING | MB_OK);
		PROCDlg->Create(IDD_PROCESS_DLG);
		PROCDlg->ShowWindow(SW_SHOW);
		this->m_hReadStatus.SetWindowText(DEFAULTTEXT);
		this->m_hFileFullName.SetWindowText(DEFAULTTEXT);
		this->m_hFileFullPath.SetWindowText(DEFAULTTEXT);
		PROCDlg->DestroyWindow();
		delete PROCDlg;
		PROCDlg = NULL;
		return;
	}
	else
	{
		SHGetPathFromIDList(idlist, (LPWSTR)dir);
		LIB_COREUTIL->FindDirectoryALL((LPCTSTR)dir);
		size = LIB_COREUTIL->FindDirectoryFileSize((LPCTSTR)dir);
		READ_SCRIPT = (LPCTSTR)dir;
		CoTaskMemFree(idlist);
	}
	wchar_t Drive[10], Dir[MAX_PATH], Name[MAX_PATH], Ext[MAX_PATH];
	_tsplitpath_s(READ_SCRIPT, Drive, Dir, Name, Ext);
	CString DRIVE = Drive, DIR = Dir, NAME = Name, EXT = Ext;
	CString FULLPATH = DRIVE + DIR + NAME + EXT;
	CString FSIZE;
	fin = static_cast<UINT>(size);
	if (fin != -1) {
		PROCDlg->Create(IDD_PROCESS_DLG);
		PROCDlg->ShowWindow(SW_SHOW);
		FSIZE.Format(_T(" %u バイト"), fin);
		this->m_hReadStatus.SetWindowText(READEDTEXT);
		this->m_hFileFullName.SetWindowText(_T("ファイル名：*.script") + EXT + _T("　　全ファイルサイズ：") + FSIZE);
		this->m_hFileFullPath.SetWindowText(_T("絶対パス：") + DRIVE + DIR);
		BUTTON_DECODE->EnableWindow(FALSE);
		BUTTON_ENCODE->EnableWindow(FALSE);
		BUTTON_ALL_DECODE->EnableWindow(TRUE);
		BUTTON_ALL_ENCODE->EnableWindow(FALSE);
		PROCDlg->DestroyWindow();
		delete PROCDlg;
		return;
	}
	MessageBox(_T("ファイルサイズの取得に失敗しました。"), _T("エラー"), MB_ICONWARNING | MB_OK);
	return;
}


void CscriptToolDlg::OnOpenallsrc()
{
	// TODO: ここにコマンド ハンドラー コードを追加します。
	OutputDebugString(_T("OnOpenallsrc\n"));
	PROCDLG* PROCDlg = new PROCDLG;
	CButton* BUTTON_DECODE = (CButton*)GetDlgItem(IDC_BUTTON_DECODE);
	CButton* BUTTON_ENCODE = (CButton*)GetDlgItem(IDC_BUTTON_ENCODE);
	CButton* BUTTON_ALL_DECODE = (CButton*)GetDlgItem(IDC_BUTTON_ALL_DECODE);
	CButton* BUTTON_ALL_ENCODE = (CButton*)GetDlgItem(IDC_BUTTON_ALL_ENCODE);
	UINT_PTR size = 0;
	UINT fin = 0;

	wchar_t name[MAX_PATH]{}, dir[MAX_PATH]{};
	BROWSEINFO  binfo{};
	LPITEMIDLIST idlist;

	binfo.hwndOwner = NULL;
	binfo.pidlRoot = NULL;
	binfo.pszDisplayName = (LPWSTR)name;
	binfo.lpszTitle = L"SRCフォルダの選択";
	binfo.ulFlags = BIF_RETURNONLYFSDIRS;
	binfo.lpfn = NULL;
	binfo.lParam = 0;
	binfo.iImage = 0;

	if ((idlist = SHBrowseForFolder(&binfo)) == NULL)
	{
		MessageBox(L"キャンセルされました", L"キャンセル", MB_ICONWARNING | MB_OK);
		PROCDlg->Create(IDD_PROCESS_DLG);
		PROCDlg->ShowWindow(SW_SHOW);
		this->m_hReadStatus.SetWindowText(DEFAULTTEXT);
		this->m_hFileFullName.SetWindowText(DEFAULTTEXT);
		this->m_hFileFullPath.SetWindowText(DEFAULTTEXT);
		PROCDlg->DestroyWindow();
		delete PROCDlg;
		PROCDlg = NULL;
		return;
	}
	else
	{
		SHGetPathFromIDList(idlist, (LPWSTR)dir);
		LIB_COREUTIL->FindDirectoryALL((LPCTSTR)dir);
		size = LIB_COREUTIL->FindDirectoryFileSize((LPCTSTR)dir);
		READ_SRC = (LPCTSTR)dir;
		CoTaskMemFree(idlist);
	}
	wchar_t Drive[10], Dir[MAX_PATH], Name[MAX_PATH], Ext[MAX_PATH];
	_tsplitpath_s(READ_SRC, Drive, Dir, Name, Ext);
	CString DRIVE = Drive, DIR = Dir, NAME = Name, EXT = Ext;
	CString FULLPATH = DRIVE + DIR + NAME + EXT;
	CString FSIZE;
	fin = static_cast<UINT>(size);
	if (fin != -1) {
		PROCDlg->Create(IDD_PROCESS_DLG);
		PROCDlg->ShowWindow(SW_SHOW);
		FSIZE.Format(_T(" %u バイト"), fin);
		this->m_hReadStatus.SetWindowText(READEDTEXT);
		this->m_hFileFullName.SetWindowText(_T("ファイル名：*.src") + EXT + _T("　　全ファイルサイズ：") + FSIZE);
		this->m_hFileFullPath.SetWindowText(_T("絶対パス：") + DRIVE + DIR);
		BUTTON_DECODE->EnableWindow(FALSE);
		BUTTON_ENCODE->EnableWindow(FALSE);
		BUTTON_ALL_DECODE->EnableWindow(FALSE);
		BUTTON_ALL_ENCODE->EnableWindow(TRUE);
		PROCDlg->DestroyWindow();
		delete PROCDlg;
		return;
	}
	MessageBox(_T("ファイルサイズの取得に失敗しました。"), _T("エラー"), MB_ICONWARNING | MB_OK);
	return;
}


void CscriptToolDlg::OnExit()
{
	// TODO: ここにコマンド ハンドラー コードを追加します。
	OutputDebugString(_T("OnExit\n"));
	AfxGetMainWnd()->SendMessage(WM_CLOSE, 0, 0);
	AfxGetMainWnd()->DestroyWindow();
	PostQuitMessage(0);
}


void CscriptToolDlg::OnAbout()
{
	// TODO: ここにコマンド ハンドラー コードを追加します。
	OutputDebugString(_T("OnAbout\n"));
	CAboutDlg About;
	About.DoModal();
}


void CscriptToolDlg::OnDestroy()
{
	OutputDebugString(_T("OnDestroy\n"));
	CDialogEx::OnDestroy();
	LIB_FREE_LIB;
	LIB_CORE->FreeResourcesDir();
	LIB_DEL_CORE;
	LOGO_MAIN.Detach();
	LIB_DEL_COREIMAGE;
	LIB_DEL_COREUTIL;
	LIB_DEL_INITSTR;
	LIB_DEL_MAINSTR;
}

void CscriptToolDlg::OnUpdate()
{
	// TODO: ここにコマンド ハンドラー コードを追加します。
	OutputDebugString(_T("OnUpdateCheck\n"));
	CString LatestVersion = LIB_COREUTIL->AppUpdateCheck();
	if (LatestVersion == _T("")) {
		MessageBox(_T("情報取得中にエラーが発生しました。\nインターネット接続がされているか確認してください。"), _T("エラー"), MB_ICONERROR | MB_OK);
		return;
	}
	if (LatestVersion == _T("-1")) {
		MessageBox(_T("情報取得中にエラーが発生しました。\nサーバーにデータが見つかりません。"), _T("エラー"), MB_ICONERROR | MB_OK);
		return;
	}
	CString CurrentVersion = LIB_COREUTIL->AppCurrentVersionCheck();
	if (CurrentVersion == _T("")) {
		MessageBox(_T("情報取得中にエラーが発生しました。\nインターネット接続がされているか確認してください。"), _T("エラー"), MB_ICONERROR | MB_OK);
		return;
	}
	LatestVersion = LatestVersion.Left(CurrentVersion.GetLength());
	LatestVersion += _T("\r");
	if (LatestVersion == CurrentVersion + _T("\r")) {
		MessageBox(_T("最新バージョン：") + LatestVersion + _T("現在使用中のバージョン：") + CurrentVersion + _T("\nアプリケーションのバージョンは最新です。"), _T("完了"), MB_ICONINFORMATION | MB_OK);
		return;
	}
	else if (LatestVersion > CurrentVersion) {
		UINT ret;
		ret = MessageBox(_T("最新バージョン：") + LatestVersion + _T("現在使用中のバージョン：") + CurrentVersion + _T("\nアプリケーションのアップデートが可能です。サイトを開きますか？"), _T("アップデート確認"), MB_ICONINFORMATION | MB_YESNOCANCEL);
		if (ret == IDYES) {
			ShellExecute(NULL, _T("open"), _T("https://imas.arc.xyle-official.com/main/tools/sp_scriptool/#latest-release"), NULL, NULL, SW_SHOWNORMAL);
			return;
		}
		else if (ret == IDNO) {
			return;
		}
		else if (ret == IDCANCEL) {
			MessageBox(_T("キャンセルされました。"), _T("キャンセル"), MB_ICONWARNING | MB_OK);
		}
		else {
			return;
		}
	}
	else {
		MessageBox(_T("情報取得中にエラーが発生しました。"), _T("エラー"), MB_ICONERROR | MB_OK);
		return;
	}
}
