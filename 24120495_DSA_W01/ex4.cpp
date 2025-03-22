#include <iostream>

using namespace std;

void towerOfHaNoi(int n, char from, char to, char aux){
    if (n==1)
    {
        cout<<"Move disk 1 from "<< from <<" to "<<to<<endl;
        return;
    }
    towerOfHaNoi(n-1, from, aux, to);
    cout<<"Move disk "<<n<<" from "<<from<<" to "<<to<<endl;
    towerOfHaNoi(n-1, aux, to, from);
}

int main(){
    int n;
    cin>>n;
    towerOfHaNoi(n, 'A','C','B');
    return 0;
}