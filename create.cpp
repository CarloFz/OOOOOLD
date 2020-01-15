#include "header.h"
void swapChar(char* a, char* b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}
void arrange(char matrix[9][9])
{
	int index[8] = { -1,-1,-1,-1,-1,-1,-1,-1 };
	int pos[9];
	for (pos[1] = 0; pos[1] < 8; pos[1]++) 
	{
		for (pos[2] = 0; pos[2] < 7; pos[2]++)
		{
			for (pos[3] = 0; pos[3] < 6; pos[3]++)
			{
				for (pos[4] = 0; pos[4] < 5; pos[4]++)
				{
					for (pos[5] = 0; pos[5] < 4; pos[5]++)
					{
						for (pos[6] = 0; pos[6]< 3; pos[6]++)
						{
							for (pos[7] = 0; pos[7] < 2; pos[7]++)
							{
								for (pos[8] = 0; pos[8] < 1; pos[8]++)
								{
									//计算排列
									index[pos[1]] = 1;
									int count = 0;
									for (int i = 2; i <= 8; i++) {
										for (int j = 0; j < 8; j++)
										{
											if (index[j] == -1)
											{
												count++;
											}
											if (count - 1 == pos[i]) {
												index[j] = i + 1;
												count = 0;
												break;
											}
										}
									}
									for (int i = 0; i < 8; i++)
									{
										index[i] = -1;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
int create(int count)
{
	if (count > MAX_CREATE)
	{
		cout << "请求生成的数独终局过多" << endl;
		return 0;
	}
	//数独终局的原始模板，其他的终局在此基础上变化而成
	char sudoTemplate[10][10] = { "abcghidef",
								  "defabcghi",
								  "ghidefabc",
								  "bcahigefd",
								  "efdbcahig",
								  "higefdbca",
								  "cabighfde",
								  "fdecabigh",
								  "ighfdecab" };
	char matrix[9][9];
	int countRes = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			matrix[i][j] = sudoTemplate[i][j];
		}
	}
	//六层循环遍历每一种模板的交换情况
	//行
	for(int row1 = 0; row1 < 2; row1++)
	{
		//12行交换
		for (int i = 0; i < 9; i++)
		{
			swapChar(&matrix[1][i], &matrix[2][i]);
		}

		for (int row2 = 0; row2 < 6; row2++)
		{
			if (row2 % 2 == 0)
			{
				//34行交换
				for (int i = 0; i < 9; i++)
				{
					swapChar(&matrix[3][i], &matrix[4][i]);
				}
			}
			else {
				//45行交换
				for (int i = 0; i < 9; i++)
				{
					swapChar(&matrix[5][i], &matrix[4][i]);
				}
			}
			for (int row3 = 0; row3 < 6; row3++)
			{
				if (row3 % 2 == 0)
				{
					//67行交换
					for (int i = 0; i < 9; i++)
					{
						swapChar(&matrix[6][i], &matrix[7][i]);
					}
				}
				else {
					//78行交换
					for (int i = 0; i < 9; i++)
					{
						swapChar(&matrix[7][i], &matrix[8][i]);
					}
				}
				//列
				for (int col1 = 0; col1 < 2; col1++)
				{
					//12列交换
					for (int i = 0; i < 9; i++)
					{
						swapChar(&matrix[i][1], &matrix[i][2]);
					}
					for (int col2 = 0; col2 < 6; col2++)
					{
						if (col2 % 2 == 0)
						{
							//34列交换
							for (int i = 0; i < 9; i++)
							{
								swapChar(&matrix[i][3], &matrix[i][4]);
							}
						}
						else {
							//45列交换
							for (int i = 0; i < 9; i++)
							{
								swapChar(&matrix[i][4], &matrix[i][5]);
							}
						}
						for (int col3 = 0; col3 < 6; col3++)
						{
							if (col2 % 2 == 0)
							{
								//67列交换
								for (int i = 0; i < 9; i++)
								{
									swapChar(&matrix[i][6], &matrix[i][7]);
								}
							}
							else {
								//78列交换
								for (int i = 0; i < 9; i++)
								{
									swapChar(&matrix[i][7], &matrix[i][8]);
								}
							}
							arrange(matrix);
							countRes++;
						}
					}
				}
			}
		}
	}

	cout << countRes << endl;

	return 0;
}