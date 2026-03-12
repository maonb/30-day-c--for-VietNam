# Day 22: Templates

## 🎯 Mục tiêu
- Function templates
- Class templates
- Template specialization

## 📖 Lý thuyết

### Function Template
```cpp
template <typename T>
T maxValue(T a, T b) {
    return (a > b) ? a : b;
}

maxValue(3, 7);        // int
maxValue(3.14, 2.71);  // double
maxValue('a', 'z');    // char
```

### Class Template
```cpp
template <typename T>
class Stack {
    std::vector<T> data;
public:
    void push(const T& val) { data.push_back(val); }
    T pop() {
        T top = data.back();
        data.pop_back();
        return top;
    }
    bool empty() const { return data.empty(); }
};

Stack<int> intStack;
Stack<std::string> strStack;
```

## ✏️ Bài tập
1. Viết template function `swap<T>`
2. Viết template class `Pair<T1, T2>`
3. Viết template class `DynamicArray<T>` (giống vector đơn giản)
