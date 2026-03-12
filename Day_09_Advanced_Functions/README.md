# Day 09: Hàm nâng cao

## 🎯 Mục tiêu
- Function overloading
- Default parameters
- Inline functions
- Đệ quy (Recursion)

## 📖 Lý thuyết

### Function Overloading
```cpp
int add(int a, int b) { return a + b; }
double add(double a, double b) { return a + b; }
int add(int a, int b, int c) { return a + b + c; }
```

### Default Parameters
```cpp
void print(std::string msg, int times = 1) {
    for (int i = 0; i < times; i++)
        std::cout << msg << std::endl;
}
```

### Đệ quy
```cpp
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
```

## ✏️ Bài tập
1. Overload hàm `area()` cho hình vuông, hình chữ nhật, hình tròn
2. Viết hàm đệ quy tính tổng các chữ số
3. Viết hàm đệ quy in dãy Fibonacci
4. Giải bài Tháp Hà Nội bằng đệ quy
