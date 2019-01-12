#pragma once

#include "Script.h"
// CMFCLUADlg �Ի���
class CMFCLUADlg : public CDialogEx
{
// ����
public:
	CMFCLUADlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCLUA_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
