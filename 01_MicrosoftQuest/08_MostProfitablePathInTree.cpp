#include <bits/stdc++.h>
using namespace std;

class Solution {
	int findPath(vector<vector<int>>& adj, int bob, vector<bool>& visited, vector<int>& bobPath) {
		if(bob == 0) {
			bobPath[bob] = 1;
			return 1;
		}
		int flag = 0;
		for(auto it: adj[bob]) {
			if(!visited[it]) {
				visited[it] = true;
				int smallAns = findPath(adj, it, visited, bobPath);
				if(smallAns > 0) {
					bobPath[bob] = smallAns+1; // This is the bob's path
					flag = smallAns+1;
				}
			}
		}
		return flag; // This path was taken by bob
	}

	void getAmounts(vector<vector<int>>& adj, vector<bool>& visited, int& maxAmount, vector<int>& amount, vector<int>& bobPath, int node, int time, int currAmount) {
		int bobTime = bobPath[node];
		if(time < bobTime) {
			// Alice takes whole amount
			currAmount += amount[node];
			// cout << "Alone " << amount[node] << " ";
		}
		else if(time == bobTime) {
			// Alice takes equal time to Bob
			currAmount += (amount[node]/2);
			// cout << "Shared " << amount[node]/2 << " ";
		}
		if(bobTime == 0) {
			// Bob hasn't visited.. This also counted in Alice's amount
			currAmount += amount[node];
		}
		// cout << node << " " << currAmount << "\n";
		if(node!=0 && adj[node].size()==1) {
			// Leaf node
			maxAmount = max(maxAmount, currAmount);
			return;
		}
		for(auto it: adj[node]) {
			if(!visited[it]) {
				visited[it] = true;
				getAmounts(adj, visited, maxAmount, amount, bobPath, it, time+1, currAmount);
			}
		}
		return;
	}

public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> adj(n, vector<int>());
        for(int i=0; i<n-1; i++) {
        	int f=edges[i][0], s=edges[i][1];
        	adj[f].push_back(s);
        	adj[s].push_back(f);
        }
        vector<bool> visited(n, false);
        vector<int> bobPath(n, 0);
        visited[bob] = true;
        bobPath[bob] = true;
        int ans = findPath(adj, bob, visited, bobPath);
        // Above function, labels the nodes.. travelled by bob.
        int maxTime = 0;
        for(int i=0; i<n; i++) {
        	maxTime = max(maxTime, bobPath[i]);
        }
        for(int i=0; i<n; i++) {
        	if(bobPath[i] != 0) {
        		int curr = (maxTime+1)-bobPath[i];
        		bobPath[i] = curr;
        	}
        	// cout << bobPath[i] << " ";
        }
        // Above loop, labels nodes.. with time, bob has visited
        // cout << "\n";
        int maxAmount = INT_MIN, currAmount=0;
        vector<bool> visited2(n, false);
        visited2[0] = true;
        getAmounts(adj, visited2, maxAmount, amount, bobPath, 0, 1, currAmount);
        return maxAmount;
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