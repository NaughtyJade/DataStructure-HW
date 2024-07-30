#include <iostream>
#include <vector>
using namespace std;

class Tnum {
public:
    int m;
    int n;
    Tnum(int m, int n) : m(m), n(n) {}
};

int Ack_nr(int m, int n){
    vector<Tnum> stack;
    stack.push_back(Tnum(m, n));

    while (!stack.empty()) {
        Tnum p = stack.back();
        stack.pop_back();

        if (p.m == 0) {
            if (stack.empty()) {
                return p.n + 1;
            } else {
                Tnum pPrev = stack.back();
                stack.pop_back();
                stack.push_back(Tnum(pPrev.m, p.n + 1));
            }
        } else if (p.n == 0) {
            stack.push_back(Tnum(p.m - 1, 1));
        } else {
            stack.push_back(Tnum(p.m - 1, -1));
            stack.push_back(Tnum(p.m, p.n - 1));
        }

        if (!stack.empty() && stack.back().n == -1) {
            stack.pop_back();
            if (!stack.empty()) {
                Tnum pTemp = stack.back();
                stack.pop_back();
                stack.push_back(Tnum(pTemp.m, p.n + 1));
            }
        }
    }
    return -1;
}



int main() {
    int m, n;
    while(cin >> m >> n){
        cout << "Non Recursive Ackermann : " << Ack_nr(m, n) << endl;
    }
}