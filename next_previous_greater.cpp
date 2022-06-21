template<typename T>
vector<T> next(vector<T> &A, function<bool(int, int)> F) {
    const int N = (int)A.size();

    vector<int> answer(N, -1);
    vector<pair<T, int>> stack = {{A[0], 0}};

    for (int i = 1; i < N; i++) {
        while (!stack.empty() && F(A[i], stack.back().first)) {
            answer[stack.back().second] = i;
            stack.pop_back();
        }
        stack.emplace_back(A[i], i);
    }

    return answer;
}


template<typename T>
vector<T> previous(vector<T> &A, function<bool(int, int)> F) {
    const int N = (int)A.size();

    vector<int> answer(N, -1);
    vector<pair<T, int>> stack = {{A[N - 1], N - 1}};

    for (int i = N - 2; i >= 0; i--) {
        while (!stack.empty() && F(A[i], stack.back().first)) {
            answer[stack.back().second] = i;
            stack.pop_back();
        }
        stack.emplace_back(A[i], i);
    }

    return answer;
}