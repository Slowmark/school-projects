#include <cmath>
#include <string>
#include <iostream>

using namespace std;

int N;

void fillArray(string arr[])
{
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
}

void findPercentages(float arr1[], string arr2[])
{
    for (int i = 0; i < N; i++)
    {
        int counter = 0;
        for (int j = 0; j < N; j++)
        {
            if (arr2[i] == arr2[j])
            {
                counter++;
            }
        }
        arr1[i] = round(100.0 * counter / N);
    }
}

void sortArrays(float arr1[], string arr2[])
{
    float temp1;
    string temp2;

    bool sorted;
    do
    {
        sorted = true;
        for (int i = 0; i < N - 1; i++)
        {
            if (arr2[i][0] > arr2[i+1][0])
            {
                temp2 = arr2[i];
                arr2[i] = arr2[i+1];
                arr2[i+1] = temp2;

                temp1 = arr1[i];
                arr1[i] = arr1[i+1];
                arr1[i+1] = temp1;

                sorted = false;
            }
            else if (arr2[i][0] == arr2[i+1][0])
            {
                int j = 1;
                bool flag = false;
                while (arr2[i][j] == arr2[i+1][j] && j < arr2[i].size() && j < arr2[i+1].size())
                {
                    j++;
                }

                if (arr2[i][j] > arr2[i+1][j] && j < arr2[i].size() && j < arr2[i+1].size())
                {
                    flag = true;
                }

                if (flag)
                {
                    temp2 = arr2[i];
                    arr2[i] = arr2[i+1];
                    arr2[i+1] = temp2;

                    temp1 = arr1[i];
                    arr1[i] = arr1[i+1];
                    arr1[i+1] = temp1;

                    sorted = false;                    
                }
            }
        }
    }
    while (!sorted);
}

void printArrays(float arr1[], string arr2[])
{
    for (int i = 0; i < N; i++)
    {
        bool flag = false;
        for (int j = 0; j < i; j++)
        {
            if (arr2[i] == arr2[j])
            {
                flag = true;
            }
        }
        if (!flag)
        {
            cout << arr2[i] << ' ' << arr1[i] << '%' <<  endl;
        }
    }
}

int main()
{
    cin >> N;

    string names[N];
    fillArray(names);
    
    float percentages[N];
    findPercentages(percentages, names);

    sortArrays(percentages, names);
    printArrays(percentages, names);
    return 0;
}
