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
