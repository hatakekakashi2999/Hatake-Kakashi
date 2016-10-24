#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int tc;
  int a[3];
  cin >> tc;
  for(int zz = 1; zz <= tc; zz++){
    cin >> a[0] >> a[1] >> a[2];
    //sometimes it is about the method that takes the least time to code
    //without exceeding the time limit
    sort(a, a + 3);
    cout << "Case " << zz << ": " << a[1] << endl;
  }
}
