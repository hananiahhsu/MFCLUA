#include "stdafx.h"
#include "MFCLUA.h"
#include "MFCLUADlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMFCLUADlg �Ի���
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


// CMFCLUADlg ��Ϣ�������
BOOL CMFCLUADlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�
void CMFCLUADlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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
