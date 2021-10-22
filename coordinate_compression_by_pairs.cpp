int n = (int)A.size();
vector<pair<int, int>> pairs(n);
for(int i = 0; i < n; ++i) {
	pairs[i] = {A[i], i};
}
sort(pairs.begin(), pairs.end());
int nxt = 0;
for(int i = 0; i < n; ++i) {
	if(i > 0 && pairs[i-1].first != pairs[i].first) nxt++;
	A[pairs[i].second] = nxt;
}