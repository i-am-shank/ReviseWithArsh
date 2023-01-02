#include <bits/stdc++.h>
using namespace std;

class Solution {
	void getCombn_rec(int k, int n, set<vector<int>>& ans, vector<int> arr, int curr) {
		if(k == 0) {
			sort(arr.begin(), arr.end());
			int sum = 0;
			for(int i=0; i<arr.size(); i++) {
				sum += arr[i];
			}
			if(sum == n) {
				ans.insert(arr);
			}
			return;
		}
		if(curr > 9) {
			// This can't be included in array
			return;
		}
		getCombn_rec(k, n, ans, arr, curr+1); // not-take current no.
		arr.push_back(curr);
		getCombn_rec(k-1, n, ans, arr, curr+1); // take current no.
		return;
	}

public:
    vector<vector<int>> combinationSum3(int k, int n) {
    	vector<int> arr;
    	set<vector<int>> setVec;
        getCombn_rec(k, n, setVec, arr, 1);
        vector<vector<int>> ans;
        for(auto it: setVec) {
        	ans.push_back(it);
        }
        return ans;
    }
};

int main() {
	int k, n;
	cin >> k >> n;
	Solution solve;
	vector<vector<int>> ans = solve.combinationSum3(k, n);
	for(int i=0; i<ans.size(); i++) {
		for(int j=0; j<ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}