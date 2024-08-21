#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <cctype> // For  toupper
#include <thread> // For std::this_thread::sleep_for
#include <chrono> // For std::chrono::seconds
#include <cmath>  // For math functions
using namespace std;

// Function to convert a string to lowercase
string toLowercase(string str)
{
	for (char &c : str)
	{
		c = tolower(c);
	}
	return str;
}

// Function to check the answer
bool checkAnswer(string correctAnswer, string userAnswer)
{
	return toLowercase(correctAnswer) == toLowercase(userAnswer);
}

void XoGame()
{
	// Tic-Tac-Toe Game Variables
	string nameO, nameX;
	char order[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

	// Helper functions for Tic-Tac-Toe
	auto resetGame = [&order]()
	{
		char start = '1';
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				order[i][j] = start++;
	};

	auto checkWinner = [&order](char player)
	{
		for (int i = 0; i < 3; ++i)
			if ((order[i][0] == player && order[i][1] == player && order[i][2] == player) ||
				(order[0][i] == player && order[1][i] == player && order[2][i] == player))
				return true;
		return (order[0][0] == player && order[1][1] == player && order[2][2] == player) ||
			   (order[0][2] == player && order[1][1] == player && order[2][0] == player);
	};

	auto checkGrid = [&order]()
	{
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				if (order[i][j] != 'O' && order[i][j] != 'X')
					return false;
		return true;
	};

	auto DesignGame = [&order]()
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				cout << "   " << order[i][j];
				if (j < 2)
					cout << " |";
			}
			if (i < 2)
				cout << "\n--------------------\n";
		}
		cout << "\n";
	};

	auto playerMove = [&order, &nameO, &nameX](char player)
	{
		int num;
		bool valid = false;
		string playerName = (player == 'O') ? nameO : nameX;

		while (!valid)
		{
			cout << "Player " << playerName << ", enter a number: ";
			cin >> num;

			if (cin.fail() || num < 1 || num > 9 || order[(num - 1) / 3][(num - 1) % 3] == 'O' || order[(num - 1) / 3][(num - 1) % 3] == 'X')
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Invalid input! Please enter a number from 1 to 9 that hasn't been used yet.\n";
			}
			else
			{
				order[(num - 1) / 3][(num - 1) % 3] = player;
				valid = true;
			}
		}
	};

	// Tic-Tac-Toe Game Loop
	bool Continue = true;
	while (Continue)
	{
		cout << "==========================================\n";
		cout << "   The Investigator's Strategic Challenge\n";
		cout << "==========================================\n\n";
		cout << " *** Tic Tac Toe Game ***\n";
		cout << "To continue unraveling the mystery of the murder, you must now prove your strategic skills.\n";
		cout << "In this challenge, you'll face off in a classic game of Tic-Tac-Toe against the enigmatic mastermind.\n";
		cout << "Winning this game might just reveal crucial hints about the case.\n";
		cout << "Show your tactical prowess and advance further in your investigation.\n";

		cout << "Enter the name of the first player 'O': ";
		cin.ignore();
		getline(cin, nameO);
		cout << "Enter the name of the second player 'X': ";
		getline(cin, nameX);

		bool gameOver = false;

		while (!gameOver)
		{
			DesignGame();
			playerMove('O');
			if (checkWinner('O'))
			{
				DesignGame();
				cout << "Player " << nameO << " Wins!\n";
				gameOver = true;
			}
			else if (checkGrid())
			{
				DesignGame();
				cout << "*** It's a Draw! ***\n";
				gameOver = true;
			}
			else
			{
				DesignGame();
				playerMove('X');
				if (checkWinner('X'))
				{
					DesignGame();
					cout << "Player " << nameX << " Wins!\n";
					gameOver = true;
				}
				else if (checkGrid())
				{
					DesignGame();
					cout << "*** It's a Draw! ***\n";
					gameOver = true;
				}
			}
		}

		cout << "******* Game Over *********\n";
		cout << "Bravo! You've outwitted the mastermind in the game of Tic-Tac-Toe.\n";
		cout << "Your strategic brilliance has brought you closer to uncovering the truth behind the murder.\n";
		cout << "Congratulations, detective! Your skillful play has added another piece to the puzzle.\n";
		cout << "Prepare yourself for the next challenge in this thrilling investigation.\n\n";
		Continue = false;
	}
}

// Function for the number guessing quiz
void NumberGuessingQuiz()
{
	cout << "==========================================\n";
	cout << "   The Final Challenge: Number Guessing\n";
	cout << "==========================================\n\n";

	cout << "You\'ve gathered valuable clues, and now it\'s time to put your intuition to the test.\n";
	cout << "The final piece of the puzzle lies in guessing the right number. This test will reveal if you\'re truly ready to solve the case.\n";
	cout << "You have three attempts to guess the correct number between 1 and 10.\n\n";

	cout << "Here\'s your final challenge:\n";

	int secretNumber = 7; // The correct number for this case
	int guess;
	int attempts = 3;

	// Loop for the number guessing game
	while (attempts > 0)
	{
		cout << "Enter your guess (1-10): ";
		cin >> guess;
		if (cin.fail())
		{
			cout << "Invalid input! Please enter a number from 1 to 10.\n"
		}
		if (guess == secretNumber)
		{
			cout << "Fantastic! You\'ve successfully guessed the number and completed the investigation. Congratulations, detective!\n\n\n";
			break; // Correct guess
		}
		else
		{
			attempts--;
			if (attempts > 0)
			{
				cout << "Not quite. You have " << attempts << " attempt(s) left.\n";
			}
			else
			{
				cout << "The correct number was " << secretNumber << ". The case remains unsolved. Better luck next time!\n";
			}
		}
	}
}

// Function for the math quiz
void MathQuiz()
{
	char choice; // Variable to store user input

	cout << "==========================================\n";
	cout << "   The Investigation Begins: Math Clues\n";
	cout << "==========================================\n\n";

	cout << "To get closer to solving the murder, you need to crack the code hidden in these math puzzles.\n";
	cout << "Each question will provide you with clues necessary for uncovering the truth.\n";
	cout << "Solve them correctly to advance in your investigation.\n\n";

	cout << "Here\'s your first challenge:\n\n";
	cout << "\"What is the result of 7^2 + 3*4 - 9?\"\n\n";

	// Multiple choice options
	cout << "A. 50\n";
	cout << "B. 52\n";
	cout << "C. 53\n";
	cout << "D. 55\n\n";

	cout << "What\'s your answer?\n";

	// Loop to get the correct answer from the user for the first question
	while (true)
	{
		cin >> choice;			  // Take user input
		choice = toupper(choice); // Convert to uppercase to handle case insensitivity

		if (choice == 'B')
		{
			cout << "Correct! You\’ve uncovered a crucial clue. Proceed to the next challenge.\n\n\n";
			break; // Exit loop when the correct answer is chosen
		}
		else if (choice == 'A' || choice == 'C' || choice == 'D')
		{
			cout << "That\’s not the right answer. Try again to find the correct clue.\n";
			continue; // Continue the loop for incorrect answers
		}
		else
		{
			cout << "Invalid choice. Please select A, B, C, or D.\n"; // Handle invalid input
			continue;
		}
	}

	// Start of the second math question
	cout << "\"If the sum of two numbers is 72 and their difference is 18, what are the numbers?\"\n\n";

	// Multiple choice options
	cout << "A. 45 and 27\n";
	cout << "B. 50 and 22\n";
	cout << "C. 55 and 17\n";
	cout << "D. 60 and 12\n\n";

	cout << "What\'s your answer?\n";

	// Loop to get the correct answer from the user for the second question
	while (true)
	{
		cin >> choice;			  // Take user input
		choice = toupper(choice); // Convert to uppercase to handle case insensitivity

		if (choice == 'A')
		{
			cout << "Well done! You\’re getting closer to solving the mystery.\n\n\n";
			break; // Exit loop when the correct answer is chosen
		}
		else if (choice == 'B' || choice == 'C' || choice == 'D')
		{
			cout << "That\’s not the right answer. Try again to find the correct clue.\n";
			continue; // Continue the loop for incorrect answers
		}
		else
		{
			cout << "Invalid choice. Please select A, B, C, or D.\n"; // Handle invalid input
			continue;
		}
	}
}

void RockPaperScissorsGame()
{
	cout << "==========================================\n";
	cout << "   Intelligence Quiz: Rock-Paper-Scissors\n";
	cout << "==========================================\n\n";

	cout << "It\'s time to test your strategic thinking with a classic game of Rock-Paper-Scissors.\n";
	cout << "Win this game, and you\'ll earn a crucial clue to solve the case.\n\n";

	// Loop for Rock-Paper-Scissors game
	while (true)
	{
		string userChoice;
		string computerChoice;
		string choices[3] = {"rock", "paper", "scissors"};

		// Generate computer choice
		srand(time(0));
		computerChoice = choices[rand() % 3];

		cout << "Choose rock, paper, or scissors: ";
		cin >> userChoice;
		userChoice = toLowercase(userChoice); // Convert user input to lowercase

		// Input validation
		while (userChoice != "rock" && userChoice != "paper" && userChoice != "scissors")
		{
			cout << "Invalid choice! Please choose rock, paper, or scissors: ";
			cin >> userChoice;
			userChoice = toLowercase(userChoice);
		}

		cout << "You chose " << userChoice << ".\n";
		cout << "The computer chose " << computerChoice << ".\n\n";

		// Determine winner
		if (userChoice == computerChoice)
		{
			cout << "It\'s a tie! Let\'s play again.\n";
		}
		else if ((userChoice == "rock" && computerChoice == "scissors") ||
				 (userChoice == "paper" && computerChoice == "rock") ||
				 (userChoice == "scissors" && computerChoice == "paper"))
		{
			cout << "You win this round! You\'ve earned another clue for the case.\n\n";
			break;
		}
		else
		{
			cout << "The computer wins this round. Try again to win the clue!\n\n";
		}
	}
}

void startInvestigation()
{
	cout << "==========================================\n";
	cout << "   Welcome, Detective!\n";
	cout << "==========================================\n\n";

	cout << "A gruesome murder has taken place, and it\'s up to you to solve the case.\n";
	cout << "Your skills in mathematics, strategic thinking, and number guessing will be put to the test.\n\n";
	cout << "Good luck!\n\n";

	// Pause for dramatic effect
	std::this_thread::sleep_for(std::chrono::seconds(2));
}

int main()
{

	startInvestigation();

	MathQuiz();

	RockPaperScissorsGame();
	XoGame();
	NumberGuessingQuiz();

	cout << "Thank you for playing! Goodbye.\n";

	return 0;
}
