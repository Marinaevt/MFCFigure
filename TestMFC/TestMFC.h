
// TestMFC.h : ������� ���� ��������� ��� ���������� TestMFC
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CTestMFCApp:
// � ���������� ������� ������ ��. TestMFC.cpp
//

class CTestMFCApp : public CWinApp
{
public:
	CTestMFCApp();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTestMFCApp theApp;
