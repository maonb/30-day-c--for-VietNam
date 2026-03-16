/*
 * Bai tap 2: Kiem tra nam nhuan
 *
 * Quy tac:
 * - Nam nhuan neu chia het cho 4 VA khong chia het cho 100
 * - HOAC chia het cho 400
 *
 * Vi du:
 * - 2024 → nhuan (chia het 4, khong chia het 100)
 * - 1900 → KHONG nhuan (chia het 100, khong chia het 400)
 * - 2000 → nhuan (chia het 400)
 */

#include <iostream>

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
    int year;

    std::cout << "=== Kiem tra nam nhuan ===" << std::endl;
    std::cout << "Nhap nam: ";
    std::cin >> year;

    if (year <= 0) {
        std::cout << "Nam khong hop le!" << std::endl;
        return 1;
    }

    if (isLeapYear(year)) {
        std::cout << "Nam " << year << " LA nam nhuan." << std::endl;
    } else {
        std::cout << "Nam " << year << " KHONG PHAI nam nhuan." << std::endl;
    }

    // Giai thich ly do
    std::cout << "\nGiai thich:" << std::endl;
    if (year % 400 == 0) {
        std::cout << "  " << year << " chia het cho 400 => Nam nhuan" << std::endl;
    } else if (year % 100 == 0) {
        std::cout << "  " << year << " chia het cho 100 nhung KHONG chia het cho 400"
                  << " => KHONG nhuan" << std::endl;
    } else if (year % 4 == 0) {
        std::cout << "  " << year << " chia het cho 4 va KHONG chia het cho 100"
                  << " => Nam nhuan" << std::endl;
    } else {
        std::cout << "  " << year << " KHONG chia het cho 4 => KHONG nhuan" << std::endl;
    }

    // Bonus: kiem tra nhieu nam
    std::cout << "\n--- Kiem tra cac nam dac biet ---" << std::endl;
    int testYears[] = {1900, 2000, 2020, 2023, 2024, 2100};
    for (int y : testYears) {
        std::cout << "  " << y << ": "
                  << (isLeapYear(y) ? "Nhuan" : "Khong nhuan") << std::endl;
    }

    return 0;
}
