# Day 01: Giới thiệu C++ & Hello World

## 🎯 Mục tiêu
- Hiểu C++ là gì, lịch sử phát triển
- Cài đặt compiler (g++) và IDE (VS Code / CLion)
- Viết và chạy chương trình đầu tiên

## 📖 Lý thuyết

### C++ là gì?
- Ngôn ngữ lập trình đa mục đích, được phát triển bởi **Bjarne Stroustrup** (1979)
- Mở rộng từ ngôn ngữ C, hỗ trợ OOP
- Được dùng trong: game, hệ thống nhúng, OS, driver, ứng dụng hiệu năng cao

### Cấu trúc chương trình C++
```cpp
#include <iostream>  // Thư viện input/output

int main() {         // Hàm main - điểm bắt đầu chương trình
    std::cout << "Hello, World!" << std::endl;
    return 0;        // Trả về 0 = chương trình kết thúc thành công
}
```

### Biên dịch và chạy
```bash
g++ -std=c++17 -o main main.cpp
./main
```

## ✏️ Bài tập
1. In ra tên và tuổi của bạn
2. In ra một tam giác bằng dấu `*`
3. Tìm hiểu sự khác nhau giữa `std::cout` và `printf()`
