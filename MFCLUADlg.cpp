#include "stdafx.h"
#include "MFCLUA.h"
#include "MFCLUADlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCLUADlg 对话框
CMFCLUADlg::CMFCLUADlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCLUA_DIALOG, pParent)
	, m_unit_price(0)
	, m_weight(0)
	, m_quantity(0)
	, m_trans_type(_T(""))
	, m_result(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

}

void CMFCLUADlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_UNIT_PRICE, m_unit_price);
	DDX_Text(pDX, IDC_WEIGHT, m_weight);
	DDX_Text(pDX, IDC_QUANTITY, m_quantity);
	DDX_Text(pDX, IDC_TRANS_TYPE, m_trans_type);
	DDX_Text(pDX, IDC_RESULT, m_result);
}

BEGIN_MESSAGE_MAP(CMFCLUADlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CALL_LUA, &CMFCLUADlg::OnBnClickedCallLua)
	ON_BN_CLICKED(IDC_CALL_CPLUS, &CMFCLUADlg::OnBnClickedCallCplus)
	ON_BN_CLICKED(IDC_COST_CAL, &CMFCLUADlg::OnBnClickedCostCal)
	ON_BN_CLICKED(IDC_COST_CAL2, &CMFCLUADlg::OnBnClickedCostCal2)
	ON_BN_CLICKED(IDC_COST_CAL3, &CMFCLUADlg::OnBnClickedCostCal3)
END_MESSAGE_MAP()


// CMFCLUADlg 消息处理程序
BOOL CMFCLUADlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	ShowWindow(SW_MAXIMIZE);



	return TRUE;  
}

void CMFCLUADlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。
void CMFCLUADlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCLUADlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//CPLUS PLUS CALLING LUA FUNCTION
void CMFCLUADlg::OnBnClickedCallLua()
{
	
}

//LUA CALLING CPLUS
void CMFCLUADlg::OnBnClickedCallCplus()
{
	
}

//
void CMFCLUADlg::OnBnClickedCostCal()
{

}

//PACK-CAL
void CMFCLUADlg::OnBnClickedCostCal2()
{
	
}


//TRANS-CAL
void CMFCLUADlg::OnBnClickedCostCal3()
{
	UpdateData(TRUE);

	m_script.InitVM("cost.lua");
	string str = (CStringA)m_trans_type;
	m_script.TransCostCal(str,m_quantity,m_weight, m_unit_price,m_result);

	UpdateData(FALSE);
}
