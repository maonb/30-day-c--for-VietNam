#include <iostream>
#include <string>
#include <cmath>

int main() {
    // ============================================
    // PHAN 1: if / else if / else
    // ============================================
    std::cout << "=== PHAN 1: if / else if / else ===" << std::endl;

    int score = 85;
    std::cout << "Diem: " << score << " -> ";
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

    // So sanh so thuc an toan
    double a = 0.1 + 0.2;
    double b = 0.3;
    const double EPSILON = 1e-9;
    std::cout << "\n0.1 + 0.2 == 0.3 ? " << std::boolalpha << (a == b) << std::endl;
    std::cout << "So sanh voi epsilon: " << (std::abs(a - b) < EPSILON) << std::endl;

    // ============================================
    // PHAN 2: switch / case
    // ============================================
    std::cout << "\n=== PHAN 2: switch / case ===" << std::endl;

    // Ngay trong tuan
    int day = 5;
    std::cout << "Ngay " << day << ": ";
    switch (day) {
        case 1: std::cout << "Thu Hai" << std::endl; break;
        case 2: std::cout << "Thu Ba" << std::endl; break;
        case 3: std::cout << "Thu Tu" << std::endl; break;
        case 4: std::cout << "Thu Nam" << std::endl; break;
        case 5: std::cout << "Thu Sau" << std::endl; break;
        case 6: std::cout << "Thu Bay" << std::endl; break;
        case 7: std::cout << "Chu Nhat" << std::endl; break;
        default: std::cout << "Khong hop le!" << std::endl;
    }

    // Fall-through: nhom ngay
    std::cout << "Ngay " << day << " la: ";
    switch (day) {
        case 1: case 2: case 3: case 4: case 5:
            std::cout << "Ngay lam viec" << std::endl;
            break;
        case 6: case 7:
            std::cout << "Cuoi tuan" << std::endl;
            break;
        default:
            std::cout << "Khong hop le" << std::endl;
    }

    // ============================================
    // PHAN 3: Toan tu 3 ngoi ?:
    // ============================================
    std::cout << "\n=== PHAN 3: Toan tu ba ngoi ===" << std::endl;

    int x = -5;
    std::string sign = (x > 0) ? "Duong" : (x < 0) ? "Am" : "Khong";
    std::cout << x << " la so: " << sign << std::endl;

    // Tim max cua 2 so
    int m = 15, n = 23;
    int maxVal = (m > n) ? m : n;
    std::cout << "Max(" << m << ", " << n << ") = " << maxVal << std::endl;

    // Gia tri tuyet doi
    int absVal = (x >= 0) ? x : -x;
    std::cout << "|" << x << "| = " << absVal << std::endl;

    // ============================================
    // PHAN 4: Kiem tra nam nhuan
    // ============================================
    std::cout << "\n=== PHAN 4: Kiem tra nam nhuan ===" << std::endl;

    int year = 2024;
    bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    std::cout << "Nam " << year << (isLeap ? " la" : " KHONG la")
              << " nam nhuan" << std::endl;

    year = 1900;
    isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    std::cout << "Nam " << year << (isLeap ? " la" : " KHONG la")
              << " nam nhuan" << std::endl;

    year = 2000;
    isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    std::cout << "Nam " << year << (isLeap ? " la" : " KHONG la")
              << " nam nhuan" << std::endl;

    // ============================================
    // PHAN 5: Truthy / Falsy demo
    // ============================================
    std::cout << "\n=== PHAN 5: Truthy / Falsy ===" << std::endl;

    std::cout << "0     -> " << (0 ? "truthy" : "falsy") << std::endl;
    std::cout << "-1    -> " << (-1 ? "truthy" : "falsy") << std::endl;
    std::cout << "3.14  -> " << (3.14 ? "truthy" : "falsy") << std::endl;
    std::cout << "0.0   -> " << (0.0 ? "truthy" : "falsy") << std::endl;
    std::cout << "'\\0'  -> " << ('\0' ? "truthy" : "falsy") << std::endl;
    std::cout << "'A'   -> " << ('A' ? "truthy" : "falsy") << std::endl;

    // ============================================
    // PHAN 6: May tinh don gian
    // ============================================
    std::cout << "\n=== PHAN 6: May tinh don gian ===" << std::endl;

    double num1 = 10, num2 = 3;
    char ops[] = {'+', '-', '*', '/'};

    for (char op : ops) {
        std::cout << num1 << " " << op << " " << num2 << " = ";
        switch (op) {
            case '+': std::cout << num1 + num2; break;
            case '-': std::cout << num1 - num2; break;
            case '*': std::cout << num1 * num2; break;
            case '/':
                if (num2 != 0)
                    std::cout << num1 / num2;
                else
                    std::cout << "LOI: chia cho 0!";
                break;
        }
        std::cout << std::endl;
    }

    return 0;
}
