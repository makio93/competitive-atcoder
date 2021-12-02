#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番,未完成

const int INF = (int)(1e9);

int main(){
    int n, q;
    cin >> n >> q;
    rep(i1, q) {
        string s;
        cin >> s;
        int ans = 0;
        while (1) {
            char tp = s[0];
            int p1 = 0;
            for (int i=1; i<n; ++i) {
                if (s[i] == tp) p1 = i;
                else break;
            }
            
        }
        cout << ans << endl;
    }
    return 0;
}
