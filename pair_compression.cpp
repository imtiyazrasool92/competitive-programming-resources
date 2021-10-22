vector<pair<int,int>> pair_compression(vector<pair<int,int>> T){
    const int N = (int)T.size();
    sort(T.begin(),T.end());
    int curr = 1;
    for(int i = 0 ; i < N;i++){
        if(i < N - 1 && T[i].first != T[i + 1].first){
            T[i].first = curr;
            curr++;
        }
        else
            T[i].first = curr;
    }
    sort(T.begin(),T.end(),[](pair<int,int> A,pair<int,int> B){return A.second < B.second;});
    curr = 1;
    for(int i = 0 ; i < N;i++){
        if(i < N -1 && T[i].second != T[i + 1].second){
            T[i].second = curr;
            curr++;
        }
        else
            T[i].second = curr;
    }
    sort(T.begin(),T.end());
    return T;
}