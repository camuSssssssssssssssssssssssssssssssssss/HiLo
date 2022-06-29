#include <iostream>
#include <ctime>
#include <random>


//��������� ������ ������� ����� �� 0 �� 100. +
//����� 7 ������. +
//���� ����� ������, ��������� ������ ������������ ���: ��� �� ��� ����� ������ ��� ����.
//���� ����� ������� �����, �� ��������� ������ ������ - "�� �����, �� ��������".
//���� �� � ������������ ��������� �������, � �� �� ������ �����, �� ��������� ������ �������� ���, ��� �� �������� � �������� ���������� ���������.
//� ����� ���� ��������� ������ �������� � ������������, �� ����� �� �� ������� ��� ���. ���� ������������ �� ������ �� y, �� n (� ���-�� ������), �� ��������� ������ �������� ��� ��� ���.


//��������� ����� �� 0 �� 100.
int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

bool playGame(int number, int heatlh)
{
	setlocale(LC_ALL, "");
	for (int count = 1; count <= heatlh; ++count)
	{
		int personalinput;
		std::cout << "������� �����: ";
		std::cin >> personalinput;
		std::cout << "������� #" << count << std::endl;

		if (personalinput < number)
		{
			std::cout << "����� ���� �����������." << std::endl;
		}
		else if (personalinput > number)
		{
			std::cout << "����� ���� �����������." << std::endl;
		}
		else
			return true;
	}
	return false;
}

bool playAgain()
{
	
	setlocale(LC_ALL, "");
	char sym;
	do
	{
		std::cout << "������ �� ������� ���? �������: Y/N" << std::endl;
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
		std::cout << "����� ���������� � HiLo. � ��� ���� ���� �������, ����� �������� �����. �������! ";
		int number = getRandomNumber(1, 100);
		bool won = playGame(number, HP);
		if (won)
			std::cout << "You win." << "\n";
		else
			std::cout << "��������, �� �� ���������. ���������� �����: " << number << "\n";
	} 
	while (playAgain());


}