#include "Reservoir.h"

reservoir::reservoir(char* name_p, int length_p, int width_p, int depth_p, const char* type_p) : name{},
length{ length_p }, width{ width_p }, depth{ depth_p }//главный конструктор
{
	strcpy_s(type, strlen(type_p) + 1, type_p);
	if (name)
	{
		new char[strlen(name_p) + 1];
		strcpy_s(name, strlen(name_p) + 1, name_p);
	}
}

reservoir::reservoir(const reservoir& reservoir_p) : name{ new char[strlen(reservoir_p.name) + 1] }, length{ reservoir_p.length },
width{ reservoir_p.width }, depth{ reservoir_p.depth }//конструктор копирования
{
	strcpy_s(type, strlen(reservoir_p.type) + 1, reservoir_p.type);
	strcpy_s(name, strlen(reservoir_p.name) + 1, reservoir_p.name);
}

//акссесоры и модификаторы
void reservoir::set_name(const char* name_p)
{
	delete[] name;

	name = new char[strlen(name_p) + 1];

	strcpy_s(name, strlen(name_p) + 1, name_p);
}

void reservoir::print() const//показывает водоем и информацию о нем
{
	printf("\nназвание водоема %s", name);
	printf("\nтип водоема %s", type);
	cout << "\nдлина " << length;
	cout << "\nширина " << width;
	cout << "\nглубина " << depth;
}

void reservoir:: comp_square(reservoir reservoir_p) const//сравнивает площади водоемов
{
	int flag = 0;//записывается результат проверки, водоемы относятся к одному типу или к разным
	int square = length * width, square_2 = reservoir_p.length * reservoir_p.width;//площади водоемов
	strcmp(type, reservoir_p.type) == 0 ? flag = 1 : flag = 0;//проверяет, относятся ли водоемы к одному типу

	if (flag == 0)
	{
		cout << "\nэто водоемы разных типов, напишите водоемы одного типа\n";
	}

	else
	{
		if (square > square_2)
		{
			cout << "\nплощадь первого водоема больше\n";
		}
		else if (square < square_2)
		{
			cout << "\nплощадь второго водоема больше\n";
		}

		else
		{
			cout << "\nплощади водоемов равны\n";
		}
	}
}

reservoir reservoir::copy(reservoir reservoir_p)//создает копию объекта
{
	reservoir new_reservoir{ reservoir_p };

	return new_reservoir;
}