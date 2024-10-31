#include "Header.h"

reservoir* adding(reservoir* reserviors, int& size)//���������� ������� � ������ �������� reserviors
{
	reservoir* new_reservoirs = new reservoir[++size];

	int length, width, depth;
	char type[SIZE], name[SIZE];

	cout << "\n������� ��������, ���, �����, ������ � ������� ������ �������\n";

	cin.ignore();

	gets_s(name);
	gets_s(type);

	cin >> length >> width >> depth;

	for (int i = 0; i < size - 1; i++)//����������� ������ �������� �� ������� ������� � �����
	{
		new_reservoirs[i].set_name(reserviors[i].get_name());
		new_reservoirs[i].set_type(reserviors[i].get_type());
		new_reservoirs[i].set_length(reserviors[i].get_length());
		new_reservoirs[i].set_width(reserviors[i].get_width());
		new_reservoirs[i].set_depth(reserviors[i].get_depth());
	}

	//���������� � ����� ������ ������ �������, ���������� �������������
	new_reservoirs[size - 1].set_name(name);
	new_reservoirs[size - 1].set_type(type);
	new_reservoirs[size - 1].set_length(length);
	new_reservoirs[size - 1].set_width(width);
	new_reservoirs[size - 1].set_depth(depth);

	delete[] reserviors;

	return new_reservoirs;
}

reservoir* deleting(reservoir* reserviors, int& size)//�������� ������� �� ������� �������� reserviors
{
	reservoir* new_reservoirs = new reservoir[--size];

	for (int i = 0; i < size; i++)//����������� ������ �������� �� ������� ������� � ����� ��� ���������� �������
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

reservoir* add_copy(reservoir* reserviors, int& size)//���������� � ������ �������������� �������
{
	reservoir* new_reservoirs = new reservoir[++size];

	int user;//������ ������a

	for (int i = 0; i < size - 1; i++)//����������� ������ �������� �� ������� ������� � ����� ��� ���������� �������
	{
		new_reservoirs[i].set_name(reserviors[i].get_name());
		new_reservoirs[i].set_type(reserviors[i].get_type());
		new_reservoirs[i].set_length(reserviors[i].get_length());
		new_reservoirs[i].set_width(reserviors[i].get_width());
		new_reservoirs[i].set_depth(reserviors[i].get_depth());
	}

	cout << "\n������� ������ ������a, �������� ������ �����������\n";

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
		cout << "�� ������� ������� ����\n";
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
		cout << "�� ������� ������� ����\n";
		return 29;
	}

}