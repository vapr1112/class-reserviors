#pragma once
#include <iostream>
#define SIZE 2000

using namespace std;

class reservoir
{
private:
	char* name;
	int length;//����� �������
	int width;//������ �������
	int depth;//������� �������
	char type[SIZE];
public:

	reservoir(char* name_p, int length_p, int width_p, int depth_p, const char* type_p);//������� �����������

	reservoir() : reservoir(nullptr, 0, 0, 0, "\0") {};

	reservoir(const reservoir& reservoir_p);//����������� �����������

	//explicit Date(int day_p) : Date(day_p, 1, 2000, nullptr) {}
	explicit reservoir(int length_p) : reservoir(nullptr, length_p, 0, 0, "\0") {}//explicit �����������

	//��������� � ������������
	void set_name(const char* name_p);

	void set_type(const char* type_p)
	{
		strcpy_s(type, strlen(type_p) + 1, type_p);
	}

	void set_length(int length_p)
	{
		length = length_p;
	}

	void set_width(int width_p)
	{
		width = width_p;
	}

	void set_depth(int depth_p)
	{
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

	void print() const;//���������� ������ � ���������� � ���

	//������ ������
	void volume() const //���������� ����� �������
	{
		cout << "\n����� ������� ������� " << depth * length * width;
	}

	void square() const //���������� ������� �������
	{
		cout << "\n ������� ������� " << length * width;
	}

	~reservoir()//����������
	{
		delete[] name;
	}
};

