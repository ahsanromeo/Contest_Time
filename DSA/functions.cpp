#include <bits/stdc++.h>
using namespace std;

inline double distance(double x1, double y1, double x2, double y2) /// 2D distance
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

template < class T > T gcd(T a, T b)
{
    return b == 0 ? a : gcd(b, a % b);
}
template < class T > T lcm(T a, T b)
{
    return (a / gcd(a, b)) * b;
}
template < class T > pair < T , T > extended_euclid(T a, T b) /// call with a > b
{
    if(b == 0)
        return make_pair(1, 0);
    pair < T , T > p = extended_euclid(b, a % b);
    return make_pair(p.second, p.first - p.second * (a / b));
}

template < class T > T POW(T b, T p)
{
    if(p == 0)
        return (T)1;
    T r = POW(b, p >> 1);
    r *= r;
    if(p & (T)1)
        return r * b;
    return r;
}

template < class T > T bigmod(T b, T p, T m)
{
    if(p == 0)
        return (T)1;
    T r = bigmod(b, p >> 1, m) % m;
    r = (r * r) % m;
    if(p & 1)
        return (r * (b % m)) % m;
    return r;
}

template < class T > T mod_inv(T b, T m)
{
    return bigmod(b, m - 2, m);
}

template < class T > string toString(T x)
{
    stringstream ss;
    ss << x;
    return ss.str();
}

template < class T > string toBin(T x)
{
    string r = "";
    while(x > 0)
    {
        r  = (char)(x % 2 + 48);
        x >>= 1;
    }
    return r;
}

inline int getint()
{
    int x;
    scanf("%d", &x);
    return x;
}
#define II getint()

inline long long getlonglong()
{
    long long x;
    scanf("%lld", &x);
    return x;
}
#define LL getlonglong()

int main()
{

    return 0;
}
