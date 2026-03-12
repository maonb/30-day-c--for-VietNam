# Day 24: STL Iterators & Algorithms

## 🎯 Mục tiêu
- Iterators
- STL Algorithms: `sort`, `find`, `for_each`, `transform`
- Lambda expressions

## 📖 Lý thuyết

### Iterators
```cpp
std::vector<int> v = {5, 3, 1, 4, 2};
for (auto it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << " ";
}
```

### Algorithms
```cpp
#include <algorithm>
std::sort(v.begin(), v.end());              // Sắp xếp
auto it = std::find(v.begin(), v.end(), 3); // Tìm kiếm
int count = std::count(v.begin(), v.end(), 4); // Đếm
std::reverse(v.begin(), v.end());           // Đảo ngược
```

### Lambda Expressions
```cpp
auto square = [](int x) { return x * x; };
std::cout << square(5);  // 25

// Sắp xếp giảm dần
std::sort(v.begin(), v.end(), [](int a, int b) {
    return a > b;
});

// for_each
std::for_each(v.begin(), v.end(), [](int x) {
    std::cout << x << " ";
});
```

## ✏️ Bài tập
1. Sắp xếp vector struct theo nhiều tiêu chí (dùng lambda)
2. Dùng `transform` để tạo vector mới từ vector cũ
3. Viết hàm `filter` dùng lambda
4. Dùng `accumulate` tính tổng/trung bình
