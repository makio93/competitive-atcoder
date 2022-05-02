// 復習0,自力,WA

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int n;
string s, t;
int count() {
    int cnt = 0;
    rep(i, n) {
        if (s[i] != t[i]) ++cnt;
    }
    return cnt;
}

int main(){
    int k;
    cin >> n >> k;
    cin >> s;
    t = s;
    rep(i, n-1) {
        char m = t[i];
        int p = i;
        for (int j=i+1; j<n; ++j) {
            if (t[j] <= m) {
                m = t[j];
                p = j;
            }
        }
        if (t[p] < t[i]) {
            swap(t[i], t[p]);
            int cnt = count();
            if (k < cnt) swap(t[i], t[p]);
        }
    }
    cout << t << endl;
    return 0;
}
