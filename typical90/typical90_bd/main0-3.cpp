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

int n;
vector<int> a, b;
vector<unordered_map<int,string>> memo;
string calc(string str, int d, int tar) {
	if (memo[d].find(tar) != memo[d].end()) return memo[d][tar];
	if (d == n) {
		if (tar == 0) return (memo[d][tar] = str);
		else return (memo[d][tar] = string("Impossible"));
	}
	else {
		if (tar <= 0) return (memo[d][tar] = string("Impossible"));
		else {
			if (a[d] >= b[d]) {
				string res = calc(str+'A', d+1, tar-a[d]);
				if (res!="Impossible" || a[d]==b[d]) return (memo[d][tar] = res);
				else return (memo[d][tar] = calc(str+'B', d+1, tar-b[d]));
			}
			else {
				string res = calc(str+'B', d+1, tar-b[d]);
				if (res != "Impossible") return (memo[d][tar] = res);
				else return (memo[d][tar] = calc(str+'A', d+1, tar-a[d]));
			}
		}
	}
}

int main() {
	int s;
	cin >> n >> s;
	a = vector<int>(n);
	b = vector<int>(n);
	rep(i, n) cin >> a[i] >> b[i];
	memo = vector<unordered_map<int,string>>(n+1, unordered_map<int,string>());
	cout << calc(string(""), 0, s) << endl;
	return 0;
}
