#include <iostream>

using namespace std;

bool checkArraySorted(int* a, int n) {
    if (n == 1)  
        return true;  
    if (a[n-2]>a[n-1])
    return false;
    return checkArraySorted(a, n-1);
}

int main(){
    int* a;
    int n;
    cin>>n;
    a=new int[n];
    for (int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    if (checkArraySorted(a, n))
    {
        cout<<"True";
    }
    else
    {
        cout<<"False";
    }
    delete[]a;
    return 0;
}