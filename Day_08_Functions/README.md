# Day 08: Hàm (Functions)

## 🎯 Mục tiêu
- Khai báo và định nghĩa hàm
- Hiểu tham số và giá trị trả về
- Phân biệt pass by value vs pass by reference

## 📖 Lý thuyết

### Cú pháp hàm
```cpp
// Khai báo (prototype)
int add(int a, int b);

// Định nghĩa
int add(int a, int b) {
    return a + b;
}

// Gọi hàm
int result = add(3, 5);  // result = 8
```

### Hàm void
```cpp
void greet(std::string name) {
    std::cout << "Hello, " << name << "!" << std::endl;
}
```

### Pass by value vs reference
```cpp
void byValue(int x) { x = 100; }       // Không thay đổi bên ngoài
void byRef(int& x) { x = 100; }        // Thay đổi bên ngoài
```

## ✏️ Bài tập
1. Viết hàm kiểm tra số nguyên tố
2. Viết hàm tính UCLN (GCD) bằng thuật toán Euclid
3. Viết hàm swap 2 số bằng tham chiếu
