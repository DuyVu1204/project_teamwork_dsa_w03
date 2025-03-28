#include <iostream> 

using namespace std;

int findMin(int* a, int n) {
    int l=0, r=n-1;
    while (l<r)
    {
        int m=(l+r)/2;
        if (a[m]>a[r])
        l=m+1;
        else
        r=m;
    }
    return a[l];
}

int main(){
    int* a, n;
    cin>>n;
    a=new int[n];
    for (int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cout<<findMin(a, n);
    delete[]a;
    return 0;
}