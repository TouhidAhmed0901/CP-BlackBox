

const int mod = 1e9 + 7; // Is it ok?
const int max_N = 2e6; //Is it ok?

//factorial
int fact[max_N+5];
bool factorail_chk = false;
void factorial(int MOD = mod){ 
    int n = max_N;
    fact[0] = 1%MOD;
    for(int i = 1; i<=n; i++){
        fact[i] = (fact[i-1]*i)%MOD;
    }
    return;
}
//binary exponentiation 
int powerMod(int base, int power, int MOD = mod){
    int res = 1%MOD;
    while(power){
        if(power&1)res = (res*base)%MOD;
        base = (base*base)%MOD;
        power = power>>1;
    }
    return res;
}
// inverseMod
int inverseMod(int n, int MOD = mod){
    return powerMod(n, MOD-2, MOD);
}
// ncr
int ncr(int n, int r, int MOD=mod){
    if(!factorail_chk){ factorail_chk = true; factorial();}
    return (fact[n]* inverseMod((fact[r]*fact[n-r])%MOD, MOD))%MOD;
}

