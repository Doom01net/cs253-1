#ifndef Complex_h_included
#define Complex_h_included

#include <iostream>

// Do NOT put “using namespace std” here--that’s namespace pollution!

class Complex {
  public:
    Complex(double real = 0.0, double imag = 0.0);
    Complex(const Complex &);			    // Note lack of arg name
    ~Complex();
    Complex &operator=(const Complex &);

    double real() const;
    double imag() const;
    Complex conj() const;
    double abs() const;
    static int get_count();

    Complex operator+(const Complex &) const;
    Complex operator-(const Complex &) const;
    Complex operator*(const Complex &) const;	// TODO
    Complex operator/(const Complex &) const;	// TODO

    Complex operator+(double) const;
    Complex operator-(double) const;
    Complex operator*(double) const;
    Complex operator/(double) const;

    Complex& operator+=(const Complex &);
    Complex &operator-=(const Complex &);
    Complex &operator*=(const Complex &);	// TODO
    Complex &operator/=(const Complex &);	// TODO

    Complex &operator+=(double);
    Complex &operator-=(double);
    Complex &operator*=(double);
    Complex &operator/=(double);

    const Complex &operator++();     // Prefix
    Complex operator++(int);         // Postfix

    const Complex &operator--();     // Prefix
    Complex operator--(int);         // Postfix

  private:
    double re, im;
    // Assume that computing the absolute value of the complex number
    // is very expensive, so we cache the result.
    mutable double absolute_value;	// Negative value means it's invalid
    void invalidate_absolute_value();	// This marks it as invalid
    static int count;
};

Complex operator+(double, const Complex &);	// TODO
Complex operator-(double, const Complex &);	// TODO
Complex operator*(double, const Complex &);	// TODO
Complex operator/(double, const Complex &);	// TODO

std::ostream &operator<<(std::ostream &, const Complex &);
std::istream &operator>>(std::istream &, Complex &);	// TODO

#endif /* Complex_h_included */
