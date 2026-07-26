CMAKE_MINIMUM_REQUIRED(VERSION 3.28)
PROJECT(Ch04_Ex01)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(Ch04_Ex01
  src/Student_info.cpp
  src/grade.cpp
  src/main.cpp
  src/median.cpp
)

target_include_directories(Ch04_Ex01 PUBLIC include)
