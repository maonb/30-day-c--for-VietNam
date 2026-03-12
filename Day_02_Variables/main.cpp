#include <iostream>
#include <string>

int main() {
    // Khai bao bien
    int age = 25;
    double height = 1.75;
    char grade = 'A';
    bool isStudent = true;
    std::string name = "Nguyen Van A";

    std::cout << "Ten: " << name << std::endl;
    std::cout << "Tuoi: " << age << std::endl;
    std::cout << "Chieu cao: " << height << "m" << std::endl;
    std::cout << "Xep loai: " << grade << std::endl;
    std::cout << "La sinh vien: " << std::boolalpha << isStudent << std::endl;

    return 0;
}
