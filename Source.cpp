#include "Header.h"


int main()
{
	setlocale(LC_ALL, "rus");

	int user, index, index_2, size = 0;//size - рахмер массива объектов reserviors

	reservoir* reserviors = nullptr;

	enum menu { ADD = 1, DELETE, PRINT, VOLUME, SQUARE, COMPARASION_TYPE, COMPARASION_SQUARE, COPY_OBJ, ADD_FILE };

	do
	{
		try
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
			case COMPARASION_TYPE://проверяет, относятся ли водоемы к одному типу
				cout << "\nвведите индексы водоемов, тип которых вы хотите сравнить\n";
				cin >> index >> index_2;
				reserviors[index].comp_type(reserviors[index_2]);
				break;
			case COMPARASION_SQUARE://сравнивает площади водоемов
				cout << "\nвведите индексы водоемов, площадь которых вы хотите сравнить\n";
				cin >> index >> index_2;
				reserviors[index].comp_square(reserviors[index_2]);
				break;
			case COPY_OBJ:
				reserviors = add_copy(reserviors, size);//в массив добавляется копия объекта
				break;
			case ADD_FILE:
				add_file(reserviors, size);
				break;
			default:
				break;
			}
		}
		catch (const negative_number& num)
		{
			cout << num.what();
		}
		catch (const error_with_file& file)
		{
			cout << file.what();
		}
		catch (const delete_error& del)
		{
			cout << del.what();
		}
		catch (...)
		{
			cout << "\nerror\n";
		}

	} while (user != 0);

	return 0;
}