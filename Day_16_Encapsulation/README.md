# Day 16: Encapsulation & Getter/Setter

## 🎯 Mục tiêu
- Đóng gói dữ liệu (Encapsulation)
- Getter / Setter methods
- Con trỏ `this`

## 📖 Lý thuyết

### Encapsulation
```cpp
class Person {
private:
    std::string name;
    int age;

public:
    // Getter
    std::string getName() const { return name; }
    int getAge() const { return age; }

    // Setter với validation
    void setAge(int a) {
        if (a > 0 && a < 150) age = a;
    }
};
```

### this pointer
```cpp
class Counter {
    int count;
public:
    Counter& increment() {
        this->count++;
        return *this;  // Method chaining
    }
};
```

## ✏️ Bài tập
1. Tạo class `Employee` với validation cho salary (> 0)
2. Implement method chaining cho class `StringBuilder`
3. Tạo class `Date` với validation cho ngày/tháng/năm
