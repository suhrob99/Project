int sravn(char *ps1, char *ps2)
{
	int i = 0; int d = 0;

	while ((*ps1 != '\0') || (*ps2 != '\0')) //Цикл от начала строки до конца.В конце строки-нулевой символ.
	{
		if (*ps1 > *ps2) return 1;
		else
			if (*ps1 < *ps2) return 2;
		ps1++;
		ps2++;
	}
	return 0;
}