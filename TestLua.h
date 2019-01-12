#pragma once


// CTestLua 对话框

class CTestLua : public CDialogEx
{
	DECLARE_DYNAMIC(CTestLua)

public:
	CTestLua(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTestLua();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST_LUA };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
