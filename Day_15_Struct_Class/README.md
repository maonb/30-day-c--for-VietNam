# Day 15: Struct & Class cơ bản

## 🎯 Mục tiêu
- Hiểu `struct` và `class`
- Access modifiers: `public`, `private`, `protected`
- Constructor và Destructor

## 📖 Lý thuyết

### Struct
```cpp
struct Point {
    double x, y;
};
Point p = {3.0, 4.0};
```

### Class
```cpp
class Student {
private:
    std::string name;
    int age;

public:
    // Constructor
    Student(std::string n, int a) : name(n), age(a) {}

    // Destructor
    ~Student() { std::cout << "Destroyed" << std::endl; }

    void display() {
        std::cout << name << " - " << age << std::endl;
    }
};
```

### Constructor types
```cpp
Student();                          // Default
Student(std::string n, int a);     // Parameterized
Student(const Student& other);     // Copy constructor
```

## ✏️ Bài tập
1. Tạo class `Rectangle` với width, height, tính diện tích và chu vi
2. Tạo class `BankAccount` với deposit, withdraw, getBalance
3. Tìm hiểu sự khác biệt `struct` vs `class` trong C++
