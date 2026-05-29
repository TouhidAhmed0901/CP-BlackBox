vector<int> buildLPS(string p) {
    int n = p.size();
    vector<int> lps(n);

    int len = 0;
    int i = 1;

    while(i < n) {
        if(p[i] == p[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if(len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

void KMP(string text, string pattern) {
    vector<int> lps = buildLPS(pattern);

    int i = 0;
    int j = 0;

    int n = text.size();
    int m = pattern.size();

    while(i < n) {

        if(text[i] == pattern[j]) {
            i++;
            j++;
        }

        if(j == m) {
            cout << "Pattern found at index "
                 << i - j << '\n';

            j = lps[j - 1];
        }

        else if(i < n && text[i] != pattern[j]) {

            if(j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}
