#ifndef MATRIX_H
#define MATRIX_H

#include <stdexcept>

template <typename T>
class Matrix
{
public:
    Matrix(size_t r, size_t c)
        : rows_(r), cols_(c)
    {
        if (r == 0 || c == 0)
            throw std::invalid_argument("Invalid matrix size");

        buffer_ = new T[r * c];
        for (size_t i = 0; i < r * c; ++i)
            buffer_[i] = T();
    }

    Matrix(const Matrix& m)
        : rows_(m.rows_), cols_(m.cols_)
    {
        buffer_ = new T[rows_ * cols_];
        for (size_t i = 0; i < rows_ * cols_; ++i)
            buffer_[i] = m.buffer_[i];
    }

    Matrix& operator=(const Matrix& m)
    {
        if (this == &m)
            return *this;

        delete[] buffer_;

        rows_ = m.rows_;
        cols_ = m.cols_;
        buffer_ = new T[rows_ * cols_];

        for (size_t i = 0; i < rows_ * cols_; ++i)
            buffer_[i] = m.buffer_[i];

        return *this;
    }

    ~Matrix()
    {
        delete[] buffer_;
    }

    size_t rowCount() const
    {
        return rows_;
    }
    size_t colCount() const
    {
        return cols_;
    }

    T& element(size_t r, size_t c)
    {
        checkIndex(r, c);
        return buffer_[r * cols_ + c];
    }

    const T& element(size_t r, size_t c) const
    {
        checkIndex(r, c);
        return buffer_[r * cols_ + c];
    }

    Matrix add(const Matrix& other) const
    {
        if (rows_ != other.rows_ || cols_ != other.cols_)
            throw std::invalid_argument("Size mismatch");

        Matrix result(rows_, cols_);
        for (size_t i = 0; i < rows_ * cols_; ++i)
            result.buffer_[i] = buffer_[i] + other.buffer_[i];

        return result;
    }

    Matrix multiply(const T& scalar) const
    {
        Matrix result(rows_, cols_);
        for (size_t i = 0; i < rows_ * cols_; ++i)
            result.buffer_[i] = buffer_[i] * scalar;

        return result;
    }

    Matrix multiply(const Matrix& other) const
    {
        if (cols_ != other.rows_)
            throw std::invalid_argument("Bad dimensions");

        Matrix result(rows_, other.cols_);

        for (size_t i = 0; i < rows_; ++i)
            for (size_t j = 0; j < other.cols_; ++j)
            {
                T value = T();
                for (size_t k = 0; k < cols_; ++k)
                    value = value + element(i, k) * other.element(k, j);

                result.element(i, j) = value;
            }

        return result;
    }

    Matrix transposed() const
    {
        Matrix t(cols_, rows_);
        for (size_t i = 0; i < rows_; ++i)
            for (size_t j = 0; j < cols_; ++j)
                t.element(j, i) = element(i, j);

        return t;
    }

private:
    void checkIndex(size_t r, size_t c) const
    {
        if (r >= rows_ || c >= cols_)
            throw std::out_of_range("Index out of range");
    }

    size_t rows_;
    size_t cols_;
    T* buffer_;
};

#endif
