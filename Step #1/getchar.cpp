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