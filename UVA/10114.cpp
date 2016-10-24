#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
//(month, depreciation rates)
double dep[101];
int main(){
  int m, n;
  float d, l;
  while(true){
    // duration of loans, down payment, loan amount, number of records to follow
    cin >> m >> d >> l >> n;
    if(m < 0) break;

    //hack. see line 35 for details
    for(int i = 0; i < 101; i++){
      dep[i] = -1;
    }

    for(int i = 0; i < n; i++){
      //month, depreciation rate
      int month;
      float rate;
      cin >> month >> rate;
      dep[month] = rate;
    }

    //iterate till money owed < car's worth
    float worth = (l + d) * (1 - dep[0]);
    float owed = l;
    float monthly = l / m;
    int monthCount = 0;
    while(worth <= owed){
      monthCount++;
      owed -= monthly;
      if (dep[monthCount] == -1) dep[monthCount] = dep[monthCount - 1];
      worth = worth * (1 - dep[monthCount]);
    }
    cout<<monthCount<<" month";
    if(monthCount != 1) cout << "s";
    cout<<endl;

  }
}
