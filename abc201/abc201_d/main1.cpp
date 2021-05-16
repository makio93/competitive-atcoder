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

// 解説を見てから実装、AC

const int NINF = (int)(-1e9);

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> a(h);
	rep(i, h) cin >> a[i];
    vector<vector<int>> opt(h+1, vector<int>(w+1));
    auto f = [&](int i, int j) -> int {
        if (i<0 || i>=h || j<0 || j>=w) return NINF;
        return (a[i][j] == '+') ? 1 : -1;
    };
    repr(i, h) repr(j, w) {
        if (i==h-1 && j==w-1) continue;
        if ((i+j)%2 == 0) opt[i][j] = max(opt[i+1][j]+f(i+1,j), opt[i][j+1]+f(i,j+1));
        else opt[i][j] = min(opt[i+1][j]-f(i+1,j), opt[i][j+1]-f(i,j+1));
    }
    if (opt[0][0] > 0) cout << "Takahashi" << endl;
    else if (opt[0][0] < 0) cout << "Aoki" << endl;
    else cout << "Draw" << endl;
    return 0;
}
