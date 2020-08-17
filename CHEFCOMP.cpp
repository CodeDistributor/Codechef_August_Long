#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int main() {
    long long int t;
    cin>>t;
    
    while(t--){
       long long int n;
       cin>>n;
       
       unordered_map<long long int,int> g[n+1];
       long long int p[n+1];
       long long int a[n+1];
       long long int b[n+1];
       
       long long int d[n+1];
       
        for(long long int i=0;i<=n;i++){
           d[i]=-1;
        }
       
       for(long long int i=1;i<=n-1;i++){
           long long int u,v;
           cin>>u>>v;
        
            g[u][v]=1;
            g[v][u]=1;
       }
       
       for(long long int i=1;i<=n;i++){
           cin>>p[i];
       }
       
        for(long long int i=1;i<=n;i++){
           cin>>a[i];
       }
       
        for(long long int i=1;i<=n;i++){
           cin>>b[i];
       }
       
       for(long long int i=1;i<=n;i++){
           long long int visited[n+1] = {0};
           long long int city = p[i];
    
           stack<long long int> q;
           q.push(city);
           
           while(!q.empty()){
               long long int source = q.top();
               q.pop();
               
               
              if(visited[source]){
                  continue;
              }else{
                  visited[source]=1;
                  
                   b[source] = b[source] - min(a[city],b[source]);
                    if(b[source]<=0 && d[source]==-1){
                         d[source] = i;
                    }
              }
               
               for(auto child : g[source]){
                  if(child.second && !visited[child.first]){
                       q.push(child.first);
                  }
               }
           }
           
            for(auto child : g[city]){
                g[city][child.first]=0;
                g[child.first][city]=0;
                 

            }
       
       }
       for(long long int i=1;i<=n;i++){
           cout<<d[i]<<" ";
       }
      
       cout<<"\n";
    }
  return 0;
}