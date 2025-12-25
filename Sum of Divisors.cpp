ll sigma(ll x){
    return ((x%mod)*((x+1)%mod)/2)%mod;
}
ll sumOfDivisors(ll n){
    // sum of all divisors of 1 to n
    // complexity: O(sqrt(n))
    ll sum = 0;
    for(ll l = 1; l<=n; l++){
        ll r = n/(n/l);
        sum += ((n/l)%mod*(sigma(r) - sigma(l-1) + mod))%mod;
        sum = (sum + mod)%mod;
        l = r;
    }
    return sum;
}
