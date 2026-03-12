# Day 05: Vòng lặp

## 🎯 Mục tiêu
- Sử dụng `for`, `while`, `do-while`
- Hiểu `break` và `continue`
- Vòng lặp lồng nhau

## 📖 Lý thuyết

### for loop
```cpp
for (int i = 0; i < 10; i++) {
    std::cout << i << " ";
}
```

### while loop
```cpp
int n = 5;
while (n > 0) {
    std::cout << n-- << " ";
}
```

### do-while loop
```cpp
int input;
do {
    std::cout << "Nhap so duong: ";
    std::cin >> input;
} while (input <= 0);
```

### Range-based for (C++11)
```cpp
int arr[] = {1, 2, 3, 4, 5};
for (int x : arr) {
    std::cout << x << " ";
}
```

## ✏️ Bài tập
1. In bảng cửu chương
2. Tính giai thừa n!
3. In tam giác Pascal
4. Tìm số nguyên tố từ 1 đến N
