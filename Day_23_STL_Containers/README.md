# Day 23: STL Containers

## 🎯 Mục tiêu
- `vector`, `list`, `deque`
- `map`, `set`, `unordered_map`, `unordered_set`
- `stack`, `queue`, `priority_queue`

## 📖 Lý thuyết

### vector
```cpp
#include <vector>
std::vector<int> v = {1, 2, 3};
v.push_back(4);
v.size();       // 4
v[0];           // 1
v.erase(v.begin() + 1);  // Xóa phần tử thứ 2
```

### map
```cpp
#include <map>
std::map<std::string, int> ages;
ages["Alice"] = 25;
ages["Bob"] = 30;
for (auto& [key, val] : ages) {
    std::cout << key << ": " << val << std::endl;
}
```

### set
```cpp
#include <set>
std::set<int> s = {3, 1, 4, 1, 5};  // {1, 3, 4, 5} - tự sắp xếp, unique
```

## ✏️ Bài tập
1. Đếm tần suất từ trong văn bản dùng `map`
2. Loại bỏ phần tử trùng dùng `set`
3. Implement stack-based bracket checker
4. Dùng `priority_queue` để sắp xếp
