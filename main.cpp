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
    // КАТЕГОРИЯ 1: Столици (10 въпроса)
    vector<Question> b1 = {
        {"Capital of France?", "London", "Paris", "Berlin", 'B', 1, 1},
        {"Capital of Italy?", "Rome", "Madrid", "Athens", 'A', 1, 1},
        {"Capital of Spain?", "Lisbon", "Madrid", "Rome", 'B', 1, 1},
        {"Capital of Germany?", "Vienna", "Munich", "Berlin", 'C', 1, 1},
        {"Capital of UK?", "London", "Dublin", "Cardiff", 'A', 1, 1},
        {"Capital of Greece?", "Sofia", "Athens", "Ankara", 'B', 1, 1},
        {"Capital of Bulgaria?", "Sofia", "Bucharest", "Belgrade", 'A', 1, 1},
        {"Capital of Austria?", "Vienna", "Prague", "Budapest", 'A', 1, 1},
        {"Capital of Poland?", "Warsaw", "Kiev", "Minsk", 'A', 1, 1},
        {"Capital of Sweden?", "Oslo", "Helsinki", "Stockholm", 'C', 1, 1}
    };

    // КАТЕГОРИЯ 2: Природа (10 въпроса)
    vector<Question> b2 = {
        {"Longest river in Europe?", "Danube", "Volga", "Rhine", 'B', 2, 2},
        {"Where are the Alps?", "Central Europe", "North", "East", 'A', 2, 2},
        {"Highest peak in Europe?", "Mont Blanc", "Elbrus", "Matterhorn", 'B', 2, 2},
        {"Sea south of Europe?", "Baltic", "North Sea", "Mediterranean", 'C', 2, 2},
        {"River in Paris?", "Seine", "Thames", "Rhone", 'A', 2, 2},
        {"Mountains between Europe and Asia?", "Alps", "Ural", "Carpathians", 'B', 2, 2},
        {"Largest island in Europe?", "Iceland", "Ireland", "Great Britain", 'C', 2, 2},
        {"Country with most lakes?", "Finland", "Norway", "Sweden", 'A', 2, 2},
        {"Where is Black Forest?", "France", "Germany", "Austria", 'B', 2, 2},
        {"Ocean west of Europe?", "Pacific", "Indian", "Atlantic", 'C', 2, 2}
    };

    // КАТЕГОРИЯ 3: Икономика и Население (10 въпроса)
    vector<Question> b3 = {
        {"Largest population in Europe?", "Germany", "Russia", "France", 'B', 3, 3},
        {"EU Headquarters?", "Brussels", "Strasbourg", "Geneva", 'A', 3, 3},
        {"Smallest country?", "Monaco", "San Marino", "Vatican", 'C', 3, 3},
        {"Currency of most EU countries?", "Pound", "Euro", "Franc", 'B', 3, 3},
        {"NOT in the EU?", "Spain", "Italy", "Switzerland", 'C', 3, 3},
        {"Largest economy?", "UK", "Germany", "France", 'B', 3, 3},
        {"Country known for fjords?", "Norway", "Denmark", "Sweden", 'A', 3, 3},
        {"Known as 'Low Countries'?", "Benelux", "Scandinavia", "Balkans", 'A', 3, 3},
        {"Produces most wine?", "Spain", "Italy", "Germany", 'B', 3, 3},
        {"European Central Bank location?", "Frankfurt", "Paris", "London", 'A', 3, 3}
    };
}