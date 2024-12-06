#include <iostream>
#include <vector>
#include "Hospital.h"
#include "Department.h"
#include "Staff.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Patient.h"
#include "Appointment.h"
#include "Billing.h"
#include "MedicalRecord.h"
#include "Treatment.h"
#include "Medication.h"
#include "Feedback.h"
#include "Insurance.h"
#include "Emergency.h"
#include "Visitor.h"

void displayMenu() {
    std::cout << "\n--- Hospital Management System ---\n";
    std::cout << "1. Add Patient\n";
    std::cout << "2. Add Doctor\n";
    std::cout << "3. Schedule Appointment\n";
    std::cout << "4. Update Medical History\n";
    std::cout << "5. Generate Invoice\n";
    std::cout << "6. Submit Feedback\n";
    std::cout << "7. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    Hospital hospital("City Hospital", "123 Main St", "555-1234");
    std::vector<Patient> patients;
    std::vector<Doctor> doctors;

    int choice;
    while (true) {
        displayMenu();
        std::cin >> choice;

        if (choice == 1) {
            std::string name;
            int age;
            std::cout << "Enter patient name: ";
            std::cin >> name;
            std::cout << "Enter patient age: ";
            std::cin >> age;
            patients.emplace_back(name, age);
            std::cout << "Patient " << name << " added.\n";

        }
        else if (choice == 2) {
            std::string name, role, phone, specialty;
            std::cout << "Enter doctor name: ";
            std::cin >> name;
            std::cout << "Enter doctor role: ";
            std::cin >> role;
            std::cout << "Enter doctor phone: ";
            std::cin >> phone;
            std::cout << "Enter doctor's specialty: ";
            std::cin >> specialty;
            doctors.emplace_back(name, role, phone, specialty);
            std::cout << "Doctor " << name << " added.\n";

        }
        else if (choice == 3) {
            std::string patientName, doctorName, date, time;
            std::cout << "Enter patient name: ";
            std::cin >> patientName;
            std::cout << "Enter doctor name: ";
            std::cin >> doctorName;
            std::cout << "Enter appointment date (YYYY-MM-DD): ";
            std::cin >> date;
            std::cout << "Enter appointment time (HH:MM): ";
            std::cin >> time;

            auto patientIt = std::find_if(patients.begin(), patients.end(),
                [&patientName](const Patient& p) { return p.getName() == patientName; });

            auto doctorIt = std::find_if(doctors.begin(), doctors.end(),
                [&doctorName](const Doctor& d) { return d.getName() == doctorName; });

            if (patientIt != patients.end() && doctorIt != doctors.end()) {
                Appointment appointment(*patientIt, *doctorIt, date, time);
                std::cout << "Appointment scheduled for " << patientName << " with " << doctorName << " on " << date << " at " << time << ".\n";
            }
            else {
                std::cout << "Patient or doctor not found.\n";
            }

        }
        else if (choice == 4) {
            std::string patientName, history;
            std::cout << "Enter patient name: ";
            std::cin >> patientName;
            std::cout << "Enter medical history update: ";
            std::cin >> history;

            auto patientIt = std::find_if(patients.begin(), patients.end(),
                [&patientName](const Patient& p) { return p.getName() == patientName; });

            if (patientIt != patients.end()) {
                patientIt->updateMedicalHistory(history);
            }
            else {
                std::cout << "Patient not found.\n";
            }

        }
        else if (choice == 5) {
            std::string patientName;
            double amount;
            std::cout << "Enter patient name: ";
            std::cin >> patientName;
            std::cout << "Enter amount: ";
            std::cin >> amount;

            auto patientIt = std::find_if(patients.begin(), patients.end(),
                [&patientName](const Patient& p) { return p.getName() == patientName; });

            if (patientIt != patients.end()) {
                Billing billing(*patientIt, amount);
                billing.generateInvoice();
            }
            else {
                std::cout << "Patient not found.\n";
            }

        }
        else if (choice == 6) {
            std::string patientName, comments;
            int rating;
            std::cout << "Enter patient name: ";
            std::cin >> patientName;
            std::cout << "Enter rating (1-5): ";
            std::cin >> rating;
            std::cout << "Enter comments: ";
            std::cin >> comments;

            auto patientIt = std::find_if(patients.begin(), patients.end(),
                [&patientName](const Patient& p) { return p.getName() == patientName; });

            if (patientIt != patients.end()) {
                Feedback feedback(*patientIt, rating, comments);
                feedback.submitFeedback();
            }
            else {
                std::cout << "Patient not found.\n";
            }

        }
        else if (choice == 7) {
            std::cout << "Exiting...\n";
            break;

        }
        else {
            std::cout << "Invalid option, please try again.\n";
        }
    }
    return 0;
}