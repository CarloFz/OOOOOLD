#include "header.h"


int main(int argc, char** argv)
{
	clock_t start = clock();
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
	clock_t end = clock();
	cout << "time : " << ((double)end - start) / CLOCKS_PER_SEC << "s\n" << endl;
	return 0;
}