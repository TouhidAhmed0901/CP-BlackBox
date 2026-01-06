long long inverseMod(long long n, long long MOD = mod){
    if(n==1) return 1;
    return (MOD - ((MOD/n)*inverseMod(MOD%n))%MOD+MOD)%MOD;
}
