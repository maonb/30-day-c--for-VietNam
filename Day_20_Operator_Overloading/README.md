# Day 20: Operator Overloading

## 🎯 Mục tiêu
- Nạp chồng toán tử
- Overload `+`, `-`, `==`, `<<`, `>>`
- Friend functions

## 📖 Lý thuyết

### Operator Overloading
```cpp
class Vector2D {
    double x, y;
public:
    Vector2D(double x = 0, double y = 0) : x(x), y(y) {}

    // Overload +
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    // Overload ==
    bool operator==(const Vector2D& other) const {
        return x == other.x && y == other.y;
    }

    // Friend: overload <<
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
        os << "(" << v.x << ", " << v.y << ")";
        return os;
    }
};
```

## ✏️ Bài tập
1. Tạo class `Fraction` (phân số) với +, -, *, /, ==, <<
2. Tạo class `Matrix` với +, *, <<
3. Overload `[]` cho class `SafeArray` (kiểm tra bounds)
