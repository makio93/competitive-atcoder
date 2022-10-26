#include <bits/stdc++.h>
using namespace std;

// 総数を1000000007（素数）で割った余り
const long long mod = 1e9 + 7;

using ll = long long;
using pii  = pair<int, int>;
using pll = pair<ll, ll>;
#define ull unsigned long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vc vector<char>
#define vs vector<string>
#define vpii vector<pii>
#define vpll vector<pll>

#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; i++)
#define rep1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; i++)
#define repr(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define rep1r(i, n) for (int i = ((int)(n)); i >= 1; i--)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
#define mp make_pair

#define INF (1e9)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

vi graphf[100005], graphb[100005];
vi label(100005, -1);
vi sz;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        graphf[a].push_back(b);
        graphf[b].push_back(a);
    }
    rep(i, k) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        graphb[a].push_back(b);
        graphb[b].push_back(a);
    }
    int num = 0;
    rep(i, n) {
        if (label[i] >= 0) continue;
        label[i] = num;
        sz.push_back(1);
        int p;
        queue<int> todo;
        todo.push(i);
        while (!todo.empty()) {
            p = todo.front();
            todo.pop();
            for (int j : graphf[p]) {
                if (label[j] >= 0) continue;
                label[j] = num;
                todo.push(j);
                sz[num]++;
            }
        }
        num++;
    }
    rep(i, n) {
        int ans;
        ans = sz[label[i]] - 1 - graphf[i].size();
        for (int j : graphb[i]) {
            if (label[j] == label[i]) ans--;
        }
        printf("%d%c", ans, i==n-1?'\n':' ');
    }
    return 0;
}
