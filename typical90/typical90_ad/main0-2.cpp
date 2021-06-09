#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 自力AC

int main() {
	int n, k;
	cin >> n >> k;
	if (k == 1) cout << (n-1) << endl;
	else {
		vector<int> pcnt(n+1);
		for (int i=2; i<=n; ++i) {
			if (pcnt[i] == 0) {
				pcnt[i]++;
				for (int j=i*2; j<=n; j+=i) pcnt[j]++;
			}
		}
		int res = 0;
		rep3(i, 2, n+1) if (pcnt[i] >= k) ++res;
		cout << res << endl;
	}
	return 0;
}
