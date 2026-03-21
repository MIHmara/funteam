#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> 
#include <ctime>   

using namespace std;

// --- СТРУКТУРИ --- 
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

// --- ФУНКЦИИ ЗА ВАЛИДАЦИЯ И ОБРАБОТКА ---
int getSafeInt(int min, int max) {
    int input;
    while (true) {
        if (cin >> input && input >= min && input <= max) {
            return input;
        } else {
            cout << "Invalid input! Please enter a number (" << min << "-" << max << "): ";
            cin.clear(); 
            cin.ignore(1000, '\n'); 
        }
    }
}

void shuffleQuestions(vector<Question>& qList) {
    for (int i = 0; i < qList.size(); i++) {
        int randomIndex = rand() % qList.size();
        swap(qList[i], qList[randomIndex]);
    }
}

// --- ФУНКЦИИ ЗА ПОТРЕБИТЕЛСКИ ИНТЕРФЕЙС ---
void showMenu() {
    cout << "\n=============================================" << endl;
    cout << "      E-SCHOOL: GEOGRAPHY OF EUROPE" << endl;
    cout << "=============================================" << endl;
    cout << "1. Read Lesson (Educational Content)" << endl;
    cout << "2. Practice (Ungraded)" << endl;
    cout << "3. TAKE THE EXAM" << endl;
    cout << "4. View Statistics" << endl;
    cout << "5. Exit" << endl;
    cout << "=============================================" << endl;
    cout << "Choose an option (1-5): ";
}

void runLesson() {
    cout << "\n--- LESSON: EUROPE AT A GLANCE ---" << endl;
    cout << "Largest country: Russia. Smallest: Vatican City." << endl;
    cout << "Longest river: Volga. Highest peak: Elbrus." << endl;
    cout << "Europe is the second smallest continent but has the third largest population." << endl;
}

void startExam(vector<Question>& b1, vector<Question>& b2, vector<Question>& b3, vector<Student>& students) {
    Student s;
    cout << "\nEnter your name: ";
    cin >> s.name;

    s.totalPoints = s.pointsCat1 = s.pointsCat2 = s.pointsCat3 = 0;

    shuffleQuestions(b1); shuffleQuestions(b2); shuffleQuestions(b3);

    vector<Question> exam;
    for(int i = 0; i < 7; i++) exam.push_back(b1[i]); 
    for(int i = 0; i < 7; i++) exam.push_back(b2[i]); 
    for(int i = 0; i < 6; i++) exam.push_back(b3[i]); 

    for (int i = 0; i < exam.size(); i++) {
        cout << "\nQ" << (i + 1) << ": " << exam[i].text << endl;
        cout << "A) " << exam[i].optionA << " B) " << exam[i].optionB << " C) " << exam[i].optionC << endl;
        
        char ans;
        cout << "Answer: "; cin >> ans;
        ans = toupper(ans);

        if (ans == exam[i].correctAnswer) {
            s.totalPoints += exam[i].points;
            if (exam[i].category == 1) s.pointsCat1 += exam[i].points;
            else if (exam[i].category == 2) s.pointsCat2 += exam[i].points;
            else if (exam[i].category == 3) s.pointsCat3 += exam[i].points;
        }
    }

    s.finalGrade = ((double)s.totalPoints / 39.0) * 4.0 + 2.0; 
    cout << "\nYour Grade: " << s.finalGrade << endl;
    students.push_back(s);
}

void showStats(const vector<Student>& students) {
    if (students.empty()) { cout << "No stats available yet.\n"; return; }
    double sum = 0;
    for (const auto& s : students) sum += s.finalGrade;
    cout << "\n--- GLOBAL STATISTICS ---" << endl;
    cout << "Average Grade: " << sum / students.size() << endl;
    cout << "Total Students: " << students.size() << endl;
}

// --- ГЛАВНА ФУНКЦИЯ ---
int main() {
    srand(time(0));
    vector<Student> students;

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

    int choice;
    do {
        showMenu();
        choice = getSafeInt(1, 5);
        if (choice == 1) runLesson();
        else if (choice == 2) cout << "Practice mode (Feature coming soon)...\n";
        else if (choice == 3) startExam(b1, b2, b3, students);
        else if (choice == 4) showStats(students);
    } while (choice != 5);

    return 0;
}