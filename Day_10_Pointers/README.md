# Day 10: Con trỏ (Pointers)

## 🎯 Mục tiêu
- Hiểu con trỏ, toán tử `*` và `&`
- Con trỏ và mảng
- Toán tử số học con trỏ

## 📖 Lý thuyết

### Con trỏ cơ bản
```cpp
int x = 42;
int* ptr = &x;         // ptr lưu địa chỉ của x

std::cout << ptr;      // Địa chỉ: 0x7fff...
std::cout << *ptr;     // Giá trị: 42 (dereference)
*ptr = 100;            // x bây giờ = 100
```

### Con trỏ và mảng
```cpp
int arr[] = {10, 20, 30};
int* p = arr;          // p trỏ đến arr[0]
std::cout << *(p + 1); // 20 (arr[1])
```

### Con trỏ hằng
```cpp
const int* p1 = &x;    // Không thay đổi giá trị qua p1
int* const p2 = &x;    // Không thay đổi địa chỉ p2 trỏ đến
```

## ✏️ Bài tập
1. Viết hàm swap dùng con trỏ
2. Duyệt mảng bằng con trỏ
3. Tìm phần tử lớn nhất dùng con trỏ
