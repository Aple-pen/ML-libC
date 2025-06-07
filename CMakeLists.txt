cmake_minimum_required(VERSION 3.14)

# 프로젝트 정보
project(
  ML-libC
  VERSION 0.1
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(KNeighbors  ${PROJECT_SOURCE_DIR}/models/KNeighbors)

add_executable (ML-libC main.cpp 
                ${KNeighbors}/Classifier.cpp  
                ${PROJECT_SOURCE_DIR}/utils/ReadCsv.cpp)

target_include_directories(ML-libC 
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/models
    PRIVATE
        ${PROJECT_SOURCE_DIR}/interfaces
        ${PROJECT_SOURCE_DIR}/utils
)