#include <iostream> 

using namespace std;

int factorial(int n){
    if (n==0 || n==1)// Stopping condition
    return 1;
    else 
    return n*factorial(n-1);// Recursive call 
}

int main(){
    int n;
    cin>>n;
    cout<<factorial(n);
    return 0;
}


