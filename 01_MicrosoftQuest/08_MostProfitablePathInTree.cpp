#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        
    }
};

int main() {
	int n, bob;
	cin >> n >> bob;
	vector<vector<int>> edges(n-1, vector<int>(2,0));
	for(int i=0; i<n-1; i++) {
		for(int j=0; j<2; j++) {
			cin >> edges[i][j];
		}
	}
	vector<int> amount(n);
	for(int i=0; i<n; i++) {
		cin >> amount[i];
	}
	Solution solve;
	int ans = solve.mostProfitablePath(edges, bob, amount);
	cout << ans << "\n";
	return 0;
}