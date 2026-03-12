# Day 03: Toán tử & Biểu thức

## 🎯 Mục tiêu
- Sử dụng các toán tử số học, so sánh, logic
- Hiểu toán tử bitwise
- Nắm vững ép kiểu (type casting)

## 📖 Lý thuyết

### Toán tử số học
```cpp
int a = 10, b = 3;
a + b;   // 13 - cộng
a - b;   // 7  - trừ
a * b;   // 30 - nhân
a / b;   // 3  - chia (nguyên)
a % b;   // 1  - chia lấy dư
```

### Toán tử so sánh
`==`, `!=`, `<`, `>`, `<=`, `>=`

### Toán tử logic
`&&` (AND), `||` (OR), `!` (NOT)

### Toán tử bitwise
`&`, `|`, `^`, `~`, `<<`, `>>`

### Ép kiểu
```cpp
int a = 10, b = 3;
double result = static_cast<double>(a) / b;  // 3.333...
```

## ✏️ Bài tập
1. Viết máy tính đơn giản (+, -, *, /)
2. Kiểm tra số chẵn/lẻ bằng toán tử `%`
3. Swap 2 số bằng toán tử XOR (không dùng biến tạm)
