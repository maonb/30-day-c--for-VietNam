# 🚀 Lộ Trình 30 Ngày Học C++

> Từ cơ bản đến nâng cao — mỗi ngày 1-2 giờ thực hành.

---

## 📅 Tuần 1: Nền tảng C++ (Day 01–07)

| Ngày | Chủ đề | Mô tả |
|------|--------|-------|
| 01 | Giới thiệu & Cài đặt | Cài đặt compiler (g++), IDE, viết chương trình Hello World |
| 02 | Biến & Kiểu dữ liệu | `int`, `float`, `double`, `char`, `bool`, `string`, `auto` |
| 03 | Toán tử & Biểu thức | Toán tử số học, so sánh, logic, bitwise, ép kiểu |
| 04 | Câu lệnh điều kiện | `if/else`, `switch/case`, toán tử 3 ngôi `?:` |
| 05 | Vòng lặp | `for`, `while`, `do-while`, `break`, `continue` |
| 06 | Mảng & Chuỗi | Mảng 1D/2D, `std::string`, các hàm xử lý chuỗi |
| 07 | Bài tập tổng hợp tuần 1 | Ôn tập + giải bài tập tổng hợp |

---

## 📅 Tuần 2: Hàm & Con trỏ (Day 08–14)

| Ngày | Chủ đề | Mô tả |
|------|--------|-------|
| 08 | Hàm (Functions) | Khai báo, định nghĩa, tham số, giá trị trả về |
| 09 | Hàm nâng cao | Overloading, default parameters, inline, recursion |
| 10 | Con trỏ (Pointers) | Khai báo, toán tử `*` và `&`, con trỏ và mảng |
| 11 | Con trỏ nâng cao | Con trỏ hàm, con trỏ void, con trỏ `nullptr` |
| 12 | Tham chiếu (References) | Tham chiếu vs Con trỏ, pass by reference |
| 13 | Cấp phát bộ nhớ động | `new`, `delete`, memory leak, smart pointers giới thiệu |
| 14 | Bài tập tổng hợp tuần 2 | Ôn tập + giải bài tập về hàm, con trỏ, tham chiếu |

---

## 📅 Tuần 3: OOP — Lập trình hướng đối tượng (Day 15–21)

| Ngày | Chủ đề | Mô tả |
|------|--------|-------|
| 15 | Struct & Class cơ bản | Định nghĩa class, access modifiers, constructor, destructor |
| 16 | Encapsulation & Getter/Setter | Đóng gói dữ liệu, getter/setter, `this` pointer |
| 17 | Kế thừa (Inheritance) | Single, multilevel, access control trong kế thừa |
| 18 | Đa hình (Polymorphism) | Function overriding, `virtual`, `override`, `final` |
| 19 | Lớp trừu tượng & Interface | Pure virtual function, abstract class |
| 20 | Operator Overloading | Nạp chồng toán tử `+`, `-`, `<<`, `>>`, `==` |
| 21 | Bài tập tổng hợp tuần 3 | Mini project OOP (quản lý sinh viên / thư viện) |

---

## 📅 Tuần 4: STL & Nâng cao (Day 22–28)

| Ngày | Chủ đề | Mô tả |
|------|--------|-------|
| 22 | Templates | Function templates, class templates |
| 23 | STL Containers | `vector`, `list`, `map`, `set`, `stack`, `queue` |
| 24 | STL Iterators & Algorithms | `sort`, `find`, `for_each`, `transform`, lambda |
| 25 | File I/O | `ifstream`, `ofstream`, `fstream`, đọc/ghi file |
| 26 | Exception Handling | `try`, `catch`, `throw`, custom exceptions |
| 27 | Smart Pointers | `unique_ptr`, `shared_ptr`, `weak_ptr`, RAII |
| 28 | Bài tập tổng hợp tuần 4 | Mini project STL (quản lý danh bạ / todo list) |

---

## 📅 Bonus: Tổng kết & Dự án (Day 29–30)

| Ngày | Chủ đề | Mô tả |
|------|--------|-------|
| 29 | Namespace, Preprocessor, Makefile | `namespace`, `#define`, `#include guard`, biên dịch đa file |
| 30 | Dự án cuối khóa | Xây dựng 1 mini project hoàn chỉnh kết hợp kiến thức 30 ngày |

---

## 📁 Cấu trúc thư mục

```
M_learn_C++/
├── ROADMAP.md                  ← File này
├── Day_01_Hello_World/
│   ├── README.md               ← Lý thuyết + hướng dẫn
│   ├── main.cpp                ← Code thực hành
│   └── exercises/              ← Bài tập
├── Day_02_Variables/
│   ├── README.md
│   ├── main.cpp
│   └── exercises/
├── ...
└── Day_30_Final_Project/
    ├── README.md
    ├── src/
    └── Makefile
```

## 📌 Quy ước

- Mỗi ngày tạo ít nhất **1 file `main.cpp`** để thực hành
- Ghi chú lý thuyết trong **`README.md`** của mỗi ngày
- Bài tập nằm trong thư mục **`exercises/`**
- Biên dịch: `g++ -std=c++17 -o main main.cpp && ./main`

---

> 💪 **"The only way to learn a new programming language is by writing programs in it."** — Dennis Ritchie
