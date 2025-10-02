//sieve start
const int Prime_Upto = 2e6; // Is it ok?
bool prm[Prime_Upto+5];
vec prime;
void sieve(){
    int n = Prime_Upto;
    prm[0] = prm[1] = 1;
    for(int i = 2; i*i<=n; i++){
        if(!prm[i]){
            for(int j = i*i; j<=n; j+=i){
                prm[j] = 1;
            }
        }
    }
    for(int i = 2; i<=n; i++){
        if(!prm[i])prime.push_back(i);
    }
}
//sieve end
