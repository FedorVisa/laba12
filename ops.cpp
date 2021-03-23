#include "Rational.h"
#include <iostream>

static int nod(int a, int b) {
	while (a && b)
		if (a > b) a %= b;
		else b %= a;
	return a + b;
}
static int nok(int a, int b) {
	return a * b / nod(a, b);
}

Rational::Rational(int numer, int denom) {
	if (denom == 0) throw "denominator is 0";
	if (denomerator < 0) {
		denomerator = -denom;
		numerator = -numer;
	}
	numerator = numer;
	denomerator = denom;
}

Rational Rational ::operator+(const Rational& a) {
	Rational res;
	res.numerator = numerator * a.denomerator + a.numerator *denomerator;
	res.denomerator = denomerator * a.denomerator;
	int nod_ = nod(res.denomerator, abs(res.numerator));
	res.denomerator /= nod_;
	res.numerator /= nod_;
	return res;
}

Rational Rational ::operator-(const Rational& a) {
	Rational res;
	res.numerator = numerator * a.denomerator - a.numerator * denomerator;
	res.denomerator = denomerator * a.denomerator;
	int nod_ = nod(res.denomerator, abs(res.numerator));
	res.denomerator /= nod_;
	res.numerator /= nod_;
	return res;

}

Rational Rational ::operator*(const Rational& a) {
	Rational res;
	res.numerator = numerator * a.numerator;
	res.denomerator = denomerator * a.denomerator;
	int nod_ = nod(res.denomerator, abs(res.numerator));
	res.denomerator /= nod_;
	res.numerator /= nod_;
	return res;
}

Rational Rational ::operator/(const Rational& a) {
	Rational res;
	res.numerator = numerator * a.denomerator;
	res.denomerator = a.numerator*denomerator;
	int nod_ = nod(res.denomerator, abs(res.numerator));
	if (res.denomerator == 0) throw "denominator is 0";
	res.denomerator /= nod_;
	res.numerator /= nod_;
	return res;
}

std::istream& operator>>(std::istream& in,  Rational& a) {
	int num, denom;
	in >> num >> denom;
	a = Rational(num, denom);
	return in;
}

std::ostream& operator<<(std::ostream& out, Rational& a) {
	out << a.getNumerator() << "/" << a.getDenominator();
	return out;
}