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
	int ri, ci;
	cin >> ri >> ci;
	if (ri > 8) ri = 16 - ri;
	if (ci > 8) ci = 16 - ci;
	if (min(ri, ci)%2 == 1) cout << "black" << endl;
	else cout << "white" << endl;
	return 0;
}
