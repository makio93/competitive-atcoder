// バチャ本番,自力AC

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
	string w;
	cin >> w;
	int n = w.length();
	vector<int> ccnt(26);
	rep(i, n) ccnt[w[i]-'a']++;
	bool ok = true;
	rep(i, 26) if (ccnt[i]%2 == 1) ok = false;
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
