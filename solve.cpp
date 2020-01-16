#include "header.h"
void initPossibleSet(int matrix[9][9], vector<int> possibleSet[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++) {
            updatePossibleSet(matrix, possibleSet, i, j);
        }
    }
}
void updatePossibleSet(int matrix[9][9], vector<int> possibleSet[9][9], int row, int col)
{
    possibleSet[row][col].clear();
    if (matrix[row][col] == 0)
    {
        int exist[9];
        memset(exist, 0, sizeof(exist));
        for (int k = 0; k < 9; k++)
        {
            if (matrix[row][k] != 0) {
                exist[matrix[row][k] - 1] = 1;
            }
            if (matrix[k][col] != 0) {
                exist[matrix[k][col] - 1] = 1;
            }
            if (matrix[row / 3 * 3 + k / 3][col / 3 * 3 + k % 3] != 0)
            {
                exist[matrix[row / 3 * 3 + k / 3][col / 3 * 3 + k % 3] - 1] = 1;
            }
        }
        for (int k = 0; k < 9; k++) {
            if (exist[k] == 0) {
                possibleSet[row][col].push_back(k + 1);
            }
        }
    }
}
bool checkPossibleSet(int matrix[9][9], vector<int> possibleSet[9][9])
{
    bool stepOut = true;
    bool res = false;
    while (stepOut)
    {
        stepOut = false;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++) {
                if (possibleSet[i][j].size() == 1) {
                    res = true;
                    stepOut = true;
                    matrix[i][j] = possibleSet[i][j][0];
                    possibleSet[i][j].clear();
                    for (int k = 0; k < 9; k++)
                    {
                        updatePossibleSet(matrix, possibleSet, i, k);
                        updatePossibleSet(matrix, possibleSet, k, j);
                        updatePossibleSet(matrix, possibleSet, i/3*3+k/3, j/3*3+k%3);
                    }
                }
            }
        }
    }
    return res;
}
bool checkTrue(int matrix[9][9])
{
    for (int i = 0; i < 9; i++) {
        int existR[9];
        int existC[9];
        int existB[9];
        memset(existR, 0, sizeof(existR));
        memset(existC, 0, sizeof(existC));
        memset(existB, 0, sizeof(existB));
        int baseR = 0, baseC = 0;
        switch (i)
        {
        case 0:
            baseR = 0; baseC = 0;
            break;
        case 1:
            baseR = 0; baseC = 3;
            break;
        case 2:
            baseR = 0; baseC = 6;
            break;
        case 3:
            baseR = 3; baseC = 0;
            break;
        case 4:
            baseR = 3; baseC = 3;
            break;
        case 5:
            baseR = 3; baseC = 6;
            break;
        case 6:
            baseR = 6; baseC = 0;
            break;
        case 7:
            baseR = 6; baseC = 3;
            break;
        case 8:
            baseR = 6; baseC = 6;
            break;
        default:
            break;
        }
        for (int j = 0; j < 9; j++) {
            if (matrix[i][j] <= 0 || matrix[i][j] >= 10 ||
                matrix[j][i] <= 0 || matrix[j][i] >= 10 ||
                matrix[baseR + j / 3][baseC + j % 3] <= 0 || matrix[baseR + j / 3][baseC + j % 3] >= 10)
            {
                return false;
            }
            if (existC[matrix[j][i] - 1] == 1 || existR[matrix[i][j] - 1] == 1 || existB[matrix[baseR + j / 3][baseC + j % 3] - 1] == 1) {
                return false;
            }
            else {
                existC[matrix[j][i] - 1] = 1;
                existR[matrix[i][j] - 1] = 1;
                existB[matrix[baseR + j / 3][baseC + j % 3] - 1] = 1;
            }
        }
    }
    return true;
}
bool backTrace(int row, int col, int matrix[9][9], vector<int> possibleSet[9][9], int nextPos[9][9][2]) {
    if (row == -1 && col == -1) {
        //已经成功了，打印数组即可
        return true;
    }
    updatePossibleSet(matrix, possibleSet, row, col);
    for (int k = 0; k < possibleSet[row][col].size(); k++) {
        //判断给i行j列放1-9中的任意一个数是否能满足规则
        //将该值赋给该空格，然后进入下一个空格
        matrix[row][col] = possibleSet[row][col][k];
        if (backTrace(nextPos[row][col][0], nextPos[row][col][1], matrix, possibleSet, nextPos))
        {
            return true;
        }
        //初始化该空格
        matrix[row][col] = 0;
    }
    return false;
}
int solve(char* path)
{
    //读文件
    clock_t start = clock();
    ifstream fin(path, std::ios::binary);
    int bufLen = static_cast<unsigned int>(fin.seekg(0, std::ios::end).tellg());
    vector<char> buf(bufLen);
    fin.seekg(0, std::ios::beg).read(&buf[0], static_cast<std::streamsize>(buf.size()));
    fin.close();

    int bufPoint = 0;
    while (bufPoint < bufLen)
    {
        //取出一个数独题目
        int matrix[9][9];
        vector<int> possibleSet[9][9];
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                matrix[i][j] = buf[bufPoint] - '0';
                bufPoint += 2;
                possibleSet[i][j].clear();
            }
        }
        //ini posSet
        initPossibleSet(matrix, possibleSet);
        checkPossibleSet(matrix, possibleSet);
        int nextPos[9][9][2];
        int startPos[2] = { -1, -1 };
        for (int i = 8; i >= 0; i--)
        {
            for (int j = 8; j >= 0; j--)
            {
                nextPos[i][j][0] = startPos[0];
                nextPos[i][j][1] = startPos[1];
                if (matrix[i][j] == 0) {
                    startPos[0] = i;
                    startPos[1] = j;
                }
            }
        }
        backTrace(startPos[0], startPos[1], matrix, possibleSet, nextPos);
        if (!checkTrue(matrix)) {
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    printf("%c", matrix[i][j] + '0');
                    if (j != 8)
                    {
                        printf(" ");
                    }
                }
                printf("\n");
            }
            printf("\n");
        }
        bufPoint++;
    }
    clock_t end = clock();
    cout << "time : " << ((double)end - start) / CLOCKS_PER_SEC << "s\n" << endl;
	return 0;
}