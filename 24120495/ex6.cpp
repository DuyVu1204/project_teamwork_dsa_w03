#include <iostream>

using namespace std;

bool CheckSumTarget(int *a, int n, int target)
{
    for (int i = 0; i < n - 1; i++)
    {
        int sum = a[i];
        for (int j = i + 1; j < n; j++)
        {
            sum += a[j];
            if (sum == target)
            {
                return true;
                break;
            }
            else
                sum = a[i];
        }
    }
    return false;
}

bool checksum2(int *a, int n, int target)
{
    int i = 0, j = n - 1;
    int sum = 0;
    while (i != j)
    {
        sum = a[i] + a[j];
        if (sum == target)
        {
            return true;
            break;
        }
        else if (sum < target)
            ++i;
        else
            --j;
    }
    return false;
}

int main()
{
    int *a, n, target;
    cin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> target;
    if (!CheckSumTarget(a, n, target))
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    delete[] a;
    return 0;
}