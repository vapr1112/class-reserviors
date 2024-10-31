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

	//if (size == 0)
	//{
	//	new_reservoirs = nullptr;
	//}

	delete[] reserviors;

	return new_reservoirs;
}