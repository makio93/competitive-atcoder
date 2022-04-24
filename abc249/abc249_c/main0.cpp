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
	int n, k;
	cin >> n >> k;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	int res = 0;
	rep(i, (1<<n)) {
		vector<int> ccnt(26);
		rep(j, n) if ((i>>j)&1) {
			for (char ci='a'; ci<='z'; ++ci) if (s[j].find(ci) != string::npos) ccnt[ci-'a']++;
		}
		int sum = 0;
		rep(j, 26) if (ccnt[j] == k) ++sum;
		res = max(res, sum);
	}
	cout << res << endl;
	return 0;
}
