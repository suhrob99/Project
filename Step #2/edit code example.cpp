case 1:
			{
				printf("enter name\n");

				fseek(fp, (nom - 1) * sizeof(my), SEEK_SET);
				fread(&vs, sizeof(vs), 1, fp);
				scanf_s("%s", vs.name, 20);
				fseek(fp, (nom - 1) * sizeof(my), SEEK_SET);
				fwrite(&vs, sizeof(vs), 1, fp);
				break;
			}

			case 2:
			{
				printf("enter surname\n");
				scanf_s("%s", surname, 20);
				fseek(fp, (nom - 1) * sizeof(my) + sizeof(surname), SEEK_SET);
				fwrite(surname, sizeof(surname), 1, fp);
				break;
			}

			case 3:
			{
				printf("enter phone\n");
				scanf_s("%d", &phone);
				fseek(fp, (nom - 1) * sizeof(my) + 2 * sizeof(surname), SEEK_SET);
				fwrite(&phone, sizeof(phone), 1, fp);
				break;