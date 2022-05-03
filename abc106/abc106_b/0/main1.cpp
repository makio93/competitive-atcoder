// 

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int divisorNum(int i) {
    int ans = 0;
    for (int j=1; j*j<=i; j++) {
        if (i%j==0) {
            if (j*j==i) ++ans;
            else ans += 2;
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    int ans = 0;
    for (int i=1; i<=n; i+=2) {
        if (divisorNum(i)==8) ++ans;
    }
    cout << ans << endl;
    return 0;
}
