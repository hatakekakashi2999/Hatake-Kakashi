#include<iostream>
using namespace std;
int main(){
  int k, n, m, x, y;
  while (true) {
    cin >> k;
    if(!k) break;
    cin >> n >> m;
    while(k--){
      cin >> x >> y;
      if(n == x || m == y) cout << "divisa" << endl;
      else if(x > n && y < m) cout << "SE" << endl;
      else if(x > n && y > m) cout << "NE" << endl;
      else if(x < n && y > m) cout << "NO" << endl;
      else if(x < n && y < m) cout << "SO" << endl;
    }
  }
}
