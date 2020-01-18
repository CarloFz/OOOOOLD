#pragma once
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <ctime>
#include <vector>
using namespace std;
#define MAX_CREATE 1000000
#define MAX_BUFLEN 10000
#define CREATE_FILENAME "./createSudoku.txt"
#define SOLVE_FILENAME "./solveSudoku.txt"


int inputProcess(int argc, char** argv);
int create(int count);
int solve(char *path);

void swapChar(char* a, char* b);//交换某两个字符的位置
void write(char* buf[], int buflen, bool fin);//将缓冲的内容写入文件

void initPossibleSet(int matrix[9][9], vector<int> possibleSet[9][9]);//初始化所有位置的可能的答案的集合
void updatePossibleSet(int matrix[9][9], vector<int> possibleSet[9][9], int row, int col);//更新某一个位置的可能的答案的集合
void checkPossibleSet(int matrix[9][9], vector<int> possibleSet[9][9]);//检查是否有能够唯一确定的空位
bool checkTrue(int matrix[9][9]);//检查数独解是否正确（DEBUG用）
bool backTrace(int row, int col, int matrix[9][9], vector<int> possibleSet[9][9], int nextPos[9][9][2]);//回溯法求解数独