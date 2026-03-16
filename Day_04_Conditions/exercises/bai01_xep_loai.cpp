/*
 * Bai tap 1: Xep loai hoc sinh theo diem
 *
 * Yeu cau:
 * - Nhap diem tu ban phim (0-100)
 * - Xep loai: A (>= 90), B (>= 80), C (>= 70), D (>= 60), F (< 60)
 * - Kiem tra diem hop le (0-100)
 * - In ket qua
 */

#include <iostream>
#include <string>

int main() {
    double score;

    std::cout << "=== Xep loai hoc sinh ===" << std::endl;
    std::cout << "Nhap diem (0 - 100): ";
    std::cin >> score;

    // Kiem tra diem hop le
    if (score < 0 || score > 100) {
        std::cout << "Diem khong hop le! Phai trong khoang 0-100." << std::endl;
        return 1;
    }

    // Xep loai
    char grade;
    std::string description;

    if (score >= 90) {
        grade = 'A';
        description = "Xuat sac";
    } else if (score >= 80) {
        grade = 'B';
        description = "Gioi";
    } else if (score >= 70) {
        grade = 'C';
        description = "Kha";
    } else if (score >= 60) {
        grade = 'D';
        description = "Trung binh";
    } else {
        grade = 'F';
        description = "Yeu";
    }

    std::cout << "\nKet qua:" << std::endl;
    std::cout << "  Diem: " << score << std::endl;
    std::cout << "  Xep loai: " << grade << " (" << description << ")" << std::endl;

    // Bonus: nhan xet them
    if (grade == 'A' || grade == 'B') {
        std::cout << "  => Hoc sinh gioi! Tiep tuc phat huy!" << std::endl;
    } else if (grade == 'F') {
        std::cout << "  => Can co gang hon!" << std::endl;
    }

    return 0;
}
