#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class Polynomial {
    vector<T> coeff;

public:
    Polynomial(const vector<T>& v) {
        size_t n = v.size();
        coeff.resize(n);
        for (size_t i = 0; i < n; i++)
            coeff[i] = v[i];
        size_t i = n - 1;
        auto it = coeff.end() - 1;
        while (i >= 1 && coeff[i] == T(0)) {
            coeff.erase(it);
            it--;
            i--;
        }
    }

    Polynomial(const T& c) {
        coeff.push_back(c);
    }

    template <typename Iter>
    Polynomial(Iter beg, Iter end) {
        while (beg != end) {
            coeff.push_back(*beg);
            beg++;
        }
        size_t i = coeff.size() - 1;
        auto it = coeff.end() - 1;
        while (i >= 1 && coeff[i] == T(0)) {
            coeff.erase(it);
            it--;
            i--;
        }
    }

    Polynomial() {
        coeff.push_back(T(0));
    }

    bool operator== (const Polynomial& p) const {
        return coeff == p.coeff;
    }

    bool operator != (const Polynomial& p) const {
        return !(*this == p);
    }

    bool operator!= (const T& c) const {
        Polynomial p(c);
        return *this != p;
    }

    vector<T> GetCoeff() const {
        return coeff;
    }

    Polynomial operator+ (const Polynomial& p) const {
        vector<T> v = coeff;
        size_t n = min(coeff.size(), p.GetCoeff().size());
        for (size_t i = 0; i < n; i++) {
            v[i] += p[i];
        }
        if (coeff.size() < p.GetCoeff().size()) {
            for (size_t i = n; i < p.GetCoeff().size(); i++)
                v.push_back(p[i]);
        }
        return Polynomial(v);
    }

    Polynomial& operator+= (const Polynomial& p) {
        size_t n = min(coeff.size(), p.GetCoeff().size());
        for (size_t i = 0; i < n; i++) {
            coeff[i] += p[i];
        }
        if (coeff.size() < p.GetCoeff().size()) {
            for (size_t i = n; i < p.GetCoeff().size(); i++)
                coeff.push_back(p[i]);
        }
        size_t i = coeff.size() - 1;
        auto it = coeff.end() - 1;
        while (i >= 1 && coeff[i] == T(0)) {
            coeff.erase(it);
            it--;
            i--;
        }
        return *this;
    }

    Polynomial operator- (const Polynomial& p) const {
        vector<T> v = coeff;
        size_t n = min(coeff.size(), p.GetCoeff().size());
        for (size_t i = 0; i < n; i++) {
            v[i] -= p[i];
        }
        if (coeff.size() < p.GetCoeff().size()) {
            for (size_t i = n; i < p.GetCoeff().size(); i++)
                v.push_back(T(0)-p[i]);
        }
        return Polynomial(v);
    }

    Polynomial& operator-= (const Polynomial& p) {
        size_t n = min(coeff.size(), p.GetCoeff().size());
        for (size_t i = 0; i < n; i++) {
            coeff[i] -= p[i];
        }
        if (coeff.size() < p.GetCoeff().size()) {
            for (size_t i = n; i < p.GetCoeff().size(); i++)
                coeff.push_back(T(0)-p[i]);
        }
        size_t i = coeff.size() - 1;
        auto it = coeff.end() - 1;
        while (i >= 1 && coeff[i] == T(0)) {
            coeff.erase(it);
            it--;
            i--;
        }
        return *this;
    }

    T operator[] (size_t index) const {
        if (index >= coeff.size())
            return T(0);
        return coeff[index];
    }

    long long Degree() const {
        if (coeff.size() == 1 && coeff[0] == T(0))
            return -1;
        return coeff.size() - 1;
    }

    typename vector<T>::const_iterator begin() const {
        return coeff.begin();
    }

    typename vector<T>::const_iterator end() const {
        return coeff.end();
    }

    Polynomial operator* (const Polynomial& p) const {
        size_t m = coeff.size();
        size_t n = p.GetCoeff().size();
        vector<T> product(m + n - 1);
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                product[i + j] += coeff[i] * p.coeff[j];
            }
        }
        return Polynomial(product);
    }

    Polynomial& operator*= (const Polynomial& p) {
        *this = *this * p;
        return *this;
    }

    T operator() (const T& c) const {
        T res = T(0);
        T x = T(1);
        for (size_t i = 0; i < coeff.size(); i++) {
            res += x * coeff[i];
            x *= c;
        }
        return res;
    }

    Polynomial& operator/= (const Polynomial& p) {
        *this = *this / p;
        return *this;
    }

    Polynomial& operator%= (const Polynomial& p) {
        *this = *this % p;
        return *this;
    }
};

template <typename T>
Polynomial<T> operator+ (const Polynomial<T>& p, const T& c) {
    return Polynomial<T>(c) + p;
}

template <typename T>
Polynomial<T> operator+ (const T& c, const Polynomial<T>& p) {
    return Polynomial<T>(c) + p;
}

template <typename T>
Polynomial<T> operator- (const Polynomial<T>& p, const T& c) {
    return p - Polynomial<T>(c);
}

template <typename T>
Polynomial<T> operator- (const T& c, const Polynomial<T>& p) {
    return Polynomial<T>(c) - p;
}

template <typename T>
Polynomial<T> operator* (const Polynomial<T>& p, const T& c) {
    return p * Polynomial<T>(c);
}

template <typename T>
Polynomial<T> operator* (const T& c, const Polynomial<T>& p) {
    return p * Polynomial<T>(c);
}

template <typename T>
ostream& operator<< (ostream& out, const Polynomial<T>& p) {
    int n = p.GetCoeff().size();
    vector<T> ans = p.GetCoeff();
    if (n == 1) {
        out << ans[0];
    } else if (n > 2) {
        if (ans[n - 1] != T(0) && ans[n - 1] != T(-1) && ans[n - 1] != T(1))
            out << ans[n - 1] << "*x^" << n - 1;
        if (ans[n - 1] == T(1))
            out << "x^" << n - 1;
        if (ans[n - 1] == T(-1))
            out << "-x^" << n - 1;
        for (int i = n - 2; i > 0; --i) {
            if (ans[i] > T(0) && ans[i] != T(1) && i != 1)
                out << "+" << ans[i] << "*x^" << i;
            if (ans[i] == T(1) && i != 1)
                out << "+x^" << i;
            if (ans[i] < T(0) && ans[i] != T(-1) && i != 1)
                out << ans[i] << "*x^" << i;
            if (ans[i] == T(-1) && i != 1)
                out << "-x^" << i;
            if (i == 1) {
                if (ans[i] != T(0) && ans[i] != T(-1) && ans[i] != T(1)) {
                    if (ans[i] > T(0))
                        out << "+" << ans[i] << "*x";
                    if (ans[i] < T(0))
                        out << ans[i] << "*x";
                }
                if (ans[i] == T(1)) {
                    out << "+x";
                }
                if (ans[i] == T(-1)) {
                    out << "-x";
                }
            }
        }
        if (ans[0] > T(0))
            out << "+" << ans[0];
        if (ans[0] < T(0))
            out << ans[0];
    } else if (n == 2) {
        if (ans[n - 1] != T(0) && ans[n - 1] != T(-1) && ans[n - 1] != T(1))
            out << ans[n - 1] << "*x";
        if (ans[n - 1] == T(1))
            out << "x";
        if (ans[n - 1] == T(-1))
            out << "-x";
        if (ans[0] > T(0))
            out << "+" << ans[0];
        if (ans[0] < T(0))
            out << ans[0];
    }
    return out;
}

template <typename T>
Polynomial<T> operator& (const Polynomial<T>& f, const Polynomial<T>& g) {
    Polynomial<T> ans = T(0);
    Polynomial<T> poly = T(1);
    size_t n = f.GetCoeff().size();
    for (size_t i = 0; i < n; i++) {
        ans += f.GetCoeff()[i] * poly;
        poly *= g;
    }
    return ans;
}

template <typename T>
Polynomial<T> operator/ (const Polynomial<T>& p1, const Polynomial<T>& p2) {
    if (p1.Degree() < p2.Degree()) {
        return Polynomial<T>(T(0));
    } else {
        long long d = p1.Degree() - p2.Degree();
        vector<T> quotient(d + 1);
        Polynomial<T> dividend = p1;
        while (dividend.Degree() != -1 &&
        dividend.Degree() >= p2.Degree()) {
            long long deg = dividend.Degree() - p2.Degree();
            quotient[deg] = dividend[dividend.Degree()] / p2[p2.Degree()];
            vector<T> tmp(deg + 1);
            tmp.back() = quotient[deg];
            Polynomial<T> temp(tmp);
            temp *= p2;
            dividend -= temp;
        }
        return Polynomial<T>(quotient);
    }
}

template <typename T>
Polynomial<T> operator% (const Polynomial<T>& p1, const Polynomial<T>& p2) {
    if (p1.Degree() < p2.Degree())
        return p1;
    long long d = p1.Degree() - p2.Degree();
    vector<T> quotient(d + 1);
    Polynomial<T> dividend = p1;
    while (dividend.Degree() != -1 &&
           dividend.Degree() >= p2.Degree()) {
        long long deg = dividend.Degree() - p2.Degree();
        quotient[deg] = dividend[dividend.Degree()] / p2[p2.Degree()];
        vector<T> tmp(deg + 1);
        tmp.back() = quotient[deg];
        Polynomial<T> temp(tmp);
        temp *= p2;
        dividend -= temp;
    }
    return dividend;
}

template <typename T>
Polynomial<T> operator, (const Polynomial<T>& p1, const Polynomial<T>& p2) {
    Polynomial<T> poly1 = p1;
    Polynomial<T> poly2 = p2;
    while (poly2 != T(0)) {
        Polynomial<T> tmp = poly2;
        poly2 = poly1 % poly2;
        poly1 = tmp;
    }
    if (poly1.Degree() + 1 > 0) {
        poly1 = poly1 / Polynomial<T>(poly1[poly1.Degree()]);
    }
    return poly1;
}
