# funteam
# 🌍 E-School: Geography of Europe
**Project for 9th Grade Project Activities | PGKPPI Burgas (2025/2026)**

## 📝 Project Description
The program allows users to read a <b>short lesson, practice, take an exam, and view statistics based on previous exam attempts.</b>
Users can read a short lesson, practice <i>(feature placeholder)</i>, take a fully automated exam, and view detailed statistics about all completed attempts.
The exam pulls questions from three difficulty categories, shuffles them, calculates a final grade on a 2.00–6.00 scale, and stores each student's results.

## 👥 The Team
<ol>
<li><b>Ангел Пиерре Андре Фриедириш — Scrum Trainer</b></li>
<li><b>Никита Сергеевич Кощеев — **Backend Developer</b></li>
<li><b>Александър Ивайлов Петров — FrontEnd Developer</b></li>
<li><b>Мирослава Ивановна Хмара — QA & Documentation</b></li>
</ol>

## ⚙️ Features
* <sup>**Question Bank:** Over 30 specialized questions divided into categories</sup>
* <sup>**Test Generation:** Randomly generates a 20-question exam (7 easy, 7 medium, 6 hard)</sup>
* <sup>**Input Validation:** Secure `getSafeInt` function to prevent crashes from invalid keyboard input</sup>
* <sup>**Statistics:** Tracks student performance, including average grades and category success rates</sup>

## 📈 Mathematical Model & Combinations
<sup>The final grade is calculated using a standard 6-point scale based on a maximum of 39 points</sup>
<sup> **Formula:** `Grade = (TotalPoints / 39.0) * 4 + 2`

### Test Variations
To calculate the number of possible test variants:
We choose 7 questions Category 1, 7 Category 2, and 6 Category 3.
The number of unique combinations is:
$$C_{10}^{7} \times C_{10}^{7} \times C_{10}^{6} = 120 \times 120 \times 210 = 3,024,000 \text{ variants}$$

## 🛠 Technologies
* <sup>**Language:** C++ </sup>
* <sup>**Libraries:** STL (vector, string), cstdlib, ctime </sup>
* <sup>**Platform:** GitHub for version control and collaboration </sup>
* <sup>**Platform:** VS and Visual Studio Code for coding </sup>
* <sup>**Platform:** Canva, Power Point and Word for documentation & presentation </sup>

## 🚀 How to Run
1. Clone the repository.
2. Compile `main.cpp` using a C++ compiler (e.g., `g++ main.cpp -o ESchool`).
3. Run the executable file.
