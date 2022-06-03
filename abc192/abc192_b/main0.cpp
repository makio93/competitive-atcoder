// 本番AC

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main(){
    string s;
    cin >> s;
    bool ok = true;
    rep(i, s.length()) {
        if (i%2==0 && isupper(s[i])) ok = false;
        if (i%2==1 && islower(s[i])) ok = false; 
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
