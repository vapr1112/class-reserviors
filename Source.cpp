#include "Header.h"

int main()
{
	setlocale(LC_ALL, "rus");

	int user, index, index_2, size = 0;//size - рахмер массива объектов reserviors

	reservoir* reserviors = nullptr;

	enum menu { ADD = 1, DELETE, PRINT, VOLUME, SQUARE, COMPARASION_TYPE, COMPARASION_SQUARE, COPY_OBJ, ADD_FILE };

	do
	{
		cout << "\nвведите \n1 добавить водоем \n2 удалить водоем \n3 показать водоемы \n4 объем водоема \n5 площадь водоема \n6 сравнение типов водоемов \n7 сравнение площадей \n8 копирование водоема \n9 добавление в файл\n";

		cin >> user;

		switch (user)
		{
		case ADD:
			reserviors = adding(reserviors, size);
			break;
		case DELETE:
			reserviors = deleting(reserviors, size);
			break;
		case PRINT://показывает все водоемы и информацию о них
			for (int i = 0; i < size; i++)
			{
				reserviors[i].print();
			}
			break;
		case VOLUME://показывает объем водоема
			cout << "\nвведите индекс водоема\n";
			cin >> index;
			reserviors[index].volume();
			break;
		case SQUARE://показывает площадь водоема
			cout << "\nвведите индекс водоема\n";
			cin >> index;
			reserviors[index].square();
			break;
		case COMPARASION_TYPE:
			cout << "\nвведите индексы водоемов, тип которых вы хотите сравнить\n";
			cin >> index >> index_2;
			reserviors[index].comp_type(reserviors[index_2]);
			break;
		case COMPARASION_SQUARE:
			cout << "\nвведите индексы водоемов, площадь которых вы хотите сравнить\n";
			cin >> index >> index_2;
			reserviors[index].comp_square(reserviors[index_2]);
			break;
		default:
			break;
		}
	} while (user != 0);

	return 0;
}