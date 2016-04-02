#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <string.h>
#include <ctime>
#include <io.h>



using namespace std;

int main()
{
    srand(time(0));
    int defaultOutput = dup(1);
    for (int currentExp = 6; currentExp <= 16; currentExp++)
    {
        char testFileIndex[2];
        char testFileNameBegin[] = "../lab1TestFiles/testSort";
        char testFileType[] = ".txt";
        char testFileName[50];
        strcat(strcat(strcpy(testFileName, testFileNameBegin), itoa(currentExp, testFileIndex, 10)), testFileType);
        cout << testFileName << " generation began..." << endl;
        freopen(testFileName, "w+", stdout);
        double numAmount = pow(2, currentExp);

        for (int j = 0; j < numAmount; j++)
        {
             cout << rand() % 20000 - 10000 << " ";
        }
        fflush(stdout);
        dup2(defaultOutput, 1);
        cout << testFileName << " ready" << endl;


    }
    return 0;
}
