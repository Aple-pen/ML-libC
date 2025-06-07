#pragma once

#include <vector>

// void train_test_split(
//     *arrays,
//     test_size=None,
//     train_size=None,
//     random_state=None,
//     shuffle=True,
//     stratify=None,
// );
template <typename T>
void train_test_split(
    const std::vector<std::vector<T>>& X,       // 입력 데이터 (n x m)
    const std::vector<int>& y,                    // 라벨 (n)
    double test_size,
    unsigned int random_seed);


template <typename T>
void train_test_split(
    const std::vector<std::vector<T>>& X,       // 입력 데이터 (n x m)
    const std::vector<int>& y,                    // 라벨 (n)
    unsigned int random_seed);