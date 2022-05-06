// 学習0回目,解説AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main(){
    string a;
    cin >> a;
    if (int(a.size())>=2) {
        a.pop_back();
        cout << a << endl;
    }
    else {
        for (char c='a'; c<='z'; ++c) {
            if (c<a[0]) {
                cout << c << endl;
                return 0;
            }
        }
        cout << -1 << endl;
    }
    return 0;
}
