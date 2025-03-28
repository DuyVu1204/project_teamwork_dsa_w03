#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

bool checkdays(int* a, int n, int capital, int days){
    int sum=0, sumdays=1;
    for (int i=0; i<n; i++)
    {
        if ((sum+a[i])>capital)
        {
            sumdays++;
            sum=0;
        }
        sum+=a[i];
    }
    return sumdays<=days;
}


int Theithpackage(int* a, int n, int days){
    int maxpackage = *max_element(a, a+n);
    int sum = accumulate(a, a + n, 0);
    while (maxpackage<sum)
    {
        int mid=(maxpackage+sum)/2;
        if (checkdays(a, n, mid, days))
        {
            sum=mid;
        }
        else
        {
            maxpackage=mid+1;
        }
    }
    return maxpackage;
}

int main(){
    int* a, n, days;
    cin>>n;
    a=new int[n];
    for (int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cin>>days;
    cout<<Theithpackage(a, n, days)<<endl;
    delete[]a;
    return 0;
}