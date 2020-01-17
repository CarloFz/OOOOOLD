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

void swapChar(char* a, char* b);//����ĳ�����ַ���λ��
void write(char* buf[], int buflen, bool fin);//�����������д���ļ�

void initPossibleSet(int matrix[9][9], vector<int> possibleSet[9][9]);
void updatePossibleSet(int matrix[9][9], vector<int> possibleSet[9][9], int row, int col);
void checkPossibleSet(int matrix[9][9], vector<int> possibleSet[9][9]);
bool checkTrue(int matrix[9][9]);
bool backTrace(int row, int col, int matrix[9][9], vector<int> possibleSet[9][9], int nextPos[9][9][2]);