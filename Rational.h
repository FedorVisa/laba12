#ifndef MYf
#define MYf
#include<iostream>
class Rational
{
private:
	int numerator;
	int denomerator;
	int num;
public:
	Rational(int numerator = 0, int denomerator = 1, int num =0 );
	Rational(const Rational& m);
	Rational(Rational&& m);
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
	int getNum() const { return num; }
	void setNumerator(int n) { numerator = n; }
	void setDenomerator(int n) {
		if (n == 0)throw "denominator is 0";
		denomerator = n;
	}
	void setNum(int n) { num = n; }
	~Rational() {};
};

 std::istream& operator>>(std::istream& in, Rational& a);
 std::ostream& operator<<(std::ostream& out, Rational& a);

#endif