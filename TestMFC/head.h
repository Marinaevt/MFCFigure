#pragma once
#define _USE_MATH_DEFINES 
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;
class CMy2DPoint{
public:
	double m_dx, m_dy;
	CMy2DPoint():m_dx(0), m_dy(0){}; //����������� �� ���������
	CMy2DPoint(const double a, const double b): m_dx(a), m_dy(b){}; //������������ � �����������
	CMy2DPoint(const CMy2DPoint &a): m_dx(a.m_dx), m_dy(a.m_dy){};

	CMy2DPoint& operator=(const CMy2DPoint& a); //��������� (���������� � ����� CMy2DPoint.cpp)
	const CMy2DPoint operator+(const CMy2DPoint & b);
	CMy2DPoint& operator+=(const CMy2DPoint & b);
	const CMy2DPoint operator-(const CMy2DPoint & b);
	friend const double operator*(const CMy2DPoint & a, const CMy2DPoint & b); //��� ��������� friend ���� ������, ��� � ��� �� ���������� �������� ���������� ������
	friend const CMy2DPoint operator*(const double & a, const CMy2DPoint & b); //(������ ��������� ����� ������), ���� ������, ��� ��� �����, ����� ����� �������
	friend const CMy2DPoint operator*(const CMy2DPoint & a, const double & b); //��� �� ������ ������ 
	friend const CMy2DPoint operator/(const CMy2DPoint & a, const double & b);
	friend const CMy2DPoint operator/(const CMy2DPoint & a, const CMy2DPoint & b);
	friend const bool operator==(const CMy2DPoint & a, const CMy2DPoint & b);
	friend const bool operator!=(const CMy2DPoint & a, const CMy2DPoint & b);
	friend ostream& operator<<(ostream &output, const CMy2DPoint& D); //��������� ������ � �����, ��� ������ friend, �.�. �����, ����� ����� ������� ��� �� ������ ������
	friend istream& operator>>(istream  &input, CMy2DPoint& D);
};
class CMy2DObject8A{
	double m_dA, m_dA1, m_dA2, m_dA3, m_dAngle;
	CMy2DPoint m_center;
public:
	CMy2DObject8A(): m_dA(0), m_dA1(0), m_dA2(0), m_dA3(0), m_dAngle(0), m_center(){}; //����������� �� ���������
	CMy2DObject8A(const double A, const double A1, const double A2, const double A3, const double angle, const CMy2DPoint center): m_dAngle(angle), m_center(center) { //������������ � �����������
		if (SET(A, A1, A2, A3)) { //�������� �� ������������ ��������� ������
			m_dA = A;
			m_dA1 = A1;
			m_dA2 = A2;
			m_dA3 = A3;
		}
		else {
			cout << "I can't do that. Try another figure" << endl;
		}
	};
	CMy2DObject8A(const double A, const double A1, const double A2, const double A3, const double angle, double x, double y): m_dAngle(angle), m_center(x, y) {
		if (!SET(A, A1, A2, A3)) {
			cout << "I can't do that. Try another figure" << endl;
		}
	};

	const double GetA(); //Get - ������� ���������� �������� private �����
	const double GetA1();
	const double GetA2();
	const double GetA3();
	const double GetAngle();
	const CMy2DPoint GetCenter();

	bool SET(const double A, const double A1, const double A2, const double A3); //����� Set ��� �������� ������������ � ������������ ��� �����
	bool SetA(const double A); //��������� Set ��� ������� ��������� ������
	bool SetA1(const double A1);
	bool SetA2(const double A2);
	bool SetA3(const double A3);
	void SetAngle(const double Angle);
	void SetCenter(const CMy2DPoint center);
	void SetCenter(const double x, const double y);
	void Move(double dX, double dY, double dAngle = 0); //����������� ������ �� ������ � ������
	void Move(const CMy2DPoint &delta, double dAngle = 0);
	void Rotate(double dAngle); //������� ������
	const bool IsInside(const CMy2DPoint &point); //��������, ��������� �� ����� ������ ������
	const bool IsInside(const double x, const double y);
	void Draw(CDC &dc);
	friend ostream& operator<<(ostream &output, const CMy2DObject8A& D); //��������� ������ � �����
	friend istream& operator>>(istream  &input, CMy2DObject8A& D);
};
double degtorad(double deg);
double NCx(double x, double y, double angle);
double NCy(double x, double y, double angle);