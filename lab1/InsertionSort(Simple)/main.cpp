#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string.h>
#include <ctime>
#include <fstream>

#include <io.h>

using namespace std;

void bubbleSort(int *v, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
        }
    }
 }

int binSearch(int *v, int x, int l, int r)
{
    int mid;
    while(l <= r)
    {
        mid = (l + r) / 2;
        if(x < v[mid])
            r = mid - 1;
        else
                l = mid + 1;
    }
    return l;
}

void insertionSortBin(int *v, int n)
{
    int k, pos, i, curr;

    for(i = 1; i < n; i++)
    {
        if (v[i - 1] > v[i])
        {
            curr = v[i];
            pos = binSearch(&v[0], v[i], 0, i);
            for(k = i - 1; k >= pos; k--)
                v[k + 1] = v[k];
            v[pos] = curr;
        }
    }
}

void insertionSort(int *v, int n)
{
    int i, j;
    for(i = 1; i < n; i++)
    {
        j = i - 1; // i = j + 1; ищем место для элемента v[i]
        while((j >= 0) && (v[j] > v[j + 1]))
        {
            swap(v[j], v[j + 1]);
            j--;
        }
    }
}

void selectSort(int *v, int n)
{
    int i, j, indMin;
    for(i = 0; i < n - 1; i++)
    {
        indMin = i; // k - индекс наименьшего элемента в неотсортированном массиве
        for(j = i + 1; j < n; j++)	// цикл выбора наименьшего элемента в неотсортированном моссиве
            if(v[j] < v[indMin])
                indMin = j;
        swap(v[i], v[indMin]);
    }
}

int main()
{
    for (int currentExp = 6; currentExp < 17; currentExp++)
    {
        char testFileIndex[2];
        char testFileNameBegin[] = "../lab1TestFiles/testSort";
        char testFileType[] = ".txt";
        char testFileName[50];
        strcat(strcat(strcpy(testFileName, testFileNameBegin), itoa(currentExp, testFileIndex, 10)), testFileType);
        cout << testFileName << " Sort began..." << endl;

        char resultFileName[50];
        char resultFileNameBegin[] = "../lab1ResultFiles/resultSort";
        strcat(strcat(strcpy(resultFileName, resultFileNameBegin), itoa(currentExp, testFileIndex, 10)), testFileType);

        ifstream fileInStream;
        fileInStream.open(testFileName);

        ofstream fileOutStream;
        fileOutStream.open(resultFileName);

        vector<int> vOrigin;

        int buffer, i;

        while(fileInStream >> buffer)
            vOrigin.push_back(buffer);


        int vectorSize = vOrigin.size();

        vector<int> vForSort;

        unsigned int startTime, endTime;

        vForSort = vOrigin;
        cout << "Executing time: \n";
        fileOutStream << "Executing time: \n";

        startTime = clock();
        bubbleSort(&vForSort[0], vectorSize);
        endTime = clock();
        cout << "Bubble Sort: " << (endTime - startTime) / 1000.0 << endl;
        fileOutStream << "Bubble Sort: " << (endTime - startTime) / 1000.0 << endl;

        vForSort = vOrigin;
        startTime = clock();
        insertionSort(&vForSort[0], vectorSize);
        endTime = clock();
        cout << "Insertion Sort: " << (endTime - startTime) / 1000.0 << endl;
        fileOutStream << "Insertion Sort: " << (endTime - startTime) / 1000.0 << endl;

        vForSort = vOrigin;
        startTime = clock();
        insertionSortBin(&vForSort[0], vectorSize);
        endTime = clock();
        cout << "Insertion Binary Sort: " << (endTime - startTime) / 1000.0 << endl;
        fileOutStream << "Insertion Binary Sort: " << (endTime - startTime) / 1000.0 << endl;

        vForSort = vOrigin;
        startTime = clock();
        selectSort(&vForSort[0], vectorSize);
        endTime = clock();
        cout << "Selection Sort: " << (endTime - startTime) / 1000.0 << endl;
        fileOutStream << "Selection Sort: " << (endTime - startTime) / 1000.0 << endl;

        for(i = 0; i < vectorSize; i++)
            fileOutStream << vForSort[i] << ' ';

        fileInStream.close();
        fileOutStream.close();

        cout << testFileName << " sorted.\nResult: " << resultFileName << endl << endl;
    }

    return 0;
}
