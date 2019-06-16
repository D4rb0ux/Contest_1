#include<iostream>
#include<vector>
#include <algorithm>
#include <cassert>

using namespace std;

template <typename T>
class MatrixIterator;

template <typename T>
class MatrixConstIterator;

template <typename T>
class Matrix {
    vector<vector<T>> data;

public:
    Matrix(const vector<vector<T>>& v) {
        size_t s1 = v.size();
        size_t s2 = v[0].size();
        data.resize(s1, vector<T>(s2));
        for (size_t i = 0; i < s1; i++) {
            for (size_t j = 0; j < s2; j++) {
                data[i][j] = v[i][j];
            }
        }
    }

    pair<size_t, size_t> size() const {
        pair<size_t, size_t> s;
        s.first = data.size();
        s.second = data[0].size();
        return s;
    }

    const vector<vector<T>>& GetData() const {
        return data;
    }

    Matrix& operator+= (const Matrix& m) {
        size_t s1 = m.size().first;
        size_t s2 = m.size().second;
        for (size_t i = 0; i < s1; i++) {
            for (size_t j = 0; j < s2; j++) {
                data[i][j] += m.data[i][j];
            }
        }
        return *this;
    }

    Matrix operator+ (const Matrix& m) const {
        size_t s1 = m.size().first;
        size_t s2 = m.size().second;
        vector<vector<T>> mat(s1, vector<T>(s2));
        for (size_t i = 0; i < s1; i++) {
            for (size_t j = 0; j < s2; j++) {
                mat[i][j] = m.data[i][j] + data[i][j];
            }
        }
        return Matrix(mat);
    }

    template <typename t>
    Matrix& operator*= (const t& a) {
        size_t s1 = this->size().first;
        size_t s2 = this->size().second;
        for (size_t i = 0; i < s1; i++) {
            for (size_t j = 0; j < s2; j++) {
                data[i][j] *= a;
            }
        }
        return *this;
    }

    template <typename t>
    Matrix operator* (const t& a) const {
        size_t s1 = this->size().first;
        size_t s2 = this->size().second;
        vector<vector<T>> mat(s1, vector<T>(s2));
        for (size_t i = 0; i < s1; i++) {
            for (size_t j = 0; j < s2; j++) {
                mat[i][j] = data[i][j] * a;
            }
        }
        return Matrix(mat);
    }

    Matrix& transpose() {
        size_t s1 = this->size().first;
        size_t s2 = this->size().second;
        vector<vector<T>> mat(s2, vector<T>(s1));
        for (size_t i = 0; i < s2; i++) {
            for (size_t j = 0; j < s1; j++) {
                mat[i][j] = data[j][i];
            }
        }
        data = mat;
        return *this;
    }

    Matrix transposed() const {
        size_t s1 = this->size().first;
        size_t s2 = this->size().second;
        vector<vector<T>> mat(s2, vector<T>(s1));
        for (size_t i = 0; i < s2; i++) {
            for (size_t j = 0; j < s1; j++) {
                mat[i][j] = data[j][i];
            }
        }
        return Matrix(mat);
    }

    Matrix& operator *= (const Matrix& other) {
        size_t s1 = this->size().first;
        size_t s2 = this->size().second;
        size_t m1 = other.size().first;
        size_t m2 = other.size().second;
        assert(s2 == m1);
        vector<vector<T>> mat(s1, vector<T>(m2));
        for (size_t i = 0; i < s1; i++) {
            for (size_t j = 0; j < m2; j++) {
                T elem = 0;
                for (size_t k = 0; k < s2; k++) {
                    elem += data[i][k] * other.data[k][j];
                }
                mat[i][j] = elem;
            }
        }
        data = mat;
        return *this;
    }

    Matrix operator * (const Matrix& other) const {
        size_t s1 = this->size().first;
        size_t s2 = this->size().second;
        size_t m1 = other.size().first;
        size_t m2 = other.size().second;
        assert(s2 == m1);
        vector<vector<T>> mat(s1, vector<T>(m2));
        for (size_t i = 0; i < s1; i++) {
            for (size_t j = 0; j < m2; j++) {
                T elem = 0;
                for (size_t k = 0; k < s2; k++) {
                    elem += data[i][k] * other.data[k][j];
                }
                mat[i][j] = elem;
            }
        }
        return mat;
    }

    const vector<T>& operator[] (size_t row) const {
        return data[row];
    }

    vector<T>& operator[] (size_t row) {
        return data[row];
    }

    MatrixIterator<T> begin() {
        return {*this, 0, 0};
    }

    MatrixIterator<T> end() {
        size_t s = this->size().first;
        return {*this, s, 0};
    }

    MatrixConstIterator<T> begin() const {
        return {*this, 0, 0};
    }

    MatrixConstIterator<T> end() const {
        size_t s = this->size().first;
        return {*this, s, 0};
    }
};

template <typename T>
ostream& operator<< (ostream& out, const Matrix<T>& m) {
    size_t s1 = m.size().first;
    size_t s2 = m.size().second;
    for (size_t i = 0; i < s1; i++) {
        if (i > 0)
            out << "\n";
        for (size_t j = 0; j < s2; j++) {
            if (j > 0)
                out << "\t";
            out << m.GetData()[i][j];
        }
    }
    return out;
}

template <typename T>
class MatrixIterator {
    Matrix<T>& matrix;
    size_t row, column;

public:
    MatrixIterator(Matrix<T>& m, size_t i, size_t j) : matrix(m), row(i), column(j) {}

    bool operator== (MatrixIterator it) const {
        return row == it.row && column == it.column;
    }

    bool operator != (MatrixIterator it) const {
        return !(*this == it);
    }

    T& operator * () {
        return matrix[row][column];
    }

    MatrixIterator& operator++ () {
        ++column;
        if (column == matrix.size().second) {
            ++row;
            column = 0;
        }
        return *this;
    }
};

template <typename T>
class MatrixConstIterator {
    const Matrix<T>& matrix;
    size_t row, column;

public:
    MatrixConstIterator(const Matrix<T>& m, size_t i, size_t j) : matrix(m), row(i), column(j) {}

    bool operator== (MatrixConstIterator it) const {
        return row == it.row && column == it.column;
    }

    bool operator != (MatrixConstIterator it) const {
        return !(*this == it);
    }

    const T& operator * () const {
        return matrix[row][column];
    }

    MatrixConstIterator& operator++ () {
        ++column;
        if (column == matrix.size().second) {
            ++row;
            column = 0;
        }
        return *this;
    }
};
