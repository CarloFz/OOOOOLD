#include "header.h"


int main(int argc, char** argv)
{
	//���봦��
	int type = inputProcess(argc, argv);
	if (type == -1)
	{
		cout << "������������������" << endl;
		return 0;
	}
	//������
	if (type == 1)
	{
		int count = atoi(argv[2]);
		create(count);
	}
	else if (type == 2)
	{
		solve(argv[2]);
	}
	return 0;
}