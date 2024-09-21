#include <iostream>

using namespace std;

long long jegop(long long c, long long n, long long mod);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long  a, b, c, x;
    cin >> a >> b >> c;
    x = jegop(a, b, c);
    cout << x;
}

long long jegop(long long c, long long n, long long mod){
    if(n == 1)
        return c % mod;
    else{
        long long x = jegop(c, n/2, mod);
        if(n % 2 == 0)
            return x % mod * x % mod;
        else
            return x % mod * x % mod * c % mod;
    }
}