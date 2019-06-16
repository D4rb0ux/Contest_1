#include <iostream>
#include <cmath>

using namespace std;

class Complex {
private:
    double re;
    double im;

public:
    Complex(double re = 0, double im = 0) {
        this->re = re;
        this->im = im;
    }

    double Re() {
        return re;
    }

    double Im() {a
        return im;
    }

    double Re() const {
        return re;
    }

    double Im() const {
        return im;
    }

    Complex operator - () {
        return Complex(-re, -im);
    }

    Complex operator + () {
        return *this;
    }

    bool operator == (const Complex& c) {
        return (re == c.re && im == c.im);
    }

    bool operator != (const Complex& c) {
        return (re != c.re || im != c.im);
    }
};

Complex operator + (const Complex& c1, const Complex& c2) {
    return Complex(c1.Re() + c2.Re(), c1.Im() + c2.Im());
}

Complex operator - (const Complex& c1, const Complex& c2) {
    return Complex(c1.Re() - c2.Re(), c1.Im() - c2.Im());
}

Complex operator * (const Complex& c1, const Complex& c2) {
    return Complex(c1.Re() * c2.Re() - c1.Im() * c2.Im(), c1.Re() * c2.Im() + c1.Im() * c2.Re());
}

Complex operator / (const Complex& c1, const Complex& c2) {
    double d = c2.Re() * c2.Re() + c2.Im() * c2.Im();
    double real = (c1.Re() * c2.Re() + c1.Im() * c2.Im()) / d;
    double imag = (c1.Im() * c2.Re() - c1.Re() * c2.Im()) / d;
    return Complex(real, imag);
}

double abs(Complex& c) {
    double real = c.Re();
    double imag = c.Im();
    return sqrt(real * real + imag * imag);
}
