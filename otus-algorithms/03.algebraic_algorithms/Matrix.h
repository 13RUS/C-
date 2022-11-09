//
// Created by Aleksey Leshchankin on 08.11.2022.
//
#include <vector>
class Matrix {
    size_t mRows;
    size_t mCols;
    std::vector<double> mData;

public:
    Matrix(size_t rows, size_t cols);
    double& operator()(size_t i, size_t j);
    double operator()(size_t i, size_t j) const;

    Matrix operator*(Matrix &M);

    int fastmultiplication (size_t n);

    friend std::ostream &operator<<(std::ostream &, Matrix&);
};

// ---------------------------------------
Matrix::Matrix(size_t rows, size_t cols)
        : mRows(rows),
          mCols(cols),
          mData(rows * cols)
{
}

// ---------------------------------------
double& Matrix::operator()(size_t i, size_t j)
{
    return mData[i * mCols + j];
}

// ---------------------------------------
double Matrix::operator()(size_t i, size_t j) const
{
    return mData[i * mCols + j];
}

// ---------------------------------------
Matrix Matrix::operator*(Matrix &M) {
    Matrix tmp(mRows,M.mCols);

    for(size_t i = 0; i < mRows; i++){
        for(size_t j = 0; j < M.mCols; j++){
            for(size_t k = 0; k < mCols && k < M.mRows; k++){
                tmp(i,j) += (*this)(i,k)*M(k,j);
            }
        }
    }
    return tmp;
}

// ---------------------------------------
std::ostream &operator<<(std::ostream &out, Matrix &m)
{
    for(size_t i = 0; i < m.mRows; i++){
        for(size_t j = 0; j < m.mCols; j++)
            std::cout << m(i,j) <<" ";
        std::cout << std::endl;
    }

    return out;
}

// ---------------------------------------
int Matrix::fastmultiplication(size_t n) {

    int a = mData [0], b = mData [1], c = mData [2], d = mData [3];
    int ta, tb, tc, rc = 0, rd = 1;

    while (n) {
        if (n & 1) {
            tc = rc;
            rc = rc * a + rd * c;
            rd = tc * b + rd * d;
        }

        ta = a;
        tb = b;
        tc = c;
        a = a * a + b * c;
        b = ta * b + b * d;
        c = c * ta + d * c;
        d = tc * tb + d * d;
        n >>= 1;
    }
    return rc;
}