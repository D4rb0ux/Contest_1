#include<iostream>
#include<cmath>

using namespace std;

class Rational {
private:
    int x, y;

public:
    Rational(int x = 0, int y = 1) {
        this->x = x;
        this->y = y;
        if (this->y < 0) {
            this->x *= (-1);
            this->y *= (-1);
        }
    }

    int gcd(int n, int d) const {
        int res;
        if (n < d && d != 1) {
            int tmp = abs(n);
            n = abs(d);
            d = abs(tmp);
        }
        if (d != 0) {
            res = n % d;
            while (res != 0) {
                n = d;
                d = res;
                res = n % d;
            }
            return d;
        }
        return 0;
    }

    Rational& operator ++() {
        x = x + y;
        return *this;
    }

    Rational operator ++(int) {
        Rational tmp = *this;
        x = x + y;
        return tmp;
    }

    Rational& operator --() {
        x = x - y;
        return *this;
    }

    Rational operator --(int) {
        Rational tmp = *this;
        x = x - y;
        return tmp;
    }

    Rational& operator += (const Rational& a) {
        x = x * a.y + a.x * y;
        y = y * a.y;
        return *this;
    }

    Rational& operator -= (const Rational& a) {
        x = x * a.y - a.x * y;
        y = y * a.y;
        return *this;
    }

    Rational& operator *= (const Rational& a) {
        x = x * a.x;
        y = y * a.y;
        return *this;
    }

    int numerator() const {
        int ans = gcd(x, y);
        if (ans == 0) {
            return 0;
        }
        return x / ans;
    }

    int denominator() const {
        int ans = gcd(x, y);
        if (ans == 0 || x == 0) {
            return 1;
        }
        return abs(y / ans);
    }

    friend Rational operator / (const Rational&, const Rational&);
    Rational& operator /= (const Rational& a) {
        *this = *this / a;
        return *this;
    }
};

bool operator == (const Rational& a, const Rational& b) {
    return (a.numerator() == b.numerator() &&
            a.denominator() == b.denominator());
}

bool operator != (const Rational& a, const Rational& b) {
    return (a.numerator() != b.numerator() ||
            a.denominator() != b.denominator());
}

Rational operator + (const Rational& a, const Rational& b) {
    return Rational(a.numerator() * b.denominator() + b.numerator() * a.denominator(),
            a.denominator() * b.denominator());
}

Rational operator + (const Rational& a) {
    return Rational(a.numerator(), a.denominator());
}

Rational operator - (const Rational& a, const Rational& b) {
    return Rational(a.numerator() * b.denominator() - b.numerator() * a.denominator(),
            a.denominator() * b.denominator());
}

Rational operator - (const Rational& a) {
    return Rational(a.numerator() * (-1), a.denominator());
}

Rational operator * (const Rational& a, const Rational& b) {
    return Rational(a.numerator() * b.numerator(),
            a.denominator() * b.denominator());
}

Rational operator / (const Rational& a, const Rational& b) {
    return Rational(a.numerator() * b.denominator(),
            a.denominator() * b.numerator());
}
