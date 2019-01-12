#pragma once

#include "Script.h"
// CMFCLUADlg 对话框
class CMFCLUADlg : public CDialogEx
{
// 构造
public:
	CMFCLUADlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCLUA_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCallLua();
	afx_msg void OnBnClickedCallCplus();
	afx_msg void OnBnClickedCostCal();
	double m_unit_price;
	double m_weight;
	double m_quantity;


public:
	CScript m_script;
	afx_msg void OnBnClickedCostCal2();
	afx_msg void OnBnClickedCostCal3();
	CString m_trans_type;
	double m_result;
};
