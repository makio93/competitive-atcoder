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

const int INF = (int)(1e9);

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	vector<string> s(a*n, string(b*n, '.'));
	rep(i, a*n) rep(j, b*n) s[i][j] = ((i/a+j/b)%2 == 0) ? '.' : '#';
	rep(i, a*n) cout << s[i] << endl;
	return 0;
}
