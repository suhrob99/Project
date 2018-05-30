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

