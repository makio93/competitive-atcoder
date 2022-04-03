// 本番1,WA

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

const string tar = "BWR";
map<pair<int, string>, char> memo;
char calc(int len, string& str) {
	if (memo.find({len,str}) != memo.end()) return memo[{len,str}];
	if (len == 2) {
		if (str[0] == str[1]) return (memo[{len,str}] = (char)str[0]);
		else {
			int tid = -1;
			rep(i, 3) if (str[0]!=tar[i] && str[1]!=tar[i]) tid = i;
			return (memo[{len,str}] = (char)tar[tid]);
		}
	}
	else {
		string lstr = str.substr(0,len-1), rstr = str.substr(1);
		string nstr = { calc(len-1, lstr), calc(len-1, rstr) };
		return (memo[{len,str}] = (char)calc((int)(nstr.length()), nstr));
	}
}

int main() {
	int n;
	cin >> n;
	string c;
	cin >> c;
	cout << calc(n, c) << endl;
	return 0;
}
