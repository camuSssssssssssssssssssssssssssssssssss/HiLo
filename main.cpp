#include <iostream>
#include <ctime>
#include <random>


//Программа должна выбрать число от 0 до 100. +
//Всего 7 жизней. +
//Если игрок ошибся, программа должна предупредить его: был ли его ответ близок или далёк.+
//Если игрок ответил верно, то программа должна выдать - "Всё верно, вы победили".+
//Если же у пользователя кончились попытки, и он не угадал число, то программа должна сообщить ему, что он проиграл и показать правильный результат.+
//В конце игры программа должна спросить у пользователя, не хочет ли он сыграть еще раз. Если пользователь не введет ни y, ни n (а что-то другое), то программа должна спросить его еще раз. +


//Генерация числа от 0 до 100.
int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

//Сравнение полученного числа с генерируемым 
bool playGame(int number, int heatlh)
{
	setlocale(LC_ALL, "");
	for (int count = 1; count <= heatlh; ++count)
	{
		int personalinput;
		std::cout << "Введите число: ";
		std::cin >> personalinput;
		std::cout << "Попытка #" << count << std::endl;

		if (personalinput < number)
		{
			std::cout << "Число ниже загаданного." << std::endl;
		}
		else if (personalinput > number)
		{
			std::cout << "Число выше загаданного." << std::endl;
		}
		else
			return true;
	}
	return false;
}
//Ввод Y - для повтора игры или N - для выхода из игры
bool playAgain()
{
	
	setlocale(LC_ALL, "");
	char sym;
	do
	{
		std::cout << "Хотите ли сыграть ещё? Введите: Y/N" << std::endl;
		std::cin >> sym;
	} while (sym != 'y' && sym != 'n');
	return (sym == 'y');
}
	
int main()
{
	setlocale(LC_ALL, "");
	srand(static_cast<unsigned int>(time(0)));
	rand();
	const int HP = 7;

	do
	{
		std::cout << "Добро пожаловать в HiLo. У вас есть семь попыток, чтобы отгадать число. Поехали! ";
		int number = getRandomNumber(1, 100);
		bool won = playGame(number, HP);
		if (won)
			std::cout << "You win." << "\n";
		else
			std::cout << "Извините, но вы проиграли. Правильный ответ: " << number << "\n";
	} 
	while (playAgain());


}
