#include "header.h"
void swapChar(char* a, char* b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

void write(char* buf[], int buflen)
{
	FILE* p = NULL;
	fopen_s(&p, "./test.txt", "a+");
	for (int i = 0; i < buflen; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			for (int k = 0; k < 9; k++)
			{
				fwrite(&buf[i][j * 9 + k], sizeof(char), 1, p);
				if (k != 8) {
					fprintf(p, " ");
				}
				else {
					fprintf(p, "\n");
				}
			}
		}
		free(buf[i]);
	}
	fclose(p);
}
int create(int count)
{
	char* buf[MAX_BUFLEN];
	int buflen = 0;
	int countRes = 0;
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
							//////
							
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
												for (pos[6] = 0; pos[6] < 3; pos[6]++)
												{
													for (pos[7] = 0; pos[7] < 2; pos[7]++)
													{
														for (pos[8] = 0; pos[8] < 1; pos[8]++)
														{
															//计算排列
															index[pos[1]] = 1;
															for (int i = 2; i <= 8; i++) {
																int countPos = 0;
																for (int j = 0; j < 8; j++)
																{
																	if (index[j] == -1)
																	{
																		countPos++;
																	}
																	if (countPos - 1 == pos[i]) {
																		index[j] = i + 1;
																		break;
																	}
																}
															}
															char* end = (char*)malloc(sizeof(char) * 81);
															for (int i = 0; i < 9; i++)
															{
																for (int j = 0; j < 9; j++) {
																	if (matrix[i][j] == 'a') {
																		end[i * 9 + j] = '2';
																	}
																	else {
																		end[i * 9 + j] = index[matrix[i][j] - 'a' - 1] + '1' - 1;
																	}
																}
															}
															buf[buflen++] = end;
															countRes++;
															if (buflen >= MAX_BUFLEN) {
																write(buf, buflen);
																buflen = 0;
															}
															if (countRes == count) {
																if (buflen != 0) {
																	write(buf, buflen);
																}
																return 0;
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
							//////
						}
					}
				}
			}
		}
	}


	return 0;
}