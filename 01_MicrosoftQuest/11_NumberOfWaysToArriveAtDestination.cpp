#include <bits/stdc++.h>
using namespace std;

#define pp pair<int,int>
#define fi first
#define se second
#define mp make_pair

class Solution {
	ll count = 0;
	ll mod = 1e9+7;

public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int r = roads.size();
        vector<vector<pp>> adj(n, vector<pp>());
        for(int i=0; i<r; i++) {
        	int u=roads[i][0], v=roads[i][1], t=roads[i][2];
        	adj[u].push_back(mp(t,v));
        	adj[v].push_back(mp(t,u));
        }
        vector<bool> visited(n, false);
        int minPath=INT_MAX, path=0;
        queue<pp> q;
        q.push(mp(0,0)); // At node 0, at time 0.
        visited[0] = true;
        while(!q.empty()) {
        	
        }
    }
};

int main() {
	int n, r;
	cin >> n >> r;
	vector<vector<int>> roads(r, vector<int>(3,0));
	for(int i=0; i<r; i++) {
		for(int j=0; j<3; j++) {
			cin >> roads[i][j];
		}
	}
	Solution solve;
	int ans = solve.countPaths(n, roads);
	cout << ans << "\n";
	return 0;
}