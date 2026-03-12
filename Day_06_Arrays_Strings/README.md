# Day 06: Mảng & Chuỗi

## 🎯 Mục tiêu
- Khai báo và sử dụng mảng 1D, 2D
- Sử dụng `std::string` và các hàm xử lý chuỗi

## 📖 Lý thuyết

### Mảng 1D
```cpp
int arr[5] = {1, 2, 3, 4, 5};
for (int i = 0; i < 5; i++) {
    std::cout << arr[i] << " ";
}
```

### Mảng 2D
```cpp
int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
```

### std::string
```cpp
#include <string>
std::string s = "Hello C++";
s.length();       // Độ dài
s.substr(0, 5);   // "Hello"
s.find("C++");    // Vị trí
s += " World";    // Nối chuỗi
```

## ✏️ Bài tập
1. Tìm phần tử lớn nhất/nhỏ nhất trong mảng
2. Đảo ngược mảng
3. Đếm số lần xuất hiện của mỗi ký tự trong chuỗi
4. Kiểm tra chuỗi palindrome
