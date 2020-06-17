#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define allrev(x) (x).rbegin(), (x).end()
#define pb push_back
#define pf push_front
#define fori(i, a, n) for(int i = a; i < n; ++i)
#define MAX(x) (*max_element(all(x)))
#define MIN(x) (*min_element(all(x)))
#define sortarr(a,n) sort(a, a+n)
#define sortvec(V) sort(all(V))

typedef vector<int> V;
typedef pair<int , int> pairi;
typedef set<int> seti;
typedef deque<int> deqi;

const int MOD = 1e9+7;
const int INF = 1e9+8;
const double pi = 3.14159265359;

template <class T>
T fac(T n)      // template function to find factorial of a number
{ 
    T res = 1, i; 
    for (i = 2; i <= n; i++) 
        res *= i; 
    return res; 
}
template<class T>
T lcm(T a, T b)     //template function to find lcm of two numbers 
{
    return (a * b) / __gcd(a,b);
}
template<class T>
T digitsum(T x)
{
    T sum = 0;
    while(x)
    {
        sum += x%10;
        x /= 10;
    }
    return sum;
}
// ternary search
/*double ternary(double l, double r){
    double eps = 1e-9;
    while(r - l > eps){
        double m1 = l + (r - l)/3;
        double m2 = r - (r - l)/3;
        double f1 = f(m1);
        double f2 = f(m2);
        if(f1 < f2)
            l = m1;
        else r = m2;
    }
    return f(l);
}*/
string tostring(int a)      //converting integer into a string
{
    string ans;
    while(a){
        ans += char(a % 10 + '0');
        a /= 10;
    }
    return ans;
}
void nPermute(string str, int n)  //function to find nth  lexi string
{ 
    sort(all(str));
    int i = 1; 
    do {
        if (i == n) 
            break; 
  
        i++; 
    } while (next_permutation(str.begin(), str.end())); 
    cout<<str<<endl;
} 
vector<int> factors(int n) 
{ 
    vector<int> f; 
    for(int x = 2; x*x <= n; x++) { 
        while (n%x == 0) { 
            f.push_back(x); 
            n /= x; 
        } 
    } 
    if (n > 1) f.push_back(n); 
    return f; 
}
bool prime(int n) 
{ 
    if (n < 2)
        return false;
    for(int x = 2; x*x <= n; x++) 
        if (n%x == 0) 
            return false; 
    return true; 
}
// binomial coeficient in O(K) 
int ncr(int n, int k){
    int res = 1;
    if(k > n - k)
        k = n - k;
    for(int i = 0; i < k; i++){
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}
tuple<int, int, int> Gcd(int a, int b)      //extended Euclids Algorithm
{
    if(b == 0)
        return {1, 0, a};
    else
    {
        int x, y, g;
        tie(x, y, g) = Gcd(b, a%b);
        return {y, x - (a/b)*y, g};
    }
}
template<class T>       // modular Exponentiation x^n mod m = x^(n mod (m - 1)) mod m : if n  is very large;
T binpow(T a, T b, T m) {
    a %= m;
    T res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
char check(int x){
    char c;
    cout << x << endl;
    cin >> c;
    if(c == 'E')    exit(0);
    else    return c;
}
void game(int l, int h){
    int m = l + (h - l) / 2;
    for(int i = 0; i < 8; i++){
        char c;
        c = check(1);
        if(c == 'L'){
            c = check(m);
            if(c == 'G')    game(m + 1, h);
            else    game(l, m - 1);
            return;
        }
    }
    char c = check(m);
    if(c == 'G')    game(m + 1, h);
    else    check(m - 1);
    return;
}
inline void predict(int l, int h){
    if(h < l)   return;
    else if(h == l){
        check(l);
        return;
    }
    int m1 = l + (h - l) / 3;
    int m2 = h - (h - l) / 3;
    char c1 = check(m1);
    char c2 = check(m2);
    if(c1 == 'L' && c2 == 'L'){
        predict(l, m2 - 1);
        return;
    }
    else if(c1 == 'G' && c2 == 'G'){
        predict(m1 + 1, h);
        return;
    }
    else if(c1 =='L' && c2 == 'G'){
        predict(l, m1 - 1);
        predict(m2 + 1, h);
        return ;
    }
    c1 = check(m2);
    if(c1 == 'L'){
        predict(l, m2 - 1);
        return ;
    }
    c2 = check(m1);
    if(c2 == 'G'){
        predict(m1 + 1, h);
        return;
    }
    predict(l, m1 - 1), predict(m1 + 1, h);
}
void solve()
{
    int n;
    cin >> n;
    char c;
    int m = (n + 1) / 2;
    for(int i = 0; i < 8; i++){
        c = check(1);
        if(c == 'L'){
            c = check(m);
            if(c == 'G')    game(m + 1, n);
            else    game(2, m - 1);
            return;
        }
    }
    predict(1, n);
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    solve();
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}