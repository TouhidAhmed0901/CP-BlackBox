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
