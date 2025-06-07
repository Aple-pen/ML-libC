#pragma once

#include <vector>
#include <unordered_map>
#include <random>
#include "Matrix/Matrix.h"

template <typename T, typename K>
struct SplitData {
    Matrix<T> X_train;
    Matrix<T> X_test;
    std::vector<K> y_train;
    std::vector<K> y_test;
};
template <typename T, typename K>
SplitData<T, K> train_test_split(
    const Matrix<T> &x,      // 입력 데이터 (n x m)
    const std::vector<K> &y, // 라벨 (n)
    double test_size = 0.25,
    unsigned int random_seed =42)
{
    if (x.rows() != y.size())
    {
        throw std::invalid_argument("Row count must match.");
    }

    std::unordered_map<K, std::vector<size_t>> label_to_indices;

    // 1. 라벨별로 인덱스 그룹화
    for (size_t i = 0; i < y.size(); ++i) {
        label_to_indices[y[i]].push_back(i);
    }

    // 2. 섞기 위한 랜덤 시드 설정
    std::mt19937 rng(random_seed);
    // 3. 훈련/테스트 분리
    SplitData<T, K> split;

    for (const auto& [label, indices] : label_to_indices) {
        std::vector<size_t> idx = indices;
        std::shuffle(idx.begin(), idx.end(), rng);

        size_t n_test = static_cast<size_t>(idx.size() * test_size);
        size_t n_train = idx.size() - n_test;

        for (size_t i = 0; i < n_train; ++i) {
            split.X_train.push_back(x[idx[i]]);
            split.y_train.push_back(y[idx[i]]);
        }
        for (size_t i = n_train; i < idx.size(); ++i) {
            split.X_test.push_back(x[idx[i]]);
            split.y_test.push_back(y[idx[i]]);
        }
    }



    return split;
}