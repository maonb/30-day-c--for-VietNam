/*
 * Bai tap 3: Tim so lon nhat trong 3 so
 *
 * Yeu cau:
 * - Nhap 3 so tu ban phim
 * - Tim va in ra so lon nhat
 * - Su dung nhieu cach: if/else, toan tu 3 ngoi, std::max
 */

#include <iostream>
#include <algorithm>   // std::max

int main() {
    double a, b, c;

    std::cout << "=== Tim so lon nhat trong 3 so ===" << std::endl;
    std::cout << "Nhap so thu 1: ";
    std::cin >> a;
    std::cout << "Nhap so thu 2: ";
    std::cin >> b;
    std::cout << "Nhap so thu 3: ";
    std::cin >> c;

    std::cout << "\nBa so da nhap: " << a << ", " << b << ", " << c << std::endl;

    // ---- Cach 1: if / else if / else ----
    double max1;
    if (a >= b && a >= c) {
        max1 = a;
    } else if (b >= a && b >= c) {
        max1 = b;
    } else {
        max1 = c;
    }
    std::cout << "\nCach 1 (if/else):    Max = " << max1 << std::endl;

    // ---- Cach 2: Toan tu 3 ngoi ----
    double max2 = (a >= b) ? ((a >= c) ? a : c)
                           : ((b >= c) ? b : c);
    std::cout << "Cach 2 (ternary):    Max = " << max2 << std::endl;

    // ---- Cach 3: so sanh tung cap ----
    double max3 = a;
    if (b > max3) max3 = b;
    if (c > max3) max3 = c;
    std::cout << "Cach 3 (tung cap):   Max = " << max3 << std::endl;

    // ---- Cach 4: std::max (khuyen dung) ----
    double max4 = std::max({a, b, c});
    std::cout << "Cach 4 (std::max):   Max = " << max4 << std::endl;

    // Bonus: tim so nho nhat
    double minVal = std::min({a, b, c});
    std::cout << "\nBonus: Min = " << minVal << std::endl;

    return 0;
}
