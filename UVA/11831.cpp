#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
string a[105];
int tx, ty;
char tcurr;

void findNext(int x, int y, char curr, char comm){
  tx=x,ty=y,tcurr=curr;
  if(comm=='D'){
    if(curr=='N'){
      tcurr='L';
    }
    else if(curr=='L'){
      tcurr='S';
    }
    else if(curr=='S'){
      tcurr='O';
    }
    else if(curr=='O'){
      tcurr='N';
    }
  }
  else if(comm=='E'){
    if(curr=='N'){
      tcurr='O';
    }
    else if(curr=='O'){
      tcurr='S';
    }
    else if(curr=='S'){
      tcurr='L';
    }
    else if(curr=='L'){
      tcurr='N';
    }
  }
  else if(comm=='F'){
    if(curr=='N'){
      tx=x-1;
    }
    else if(curr=='L'){
      ty=y+1;
    }
    else if(curr=='S'){
      tx=x+1;
    }
    else if(curr=='O'){
      ty=y-1;
    }
  }
}
int main(){
  int n,m,s,x,y;
  //freopen("11831-in.txt","r",stdin);
  while(true){
    cin>>n>>m>>s;
    bool found=false;
    if(n==0&&m==0&&s==0) break;
    for(int i=0;i<n;i++){
      cin>>a[i];
      for(int j=0;j<m&&(!found);j++){
        if(a[i][j]=='N'||a[i][j]=='S'||a[i][j]=='L'||a[i][j]=='O'){
          x=i;
          y=j;
          found=true;
          break;
        }
      }
    }
    string ins;
    cin>>ins;
    char curr=a[x][y];
    int res=0;
    for(int i=0;i<ins.length();i++){
      //cout<<x<<" "<<y<<endl;
      findNext(x, y, curr, ins[i]);
      if(tx>=0&&tx<n&&ty>=0&&ty<m&&a[tx][ty]!='#'){
        x=tx,y=ty,curr=tcurr;
        if(a[x][y]=='*'){
          res++;
          a[x][y]='.';
        }
      }
    }
    cout<<res<<endl;
  }
}
