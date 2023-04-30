#include "Arena.h"

Arena::Arena(int l, int w, Prey* prey, Predator* predator) : prey(prey), predator(predator)
{
	//ѕроверка диапазона l w от (1 до 99)       
	/*length = l;
	width = w;*/
	if ((l < 0 || l > 100) || (w < 0 || w > 100))
	{
		std::cout << "Ќепраильный размер пол€ \n" << std::endl;
		exit(-1);
	}

	// Ќахождение местоположени€ жертвы, проверка в пределах пол€
	else if (prey->getLocation().getX() > l || prey->getLocation().getY > w)
	{
		std::cout << "∆ертва за пределами пол€\n" << std::endl;
		exit(-1);
	}

	// Ќахождение местоположени€ хищника, проверка в пределах пол€
	else if (predator->getLocation().getX() > l || predator->getLocation().getY > w)
	{
		std::cout << "’ищник за пределами пол€\n" << std::endl;
		exit(-1);
	}

	else
	{
		length = l;
		width = w;
	}

	// увеличение размера пол€ дл€ посто€нных символов (границы, координаты) 
	int shift_l = 3;
	int shift_w = 4;
	int stretch_w = 2; // удвоим ширину пол€ ( дл€ симметрии клеток при отображении)

	view_length = length + shift_l;
	view_width = width * stretch_w + shift_w;

	//выдел€ем пам€ть под массив field размером view_length x view_width
	field = new char* [view_length];

	for (int i = 0; i < view_length; i++) 
	{
		field[i] = new char[view_width]();

		for (int j = 0; j < view_width; j++)
		{
			field[i][j] = ' ';
		}
	}
	
	// заполнение массива декоративными символами

	// верхн€€ и нижн€€ грань пол€
	for (int j = 2; j < view_width; j++) 
	{
		field[0][j] = '~';
		field[view_length - 2][j] = '~';
		//нумераци€ снизу
		int cell_num = (j / 2);

		if (j >= view_width - 2) 
			continue;

		if (cell_num > 9) 
		{
			if ((j + 1) % 2 == 0) 
			{
				field[view_length - 1][j + 1] = (cell_num % 10) + '0';
			}
			else field[view_length - 1][j + 1] = (cell_num / 10) + '0';
		}
		else 
		{
			if ((j + 1) % 2 == 0) 
			{
				field[view_length - 1][j + 1] = cell_num + '0';
			}
			else field[view_length - 1][j + 1] = ' ';
		}
	}
	// лева€ и права€ грань пол€
	for (int i = 1; i < view_length - 2; i++) 
	{
		field[i][2] = '|';
		field[i][view_width - 1] = '|';

		// нумераци€ слева
		int y_coords = view_length - shift_l + 1;

		if (y_coords - i > 9) 
		{
			int tmp = ((y_coords - i) / 10);
			field[i][0] = ((y_coords - i) / 10) + '0';
			field[i][1] = ((y_coords - i) % 10) + '0';
		}
		else field[i][1] = y_coords - i + '0';
	}

}

void Arena::clearStep() 
{
	// удаление жертвы
	int preyX = (prey->getLocation().getX() * 2) + 4;
	int preyY = prey->getLocation().getY() + 3;

	field[view_length - preyY][preyX] = ' ';
	field[view_length - preyY][preyX - 1] = ' ';

	// удаление хищника
	int predX = (predator->getLocation().getX() * 2) + 4;
	int predY = predator->getLocation().getY() + 3;

	field[view_length - predY][predX] = ' ';
	field[view_length - predY][predX - 1] = ' ';
}

//TODO: скорректирвовать границы ()
/*bool Arena::checkOverRun() {
	int preyX = prey->getLocation().getX();
	int preyY = prey->getLocation().getY();

	if (preyX > width-1 || preyX < 0 || preyY > length-1 || preyY < 0) return true;

	int predX = predator->getLocation().getX();
	int predY = predator->getLocation().getY();

	if (predX > width-1 || predX < 0 || predY > length-1 || predY < 0) return true;

	return false;
}*/

bool Arena::checkOverRun()
{
	int preyX = (prey->getLocation().getX() * 2) + 2;
	int preyY = prey->getLocation().getY() + 2;

	if (preyX > view_width || preyX < 3 || preyY > view_length || preyY < 3) return true;

	int predX = (predator->getLocation().getX() * 2) + 2;
	int predY = predator->getLocation().getY() + 2;

	if (predX > view_width || predX < 3 || predY > view_length || predY < 3) return true;

	return false;
}



bool Arena::checkPosition()
{
	if (prey->getLocation() == predator->getLocation())
		return true;
	return false;

}

Arena::~Arena() {

	//TODO: ѕроверить правильность освобождени€ пам€ти
	for (int i = 0; i < length; i++) {

		delete[] field[i];
	}

	delete[] field;

	if (field != nullprt)
		exit(-2);
}

std::ostream& operator<<(std::ostream& out, const Arena& a) {

	// –азмещение жертвы
	int preyX = (a.prey->getLocation().getX() * 2) + 2;
	int preyY = a.prey->getLocation().getY() + 2;

	a.field[a.view_length - preyY][preyX] = ')';
	a.field[a.view_length - preyY][preyX - 1] = '(';

	// –азмещение хищника
	int predX = (a.predator->getLocation().getX() * 2) + 2;
	int predY = a.predator->getLocation().getY() + 2;

	a.field[a.view_length - predY][predX] = '*';
	a.field[a.view_length - predY][predX - 1] = '*';


	for (int i = 0; i < a.view_length; i++) {
		for (int j = 0; j < a.view_width; j++) {
			std::cout << a.field[i][j];
		}
		std::cout << "\n";
	}
	return out;
}