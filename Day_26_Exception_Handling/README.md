# Day 26: Exception Handling

## 🎯 Mục tiêu
- `try`, `catch`, `throw`
- Standard exceptions
- Custom exceptions

## 📖 Lý thuyết

### try / catch / throw
```cpp
try {
    int age;
    std::cin >> age;
    if (age < 0) throw std::invalid_argument("Age cannot be negative");
    if (age > 150) throw std::out_of_range("Age is too large");
    std::cout << "Age: " << age << std::endl;
} catch (const std::invalid_argument& e) {
    std::cerr << "Invalid: " << e.what() << std::endl;
} catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
}
```

### Custom Exception
```cpp
class InsufficientFundsException : public std::runtime_error {
    double amount;
public:
    InsufficientFundsException(double amt)
        : std::runtime_error("Insufficient funds"), amount(amt) {}
    double getAmount() const { return amount; }
};
```

## ✏️ Bài tập
1. Viết hàm chia có xử lý ngoại lệ (chia cho 0)
2. Tạo custom exception cho `BankAccount`
3. Viết chương trình đọc file với xử lý lỗi đầy đủ
