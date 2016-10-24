#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;
vector<string> big;
vector<string> small;
int N, n;

int count(){
  int c = 0;
  bool match = true;
  for(int i = 0; i < N - n + 1; i++){
    for(int j = 0; j < N - n + 1; j++){
      match = true;
      for(int m = i, k = 0; k < n; m++, k++){
        for(int o = j,l = 0; l < n; o++, l++){
          if(big[m][o] != small[k][l]){
            match = false;
            break;
          }
        }
        if(!match) break;
      }
      if(match) c++;
    }
  }
  return c;
}

int count90(){
  int c = 0;
  bool match = true;
  for(int i = 0; i < N - n + 1; i++){
    for(int j = 0; j < N - n + 1; j++){
      match = true;
      for(int m = i, l = 0; l < n; m++, l++){
        for(int o = j, k = n - 1; k >= 0; o++, k--){
          if(big[m][o] != small[k][l]){
            match = false;
            break;
          }
        }
        if(!match) break;
      }
      if(match) c++;
    }
  }
  return c;
}

int count180(){
  int c = 0;
  bool match = true;
  for(int i = 0; i < N - n + 1; i++){
    for(int j = 0; j < N - n + 1; j++){
      match = true;
      for(int m = i, k = n - 1; k >= 0; m++, k--){
        for(int o = j, l = n - 1; l >= 0; o++, l--){
          if(big[m][o] != small[k][l]){
            match = false;
            break;
          }
        }
        if(!match) break;
      }
      if(match) c++;
    }
  }
  return c;
}

int count270(){
  int c = 0;
  bool match = true;
  for(int i = 0; i < N - n + 1; i++){
    for(int j = 0; j < N - n + 1; j++){
      match = true;
      for(int m = i, l = n - 1; l >= 0; m++, l--){
        for(int o = j, k = 0; k < n; o++, k++){
          if(big[m][o] != small[k][l]){
            match = false;
            break;
          }
        }
        if(!match) break;
      }
      if(match) c++;
    }
  }
  return c;
}

int main(){
  while(true){
    cin >> N >> n;
    if(N==0 && n == 0) break;
    string s;

    big.resize(N);
    for(int i = 0; i < N ; i++){
      big[i].resize(N);
    }
    for(int i = 0; i < N; i++){
      cin >> s;
      big[i] = s;
    }

    small.resize(n);
    for(int i = 0; i < n ; i++){
      small[i].resize(n);
    }
    for(int i = 0; i < n; i++){
      cin >> s;
      small[i] = s;
    }

    cout << count() << " " << count90() << " " << count180() << \
    " " << count270() << endl;
  }
}
