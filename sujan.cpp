#include<iostream>
using namespace std;
#define max 10

void find_indegree(int cost[max][max],int indegree[],int n){
    int sum;
    for(int i=1;i<=n;i++){
         sum=0;
        for(int j=1;j<=n;j++){
            sum+=cost[j][i];//sum is incremented if there is a edges from j to i
            indegree[i]=sum;
        }
    }
}

/* indegree[max]:to store the degree of each node
topo[max]:to store the sorted order
stack[max]:to store the node with zeroindegree
k:to track the indexof sorted nodes
count: to track the process nodes*/

void topo_sort(int cost[max][max],int n){
    int indegree[max],topo[max],stack[max];
    int k=0,count=0;
    int top=-1;

    find_indegree(cost,indegree,n);

for(int i=1;i<=n;i++){
    if(indegree[i]==0){
        stack[++top]=i;
    }
}

while(top!=-1){//until stack get emty loops run
int u=stack[top--];
topo[++k]=u;
count++;//count increment to travk the provess node

for(int v=1;v<=n;v++){
    if(cost[u][v]==1){
        indegree[v]--;
        if(indegree[v]==0){
            stack[++top]=v;
        }
    }
}

}

if(count!=n){
    cout<<"the graph contain a cycle:";

}else{
    cout<<"topological sort:\n";
    for(int i=1;i<=n;i++){
     cout<<topo[i]+" ";
    }
}
}

int main(){
    int cost[max][max],n;

    cout<<"enter the number of nodes\n";
    cin>>n;

    cout<<"enter the cost matrix:(1 for egde and 0 for no egde)\n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>cost[i][j];
        }
    }

    topo_sort(cost,n);

    return 0;
}


