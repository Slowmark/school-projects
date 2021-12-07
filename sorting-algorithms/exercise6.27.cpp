#include <iostream>

using namespace std;

void fillArray(int size, int arr[])
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

void sortArray(int size, int arr[])
{
    int temp;
    bool sorted;

    do
    {
        sorted = true;
        for (int i = 0; i < size - 1; i++)
        {
            if (arr[i] > arr[i+1])
            {
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;

                sorted = false;
            }
        }
    }
    while (!sorted);
}

int main()
{
    int B;
    int G;
    cin >> B;
    cin >> G;

    int A[B];
    int K[G];
    fillArray(B, A);
    fillArray(G, K);
    sortArray(B, A);
    sortArray(G, K);

    int counter = 0;

    int q = -1;
    for (int i = 0; i < B; i++)
    {
        bool flag = false;
        for (int j = q + 1; j < G; j++)
        {
            if (A[i] > K[j] && !flag)
            {
                q = j;
                flag = true;
            }
        }
        if (flag)
        {
            counter++;
        }
    }
    cout << counter;
    return 0;
}
