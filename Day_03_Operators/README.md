# Day 03: Toán tử & Biểu thức (Cơ bản + Nâng cao)

## 🎯 Mục tiêu
- Nắm vững tất cả toán tử trong C++
- Hiểu thứ tự ưu tiên (precedence) và kết hợp (associativity)
- Sử dụng toán tử bitwise thành thạo
- Hiểu type casting đúng cách trong Modern C++
- **Biết các bẫy nguy hiểm liên quan đến toán tử**

---

## 🗺️ Phân loại toán tử C++

```
Toán tử C++
├── 1. Số học (Arithmetic)         +  -  *  /  %  ++  --
├── 2. Gán (Assignment)            =  +=  -=  *=  /=  %=  &=  |=  ^=  <<=  >>=
├── 3. So sánh (Comparison)        ==  !=  <  >  <=  >=  <=> (C++20)
├── 4. Logic (Logical)             &&  ||  !
├── 5. Bitwise                     &  |  ^  ~  <<  >>
├── 6. Con trỏ & Truy cập          *  &  ->  .  ->*  .*  []
├── 7. Đặc biệt                   ?:  ,  sizeof  alignof  typeid
│                                  decltype  noexcept  co_await
├── 8. Ép kiểu (Casting)          static_cast  dynamic_cast  const_cast  reinterpret_cast
├── 9. Cấp phát bộ nhớ             new  delete  new[]  delete[]
└── 10. Scope & Khác               ::  ...  <>
```

---

# PHẦN I: CÁC TOÁN TỬ CƠ BẢN

## 1.1. Toán tử số học (Arithmetic)

```cpp
int a = 10, b = 3;

a + b;    // 13  — cộng
a - b;    // 7   — trừ
a * b;    // 30  — nhân
a / b;    // 3   — chia nguyên (truncation toward zero)
a % b;    // 1   — chia lấy dư (modulo)

// ⚠️ Chia nguyên cắt về 0
-7 / 2;   // -3  (KHÔNG phải -4)
-7 % 2;   // -1  (dấu theo số bị chia)

// Chia double
double result = static_cast<double>(a) / b;  // 3.333...
```

### Toán tử tăng / giảm (Increment / Decrement)
```cpp
int x = 5;

// Prefix: tăng TRƯỚC, rồi dùng giá trị
int a = ++x;    // x = 6, a = 6

// Postfix: dùng giá trị TRƯỚC, rồi tăng
int b = x++;    // b = 6, x = 7

// ⚠️ TRÁNH dùng ++ nhiều lần trên cùng biến trong 1 biểu thức!
// int c = x++ + ++x;  // ❌ Undefined Behavior trước C++17!
```

> **Best practice:** Ưu tiên **prefix** (`++i`) trong vòng lặp — hiệu quả hơn với iterators.

## 1.2. Toán tử gán (Assignment)

```cpp
int x = 10;

x += 5;    // x = x + 5  → 15
x -= 3;    // x = x - 3  → 12
x *= 2;    // x = x * 2  → 24
x /= 4;    // x = x / 4  → 6
x %= 4;    // x = x % 4  → 2

// Bitwise assignment
x &= 0xFF;
x |= 0x01;
x ^= 0x10;
x <<= 2;
x >>= 1;
```

> ⚠️ **Bẫy:** `=` (gán) vs `==` (so sánh). `if (x = 5)` luôn true! Dùng `if (5 == x)` (Yoda condition) hoặc bật `-Wall`.

## 1.3. Toán tử so sánh (Comparison)

```cpp
int a = 5, b = 10;

a == b;    // false — bằng
a != b;    // true  — khác
a < b;     // true  — nhỏ hơn
a > b;     // false — lớn hơn
a <= b;    // true  — nhỏ hơn hoặc bằng
a >= b;    // false — lớn hơn hoặc bằng
```

### Three-way comparison `<=>` (C++20 Spaceship operator)
```cpp
#include <compare>

int a = 3, b = 5;
auto result = a <=> b;

if (result < 0)  std::cout << "a < b";   // ✅ In ra
if (result == 0) std::cout << "a == b";
if (result > 0)  std::cout << "a > b";

// Trả về kiểu:
// - std::strong_ordering    (int, char, enum)
// - std::weak_ordering      (custom types)
// - std::partial_ordering   (float, double — vì NaN)

// Auto-generate tất cả 6 operators!
struct Point {
    int x, y;
    auto operator<=>(const Point&) const = default;
    // Tự động có: ==, !=, <, >, <=, >=
};
```

## 1.4. Toán tử logic (Logical)

```cpp
bool a = true, b = false;

a && b;    // false — AND (cả 2 true)
a || b;    // true  — OR  (ít nhất 1 true)
!a;        // false — NOT (đảo ngược)
```

### ⚡ Short-circuit evaluation (Đánh giá ngắn mạch)
```cpp
// && : nếu vế trái false → KHÔNG đánh giá vế phải
if (ptr != nullptr && ptr->value > 0) {
    // An toàn! Nếu ptr == nullptr, ptr->value KHÔNG được gọi
}

// || : nếu vế trái true → KHÔNG đánh giá vế phải
if (cache_hit || expensive_lookup()) {
    // expensive_lookup() chỉ gọi khi cache_hit == false
}

// ⚠️ Side effects có thể bị skip!
int x = 0;
bool result = false && (++x > 0);
// x vẫn = 0! (++x không được thực thi)
```

---

# PHẦN II: TOÁN TỬ BITWISE

## 2.1. Các toán tử bitwise cơ bản

| Toán tử | Tên | Mô tả | Ví dụ (8-bit) |
|---------|-----|-------|---------------|
| `&` | AND | 1 nếu cả 2 bit = 1 | `0b1100 & 0b1010 = 0b1000` |
| `\|` | OR | 1 nếu ít nhất 1 bit = 1 | `0b1100 \| 0b1010 = 0b1110` |
| `^` | XOR | 1 nếu 2 bit khác nhau | `0b1100 ^ 0b1010 = 0b0110` |
| `~` | NOT | Đảo tất cả bit | `~0b1100 = 0b...0011` |
| `<<` | Left shift | Dịch trái n bit | `0b0001 << 3 = 0b1000` |
| `>>` | Right shift | Dịch phải n bit | `0b1000 >> 2 = 0b0010` |

```cpp
int a = 0b1100;  // 12
int b = 0b1010;  // 10

a & b;   // 0b1000 = 8   — AND
a | b;   // 0b1110 = 14  — OR
a ^ b;   // 0b0110 = 6   — XOR
~a;      // ~12 = -13     — NOT (two's complement)
a << 2;  // 0b110000 = 48 — Left shift (nhân 4)
a >> 1;  // 0b0110 = 6    — Right shift (chia 2)
```

## 2.2. Kỹ thuật bitwise thường dùng

### Kiểm tra bit
```cpp
// Kiểm tra bit thứ n có bật không
bool isSet(int x, int n) {
    return (x >> n) & 1;
    // hoặc: return x & (1 << n);
}
```

### Set / Clear / Toggle bit
```cpp
int x = 0b0000;

x |= (1 << 3);    // Set bit 3    → 0b1000
x &= ~(1 << 3);   // Clear bit 3  → 0b0000
x ^= (1 << 3);    // Toggle bit 3 → 0b1000
```

### Kiểm tra chẵn/lẻ
```cpp
bool isEven = (x & 1) == 0;   // Nhanh hơn x % 2
bool isOdd  = (x & 1) == 1;
```

### Swap không dùng biến tạm
```cpp
void swap(int& a, int& b) {
    a ^= b;   // a = a ^ b
    b ^= a;   // b = b ^ (a ^ b) = a
    a ^= b;   // a = (a ^ b) ^ a = b
}
// ⚠️ KHÔNG dùng khi a và b cùng địa chỉ! (a ^= a → 0)
```

### Nhân / Chia lũy thừa 2
```cpp
x << n;    // x * 2^n  (nhanh hơn phép nhân)
x >> n;    // x / 2^n  (nhanh hơn phép chia)

// ⚠️ Right shift với số âm: implementation-defined!
// Hầu hết compiler dùng arithmetic shift (giữ sign bit)
(-8) >> 1;   // Thường = -4 (arithmetic shift)
```

### Đếm số bit 1 (popcount)
```cpp
// C++20
#include <bit>
int count = std::popcount(static_cast<unsigned>(x));

// Thủ công (Brian Kernighan's algorithm)
int popcount(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1);  // Xóa bit 1 thấp nhất
        count++;
    }
    return count;
}
```

### Power of 2
```cpp
// Kiểm tra n là lũy thừa 2
bool isPowerOf2(unsigned n) {
    return n > 0 && (n & (n - 1)) == 0;
}

// Tìm bit cao nhất (C++20)
#include <bit>
int highest = std::bit_floor(x);   // Largest power of 2 ≤ x
int lowest  = std::countr_zero(x); // Position of lowest set bit
```

### Bitmask flags (thực tế)
```cpp
enum class Permission : uint8_t {
    None    = 0,
    Read    = 1 << 0,   // 0b001
    Write   = 1 << 1,   // 0b010
    Execute = 1 << 2    // 0b100
};

// Cần overload operators cho enum class
constexpr Permission operator|(Permission a, Permission b) {
    return static_cast<Permission>(
        static_cast<uint8_t>(a) | static_cast<uint8_t>(b)
    );
}
constexpr bool operator&(Permission a, Permission b) {
    return static_cast<uint8_t>(a) & static_cast<uint8_t>(b);
}

// Sử dụng
auto perms = Permission::Read | Permission::Write;
if (perms & Permission::Read) {
    std::cout << "Can read!" << std::endl;
}
```

---

# PHẦN III: TOÁN TỬ ĐẶC BIỆT

## 3.1. Toán tử 3 ngôi (Ternary `?:`)
```cpp
int x = 10;
std::string s = (x > 0) ? "Positive" : "Non-positive";

// Lồng nhau (khó đọc, nên tránh)
std::string grade = (score >= 90) ? "A"
                  : (score >= 80) ? "B"
                  : (score >= 70) ? "C"
                  : "F";

// ⚠️ Kiểu trả về phải tương thích
auto val = true ? 42 : 3.14;  // val = 42.0 (double, vì promotion)
```

## 3.2. Toán tử dấu phẩy (Comma `,`)
```cpp
// Đánh giá cả 2, trả về giá trị bên phải
int x = (1, 2, 3);   // x = 3

// Thường dùng trong for loop
for (int i = 0, j = 10; i < j; i++, j--) {
    // i tăng, j giảm
}

// ⚠️ Khác với dấu phẩy trong danh sách tham số!
f(a, b);       // 2 tham số
f((a, b));     // 1 tham số! (giá trị = b)
```

## 3.3. `sizeof` — Kích thước (compile-time)
```cpp
sizeof(int);         // 4 (bytes)
sizeof(double);      // 8
sizeof(char);        // 1 (luôn luôn)

int arr[10];
sizeof(arr);         // 40 (tổng kích thước mảng)
sizeof(arr) / sizeof(arr[0]);  // 10 (số phần tử)

// ⚠️ sizeof con trỏ ≠ sizeof mảng!
void foo(int arr[]) {
    sizeof(arr);     // 8 (kích thước con trỏ, KHÔNG phải mảng!)
}

// sizeof... cho variadic templates
template<typename... Args>
void bar(Args... args) {
    constexpr size_t n = sizeof...(args);  // Số lượng args
}
```

## 3.4. `alignof` — Yêu cầu alignment (C++11)
```cpp
alignof(int);        // 4
alignof(double);     // 8
alignof(char);       // 1

struct S { char c; int i; };
alignof(S);          // 4 (alignment theo member lớn nhất)
```

## 3.5. `typeid` — Thông tin kiểu (runtime)
```cpp
#include <typeinfo>

int x = 42;
std::cout << typeid(x).name() << std::endl;  // "i" (GCC) hoặc "int" (MSVC)

// Dùng với polymorphism
Base* p = new Derived();
std::cout << typeid(*p).name();  // In tên Derived (cần virtual)
```

## 3.6. `decltype` — Suy luận kiểu (compile-time, C++11)
```cpp
int x = 42;
decltype(x) y = 10;          // y là int
decltype(x + 0.5) z = 3.14;  // z là double

// Trong return type
template<typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
    return a + b;
}
```

## 3.7. `noexcept` — Kiểm tra exception (C++11)
```cpp
void safe() noexcept {}
void risky() {}

constexpr bool b1 = noexcept(safe());   // true
constexpr bool b2 = noexcept(risky());  // false
constexpr bool b3 = noexcept(1 + 2);    // true
```

---

# PHẦN IV: ÉP KIỂU (Type Casting)

## 4.1. C-style cast (❌ KHÔNG khuyến khích)
```cpp
double pi = 3.14;
int x = (int)pi;              // C-style
int y = int(pi);               // Function-style

// ⚠️ Quá mạnh! Có thể cast bất kỳ thứ gì mà không báo lỗi
const int* cp = &x;
int* p = (int*)cp;             // Bỏ const! Nguy hiểm!
```

## 4.2. `static_cast` — Cast an toàn, compile-time ✅
> Dùng cho: chuyển đổi kiểu tương thích (numeric, up/down cast, enum, void*).

```cpp
// Numeric conversion
double pi = 3.14;
int x = static_cast<int>(pi);           // 3 (truncation)

// Enum
enum class Color { Red, Green, Blue };
int n = static_cast<int>(Color::Green);  // 1

// void* conversion
void* vp = &x;
int* ip = static_cast<int*>(vp);

// Downcast (không an toàn — dùng dynamic_cast nếu cần kiểm tra)
Base* bp = new Derived();
Derived* dp = static_cast<Derived*>(bp);  // OK nếu thật sự là Derived
```

## 4.3. `dynamic_cast` — Cast an toàn, runtime ✅
> Dùng cho: downcast trong polymorphic hierarchy. Yêu cầu `virtual`.

```cpp
class Base { virtual void foo() {} };
class Derived : public Base { void bar() {} };

Base* bp = new Derived();

// Con trỏ: trả về nullptr nếu thất bại
Derived* dp = dynamic_cast<Derived*>(bp);
if (dp) {
    dp->bar();  // An toàn
}

// Tham chiếu: throw std::bad_cast nếu thất bại
try {
    Derived& dr = dynamic_cast<Derived&>(*bp);
} catch (const std::bad_cast& e) {
    std::cerr << e.what() << std::endl;
}

// ⚠️ Có overhead runtime (RTTI). Dùng khi thật sự cần.
```

## 4.4. `const_cast` — Thêm/bỏ `const`
> Dùng khi API cũ không nhận `const` nhưng không sửa dữ liệu.

```cpp
const int x = 42;
int* p = const_cast<int*>(&x);
*p = 100;  // ⚠️ Undefined Behavior! x là const thật sự

// Use case hợp lệ: gọi API cũ
void legacy_api(char* s);               // API không nhận const
const std::string& str = "hello";
legacy_api(const_cast<char*>(str.c_str()));  // OK nếu API không sửa
```

## 4.5. `reinterpret_cast` — Cast bit-level (⚠️ nguy hiểm)
> Diễn giải lại bit pattern. Hầu như KHÔNG nên dùng.

```cpp
int x = 42;
int* ip = &x;
long addr = reinterpret_cast<long>(ip);  // Địa chỉ dạng số

// Dùng trong embedded / networking
uint32_t raw = 0x40490FDB;              // IEEE 754 of pi
float pi = *reinterpret_cast<float*>(&raw);
// ⚠️ Strict aliasing violation! Dùng std::bit_cast thay (C++20)
```

## 4.6. `std::bit_cast` (C++20) — Cast bit-level an toàn ✅
```cpp
#include <bit>

float f = 3.14f;
uint32_t bits = std::bit_cast<uint32_t>(f);  // Xem bit pattern
float f2 = std::bit_cast<float>(bits);       // Khôi phục

// An toàn, constexpr, không UB!
// Yêu cầu: sizeof(From) == sizeof(To), cả 2 trivially copyable
```

### 📊 Tổng hợp Type Casting

| Cast | Compile/Runtime | Mục đích | An toàn |
|------|:---:|---------|:---:|
| `static_cast` | Compile | Numeric, up/down cast, enum | ✅ |
| `dynamic_cast` | Runtime | Downcasting polymorphic | ✅✅ |
| `const_cast` | Compile | Thêm/bỏ const | ⚠️ |
| `reinterpret_cast` | Compile | Bit reinterpretation | ❌ |
| `std::bit_cast` | Compile | Bit copy an toàn (C++20) | ✅ |
| `(type)expr` | Compile | C-style (all-in-one) | ❌ |

> **Rule:** `static_cast` > `dynamic_cast` > `std::bit_cast` >> `const_cast` >>> `reinterpret_cast` >>> C-style cast

---

# PHẦN V: IMPLICIT CONVERSIONS (Chuyển đổi ngầm)

## 5.1. Integer promotion
```cpp
// Kiểu nhỏ hơn int → int khi tính toán
char a = 10, b = 20;
auto c = a + b;          // c là int, KHÔNG phải char!
sizeof(c);               // 4

short s1 = 100, s2 = 200;
auto s3 = s1 + s2;       // s3 là int!

bool t = true;
auto r = t + t;           // r = 2, kiểu int
```

## 5.2. Usual arithmetic conversions
```cpp
// Khi 2 toán hạng khác kiểu → convert lên kiểu "rộng" hơn
int i = 5;
double d = 2.5;
auto result = i + d;     // result là double (5.0 + 2.5 = 7.5)

// Thứ tự: long double > double > float > unsigned long long > long long > ...

// ⚠️ signed vs unsigned trap!
int a = -1;
unsigned int b = 1;
auto c = a + b;           // c là unsigned int!
// -1 → 4294967295 (unsigned), + 1 = 4294967296 → overflow → 0
// Thực tế: -1u + 1u = 0 (wrap around)
```

## 5.3. Narrowing conversions
```cpp
double d = 3.14;
int i = d;                // OK (implicit, data loss) — warning
// int i{d};              // ❌ Compile error! Brace init ngăn narrowing

long long big = 1LL << 40;
int small = big;          // Mất dữ liệu!
// int small{big};        // ❌ Compile error!
```

> **Best practice:** Dùng `{}` (brace initialization) để ngăn narrowing conversion.

---

# PHẦN VI: THỨ TỰ ƯU TIÊN & KẾT HỢP (Precedence & Associativity)

## Bảng ưu tiên (cao → thấp)

| Ưu tiên | Toán tử | Kết hợp |
|:---:|---------|:---:|
| 1 | `::` | L→R |
| 2 | `a++` `a--` `()` `[]` `.` `->` | L→R |
| 3 | `++a` `--a` `+a` `-a` `!` `~` `*` `&` `sizeof` `new` `delete` `(type)` | **R→L** |
| 4 | `.*` `->*` | L→R |
| 5 | `*` `/` `%` | L→R |
| 6 | `+` `-` | L→R |
| 7 | `<<` `>>` | L→R |
| 8 | `<=>` | L→R |
| 9 | `<` `<=` `>` `>=` | L→R |
| 10 | `==` `!=` | L→R |
| 11 | `&` (bitwise) | L→R |
| 12 | `^` | L→R |
| 13 | `\|` | L→R |
| 14 | `&&` | L→R |
| 15 | `\|\|` | L→R |
| 16 | `?:` `=` `+=` `-=` ... `throw` `co_yield` | **R→L** |
| 17 | `,` | L→R |

### ⚠️ Bẫy precedence thường gặp
```cpp
// BẪY 1: Bitwise vs Comparison
if (x & 0xFF == 0)         // Thực tế: x & (0xFF == 0) → x & 0 = 0
if ((x & 0xFF) == 0)       // ✅ Đúng ý

// BẪY 2: Shift vs Addition
x = a << 2 + 1;            // Thực tế: a << (2 + 1) = a << 3
x = (a << 2) + 1;          // ✅ Đúng ý

// BẪY 3: Ternary vs Assignment
x = a > b ? a : b = 0;     // Parse: x = (a > b ? a : b) = 0  ❌
x = a > b ? a : (b = 0);   // ✅ Rõ ràng hơn

// RULE: Khi không chắc → THÊM NGOẶC!
```

---

# PHẦN VII: OPERATOR OVERLOADING (Giới thiệu)

> Chi tiết ở Day 20. Giới thiệu ở đây để biết toán tử có thể overload.

### Toán tử CÓ THỂ overload
```
+  -  *  /  %  ^  &  |  ~  !  =  <  >
+=  -=  *=  /=  %=  ^=  &=  |=  <<=  >>=
==  !=  <=  >=  <=>  &&  ||
++  --  ,  ->*  ->  ()  []
new  delete  new[]  delete[]
<<  >>  (chỉ khi ít nhất 1 toán hạng là user-defined type)
```

### Toán tử KHÔNG THỂ overload
```
::  .  .*  ?:  sizeof  alignof  typeid  noexcept
static_cast  dynamic_cast  const_cast  reinterpret_cast
```

### Ví dụ nhanh
```cpp
struct Vec2 {
    double x, y;

    Vec2 operator+(const Vec2& other) const {
        return {x + other.x, y + other.y};
    }

    bool operator==(const Vec2& other) const = default;  // C++20
};

Vec2 a{1, 2}, b{3, 4};
Vec2 c = a + b;   // {4, 6}
```

---

# PHẦN VIII: BIỂU THỨC NÂNG CAO

## 8.1. Fold expressions (C++17)
```cpp
// Tính tổng variadic
template<typename... Args>
auto sum(Args... args) {
    return (args + ...);                // Right fold: a + (b + (c + d))
    // return (... + args);             // Left fold:  ((a + b) + c) + d
    // return (0 + ... + args);         // Left fold with init
}

sum(1, 2, 3, 4);   // 10

// In tất cả
template<typename... Args>
void print(Args... args) {
    (std::cout << ... << args) << std::endl;  // Left fold
}
print("Hello", " ", "World");  // "Hello World"
```

## 8.2. Comma operator tricks
```cpp
// Fold expression với comma — gọi hàm cho mỗi arg
template<typename... Args>
void callAll(Args... args) {
    (process(args), ...);  // Gọi process() cho mỗi arg
}
```

## 8.3. Lambda expressions (giới thiệu)
```cpp
auto add = [](int a, int b) { return a + b; };
std::cout << add(3, 5);   // 8

// Generic lambda (C++14)
auto multiply = [](auto a, auto b) { return a * b; };
multiply(3, 4);      // 12
multiply(3.0, 4.0);  // 12.0

// Capture
int x = 10;
auto f = [x](int y) { return x + y; };    // Capture by value
auto g = [&x](int y) { return x + y; };   // Capture by reference
auto h = [=](int y) { return x + y; };    // Capture all by value
auto k = [&](int y) { return x + y; };    // Capture all by reference
```

---

## ✏️ Bài tập cơ bản
1. Viết máy tính đơn giản (+, -, *, /, %)
2. Kiểm tra số chẵn/lẻ bằng bitwise AND
3. Swap 2 số bằng XOR (không dùng biến tạm)
4. Viết hàm set/clear/toggle bit thứ n
5. Kiểm tra số có phải power of 2
6. Đếm số bit 1 trong một số nguyên
7. Viết chương trình sử dụng bitmask cho quyền file (read/write/execute)

---

## 🔥 20 Câu hỏi khó về Toán tử & Biểu thức

### Câu 1: Precedence trap — bitwise vs comparison
```cpp
int x = 5;
if (x & 1 == 0)
    std::cout << "even" << std::endl;
else
    std::cout << "odd" << std::endl;
```
**Hỏi:** Output là gì? `x = 5` là lẻ, tại sao kết quả có thể sai? Sửa lại thế nào?

---

### Câu 2: Signed right shift
```cpp
int a = -16;
int b = a >> 2;
std::cout << b << std::endl;

unsigned int c = static_cast<unsigned int>(-16);
unsigned int d = c >> 2;
std::cout << d << std::endl;
```
**Hỏi:** `b` và `d` bằng bao nhiêu? Tại sao khác nhau? Giải thích arithmetic shift vs logical shift.

---

### Câu 3: Sequence points & UB
```cpp
int i = 0;
int a = i++ + i++;     // (1)
int b = ++i + ++i;     // (2)
```
**Hỏi:** Giá trị `a` và `b`? Đây có phải Undefined Behavior không? Giải thích sequence points / sequencing rules.

---

### Câu 4: Short-circuit side effects
```cpp
int x = 0, y = 0;

bool r1 = (++x > 0) || (++y > 0);
std::cout << "x=" << x << " y=" << y << std::endl;

bool r2 = (x > 10) && (++y > 0);
std::cout << "x=" << x << " y=" << y << std::endl;
```
**Hỏi:** Giá trị `x`, `y` sau mỗi dòng? Giải thích short-circuit hoạt động.

---

### Câu 5: Comma operator
```cpp
int a = (1, 2, 3);
int b = 1, 2, 3;        // Compile không?
int c = (1 + 2, 3 + 4);

void foo(int x, int y);
foo((1, 2), 3);          // Gọi foo(?, ?)
```
**Hỏi:** Giá trị `a`, `c`? Dòng `b` compile không? `foo` nhận tham số gì?

---

### Câu 6: Integer division & modulo
```cpp
std::cout << 7 / 2 << std::endl;      // (1)
std::cout << -7 / 2 << std::endl;     // (2)
std::cout << 7 / -2 << std::endl;     // (3)
std::cout << -7 / -2 << std::endl;    // (4)

std::cout << 7 % 2 << std::endl;      // (5)
std::cout << -7 % 2 << std::endl;     // (6)
std::cout << 7 % -2 << std::endl;     // (7)
std::cout << -7 % -2 << std::endl;    // (8)
```
**Hỏi:** Output mỗi dòng? Quy tắc chia nguyên và modulo với số âm trong C++ là gì? (truncation toward zero)

---

### Câu 7: Implicit conversion in mixed operations
```cpp
unsigned int a = 1;
int b = -2;
auto c = a + b;

std::cout << c << std::endl;
std::cout << (c > 0 ? "positive" : "negative") << std::endl;

if (a + b > 0)
    std::cout << "Greater than 0" << std::endl;
else
    std::cout << "Not greater" << std::endl;
```
**Hỏi:** `c` có kiểu gì? Giá trị bao nhiêu? Tại sao kết quả so sánh bất ngờ?

---

### Câu 8: sizeof traps
```cpp
int arr[10];
int* p = arr;

std::cout << sizeof(arr) << std::endl;    // (1)
std::cout << sizeof(p) << std::endl;      // (2)
std::cout << sizeof(*p) << std::endl;     // (3)
std::cout << sizeof(arr[0]) << std::endl; // (4)

void foo(int arr[10]) {
    std::cout << sizeof(arr) << std::endl; // (5) ???
}
```
**Hỏi:** Output mỗi dòng? Đặc biệt (5) — tại sao `sizeof` trong hàm cho kết quả khác?

---

### Câu 9: Ternary type deduction
```cpp
auto a = true ? 42 : 3.14;
auto b = true ? "hello" : std::string("world");
// auto c = true ? 42 : "hello";  // Compile không?

int x = 5, y = 10;
(x > y ? x : y) = 100;
std::cout << x << " " << y << std::endl;
```
**Hỏi:** `a` có kiểu gì? `b` compile không? `c` compile không? Dòng cuối: `x` và `y` bằng bao nhiêu?

---

### Câu 10: Bitwise NOT với unsigned
```cpp
uint8_t  a = 0;
uint16_t b = 0;
uint32_t c = 0;

auto ra = ~a;
auto rb = ~b;
auto rc = ~c;

std::cout << sizeof(ra) << " " << ra << std::endl;
std::cout << sizeof(rb) << " " << rb << std::endl;
std::cout << sizeof(rc) << " " << rc << std::endl;
```
**Hỏi:** Mỗi dòng output gì? Tại sao `sizeof(~a)` KHÔNG phải 1? (Integer promotion!)

---

### Câu 11: Cast away const — UB?
```cpp
const int x = 42;
int* p = const_cast<int*>(&x);
*p = 100;
std::cout << x << std::endl;    // (1)
std::cout << *p << std::endl;   // (2)
```
**Hỏi:** Output dòng (1) và (2)? Có thể giống hoặc khác nhau — tại sao? Đây có phải UB? Giải thích.

---

### Câu 12: static_cast vs reinterpret_cast
```cpp
int x = 42;
// (1)
double d1 = static_cast<double>(x);
// (2)
double d2 = *reinterpret_cast<double*>(&x);  // ⚠️
```
**Hỏi:** `d1` và `d2` có giống nhau không? Tại sao? `d2` có giá trị gì? Đây có phải UB?

---

### Câu 13: XOR swap pitfall
```cpp
int arr[] = {1, 2, 3};
int i = 0;

// Swap arr[i] và arr[i]
arr[i] ^= arr[i];
arr[i] ^= arr[i];
arr[i] ^= arr[i];

std::cout << arr[0] << std::endl;
```
**Hỏi:** Output là gì? Tại sao XOR swap thất bại khi 2 operands là cùng 1 biến?

---

### Câu 14: Fold expression order
```cpp
template<typename... Args>
auto right_fold(Args... args) {
    return (args - ...);    // Right fold
}

template<typename... Args>
auto left_fold(Args... args) {
    return (... - args);    // Left fold
}

std::cout << right_fold(1, 2, 3, 4) << std::endl;
std::cout << left_fold(1, 2, 3, 4) << std::endl;
```
**Hỏi:** Output mỗi dòng? Giải thích sự khác nhau giữa left fold và right fold.

---

### Câu 15: Overflow semantics
```cpp
int a = INT_MAX;
unsigned int b = UINT_MAX;

int c = a + 1;           // (1)
unsigned int d = b + 1;  // (2)
int e = a * 2;           // (3)
unsigned int f = b * 2;  // (4)

// Bonus:
int g = INT_MIN / -1;    // (5) ??
int h = INT_MIN % -1;    // (6) ??
```
**Hỏi:** Giá trị và UB status của mỗi dòng? Tại sao signed overflow là UB nhưng unsigned overflow thì không?

---

### Câu 16: Spaceship operator details
```cpp
#include <compare>

struct Fraction {
    int num, den;
    auto operator<=>(const Fraction& other) const {
        return num * other.den <=> other.num * den;
    }
    bool operator==(const Fraction& other) const = default;
};

Fraction a{1, 2}, b{2, 4};
std::cout << (a == b) << std::endl;        // (1)
std::cout << (a <=> b == 0) << std::endl;  // (2)
```
**Hỏi:** Output dòng (1) và (2)? Tại sao có thể khác nhau? Khi nào cần viết `operator==` riêng thay vì dùng `= default`?

---

### Câu 17: Lambda capture semantics
```cpp
int x = 10;
auto f1 = [x]() mutable { return ++x; };
auto f2 = [&x]() { return ++x; };

std::cout << f1() << std::endl;  // (1)
std::cout << f1() << std::endl;  // (2)
std::cout << x << std::endl;     // (3)

std::cout << f2() << std::endl;  // (4)
std::cout << x << std::endl;     // (5)
```
**Hỏi:** Output mỗi dòng? `mutable` làm gì? Sự khác nhau giữa capture by value và by reference?

---

### Câu 18: Pointer arithmetic precision
```cpp
int arr[5] = {10, 20, 30, 40, 50};
int* p = arr;

std::cout << *(p + 2) << std::endl;        // (1)
std::cout << *p + 2 << std::endl;          // (2)
std::cout << *(p++) << std::endl;          // (3)
std::cout << *(++p) << std::endl;          // (4)
std::cout << p - arr << std::endl;         // (5)
```
**Hỏi:** Output mỗi dòng? Giải thích precedence giữa `*`, `+`, `++` và pointer arithmetic.

---

### Câu 19: Boolean algebra traps
```cpp
int x = 2;

if (x == 1 || 2)           // (1) Luôn true? Tại sao?
    std::cout << "A" << std::endl;

if (x == 1 || x == 2)      // (2) Đúng cách
    std::cout << "B" << std::endl;

if (1 < x < 5)             // (3) Luôn true? Tại sao?
    std::cout << "C" << std::endl;

if (1 < x && x < 5)        // (4) Đúng cách
    std::cout << "D" << std::endl;
```
**Hỏi:** Dòng nào in ra? Giải thích tại sao (1) và (3) là bẫy logic phổ biến.

---

### Câu 20: Expression SFINAE & decltype
```cpp
// Kiểm tra type có operator+ không
template<typename T, typename = void>
struct has_plus : std::false_type {};

template<typename T>
struct has_plus<T, std::void_t<decltype(std::declval<T>() + std::declval<T>())>>
    : std::true_type {};

std::cout << has_plus<int>::value << std::endl;         // (1)
std::cout << has_plus<std::string>::value << std::endl;  // (2)

struct NoPlus {};
std::cout << has_plus<NoPlus>::value << std::endl;       // (3)
```
**Hỏi:** Output mỗi dòng? Giải thích SFINAE (Substitution Failure Is Not An Error) hoạt động. `std::void_t` và `std::declval` dùng để làm gì?

---

## 📌 Tổng kết — Rules of Thumb

> 1. **Khi không chắc precedence → THÊM NGOẶC `()`**
> 2. **Dùng `static_cast` thay C-style cast** — an toàn, rõ ràng
> 3. **Prefix `++i` tốt hơn postfix `i++`** khi không cần giá trị cũ
> 4. **Cẩn thận signed/unsigned mixing** — source #1 of subtle bugs
> 5. **Short-circuit `&&` `||`** — đặt điều kiện rẻ trước, đắt sau
> 6. **Brace init `{}` ngăn narrowing** — luôn ưu tiên dùng
> 7. **`= default` cho `<=>` (C++20)** — tự generate 6 comparison operators
> 8. **Bitwise ops → luôn dùng `unsigned`** — tránh implementation-defined behavior
