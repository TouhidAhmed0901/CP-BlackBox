struct Fenwick{
    int n;
    vector<long long> bit;
    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void update(int idx, long long val) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] += val;
        }
    }

    long long query(int idx) {
        long long sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += bit[idx];
        }
        return sum;
    }
};
