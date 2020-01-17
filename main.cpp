#include "header.h"


int main(int argc, char** argv)
{
	clock_t start = clock();
	//输入处理
	int type = inputProcess(argc, argv);
	if (type == -1)
	{
		cout << "参数错误，请重新输入" << endl;
		return 0;
	}
	//任务处理
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