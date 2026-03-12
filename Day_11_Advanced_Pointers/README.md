# Day 11: Con trỏ nâng cao

## 🎯 Mục tiêu
- Con trỏ hàm (function pointers)
- Con trỏ void
- `nullptr` (C++11)

## 📖 Lý thuyết

### Con trỏ hàm
```cpp
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }

int (*funcPtr)(int, int) = add;
std::cout << funcPtr(3, 5);   // 8

funcPtr = sub;
std::cout << funcPtr(3, 5);   // -2
```

### Con trỏ void
```cpp
void* vp;
int x = 10;
vp = &x;
std::cout << *(static_cast<int*>(vp));  // 10
```

### nullptr
```cpp
int* p = nullptr;  // Thay vì NULL hoặc 0
if (p == nullptr) {
    std::cout << "Pointer is null" << std::endl;
}
```

## ✏️ Bài tập
1. Viết hàm nhận con trỏ hàm để áp dụng phép tính lên mảng
2. Tạo mảng con trỏ hàm cho menu calculator
3. So sánh `nullptr` vs `NULL` vs `0`
