# Day 04: Câu lệnh điều kiện

## 🎯 Mục tiêu
- Sử dụng `if`, `else if`, `else`
- Sử dụng `switch/case`
- Toán tử 3 ngôi `?:`

## 📖 Lý thuyết

### if / else
```cpp
int score = 85;
if (score >= 90) {
    std::cout << "Xuat sac" << std::endl;
} else if (score >= 70) {
    std::cout << "Kha" << std::endl;
} else {
    std::cout << "Trung binh" << std::endl;
}
```

### switch / case
```cpp
int choice = 2;
switch (choice) {
    case 1: std::cout << "Option 1"; break;
    case 2: std::cout << "Option 2"; break;
    default: std::cout << "Invalid";
}
```

### Toán tử 3 ngôi
```cpp
int x = 10;
std::string result = (x > 0) ? "Duong" : "Am hoac 0";
```

## ✏️ Bài tập
1. Xếp loại học sinh theo điểm (A, B, C, D, F)
2. Kiểm tra năm nhuận
3. Tìm số lớn nhất trong 3 số
