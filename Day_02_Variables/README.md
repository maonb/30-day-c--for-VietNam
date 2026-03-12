# Day 02: Biến & Kiểu dữ liệu

## 🎯 Mục tiêu
- Hiểu cách khai báo biến
- Nắm vững các kiểu dữ liệu cơ bản
- Sử dụng `auto` và `const`

## 📖 Lý thuyết

### Các kiểu dữ liệu cơ bản
| Kiểu | Kích thước | Ví dụ |
|------|-----------|-------|
| `int` | 4 bytes | `int age = 25;` |
| `float` | 4 bytes | `float pi = 3.14f;` |
| `double` | 8 bytes | `double pi = 3.14159;` |
| `char` | 1 byte | `char grade = 'A';` |
| `bool` | 1 byte | `bool isActive = true;` |
| `std::string` | dynamic | `std::string name = "C++";` |

### Từ khóa hữu ích
```cpp
const int MAX = 100;     // Hằng số, không thay đổi được
auto x = 42;             // Tự suy luận kiểu (int)
auto name = "Hello"s;    // std::string (C++14)
```

## ✏️ Bài tập
1. Khai báo biến cho thông tin cá nhân (tên, tuổi, chiều cao, cân nặng)
2. Tính diện tích hình tròn với `r` nhập từ bàn phím
3. Tìm hiểu `sizeof()` cho mỗi kiểu dữ liệu
