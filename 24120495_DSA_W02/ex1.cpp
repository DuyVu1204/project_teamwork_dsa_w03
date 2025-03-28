#include <iostream>

using namespace std;

int LinearSearch(int *a, int n, int k)
{
    for (int i = 0; i < n; i++)//Iterate through the entire array
    {
        if (a[i] == k)//Check if element a[i] equals target
            return i;
    }
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
    cout << LinearSearch(a, n, k);
    delete[] a;
    return 0;
}