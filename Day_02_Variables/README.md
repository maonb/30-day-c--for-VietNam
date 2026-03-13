# Day 02: Biến & Kiểu dữ liệu (Cơ bản + Nâng cao)

## 🎯 Mục tiêu
- Hiểu cách khai báo biến
- Nắm vững các kiểu dữ liệu cơ bản
- Sử dụng `auto` và `const`
- **Hiểu các kiểu dữ liệu nâng cao trong Modern C++**
- **Biết khi nào dùng kiểu nào, tránh viết C++ như C**

---

## 🗺️ Bản đồ phân loại tổng quan

```
Kiểu dữ liệu C++
├── 1. Kiểu nguyên thuỷ (Fundamental / Built-in)
│   ├── Số nguyên: bool, char, short, int, long, long long
│   ├── Số thực:   float, double, long double
│   ├── Ký tự:     char, wchar_t, char8_t, char16_t, char32_t
│   └── Void:      void
│
├── 2. Kiểu kích thước cố định & Kiểu đặc biệt
│   ├── Fixed-width: int8_t, uint32_t, int64_t, ...
│   └── Đặc biệt:   size_t, ptrdiff_t, intptr_t, nullptr_t
│
├── 3. Kiểu do người dùng định nghĩa (User-defined)
│   ├── struct, class
│   ├── enum, enum class
│   ├── union
│   └── Type aliases: typedef, using
│
├── 4. Kiểu Utility (Tiện ích)
│   ├── std::pair, std::tuple
│   ├── std::optional, std::variant, std::any
│   ├── std::bitset, std::complex
│   └── std::string, std::string_view
│
├── 5. Containers (Bộ chứa)
│   ├── Sequence:    vector, array, deque, list, forward_list
│   ├── Associative: map, set, multimap, multiset
│   ├── Unordered:   unordered_map, unordered_set, ...
│   └── Adapters:    stack, queue, priority_queue
│
├── 6. Con trỏ & Tham chiếu
│   ├── Raw: T*, T&, T&&
│   └── Smart: unique_ptr, shared_ptr, weak_ptr
│
└── 7. Qualifiers & Modifiers
    ├── const, constexpr, consteval, constinit
    ├── volatile, mutable
    ├── signed, unsigned
    └── auto, decltype
```

---

# PHẦN I: KIỂU NGUYÊN THUỶ (Fundamental Types)

## 1.1. Số nguyên (Integer types)

| Kiểu | Kích thước | Phạm vi (signed) | Ví dụ |
|------|-----------|-------------------|-------|
| `bool` | 1 byte | `true` (1) / `false` (0) | `bool ok = true;` |
| `char` | 1 byte | -128 → 127 | `char c = 'A';` |
| `short` | 2 bytes | -32,768 → 32,767 | `short s = 100;` |
| `int` | 4 bytes | -2,147,483,648 → 2,147,483,647 | `int age = 25;` |
| `long` | 4/8 bytes | ≥ 32 bit | `long l = 100000L;` |
| `long long` | 8 bytes | -2^63 → 2^63 - 1 | `long long ll = 9'000'000'000LL;` |

### `unsigned` — Kiểu không dấu
```cpp
unsigned int   u = 42;        // 0 → 4,294,967,295
unsigned short us = 100;       // 0 → 65,535
unsigned char  uc = 255;       // 0 → 255

// ⚠️ CẨN THẬN: unsigned wrap around!
unsigned int x = 0;
x--;  // x = 4294967295 (KHÔNG phải -1!)
```

## 1.2. Số thực (Floating-point types)

| Kiểu | Kích thước | Độ chính xác | Ví dụ |
|------|-----------|-------------|-------|
| `float` | 4 bytes | ~7 chữ số | `float pi = 3.14f;` |
| `double` | 8 bytes | ~15 chữ số | `double pi = 3.14159265358979;` |
| `long double` | 8–16 bytes | ≥ double | `long double ld = 3.14L;` |

> ⚠️ **Lưu ý:** Floating-point KHÔNG chính xác! `0.1 + 0.2 != 0.3`. Dùng epsilon comparison.

```cpp
#include <cmath>
bool almostEqual(double a, double b, double eps = 1e-9) {
    return std::abs(a - b) < eps;
}
```

## 1.3. Kiểu ký tự (Character types)

| Kiểu | Kích thước | Encoding | Ví dụ |
|------|-----------|----------|-------|
| `char` | 1 byte | ASCII / UTF-8 byte | `char c = 'A';` |
| `wchar_t` | 2/4 bytes | Wide character | `wchar_t w = L'Ω';` |
| `char8_t` | 1 byte | UTF-8 (C++20) | `char8_t u8 = u8'A';` |
| `char16_t` | 2 bytes | UTF-16 (C++11) | `char16_t u16 = u'Ω';` |
| `char32_t` | 4 bytes | UTF-32 (C++11) | `char32_t u32 = U'😀';` |

```cpp
// String literals cho mỗi encoding
auto s1 = "Hello";          // const char*
auto s2 = L"Hello";         // const wchar_t*
auto s3 = u8"Hello";        // const char8_t* (C++20) / const char* (C++17)
auto s4 = u"Hello";         // const char16_t*
auto s5 = U"Hello";         // const char32_t*
```

## 1.4. `void`
```cpp
void doSomething();          // Hàm không trả về giá trị
void* ptr;                   // Con trỏ generic (trỏ đến bất kỳ kiểu nào)
```

## 1.5. Digit separators & Literals (C++14)
```cpp
int million = 1'000'000;               // Dễ đọc hơn
long long big = 9'223'372'036'854'775'807LL;
double pi = 3.141'592'653'589'793;
int hex = 0xFF'FF;                      // Hex literal
int oct = 0177;                         // Octal literal
int bin = 0b1010'1010;                  // Binary literal (C++14)
```

---

# PHẦN II: KIỂU KÍCH THƯỚC CỐ ĐỊNH & KIỂU ĐẶC BIỆT

## 2.1. Fixed-width integers (`<cstdint>`)
> **Tại sao cần?** `int` có thể là 2, 4 hoặc 8 bytes tùy platform. Dùng fixed-width để đảm bảo kích thước.

```cpp
#include <cstdint>

// Exact-width — chính xác N bit
int8_t    i8  = -128;          // 8 bit signed
uint8_t   u8  = 255;           // 8 bit unsigned
int16_t   i16 = -32768;        // 16 bit
uint16_t  u16 = 65535;         // 16 bit unsigned
int32_t   i32 = -2147483648;   // 32 bit
uint32_t  u32 = 4294967295U;   // 32 bit unsigned
int64_t   i64 = -1;            // 64 bit
uint64_t  u64 = 18446744073709551615ULL;

// Fast — kiểu nhanh nhất có ≥ N bit
int_fast32_t fast = 42;

// Least — kiểu nhỏ nhất có ≥ N bit
int_least16_t small = 42;

// Max-width
intmax_t  imax = 42;           // Kiểu nguyên lớn nhất hỗ trợ
uintmax_t umax = 42;
```

## 2.2. Kiểu đặc biệt

| Kiểu | Mục đích | Header |
|------|---------|--------|
| `size_t` | Kích thước, index (unsigned) | `<cstddef>` |
| `ptrdiff_t` | Hiệu 2 con trỏ (signed) | `<cstddef>` |
| `intptr_t` | Integer chứa được con trỏ | `<cstdint>` |
| `uintptr_t` | Unsigned integer chứa được con trỏ | `<cstdint>` |
| `nullptr_t` | Kiểu của `nullptr` | `<cstddef>` |
| `byte` | 1 byte, không phải số | `<cstddef>` (C++17) |
| `ssize_t` | Signed size (POSIX) | `<sys/types.h>` |

```cpp
#include <cstddef>
#include <cstdint>

size_t    len = 100;            // Dùng cho .size(), sizeof(), index
ptrdiff_t diff = ptr2 - ptr1;   // Khoảng cách giữa 2 con trỏ
intptr_t  ip = reinterpret_cast<intptr_t>(ptr);
std::nullptr_t np = nullptr;    // Kiểu của nullptr
std::byte b{0xFF};              // C++17: byte thuần tuý, không phải char
```

---

# PHẦN III: KIỂU DO NGƯỜI DÙNG ĐỊNH NGHĨA (User-Defined Types)

## 3.1. `struct` và `class`
```cpp
// struct — mặc định public
struct Point {
    double x, y;
    double distance() const { return std::sqrt(x*x + y*y); }
};
Point p = {3.0, 4.0};         // Aggregate initialization

// class — mặc định private
class Student {
private:
    std::string name;
    int age;
public:
    Student(std::string n, int a) : name(std::move(n)), age(a) {}
    std::string getName() const { return name; }
};
```
> ⚠️ **Sự khác biệt duy nhất** giữa `struct` và `class`: default access level. `struct` = public, `class` = private.

## 3.2. `enum` và `enum class` (Scoped Enum)
```cpp
// ❌ C-style enum (KHÔNG khuyến khích)
enum Color { RED, GREEN, BLUE };
Color c = RED;
int n = RED;  // ⚠️ Implicit conversion → dễ gây bug!

// ✅ enum class (C++11) — type-safe, scoped
enum class Direction : uint8_t {
    Up = 0, Down = 1, Left = 2, Right = 3
};
Direction d = Direction::Up;
// int n = d;                        // ❌ Compile error!
int n = static_cast<int>(d);         // ✅ Phải ép kiểu
```

## 3.3. `union`
```cpp
// Tất cả members chia sẻ cùng bộ nhớ
union Data {
    int    i;
    float  f;
    char   c;
};  // sizeof(Data) = max(sizeof members) = 4

Data d;
d.i = 42;     // Ghi vào i
d.f = 3.14f;  // ⚠️ Ghi đè lên i! Chỉ 1 member active.
// ❌ Đọc d.i sau khi ghi d.f → Undefined Behavior!

// ✅ Dùng std::variant thay thế (xem phần IV)
```

## 3.4. Type aliases (`using` / `typedef`)
```cpp
// ❌ typedef (C-style)
typedef unsigned long ulong;
typedef std::vector<std::pair<std::string, int>> ScoreBoard;

// ✅ using (C++11, dễ đọc hơn, hỗ trợ template)
using ulong = unsigned long;
using ScoreBoard = std::vector<std::pair<std::string, int>>;

// Template alias — typedef KHÔNG làm được!
template<typename T>
using Vec = std::vector<T>;
Vec<int> v = {1, 2, 3};
```

---

# PHẦN IV: KIỂU UTILITY (Tiện ích)

## 4.1. `std::string` (`<string>`)
```cpp
#include <string>
using namespace std::string_literals;

std::string s = "Hello C++";
s.length();                    // 9
s.size();                      // 9 (giống length)
s.empty();                     // false
s.substr(0, 5);                // "Hello"
s.find("C++");                 // 6
s += " World";                 // Nối chuỗi
s.starts_with("Hello");        // true (C++20)
s.ends_with("World");          // true (C++20)
s.contains("C++");             // true (C++23)

auto str = "Hello"s;           // std::string literal (C++14)
```

## 4.2. `std::string_view` (`<string_view>`, C++17)
> **View không copy** — hiệu suất cao cho đọc chuỗi.
- Tránh copy string
- Tăng performance
- API linh hoạt hơn
- Parse text nhanh hơn

```cpp
#include <string_view>

void print(std::string_view sv) {   // Không copy string!
    std::cout << sv << std::endl;
}

print("Hello");                      // Từ C-string literal
std::string s = "World";
print(s);                            // Từ std::string
print(std::string_view(s).substr(0, 3));  // "Wor" — cũng không copy!

// ⚠️ NGUY HIỂM: string_view KHÔNG sở hữu data!
std::string_view dangerous() {
    std::string local = "Hello";
    return local;  // ❌ Dangling! local bị huỷ!
}
```

## 4.3. `std::pair` (`<utility>`)
```cpp
#include <utility>

std::pair<std::string, int> p = {"Alice", 25};
std::cout << p.first << " - " << p.second;

auto p2 = std::make_pair("Bob", 30);

// Structured bindings (C++17)
auto [name, age] = p;
```

## 4.4. `std::tuple` (`<tuple>`)
```cpp
#include <tuple>

std::tuple<std::string, int, double> t = {"Charlie", 28, 1.75};
std::cout << std::get<0>(t);          // "Charlie"

// Structured bindings (C++17)
auto [name, age, height] = t;

// Hàm trả về nhiều giá trị
std::tuple<bool, std::string> validate(int x) {
    if (x > 0) return {true, "OK"};
    return {false, "Must be positive"};
}
auto [ok, msg] = validate(5);
```

## 4.5. `std::optional` (`<optional>`, C++17)
> Thay thế magic values (-1, nullptr, "") để biểu diễn "có hoặc không có giá trị".

```cpp
#include <optional>

std::optional<int> findIndex(const std::vector<int>& v, int target) {
    for (size_t i = 0; i < v.size(); i++) {
        if (v[i] == target) return static_cast<int>(i);
    }
    return std::nullopt;
}

auto result = findIndex({1, 2, 3}, 2);
if (result.has_value()) {
    std::cout << "Found at: " << result.value() << std::endl;
}
std::cout << result.value_or(-1) << std::endl;
```

## 4.6. `std::variant` (`<variant>`, C++17)
> **Type-safe union** — thay thế `union`.

```cpp
#include <variant>

std::variant<int, float, std::string> v;
v = 42;                                  // Lưu int
v = 3.14f;                               // Lưu float
v = "hello"s;                            // Lưu string

// Truy cập an toàn
std::cout << std::get<std::string>(v);    // "hello"
// std::get<int>(v);                      // ❌ throw std::bad_variant_access

// Kiểm tra kiểu
if (std::holds_alternative<std::string>(v)) {
    std::cout << "Đang lưu string!" << std::endl;
}

// std::visit — visitor pattern
std::visit([](auto&& arg) {
    std::cout << arg << std::endl;
}, v);
```

## 4.7. `std::any` (`<any>`, C++17)
> Lưu **bất kỳ kiểu nào**. Ít type-safe hơn `variant`.

```cpp
#include <any>

std::any a = 42;
a = std::string("hello");
a = 3.14;

double d = std::any_cast<double>(a);     // OK
// std::any_cast<int>(a);                // ❌ throw std::bad_any_cast

if (a.type() == typeid(double)) { /* ... */ }
```

## 4.8. `std::bitset` (`<bitset>`)
```cpp
#include <bitset>

std::bitset<8> bits("10110011");
std::bitset<8> b2(0xAB);

bits.count();    // 5 — số bit 1
bits.test(0);    // true — bit 0
bits.flip();     // Đảo tất cả
bits.set(3);     // Set bit 3 = 1
bits.reset(3);   // Set bit 3 = 0

std::cout << bits << std::endl;      // In dạng binary
```

## 4.9. `std::complex` (`<complex>`)
```cpp
#include <complex>

std::complex<double> z1(3.0, 4.0);  // 3 + 4i
std::complex<double> z2(1.0, -2.0);

auto sum = z1 + z2;                  // 4 + 2i
std::cout << std::abs(z1);           // 5.0 (modulus)
std::cout << std::arg(z1);           // Góc (radian)
```

### 📊 So sánh variant vs any vs optional vs union

| | `union` | `std::variant` | `std::any` | `std::optional` |
|--|---------|---------------|------------|-----------------|
| Type-safe | ❌ | ✅ | Một phần | ✅ |
| Số kiểu | Cố định | Cố định (listed) | Bất kỳ | 1 kiểu duy nhất |
| Memory | Nhỏ nhất | Stack | Heap possible | Stack |
| Use case | Low-level | Thay `union` | Plugin/config | "Có hoặc không" |
| C++ version | C | C++17 | C++17 | C++17 |

---

# PHẦN V: CONTAINERS (Bộ chứa)

## 5.1. Sequence Containers — Tuần tự

### `std::array` (`<array>`, C++11) — Mảng cố định
> Thay thế C-style array `int arr[5]`. Biết size, có bounds check, STL compatible.

```cpp
#include <array>

std::array<int, 5> arr = {1, 2, 3, 4, 5};
arr.size();         // 5
arr.at(2);          // 3 — có bounds check
arr.front();        // 1
arr.back();         // 5

for (int x : arr) std::cout << x << " ";

// So sánh
std::array<int, 3> a = {1, 2, 3};
std::array<int, 3> b = {1, 2, 3};
if (a == b) std::cout << "Equal!";
```

### `std::vector` (`<vector>`) — Mảng động ⭐ DÙNG NHIỀU NHẤT
```cpp
#include <vector>

std::vector<int> v = {1, 2, 3};
v.push_back(4);           // Thêm cuối: O(1) amortized
v.emplace_back(5);        // Tạo tại chỗ, hiệu quả hơn
v.size();                 // 5
v.capacity();             // ≥ 5 (bộ nhớ đã cấp)
v.reserve(100);           // Cấp trước 100 slot → tránh realloc
v[0];                     // 1 — không bounds check
v.at(0);                  // 1 — có bounds check
v.pop_back();             // Xóa cuối: O(1)
v.erase(v.begin() + 1);  // Xóa ở giữa: O(n)!
v.insert(v.begin(), 0);  // Insert đầu: O(n)!
v.clear();                // Xóa hết
v.shrink_to_fit();        // Thu nhỏ capacity
```

### `std::deque` (`<deque>`) — Double-ended queue
```cpp
#include <deque>

std::deque<int> dq = {1, 2, 3};
dq.push_front(0);         // O(1) — vector không có!
dq.push_back(4);          // O(1)
dq[2];                    // ✅ Random access
dq.pop_front();           // O(1)
```

### `std::list` (`<list>`) — Doubly linked list
```cpp
#include <list>

std::list<int> lst = {1, 2, 3};
lst.push_front(0);        // O(1)
lst.push_back(4);         // O(1)
// lst[2];                // ❌ Không có random access!
lst.sort();               // Có sort riêng
lst.unique();             // Loại trùng liên tiếp
lst.merge(other_list);    // Trộn 2 list đã sort
```

### `std::forward_list` (`<forward_list>`, C++11) — Singly linked list
```cpp
#include <forward_list>

std::forward_list<int> fl = {1, 2, 3};
fl.push_front(0);         // O(1)
// fl.push_back(4);       // ❌ Không có! (singly linked)
// fl.size();             // ❌ Không có! (tiết kiệm memory)
fl.sort();
```

---

## 5.2. Associative Containers — Sắp xếp theo key (Red-Black Tree)

### `std::map` (`<map>`) — Key-Value, ordered, unique key
```cpp
#include <map>

std::map<std::string, int> ages;
ages["Alice"] = 25;
ages["Bob"] = 30;
ages.insert({"Charlie", 28});
ages.emplace("David", 22);    // Tạo tại chỗ

// Duyệt — tự động sắp xếp theo key!
for (const auto& [name, age] : ages) {
    std::cout << name << ": " << age << std::endl;
}
// Output: Alice: 25, Bob: 30, Charlie: 28, David: 22

// Tìm kiếm
auto it = ages.find("Bob");
if (it != ages.end()) {
    std::cout << it->second << std::endl;  // 30
}

// ⚠️ operator[] tạo phần tử mới nếu key chưa có!
std::cout << ages["Eve"];  // Tạo "Eve" = 0!

// ✅ Dùng .at() để tránh tạo mới
try {
    ages.at("Frank");  // throw std::out_of_range
} catch (...) {}

// C++17: insert_or_assign, try_emplace
ages.insert_or_assign("Alice", 26);   // Update nếu đã có
ages.try_emplace("Grace", 20);        // Chỉ insert nếu chưa có
```

### `std::multimap` (`<map>`) — Cho phép trùng key
```cpp
std::multimap<std::string, std::string> phonebook;
phonebook.insert({"Alice", "0901234567"});
phonebook.insert({"Alice", "0912345678"});  // ✅ OK, trùng key!
phonebook.insert({"Bob", "0923456789"});

// Tìm tất cả entries của Alice
auto [begin, end] = phonebook.equal_range("Alice");
for (auto it = begin; it != end; ++it) {
    std::cout << it->first << ": " << it->second << std::endl;
}
```

### `std::set` (`<set>`) — Tập hợp, unique, sorted
```cpp
#include <set>

std::set<int> s = {3, 1, 4, 1, 5, 9};
// s = {1, 3, 4, 5, 9} — loại trùng, tự sắp xếp

s.insert(2);               // {1, 2, 3, 4, 5, 9}
s.erase(4);                // {1, 2, 3, 5, 9}
s.count(3);                // 1 (có) hoặc 0 (không)
s.contains(3);             // true (C++20)

// Duyệt
for (int x : s) std::cout << x << " ";
```

### `std::multiset` (`<set>`) — Cho phép trùng
```cpp
std::multiset<int> ms = {3, 1, 4, 1, 5, 1};
// ms = {1, 1, 1, 3, 4, 5} — sorted, có trùng
ms.count(1);   // 3
```

---

## 5.3. Unordered Containers — Hash table, O(1) average

### `std::unordered_map` (`<unordered_map>`) — Hash map ⭐
```cpp
#include <unordered_map>

std::unordered_map<std::string, int> scores;
scores["math"] = 95;
scores["physics"] = 88;
scores["chemistry"] = 92;

// Duyệt — THỨ TỰ KHÔNG XÁC ĐỊNH!
for (const auto& [subject, score] : scores) {
    std::cout << subject << ": " << score << std::endl;
}

// Kiểm tra tồn tại
scores.contains("math");               // true (C++20)
scores.count("math") > 0;              // true (Pre-C++20)

// Hash info
scores.bucket_count();                  // Số buckets
scores.load_factor();                   // Tỷ lệ fill
```

### `std::unordered_multimap` — Hash + trùng key
```cpp
std::unordered_multimap<std::string, int> grades;
grades.insert({"Alice", 90});
grades.insert({"Alice", 85});  // ✅ Trùng key OK
```

### `std::unordered_set` / `std::unordered_multiset`
```cpp
#include <unordered_set>

std::unordered_set<std::string> tags = {"c++", "programming", "c++"};
// tags = {"c++", "programming"} — unique, không thứ tự

std::unordered_multiset<int> ums = {1, 1, 2, 3, 3, 3};
ums.count(3);  // 3
```

---

## 5.4. Container Adapters — Bọc container khác

### `std::stack` (`<stack>`) — LIFO
```cpp
#include <stack>

std::stack<int> stk;
stk.push(1); stk.push(2); stk.push(3);
stk.top();    // 3 — xem đỉnh
stk.pop();    // Xóa 3

// Custom underlying container
std::stack<int, std::vector<int>> stk2;
```

### `std::queue` (`<queue>`) — FIFO
```cpp
#include <queue>

std::queue<int> q;
q.push(1); q.push(2); q.push(3);
q.front();    // 1 — đầu hàng
q.back();     // 3 — cuối hàng
q.pop();      // Xóa 1
```

### `std::priority_queue` (`<queue>`) — Heap
```cpp
// Max heap (mặc định)
std::priority_queue<int> maxPQ;
maxPQ.push(3); maxPQ.push(1); maxPQ.push(4);
maxPQ.top();   // 4 — lớn nhất

// Min heap
std::priority_queue<int, std::vector<int>, std::greater<int>> minPQ;
minPQ.push(3); minPQ.push(1); minPQ.push(4);
minPQ.top();   // 1 — nhỏ nhất
```

### `std::span` (`<span>`, C++20) — View cho contiguous data
```cpp
#include <span>

void process(std::span<int> data) {  // Không copy!
    for (int x : data) std::cout << x << " ";
}

std::vector<int> v = {1, 2, 3, 4, 5};
int arr[] = {1, 2, 3};
process(v);     // Từ vector
process(arr);   // Từ C-array
process({v.begin(), 3});  // Subset
```

---

## 5.5. Bảng tổng hợp Container

### 🔑 So sánh Map / Set

| Kiểu | Ordered | Trùng key | Lookup | Insert |
|------|---------|-----------|--------|--------|
| `map` | ✅ | ❌ | O(log n) | O(log n) |
| `multimap` | ✅ | ✅ | O(log n) | O(log n) |
| `unordered_map` | ❌ | ❌ | **O(1)** | **O(1)** |
| `unordered_multimap` | ❌ | ✅ | **O(1)** | **O(1)** |
| `set` | ✅ | ❌ | O(log n) | O(log n) |
| `multiset` | ✅ | ✅ | O(log n) | O(log n) |
| `unordered_set` | ❌ | ❌ | **O(1)** | **O(1)** |
| `unordered_multiset` | ❌ | ✅ | **O(1)** | **O(1)** |

### 📊 So sánh Sequence Containers

| Container | Random Access | Insert đầu | Insert cuối | Insert giữa | Memory |
|-----------|:---:|:---:|:---:|:---:|--------|
| `array` | **O(1)** | ❌ | ❌ | ❌ | Stack, liên tục |
| `vector` | **O(1)** | O(n) | **O(1)**\* | O(n) | Heap, liên tục |
| `deque` | **O(1)** | **O(1)** | **O(1)** | O(n) | Chunks |
| `list` | O(n) | **O(1)** | **O(1)** | **O(1)**† | Nodes |
| `forward_list` | O(n) | **O(1)** | O(n) | **O(1)**† | Nodes (nhỏ hơn list) |

\* amortized  
† nếu đã có iterator

### 🎯 Khi nào dùng container nào?

| Tình huống | Container |
|-----------|-----------|
| Mặc định, đa dụng | **`std::vector`** |
| Kích thước cố định lúc compile | `std::array` |
| Thêm/xóa ở cả 2 đầu | `std::deque` |
| Thêm/xóa giữa nhiều | `std::list` |
| Key-value, cần sort | `std::map` |
| Key-value, cần nhanh | **`std::unordered_map`** |
| Unique values, cần sort | `std::set` |
| Unique values, cần nhanh | `std::unordered_set` |
| LIFO | `std::stack` |
| FIFO | `std::queue` |
| Min/Max nhanh | `std::priority_queue` |

---

# PHẦN VI: CON TRỎ & THAM CHIẾU (Giới thiệu)

> Chi tiết ở Day 10–13. Ở đây chỉ giới thiệu như kiểu dữ liệu.

| Kiểu | Ví dụ | Mô tả |
|------|-------|-------|
| `T*` | `int* p = &x;` | Raw pointer |
| `T&` | `int& r = x;` | Lvalue reference |
| `T&&` | `int&& r = 42;` | Rvalue reference (C++11) |
| `const T*` | `const int* p;` | Pointer to const |
| `T* const` | `int* const p = &x;` | Const pointer |
| `std::unique_ptr<T>` | `auto p = std::make_unique<int>(42);` | Sở hữu duy nhất |
| `std::shared_ptr<T>` | `auto p = std::make_shared<int>(42);` | Sở hữu chia sẻ |
| `std::weak_ptr<T>` | `std::weak_ptr<int> wp = sp;` | Không sở hữu |

---

# PHẦN VII: QUALIFIERS & MODIFIERS

## 7.1. Hằng số & Compile-time

| Keyword | Mô tả | Ví dụ |
|---------|-------|-------|
| `const` | Không thay đổi giá trị (runtime OK) | `const int MAX = f();` |
| `constexpr` | Phải xác định lúc compile (C++11) | `constexpr int SIZE = 256;` |
| `consteval` | Hàm CHỈ chạy lúc compile (C++20) | `consteval int sq(int x) { return x*x; }` |
| `constinit` | Khởi tạo lúc compile, nhưng cho phép sửa (C++20) | `constinit int x = 42;` |

```cpp
const int a = 42;           // ✅ Hằng runtime
constexpr int b = 42;       // ✅ Hằng compile-time

int y;
std::cin >> y;
const int c = y;             // ✅ const cho phép runtime value
// constexpr int d = y;      // ❌ constexpr yêu cầu compile-time!
```

## 7.2. Type deduction

```cpp
auto x = 42;                 // int
auto y = 3.14;               // double
auto s = "Hello"s;           // std::string
auto v = {1, 2, 3};          // std::initializer_list<int>

decltype(x) z = 10;          // int (cùng kiểu với x)
decltype(auto) w = x;        // int (giữ nguyên value category)
```

## 7.3. Các modifier khác

| Modifier | Mô tả |
|----------|-------|
| `signed` / `unsigned` | Có dấu / không dấu |
| `volatile` | Ngăn compiler optimize (I/O, hardware) |
| `mutable` | Cho phép sửa trong `const` method |
| `static` | Biến tĩnh (sống suốt chương trình) |
| `extern` | Khai báo biến ở file khác |
| `register` | Gợi ý đặt vào register (deprecated C++17) |
| `thread_local` | Mỗi thread có bản copy riêng (C++11) |
| `inline` | Gợi ý inline / cho phép multiple definitions |

---

# PHẦN VIII: TỔNG HỢP — Khi nào dùng kiểu nào?

## ❌ C-style → ✅ Modern C++

| Tình huống | ❌ Cách cũ (C-style) | ✅ Modern C++ |
|-----------|---------------------|--------------|
| Hằng số compile-time | `#define MAX 100` | `constexpr int MAX = 100;` |
| Mảng cố định | `int arr[5]` | `std::array<int, 5>` |
| Mảng động | `int* arr = new int[n]` | `std::vector<int>(n)` |
| Giá trị có/không | `return -1` hoặc `nullptr` | `std::optional<T>` |
| Union nhiều kiểu | `union { int i; float f; }` | `std::variant<int, float>` |
| Lưu bất kỳ kiểu | `void*` | `std::any` |
| Enum | `enum Color { RED }` | `enum class Color { Red }` |
| Chuỗi chỉ đọc | `const char*` | `std::string_view` |
| Trả về nhiều giá trị | out params hoặc struct | `std::tuple` + structured bindings |
| Kích thước cố định | `int` (platform-dependent) | `int32_t` (`<cstdint>`) |
| Lưu key-value | mảng song song | `std::map` / `std::unordered_map` |
| Unique values | sort + unique | `std::set` / `std::unordered_set` |

---

## ✏️ Bài tập cơ bản
1. Khai báo biến cho thông tin cá nhân (tên, tuổi, chiều cao, cân nặng)
2. Tính diện tích hình tròn với `r` nhập từ bàn phím
3. Tìm hiểu `sizeof()` cho mỗi kiểu dữ liệu cơ bản
4. Viết chương trình dùng `std::optional` trả kết quả tìm kiếm
5. Dùng `std::variant` lưu các kiểu dữ liệu khác nhau trong vector
6. Dùng `std::map` đếm tần suất ký tự trong chuỗi
7. So sánh hiệu suất `std::map` vs `std::unordered_map` với 1 triệu phần tử

---

## 🔥 20 Câu hỏi khó về Kiểu dữ liệu

### Câu 1: Overflow và Undefined Behavior
```cpp
int x = INT_MAX;  // 2147483647
x = x + 1;
std::cout << x << std::endl;
```
**Hỏi:** Output là gì? Đây có phải undefined behavior không? Giải thích chi tiết.

---

### Câu 2: unsigned underflow
```cpp
unsigned int a = 0;
a--;
std::cout << a << std::endl;
```
**Hỏi:** Output là gì? Tại sao kết quả khác với signed int? Đây có phải UB không?

---

### Câu 3: So sánh signed và unsigned
```cpp
int a = -1;
unsigned int b = 1;
if (a < b)
    std::cout << "a < b" << std::endl;
else
    std::cout << "a >= b" << std::endl;
```
**Hỏi:** Output là gì? Tại sao? Compiler cảnh báo gì?

---

### Câu 4: Narrowing conversion
```cpp
int x = 256;
char c = x;
std::cout << static_cast<int>(c) << std::endl;

// So sánh với:
// char c2{256};  // Dòng này có compile được không?
```
**Hỏi:** Giá trị `c` là gì? Dòng `char c2{256}` khác gì? Giải thích narrowing conversion.

---

### Câu 5: float precision
```cpp
float a = 0.1f;
float b = 0.2f;
float c = 0.3f;

if (a + b == c)
    std::cout << "Equal" << std::endl;
else
    std::cout << "Not equal" << std::endl;

std::cout << std::setprecision(20) << a + b << std::endl;
std::cout << std::setprecision(20) << c << std::endl;
```
**Hỏi:** Output là gì? Tại sao `0.1 + 0.2 != 0.3`? Cách so sánh float đúng là gì?

---

### Câu 6: sizeof và alignment
```cpp
struct A {
    char c;     // 1 byte
    int i;      // 4 bytes
    char d;     // 1 byte
};

struct B {
    char c;     // 1 byte
    char d;     // 1 byte
    int i;      // 4 bytes
};

std::cout << sizeof(A) << std::endl;
std::cout << sizeof(B) << std::endl;
```
**Hỏi:** `sizeof(A)` và `sizeof(B)` bằng bao nhiêu? Tại sao khác nhau dù cùng members? **Padding** và **alignment** là gì?

---

### Câu 7: auto deduction traps
```cpp
auto a = 42;          // Kiểu gì?
auto b = 42u;         // Kiểu gì?
auto c = 42L;         // Kiểu gì?
auto d = 42LL;        // Kiểu gì?
auto e = 42.0;        // Kiểu gì?
auto f = 42.0f;       // Kiểu gì?
auto g = 'A';         // Kiểu gì?
auto h = "Hello";     // Kiểu gì? (CẨN THẬN!)
auto i = "Hello"s;    // Kiểu gì?
auto j = {1, 2, 3};   // Kiểu gì?
```
**Hỏi:** Xác định kiểu của mỗi biến. Đặc biệt giải thích `h` vs `i` và `j`.

---

### Câu 8: Integer promotion
```cpp
char a = 10;
char b = 20;
auto c = a + b;
std::cout << sizeof(c) << std::endl;
std::cout << typeid(c).name() << std::endl;
```
**Hỏi:** `c` có kiểu `char` không? `sizeof(c)` bằng bao nhiêu? Giải thích **integer promotion rules**.

---

### Câu 9: Boolean conversion quirks
```cpp
bool b1 = 42;
bool b2 = -1;
bool b3 = 0;
bool b4 = 0.0001;

int sum = b1 + b2 + b3 + b4;
std::cout << sum << std::endl;

// Nhưng:
std::cout << std::boolalpha << (b1 == true) << std::endl;
std::cout << (42 == true) << std::endl;
```
**Hỏi:** Giá trị `sum`? Tại sao `42 == true` cho kết quả khác mong đợi?

---

### Câu 10: const vs constexpr vs consteval
```cpp
const int a = 42;              // (1)
constexpr int b = 42;          // (2)
// consteval int square(int x) { return x * x; }  // (3) C++20

int x;
std::cin >> x;
const int c = x;               // (4)
// constexpr int d = x;        // (5) Dòng này compile được không?
```
**Hỏi:** Sự khác biệt giữa `const`, `constexpr`, và `consteval`? Dòng (4) hợp lệ mà dòng (5) không — tại sao?

---

### Câu 11: variant vs any vs union
```cpp
// (1) union
union U { int i; float f; };

// (2) std::variant
std::variant<int, float, std::string> v;

// (3) std::any
std::any a;
```
**Hỏi:** So sánh 3 cách lưu nhiều kiểu trên. Khi nào dùng cái nào? Về: type safety, performance, memory, khả năng mở rộng.

---

### Câu 12: string_view dangling reference
```cpp
std::string_view getName() {
    std::string s = "Hello";
    return s;  // ⚠️
}

std::string_view sv = getName();
std::cout << sv << std::endl;
```
**Hỏi:** Code này có vấn đề gì? Output có thể là gì? Tại sao `string_view` có thể nguy hiểm?

---

### Câu 13: Implicit conversions chain
```cpp
double d = 3.14;
int i = d;              // (1) Chuyện gì xảy ra?
char c = i;             // (2) Chuyện gì xảy ra?
bool b = c;             // (3) Chuyện gì xảy ra?
double d2 = b;          // (4) Giá trị là gì?

std::cout << d2 << std::endl;
```
**Hỏi:** Theo dõi giá trị qua mỗi bước conversion. `d2` cuối cùng bằng bao nhiêu? Có mất dữ liệu không?

---

### Câu 14: struct với bitfield
```cpp
struct Flags {
    uint8_t read    : 1;   // 1 bit
    uint8_t write   : 1;   // 1 bit
    uint8_t execute : 1;   // 1 bit
    uint8_t reserved: 5;   // 5 bits
};

Flags f = {1, 1, 0, 0};
std::cout << sizeof(f) << std::endl;
f.read = 2;  // Gán giá trị 2 vào 1 bit?
```
**Hỏi:** `sizeof(f)` bằng bao nhiêu? Điều gì xảy ra khi gán `f.read = 2`? Bitfield dùng trong tình huống nào?

---

### Câu 15: NaN và Infinity
```cpp
double a = 0.0 / 0.0;                    // (1)
double b = 1.0 / 0.0;                    // (2)
double c = -1.0 / 0.0;                   // (3)

std::cout << (a == a) << std::endl;       // (4) ???
std::cout << (b > 1000000) << std::endl;  // (5) ???
std::cout << std::isnan(a) << std::endl;  // (6)
std::cout << std::isinf(b) << std::endl;  // (7)
```
**Hỏi:** Giá trị `a`, `b`, `c` là gì? Tại sao `NaN != NaN` (dòng 4)? Đây là đặc điểm quan trọng nào của IEEE 754?

---

### Câu 16: std::optional edge cases
```cpp
std::optional<int> opt1;
std::optional<int> opt2 = 0;
std::optional<int> opt3 = std::nullopt;

std::cout << opt1.has_value() << std::endl;  // (1)
std::cout << opt2.has_value() << std::endl;  // (2)
std::cout << opt3.has_value() << std::endl;  // (3)

// So sánh
std::cout << (opt1 == opt3) << std::endl;    // (4)
std::cout << (opt1 < opt2) << std::endl;     // (5)

// ⚠️ Nguy hiểm:
// std::cout << opt1.value() << std::endl;   // (6) Điều gì xảy ra?
std::cout << opt1.value_or(-1) << std::endl; // (7)
```
**Hỏi:** Output mỗi dòng? Đặc biệt giải thích dòng (5): `nullopt` so sánh với `0` ra sao? Dòng (6) throw exception gì?

---

### Câu 17: Structured bindings và lifetime
```cpp
std::tuple<int, std::string> getData() {
    return {42, "Hello"};
}

auto [num, str] = getData();              // (1) Copy hay reference?
auto& [num2, str2] = getData();           // (2) Compile được không?
const auto& [num3, str3] = getData();     // (3) Compile được không?
```
**Hỏi:** Dòng (1) copy hay reference? Dòng (2) có compile được không — tại sao? Dòng (3) thì sao?

---

### Câu 18: Size of empty struct
```cpp
struct Empty {};
struct HasChar { char c; };
struct HasEmpty { Empty e; char c; };

std::cout << sizeof(Empty) << std::endl;     // (1)
std::cout << sizeof(HasChar) << std::endl;   // (2)
std::cout << sizeof(HasEmpty) << std::endl;  // (3)

// C++20:
struct HasNoUnique { [[no_unique_address]] Empty e; char c; };
std::cout << sizeof(HasNoUnique) << std::endl; // (4)
```
**Hỏi:** Output mỗi dòng? Tại sao `sizeof(Empty) != 0`? `[[no_unique_address]]` giải quyết vấn đề gì?

---

### Câu 19: Type deduction với references
```cpp
int x = 42;
int& rx = x;
const int& crx = x;

auto a = x;      // Kiểu gì?
auto b = rx;     // Kiểu gì? (CẨN THẬN!)
auto c = crx;    // Kiểu gì? (CẨN THẬN!)
auto& d = x;     // Kiểu gì?
auto& e = crx;   // Kiểu gì?
decltype(x) f;   // Kiểu gì?
decltype(rx) g = x;  // Kiểu gì?
decltype((x)) h = x; // Kiểu gì? (TRICKY!)
```
**Hỏi:** Xác định kiểu mỗi biến. Đặc biệt giải thích: tại sao `auto` bỏ reference và const? `decltype(x)` vs `decltype((x))` khác nhau thế nào?

---

### Câu 20: Multi-dimensional variant + visit
```cpp
using Value = std::variant<int, double, std::string>;

std::vector<Value> data = {42, 3.14, "hello"s, 100, "world"s};

// Tính tổng:
// - int/double → cộng dồn
// - string → nối lại
// Viết code dùng std::visit và overloaded lambda pattern

// Gợi ý pattern:
template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;  // C++17 deduction guide
```
**Hỏi:** Implement đoạn code trên. Giải thích `overloaded` pattern hoạt động ra sao. Tại sao đây là idiomatic C++17 cho variant visitation?

---

## 📌 Ghi chú quan trọng

> **"Không viết C++ như C"** — Hãy ưu tiên dùng:
> - `std::array` thay `int[]`
> - `std::vector` thay `new int[n]`
> - `std::optional` thay return `-1`
> - `enum class` thay `enum`
> - `std::variant` thay `union`
> - `constexpr` thay `#define`
> - `std::string_view` thay `const char*`
> - `std::unordered_map` thay mảng song song
> - `std::span` thay `(T* ptr, size_t len)`
