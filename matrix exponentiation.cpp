vector<vec> matrix_multiplication(vector<vec> &mat1, vector<vec> &mat2){
    int n = mat1.size();
    vector<vec> result(n, vec(n));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            for(int k = 0; k<n; k++){
                result[i][j] = (result[i][j] + (mat1[i][k]*mat2[k][j])%mod)%mod;
            }
        }
    }
    return result;
}
vector<vec> matrix_exp(vector<vec> mat, int n){
    //identity matrix
    vector<vec> result(mat.size(), vec(mat.size()));
    for(int i = 0; i<mat.size(); i++)result[i][i] = 1;

    while(n){
        if(n&1)result = matrix_multiplication(result, mat);
        n = n>>1;
        mat = matrix_multiplication(mat, mat);
    }
    return result;
}

/*
    Find nth fibonacci number
    cin>>n;
    vector<vec> res = {
        {1, 1},
        {1, 0}
    };
    res = matrix_exp(res, n);
    pn(res[0][1]);


*/
