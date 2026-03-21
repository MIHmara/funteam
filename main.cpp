#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// СТРУКТУРИ
struct Question {
    string text;
    string optionA, optionB, optionC;
    char correctAnswer;
    int category;
    int points;
};

struct Student {
    string name;
    double finalGrade;
    int totalPoints;
    int pointsCat1, pointsCat2, pointsCat3;
};

// ВАЛИДАЦИЯ - Защита от грешен вход
int getSafeInt(int min, int max) {
    int input;
    while (true) {
        if (cin >> input && input >= min && input <= max) return input;
        cout << "Invalid input! Enter number (" << min << "-" << max << "): ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

void shuffleQuestions(vector<Question>& qList) {
    for (int i = 0; i < qList.size(); i++) {
        swap(qList[i], qList[rand() % qList.size()]);
    }
}

// ИНТЕРФЕЙС
void showMenu() {
    cout << "\n1. Lesson\n2. Practice\n3. EXAM\n4. Stats\n5. Exit\nChoice: ";
}

int main() {
    srand(time(0));
    vector<Student> students;
    
    // БАНКА С ВЪПРОСИ (Начална версия)
    vector<Question> b1 = {{"Capital of France?", "London", "Paris", "Berlin", 'B', 1, 1}};
    vector<Question> b2 = {{"Longest river in Europe?", "Danube", "Volga", "Rhine", 'B', 2, 2}};
    vector<Question> b3 = {{"Smallest country in Europe?", "Monaco", "Malta", "Vatican", 'C', 3, 3}};

    int choice;
    do {
        showMenu();
        choice = getSafeInt(1, 5);
        if (choice == 3) cout << "Exam logic ready. Need more questions...\n";
    } while (choice != 5);

    return 0;
}