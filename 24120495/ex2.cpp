#include <iostream>

using namespace std;

int LinearSearchWithSentinel(int *a, int n, int k)
{
    if (a[n - 1] == k)
        return n - 1;
    int last = a[n - 1];
    a[n - 1] = k;
    int i = 0;
    while (a[i] != k)
        i++;
    a[n - 1] = last;
    if (i < n - 1)
        return i;
    else
        return -1;
}

int main()
{
    int *a, n, k;
    cin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> k;
    cout << LinearSearchWithSentinel(a, n, k);
    delete[] a;
    return 0;
}