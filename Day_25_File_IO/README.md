# Day 25: File I/O

## 🎯 Mục tiêu
- Đọc/ghi file text
- `ifstream`, `ofstream`, `fstream`
- Xử lý file CSV

## 📖 Lý thuyết

### Ghi file
```cpp
#include <fstream>
std::ofstream outFile("data.txt");
if (outFile.is_open()) {
    outFile << "Hello, File!" << std::endl;
    outFile << "Line 2" << std::endl;
    outFile.close();
}
```

### Đọc file
```cpp
std::ifstream inFile("data.txt");
std::string line;
while (std::getline(inFile, line)) {
    std::cout << line << std::endl;
}
inFile.close();
```

### Đọc file CSV
```cpp
std::ifstream csv("data.csv");
std::string line;
while (std::getline(csv, line)) {
    std::stringstream ss(line);
    std::string cell;
    while (std::getline(ss, cell, ',')) {
        std::cout << cell << " | ";
    }
    std::cout << std::endl;
}
```

## ✏️ Bài tập
1. Đọc file text, đếm số dòng, từ, ký tự
2. Ghi danh sách sinh viên ra file CSV
3. Đọc file CSV, parse và hiển thị dạng bảng
4. Copy nội dung file (clone `cp` command)
