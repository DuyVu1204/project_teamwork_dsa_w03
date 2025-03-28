#include <iostream>

using namespace std;

int minSubarraylen(int* a, int n, int target){
    int l=0;
    int sum=0;
    int len=n+1;
    for (int r=0; r<n; r++)
    {
        sum+=a[r];
        while (sum>=target)
        {
            if ((r-l+1)<len)
            {
                len=r-l+1;
            }
            sum-=a[l];
            l++;
        }
    }
    if (len==n+1)
    return 0;
    else
    return len;
}

int main(){
    int* a, n;
    cin>>n;
    a=new int[n];
    for(int i=0; i<n; i++)
    cin>>a[i];
    int target;
    cin>>target;
    cout<<minSubarraylen(a, n, target)<<endl;
    delete[]a;
    return 0;
}