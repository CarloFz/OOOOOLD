#include "header.h"

int inputProcess(int argc, char** argv)
{
	//��֤��������
	if (argc != 3)
	{
		return -1;
	}
	//��֤��һ������-c/-s
	int type = 0; //-c = 1; -s = 2;
	if (strcmp(argv[1],"-c") == 0) {
		type = 1;
	}
	else if (strcmp(argv[1], "-s") == 0)
	{
		type = 2;
	}
	else {
		type = -1;//�������
	}
	if (type == -1)
	{
		return -1;
	}
	//��֤�ڶ�������
	if (type == 1)//-c
	{
		string countS = argv[2];
		for (unsigned int i = 0; i < countS.length(); i++)
		{
			if (countS[i] > '9' || countS[i] < '0')
			{
				return -1;
			}
		}
	}
	else if (type == 2) {//-s
		FILE* p = NULL;
		fopen_s(&p, argv[2], "r");
		if (p == NULL)
		{
			return -1;
		}
		fclose(p);
	}
	return type;
}