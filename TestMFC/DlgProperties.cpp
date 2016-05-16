// DlgProperties.cpp: файл реализации
//

#include "stdafx.h"
#include "TestMFC.h"
#include "DlgProperties.h"
#include "afxdialogex.h"


// диалоговое окно CDlgProperties

IMPLEMENT_DYNAMIC(CDlgProperties, CDialogEx)

CDlgProperties::CDlgProperties(double dA, double dA1, double dA2, double dA3, double dX, double dY, double dAngle, CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, A(dA)
	, A1(dA1)
	, A2(dA2)
	, A3(dA3)
	, C_X(dX)
	, C_Y(dY)
	, Angle(dAngle)
{

}

CDlgProperties::~CDlgProperties()
{
}

void CDlgProperties::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_A, A);
	DDX_Text(pDX, IDC_A1, A1);
	DDX_Text(pDX, IDC_A2, A2);
	DDX_Text(pDX, IDC_A3, A3);
	DDX_Text(pDX, IDC_CX, C_X);
	DDX_Text(pDX, IDC_CY, C_Y);
	DDX_Text(pDX, IDC_Angle, Angle);
}

BOOL CDlgProperties::OnInitDialog() {

	CDialogEx::OnInitDialog();
	CEdit *pEdit = (CEdit *)GetDlgItem(IDC_A);
	CString str;
	str.Format(_T("%.1f"), A);
	pEdit->SetWindowText(str);
	pEdit = (CEdit *)GetDlgItem(IDC_A1);
	str.Format(_T("%.1f"), A1);
	pEdit->SetWindowText(str);
	pEdit = (CEdit *)GetDlgItem(IDC_A2);
	str.Format(_T("%.1f"), A2);
	pEdit->SetWindowText(str);
	pEdit = (CEdit *)GetDlgItem(IDC_A3);
	str.Format(_T("%.1f"), A3);
	pEdit->SetWindowText(str);
	pEdit = (CEdit *)GetDlgItem(IDC_CX);
	str.Format(_T("%.1f"), C_X);
	pEdit->SetWindowText(str);
	pEdit = (CEdit *)GetDlgItem(IDC_CY);
	str.Format(_T("%.1f"), C_Y);
	pEdit->SetWindowText(str);
	pEdit = (CEdit *)GetDlgItem(IDC_Angle);
	str.Format(_T("%.1f"), Angle);
	pEdit->SetWindowText(str);
	return TRUE; 
}

BEGIN_MESSAGE_MAP(CDlgProperties, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDlgProperties::OnBtnOK)
END_MESSAGE_MAP()


// обработчики сообщений CDlgProperties




void CDlgProperties::OnBtnOK()
{
	CEdit *pEdit = (CEdit *)GetDlgItem(IDC_A);
	CString str;
	pEdit->GetWindowText(str);
	A = _wtof(str);
	pEdit = (CEdit *)GetDlgItem(IDC_A1);
	pEdit->GetWindowText(str);
	A1 = _wtof(str);
	pEdit = (CEdit *)GetDlgItem(IDC_A2);
	pEdit->GetWindowText(str);
	A2 = _wtof(str);
	pEdit = (CEdit *)GetDlgItem(IDC_A3);
	pEdit->GetWindowText(str);
	A3 = _wtof(str);
	pEdit = (CEdit *)GetDlgItem(IDC_CX);
	pEdit->GetWindowText(str);
	C_X = _wtof(str);
	pEdit = (CEdit *)GetDlgItem(IDC_CY);
	pEdit->GetWindowText(str);
	C_Y = _wtof(str);
	pEdit = (CEdit *)GetDlgItem(IDC_Angle);
	pEdit->GetWindowText(str);
	Angle = _wtof(str);
	CDialogEx::OnOK();
}
