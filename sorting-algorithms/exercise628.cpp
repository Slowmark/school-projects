#include <iostream>

using namespace std;

void fillArray(int size, char arr[])
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

void sortArray(int size, char arr[])
{
    char temp;
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
    int N;
    cin >> N;
    char A[N];
    fillArray(N, A);
    sortArray(N, A);

    int Q;
    cin >> Q;
    char B[Q];
    fillArray(Q, B);

    for (int i = 0; i < Q; i++)
    {
        int counter = 0;
        while (B[i] != A[counter])
        {
            counter++;
        } 
        cout << counter << endl;
    }
    return 0;
}
