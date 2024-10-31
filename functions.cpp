#include "Header.h"

reservoir* adding(reservoir* reserviors, int& size)//добавление объекта в массив объектов reserviors
{
	reservoir* new_reservoirs = new reservoir[++size];

	int length, width, depth;
	char type[SIZE], name[SIZE];

	cout << "\nВведите название, тип, длину, ширину и глубину нового водоема\n";

	cin.ignore();

	gets_s(name);
	gets_s(type);

	cin >> length >> width >> depth;

	for (int i = 0; i < size - 1; i++)//копирование старых объектов из старого массива в новый
	{
		new_reservoirs[i].set_name(reserviors[i].get_name());
		new_reservoirs[i].set_type(reserviors[i].get_type());
		new_reservoirs[i].set_length(reserviors[i].get_length());
		new_reservoirs[i].set_width(reserviors[i].get_width());
		new_reservoirs[i].set_depth(reserviors[i].get_depth());
	}

	//добавление в новый массив нового объекта, введенного пользователем
	new_reservoirs[size - 1].set_name(name);
	new_reservoirs[size - 1].set_type(type);
	new_reservoirs[size - 1].set_length(length);
	new_reservoirs[size - 1].set_width(width);
	new_reservoirs[size - 1].set_depth(depth);

	delete[] reserviors;

	return new_reservoirs;
}

reservoir* deleting(reservoir* reserviors, int& size)//удаление объекта из массива объектов reserviors
{
	reservoir* new_reservoirs = new reservoir[--size];

	for (int i = 0; i < size; i++)//копирование старых объектов из старого массива в новый без последнего объекта
	{
		new_reservoirs[i].set_name(reserviors[i].get_name());
		new_reservoirs[i].set_type(reserviors[i].get_type());
		new_reservoirs[i].set_length(reserviors[i].get_length());
		new_reservoirs[i].set_width(reserviors[i].get_width());
		new_reservoirs[i].set_depth(reserviors[i].get_depth());
	}

	delete[] reserviors;

	return new_reservoirs;
}

reservoir* add_copy(reservoir* reserviors, int& size)//добавление в массив скопированного объекта
{
	reservoir* new_reservoirs = new reservoir[++size];

	int user;//индекс водоемa

	for (int i = 0; i < size - 1; i++)//копирование старых объектов из старого массива в новый без последнего объекта
	{
		new_reservoirs[i].set_name(reserviors[i].get_name());
		new_reservoirs[i].set_type(reserviors[i].get_type());
		new_reservoirs[i].set_length(reserviors[i].get_length());
		new_reservoirs[i].set_width(reserviors[i].get_width());
		new_reservoirs[i].set_depth(reserviors[i].get_depth());
	}

	cout << "\nвведите индекс водоемa, которого хотите скопировать\n";

	cin >> user;

	reservoir copy_reservoir{ reserviors[user].copy(reserviors[user])};

	new_reservoirs[size - 1].set_name(copy_reservoir.get_name());
	new_reservoirs[size - 1].set_type(copy_reservoir.get_type());
	new_reservoirs[size - 1].set_length(copy_reservoir.get_length());
	new_reservoirs[size - 1].set_width(copy_reservoir.get_width());
	new_reservoirs[size - 1].set_depth(copy_reservoir.get_depth());

	delete[] reserviors;

	return new_reservoirs;
}

int add_file(reservoir* reserviors, int size) 
{
	FILE* file;
	int count = 0;

	if (fopen_s(&file, "reserviors.txt", "w") != NULL)
	{
		cout << "Не удалось открыть файл\n";
		return 15;
	}

	fprintf_s(file, "%d\n", size);


	for (int i = 0; i < size; i++)
	{
		fprintf_s(file, "%s\n%s\n%d\n%d\n%d", reserviors[i].get_name(), reserviors[i].get_type(), reserviors[i].get_length(), reserviors[i].get_width(), reserviors[i].get_depth());
		fputc('\n', file);
	}

	if (fclose(file) != NULL)
	{
		cout << "Не удалось закрыть файл\n";
		return 29;
	}

}