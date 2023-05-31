// バチャ本番AC

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
	int n, m;
	string s;
	cin >> n >> m >> s;
	int val = 0;
	vector<int> cnt(n);
	rep(i, m) {
		cnt[i%n]++;
		if (s[i] == '+') {
			cnt[i%n] += val;
			val = 0;
		}
		else if (s[i] == '-') {
			val += cnt[i%n];
			cnt[i%n] = 0;
		}
	}
	rep(i, n) cout << cnt[i] << endl;
	return 0;
}
