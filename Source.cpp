#include "Header.h"

int main()
{
	setlocale(LC_ALL, "rus");

	int user, index, index_2, size = 0;//size - ������ ������� �������� reserviors

	reservoir* reserviors = nullptr;

	enum menu { ADD = 1, DELETE, PRINT, VOLUME, SQUARE, COMPARASION_TYPE, COMPARASION_SQUARE, COPY_OBJ, ADD_FILE };

	do
	{
		cout << "\n������� \n1 �������� ������ \n2 ������� ������ \n3 �������� ������� \n4 ����� ������� \n5 ������� ������� \n6 ��������� ����� �������� \n7 ��������� �������� \n8 ����������� ������� \n9 ���������� � ����\n";

		cin >> user;

		switch (user)
		{
		case ADD:
			reserviors = adding(reserviors, size);
			break;
		case DELETE:
			reserviors = deleting(reserviors, size);
			break;
		case PRINT://���������� ��� ������� � ���������� � ���
			for (int i = 0; i < size; i++)
			{
				reserviors[i].print();
			}
			break;
		case VOLUME://���������� ����� �������
			cout << "\n������� ������ �������\n";
			cin >> index;
			reserviors[index].volume();
			break;
		case SQUARE://���������� ������� �������
			cout << "\n������� ������ �������\n";
			cin >> index;
			reserviors[index].square();
			break;
		case COMPARASION_TYPE:
			cout << "\n������� ������� ��������, ��� ������� �� ������ ��������\n";
			cin >> index >> index_2;
			reserviors[index].comp_type(reserviors[index_2]);
			break;
		case COMPARASION_SQUARE:
			cout << "\n������� ������� ��������, ������� ������� �� ������ ��������\n";
			cin >> index >> index_2;
			reserviors[index].comp_square(reserviors[index_2]);
			break;
		default:
			break;
		}
	} while (user != 0);

	return 0;
}