#include <iostream>
#include <vector>
using namespace std;

int Ack_r(int m, int n){
    if(m == 0){
        return n + 1;
    }
    else if(n == 0){
        return Ack_r(m - 1, 1);
    }
    else{
        return Ack_r(m - 1, Ack_r(m , n - 1));
    }
}

int main(){
    int m, n;
    while(cin >> m >> n){
        cout << "Recursive Ackermann : " << Ack_r(m, n) << endl;
    }
}