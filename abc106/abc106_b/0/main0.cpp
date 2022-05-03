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
    int n;
    cin >> n;
    int ans = 0;
    for (int i=1; i<=n; i+=2) {
        int dn = 0;
        rep3(j, 1, i+1) {
            if (i%j==0) ++dn;
        }
        if (dn==8) ++ans;
    }
    cout << ans << endl;
    return 0;
}

