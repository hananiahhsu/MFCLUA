// TestLua.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCLUA.h"
#include "TestLua.h"
#include "afxdialogex.h"


// CTestLua �Ի���

IMPLEMENT_DYNAMIC(CTestLua, CDialogEx)

CTestLua::CTestLua(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TEST_LUA, pParent)
{

}

CTestLua::~CTestLua()
{
}

void CTestLua::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTestLua, CDialogEx)
END_MESSAGE_MAP()


// CTestLua ��Ϣ�������
