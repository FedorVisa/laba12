#pragma once
#include<iostream>
class Rational
{
private:
	int numerator;
	int denomerator;
public:
	Rational(int numerator = 0, int denomerator = 1 );
	Rational operator+(const Rational& b);
	Rational operator-(const Rational& a);
	Rational operator*(const Rational& a);
	Rational operator/(const Rational& a);

	Rational& operator += (const Rational& a) { *this = *this + a; return *this; };
	Rational& operator -= (const Rational& a) { *this = *this - a; return *this; };
	Rational& operator *= (const Rational& a) { *this = *this * a; return *this; };
	Rational& operator /= (const Rational& a) { *this = *this / a; return *this; };
	Rational& operator=(const Rational& a) = default;
	int getNumerator() const { return numerator; }
	int getDenominator() const { return denomerator; }
	~Rational() {};
};

 std::istream& operator>>(std::istream& in, Rational& a);
 std::ostream& operator<<(std::ostream& out, Rational& a);

