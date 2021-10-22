
vector<array<int,3>> pair_compression_withorder(vector<array<int,3>> A){
    const int N = (int)A.size();
    sort(A.begin(),A.end(),[](auto a,auto b){return a[0] < b[0];});
    int curr = 1;
    for(int i = 0 ;i < N;i++){
        if(i + 1 < N && A[i][0] != A[i + 1][0]){
            A[i][0] = curr;
            curr++;
        }else{
            A[i][0] = i + 1;
        }
    }
    sort(A.begin(),A.end(),[](auto a,auto b){return a[1] < b[1];});
    curr = 1;
    for(int i = 0; i < N;i++){
        if(i + 1< N && A[i][1] != A[i + 1][1]){
            A[i][1] = curr;
            curr++;
        }else{
            A[i][1] = i + 1;
        }
    }
    sort(A.begin(),A.end(),[](auto a,auto b){return a[2] < b[2];});
    return A;
}