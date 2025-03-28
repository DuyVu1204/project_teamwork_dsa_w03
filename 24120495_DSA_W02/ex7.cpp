#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<vector<int>> threeSum(int* a,  int n) {
    sort(a, a+n);
    vector<vector<int>> x;
    vector<int> b;
    for (int i=0; i<n-2; i++)
    {
        if (i>0 && a[i]==a[i-1])
        continue;
        int l=i+1;
        int r=n-1;
        while (l<r)
        {
            int total=a[i]+a[l]+a[r];
            if (total<0)
            l=l+1;
            else if (total>0)
            r=r-1;
            else 
            {
                b.push_back(a[i]);
                b.push_back(a[l]);
                b.push_back(a[r]);
                x.push_back(b);
                while (l<r && a[l]==b[1])
                l=l+1;
                while (l<r && a[r]==b[2])
                r=r-1;
            }
            b.clear();
        }
    }
    return x;
}

int main(){
    int* a, n;
    cin>>n;
    a=new int[n];
    for (int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    vector<vector<int>> x=threeSum(a, n);
    for (int i=0; i<x.size(); i++)
    {
        for (int j=0; j<x[i].size(); j++)
        {
            cout<<x[i][j]<<" ";
        }
        cout<<endl;
    }
    delete[]a;
    return 0;
}