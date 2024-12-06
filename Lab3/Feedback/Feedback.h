#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <string>
#include "Patient.h"

class Feedback {
public:
    Feedback(const Patient& patient, int rating, const std::string& comments);
    void submitFeedback();

private:
    Patient patient;
    int rating;
    std::string comments;
};

#endif // FEEDBACK_H