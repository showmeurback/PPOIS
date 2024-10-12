#include <iostream>
#include "SignedFraction.h"

void displayMenu() {
    std::cout << "Выберите операцию:\n";
    std::cout << "1. Сложение\n";
    std::cout << "2. Вычитание\n";
    std::cout << "3. Умножение\n";
    std::cout << "4. Деление\n";
    std::cout << "5. Выход\n";
}

SignedFraction inputFraction() {
    int numerator, denominator;
    char slash;

    std::cout << "Введите дробь (например, 1/2): ";
    std::cin >> numerator >> slash >> denominator;

    return SignedFraction(numerator, denominator);
}

int main() {
    setlocale(LC_ALL, "RU");
    while (true) {
        displayMenu();
        int choice;
        std::cin >> choice;

        if (choice == 5) {
            std::cout << "Выход из программы.\n";
            break;
        }

        SignedFraction frac1 = inputFraction();
        SignedFraction frac2 = inputFraction();
        SignedFraction result;

        switch (choice) {
        case 1:
            result = frac1 + frac2;
            std::cout << "Результат: " << result.getNumerator() << '/' << result.getDenominator() << "\n";
            break;
        case 2:
            result = frac1 - frac2;
            std::cout << "Результат: " << result.getNumerator() << '/' << result.getDenominator() << "\n";
            break;
        case 3:
            result = frac1 * frac2;
            std::cout << "Результат: " << result.getNumerator() << '/' << result.getDenominator() << "\n";
            break;
        case 4:
            try {
                result = frac1 / frac2;
                std::cout << "Результат: " << result.getNumerator() << '/' << result.getDenominator() << "\n";
            }
            catch (const std::invalid_argument& e) {
                std::cout << "Ошибка: " << e.what() << "\n";
            }
            break;
        default:
            std::cout << "Неверный выбор, попробуйте снова.\n";
            break;
        }
    }

    return 0;
}