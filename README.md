# funteam
# 🌍 E-School: Geography of Europe
**Project for 9th Grade Project Activities | PGKPPI Burgas (2025/2026)**

## 📝 Project Description
The program allows users to read a short lesson, practice, take an exam, and view statistics based on previous exam attempts.
Users can read a short lesson, practice (feature placeholder), take a fully automated exam, and view detailed statistics about all completed attempts.
The exam pulls questions from three difficulty categories, shuffles them, calculates a final grade on a 2.00–6.00 scale, and stores each student's results.

## 👥 The Team
<ol>
<li>*Ангел Пиерре Андре Фриедириш* — **Scrum Trainer**</li>
<li>*Никита Сергеевич Кощеев* — **Backend Developer**</li>
<li>*Александър Ивайлов Петров* — **FrontEnd Developer**</li>
<li>*Мирослава Ивановна Хмара* — **QA & Documentation**</li>
</ol>
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
