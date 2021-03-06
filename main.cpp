/* #region header */

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
// types
using ll = long long;
using ull = unsigned long long;
using ld = long double;
typedef pair<ll, ll> Pl;
typedef pair<int, int> Pi;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<char> vc;
template <typename T> using mat = vector<vector<T>>;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvl;
typedef vector<vector<char>> vvc;
// abreviations
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep_(i, a_, b_, a, b, ...) for (ll i = (a), max_i = (b); i < max_i; i++)
#define rep(i, ...) rep_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define rrep_(i, a_, b_, a, b, ...) for (ll i = (b - 1), min_i = (a); i >= min_i; i--)
#define rrep(i, ...) rrep_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define srep(i, a, b, c) for (ll i = (a), max_i = (b); i < max_i; i += c)
#define SZ(x) ((int)(x).size())
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define mp make_pair
//入出力
#define print(x) cout << x << endl
template <class T> ostream &operator<<(ostream &os, const vector<T> &v) {
    for (auto &e : v)
        cout << e << " ";
    cout << endl;
    return os;
}
void scan(int &a) {
    cin >> a;
}
void scan(long long &a) {
    cin >> a;
}
void scan(char &a) {
    cin >> a;
}
void scan(double &a) {
    cin >> a;
}
void scan(string &a) {
    cin >> a;
}
template <class T> void scan(vector<T> &a) {
    for (auto &i : a)
        scan(i);
}
#define vsum(x) accumulate(all(x), 0LL)
#define vmax(a) *max_element(all(a))
#define vmin(a) *min_element(all(a))
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
// functions
// gcd(0, x) fails.
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
ll safemod(ll a, ll b) {
    return (a % b + b) % b;
}
template <class T> bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T> T mypow(T x, ll n) {
    T ret = 1;
    while (n > 0) {
        if (n & 1)
            (ret *= x);
        (x *= x);
        n >>= 1;
    }
    return ret;
}
ll modpow(ll x, ll n, const ll mod) {
    ll ret = 1;
    while (n > 0) {
        if (n & 1)
            (ret *= x);
        (x *= x);
        n >>= 1;
        x %= mod;
        ret %= mod;
    }
    return ret;
}

uint64_t my_rand(void) {
    static uint64_t x = 88172645463325252ULL;
    x = x ^ (x << 13);
    x = x ^ (x >> 7);
    return x = x ^ (x << 17);
}
int popcnt(ull x) {
    return __builtin_popcountll(x);
}
template <typename T> vector<int> IOTA(vector<T> a) {
    int n = a.size();
    vector<int> id(n);
    iota(all(id), 0);
    sort(all(id), [&](int i, int j) { return a[i] < a[j]; });
    return id;
}
struct Timer {
    clock_t start_time;
    void start() {
        start_time = clock();
    }
    int lap() {
        // return x ms.
        return (clock() - start_time) * 1000 / CLOCKS_PER_SEC;
    }
};
template <int Mod> struct modint {
    int x;

    modint() : x(0) {
    }

    modint(long long y) : x(y >= 0 ? y % Mod : (Mod - (-y) % Mod) % Mod) {
    }

    modint &operator+=(const modint &p) {
        if ((x += p.x) >= Mod)
            x -= Mod;
        return *this;
    }

    modint &operator-=(const modint &p) {
        if ((x += Mod - p.x) >= Mod)
            x -= Mod;
        return *this;
    }

    modint &operator*=(const modint &p) {
        x = (int)(1LL * x * p.x % Mod);
        return *this;
    }

    modint &operator/=(const modint &p) {
        *this *= p.inverse();
        return *this;
    }

    modint operator-() const {
        return modint(-x);
    }

    modint operator+(const modint &p) const {
        return modint(*this) += p;
    }

    modint operator-(const modint &p) const {
        return modint(*this) -= p;
    }

    modint operator*(const modint &p) const {
        return modint(*this) *= p;
    }

    modint operator/(const modint &p) const {
        return modint(*this) /= p;
    }

    bool operator==(const modint &p) const {
        return x == p.x;
    }

    bool operator!=(const modint &p) const {
        return x != p.x;
    }

    modint inverse() const {
        int a = x, b = Mod, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return modint(u);
    }

    modint pow(int64_t n) const {
        modint ret(1), mul(x);
        while (n > 0) {
            if (n & 1)
                ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const modint &p) {
        return os << p.x;
    }

    friend istream &operator>>(istream &is, modint &a) {
        long long t;
        is >> t;
        a = modint<Mod>(t);
        return (is);
    }

    static int get_mod() {
        return Mod;
    }

    constexpr int get() const {
        return x;
    }
};
template <typename T = int> struct Edge {
    int from, to;
    T cost;
    int idx;

    Edge() = default;

    Edge(int from, int to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx) {
    }

    operator int() const {
        return to;
    }
};

template <typename T = int> struct Graph {
    vector<vector<Edge<T>>> g;
    int es;

    Graph() = default;

    explicit Graph(int n) : g(n), es(0) {
    }

    size_t size() const {
        return g.size();
    }

    void add_directed_edge(int from, int to, T cost = 1) {
        g[from].emplace_back(from, to, cost, es++);
    }

    void add_edge(int from, int to, T cost = 1) {
        g[from].emplace_back(from, to, cost, es);
        g[to].emplace_back(to, from, cost, es++);
    }

    void read(int M, int padding = -1, bool weighted = false, bool directed = false) {
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            a += padding;
            b += padding;
            T c = T(1);
            if (weighted)
                cin >> c;
            if (directed)
                add_directed_edge(a, b, c);
            else
                add_edge(a, b, c);
        }
    }
};

/* #endregion*/
// constant
#define inf 1000000000ll
#define INF 4000000004000000000LL
#define mod 998244353ll
const long double eps = 0.000000000000001;
const long double PI = 3.141592653589793;
using mint = modint<mod>;
using vmint = vector<mint>;

const int SIZE = 20;
const int MAXLEN = 200;
int si, sj, ti, tj;
ld p;
mat<int> h(SIZE, vi(SIZE - 1)), v(SIZE - 1, vi(SIZE));
vector<mat<ld>> dp(MAXLEN + 1, mat<ld>(SIZE, vector<ld>(SIZE, 0)));
auto tmp = dp;
int change_i = -1;
template <typename T> ld calc_score(string &ans, int st = 0) {
    ld ex = 0;
    if (st == 0)
        dp[0][si][sj] = 1;
    rep(t, st, ans.size()) {
        char c = ans[t];
        rep(i, SIZE) rep(j, SIZE) {
            dp[t + 1][i][j] = 0;
        }
        rep(i, SIZE) rep(j, SIZE) {
            if (i == ti && j == tj)
                continue;
            if (dp[t][i][j] == 0)
                continue;
            int dx, dy;
            if (c == 'U') {
                dx = (i > 0 && v[i - 1][j] == 0 ? -1 : 0);
                dy = 0;
            } else if (c == 'D') {
                dx = (i < SIZE - 1 && v[i][j] == 0 ? 1 : 0);
                dy = 0;
            } else if (c == 'L') {
                dx = 0;
                dy = (j > 0 && h[i][j - 1] == 0 ? -1 : 0);
            } else {
                dx = 0;
                dy = (j < SIZE - 1 && h[i][j] == 0 ? 1 : 0);
            }
            dp[t + 1][i + dx][j + dy] += (1 - p) * dp[t][i][j];
            dp[t + 1][i][j] += p * dp[t][i][j];
        }
    }
    rep(t, ans.size()) {
        ex += dp[t + 1][ti][tj] * (400 - t);
    }
    return ex * 250000;
}

long long xor64(long long range) {
    static uint64_t x = 88172645463325252ULL;
    x ^= x << 13;
    x ^= x >> 7;
    return (x ^= x << 17) % range;
}

using State = string;
Timer timer;

string udlr = "UDLR";
State modify(State state) {
    int i = xor64(MAXLEN);
    int j = xor64(4);
    if (udlr[j] == state[i]) {
        j = (j + 1) % 4;
    }
    state[i] = udlr[j];
    change_i = i;
    return state;
}

template <typename T> State sa(State state) {
    const double TIME_LIMIT = 1950;
    double start_temp = 50, end_temp = 5; // 適当な値を入れる（後述）
    int it = 0;
    T pre_score = calc_score<T>(state);
    while (timer.lap() < TIME_LIMIT) { // 時間の許す限り回す
        State new_state = modify(state);
        T new_score;
        if (change_i > 100) {
            tmp = dp;
            new_score = calc_score<T>(new_state, change_i);
        } else {
            new_score = calc_score<T>(new_state, 0);
        }
        // 温度関数
        double temp = start_temp + (end_temp - start_temp) * timer.lap() / TIME_LIMIT;
        // 遷移確率関数(最大化の場合)
        double prob = new_score > pre_score ? 1 : exp((new_score - pre_score) / temp);

        if (prob > (double)xor64(inf) / inf) { // 確率probで遷移する
            state = new_state;
            pre_score = new_score;
        } else if (change_i > 100) {
            dp = tmp;
        }
        // if (it % 1 == 0) {
        //     cerr << it << ' ' << pre_score << ' ' << prob << endl;
        // }
        it++;
    }
    return state;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << setprecision(30) << fixed;
    cin >> si >> sj >> ti >> tj >> p;
    rep(i, SIZE) rep(j, SIZE - 1) {
        char x;
        cin >> x;
        h[i][j] = x - '0';
    }
    rep(i, SIZE - 1) rep(j, SIZE) {
        char x;
        cin >> x;
        v[i][j] = x - '0';
    }
    string ans = "RDLRLRRDUUDRLURDRRDDLRLRUURUUUUDRDRUUDLRUDLLDDDDURLRUDDLDRDLRLLLLUDRUDRRULRULRDLRLDLLUUULDLUURRLRDRRR"
                 "RDULDRLRRRRDDDDDRULDDURDDDRDLRRLDLDLDLRLLLUDDRDDDUURUDDLLLUULLLLDLUDRLLDLLULRLDLDDRLDRDLURURULRDDDR";
    ans = sa<ld>(ans);
    cout << ans << endl;
}