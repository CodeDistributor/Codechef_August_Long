#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int fin_ans[1001][1001] = {0};

long long int cal(int start,int end,long long int f[],int k){
    if(start==end){
        return k;
    }
    int fam[101] = {0};
    long long int ans = k;
    for(int i=start;i<=end;i++){
       fam[f[i]]++;
    }
    for(int i=0;i<=100;i++){
        if(fam[i]>1){
            ans+=fam[i];
        }
    }
    return ans;
}

long long int fun(int start,int end,long long int f[],int k){
    if(start>end){
        return 0;
    }
    if(start==end){
        return k;
    }
    if(fin_ans[start][end]!=0){
        return fin_ans[start][end];
    }
    long long int final_ans = INT_MAX;
    
    for(int i=start;i<=end;i++){
        final_ans = min(final_ans,cal(start,i,f,k) + fun(i+1,end,f,k));
    }
    
    fin_ans[start][end] = final_ans;
    return fin_ans[start][end];
}

int main() {
    long long int t;
    cin>>t;
    while(t--){
       long long int n,k;
       cin>>n>>k;
       long long int f[n];
       long long int ans = k;
       int fam[101] = {0};
       
       for(int i=0;i<1001;i++){
           for(int j=0;j<1001;j++){
               fin_ans[i][j] = 0;
           }
       }
       
       for(int i=0;i<n;i++){
           cin>>f[i];
       }
       
       cout<<fun(0,n-1,f,k)<<endl;
       
    }
  return 0;
}