# Day 18: Đa hình (Polymorphism)

## 🎯 Mục tiêu
- Function overriding
- Virtual functions
- `override` và `final` keywords

## 📖 Lý thuyết

### Virtual Functions
```cpp
class Shape {
public:
    virtual double area() const {
        return 0;
    }
    virtual ~Shape() {}  // Virtual destructor!
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return 3.14159 * radius * radius;
    }
};

// Polymorphism
Shape* s = new Circle(5);
std::cout << s->area();  // 78.5397 (gọi Circle::area)
delete s;
```

### final keyword
```cpp
class Base {
    virtual void foo() final;  // Không thể override
};

class Derived final : public Base {  // Không thể kế thừa tiếp
};
```

## ✏️ Bài tập
1. Tạo mảng `Shape*`, tính tổng diện tích các hình
2. Tạo hệ thống `Employee` với tính lương khác nhau (polymorphism)
3. Giải thích tại sao cần virtual destructor
