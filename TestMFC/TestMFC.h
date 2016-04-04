
// TestMFC.h : главный файл заголовка для приложения TestMFC
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CTestMFCApp:
// О реализации данного класса см. TestMFC.cpp
//

class CTestMFCApp : public CWinApp
{
public:
	CTestMFCApp();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTestMFCApp theApp;
