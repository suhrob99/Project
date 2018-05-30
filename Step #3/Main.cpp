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