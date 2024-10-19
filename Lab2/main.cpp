#include <iostream>
#include <vector>
#include <limits>
#include "Aircraft.h"
#include "Airport.h"
#include "CheckIn.h"
#include "Passenger.h"
#include "Ticket.h"
#include "Flight.h"
#include "ReservationSystem.h"
#include "Security.h"
#include "CustomerService.h"
#include "Maintenance.h"
#include "Airline.h"
#include "Baggage.h"
#include "FlightSchedule.h"

void displayMenu() {
    setlocale(LC_ALL, "RU");
    std::cout << "Выберите команду:\n";
    std::cout << "1. Создать пассажира\n";
    std::cout << "2. Создать авиакомпанию\n";
    std::cout << "3. Создать самолет\n";
    std::cout << "4. Создать рейс\n";
    std::cout << "5. Забронировать билет\n";
    std::cout << "6. Проверить безопасность пассажира\n";
    std::cout << "7. Выполнить техническое обслуживание самолета\n";
    std::cout << "8. Добавить багаж\n";
    std::cout << "9. Показать расписание рейсов\n";
    std::cout << "10. Выйти\n";
}

int main() {
    // Переменные для хранения данных
    std::vector<Passenger> passengers;
    std::vector<Flight> flights;
    std::vector<Aircraft> aircrafts;
    Airline airline("Airline One");
    ReservationSystem reservationSystem;
    FlightSchedule flightSchedule;
    int choice;

    do {
        displayMenu();
        std::cout << "Ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            // Создать пассажира
            std::string name, passportNumber;
            int age;

            std::cout << "Введите имя пассажира: ";
            std::cin.ignore(); // Игнорируем остатки строки
            std::getline(std::cin, name);
            std::cout << "Введите номер паспорта: ";
            std::getline(std::cin, passportNumber);
            std::cout << "Введите возраст: ";
            std::cin >> age;

            passengers.emplace_back(name, passportNumber, age);
            std::cout << "Пассажир " << name << " создан.\n";
            break;
        }
        case 2: {
            // Создать авиакомпанию
            std::string airlineName;
            std::cout << "Введите название авиакомпании: ";
            std::cin.ignore();
            std::getline(std::cin, airlineName);
            airline = Airline(airlineName);
            std::cout << "Авиакомпания " << airlineName << " создана.\n";
            break;
        }
        case 3: {
            // Создать самолет
            std::string model, registrationNumber;
            int capacity;

            std::cout << "Введите модель самолета: ";
            std::cin.ignore();
            std::getline(std::cin, model);
            std::cout << "Введите номер регистрации: ";
            std::getline(std::cin, registrationNumber);
            std::cout << "Введите емкость самолета: ";
            std::cin >> capacity;

            Aircraft aircraft(model, capacity, registrationNumber);
            airline.addAircraft(aircraft);
            aircrafts.push_back(aircraft);
            std::cout << "Самолет " << model << " создан.\n";
            break;
        }
        case 4: {
            // Создать рейс
            std::string flightNumber, origin, destination, departureTime, arrivalTime;
            int capacity;

            std::cout << "Введите номер рейса: ";
            std::cin.ignore();
            std::getline(std::cin, flightNumber);
            std::cout << "Введите пункт отправления: ";
            std::getline(std::cin, origin);
            std::cout << "Введите пункт назначения: ";
            std::getline(std::cin, destination);
            std::cout << "Введите время отправления: ";
            std::getline(std::cin, departureTime);
            std::cout << "Введите время прибытия: ";
            std::getline(std::cin, arrivalTime);
            std::cout << "Введите емкость рейса: ";
            std::cin >> capacity;

            Flight flight(flightNumber, origin, destination, departureTime, arrivalTime, capacity);
            flights.push_back(flight);
            flightSchedule.addFlight(flight);
            std::cout << "Рейс " << flightNumber << " создан.\n";
            break;
        }
        case 5: {
            // Забронировать билет
            if (passengers.empty() || flights.empty()) {
                std::cout << "Сначала создайте пассажиров и рейсы.\n";
                break;
            }

            int ticketID;
            double price;
            std::string flightNumber;

            std::cout << "Введите ID билета: ";
            std::cin >> ticketID;
            std::cout << "Введите цену билета: ";
            std::cin >> price;
            std::cout << "Введите номер рейса: ";
            std::cin.ignore();
            std::getline(std::cin, flightNumber);

            // Находим пассажира
            Passenger* passenger = nullptr;
            for (auto& p : passengers) {
                if (p.passportNumber == flightNumber) { // Используем номер паспорта для поиска
                    passenger = &p;
                    break;
                }
            }

            if (passenger) {
                Ticket ticket(ticketID, price, flightNumber, *passenger);
                reservationSystem.bookTicket(ticket);
                std::cout << "Билет забронирован для " << passenger->name << ".\n";
            }
            else {
                std::cout << "Пассажир не найден.\n";
            }
            break;
        }
        case 6: {
            // Проверить безопасность пассажира
            if (passengers.empty()) {
                std::cout << "Сначала создайте пассажиров.\n";
                break;
            }

            std::string passportNumber;
            std::cout << "Введите номер паспорта пассажира для проверки: ";
            std::cin.ignore();
            std::getline(std::cin, passportNumber);

            // Находим пассажира
            Passenger* passenger = nullptr;
            for (auto& p : passengers) {
                if (p.passportNumber == passportNumber) {
                    passenger = &p;
                    break;
                }
            }

            if (passenger) {
                Security security;
                security.scanPassenger(*passenger);
                std::cout << "Проверка безопасности завершена для " << passenger->name << ".\n";
            }
            else {
                std::cout << "Пассажир не найден.\n";
            }
            break;
        }
        case 7: {
            // Выполнить техническое обслуживание самолета
            if (aircrafts.empty()) {
                std::cout << "Сначала создайте самолеты.\n";
                break;
            }

            std::string registrationNumber;
            std::cout << "Введите номер регистрации самолета для обслуживания: ";
            std::cin.ignore();
            std::getline(std::cin, registrationNumber);

            // Находим самолет
            Aircraft* aircraft = nullptr;
            for (auto& a : aircrafts) {
                if (a.registrationNumber == registrationNumber) {
                    aircraft = &a;
                    break;
                }
            }

            if (aircraft) {
                Maintenance maintenance;
                maintenance.performMaintenance(*aircraft);
                std::cout << "Техническое обслуживание завершено для самолета " << aircraft->registrationNumber << ".\n";
            }
            else {
                std::cout << "Самолет не найден.\n";
            }
            break;
        }
        case 8: {
            // Добавить багаж
            if (passengers.empty()) {
                std::cout << "Сначала создайте пассажиров.\n";
                break;
            }

            std::string passengerPassport;
            int weight, numberOfPieces;

            std::cout << "Введите номер паспорта пассажира: ";
            std::cin.ignore();
            std::getline(std::cin, passengerPassport);
            std::cout << "Введите вес багажа: ";
            std::cin >> weight;
            std::cout << "Введите количество мест багажа: ";
            std::cin >> numberOfPieces;

            // Находим пассажира
            Passenger* passenger = nullptr;
            for (auto& p : passengers) {
                if (p.passportNumber == passengerPassport) {
                    passenger = &p;
                    break;
                }
            }

            if (passenger) {
                Baggage baggage(weight, numberOfPieces);
                std::cout << "Багаж добавлен для " << passenger->name << ".\n";
            }
            else {
                std::cout << "Пассажир не найден.\n";
            }
            break;
        }
        case 9: {
            // Показать расписание рейсов
            std::cout << "Расписание рейсов:\n";
            for (const auto& flight : flightSchedule.flights) {
                std::cout << "Рейс: " << flight.flightNumber
                    << ", Пункт отправления: " << flight.origin
                    << ", Пункт назначения: " << flight.destination
                    << ", Время отправления: " << flight.departureTime
                    << ", Время прибытия: " << flight.arrivalTime
                    << ", Емкость: " << flight.capacity << std::endl;
            }
            break;
        }
        case 10:
            std::cout << "Выход из программы.\n";
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова.\n";
        }

        std::cout << std::endl;

    } while (choice != 10);

    return 0;
}