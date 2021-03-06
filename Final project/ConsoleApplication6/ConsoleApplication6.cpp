//База данных - набор сведений, хранящихся некоторым упорядоченным способом.
//Каждый раз, когда вы что-то ищете в поисковике, вы используете базу данных.
//Когда вы вводите свои логин и пароль для входа на какой-нибудь сервис,
//они сравниваются со значениями, которые хранятся в базе данных этого сервиса


/* Мой проект представляет собой СУБД людей,
внесших огромный вклад в развитие общества и науки в целом*/


#include "stdafx.h"  // Стандартные заголовочные файлы
#include <iostream>  // Поток ввода-вывода
using namespace std; // Открывает пространство имен библиотеки iostream
FILE *fp, *temp;  //Работа с файлами
int i, ch, phone, t, nom, vib, h;   // ch - для меню функций СУБД,vib - "плюсовые" возможности редактирования
char surname[20], name[20], sfera[20], x;
int N; // Количество элементов в Базе Данных
int sravn(char *ps1, char *ps2);   // Функция поиска элементов(по методу сравнения)

struct my          // Задаем через структуру  данные элементов(4 типа)
{
	char name[20];
	char surname[20];
	char sfera[30];
	int phone;
}

My = { "Bill", "Gates","<Microsoft>", 48917579 },
My2 = { "Isaac", "Newton","<Physics>", 3260078 },
My3 = { "Henry", "Ford","<Cars>", 6540498 },
My4 = { "Leonardo", "da Vinci","<Universal Genius>", 5820648 },
My5 = { "Sigmund", "Freud","<Psychology>", 98220423 },
My6 = { "Steve", "Jobs","<Changed the world>", 4890052 },
My7 = { "Albert", "Einstein","<Physics>", 86264694 },
My8 = { "Erich-Maria", "Remarque","<Writer>", 60032659 },
My9 = { "Winston", "Churchill","<Politician>", 4891579 },
My10 = { "Mahatma", "Gandhi","<Indian activist>", 9440059 },
My11 = { "Louis", "Pasteur","<Biologist>", 10291779 },
My12 = { "Fidel", "Castro","<Revolutionary >", 38917579 },
vs;   // Префикс для структуры(использовали для вывода в консоли)

int main()
{
	setlocale(LC_ALL, "Russian");  // Работа с кириллицей
	
	fopen_s(&fp, "bd.txt", "r+");
	// _s это фишка Microsoft,работаем с текстовым файлом
	// который создан заранее,r+ для чтения и записи файла

	fseek(fp, 0, SEEK_END);
	// Функция fseek перемещает указатель позиции в потоке.
	// В нашем случае позиция изменяется на 0 байт относительно конца файла

	fwrite(&My, sizeof(my), 1, fp); //fwrite записывает массив в наш исходный файл
	fwrite(&My2, sizeof(my), 1, fp);
	fwrite(&My3, sizeof(my), 1, fp);
	fwrite(&My4, sizeof(my), 1, fp);
	fwrite(&My5, sizeof(my), 1, fp);
	fwrite(&My6, sizeof(my), 1, fp);
	fwrite(&My7, sizeof(my), 1, fp);
	fwrite(&My8, sizeof(my), 1, fp);
	fwrite(&My9, sizeof(my), 1, fp);
	fwrite(&My10, sizeof(my), 1, fp);
	fwrite(&My11, sizeof(my), 1, fp);
	fwrite(&My12, sizeof(my), 1, fp);
	fclose(fp);  // Закрываем поток,открытый ранее fopen

	do // Сначала выполняется тело цикла, а потом проверяется условие(while в конце)
	{
		printf("1 - Создать базу данных \n");
		printf("2 - Показать базу данных \n");
		printf("3 - Добавить элементы в базу \n");
		printf("4 - Найти по фильтрам \n");
		printf("5 - Изменить элемент \n");
		printf("6 - Удалить элемент \n");
		printf("7 - Выйти из программы \n");
		printf("Введите желаемую операцию:");


		scanf_s("%d", &ch); //Считываем вводимую информацию
		switch (ch)
		{
		case 1:
		{
			// Создать новый список,"w" пустой файл для записи
			fopen_s(&fp, "bd.txt", "w");
			fclose(fp);
		}

		case 2:
			// Показать БД 
		{
			fopen_s(&fp, "bd.txt", "r"); // "r" для чтения
			printf("\n");
			printf("*Имя* *Фамилия* *Сфера деятельности* *Телефон*\n");
			while ((x = fgetc(fp)) != EOF) // Пока считываемые символы в источнике не закончатся
			{
				ungetc(x, fp); // Возвращаем считанный символ x в поток ввода
				fread(&vs, sizeof(my), 1, fp);  // Считываем массив элементов из файла
				printf("%s %s %s %d \n", vs.name, vs.surname, vs.sfera, vs.phone); //Показываем БД
			}
			printf("\n");
			fclose(fp); // Каждый раз закрываем поток
			break;  // И выходим из цикла while
		}

		case 3:
		{
			// Добавить какой-нибудь элемент в БД
			fopen_s(&fp, "bd.txt", "r+"); //Режим открытия файла для обновления чтения и записи
			fseek(fp, 0, SEEK_END);  // Относительно конца на 0 байт смещаем
			printf("Введите имя:");
			scanf_s("%s", vs.name, 20);
			printf("Введите фамилию:");
			scanf_s("%s", vs.surname, 20);
			printf("Введите сферу деятельности:");
			scanf_s("%s", vs.sfera, 20);
			printf("Введите телефон:");
			scanf_s("%d", &vs.phone);
			fwrite(&vs, sizeof(my), 1, fp); //Записываем в файл содержимое буфера
			fclose(fp); // Закрываем поток
			break;  // Выходим с этой зоны
		}

		case 4:
		{
			// Поиск по фильтрам
			fopen_s(&fp, "bd.txt", "r");
			t = 0;  //Используем переменную для случая,если поиск не даст результатов
			printf("1 - Искать по имени\n2 - Искать по фамилии\n3 - Искать по номеру телефона\n");
			scanf_s("%d", &vib);
			switch (vib)
			{
			case 1:
			{
				printf("Введите имя: ");
				scanf_s("%s", name, 20);
				while ((x = fgetc(fp)) != EOF)  // Пока считываемые символы в источнике не закончатся
				{
					ungetc(x, fp);  // Возвращаем считанный символ x в поток ввода
					fread(&vs, sizeof(my), 1, fp); // Считываем массив элементов из файла
					if (sravn(vs.name, name) == 0)  
					// Если имя,введенное в консоль совпадет с именами в БД
					// то выводится элемент со всеми данными
					{
						printf("Результат поиска:\n");
						printf("%s %s %s %d\n", vs.name, vs.surname, vs.sfera, vs.phone);
						t = 1;
						break;
					}
				}
				if (t == 0) printf("Совпадений не найдено\n");
				break;
			}

			case 2:
			{
				printf("Введите фамилию: ");
				scanf_s("%s", surname, 20);
				while ((x = fgetc(fp)) != EOF)
				{
					ungetc(x, fp);
					fread(&vs, sizeof(my), 1, fp);
					if (sravn(vs.surname, surname) == 0)
					{
						printf("Результат поиска:\n");
						printf("%s %s %s %d\n", vs.name, vs.surname, vs.sfera, vs.phone);
						t = 1;
						break;
					}
				}
				if (t == 0) printf("Совпадений не найдено\n");
				break;
			}

			case 3:
			{
				printf("Введите номер телефона: ");
				scanf_s("%d", &phone);
				while ((x = fgetc(fp)) != EOF)
				{
					ungetc(x, fp);
					fread(&vs, sizeof(my), 1, fp);
					if (vs.phone == phone)
					{
						printf("Результат поиска:\n");
						printf("%s %s %s %d\n", vs.name, vs.surname, vs.sfera, vs.phone);
						t = 1;
					}
				}
				if (t == 0) printf("Совпадений не найдено\n");
				break;
			}
			}

			fclose(fp);
			break;
		}

		case 5:
		{
			//Редактирование элементов 
			fopen_s(&fp, "bd.txt", "r+");
			printf("Введите номер элемента:");
			scanf_s("%d", &nom);

			printf("1 - Имя\n2 - Фамилия\n3 - Телефон\n");
			scanf_s("%d", &vib);
			switch (vib)
			{
			case 1:
			{
				printf("Смена старого имени на: \n");

				fseek(fp, (nom - 1) * sizeof(my), SEEK_SET); // Смещение массивов относительно начала файла
				fread(&vs, sizeof(vs), 1, fp); // Считываем из файла массив элементов вводимых 
				scanf_s("%s", vs.name, 20);
				fseek(fp, (nom - 1) * sizeof(my), SEEK_SET); // В этой части уже вносим изменения буфера в файл
				fwrite(&vs, sizeof(vs), 1, fp);
				break;
			}

			case 2:
			{
				// Почти та же схема действий,немного меняем смещение в байтах
				printf("Смена старой фамилии на: \n");
				scanf_s("%s", surname, 20);
				fseek(fp, (nom - 1) * sizeof(my) + sizeof(surname), SEEK_SET);
				fwrite(surname, sizeof(surname), 1, fp);
				break;
			}

			case 3:
			{
				printf("Смена старого номера на: \n");
				scanf_s("%d", &phone);
				fseek(fp, (nom - 1) * sizeof(my) + 2 * sizeof(surname), SEEK_SET);
				fwrite(&phone, sizeof(phone), 1, fp);
				break;
			}
			}

			fclose(fp);
			break;
		}


		case 6:
		{
			// Удаление элементов из БД
			fopen_s(&fp, "bd.txt", "r+");
			N = 0;
			while ((x = fgetc(fp)) != EOF) // Пока считываемые символы в источнике не закончатся
			{
				ungetc(x, fp);   // Возвращаем считанный символ x в поток ввода
				fread(&vs, sizeof(my), 1, fp);
				N++;  // В таких условиях увеличиваем на +1
			}


			printf("Всего элементов в Базе Данных- %d\n", N);
			fseek(fp, (N - 1) * sizeof(my), SEEK_SET);
			fread(&vs, sizeof(my), 1, fp);

			printf("Введите номер удаляемого элемента:");
			scanf_s("%d", &nom);
			fseek(fp, (nom - 1) * sizeof(my), SEEK_SET);
			fwrite(&vs, sizeof(my), 1, fp);



			fopen_s(&temp, "bd1.txt", "w+"); // Работа с уже другим пустым файлом для записи*чтения 

			rewind(fp); // установили внутренний указатель файла в начало файла fp

			for (i = 0; i < N - 1; i++)  // Считываем с fp файла,и заносим в файл temp массивы элементов
			{

				fread(&vs, sizeof(my), 1, fp);
				fwrite(&vs, sizeof(my), 1, temp);
			}

			//Закрыли оба потока
			fclose(temp); 
			fclose(fp);

			// Если файлы будут пустые,то пропишем ошибки 
			fopen_s(&fp, "bd.txt", "w+"); fopen_s(&temp, "bd1.txt", "r+");
			if (fp == NULL)printf("error");
			if (temp == NULL)printf("error1");


			// В этом случае нам придется считывать с temp файла,а массивы данных заносить в fp файл
			for (i = 0; i < N - 1; i++) // В этом случае нам придется считать с
			{

				fread(&vs, sizeof(my), 1, temp);
				fwrite(&vs, sizeof(my), 1, fp);
			}

			fclose(fp);
			break;

			// Закрываем все открытые потоки
		}
		}

	} while (ch != 7);

	// В остальных случаях программа закрывается
	return 0;
}

int sravn(char *ps1, char *ps2)   // Функция сравнения,которую использовали в начале.Нужна для работы со строками.
{
	int i = 0; int d = 0;

	while ((*ps1 != '\0') || (*ps2 != '\0')) //Пока у строки не будет конца,то выполняем
	{
		if (*ps1 > *ps2) return 1;
		else
			if (*ps1 < *ps2) return 2;
		ps1++;
		ps2++;
	}
	return 0;
}