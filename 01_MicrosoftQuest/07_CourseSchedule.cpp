#include <bits/stdc++.h>
using namespace std;

// b --> a    [a,b]

class Solution {
	bool isCyclic(vector<vector<int>>& adj, int n) {
		// Counting elements in toposort..
		// If equal to n .. total no. of nodes --> Non-cyclic
		vector<int> inDegree(n, 0);
		for(int i=0; i<n; i++) {
			for(auto it: adj[i]) {
				// i --> it
				inDegree[it]++;
			}
		}
		queue<int> q;
		int count = 0;
		for(int i=0; i<n; i++) {
			if(inDegree[i] == 0) {
				q.push(i);
			}
		}
		while(!q.empty()) {
			int front = q.front();
			q.pop();
			count++;
			for(auto it: adj[front]) {
				// front --> it
				inDegree[it]--; // Removing all these edges
				if(inDegree[it] == 0) {
					q.push(it); // If all in-edges removed.. time for toposort
				}
			}
		}
		return (count != n); // If count == n .. Non-cyclic
	}

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>> adj(numCourses, vector<int>());
        for(int i=0; i<n; i++) {
        	int a=prerequisites[i][0], b=prerequisites[i][1];
        	adj[b].push_back(a); // b --> a
        }
        bool ans = isCyclic(adj, numCourses);
        // cout << (ans == true ? "Cyclic" : "Non-cyclic") << "\n";
        return (ans == false); // If non-cyclic -> CanFinish.
    }
};

int main() {
	int numCourses, n;
	cin >> numCourses, n;
	vector<vector<int>> prerequisites(n, vector<int>(2,0));
	for(int i=0; i<n; i++) {
		for(int j=0; j<2; j++) {
			cin >> prerequisites[i][j];
		}
	}
	Solution solve;
	bool ans = solve.canFinish(numCourses, prerequisites);
	cout << (ans == true ? "true" : "false") << "\n";
	return 0;
}