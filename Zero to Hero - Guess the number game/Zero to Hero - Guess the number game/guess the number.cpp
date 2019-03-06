#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cctype>
/*

random gen numbers
while false loop until number is correct
//add quit feature to loop
add play again after quiting or winning

*/
void GenerateNumber(int& x)
{
	
	x = ((rand()) % 20) +1 ;
	std::cout << "the range is 1-20" << std::endl;
}

bool numberCheck(std::string passed_string)
{
	for (char scanned : passed_string)
	{
		if (isdigit(scanned) == false)
			return false;

	}
	return true;
}

int GetNumberFromUser(bool* end)
{
	
	int input = 0;
	std::string string_Input;
	int i = 0;
	//works once skipped second time
	try {
     
		std::cin >> string_Input;
			
		if (numberCheck(string_Input)) {
			input = stoi(string_Input);
		}
		else if (string_Input == "quit")
		{
			*end = true;
			return 0;
		}
	}
	
	catch (...)
	{
		std::cout << "invalid entry" << std::endl;
		
		return 0;
	}
	//std::cin >> userInput;
	
	std::cout << "You entered " << input << std::endl;
	//check if num
	
	
	
	return input;
}

void GameLoop()
{
	bool correct_guess = false;
	bool quit = false;
	//set number
	int numberToGuess;
	int userGuess;
	GenerateNumber(numberToGuess);
	


	while ((correct_guess == false) & (quit == false)) 
	{
		
		userGuess = GetNumberFromUser(&quit);
		//play game
		if(userGuess == numberToGuess)
		{
			correct_guess = true;
			std::cout << "Congrats!!\n\nYou selected the correct number!" << std::endl;
		}
		else if (quit == true)
		{
			
			std::cout << "You decided to quit" << std::endl;
		}
		else 
		{
			std::cout << userGuess << " is not the correct answer" << std::endl;
			//reset value
			userGuess = 0;
		}
	}
	std::cin.ignore();
	std::cin.clear();
	if (correct_guess == true)
	{
		std::string response;
		printf("Do you want to play again?(y/n)\n");
		std::cin >> response;
		if ((response == "y") | response == "Y")
		{
			GameLoop();
		}
	}
}

int main()
{
	srand(time(0));
	GameLoop();
	std::cout << "Thank you for playing!" << std::endl;
	system("pause");
	return 0;
}