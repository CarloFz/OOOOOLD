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
	if (argv[1] == "-c") {
		type = 1;
	}
	else if (argv[1] == "-s")
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
		for (int i = 0; i < countS.length; i++)
		{
			if (countS[i] > '9' || countS[i] < '0')
			{
				return -1;
			}
		}
	}
	else if (type == 2) {//-s
		FILE* p = NULL;
		p = fopen(argv[2], "r");
		if (p == NULL)
		{
			return -1;
		}
		fclose(p);
	}
	return type;
}