# Day 04: Câu lệnh điều kiện (Conditions)

## 🎯 Mục tiêu
- Sử dụng `if`, `else if`, `else`
- Sử dụng `switch/case`
- Toán tử 3 ngôi `?:`
- **Hiểu các kỹ thuật nâng cao: `if` với initializer (C++17), `constexpr if`, `std::optional`**
- **Biết các bẫy nguy hiểm liên quan đến câu lệnh điều kiện**

---

## 🗺️ Phân loại câu lệnh điều kiện C++

```
Điều kiện C++
├── 1. if / else if / else          — Rẽ nhánh cơ bản
├── 2. switch / case / default      — Rẽ nhánh theo giá trị rời rạc
├── 3. Toán tử 3 ngôi (?:)         — Biểu thức điều kiện inline
├── 4. if với initializer (C++17)   — Khai báo biến trong if
├── 5. constexpr if (C++17)         — Rẽ nhánh compile-time
└── 6. std::optional (C++17)        — Xử lý giá trị có/không có
```

---

# PHẦN I: CÂU LỆNH IF / ELSE

## 1.1. Cú pháp cơ bản

```cpp
if (điều_kiện) {
    // Thực hiện khi điều kiện TRUE
} else if (điều_kiện_2) {
    // Thực hiện khi điều kiện 2 TRUE
} else {
    // Thực hiện khi tất cả FALSE
}
```

### Ví dụ: Xếp loại điểm
```cpp
int score = 85;

if (score >= 90) {
    std::cout << "Xuat sac (A)" << std::endl;
} else if (score >= 80) {
    std::cout << "Gioi (B)" << std::endl;
} else if (score >= 70) {
    std::cout << "Kha (C)" << std::endl;
} else if (score >= 60) {
    std::cout << "Trung binh (D)" << std::endl;
} else {
    std::cout << "Yeu (F)" << std::endl;
}
```

## 1.2. if lồng nhau (Nested if)

```cpp
int age = 25;
bool hasLicense = true;

if (age >= 18) {
    if (hasLicense) {
        std::cout << "Duoc lai xe" << std::endl;
    } else {
        std::cout << "Can thi bang lai" << std::endl;
    }
} else {
    std::cout << "Chua du tuoi" << std::endl;
}

// ✅ Viết gọn hơn với toán tử logic:
if (age >= 18 && hasLicense) {
    std::cout << "Duoc lai xe" << std::endl;
}
```

## 1.3. ⚠️ Bẫy nguy hiểm với if

### Bẫy 1: Dangling else
```cpp
// ⚠️ else thuộc về if GẦN NHẤT
if (x > 0)
    if (y > 0)
        std::cout << "Ca 2 duong";
else                          // ← Thuộc về if (y > 0), KHÔNG phải if (x > 0)!
    std::cout << "x <= 0???"; // ❌ Sai logic!

// ✅ Luôn dùng {} để tránh nhầm lẫn
if (x > 0) {
    if (y > 0) {
        std::cout << "Ca 2 duong";
    }
} else {
    std::cout << "x <= 0";
}
```

### Bẫy 2: Gán thay vì so sánh
```cpp
int x = 5;

if (x = 0) {                 // ⚠️ GÁN x = 0, rồi kiểm tra 0 → false!
    std::cout << "Zero";      // KHÔNG BAO GIỜ chạy
}

if (x == 0) {                // ✅ So sánh đúng
    std::cout << "Zero";
}

// Mẹo: Yoda condition
if (0 == x) { }              // Nếu nhầm viết = sẽ lỗi compile
```

### Bẫy 3: So sánh số thực (floating-point)
```cpp
double a = 0.1 + 0.2;
double b = 0.3;

if (a == b) {                // ⚠️ FALSE! (0.30000000000000004 != 0.3)
    std::cout << "Equal";
}

// ✅ So sánh với epsilon
const double EPSILON = 1e-9;
if (std::abs(a - b) < EPSILON) {
    std::cout << "Equal";     // ✅ Đúng!
}
```

### Bẫy 4: Thiếu dấu ngoặc nhọn
```cpp
if (condition)
    doSomething();
    doSomethingElse();  // ⚠️ LUÔN chạy! Không thuộc if!

// ✅ Luôn dùng {}
if (condition) {
    doSomething();
    doSomethingElse();  // ✅ Thuộc if
}
```

---

# PHẦN II: SWITCH / CASE

## 2.1. Cú pháp cơ bản

```cpp
switch (biểu_thức) {
    case giá_trị_1:
        // code
        break;          // ← QUAN TRỌNG!
    case giá_trị_2:
        // code
        break;
    default:
        // code khi không khớp case nào
        break;
}
```

### Ví dụ: Menu chọn phép tính
```cpp
char op;
std::cout << "Nhap phep tinh (+, -, *, /): ";
std::cin >> op;

double a = 10, b = 3;
switch (op) {
    case '+':
        std::cout << a + b << std::endl;
        break;
    case '-':
        std::cout << a - b << std::endl;
        break;
    case '*':
        std::cout << a * b << std::endl;
        break;
    case '/':
        if (b != 0)
            std::cout << a / b << std::endl;
        else
            std::cout << "Khong chia duoc cho 0!" << std::endl;
        break;
    default:
        std::cout << "Phep tinh khong hop le!" << std::endl;
}
```

## 2.2. Fall-through (Rơi xuống)

```cpp
int day = 3;
switch (day) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        std::cout << "Ngay lam viec" << std::endl;
        break;      // break 1 lần cho cả nhóm
    case 6:
    case 7:
        std::cout << "Cuoi tuan" << std::endl;
        break;
    default:
        std::cout << "Ngay khong hop le" << std::endl;
}
```

### C++17: `[[fallthrough]]` attribute
```cpp
int x = 1;
switch (x) {
    case 1:
        doSetup();
        [[fallthrough]];  // Nói compiler: fall-through có chủ đích
    case 2:
        doWork();
        break;
    case 3:
        doOther();
        break;
}
```

## 2.3. Khai báo biến trong switch

```cpp
// ⚠️ KHÔNG được khai báo biến trong case mà không có {}
switch (x) {
    case 1:
        int y = 10;   // ❌ Lỗi! y có thể bị nhảy qua bởi case 2
        break;
    case 2:
        std::cout << y; // y chưa được khởi tạo!
        break;
}

// ✅ Dùng {} để tạo scope riêng
switch (x) {
    case 1: {
        int y = 10;   // ✅ y chỉ tồn tại trong block {}
        std::cout << y;
        break;
    }
    case 2: {
        int y = 20;   // ✅ y khác, scope khác
        std::cout << y;
        break;
    }
}
```

## 2.4. Switch vs If — Khi nào dùng gì?

| Tiêu chí | `switch` | `if/else` |
|----------|:--------:|:---------:|
| So sánh giá trị rời rạc | ✅ Tốt | Được |
| So sánh phạm vi (range) | ❌ Không | ✅ Tốt |
| Kiểu dữ liệu | `int`, `char`, `enum` | Mọi kiểu |
| So sánh chuỗi | ❌ Không | ✅ Được |
| Nhiều case cùng xử lý | ✅ Fall-through | Dùng `||` |
| Hiệu năng | Thường nhanh hơn (jump table) | Tuần tự |

> **Rule:** Dùng `switch` khi so sánh **giá trị rời rạc** (enum, int, char). Dùng `if/else` cho **điều kiện phức tạp** hoặc **range**.

---

# PHẦN III: TOÁN TỬ 3 NGÔI (Ternary Operator `?:`)

## 3.1. Cú pháp
```cpp
điều_kiện ? giá_trị_nếu_true : giá_trị_nếu_false
```

### Ví dụ cơ bản
```cpp
int x = 10;
std::string result = (x > 0) ? "Duong" : "Am hoac 0";
std::cout << result << std::endl;  // "Duong"

// Tìm max
int a = 5, b = 8;
int maxVal = (a > b) ? a : b;     // 8

// Tìm min
int minVal = (a < b) ? a : b;     // 5

// Giá trị tuyệt đối
int abs_x = (x >= 0) ? x : -x;
```

## 3.2. Ternary lồng nhau
```cpp
int score = 75;

// Xếp loại bằng ternary lồng
std::string grade = (score >= 90) ? "A"
                  : (score >= 80) ? "B"
                  : (score >= 70) ? "C"
                  : (score >= 60) ? "D"
                  : "F";

// ⚠️ Khó đọc! Nên dùng if/else hoặc hàm riêng khi > 2 nhánh
```

## 3.3. ⚠️ Bẫy với ternary

```cpp
// Bẫy 1: Kiểu trả về phải tương thích
auto val = true ? 42 : 3.14;   // val = 42.0 (double — promotion!)

// Bẫy 2: Precedence thấp!
std::cout << (x > 0 ? "Duong" : "Am");  // ✅ Cần ()
std::cout << x > 0 ? "Duong" : "Am";    // ❌ Compile error!
// Parse: (std::cout << x) > 0 ? "Duong" : "Am"

// Bẫy 3: Không phải mọi thứ đều nên dùng ternary
// ❌ Quá phức tạp
result = (a > b) ? (a > c ? a : c) : (b > c ? b : c);
// ✅ Dùng std::max
result = std::max({a, b, c});
```

---

# PHẦN IV: CÂU LỆNH ĐIỀU KIỆN NÂNG CAO (Modern C++)

## 4.1. `if` với initializer (C++17)

```cpp
// Khai báo biến trong if — giới hạn scope
if (int result = compute(); result > 0) {
    std::cout << "Positive: " << result << std::endl;
} else {
    std::cout << "Non-positive: " << result << std::endl;
}
// result KHÔNG tồn tại ở đây — tránh ô nhiễm scope!

// Ví dụ thực tế: tìm kiếm trong map
#include <map>
std::map<std::string, int> scores = {{"Alice", 90}, {"Bob", 75}};

if (auto it = scores.find("Alice"); it != scores.end()) {
    std::cout << it->first << ": " << it->second << std::endl;
} else {
    std::cout << "Khong tim thay" << std::endl;
}

// Ví dụ: lock
if (std::lock_guard lock(mutex); shared_data.ready) {
    process(shared_data);
}
```

## 4.2. `switch` với initializer (C++17)

```cpp
switch (auto status = getStatus(); status) {
    case Status::OK:
        std::cout << "Thanh cong" << std::endl;
        break;
    case Status::ERROR:
        std::cout << "Loi" << std::endl;
        break;
    default:
        std::cout << "Trang thai khac: " << static_cast<int>(status) << std::endl;
}
```

## 4.3. `constexpr if` (C++17) — Rẽ nhánh compile-time

```cpp
#include <type_traits>

template<typename T>
void printTypeInfo(T value) {
    if constexpr (std::is_integral_v<T>) {
        std::cout << value << " la so nguyen" << std::endl;
    } else if constexpr (std::is_floating_point_v<T>) {
        std::cout << value << " la so thuc" << std::endl;
    } else {
        std::cout << "Kieu khac" << std::endl;
    }
}

printTypeInfo(42);      // "42 la so nguyen"
printTypeInfo(3.14);    // "3.14 la so thuc"
printTypeInfo("hello"); // "Kieu khac"

// ⚡ Nhánh không thỏa mãn KHÔNG ĐƯỢC biên dịch
// → Có thể gọi hàm chỉ tồn tại cho 1 kiểu cụ thể
template<typename T>
auto getValue(T container) {
    if constexpr (std::is_same_v<T, std::vector<int>>) {
        return container.front();  // Chỉ vector có front()
    } else {
        return container;          // Trả về chính nó
    }
}
```

## 4.4. `std::optional` (C++17) — Giá trị có thể không tồn tại

```cpp
#include <optional>

std::optional<int> findIndex(const std::vector<int>& v, int target) {
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] == target) {
            return i;             // Tìm thấy → trả về index
        }
    }
    return std::nullopt;          // Không tìm thấy → "không có giá trị"
}

// Sử dụng
std::vector<int> nums = {10, 20, 30, 40};
auto result = findIndex(nums, 30);

if (result.has_value()) {
    std::cout << "Tim thay tai index: " << result.value() << std::endl;
}

// Hoặc dùng value_or
int idx = findIndex(nums, 50).value_or(-1);   // -1 nếu không tìm thấy
```

---

# PHẦN V: PATTERNS & BEST PRACTICES

## 5.1. Early return (Trả về sớm)
```cpp
// ❌ Lồng sâu, khó đọc
int process(int x) {
    if (x > 0) {
        if (x < 100) {
            if (x % 2 == 0) {
                return x * 2;
            } else {
                return x * 3;
            }
        } else {
            return -1;
        }
    } else {
        return 0;
    }
}

// ✅ Early return — phẳng, dễ đọc
int process(int x) {
    if (x <= 0) return 0;
    if (x >= 100) return -1;
    if (x % 2 == 0) return x * 2;
    return x * 3;
}
```

## 5.2. Guard clauses (Bảo vệ đầu vào)
```cpp
void processOrder(Order* order) {
    // Guard clauses — xử lý lỗi trước
    if (!order) return;
    if (order->items.empty()) return;
    if (!order->isPaid()) return;

    // Happy path — logic chính
    ship(order);
    notify(order->customer);
}
```

## 5.3. Lookup table thay switch dài
```cpp
#include <map>
#include <functional>

// Thay vì switch/case dài:
std::map<char, std::function<double(double, double)>> ops = {
    {'+', [](double a, double b) { return a + b; }},
    {'-', [](double a, double b) { return a - b; }},
    {'*', [](double a, double b) { return a * b; }},
    {'/', [](double a, double b) { return b != 0 ? a / b : 0; }}
};

if (ops.count(op)) {
    std::cout << ops[op](a, b) << std::endl;
} else {
    std::cout << "Phep tinh khong hop le" << std::endl;
}
```

---

# PHẦN VI: KIẾN THỨC BỔ SUNG

## 6.1. Truthy / Falsy trong C++

```cpp
// Các giá trị falsy (chuyển thành false):
if (0)        {}   // int 0
if (0.0)      {}   // double 0.0
if ('\0')     {}   // null character
if (nullptr)  {}   // null pointer
if (false)    {}   // bool false

// Tất cả giá trị khác → truthy
if (1)        {}   // true
if (-1)       {}   // true! (≠ 0)
if (3.14)     {}   // true
if ("hello")  {}   // true (pointer != nullptr)
```

## 6.2. Điều kiện với enum

```cpp
enum class Season { Spring, Summer, Autumn, Winter };

Season s = Season::Summer;

switch (s) {
    case Season::Spring:
        std::cout << "Mua xuan" << std::endl;
        break;
    case Season::Summer:
        std::cout << "Mua he" << std::endl;
        break;
    case Season::Autumn:
        std::cout << "Mua thu" << std::endl;
        break;
    case Season::Winter:
        std::cout << "Mua dong" << std::endl;
        break;
    // Không cần default nếu xử lý tất cả enum values
    // Compiler sẽ warning nếu thiếu case (với -Wswitch)
}
```

## 6.3. Điều kiện với string — không dùng switch được!

```cpp
#include <string>

std::string command = "start";

// ❌ switch KHÔNG hỗ trợ string!
// switch (command) { ... }   // Compile error!

// ✅ Dùng if/else
if (command == "start") {
    std::cout << "Bat dau" << std::endl;
} else if (command == "stop") {
    std::cout << "Dung" << std::endl;
} else if (command == "pause") {
    std::cout << "Tam dung" << std::endl;
} else {
    std::cout << "Lenh khong hop le" << std::endl;
}

// ✅ Hoặc dùng map (tốt hơn khi nhiều nhánh)
#include <map>
#include <functional>

std::map<std::string, std::function<void()>> commands = {
    {"start", []() { std::cout << "Bat dau" << std::endl; }},
    {"stop",  []() { std::cout << "Dung" << std::endl; }},
    {"pause", []() { std::cout << "Tam dung" << std::endl; }}
};

if (commands.count(command)) {
    commands[command]();
} else {
    std::cout << "Lenh khong hop le" << std::endl;
}
```

---

## ✏️ Bài tập

### Bài tập cơ bản
1. **Xếp loại học sinh** theo điểm (A ≥ 90, B ≥ 80, C ≥ 70, D ≥ 60, F < 60)
2. **Kiểm tra năm nhuận** (chia hết 4 và không chia hết 100, hoặc chia hết 400)
3. **Tìm số lớn nhất** trong 3 số nhập từ bàn phím

### Bài tập nâng cao
4. **Máy tính đơn giản** — nhập 2 số và phép tính, xử lý chia cho 0
5. **Giải phương trình bậc 2** — tính delta, xử lý 3 trường hợp (2 nghiệm, 1 nghiệm, vô nghiệm)
6. **Chuyển đổi tháng sang tên** — nhập số 1-12, in tên tháng (dùng switch)

---

## 🔥 10 Câu hỏi khó về Câu lệnh điều kiện

### Câu 1: Dangling else
```cpp
int x = 1, y = -1;
if (x > 0)
    if (y > 0)
        std::cout << "A";
else
    std::cout << "B";
```
**Hỏi:** Output là gì? `"A"`, `"B"`, hay không in gì? Giải thích quy tắc dangling else.

---

### Câu 2: Assignment trong if
```cpp
int x = 0;
if (x = 5) {
    std::cout << x << std::endl;
}
```
**Hỏi:** Output là gì? Tại sao code này compile thành công? Cách phòng tránh?

---

### Câu 3: Fall-through trong switch
```cpp
int x = 2;
switch (x) {
    case 1: std::cout << "A";
    case 2: std::cout << "B";
    case 3: std::cout << "C";
    default: std::cout << "D";
}
```
**Hỏi:** Output là gì? Giải thích fall-through. Sửa lại để chỉ in "B".

---

### Câu 4: Scope trong switch
```cpp
int x = 1;
switch (x) {
    case 0:
        int y = 10;
        break;
    case 1:
        std::cout << y << std::endl;
        break;
}
```
**Hỏi:** Code này compile được không? Nếu không, lỗi gì? Cách sửa?

---

### Câu 5: Floating-point comparison
```cpp
double a = 0.1 + 0.2;
if (a == 0.3) {
    std::cout << "Equal" << std::endl;
} else {
    std::cout << "Not equal: " << a << std::endl;
}
```
**Hỏi:** Output? Tại sao `0.1 + 0.2 != 0.3`? Cách so sánh đúng?

---

### Câu 6: Ternary operator type
```cpp
int x = 1;
auto a = (x > 0) ? 1 : 2.0;
auto b = (x > 0) ? "hello" : std::string("world");
```
**Hỏi:** Kiểu của `a`? Dòng `b` compile được không? Tại sao?

---

### Câu 7: Short-circuit + side effects
```cpp
int a = 0, b = 0;
if (++a || ++b) {
    std::cout << a << " " << b << std::endl;
}
```
**Hỏi:** Output? Giá trị `a` và `b` sau khi chạy? Giải thích short-circuit.

---

### Câu 8: if constexpr vs if thường
```cpp
template<typename T>
void test(T value) {
    if constexpr (std::is_integral_v<T>) {
        std::cout << value % 2 << std::endl;
    } else {
        std::cout << value << std::endl;
    }
}
test(3.14);
```
**Hỏi:** Nếu dùng `if` thường thay `if constexpr`, code có compile được không? Tại sao?

---

### Câu 9: Truthy values
```cpp
if (-1)     std::cout << "A";
if (0.001)  std::cout << "B";
if ('\0')   std::cout << "C";
if ("")     std::cout << "D";
if (nullptr) std::cout << "E";
```
**Hỏi:** Output? Giải thích từng giá trị truthy/falsy. `""` (chuỗi rỗng) là truthy hay falsy?

---

### Câu 10: Nested ternary precedence
```cpp
int x = 5;
int result = x > 10 ? 1 : x > 5 ? 2 : x > 0 ? 3 : 4;
std::cout << result << std::endl;
```
**Hỏi:** Output? Vẽ cây parse cho biểu thức ternary lồng nhau này.

---

> 💡 **Tổng kết:** Câu lệnh điều kiện là nền tảng quan trọng. Nắm vững `if/else`, `switch/case`, toán tử `?:` và các kỹ thuật Modern C++ giúp viết code sạch, an toàn và hiệu quả hơn.
