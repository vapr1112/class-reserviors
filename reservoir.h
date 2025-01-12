#pragma once
#include <iostream>
#include "negative_number.h" 
#define SIZE 2000

using namespace std;

class reservoir
{
private:
	char* name;
	int length;//длина водоема
	int width;//ширина водоема
	int depth;//глубина водоема
	char type[SIZE];
public:

	reservoir(char* name_p, int length_p, int width_p, int depth_p, const char* type_p);//главный конструктор

	reservoir() : reservoir(nullptr, 0, 0, 0, "\0") {};

	reservoir(const reservoir& reservoir_p);//конструктор копирования

	//explicit Date(int day_p) : Date(day_p, 1, 2000, nullptr) {}
	explicit reservoir(int length_p) : reservoir(nullptr, length_p, 0, 0, "\0") {}//explicit конструктор

	//акссесоры и модификаторы
	void set_name(const char* name_p);

	void set_type(const char* type_p)
	{
		strcpy_s(type, strlen(type_p) + 1, type_p);
	}

	void set_length(int length_p)
	{
		if (length_p < 0) throw negative_number("длина не может быть отрицательной");
		length = length_p;
	}

	void set_width(int width_p)
	{
		if (width_p < 0) throw negative_number("ширина не может быть отрицательной");
		width = width_p;
	}

	void set_depth(int depth_p)
	{
		if (depth_p < 0) throw negative_number("глубина не может быть отрицательной");
		depth = depth_p;
	}

	const char* get_name() const
	{
		return name;
	}

	const char* get_type() const
	{
		return type;
	}

	int get_length() const
	{
		return length;
	}

	int get_width() const
	{
		return width;
	}

	int get_depth() const
	{
		return depth;
	}

	void print() const;//показывает водоем и информацию о нем

	//другие методы
	void volume() const //показывает объем водоема
	{
		cout << "\nобъем данного водоема " << depth * length * width;
	}

	void square() const //показывает площадь водоема
	{
		cout << "\n площадь водоема " << length * width;
	}

	void comp_type(reservoir reservoir_p) const//проверяет, относятся ли водоемы к одному типу
	{
		strcmp(type, reservoir_p.type) == 0 ? cout << "\nводоемы относятся к одному типу\n": cout << "\nводоемы относятся к разным типам\n";
	}

	void comp_square(reservoir reservoir_p) const;//сравнивает площади водоемов

	reservoir copy(reservoir reservoir_p);//создает копию объекта

	~reservoir()//деструктор
	{
		delete[] name;
	}
};

