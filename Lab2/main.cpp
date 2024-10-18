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
    std::cout << "�������� �������:\n";
    std::cout << "1. ������� ���������\n";
    std::cout << "2. ������� ������������\n";
    std::cout << "3. ������� �������\n";
    std::cout << "4. ������� ����\n";
    std::cout << "5. ������������� �����\n";
    std::cout << "6. ��������� ������������ ���������\n";
    std::cout << "7. ��������� ����������� ������������ ��������\n";
    std::cout << "8. �������� �����\n";
    std::cout << "9. �������� ���������� ������\n";
    std::cout << "10. �����\n";
}

int main() {
    // ���������� ��� �������� ������
    std::vector<Passenger> passengers;
    std::vector<Flight> flights;
    std::vector<Aircraft> aircrafts;
    Airline airline("Airline One");
    ReservationSystem reservationSystem;
    FlightSchedule flightSchedule;
    int choice;

    do {
        displayMenu();
        std::cout << "��� �����: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            // ������� ���������
            std::string name, passportNumber;
            int age;

            std::cout << "������� ��� ���������: ";
            std::cin.ignore(); // ���������� ������� ������
            std::getline(std::cin, name);
            std::cout << "������� ����� ��������: ";
            std::getline(std::cin, passportNumber);
            std::cout << "������� �������: ";
            std::cin >> age;

            passengers.emplace_back(name, passportNumber, age);
            std::cout << "�������� " << name << " ������.\n";
            break;
        }
        case 2: {
            // ������� ������������
            std::string airlineName;
            std::cout << "������� �������� ������������: ";
            std::cin.ignore();
            std::getline(std::cin, airlineName);
            airline = Airline(airlineName);
            std::cout << "������������ " << airlineName << " �������.\n";
            break;
        }
        case 3: {
            // ������� �������
            std::string model, registrationNumber;
            int capacity;

            std::cout << "������� ������ ��������: ";
            std::cin.ignore();
            std::getline(std::cin, model);
            std::cout << "������� ����� �����������: ";
            std::getline(std::cin, registrationNumber);
            std::cout << "������� ������� ��������: ";
            std::cin >> capacity;

            Aircraft aircraft(model, capacity, registrationNumber);
            airline.addAircraft(aircraft);
            aircrafts.push_back(aircraft);
            std::cout << "������� " << model << " ������.\n";
            break;
        }
        case 4: {
            // ������� ����
            std::string flightNumber, origin, destination, departureTime, arrivalTime;
            int capacity;

            std::cout << "������� ����� �����: ";
            std::cin.ignore();
            std::getline(std::cin, flightNumber);
            std::cout << "������� ����� �����������: ";
            std::getline(std::cin, origin);
            std::cout << "������� ����� ����������: ";
            std::getline(std::cin, destination);
            std::cout << "������� ����� �����������: ";
            std::getline(std::cin, departureTime);
            std::cout << "������� ����� ��������: ";
            std::getline(std::cin, arrivalTime);
            std::cout << "������� ������� �����: ";
            std::cin >> capacity;

            Flight flight(flightNumber, origin, destination, departureTime, arrivalTime, capacity);
            flights.push_back(flight);
            flightSchedule.addFlight(flight);
            std::cout << "���� " << flightNumber << " ������.\n";
            break;
        }
        case 5: {
            // ������������� �����
            if (passengers.empty() || flights.empty()) {
                std::cout << "������� �������� ���������� � �����.\n";
                break;
            }

            int ticketID;
            double price;
            std::string flightNumber;

            std::cout << "������� ID ������: ";
            std::cin >> ticketID;
            std::cout << "������� ���� ������: ";
            std::cin >> price;
            std::cout << "������� ����� �����: ";
            std::cin.ignore();
            std::getline(std::cin, flightNumber);

            // ������� ���������
            Passenger* passenger = nullptr;
            for (auto& p : passengers) {
                if (p.passportNumber == flightNumber) { // ���������� ����� �������� ��� ������
                    passenger = &p;
                    break;
                }
            }

            if (passenger) {
                Ticket ticket(ticketID, price, flightNumber, *passenger);
                reservationSystem.bookTicket(ticket);
                std::cout << "����� ������������ ��� " << passenger->name << ".\n";
            }
            else {
                std::cout << "�������� �� ������.\n";
            }
            break;
        }
        case 6: {
            // ��������� ������������ ���������
            if (passengers.empty()) {
                std::cout << "������� �������� ����������.\n";
                break;
            }

            std::string passportNumber;
            std::cout << "������� ����� �������� ��������� ��� ��������: ";
            std::cin.ignore();
            std::getline(std::cin, passportNumber);

            // ������� ���������
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
                std::cout << "�������� ������������ ��������� ��� " << passenger->name << ".\n";
            }
            else {
                std::cout << "�������� �� ������.\n";
            }
            break;
        }
        case 7: {
            // ��������� ����������� ������������ ��������
            if (aircrafts.empty()) {
                std::cout << "������� �������� ��������.\n";
                break;
            }

            std::string registrationNumber;
            std::cout << "������� ����� ����������� �������� ��� ������������: ";
            std::cin.ignore();
            std::getline(std::cin, registrationNumber);

            // ������� �������
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
                std::cout << "����������� ������������ ��������� ��� �������� " << aircraft->registrationNumber << ".\n";
            }
            else {
                std::cout << "������� �� ������.\n";
            }
            break;
        }
        case 8: {
            // �������� �����
            if (passengers.empty()) {
                std::cout << "������� �������� ����������.\n";
                break;
            }

            std::string passengerPassport;
            int weight, numberOfPieces;

            std::cout << "������� ����� �������� ���������: ";
            std::cin.ignore();
            std::getline(std::cin, passengerPassport);
            std::cout << "������� ��� ������: ";
            std::cin >> weight;
            std::cout << "������� ���������� ���� ������: ";
            std::cin >> numberOfPieces;

            // ������� ���������
            Passenger* passenger = nullptr;
            for (auto& p : passengers) {
                if (p.passportNumber == passengerPassport) {
                    passenger = &p;
                    break;
                }
            }

            if (passenger) {
                Baggage baggage(weight, numberOfPieces);
                std::cout << "����� �������� ��� " << passenger->name << ".\n";
            }
            else {
                std::cout << "�������� �� ������.\n";
            }
            break;
        }
        case 9: {
            // �������� ���������� ������
            std::cout << "���������� ������:\n";
            for (const auto& flight : flightSchedule.flights) {
                std::cout << "����: " << flight.flightNumber
                    << ", ����� �����������: " << flight.origin
                    << ", ����� ����������: " << flight.destination
                    << ", ����� �����������: " << flight.departureTime
                    << ", ����� ��������: " << flight.arrivalTime
                    << ", �������: " << flight.capacity << std::endl;
            }
            break;
        }
        case 10:
            std::cout << "����� �� ���������.\n";
            break;
        default:
            std::cout << "�������� �����. ���������� �����.\n";
        }

        std::cout << std::endl;

    } while (choice != 10);

    return 0;
}