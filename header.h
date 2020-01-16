#pragma once
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;
#define MAX_CREATE 1000000
#define MAX_BUFLEN 10000

int inputProcess(int argc, char** argv);
int create(int count);
int solve(char *path);

void swapChar(char* a, char* b);
void write(char* buf[], int buflen);