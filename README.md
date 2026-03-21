# funteam
# 🌍 E-School: Geography of Europe
**Project for 9th Grade Project Activities | PGKPPI Burgas (2025/2026)**

## 📝 Project Description
[cite_start]This application is an interactive educational tool designed for learning and testing knowledge about European Geography[cite: 15]. [cite_start]It features study materials, practice sessions, and a standardized exam with automated grading[cite: 17].

## 👥 The Team
* [cite_start]**[Your Name]** — **Scrum Trainer**: Team coordinator, GitHub administrator, and Backend Developer[cite: 62, 94].
* [cite_start]**[Teammate 2 Name]** — **Backend Developer**: Logic implementation and data processing[cite: 68, 94].
* [cite_start]**[Teammate 3 Name]** — **FrontEnd Developer**: User interface and menu design[cite: 68, 94].
* [cite_start]**[Teammate 4 Name]** — **QA & Documentation**: Testing, error handling, and Wiki maintenance.

## ⚙️ Features
* [cite_start]**Question Bank:** Over 30 specialized questions divided into categories[cite: 19].
* [cite_start]**Test Generation:** Randomly generates a 20-question exam (7 easy, 7 medium, 6 hard)[cite: 19].
* [cite_start]**Input Validation:** Secure `getSafeInt` function to prevent crashes from invalid keyboard input[cite: 48].
* [cite_start]**Statistics:** Tracks student performance, including average grades and category success rates[cite: 22, 24].

## 📈 Mathematical Model & Combinations
[cite_start]The final grade is calculated using a standard 6-point scale based on a maximum of 39 points[cite: 21]:
**Formula:** `Grade = (TotalPoints / 39.0) * 4 + 2`

### Test Variations
[cite_start]According to the project requirements to calculate the number of possible test variants:
We choose 7 questions from 10 (Category 1), 7 from 10 (Category 2), and 6 from 10 (Category 3).
The number of unique combinations is:
$$C_{10}^{7} \times C_{10}^{7} \times C_{10}^{6} = 120 \times 120 \times 210 = 3,024,000 \text{ variants}$$

## 🛠 Technologies
* [cite_start]**Language:** C++ [cite: 43]
* [cite_start]**Libraries:** STL (vector, string), cstdlib, ctime [cite: 32, 51]
* [cite_start]**Platform:** GitHub for version control and collaboration [cite: 39]

## 🚀 How to Run
1. Clone the repository.
2. Compile `main.cpp` using a C++ compiler (e.g., `g++ main.cpp -o ESchool`).
3. Run the executable file.
