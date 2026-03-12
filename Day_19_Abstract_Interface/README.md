# Day 19: Lớp trừu tượng & Interface

## 🎯 Mục tiêu
- Pure virtual functions
- Abstract class
- Interface pattern trong C++

## 📖 Lý thuyết

### Pure Virtual Function & Abstract Class
```cpp
class IShape {  // Interface (abstract class)
public:
    virtual double area() const = 0;       // Pure virtual
    virtual double perimeter() const = 0;  // Pure virtual
    virtual void draw() const = 0;
    virtual ~IShape() {}
};

class Circle : public IShape {
    double r;
public:
    Circle(double radius) : r(radius) {}
    double area() const override { return 3.14159 * r * r; }
    double perimeter() const override { return 2 * 3.14159 * r; }
    void draw() const override { std::cout << "Drawing circle" << std::endl; }
};
```

### Quy tắc
- Không thể tạo object từ abstract class
- Lớp con **phải** override tất cả pure virtual functions
- Abstract class có thể có hàm thường + data members

## ✏️ Bài tập
1. Tạo interface `IAnimal` với `speak()`, `move()`, implement cho `Dog`, `Cat`, `Bird`
2. Tạo interface `ISerializable` với `serialize()`, `deserialize()`
3. Tạo hệ thống payment: `IPayment` → `CreditCard`, `PayPal`, `BankTransfer`
