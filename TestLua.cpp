// TestLua.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCLUA.h"
#include "TestLua.h"
#include "afxdialogex.h"


// CTestLua 对话框

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


// CTestLua 消息处理程序
