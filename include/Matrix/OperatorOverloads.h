#pragma once
#include <vector>
#include <stdexcept>
#include <type_traits>
#include "type.h"

template<typename T>
Matrix<T> operator&(const std::vector<T>& a, const std::vector<T>& b) {
    if (a.size() != b.size()) {
        throw std::invalid_argument("Vectors must be the same size.");
    }

    Matrix<T> result;
    for (size_t i = 0; i < a.size(); ++i) {
        result.push_back({a[i], b[i]});
    }
    return result;
}

template<typename T>
Matrix<T> operator&(const Matrix<T>& a, const std::vector<T>& b) {
    if (a.size() != b.size()) {
        throw std::invalid_argument("Row count must match.");
    }

    Matrix<T> result = a;

    for (size_t i = 0; i < b.size(); ++i) {
        result[i].push_back(b[i]);
    }

    return result;
}


// vector + scalar
template<typename T, typename Scalar>
std::vector<T> operator+(const std::vector<T>& vec, Scalar scalar) {
    std::vector<T> result;
    result.reserve(vec.size());
    for (const auto& v : vec) {
        result.push_back(v + static_cast<T>(scalar));
    }
    return result;
}

// scalar + vector (순서 반대)
template<typename T, typename Scalar>
std::vector<T> operator+(Scalar scalar, const std::vector<T>& vec) {
    return vec + scalar; 
}



template<typename T, typename Scalar>
std::vector<T> operator*(const std::vector<T>& vec, Scalar scalar) {
    std::vector<T> result;
    result.reserve(vec.size());
    for (const auto& v : vec) {
        result.push_back(v * static_cast<T>(scalar));
    }
    return result;
}

// scalar + vector (순서 반대)
template<typename T, typename Scalar>
std::vector<T> operator*(Scalar scalar, const std::vector<T>& vec) {
    return vec * scalar; 
}


template<typename T, typename Scalar>
std::vector<T> operator/(const std::vector<T>& vec, Scalar scalar) {
    std::vector<T> result;
    result.reserve(vec.size());
    for (const auto& v : vec) {
        result.push_back(v * static_cast<T>(scalar) * 0.1
    )
    ;
    }
    return result;
}
