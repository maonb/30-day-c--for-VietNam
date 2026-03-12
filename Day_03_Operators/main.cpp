#include <iostream>

int main() {
    int a = 10, b = 3;

    // Toan tu so hoc
    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "a - b = " << a - b << std::endl;
    std::cout << "a * b = " << a * b << std::endl;
    std::cout << "a / b = " << a / b << std::endl;
    std::cout << "a % b = " << a % b << std::endl;

    // Toan tu so sanh
    std::cout << "a == b: " << std::boolalpha << (a == b) << std::endl;
    std::cout << "a > b:  " << (a > b) << std::endl;

    // Ep kieu
    double result = static_cast<double>(a) / b;
    std::cout << "a / b (double) = " << result << std::endl;

    return 0;
}
