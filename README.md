# funteam
# 🌍 E-School: **World History**
**Project for 9th Grade Project Activities | PGKPPI Burgas (2025/2026)**

## 📝 Project Description
The program allows users to read a <b>short lesson, practice, take an exam, and view statistics based on previous exam attempts.</b>  
Users can read a short lesson, practice , take a fully automated exam, and view detailed statistics about all completed attempts.

The exam pulls questions from three historical periods — **Ancient, Medieval, and Modern History** — shuffles them, calculates a final grade on a 2.00–6.00 scale, and stores each student's results.

## 👥 The Team
<ol>
<li><b>Ангел Пиерре Андре Фриедириш — Scrum Trainer</b></li>
<li><b>Никита Сергеевич Кощеев — Backend Developer</b></li>
<li><b>Александър Ивайлов Петров — FrontEnd Developer</b></li>
<li><b>Мирослава Ивановна Хмара — QA & Documentation</b></li>
</ol>

## ⚙️ Features
* **Question Bank:** Over 30 history questions divided into three categories (Ancient, Medieval, Modern)
* **Test Generation:** Randomly generates a 20-question exam (7 easy, 7 medium, 6 hard)
* **Input Validation:** Secure `getSafeInt` function to prevent crashes from invalid keyboard input
* **Statistics:** Tracks student performance, including average grades and category success rates

## 📈 Mathematical Model & Combinations
The final grade is calculated using a standard 6-point scale based on a maximum of 39 points.  
**Formula:**  
`Grade = (TotalPoints / 39.0) * 4 + 2`

### Test Variations
To calculate the number of possible test variants:  
We choose 7 questions from Category 1 (Ancient), 7 from Category 2 (Medieval), and 6 from Category 3 (Modern).

The number of unique combinations is:

$$C_{10}^{7} \times C_{10}^{7} \times C_{10}^{6} = 120 \times 120 \times 210 = 3,024,000 \text{ variants}$$

## 🛠 Technologies
* **Language:** C++  
* **Libraries:** STL (vector, string), cstdlib, ctime  
* **Platform:** GitHub for version control and collaboration  
* **Platform:** Visual Studio & Visual Studio Code for coding  
* **Platform:** Canva, PowerPoint, and Word for documentation & presentation  

## 🚀 How to Run
1. Clone the repository.  
2. Compile `main.cpp` using a C++ compiler (e.g., `g++ main.cpp -o ESchool`).  
3. Run the executable file.

## 📂 Documentation & Presentation

### 📋 Documentation
[Documentation](https://github.com/MIHmara/funteam/blob/6c895e40aee9576e2e9808d21dcf89ed79898ff7/Presntation%20%20%26%20Documentation/E-School%20World%20History.docx) 
### 🎤 Presentation
[Presentation](https://github.com/MIHmara/funteam/blob/6c895e40aee9576e2e9808d21dcf89ed79898ff7/Presntation%20%20%26%20Documentation/FUNTEAM%20Presentation.pptx)
