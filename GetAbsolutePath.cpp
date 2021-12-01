#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

string GetAbsolutePath(string relativePath) {
	int startPos = relativePath.find("/");
	if (startPos == string::npos || startPos == relativePath.length() - 1) {
		return relativePath;
	}
	int endPos = relativePath.find("/", startPos + 1);;

	stack<string> s;
	while (endPos != string::npos) {
		string next = relativePath.substr(startPos + 1, endPos - startPos - 1);
		if (next == "..") {
			s.pop();
		} 
		else if (next != ".") {
			s.push(next);
		}
		startPos = endPos;
		if (startPos == relativePath.length() - 1) {
			break;
		}
		endPos = relativePath.find("/", startPos + 1);
	}

	// get the last one
	if (endPos == string::npos) {
		s.push(relativePath.substr(startPos + 1, endPos - startPos - 1));
	}	

	string ret = "";
	while (!s.empty()) {
		ret = "/" + s.top() + ret;
		s.pop();
	}

	return (ret == "" ? relativePath : ret);
}

int main() {
	// Your code goes here;
	string test = "/ab/bc/cd";
	cout << GetAbsolutePath(test) << endl;
	test = "/ab/bc/./cd";
	cout << GetAbsolutePath(test) << endl;
	test = " /ab/bc/../cd/ef";
	cout << GetAbsolutePath(test) << endl;
	return 0;
}