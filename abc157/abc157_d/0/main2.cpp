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

vi fg[100005], bg[100005], s;
vi label(100005, -1);

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        fg[a].push_back(b);
        fg[b].push_back(a);
    }
    rep(i, k){
        int a, b;
        cin >> a >> b;
        a--; b--;
        bg[a].push_back(b);
        bg[b].push_back(a);
    }
    int num = 0;
    rep(i, n) {
        if (label[i] >= 0) continue;
        int p, size = 0;
        stack<int> st;
        label[i] = num;
        st.push(i); size++;
        while (st.size() > 0) {
            p = st.top();
            st.pop();
            for (int j : fg[p]) {
                if (label[j] < 0) {
                    label[j] = num;
                    st.push(j); size++;
                }
            }
        }
        s.push_back(size);
        num++;
    }
    rep(i, n) {
        int ans;
        ans = s[label[i]] - 1 - fg[i].size();
        for (int j : bg[i]) {
            if (label[j] == label[i]) ans--;
        }
        printf("%d%c", ans, i==n-1?'\n':' ');
    }
    return 0;
}

