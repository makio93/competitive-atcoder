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

// 本番WA

int main() {
	string s;
	int k;
	cin >> s >> k;
	int n = s.length();
	string tar = "KEY";
	vector<int> ccnt(3);
	rep(i, n) rep(j, 3) if (s[i] == tar[j]) ccnt[j]++;
	sort(all(ccnt));
	ll acnt = 1;
	rep3(i, 1, ccnt[0]+1) {
		acnt *= (n - i + 1);
		acnt /= i;
	}
	rep3(i, 1, ccnt[1]+1) {
		acnt *= ((n-ccnt[0]) - i + 1);
		acnt /= i;
	}

	map<string, int> dist;
	queue<string> que;
	dist[s] = 0;
	que.push(s);
	while (!que.empty() && (int)(dist.size())<=(int)(1e6)) {
		string str = que.front(); que.pop();
		int d = dist[str];
		if (d >= k) continue;
		rep(i, n-1) {
			string nstr = str;
			swap(nstr[i], nstr[i+1]);
			if (dist.find(nstr) != dist.end()) continue;
			dist[nstr] = d + 1;
			if (d+1 < k) que.push(nstr);
		}
	}
	ll res = (int)(dist.size());
	if (res > (int)(1e6)) res = acnt;
	cout << res << endl;
	return 0;
}
