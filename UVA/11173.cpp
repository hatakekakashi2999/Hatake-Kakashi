/*UVA 11173
*author: hatake kakashi
*/
#include <iostream>
using namespace std;

//n bits, kth position
int findNumberAtPos(int n, int k){
	if(n==1 && k==0) return 0;
	if(n==1 && k==1) return 1;
	//we can have more base cases.
	
	//lower half, so we append 1
	if(k>=(1<<(n-1))){
		return 1<<(n-1)|findNumberAtPos(n-1,(1<<n)-k-1);
	}
	//upper half, so we recurse by appending 0; ie we don't append anything;
	else{
		return findNumberAtPos(n-1,k);
	}
}



int main() {
	int n, k,tc;
	cin>>tc;
	while(tc--){
		cin>>n>>k;
		cout<<findNumberAtPos(n,k)<<endl;
	}
	return 0;
}