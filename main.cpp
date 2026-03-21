#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

struct Question {
    string text;
    string a, b, c;
    char correct;
    int cat;
    int pts;
};

struct Student {
    string name;
    double grade;
    int total;
    int cat1, cat2, cat3;
};

int getInt(int min, int max) {
    int x;
    while (true) {
                if (cin >> x && x >= min && x <= max) {
            cin.ignore(1000, '\n');
            return x;
        } else {
            cout << "Invalid input! Enter number (" << min << "-" << max << "): ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
}
void shuffleQs(vector<Question>& q) {
    for (int i = 0; i < q.size(); i++) {
        int r = rand() % q.size();
        swap(q[i], q[r]);
    }
}

void showMenu() {
    cout << "\n=============================================\n";
    cout << "      E-SCHOOL: GEOGRAPHY OF EUROPE\n";
    cout << "=============================================\n";
    cout << "1. Read Lesson\n";
    cout << "2. Practice\n";
    cout << "2. Practice\n";
    cout << "3. Take Exam\n";
    cout << "4. Statistics\n";
    cout << "5. Exit\n";
    cout << "=============================================\n";
    cout << "Choose (1-5): ";
}

void showLesson() {
    cout << "\n--- LESSON: EUROPE AT A GLANCE ---\n";
    cout << "Largest country: Russia. Smallest: Vatican City.\n";
    cout << "Longest river: Volga. Highest peak: Elbrus.\n";
    cout << "Europe is the 2nd smallest continent but 3rd in population.\n";
    cout << "EU has 27 member states.\n";
}

void startExam(vector<Question>& q1, vector<Question>& q2, vector<Question>& q3, vector<Student>& list) {
    Student s;
    cout << "\nEnter your full name: ";
    cin.ignore();
    getline(cin, s.name);
    s.total = s.cat1 = s.cat2 = s.cat3 = 0;
    shuffleQs(q1);
    shuffleQs(q2);
    shuffleQs(q3);
    vector<Question> exam;
    for (int i = 0; i < 7; i++) exam.push_back(q1[i]);
    for (int i = 0; i < 7; i++) exam.push_back(q2[i]);
    for (int i = 0; i < 6; i++) exam.push_back(q3[i]);
    for (int i = 0; i < exam.size(); i++) {
        cout << "\nQ" << (i + 1) << ": " << exam[i].text << endl;
        cout << "A) " << exam[i].a << "  B) " << exam[i].b << "  C) " << exam[i].c << endl;
        
        char ans;
        cout << "Your Answer (A/B/C): ";
        cin >> ans;
        ans = toupper(ans);
            if (ans == exam[i].correct) {
            s.total += exam[i].pts;
            if (exam[i].cat == 1) s.cat1 += exam[i].pts;
            else if (exam[i].cat == 2) s.cat2 += exam[i].pts;
            else if (exam[i].cat == 3) s.cat3 += exam[i].pts;
        }
    }
    s.grade = ((double)s.total / 39.0) * 4.0 + 2.0;
    if (s.grade > 6.0) s.grade = 6.0;

    cout << "\n--- EXAM FINISHED ---\n";
    cout << "Name: " << s.name
         << " | Score: " << s.total << "/39"
         << " | Grade: " << s.grade << endl;

    list.push_back(s);
}
void showStats(const vector<Student>& list) {
    if (list.empty()) {
        cout << "\n[!] No exam data available.\n";
        return;
    }

    double sum = 0;
    double maxG = 0;
    double minG = 7.0;
    string best, worst;

    for (const auto& s : list) {
        sum += s.grade;
        if (s.grade > maxG) { maxG = s.grade; best = s.name; }
        if (s.grade < minG) { minG = s.grade; worst = s.name; }
    }