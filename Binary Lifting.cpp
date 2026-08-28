struct BinaryLifting{
    vector<vector<int>> up;
    vector<int> depth;
    int LOG, MAXN;

    BinaryLifting(int n){
        MAXN = n + 5;
        LOG = log2(n) + 2;
        up.resize(MAXN, vector<int>(LOG, 0));
        depth.resize(MAXN, 0);
    }

    void dfs(int node, int prt, auto &adj){
        up[node][0] = prt;
        for(int j = 1; j < LOG; j++){
            up[node][j] = up[up[node][j - 1]][j - 1];
        }
        for(int nxt : adj[node]){
            if(nxt == prt)continue;
            depth[nxt] = depth[node] + 1;
            dfs(nxt, node, adj);
        }
    }

    int kthAncestor(int node, int k){
        for(int j = 0; j < LOG; j++){
            if(k & (1 << j)){
                node = up[node][j];
                if(node == 0) return -1;
            }
        }
        return node;
    }

    // Lowest Common Ancestor of u and v
    int LCA(int u, int v){
        if(depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];
        u = kthAncestor(u, diff);
        if(u == v) return u;
        for(int j = LOG - 1; j >= 0; j--){
            if(up[u][j] != up[v][j]){
                u = up[u][j];
                v = up[v][j];
            }
        }
        return up[u][0];
    }
};

/*
  BinaryLifting objectName(Tree Size);
  objName.dfs(root, 0, Adjacent Matrix -> adj); adj will be in vector<int> adj[N] form 
*/

