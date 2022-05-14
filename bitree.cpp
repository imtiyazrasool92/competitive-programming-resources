// by tourist
// 0 base index
template <typename T>
class fenwick {
public:
    vector<T> fenw;
    int n;
    fenwick(int _n) : n(_n) {
        fenw.resize(n);
    }
    // index,value
    void update(int x, T v) {
        while (x < n) {
            fenw[x] += v;
            x |= (x + 1);
        }
    }
    // prefix sum till x
    T get(int x) {
        T v{};
        while (x >= 0) {
            v += fenw[x];
            x = (x & (x + 1)) - 1;
        }
        return v;
    }
    T get_range(int l, int r) {
        return get(r) - (l > 0 ? get(l - 1) : 0);
    }
};

