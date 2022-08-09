#include <bits/stdc++.h>
using namespace std;
struct Hashing
{
    const int Prime = 131;
    const int mod = 1e9 + 7;
    vector < long long > powers = {};
    Hashing(int len)
    {
        if(len == 0)
        {
            cerr << "Error !!!" << endl;
            cerr << "Give Length greater than zero, you careless" << endl;
            cerr << "Exiting" << endl;
            exit(0);
        }
        long long p = 1;
        for(int i = 0; i < len; ++i)
        {
            powers.push_back(p);
            p *= Prime;
            p %= mod;
        }
    }
    long long getHash(string s)
    {
        long long h = 0;
        if((int)powers.size() < (int)s.size())
        {
            cerr << "Not enough powers, you fool !!!" << endl;
            exit(0);
        }
        for(int i = 0; i < (int)s.size(); ++i)
        {
            h += (powers[i] * s[i]) % mod;
            h %= mod;
        }
        return h;
    }
};

int main()
{
    Hashing h(5);
    cout << h.getHash("abcdefghij");
    return 0;
}
