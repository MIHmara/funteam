#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

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
    int totalScore;
};

int getValidInteger(int min, int max) {
    int input;
    while (!(cin >> input) || input < min || input > max) {
        cout << "Invalid! Please enter a number (" << min << "-" << max << "): ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cin.ignore(1000, '\n');
    return input;
}

void shuffleQuestions(vector<Question>& bank) {
    for (int i = 0; i < bank.size(); i++) {
        int swapIndex = rand() % bank.size();
        swap(bank[i], bank[swapIndex]);
    }
}

double calculateGrade(int score, int maxPossible) {
    double grade = ((double)score / (double)maxPossible) * 4.0 + 2.0;
    return (grade > 6.0) ? 6.0 : grade;
}


void loadAncient(vector<Question>& b) {
    b = {
        {"Who built the Great Pyramid of Giza?", "Egyptians", "Romans", "Greeks", 'A', 1, 1},
        {"First Emperor of Rome?", "Julius Caesar", "Augustus", "Nero", 'B', 1, 1},
        {"Ancient writing system of Sumerians?", "Hieroglyphs", "Cuneiform", "Alphabet", 'B', 1, 1},
        {"Which city-state introduced democracy?", "Sparta", "Athens", "Troy", 'B', 1, 1},
        {"What river was ancient Egypt built around?", "Tigris", "Nile", "Euphrates", 'B', 1, 1},
        {"Famous conqueror from Macedonia?", "Alexander", "Hannibal", "Leonidas", 'A', 1, 1},
        {"Roman city destroyed by a volcano?", "Rome", "Pompeii", "Carthage", 'B', 1, 1},
        {"Ancient trade route to China?", "Spice Route", "Silk Road", "Amber Road", 'B', 1, 1},
        {"War between Athens and Sparta?", "Punic", "Peloponnesian", "Persian", 'B', 1, 1},
        {"Mythical founder of Rome?", "Romulus", "Remus", "Aeneas", 'A', 1, 1}
    };
}

void loadMedieval(vector<Question>& b) {
    b = {
        {"Disease that devastated 14th-century Europe?", "Cholera", "Black Death", "Smallpox", 'B', 2, 2},
        {"Document King John signed in 1215?", "Magna Carta", "Bill of Rights", "Constitution", 'A', 2, 2},
        {"Who was the first Holy Roman Emperor?", "Charlemagne", "Otto I", "Clovis", 'A', 2, 2},
        {"War between England & France (1337-1453)?", "Thirty Years'", "Hundred Years'", "Rose War", 'B', 2, 2},
        {"Period of cultural rebirth starting in Italy?", "Enlightenment", "Renaissance", "Reformation", 'B', 2, 2},
        {"Empire that captured Constantinople in 1453?", "Roman", "Mongol", "Ottoman", 'C', 2, 2},
        {"Scandinavian seafaring raiders?", "Vikings", "Celts", "Franks", 'A', 2, 2},
        {"Famous peasant girl who led the French army?", "Eleanor", "Joan of Arc", "Marie Antoinette", 'B', 2, 2},
        {"System of land ownership and duties?", "Capitalism", "Feudalism", "Communism", 'B', 2, 2},
        {"Religious wars to control the Holy Land?", "Crusades", "Inquisitions", "Reconquista", 'A', 2, 2}
    };
}

void loadModern(vector<Question>& b) {
    b = {
        {"Year World War I began?", "1912", "1914", "1918", 'B', 3, 3},
        {"Inventor of the practical telephone?", "Edison", "Bell", "Tesla", 'B', 3, 3},
        {"First person in space?", "Armstrong", "Gagarin", "Glenn", 'B', 3, 3},
        {"Famous ship that sank in 1912?", "Lusitania", "Titanic", "Bismarck", 'B', 3, 3},
        {"Global conflict that ended in 1945?", "WWI", "WWII", "Cold War", 'B', 3, 3},
        {"Author of the US Declaration of Independence?", "Washington", "Jefferson", "Lincoln", 'B', 3, 3},
        {"Fall of this wall in 1989 reunited Germany?", "Berlin", "Munich", "Iron", 'A', 3, 3},
        {"French general who became Emperor in 1804?", "Lafayette", "Napoleon", "Robespierre", 'B', 3, 3},
        {"US President during the Civil War?", "Washington", "Lincoln", "Roosevelt", 'B', 3, 3},
        {"Global conflict of ideologies after WWII?", "Cold War", "Gulf War", "Korean War", 'A', 3, 3}
    };
}


void showLesson() {
    cout << "\n--- WORLD HISTORY LESSON ---\n";
    cout << "* Ancient: Empires grew around rivers like the Nile.\n";
    cout << "* Medieval: Feudalism and the Renaissance shaped Europe.\n";
    cout << "* Modern: The 20th century saw two World Wars and Space flight.\n";
}

void conductExam(vector<Question>& q1, vector<Question>& q2, vector<Question>& q3, vector<Student>& records) {
    Student s;
    cout << "\nEnter Full Name: ";
    getline(cin, s.name);

    shuffleQuestions(q1); shuffleQuestions(q2); shuffleQuestions(q3);

    vector<Question> exam;
    for(int i = 0; i < 7; i++) exam.push_back(q1[i]);
    for(int i = 0; i < 7; i++) exam.push_back(q2[i]);
    for(int i = 0; i < 6; i++) exam.push_back(q3[i]);

    int score = 0;
    for (int i = 0; i < exam.size(); i++) {
        cout << "\nQ" << (i + 1) << ": " << exam[i].text << endl;
        cout << "A) " << exam[i].optionA << " B) " << exam[i].optionB << " C) " << exam[i].optionC << endl;
        cout << "Answer: ";
        char ans; cin >> ans;
        if (toupper(ans) == exam[i].correctAnswer) score += exam[i].points;
    }

    s.totalScore = score;
    s.finalGrade = calculateGrade(score, 39);
    records.push_back(s);
    
    cout << "\n>> " << s.name << ", your Grade is: " << s.finalGrade << " (" << score << "/39 pts)\n";
}

void showStats(const vector<Student>& records) {
    if (records.empty()) {
        cout << "\n[!] No data found.\n";
        return;
    }
    double sum = 0, bestG = 0, worstG = 7.0;
    string bestN, worstN;
    for (auto const& s : records) {
        sum += s.finalGrade;
        if (s.finalGrade > bestG) { bestG = s.finalGrade; bestN = s.name; }
        if (s.finalGrade < worstG) { worstG = s.finalGrade; worstN = s.name; }
    }
    cout << "\n--- STATISTICS ---\n"
         << "Average: " << sum / records.size() << "\n"
         << "Best: " << bestG << " (" << bestN << ")\n"
         << "Worst: " << worstG << " (" << worstN << ")\n";
}


int main() {
    srand(time(0));
    vector<Student> records;
    vector<Question> ancient, medieval, modern;
    
    loadAncient(ancient); 
    loadMedieval(medieval); 
    loadModern(modern);

    int choice = 0;
    while (choice != 5) {
        cout << "\n1.Lesson 2.Practice 3.Exam 4.Stats 5.Exit\nChoice: ";
        choice = getValidInteger(1, 5);

        if (choice == 1) showLesson();
        else if (choice == 2) cout << "\nPractice mode coming soon...\n";
        else if (choice == 3) conductExam(ancient, medieval, modern, records);
        else if (choice == 4) showStats(records);
    }
    cout << "Goodbye!\n";
    return 0;
}
