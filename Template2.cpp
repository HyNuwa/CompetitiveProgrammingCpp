// Plantilla de Programacion Competitiva (GNU++20)
// Basada en las notas: STL, aritmetica modular, combinatoria, DP,
// memoizacion, Segment Tree, grillas y custom hash.
// Compilar: g++ -std=c++20 -O2 -pipe -Wall -Wextra -Wshadow archivo.cpp

#include <bits/stdc++.h>
using namespace std;

// ---------- Tipos, constantes y atajos ----------
using ll = long long;
using ull = unsigned long long;
using i128 = __int128_t;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template <class T> using vec = vector<T>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) static_cast<int>((x).size())
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

constexpr int MOD = 1'000'000'007;
constexpr int MOD_NTT = 998'244'353;
constexpr int INF = 1'000'000'000;
constexpr ll INFLL = (1LL << 62); // Deja margen para sumas seguras.
constexpr long double EPS = 1e-12L;
constexpr long double PI = acosl(-1.0L);

constexpr array<int, 4> DX4{-1, 1, 0, 0};
constexpr array<int, 4> DY4{0, 0, -1, 1};
constexpr array<int, 8> DX8{-1, -1, -1, 0, 0, 1, 1, 1};
constexpr array<int, 8> DY8{-1, 0, 1, -1, 1, -1, 0, 1};

// ---------- Utilidades pequeñas ----------
template <class T>
bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template <class T>
int sgn(const T& x) {
    return (T(0) < x) - (x < T(0));
}

bool in_bounds(int x, int y, int n, int m) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

// Division matematica para divisores con signo; no depende del truncado de C++.
ll floor_div(ll a, ll b) {
    assert(b != 0);
    ll q = a / b, r = a % b;
    if (r != 0 && ((r > 0) != (b > 0))) --q;
    return q;
}

ll ceil_div(ll a, ll b) {
    assert(b != 0);
    ll q = a / b, r = a % b;
    if (r != 0 && ((r > 0) == (b > 0))) ++q;
    return q;
}

void print_yes(bool ok) { cout << (ok ? "YES\n" : "NO\n"); }

#ifdef LOCAL
template <class... Ts>
void debug_out(const Ts&... xs) {
    ((cerr << xs << ' '), ...) << '\n';
}
#define debug(...) debug_out(__VA_ARGS__)
#else
#define debug(...) ((void)0)
#endif

// ---------- Aritmetica modular ----------
ll norm_mod(ll x, ll mod) {
    assert(mod > 0);
    x %= mod;
    return x < 0 ? x + mod : x;
}

// Usa __int128 para no desbordar si a y b son long long grandes.
ll mul_mod(ll a, ll b, ll mod) {
    return static_cast<ll>((static_cast<i128>(norm_mod(a, mod)) * norm_mod(b, mod)) % mod);
}

ll binpow(ll a, ll e, ll mod = MOD) {
    assert(e >= 0 && mod > 0);
    ll result = 1 % mod;
    a = norm_mod(a, mod);
    while (e > 0) {
        if (e & 1) result = mul_mod(result, a, mod);
        a = mul_mod(a, a, mod);
        e >>= 1;
    }
    return result;
}

// Devuelve gcd(a,b) y encuentra x,y tales que a*x + b*y = gcd(a,b).
ll ext_gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = (a >= 0 ? 1 : -1);
        y = 0;
        return abs(a);
    }
    ll x1, y1;
    ll g = ext_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

// Inverso para modulo cualquiera; nullopt si gcd(a, mod) != 1.
optional<ll> mod_inverse(ll a, ll mod) {
    ll x, y;
    if (ext_gcd(a, mod, x, y) != 1) return nullopt;
    return norm_mod(x, mod);
}

// Solo si mod es primo y a no es multiplo de mod.
ll mod_inverse_prime(ll a, ll mod = MOD) {
    return binpow(a, mod - 2, mod);
}

template <int Mod>
struct Mint {
    int v;

    Mint(ll value = 0) : v(static_cast<int>(value % Mod)) {
        if (v < 0) v += Mod;
    }

    static constexpr int mod() { return Mod; }
    explicit operator int() const { return v; }

    Mint& operator+=(const Mint& other) {
        if ((v += other.v) >= Mod) v -= Mod;
        return *this;
    }
    Mint& operator-=(const Mint& other) {
        if ((v -= other.v) < 0) v += Mod;
        return *this;
    }
    Mint& operator*=(const Mint& other) {
        v = static_cast<int>(1LL * v * other.v % Mod);
        return *this;
    }
    Mint pow(ll e) const {
        Mint result = 1, base = *this;
        while (e > 0) {
            if (e & 1) result *= base;
            base *= base;
            e >>= 1;
        }
        return result;
    }
    // Requiere que Mod sea primo y v != 0.
    Mint inv() const { return pow(Mod - 2); }
    Mint& operator/=(const Mint& other) { return *this *= other.inv(); }

    friend Mint operator+(Mint a, const Mint& b) { return a += b; }
    friend Mint operator-(Mint a, const Mint& b) { return a -= b; }
    friend Mint operator*(Mint a, const Mint& b) { return a *= b; }
    friend Mint operator/(Mint a, const Mint& b) { return a /= b; }
    friend bool operator==(const Mint&, const Mint&) = default;
    friend ostream& operator<<(ostream& os, const Mint& x) { return os << x.v; }
};

using mint = Mint<MOD>;

// Combinatoria: C(n,k), P(n,k), combinaciones con repeticion.
// El modulo de Mint debe ser primo y n debe ser menor que el modulo.
template <int Mod>
struct Combinatorics {
    using M = Mint<Mod>;
    vector<M> fact{1}, inv_fact{1};

    void ensure(int n) {
        assert(n >= 0 && n < Mod);
        int old = sz(fact) - 1;
        if (n <= old) return;
        fact.resize(n + 1);
        inv_fact.resize(n + 1);
        for (int i = old + 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
        inv_fact[n] = fact[n].inv();
        for (int i = n; i > old; --i) inv_fact[i - 1] = inv_fact[i] * i;
    }

    M C(int n, int k) {
        if (k < 0 || k > n) return 0;
        ensure(n);
        return fact[n] * inv_fact[k] * inv_fact[n - k];
    }
    M P(int n, int k) {
        if (k < 0 || k > n) return 0;
        ensure(n);
        return fact[n] * inv_fact[n - k];
    }
    M H(int n, int k) { // Elegir k elementos de n tipos, con repeticion.
        return n == 0 ? M(k == 0) : C(n + k - 1, k);
    }
};

// ---------- Hash seguro para unordered_map / unordered_set ----------
struct CustomHash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t random_seed = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + random_seed);
    }
};

// Ejemplo: unordered_map<ll, int, CustomHash> frequency;

// ---------- Estructuras de datos ----------
struct DSU {
    vector<int> parent, size;

    explicit DSU(int n = 0) { init(n); }
    void init(int n) {
        parent.resize(n);
        size.assign(n, 1);
        iota(all(parent), 0);
    }
    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
    int component_size(int x) { return size[find(x)]; }
};

// Fenwick / BIT: suma de rango y actualizacion puntual, todo en O(log n).
template <class T = ll>
struct Fenwick {
    int n = 0;
    vector<T> bit;

    explicit Fenwick(int n_ = 0) { init(n_); }
    void init(int n_) { n = n_; bit.assign(n + 1, T{}); }
    void add(int index, T delta) { // indice 0-based
        for (++index; index <= n; index += index & -index) bit[index] += delta;
    }
    T prefix_sum(int right) const { // [0, right)
        T answer{};
        for (; right > 0; right -= right & -right) answer += bit[right];
        return answer;
    }
    T range_sum(int left, int right) const { return prefix_sum(right) - prefix_sum(left); }
    // Menor indice i tal que sum[0..i] >= target; requiere target en [1, total].
    int lower_bound(T target) const {
        int index = 0;
        for (int step = bit_floor(static_cast<unsigned>(n)); step; step >>= 1) {
            int next = index + step;
            if (next <= n && bit[next] < target) {
                index = next;
                target -= bit[next];
            }
        }
        return index;
    }
};

// Segment Tree iterativo generico: consultas [l, r) y asignaciones puntuales.
// Ejemplo suma: SegTree<ll, plus<ll>> st(a, 0LL, plus<ll>{});
template <class T, class Merge>
struct SegTree {
    int n = 0;
    T identity;
    Merge merge;
    vector<T> tree;

    SegTree(const vector<T>& values, T identity_, Merge merge_)
        : identity(identity_), merge(merge_) {
        init(values);
    }
    void init(const vector<T>& values) {
        n = sz(values);
        tree.assign(2 * max(1, n), identity);
        for (int i = 0; i < n; ++i) tree[n + i] = values[i];
        for (int i = n - 1; i > 0; --i) tree[i] = merge(tree[i << 1], tree[i << 1 | 1]);
    }
    void set(int pos, T value) {
        for (tree[pos += n] = value; pos > 1; pos >>= 1)
            tree[pos >> 1] = merge(tree[pos], tree[pos ^ 1]);
    }
    T query(int left, int right) const {
        T left_result = identity, right_result = identity;
        for (left += n, right += n; left < right; left >>= 1, right >>= 1) {
            if (left & 1) left_result = merge(left_result, tree[left++]);
            if (right & 1) right_result = merge(tree[--right], right_result);
        }
        return merge(left_result, right_result);
    }
};

// Lazy Segment Tree: suma sobre rango + actualizar un rango por suma, O(log n).
struct LazySegTreeAddSum {
    int n = 0;
    vector<ll> tree, lazy;

    explicit LazySegTreeAddSum(const vector<ll>& values) {
        n = sz(values);
        tree.assign(4 * max(1, n), 0);
        lazy.assign(4 * max(1, n), 0);
        if (n) build(1, 0, n, values);
    }
    void build(int node, int left, int right, const vector<ll>& values) {
        if (right - left == 1) {
            tree[node] = values[left];
            return;
        }
        int mid = (left + right) / 2;
        build(node * 2, left, mid, values);
        build(node * 2 + 1, mid, right, values);
        pull(node);
    }
    void apply(int node, int left, int right, ll value) {
        tree[node] += value * (right - left);
        lazy[node] += value;
    }
    void push(int node, int left, int right) {
        if (lazy[node] == 0 || right - left == 1) return;
        int mid = (left + right) / 2;
        apply(node * 2, left, mid, lazy[node]);
        apply(node * 2 + 1, mid, right, lazy[node]);
        lazy[node] = 0;
    }
    void pull(int node) { tree[node] = tree[node * 2] + tree[node * 2 + 1]; }
    void add(int left, int right, ll value) { // [left, right)
        if (left < right) add(1, 0, n, left, right, value);
    }
    void add(int node, int left, int right, int ql, int qr, ll value) {
        if (qr <= left || right <= ql) return;
        if (ql <= left && right <= qr) return apply(node, left, right, value);
        push(node, left, right);
        int mid = (left + right) / 2;
        add(node * 2, left, mid, ql, qr, value);
        add(node * 2 + 1, mid, right, ql, qr, value);
        pull(node);
    }
    ll sum(int left, int right) { // [left, right)
        return left < right ? sum(1, 0, n, left, right) : 0;
    }
    ll sum(int node, int left, int right, int ql, int qr) {
        if (qr <= left || right <= ql) return 0;
        if (ql <= left && right <= qr) return tree[node];
        push(node, left, right);
        int mid = (left + right) / 2;
        return sum(node * 2, left, mid, ql, qr) + sum(node * 2 + 1, mid, right, ql, qr);
    }
};

// ---------- Esqueleto de solucion ----------
void solve() {
    // 1) Lee las restricciones; decide complejidad y tipos (usa ll si hay productos/sumas grandes).
    // 2) Declara vectores dinamicos por defecto; usa globales solo si necesitas mucha memoria.
    // 3) DP: define estado, bases, transicion, orden y donde queda la respuesta.
    // 4) Para modulo negativo usa norm_mod(x, MOD), no x % MOD directamente.
    // 5) Para decimales: cout << fixed << setprecision(10) << answer << '\n';

    // int n;
    // cin >> n;
    // vector<ll> a(n);
    // for (ll& x : a) cin >> x;
    // ...
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases = 1;
    // cin >> test_cases; // Activalo si el enunciado tiene T casos.
    while (test_cases--) solve();
    return 0;
}
