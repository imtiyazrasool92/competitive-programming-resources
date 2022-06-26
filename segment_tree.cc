// my implementaion for basic segment tree

template<typename T, class F = function<T(T, T)>>
struct segment_tree {
    int N; // size of tree
    // change data type if INF is big
    int default_value = 0; // change this if you are using query like for gcd and sum : 0,min : +INF ,max : -INF ,lcm : 1
    F funct;
    vector<T> tree;

    segment_tree(int n, F fun) : N(n) {
        N = (1 << (32 - __builtin_clz(N)));
        assert(N <= 1e6);
        funct = fun;
        tree.resize(N << 1, default_value);
        build();
    }

    segment_tree(vector<T> &A, F fun) : N((int)A.size()) {
        N = (1 << (32 - __builtin_clz(N)));
        assert(N <= 1e6);
        funct = fun;

        tree.resize(N << 1, default_value);
        for (int i = 0; i < (int)A.size(); i++)
            tree[N + i] = A[i];

        build();
    }

    void build() {
        for (int i = N - 1; i >= 1; i--)
            tree[i] = funct(tree[i << 1], tree[(i << 1) | 1]);
    }

    // 0 base_index
    T query(int L, int R) {
        return query(1, 0, N - 1, L, R);
    }

    // just to make query easy to call
    T query(int node, int seg_L, int seg_R, int L, int R) {
        if (seg_L >= L && seg_R <= R) {
            return tree[node];
        }
        if (seg_L > R || seg_R < L) {
            return default_value;
        }
        int mid = (seg_L + seg_R) / 2;
        return funct(query(node << 1, seg_L, mid, L, R), query((node << 1) | 1, mid + 1, seg_R, L, R));
    }

    void change(int index, T value) {
        tree[N + index] = value;
        for (int i = (N + index)>>1; i >= 1; i>>=1)
            tree[i] = funct(tree[i << 1], tree[(i << 1) | 1]);
    }

};

// segment_tree<int64_t> T(vector, lambda);

// init segment tree with value 0
// segment_tree<int64_t> T(size, lambda);
