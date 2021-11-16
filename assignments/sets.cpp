#include <iostream>
using namespace std;

int main()
{
    int sizeA;
    cout << "How many elements in set A? ";
    cin >> sizeA;
    int A[sizeA];
    for (int i = 0; i < sizeA; i++)
    {
        cout << "A[" << i << "]:";
        cin >> A[i];
        for (int j = 0; j < i; j++)
            while (A[i] == A[j])
            {
                cout << "Try again A[" << i << "]:";
                cin >> A[i];
            }
    }
    cout << endl;
    int sizeB;
    cout << "How many elements in set B? ";
    cin >> sizeB;
    int B[sizeB];
    for (int i = 0; i < sizeB; i++)
    {
        cout << "B[" << i << "]:";
        cin >> B[i];
        for (int j = 0; j < i; j++)
            while (B[i] == B[j])
            {
                cout << "Try again B[" << i << "]:";
                cin >> B[i];
            }
    }
    cout << endl;
    int sizeC = 0;
    for (int i = 0; i < sizeA; i++)
        for (int j = 0; j < sizeB; j++)
            if (A[i] == B[j])
                sizeC++;
    int C[sizeC];
    int k = -1;
    for (int i = 0; i < sizeC; i++)
        for (int j = k + 1; j < sizeA; j++)
        {
            bool flag = false;
            for (int q = 0; q < sizeB; q++)
                if (A[j] == B[q])
                {   
                    k = j;
                    flag = true;
                    C[i] = A[j];
                }
            if (flag)
                break;
        }
    cout << "C={";
    for (int i = 0; i < sizeC; i++)
    {
        if (i != sizeC - 1)
            cout << C[i] << ',';
        else
            cout << C[i] << '}' << endl;
    }
    int sizeD = sizeA + sizeB - sizeC;
    int D[sizeD];
    for (int i = 0; i < sizeA; i++)
            D[i] = A[i];
    int z = -1;
    for (int i = sizeA; i < sizeD; i++)
        for (int j = z + 1; j < sizeB; j++)
        {
            bool flag = false;
            for (int q = 0; q < sizeC; q++)
                if (B[j] == C[q])
                    flag = true;
            if (!flag)
            {
                z = j;
                D[i] = B[j];
                break;
            }
        }
    cout << "D={";
    for (int i = 0; i < sizeD; i++)
    {
        if (i != sizeD - 1)
            cout << D[i] << ',';
        else
            cout << D[i] << '}' << endl;
    }
    int sizeE = sizeA - sizeC;
    int E[sizeE];
    int g = -1;
    for (int i = 0; i < sizeE; i++)
        for (int j = g + 1; i < sizeA; j++)
        {
            bool flag  = false;
            for (int q = 0; q < sizeC; q++)
                if (A[j] == C[q])
                    flag = true;
            if (!flag)
            {
                g = j;
                E[i] = A[j];
                break;
            }
        }
    cout << "E={";
    for (int i = 0; i < sizeE; i++)
    {
        if (i != sizeE - 1)
            cout << E[i] << ',';
        else
            cout << E[i] << '}' << endl;
    }
    int sizeF = sizeA + sizeB - 2 * sizeC;
    int F[sizeF];
    int p = -1;
    for (int i = 0; i < sizeA - sizeC; i++)
        for (int j = p + 1; i < sizeA; j++)
        {
            bool flag = false;
            for (int q = 0; q < sizeC; q++)
                if (A[j] == C[q])
                    flag = true;
            if (!flag)
            {
                p = j;
                F[i] = A[j];
                break;
            }
        }
    int b = -1;
    for (int i = sizeA - sizeC; i < sizeF; i++)
        for (int j = b + 1; j < sizeB; j++)
        {
            bool flag = false;
            for (int q = 0; q < sizeC; q++)
                if (B[j] == C[q])
                    flag = true;
            if (!flag)
            {
                b = j;
                F[i] = B[j];
                break;
            }
        }
    cout << "F={";
    for (int i = 0; i < sizeF; i++)
    {
        if (i != sizeF - 1)
            cout << F[i] << ',';
        else
            cout << F[i] << '}' << endl;
    }
    return 0;
}
