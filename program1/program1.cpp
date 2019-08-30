// Justin Foster - Program 1
// August 28, 2019 - CS201

#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <cstdlib>

using namespace std;

//Declaration of functions

int diceRoll();
int playerTurn(int& playerScore); //Both of these functions using bass-by-reference to keep the score updated throughout turns
int cpuTurn(int& cpuScore);

int main()
{
	srand(time(0)); //setting random time

	int playerScore = 0;
	int cpuScore = 0;

	cout << "Did user roll first previous game? (Y)es or (N)o." << endl;
	string choice;
	cin >> choice;

	while (!(choice == "Y" || "y" || "N" || "n"))
	{
		cout << "Please enter Y or N." << endl;
	}

	if (choice == "Y" || choice =="y")
	{

		while (playerScore < 50 || cpuScore < 50)
		{
			playerTurn(playerScore);
			cpuTurn(cpuScore);
			cout << "Current scores - You: " << playerScore << ". Computer: " << cpuScore << "." << endl;
			if (playerScore >= 50 || cpuScore >= 50)
			{
				break;
			}
		}
	}

	if (choice == "n" || choice == "N")
	{
		while (playerScore < 50 || cpuScore < 50)
		{
			cpuTurn(cpuScore);
			playerTurn(playerScore);
			cout << "Current scores - You: " << playerScore << ". Computer: " << cpuScore << "." << endl;
			if (playerScore >= 50 || cpuScore >= 50)
			{
				break;
			}
		}
	}

	if (playerScore >= 50)
	{
		cout << "Congratulations, you win! Score: " << playerScore << endl;
	}

	if (cpuScore >= 50)
	{
		cout << "You got beat by a computer! CPU score: " << cpuScore << endl;
	}
}

//Definition of Functions

int diceRoll() //Function to roll the dice 
{
	int dice;
	dice = 1 + rand() % 6;

	return dice;
}

int playerTurn(int& playerScore)
{
	int score = 0;
	int pot = 0;
	string rollOrHold;

	cout << "Player turn. Would you like to (R)oll or (H)old?" << endl;
	cin >> rollOrHold;

	while (!(rollOrHold == "r" || "R" || "h" || "H"))
	{
		cout << "Please enter R or H." << endl;
		cin >> rollOrHold;
	}

	do
	{
		int score = diceRoll(); //assigned function call to value 
		cout << "Dice roll: " << score;

		if (score == 1)
		{
			pot = 0;
			cout << " Bust! Pot set to zero. " << endl;
			break;
		}

		else (score > 1);
		{
			pot += score;
			cout << " Dice roll: " << score << " Player Score: " << playerScore << " Pot: " << pot << endl;
			cout << "Player turn. Would you like to (R)oll or (H)old?" << endl;
			cin >> rollOrHold;
		}

	} while (rollOrHold == "r" || rollOrHold == "R");

	if(rollOrHold == "h" || rollOrHold == "H")
	{
		playerScore += pot;
		cout << "Player score: " << playerScore << endl;
	}

	return playerScore;
}

int cpuTurn(int& cpuScore)
{
	int score = 0;
	int pot = 0;

	cout << "Computer Turn. " << endl;

	while (pot <= 20)
	{
		score = diceRoll();

		if (score == 1)
		{
			cout << "Computer bust. " << endl;
			break;
		}

		else (score > 1);
		{
			pot += score;
			cout << "Dice roll: " << score << " Pot: " << pot << endl;
		}
	}

	if (pot >= 20)
	{
		cpuScore += pot;
		cout << "Computer score: " << cpuScore << endl;
	}

	return cpuScore;
}