# Day 27: Smart Pointers & RAII

## 🎯 Mục tiêu
- `unique_ptr`, `shared_ptr`, `weak_ptr`
- RAII (Resource Acquisition Is Initialization)
- Move semantics cơ bản

## 📖 Lý thuyết

### unique_ptr
```cpp
#include <memory>
auto p = std::make_unique<int>(42);
std::cout << *p;  // 42
// Tự giải phóng khi ra khỏi scope

// Không thể copy, chỉ move
auto p2 = std::move(p);  // p bây giờ = nullptr
```

### shared_ptr
```cpp
auto sp1 = std::make_shared<int>(100);
auto sp2 = sp1;  // reference count = 2
std::cout << sp1.use_count();  // 2
```

### weak_ptr
```cpp
std::weak_ptr<int> wp;
{
    auto sp = std::make_shared<int>(42);
    wp = sp;
    // sp vẫn tồn tại
}
// sp bị giải phóng, wp.lock() trả về nullptr
```

### RAII Pattern
```cpp
class FileHandler {
    std::ofstream file;
public:
    FileHandler(const std::string& path) : file(path) {
        if (!file.is_open()) throw std::runtime_error("Cannot open file");
    }
    ~FileHandler() { file.close(); }  // Tự đóng file
    void write(const std::string& data) { file << data; }
};
```

## ✏️ Bài tập
1. Refactor Day 13 dùng smart pointers thay `new/delete`
2. Tạo class `ResourceManager` theo RAII
3. Implement Observer pattern dùng `shared_ptr` + `weak_ptr`
