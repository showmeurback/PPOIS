#include "Feedback.h"
#include <iostream>

Feedback::Feedback(const Patient& patient, int rating, const std::string& comments)
    : patient(patient), rating(rating), comments(comments) {
}

void Feedback::submitFeedback() {
    std::cout << "Feedback submitted by " << patient.getName() << ": Rating = " << rating << ", Comments: " << comments << "\n";
}