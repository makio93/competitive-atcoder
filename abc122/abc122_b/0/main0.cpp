// 学習0回目,自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main(){
    string s;
    cin >> s;
    int len = 0, maxlen = 0;
    for (char c : s) {
        if (c=='A'||c=='C'||c=='G'||c=='T') {
            ++len;
            maxlen = (len>maxlen)?len:maxlen;
        } 
        else len = 0;
    }
    cout << maxlen << endl;
    return 0;
}

