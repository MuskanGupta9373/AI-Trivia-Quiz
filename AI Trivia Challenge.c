#include <stdio.h>
#include <time.h>

#define QUESTIONS 3

struct Question {
    char question_text[250];
    char choices[4][100];
    char correct_answer;
};

int main() {
    struct Question quiz[QUESTIONS] = {
        {
            "In the field of computer science, what does 'AI' stand for?",
            {"A. Automated Interface", "B. Artificial Intelligence", "C. Algorithmic Integration", "D. Advanced Internet"},
            'B'
        },
        {
            "Which of these is widely used as a machine learning algorithm?",
            {"A. Linear Regression", "B. Binary Search", "C. Depth-First Search", "D. Quick Sort"},
            'A'
        },
        {
            "When developing AI systems, what is the process called where the model learns from data?",
            {"A. Programming", "B. Testing", "C. Learning", "D. Deployment"},
            'C'
        }
    };

    int score = 0;
    char user_response;
    time_t start, end;

    printf("Welcome to the AI Basics Quiz!\n");
    printf("You'll be asked %d questions related to Artificial Intelligence.\n", QUESTIONS);
    printf("Simply type the letter (A, B, C, or D) corresponding to your answer.\n\n");

    start = time(NULL);

    for (int i = 0; i < QUESTIONS; i++) {
        printf("Question %d:\n%s\n", i + 1, quiz[i].question_text);
        for (int j = 0; j < 4; j++) {
            printf("  %s\n", quiz[i].choices[j]);
        }

        printf("Your answer: ");
        scanf(" %c", &user_response);

        // Normalize to uppercase
        if (user_response >= 'a' && user_response <= 'z') {
            user_response -= 32;
        }

        if (user_response == quiz[i].correct_answer) {
            printf("Nice! That's the correct answer.\n\n");
            score++;
        } else {
            printf("Oops! The right answer was '%c'. Don't worry, keep learning!\n\n", quiz[i].correct_answer);
        }
    }

    end = time(NULL);
    double total_time = difftime(end, start);

    printf("You made it to the end! Your final score is %d out of %d.\n", score, QUESTIONS);
    printf("And you completed this quiz in %.0f seconds. Great effort!\n", total_time);
    printf("Keep practicing and you'll master AI concepts in no time!\n");

    return 0;
}
