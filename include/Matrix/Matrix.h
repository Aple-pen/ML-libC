#pragma once
#include <utility>
#include "Matrix/MatrixFunc.h"

typedef struct {
    size_t rows;
    size_t cols;
}Shape;

template<typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data;

public:
    Matrix() = default;
    Matrix(size_t rows, size_t cols, T init = T()) {
        data = std::vector<std::vector<T>>(rows, std::vector<T>(cols, init));
    }

    // 접근 연산자
    std::vector<T>& operator[](size_t i) { return data[i]; }
    const std::vector<T>& operator[](size_t i) const { return data[i]; }

    // 행/열 개수
    size_t rows() const { return data.size(); }
    size_t cols() const { return data.empty() ? 0 : data[0].size(); }

    // 예시: 전치
    Matrix<T> transpose() const {
        size_t r = rows(), c = cols();
        Matrix<T> result(c, r);
        for (size_t i = 0; i < r; ++i)
            for (size_t j = 0; j < c; ++j)
                result[j][i] = data[i][j];
        return result;
    }

    Shape shape(){
        Shape s;
        s.rows = rows();
        s.cols = cols();
        return s;
    }

    // 직접 데이터 접근하고 싶으면 getter
    const std::vector<std::vector<T>>& raw() const { return data; }

    //push_back wrapping
    void push_back(const std::vector<T>& vecData){
        data.push_back(vecData);
    }
};

#include "Matrix/OperatorOverloads.h"