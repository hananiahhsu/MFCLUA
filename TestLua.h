#pragma once


// CTestLua �Ի���

class CTestLua : public CDialogEx
{
	DECLARE_DYNAMIC(CTestLua)

public:
	CTestLua(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTestLua();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST_LUA };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
