#include "pch.h"
#include "gtest/gtest.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 3\PPOISLab3\Feedback.h"

class FeedbackTest : public ::testing::Test {
protected:
    Patient patient;
    Feedback feedback;

    FeedbackTest() : patient("Jane Doe", 28), feedback(patient, 5, "Excellent service!") {}
};

TEST_F(FeedbackTest, SubmitFeedback) {
    testing::internal::CaptureStdout();
    feedback.submitFeedback();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_NE(output.find("Feedback submitted by Jane Doe: Rating = 5, Comments: Excellent service!"), std::string::npos);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
