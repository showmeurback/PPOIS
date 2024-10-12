#include <iostream>
#include "SignedFraction.h"

void displayMenu() {
    std::cout << "�������� ��������:\n";
    std::cout << "1. ��������\n";
    std::cout << "2. ���������\n";
    std::cout << "3. ���������\n";
    std::cout << "4. �������\n";
    std::cout << "5. �����\n";
}

SignedFraction inputFraction() {
    int numerator, denominator;
    char slash;

    std::cout << "������� ����� (��������, 1/2): ";
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
            std::cout << "����� �� ���������.\n";
            break;
        }

        SignedFraction frac1 = inputFraction();
        SignedFraction frac2 = inputFraction();
        SignedFraction result;

        switch (choice) {
        case 1:
            result = frac1 + frac2;
            std::cout << "���������: " << result.getNumerator() << '/' << result.getDenominator() << "\n";
            break;
        case 2:
            result = frac1 - frac2;
            std::cout << "���������: " << result.getNumerator() << '/' << result.getDenominator() << "\n";
            break;
        case 3:
            result = frac1 * frac2;
            std::cout << "���������: " << result.getNumerator() << '/' << result.getDenominator() << "\n";
            break;
        case 4:
            try {
                result = frac1 / frac2;
                std::cout << "���������: " << result.getNumerator() << '/' << result.getDenominator() << "\n";
            }
            catch (const std::invalid_argument& e) {
                std::cout << "������: " << e.what() << "\n";
            }
            break;
        default:
            std::cout << "�������� �����, ���������� �����.\n";
            break;
        }
    }

    return 0;
}