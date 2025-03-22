#include <iostream>

using namespace std;

int N, X[100],col[100], crossL[100], crossR[100];
int cnt=0;

void NqueensProblem(int i){
    for (int j=1; j<=N; j++)
    {
        if (col[j]==1 && crossL[i-j+N]==1 && crossR[i+j-1]==1)
        {
            X[i]=j;
            crossL[i-j+N]= crossR[i+j-1]=col[j]=0;
            if (i==N)
            {
                ++cnt;
            }
            else
            {
            NqueensProblem(i+1);
            }
            crossL[i-j+N]= crossR[i+j-1]=col[j]=1;
        }
    }

}

int main(){
    cin>>N;
    for (int i=1; i<100; i++)
    {
        col[i]=crossL[i]=crossR[i]=1;
    }
    NqueensProblem(1);
    cout<<cnt<<endl;
    return 0;
}