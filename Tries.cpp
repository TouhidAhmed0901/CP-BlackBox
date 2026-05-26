struct TrieNode{
    TrieNode* child[26];
    bool endmark;

    TrieNode(){
        endmark = false;

        for(int i=0;i<26;i++)
            child[i] = NULL;
    }
};

TrieNode* root = new TrieNode();

void insert_word(string s){
    TrieNode* cur = root;

    for(char ch : s){
        int id = ch - 'a';

        if(cur->child[id] == NULL)
            cur->child[id] = new TrieNode();

        cur = cur->child[id];
    }

    cur->endmark = true;
}

bool search_word(string s){
    TrieNode* cur = root;

    for(char ch : s){
        int id = ch - 'a';

        if(cur->child[id] == NULL)
            return false;

        cur = cur->child[id];
    }

    return cur->endmark;
}

bool prefix_exist(string s){
    TrieNode* cur = root;

    for(char ch : s){
        int id = ch - 'a';

        if(cur->child[id] == NULL)
            return false;

        cur = cur->child[id];
    }

    return true;
}



/*
    insert_word("cat");
    insert_word("car");
    insert_word("dog");

    cout << search_word("cat") << '\n'; // 1
    cout << search_word("cow") << '\n'; // 0

    cout << prefix_exist("co") << '\n'; // 1

*/
