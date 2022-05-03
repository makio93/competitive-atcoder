// 

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main(){
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> b(n);
    rep(i, n-1) {
        if (s.substr(i, 2) == "AC") b[i+1] = b[i] + 1;
        else b[i+1] = b[i];
    } 
    rep(i, q) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        cout << (b[r]-b[l]) << endl;
    }
    return 0;
}
