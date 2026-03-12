# Day 17: Kế thừa (Inheritance)

## 🎯 Mục tiêu
- Single inheritance
- Multilevel inheritance
- Access control trong kế thừa

## 📖 Lý thuyết

### Single Inheritance
```cpp
class Animal {
protected:
    std::string name;
public:
    Animal(std::string n) : name(n) {}
    void eat() { std::cout << name << " is eating" << std::endl; }
};

class Dog : public Animal {
public:
    Dog(std::string n) : Animal(n) {}
    void bark() { std::cout << name << " says Woof!" << std::endl; }
};
```

### Access Control
| Base class | public | protected | private |
|-----------|--------|-----------|---------|
| public    | public | protected | ❌ |
| protected | protected | protected | ❌ |
| private   | private | private | ❌ |

## ✏️ Bài tập
1. Tạo hệ thống `Shape` → `Circle`, `Rectangle`, `Triangle`
2. Tạo hệ thống `Vehicle` → `Car`, `Bike`
3. Multilevel: `Animal` → `Mammal` → `Dog`
