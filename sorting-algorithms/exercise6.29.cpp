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

                sorted = true;
            }
        }
    }
    while (!sorted);
}

int main()
{
    int N;
    cin >> N;
    int A[N];
    fillArray(N, A);
    sortArray(N, A);

    int M;
    cin >> M;
    int B[M];
    fillArray(M, B);
    sortArray(M, B);

    int sum = 0;
    int counter = 0;

    int q = -1;
    for (int i = 0; i < N; i++)
    {
        bool flag = false;
        for (int j = q + 1; j < M; j++)
        {
            if (A[i] <= B[j] && !flag)
            {
                q = j;
                counter++;
                flag = true;
            }
        }
        if (flag)
        {
            sum += B[q];
        }
    }
    if (counter == N)
    {
        cout << sum;
    }
    else
    {
        cout << -1;
    }
    return 0;
}
