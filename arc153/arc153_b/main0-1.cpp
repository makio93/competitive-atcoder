// 本番WA

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
	int h, w, q;
	cin >> h >> w;
	vector<string> ab(h);
	rep(i, h) cin >> ab[i];
	vector<vector<ll>> hsub(h+1, vector<ll>(w+1)), wsub(h+1, vector<ll>(w+1));
	cin >> q;
	vector<int> a(q), b(q);
	rep(i, q) cin >> a[i] >> b[i];
	repr(i, q) {
		{
			hsub[0][0] += (a[i]-1) * (i%2==0 ? -1 : 1);
			wsub[0][0] += (b[i]-1) * (i%2==0 ? -1 : 1);
			hsub[a[i]][b[i]] += (a[i]-1) * (i%2==0 ? -1 : 1);
			wsub[a[i]][b[i]] += (b[i]-1) * (i%2==0 ? -1 : 1);
			hsub[0][b[i]] += (a[i]-1) * (i%2!=0 ? -1 : 1);
			wsub[0][b[i]] += (b[i]-1) * (i%2!=0 ? -1 : 1);
			hsub[a[i]][0] += (a[i]-1) * (i%2!=0 ? -1 : 1);
			wsub[a[i]][0] += (b[i]-1) * (i%2!=0 ? -1 : 1);
		}
		{
			hsub[a[i]][0] += (a[i]+h-1) * (i%2==0 ? -1 : 1);
			wsub[a[i]][0] += (b[i]-1) * (i%2==0 ? -1 : 1);
			hsub[h][b[i]] += (a[i]+h-1) * (i%2==0 ? -1 : 1);
			wsub[h][b[i]] += (b[i]-1) * (i%2==0 ? -1 : 1);
			hsub[a[i]][b[i]] += (a[i]+h-1) * (i%2!=0 ? -1 : 1);
			wsub[a[i]][b[i]] += (b[i]-1) * (i%2!=0 ? -1 : 1);
			hsub[h][0] += (a[i]+h-1) * (i%2!=0 ? -1 : 1);
			wsub[h][0] += (b[i]-1) * (i%2!=0 ? -1 : 1);
		}
		{
			hsub[0][b[i]] += (a[i]-1) * (i%2==0 ? -1 : 1);
			wsub[0][b[i]] += (b[i]+w-1) * (i%2==0 ? -1 : 1);
			hsub[a[i]][w] += (a[i]-1) * (i%2==0 ? -1 : 1);
			wsub[a[i]][w] += (b[i]+w-1) * (i%2==0 ? -1 : 1);
			hsub[0][w] += (a[i]-1) * (i%2!=0 ? -1 : 1);
			wsub[0][w] += (b[i]+w-1) * (i%2!=0 ? -1 : 1);
			hsub[a[i]][b[i]] += (a[i]-1) * (i%2!=0 ? -1 : 1);
			wsub[a[i]][b[i]] += (b[i]+w-1) * (i%2!=0 ? -1 : 1);
		}
		{
			hsub[a[i]][b[i]] += (a[i]+h-1) * (i%2==0 ? -1 : 1);
			wsub[a[i]][b[i]] += (b[i]+w-1) * (i%2==0 ? -1 : 1);
			hsub[h][w] += (a[i]+h-1) * (i%2==0 ? -1 : 1);
			wsub[h][w] += (b[i]+w-1) * (i%2==0 ? -1 : 1);
			hsub[a[i]][w] += (a[i]+h-1) * (i%2!=0 ? -1 : 1);
			wsub[a[i]][w] += (b[i]+w-1) * (i%2!=0 ? -1 : 1);
			hsub[h][b[i]] += (a[i]+h-1) * (i%2!=0 ? -1 : 1);
			wsub[h][b[i]] += (b[i]+w-1) * (i%2!=0 ? -1 : 1);
		}
	}
	rep(i, h+1) rep(j, w) {
		hsub[i][j+1] += hsub[i][j];
		wsub[i][j+1] += wsub[i][j];
	}
	rep(i, w+1) rep(j, h) {
		hsub[j+1][i] += hsub[j][i];
		wsub[j+1][i] += wsub[j][i];
	}
	vector<string> res(h, string(w, '.'));
	int mul = (q%2 == 1) ? -1 : 1;
	rep(i, h) {
		rep(j, w) {
		res[i][j] = ab[(hsub[i][j]+i)*mul][(wsub[i][j]+j)*mul];
		cout << ((hsub[i][j]+i)*mul) << "," << ((wsub[i][j]+j)*mul) << ' ';
		}
		cout << endl;
	}
	rep(i, h) cout << res[i] << endl;
	return 0;
}
