#include "stdafx.h"
#include "head.h"

CMy2DPoint& CMy2DPoint::operator=(const CMy2DPoint& a){
		m_dx = a.m_dx;
		m_dy = a.m_dy;
		return *this;
}
const CMy2DPoint CMy2DPoint::operator+(const CMy2DPoint & b){
	return CMy2DPoint((*this).m_dx + b.m_dx, (*this).m_dy + b.m_dy);
}
CMy2DPoint& CMy2DPoint::operator+=(const CMy2DPoint & b){
	m_dx = m_dx + b.m_dx;
	m_dy = m_dy + b.m_dy;
	return *this;
}
const CMy2DPoint CMy2DPoint::operator-(const CMy2DPoint & b){
	return CMy2DPoint((*this).m_dx - b.m_dx, (*this).m_dy - b.m_dy);
}
const double operator*(const CMy2DPoint & a, const CMy2DPoint & b){
	return (a.m_dx * b.m_dx + a.m_dy * b.m_dy);
}
const CMy2DPoint operator*(const double & a, const CMy2DPoint & b){
	return CMy2DPoint(a * b.m_dx, a * b.m_dy);
}
const CMy2DPoint operator*(const CMy2DPoint & a, const double & b){
	return CMy2DPoint(a.m_dx * b, a.m_dy * b);
}
const CMy2DPoint operator/(const CMy2DPoint & a, const double & b){
	return CMy2DPoint(a.m_dx / b, a.m_dy / b);
}
const CMy2DPoint operator/(const CMy2DPoint & a, const CMy2DPoint & b){
	return CMy2DPoint(a.m_dx / b.m_dx, a.m_dy / b.m_dy);
}
const bool operator==(const CMy2DPoint & a, const CMy2DPoint & b){
	return (a.m_dx == b.m_dx && a.m_dy == b.m_dy);
}
const bool operator!=(const CMy2DPoint & a, const CMy2DPoint & b){
	return !operator==(a, b);
}
ostream &operator<<(ostream &output, const CMy2DPoint& a){
	output << "(" << a.m_dx << "; " << a.m_dy << ")";
	return output;
}
istream &operator>>(istream  &input, CMy2DPoint& D) {
	input >> D.m_dx >> D.m_dy;
	return input;
}