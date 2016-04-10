#include "stdafx.h"
#include "head.h"
#include "ChildView.h"
#include <wingdi.h>

const double CMy2DObject8A ::  GetA(){
	return m_dA;
}
const double CMy2DObject8A ::  GetA1(){
	return m_dA1;
}
const double CMy2DObject8A ::  GetA2(){
	return m_dA2;
}
const double CMy2DObject8A ::  GetA3(){
	return m_dA3;
}
const double CMy2DObject8A ::  GetAngle(){
	return m_dAngle;
}
const CMy2DPoint CMy2DObject8A ::  GetCenter(){
	return m_center;
}

bool CMy2DObject8A::SET(const double A, const double A1, const double A2, const double A3) {
	if (A > A1 && A / 2.0 >= A2 && A3 < A && (A3 + A2 <= A) && (A3 + A1 < A) && A > 0 && A1 > 0 && A2 > 0 && A3 > 0) {
		m_dA = A;
		m_dA1 = A1;
		m_dA2 = A2;
		m_dA3 = A3;
		return 1;
	}
	else {
		return 0;
	}
}

bool CMy2DObject8A ::  SetA(const double A){
	if (A / 2 >= m_dA1 && A > (m_dA3 + 2 * m_dA2) && A > (m_dA3 + m_dA1) && A / 2 >= m_dA2){
		m_dA = A;
		return 1;
	}
	else{
		cout << "I cant do that! try again. Old A = " << m_dA << endl;
		return 0;
	}
}
bool CMy2DObject8A ::  SetA1(const double A1){
	if (A1 <= m_dA / 2 && m_dA > (m_dA3 + A1)){
		m_dA1 = A1;
		return 1;
	}
	else{
		cout << "I cant do that! try again. Old A1 = " << m_dA1 << endl;
		return 0;
	}
}
bool CMy2DObject8A ::  SetA2(const double A2){
	if (A2 <= m_dA / 2 && m_dA > (m_dA3 + 2 * A2)){
		m_dA2 = A2;
		return 1;
	}
	else{
		cout << "I cant do that! try again. Old A2 = " << m_dA2 << endl;
		return 0;
	}
}
bool CMy2DObject8A ::  SetA3(const double A3){
	if (m_dA > (A3 + 2 * m_dA2) && m_dA > (A3 + m_dA1)){
		m_dA3 = A3;
		return 1;
	}
	else{
		cout << "I cant do that! try again. Old A3 = " << m_dA3 << endl;
		return 0;
	}
}
void CMy2DObject8A ::  SetAngle(const double Angle){
	m_dAngle = Angle;
	if (m_dAngle > 360){
		while (m_dAngle > 360){
			m_dAngle -= 360;
		}
	}
	else if (m_dAngle < 0){
		while (m_dAngle < -360){
			m_dAngle += 360;
		}
	}
		cout << "Ok! Newest Angle = " << m_dAngle << endl;
}
void CMy2DObject8A ::  SetCenter(const CMy2DPoint center){
	m_center = center;
	cout << "Ok! Newest Center = " << m_center << endl;
}
void CMy2DObject8A ::  SetCenter(const double x, const double y){
	CMy2DPoint a(x, y);
	m_center = a;
	cout << "Ok! Newest Center = " << m_center << endl;
}
void CMy2DObject8A :: Move(double dX, double dY, double dAngle){
	CMy2DPoint a(dX, dY);
	m_center += a;
	m_dAngle += dAngle;
	if (m_dAngle > 360){
		while (m_dAngle > 360){
			m_dAngle -= 360;
		}
	}
	else if (m_dAngle < 0){
		while (m_dAngle < -360){
			m_dAngle += 360;
		}
	}
	cout << "Ok! Newest Center = " << m_center << ", " << "Newest Angle = " << m_dAngle << endl;
}
void CMy2DObject8A :: Move(const CMy2DPoint &delta, double dAngle){
	m_center += delta;
	m_dAngle += dAngle;
	if (m_dAngle > 360){
		while (m_dAngle > 360){
			m_dAngle -= 360;
		}
	}
	else if (m_dAngle < 0){
		while (m_dAngle < -360){
			m_dAngle += 360;
		}
	}
	cout << "Ok! Newest Center = " << m_center << ", " << "Newest Angle = " << m_dAngle << endl;
}
void CMy2DObject8A :: Rotate(double dAngle){
	m_dAngle += dAngle;
	if (m_dAngle > 360){
		while (m_dAngle > 360){
			m_dAngle -= 360;
		}
	}
	if (m_dAngle < 0){
		while (m_dAngle < -360){
			m_dAngle += 360;
		}
	}
	cout << "Ok! Newest Angle = " << m_dAngle << endl;
}
double NCx(double x, double y, double angle) {
	return (x*cos(angle) + y*sin(angle));
}
double NCy(double x, double y, double angle) {
	return (-x*sin(angle) + y*cos(angle));
}
double degtorad(double deg) {
	return (deg * M_PI / 180);
}
const bool CMy2DObject8A :: IsInside(const CMy2DPoint &point){
	CMy2DPoint a(point.m_dx - m_center.m_dx, point.m_dy - m_center.m_dy);
	a.m_dx = NCx(a.m_dx, a.m_dy, degtorad(-m_dAngle));//a.m_dx*cos(m_dAngle) + a.m_dy*sin(m_dAngle);
	a.m_dy = NCy(a.m_dx, a.m_dy, degtorad(-m_dAngle));//-a.m_dx*sin(m_dAngle) + a.m_dy*cos(m_dAngle);

	if (abs(a.m_dx) <= m_dA / 2 && abs(a.m_dy) <= m_dA / 2) {
		if (pow(a.m_dx - m_dA / 2, 2) + a.m_dy*a.m_dy >= m_dA1*m_dA1) {
			if (a.m_dx >= (-m_dA / 2 + m_dA3) || a.m_dy <= (m_dA / 2 - m_dA3)) {
				if (pow(a.m_dx + (m_dA / 2 - m_dA2), 2) + pow(a.m_dy + (m_dA / 2 - m_dA2), 2) <= m_dA2*m_dA2 || a.m_dy >= (-m_dA / 2 + m_dA2) || a.m_dx >= (-m_dA / 2 + m_dA2)) {
					return 1;
				}
			}
		}
	}
	//cout << "point isn't inside" << endl;
	return 0;
}
const bool CMy2DObject8A::IsInside(const double x, const double y) {
	//CMy2DPoint a(x - NCx(m_center.m_dx, m_center.m_dy, degtorad(m_dAngle)), y - NCy(m_center.m_dx, m_center.m_dy, degtorad(m_dAngle)));
	//CMy2DPoint a(-m_center.m_dx + NCx(x, y, degtorad(m_dAngle)), -m_center.m_dy + NCy(x, y, degtorad(m_dAngle)));
	CMy2DPoint a(x - m_center.m_dx, y - m_center.m_dy);
	a.m_dx = NCx(a.m_dx, a.m_dy, degtorad(-m_dAngle));//a.m_dx*cos(m_dAngle) + a.m_dy*sin(m_dAngle);
	a.m_dy = NCy(a.m_dx, a.m_dy, degtorad(-m_dAngle));//-a.m_dx*sin(m_dAngle) + a.m_dy*cos(m_dAngle);
	if (abs(a.m_dx) <= m_dA / 2 && abs(a.m_dy) <= m_dA / 2) {
//		if (pow(a.m_dx - m_dA/2, 2) + a.m_dy*a.m_dy >= m_dA1*m_dA1) {
//			if (a.m_dx >= (-m_dA/2 + m_dA3) || a.m_dy<=(m_dA/2 - m_dA3)) {
//				if (pow(a.m_dx + (m_dA/2 - m_dA2), 2) + pow(a.m_dy + (m_dA/2 - m_dA2), 2) <= m_dA2*m_dA2 || a.m_dy >= (-m_dA/2 +m_dA2) || a.m_dx >= (-m_dA / 2 + m_dA2)) {
					return 1;
//				}
//			}
//		}
	}
	//cout << "point isn't inside" << endl;
	return 0;
}
ostream &operator<<(ostream &output, const CMy2DObject8A& a){
	output << "A = " << a.m_dA << " A1 = " << a.m_dA1 << " A2 = " << a.m_dA2 << " A3 = " << a.m_dA3 << " Center:" << a.m_center << " Angle = " << a.m_dAngle;
	return output;
}
istream &operator>>(istream  &input, CMy2DObject8A& D) {
	double A, A1, A2, A3, Angle;
	CMy2DPoint center;
	while (1) {
		input >> A >> A1 >> A2 >> A3 >> center >> Angle; //ввод из консоли с проверкой. Пока не будут введены правильные данные - будет повторяться
		if (D.SET(A, A1, A2, A3)) {
			D.SetCenter(center);
			D.SetAngle(Angle);
			return input;
		}
		else {
			cout << "I can't do that! Try again" << endl;
		}
	}
}

void CMy2DObject8A::Draw(CDC &dc) {
	CMy2DPoint c = this->m_center, c1(NCx(c.m_dx, c.m_dy, degtorad(m_dAngle)), NCy(c.m_dx, c.m_dy, degtorad(m_dAngle)));
	double A = this->m_dA, A1 = this->m_dA1, A2 = this->m_dA2, A3 = this->m_dA3, angle = this->m_dAngle;
	double tempx, tempy;
	c1 = c - c1;
	tempx = NCx(A2 + c.m_dx - A / 2, c.m_dy - A / 2, degtorad(m_dAngle));
	tempy = NCy(A2 + c.m_dx - A / 2, c.m_dy - A / 2, degtorad(m_dAngle));
	dc.MoveTo(tempx + c1.m_dx, tempy + c1.m_dy);
	tempx = NCx(A2 + c.m_dx - A / 2, A2 + c.m_dy - A / 2, degtorad(m_dAngle));
	tempy = NCy(A2 + c.m_dx - A / 2, A2 + c.m_dy - A / 2, degtorad(m_dAngle));
	dc.AngleArc(tempx + c1.m_dx, tempy + c1.m_dy, A2, 90 + m_dAngle, 90);
	tempx = NCx(c.m_dx - A / 2, c.m_dy - A / 2 + A2 + (A - A2 - A3), degtorad(m_dAngle));
	tempy = NCy(c.m_dx - A / 2, c.m_dy - A / 2 + A2 + (A - A2 - A3), degtorad(m_dAngle));
	dc.LineTo(tempx + c1.m_dx, tempy + c1.m_dy);
	tempx = NCx(c.m_dx - A / 2 + A3, c.m_dy - A / 2 + A - A3, degtorad(m_dAngle));
	tempy = NCy(c.m_dx - A / 2 + A3, c.m_dy - A / 2 + A - A3, degtorad(m_dAngle));
	dc.LineTo(tempx + c1.m_dx, tempy + c1.m_dy);
	tempx = NCx(A3 + c.m_dx - A / 2, c.m_dy - A / 2 + A, degtorad(m_dAngle));
	tempy = NCy(A3 + c.m_dx - A / 2, c.m_dy - A / 2 + A, degtorad(m_dAngle));
	dc.LineTo(tempx + c1.m_dx, tempy + c1.m_dy);
	tempx = NCx(A + c.m_dx - A / 2, A + c.m_dy - A / 2, degtorad(m_dAngle));
	tempy = NCy(A + c.m_dx - A / 2, A + c.m_dy - A / 2, degtorad(m_dAngle));
	dc.LineTo(tempx + c1.m_dx, tempy + c1.m_dy);
	tempx = NCx(A + c.m_dx - A / 2, c.m_dy - A / 2 + 2 * A1 + A / 2 - A1, degtorad(m_dAngle));
	tempy = NCy(A + c.m_dx - A / 2, c.m_dy - A / 2 + 2 * A1 + A / 2 - A1, degtorad(m_dAngle));
	dc.LineTo(tempx + c1.m_dx, tempy + c1.m_dy);
	tempx = NCx(c.m_dx - A / 2 + A, c.m_dy - A / 2 + A / 2, degtorad(m_dAngle));
	tempy = NCy(c.m_dx - A / 2 + A, c.m_dy - A / 2 + A / 2, degtorad(m_dAngle));
	dc.AngleArc(tempx + c1.m_dx, tempy + c1.m_dy, A1, -90 + m_dAngle, -180);
	tempx = NCx(c.m_dx - A / 2 + A, c.m_dy - A / 2, degtorad(m_dAngle));
	tempy = NCy(c.m_dx - A / 2 + A, c.m_dy - A / 2, degtorad(m_dAngle));
	dc.LineTo(tempx + c1.m_dx, tempy + c1.m_dy);
	tempx = NCx(c.m_dx - A / 2 + A2, c.m_dy - A / 2, degtorad(m_dAngle));
	tempy = NCy(c.m_dx - A / 2 + A2, c.m_dy - A / 2, degtorad(m_dAngle));
	dc.LineTo(tempx + c1.m_dx, tempy + c1.m_dy);


	for (int i = 0; i < 5000; i += 5) {
		for (int j = 0; j < 5000; j += 5) {
			if (IsInside(i, j)){
				dc.SetPixel(i, j, RGB(255, 0, 0));
			}
		}
	}
/*
	for (int i = -300; i < A+200; i += 5) {
		for (int j = -300; j < A+200; j += 5) {
			if (IsInside(c.m_dx + i, c.m_dy + j)) {
				tempx = NCx(c.m_dx + i, c.m_dy + j, degtorad(m_dAngle));
				tempy = NCy(c.m_dx + i, c.m_dy + j, degtorad(m_dAngle));
				dc.SetPixel(tempx, tempy, RGB(255, 0, 0));
			}
		}
	}
	*/

	/*
	dc.MoveTo(A2 + c.m_dx - A / 2, c.m_dy - A / 2);
	dc.AngleArc(A2 + c.m_dx - A / 2, A2 + c.m_dy - A / 2, A2, 90, 90);
	dc.LineTo(c.m_dx - A / 2, c.m_dy - A / 2 + A2 + (A - A2 - A3));
	dc.LineTo(c.m_dx - A / 2 + A3, c.m_dy - A / 2 + A - A3);
	dc.LineTo(A3 + c.m_dx - A / 2, c.m_dy - A / 2 + A);
	dc.LineTo(A + c.m_dx - A / 2, A + c.m_dy - A / 2);
	dc.LineTo(A + c.m_dx - A / 2, c.m_dy - A / 2 + 2 * A1 + A / 2 - A1);
	dc.AngleArc(c.m_dx - A / 2 + A, c.m_dy - A / 2 + A / 2, A1, -90, -180);
	dc.LineTo(c.m_dx - A / 2 + A, c.m_dy - A / 2);
	dc.LineTo(c.m_dx - A / 2 + A2, c.m_dy - A / 2);
	*/
}