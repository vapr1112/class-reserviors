#include "Reservoir.h"

reservoir::reservoir(char* name_p, int length_p, int width_p, int depth_p, const char* type_p) : name{},
length{ length_p }, width{ width_p }, depth{ depth_p }//������� �����������
{
	if (length_p < 0 || width_p  < 0|| depth_p < 0) throw negative_number("�������� �� ����� ���� ��������������");
	strcpy_s(type, strlen(type_p) + 1, type_p);
	if (name)
	{
		new char[strlen(name_p) + 1];
		strcpy_s(name, strlen(name_p) + 1, name_p);
	}
}

//����������� �����������
reservoir::reservoir(const reservoir& reservoir_p) : name{ new char[strlen(reservoir_p.name) + 1] }, length{ reservoir_p.length },
width{ reservoir_p.width }, depth{ reservoir_p.depth }
{
	strcpy_s(type, strlen(reservoir_p.type) + 1, reservoir_p.type);
	strcpy_s(name, strlen(reservoir_p.name) + 1, reservoir_p.name);
}

//��������� � ������������
void reservoir::set_name(const char* name_p)
{
	delete[] name;

	name = new char[strlen(name_p) + 1];

	strcpy_s(name, strlen(name_p) + 1, name_p);
}
//���������� ������ � ���������� � ���
void reservoir::print() const
{
	printf("\n�������� ������� %s", name);
	printf("\n��� ������� %s", type);
	cout << "\n����� " << length;
	cout << "\n������ " << width;
	cout << "\n������� " << depth;
}
//���������� ������� ��������
void reservoir:: comp_square(reservoir reservoir_p) const
{
	int flag = 0;//������������ ��������� ��������, ������� ��������� � ������ ���� ��� � ������
	int square = length * width, square_2 = reservoir_p.length * reservoir_p.width;//������� ��������
	strcmp(type, reservoir_p.type) == 0 ? flag = 1 : flag = 0;//���������, ��������� �� ������� � ������ ����

	if (flag == 0)
	{
		cout << "\n��� ������� ������ �����, �������� ������� ������ ����\n";
	}

	else
	{
		if (square > square_2)
		{
			cout << "\n������� ������� ������� ������\n";
		}
		else if (square < square_2)
		{
			cout << "\n������� ������� ������� ������\n";
		}

		else
		{
			cout << "\n������� �������� �����\n";
		}
	}
}

reservoir reservoir::copy(reservoir reservoir_p)//������� ����� �������
{
	reservoir new_reservoir{ reservoir_p };

	return new_reservoir;
}