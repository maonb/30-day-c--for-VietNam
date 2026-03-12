# Day 12: Tham chiếu (References)

## 🎯 Mục tiêu
- Hiểu tham chiếu (reference)
- So sánh tham chiếu vs con trỏ
- Pass by reference trong thực tế

## 📖 Lý thuyết

### Tham chiếu
```cpp
int x = 10;
int& ref = x;     // ref là alias của x
ref = 20;          // x cũng = 20

std::cout << x;    // 20
```

### Tham chiếu vs Con trỏ
| Tham chiếu | Con trỏ |
|------------|---------|
| Phải khởi tạo | Có thể null |
| Không thay đổi đối tượng | Có thể trỏ đến đối tượng khác |
| Cú pháp gọn hơn | Linh hoạt hơn |
| An toàn hơn | Có thể gây lỗi |

### const reference
```cpp
void print(const std::string& s) {  // Không copy, không sửa
    std::cout << s << std::endl;
}
```

## ✏️ Bài tập
1. Viết hàm trả về tham chiếu đến phần tử lớn nhất
2. So sánh hiệu suất pass by value vs reference với struct lớn
3. Viết hàm nhận `const&` để xử lý vector
