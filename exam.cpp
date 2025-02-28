#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Question
{
public:
    string questionText;
    string option1, option2, option3, option4;
    int correctOption;

    Question(string q, string o1, string o2, string o3, string o4, int correct)
        : questionText(q), option1(o1), option2(o2), option3(o3), option4(o4), correctOption(correct) {}

    void display()
    {
        cout << questionText << endl;
        cout << "1. " << option1 << endl;
        cout << "2. " << option2 << endl;
        cout << "3. " << option3 << endl;
        cout << "4. " << option4 << endl;
    }

    bool isCorrect(int userAnswer)
    {
        return userAnswer == correctOption;
    }
};

class Exam
{
private:
    vector<Question> questions;
    int correctAnswers = 0;
    int wrongAnswers = 0;
    const int PASS_MARKS = 8;

public:
    void addQuestion()
    {
        string q, o1, o2, o3, o4;
        int correctOption;

        cout << "Enter the question: ";
        cin.ignore();
        getline(cin, q);

        cout << "Enter option 1: ";
        getline(cin, o1);
        cout << "Enter option 2: ";
        getline(cin, o2);
        cout << "Enter option 3: ";
        getline(cin, o3);
        cout << "Enter option 4: ";
        getline(cin, o4);

        cout << "Enter the correct option (1-4): ";
        cin >> correctOption;

        questions.push_back(Question(q, o1, o2, o3, o4, correctOption));
        cout << "Question added successfully!\n";
    }

    void addPredefinedQuestions()
    {
        questions.push_back(Question("What is the size of an int in C++?", "2 bytes", "4 bytes", "8 bytes", "16 bytes", 2));
        questions.push_back(Question("Which keyword is used to define a constant in C++?", "#define", "const", "final", "constant", 2));
        questions.push_back(Question("How do you declare a pointer in C++?", "int ptr;", "ptr int;", "int* ptr;", "ptr* int;", 3));
        questions.push_back(Question("Default value of a static variable in C++?", "1", "0", "null", "undefined", 2));
        questions.push_back(Question("Which keyword is used for dynamic memory allocation?", "malloc()", "calloc()", "new", "allocate()", 3));
        questions.push_back(Question("Which function is used to read input from the user?", "print()", "input()", "cin", "cout", 3));
        questions.push_back(Question("Which of these is not a valid data type in C++?", "int", "float", "real", "char", 3));
        questions.push_back(Question("What does OOP stand for?", "Object Oriented Programming", "Order of Processing", "Online Object Protocol", "Optimal Object Processing", 1));
        questions.push_back(Question("Which of these is not a C++ access specifier?", "public", "private", "protected", "extern", 4));
        questions.push_back(Question("Which operator is used to allocate memory dynamically in C++?", "malloc", "alloc", "new", "create", 3));
    }

    void startExam()
    {
        if (questions.empty())
        {
            cout << "No questions available!\n";
            return;
        }

        correctAnswers = wrongAnswers = 0;

        for (int i = 0; i < questions.size(); ++i)
        {
            cout << "\nQuestion " << i + 1 << ":\n";
            questions[i].display();

            int userAnswer;
            cout << "Enter your answer (1-4): ";
            cin >> userAnswer;

            if (questions[i].isCorrect(userAnswer))
            {
                cout << "\033[1;32mCorrect!\033[0m\n";
                correctAnswers++;
            }
            else
            {
                cout << "\033[1;31mWrong!\033[0m\n";
                wrongAnswers++;
            }
        }

        cout << "\nExam Completed!\n";
        cout << "Correct Answers: " << correctAnswers << "\n";
        cout << "Wrong Answers: " << wrongAnswers << "\n";

        if (correctAnswers >= PASS_MARKS)
        {
            cout << "\033[1;32mCongratulations! You Passed the Exam! \033[0m\n";
        }
        else
        {
            cout << "\033[1;31mYou Failed the Exam. Better Luck Next Time. \033[0m\n";
        }
    }

    void exitExam()
    {
        cout << "Exiting the exam system. Goodbye!\n";
    }
};

int main()
{
    Exam exam;
    int choice;

    exam.addPredefinedQuestions();

    while (true)
    {
        cout << "\nExam System Menu:\n";
        cout << "1. Add a question\n";
        cout << "2. Start the exam\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            exam.addQuestion();
            break;
        case 2:
            exam.startExam();
            break;
        case 0:
            exam.exitExam();
            return 0;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    }

    return 0;
}
