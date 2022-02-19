void out(vector<int> &T, bool print_size = false, bool first_index = false, int last_index = -1) {
    int start = first_index;
    int last = (last_index == -1  ? (int)T.size() : last_index);
    if (print_size) {
        cout << T.size() << '\n';
    }
    for (int i = start; i < last; i++) {
        cout << T[i] << ' ';
    }

}