//im1
struct dsu{
    vector<int> parent;
    vector<int> size;
    void init(int n){
        parent.resize(n + 1);
        size.resize(n + 1);
        iota(parent.begin(),parent.end(),0);
        fill(size.begin(),size.end(),1);
    }
    int find_parent(int i){
        if(parent[i]==i){
            return i;
        }
        return parent[i] = find_parent(parent[i]);
    }
    void uni(int u,int v){
        u = find_parent(u);
        v = find_parent(v);
        if(u!=v){
            if (size[u] < size[v])
                swap(u, v);
            parent[v] = u;
            size[u] += size[v];
        }
    }
};

// imp2
struct dsu{
    vector<int> group;
    vector<vector<int>> members;
    dsu(int n){
        group.resize(n + 1);
        members.resize(n + 1);
        for(int i = 0 ; i < n + 1;i++){
            group[i] = i;
            members[i] = {i};
        }
    }
    void uni(int x,int y){
        int u = group[x];
        int v = group[y];
        if(u==v){
            return;
        }
        if(members[u].size() < members[v].size()){
            swap(u,v);
        }
        const int n = (int)members[v].size();
        for(int i = 0; i < n;i++){
            members[u].push_back(members[v][i]);
            group[members[v][i]] = u;
        }
        members[v].clear();
    }
};