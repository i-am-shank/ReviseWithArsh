#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> stk;
        for(int i=0; i<n; i++) {
        	if((tokens[i]=="*") || (tokens[i]=="+") || (tokens[i]=="/") || (tokens[i]=="-")) {
        		int n1=stk.top();
        		stk.pop();
        		int n2 = stk.top();
        		stk.pop();
        		int curr;
        		if(tokens[i] == "*") {
        			curr = (n2*n1);
        		}
        		else if(tokens[i] == "+") {
        			curr = (n2+n1);
	        	}
	        	else if(tokens[i] == "/") {
	        		curr = (n2/n1);
	        	}
	        	else {
	        		curr = (n2-n1);
	        	}
        		stk.push(curr);
        	}
        	else {
        		int num = stoi(tokens[i]);
        		stk.push(num);
        	}
        }
        int ans = stk.top();
        stk.pop();
        return ans;
    }
};

int main() {
	int n;
	cin >> n;
	vector<string> tokens(n);
	for(int i=0; i<n; i++) {
		cin >> tokens[i];
	}
	Solution solve;
	int ans = solve.evalRPN(tokens);
	cout << ans << "\n";
	return 0;
}