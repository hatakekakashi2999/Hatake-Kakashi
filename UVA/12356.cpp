#include<iostream>
#include<cstdio>
using namespace std;
int lef[100001], righ[100001];
int main(){
  int s, b, l ,r;
  while(true){
    scanf("%d%d", &s, &b);

    if(s == 0 && b == 0)
      break;

    for(int i = 1; i <= s; i++){
      lef[i] = i - 1;
      righ[i] = i + 1;
    }

    lef[1] = -1;
    righ[s] = -1;

    for(int i = 0; i < b; i++){
      scanf("%d%d", &l, &r);

      if(lef[l] != -1){
        printf("%d ", lef[l]);
      }
      else {
        printf("* ");
      }

      if(righ[r] != -1){
        printf("%d", righ[r]);
      }
      else{
        printf("*");
      }
      printf("\n");

      righ[lef[l]] = righ[r];
      lef[righ[r]] = lef[l];
    }

    printf("-\n");
  }
}
