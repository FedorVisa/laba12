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

Rational::Rational(int numer, int denom, int nume) {
	if (denom == 0) throw "denominator is 0";
	if (denomerator < 0) {
		denomerator = -denom;
		numerator = numer;
		num = -nume;
	}

	numerator = numer;
	denomerator = denom;
	num = nume;
}

Rational::Rational(const Rational& m) : numerator(m.numerator),denomerator(m.denomerator),num(m.num){

}

Rational Rational ::operator+(const Rational& a) {
	Rational res;
	res.numerator = numerator * a.denomerator + a.numerator *denomerator;
	res.denomerator = denomerator * a.denomerator;
	res.num = num + a.num;
	int nod_ = nod(res.denomerator, abs(res.numerator));
	res.denomerator /= nod_;
	res.numerator /= nod_;
	res.num += res.numerator/res.denomerator;
	return res;
}

Rational Rational ::operator-(const Rational& a) {
	Rational res;
	res.numerator = numerator * a.denomerator - a.numerator * denomerator;
	res.denomerator = denomerator * a.denomerator;
	res.num = num - a.num;
	int nod_ = nod(res.denomerator, abs(res.numerator));
	res.denomerator /= nod_;
	res.numerator /= nod_;
    res.num += res.numerator / res.denomerator;
	return res;

}

Rational Rational ::operator*(const Rational& a) {
	Rational res;
	res.numerator = numerator * a.numerator;
	res.denomerator = denomerator * a.denomerator;
	res.num = num * a.num;
	int nod_ = nod(res.denomerator, abs(res.numerator));
	res.denomerator /= nod_;
	res.numerator /= nod_;
	res.num += res.numerator / res.denomerator;
	return res;
}

Rational Rational ::operator/(const Rational& a) {
	Rational res;
	numerator += num * denomerator;
	
	res.numerator = numerator * a.denomerator;
	res.denomerator = (a.numerator+a.num*a.denomerator)*denomerator;
	res.num = 0;
	int nod_ = nod(res.denomerator, abs(res.numerator));
	if (res.denomerator == 0) throw "denominator is 0";
	res.denomerator /= nod_;
	res.numerator /= nod_;
	res.num += res.numerator / res.denomerator;
	return res;
}

std::istream& operator>>(std::istream& in,  Rational& a) {
	int numer, denom, num;
	in >> numer >> denom >> num;
	if(std::cin.fail())throw "num denom and full part should be a number";
	a = Rational(numer, denom,num);
	return in;
}

std::ostream& operator<<(std::ostream& out, Rational& a) {
	
	out << a.getNum()<<"."<< a.getNumerator() % a.getDenominator()<<"/"<< a.getDenominator();
	return out;
}

Rational::Rational(Rational&& m) : numerator(m.numerator), denomerator(m.denomerator),num(m.num) {
	m.numerator = 0;
	m.denomerator = 0;
	m.num = 0;
}