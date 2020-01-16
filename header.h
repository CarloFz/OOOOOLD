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

int inputProcess(int argc, char** argv);
int create(int count);
int solve(char *path);

void swapChar(char* a, char* b);
void write(char* buf[], int buflen);

void initPossibleSet(int matrix[9][9], vector<int> possibleSet[9][9]);
void updatePossibleSet(int matrix[9][9], vector<int> possibleSet[9][9], int row, int col);
bool checkPossibleSet(int matrix[9][9], vector<int> possibleSet[9][9]);