
// MFCLUA.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCLUAApp: 
// �йش����ʵ�֣������ MFCLUA.cpp
//

class CMFCLUAApp : public CWinApp
{
public:
	CMFCLUAApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCLUAApp theApp;