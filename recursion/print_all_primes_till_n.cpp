#include <iostream>
using namespace std;

bool CheckPrime(int &n){
    for(int i=2; i*i<=n; i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int main(int argc, char **argv){
    int low, high;
    cin >> low >> high;
    for(int i=low; i<=high; i++){
        bool res = CheckPrime(i);
        if(res){
            cout<<i<<endl;
        }
    }
}
