#include <iostream>
#include <cmath> 

void calculateExponentiation() {
    int choice;
    std::cout << "Выберите операцию:\n";
    std::cout << "1. e^x\n";
    std::cout << "2. x^y\n";
    std::cout << "Введите номер операции (1 или 2): ";
    std::cin >> choice;

    if (choice == 1) {
        double x;
        std::cout << "Введите значение x: ";
        std::cin >> x;
        double result = exp(x); // e^x
        std::cout << "Результат e^" << x << " = " << result << std::endl;
    } else if (choice == 2) {
        double x, y;
        std::cout << "Введите значение x: ";
        std::cin >> x;
        std::cout << "Введите значение y: ";
        std::cin >> y;
        double result = pow(x, y); // x^y
        std::cout << "Результат " << x << "^" << y << " = " << result << std::endl;
    } else {
        std::cout << "Неверный выбор. Пожалуйста, выберите 1 или 2." << std::endl;
    }
}

int main() {
    calculateExponentiation();
    return 0;
}
