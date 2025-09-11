# 🕵️ Investigation-Game: The Detective's Quest

A **C++ console-based mystery adventure game** where you step into the role of a detective trying to solve a murder.  
To uncover the truth, you must complete a series of challenges that test your **math skills, intuition, logic, and strategy**.

---

## 📖 Storyline

A gruesome murder has shaken the city.  
You, the detective, are tasked with piecing together the clues.  

But this isn’t an ordinary investigation...  
To reveal the truth, you must pass through **multiple challenges**:
- Crack math puzzles 🔢
- Outsmart the mastermind in Rock-Paper-Scissors ✊✋✌️
- Show your strategy in Tic-Tac-Toe ⭕❌
- Trust your intuition in a Number Guessing challenge 🎲  

Only if you succeed in all modules will you uncover the killer!

---

## 🧩 Modules in the Game

The game is divided into **5 main modules**:

### 1. **Start Investigation**
- Welcomes the player.
- Sets the story of the murder.
- Suspenseful delay using `std::this_thread::sleep_for`.

### 2. **Math Quiz**
- Tests logical reasoning with **multiple-choice math puzzles**.
- Example question:  
  *"What is the result of 7^2 + 3*4 - 9?"*

### 3. **Rock-Paper-Scissors Game**
- A battle of wits against the computer.
- Randomized opponent choices using `rand() % 3`.
- Win to earn a clue.

### 4. **Tic-Tac-Toe (XO Game)**
- Classic 3x3 grid strategic challenge.
- Features:
  - Input validation
  - Winner/draw detection
  - Replayable rounds
- Fully interactive between two players.

### 5. **Number Guessing Quiz**
- Final test of intuition.
- Guess the **secret number (1–10)** within **3 attempts**.
- Success completes the case; failure leaves it unsolved.

---

## ✨ Features

- Case-insensitive input handling
- Multiple-choice questions
- Randomized computer opponent
- Replayable mini-games
- Smooth storytelling experience

---

## 📂 Project Structure

- **`main()`** → Entry point, controls game flow.
- **`startInvestigation()`** → Displays intro and story.
- **`MathQuiz()`** → Handles math questions.
- **`RockPaperScissorsGame()`** → Runs RPS game logic.
- **`XoGame()`** → Implements Tic-Tac-Toe with helper functions:
  - `checkWinner()`
  - `checkGrid()`
  - `playerMove()`
- **`NumberGuessingQuiz()`** → Manages number guessing game.
- **Utility Functions**
  - `toLowercase(string)` → Case-insensitive input handling.
  - `checkAnswer(correct, user)` → Simple answer checker.

---

## ⚙️ Technologies Used

- **C++ Standard Library**:
  - `<iostream>`: Input/output  
  - `<string>`, `<vector>`: String & data handling  
  - `<cstdlib>`, `<ctime>`: Randomization  
  - `<thread>`, `<chrono>`: Game delays  
  - `<cctype>`: Input validation (case conversion)  
  - `<cmath>`, `<iomanip>`, `<limits>`: Supporting math and formatting

---

## 🚀 How to Run

1. Clone the repository or copy the source file.
2. Compile the project:
   ```bash
   g++ -std=c++11 -o InvestigationGame main.cpp

---

## 📌 Future Improvements

- Add more math puzzles & levels.
- Include a timer for faster-paced challenges.
- Add scoreboard system to track performance.
- Expand storyline with branching paths.
