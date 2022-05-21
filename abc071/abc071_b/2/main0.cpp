// 学習2回目,自力AC

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
	string s;
	cin >> s;
	int n = s.length();
	vector<bool> used(26);
	rep(i, n) used[s[i]-'a'] = true;
	char res = '*';
	rep(i, 26) if (!used[i]) {
		res = (char)(i+'a');
		break;
	}
	if (res == '*') cout << "None" << endl;
	else cout << res << endl;
	return 0;
}
