#include <iostream>
#include <vector>
#include <cstring>                                                    

using namespace std;

void MergeSorted(vector<int> &target, const vector<int> &source)
{
	// sizeof(target) = M
	// sizeof(source) = N
	// best speed = O(max(M,N))
	// best space = O(M+N)

	int M = target.size();
	int N = source.size();
	
	target.resize(M+N);
	
	int end = ((M-- + N--) - 1);

	while (M >= 0 && N >= 0) {
            if (target[M] > source[N]) {
	        target[end--] = target[M--];
	    } 
	    else if (target[M] < source[N]) {
	        target[end--] = source[N--];
	    } 
	    else {
	        // target[M] == source[N]
	        target[end--] = target[M--];
	        target[end--] = source[N--];
	    }
	}
        
	// if M > 0 ok, because is already sorted at front of target
        while (N >= 0) {
	      target[end--] = source[N--];
        }
}

int main() {
    vector<int> target = {1, 2, 2, 2, 3, 4, 4};
    const vector<int> source = {2, 3, 4};
    
    MergeSorted(target, source);
    
    for (int n : target) {
        cout << n << ", ";
    }
    cout << endl;
    
}
