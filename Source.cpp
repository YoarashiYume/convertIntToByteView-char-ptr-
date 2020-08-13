#include <iostream>
#include "Randomizer.h"

void numberAsBinary(char* _result, unsigned int _number)
{
	*_result = '\0';
	if (_number == 0)
	{
		*_result = '0';
		*(_result + 1) = '\0';
		return;
	}
	if (_number != 1)
		numberAsBinary(_result, _number / 2);
	int size = std::strlen(_result);
	*(_result + size ) = '0' + _number % 2;
	*(_result + size + 1) = '\0';
	
}

int main()
{
	setlocale(LC_ALL, "ru");
	Randomizer random;
	random.setRange(0, 512);
	char* res = new char[11];
	for (int i=0; i<11; ++i)
	{
		int value = random.getRandomValue();
		numberAsBinary(res, value);
		std::cout << value << " = " << res << std::endl;
	}
	return 0;
}