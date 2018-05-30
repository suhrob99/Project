printf("1 - create bd \n");
		printf("2 - print bd \n");
		printf("3 - add record in bd\n");
		printf("4 - to find \n");
		printf("5 - to change record \n");
		printf("6 - to delete \n");
		printf("7 - to exit \n");
		printf("enter operation:");


		scanf_s("%d", &ch);
		switch (ch)
		{
		case 1:
		{
			fopen_s(&fp, "bd.txt", "w");
			fclose(fp);
		}

		case 2:
			//вывод БД 
		{
			fopen_s(&fp, "bd.txt", "r");
			printf("\n");
			printf("name: surname: phone:\n");
			while ((x = fgetc(fp)) != EOF)
			{
				ungetc(x, fp);
				fread(&vs, sizeof(my), 1, fp);
				printf("%s %s %d\n", vs.name, vs.surname, vs.phone);
			}
			printf("\n");
			fclose(fp);
			break;
		}