
// OpenGL_Demo_dialog.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// COpenGL_Demo_dialogApp:
// �йش����ʵ�֣������ OpenGL_Demo_dialog.cpp
//

class COpenGL_Demo_dialogApp : public CWinApp
{
public:
	COpenGL_Demo_dialogApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern COpenGL_Demo_dialogApp theApp;