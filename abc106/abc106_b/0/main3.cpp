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
    vector<int> divisorNum(n+1, 0);
    rep3(i, 1, n+1) {
        for (int j=i; j<=n; j+=i) {
            divisorNum[j]++;
        }
    }
    int ans = 0;
    for (int i=1; i<=n; i+=2) {
        if (divisorNum[i]==8) ++ans;
    }
    cout << ans << endl;
    return 0;
}
