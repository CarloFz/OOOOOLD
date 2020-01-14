#include "header.h"


int main(int argc, char** argv)
{
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
	return 0;
}