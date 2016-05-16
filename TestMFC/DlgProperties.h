#pragma once


// ���������� ���� CDlgProperties

class CDlgProperties : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgProperties)

public:
	CDlgProperties(double dA = 0, double dA1 = 0, double dA2 = 0, double dA3 = 0, double dX = 0, double dY = 0, double dAngle = 0, CWnd* pParent = NULL);   // ����������� �����������
	virtual ~CDlgProperties();

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV
	BOOL OnInitDialog();
	//void OnBtnOK();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit6();
	afx_msg void OnBnClickedCancel();
	double A;
	double A1;
	double A2;
	double A3;
	double C_X;
	double C_Y;
	double Angle;
	afx_msg void OnBtnOK();
};
