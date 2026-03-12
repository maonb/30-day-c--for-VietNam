# Day 29: Namespace, Preprocessor & Makefile

## 🎯 Mục tiêu
- Namespace
- Preprocessor directives
- Biên dịch đa file với Makefile

## 📖 Lý thuyết

### Namespace
```cpp
namespace Math {
    const double PI = 3.14159;
    double circleArea(double r) { return PI * r * r; }
}

// Sử dụng
std::cout << Math::PI;
std::cout << Math::circleArea(5);

// Hoặc: using namespace Math; (không khuyến khích trong header)
```

### Preprocessor
```cpp
#define MAX_SIZE 100
#define SQUARE(x) ((x) * (x))

// Include guard
#ifndef MYHEADER_H
#define MYHEADER_H
// ... declarations ...
#endif

// C++17: dùng #pragma once thay thế
#pragma once
```

### Multi-file compilation
```
// math_utils.h
#pragma once
int add(int a, int b);

// math_utils.cpp
#include "math_utils.h"
int add(int a, int b) { return a + b; }

// main.cpp
#include "math_utils.h"
int main() { std::cout << add(3, 5); }
```

### Makefile
```makefile
CXX = g++
CXXFLAGS = -std=c++17 -Wall

main: main.o math_utils.o
	$(CXX) -o main main.o math_utils.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

math_utils.o: math_utils.cpp math_utils.h
	$(CXX) $(CXXFLAGS) -c math_utils.cpp

clean:
	rm -f *.o main
```

## ✏️ Bài tập
1. Tổ chức code multi-file cho 1 project trước đó
2. Viết Makefile để build
3. Tạo namespace riêng cho utility functions
