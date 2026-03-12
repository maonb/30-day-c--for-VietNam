# Day 13: Cấp phát bộ nhớ động

## 🎯 Mục tiêu
- `new` và `delete`
- Mảng động
- Giới thiệu smart pointers

## 📖 Lý thuyết

### new / delete
```cpp
int* p = new int(42);       // Cấp phát 1 biến
delete p;                    // Giải phóng

int* arr = new int[10];      // Cấp phát mảng
delete[] arr;                // Giải phóng mảng
```

### Memory Leak
```cpp
void leak() {
    int* p = new int(10);
    // Quên delete → memory leak!
}
```

### Smart Pointers (giới thiệu)
```cpp
#include <memory>
auto p = std::make_unique<int>(42);  // Tự giải phóng
std::cout << *p;
// Không cần delete!
```

## ✏️ Bài tập
1. Tạo mảng động, nhập dữ liệu, sắp xếp, giải phóng
2. Tạo ma trận 2D động (dùng `new`)
3. Viết chương trình gây memory leak và dùng Valgrind kiểm tra
