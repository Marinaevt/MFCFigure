// DlgProperties.cpp: ���� ����������
//

#include "stdafx.h"
#include "TestMFC.h"
#include "DlgProperties.h"
#include "afxdialogex.h"


// ���������� ���� CDlgProperties

IMPLEMENT_DYNAMIC(CDlgProperties, CDialogEx)

CDlgProperties::CDlgProperties(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CDlgProperties::~CDlgProperties()
{
}

void CDlgProperties::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgProperties, CDialogEx)
END_MESSAGE_MAP()


// ����������� ��������� CDlgProperties


