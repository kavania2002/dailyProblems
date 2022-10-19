//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int cnt;
    bool dfs(vector<vector<int>>graph_adjM,int a,vector<int>visited,int b){
        if(b==cnt)return true;
        visited[a]=1;
        bool flag=false;
        for(auto &ver:graph_adjM[a]){
            if(visited[ver]==0 && dfs(graph_adjM,ver,visited,b+1))
            return true;
        }
        visited[a]=0;
        return flag;
    }
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        // code here
        vector<vector<int>>graph_adjM(N);
        vector<int>visited(N,0);
        cnt=N;
        for(auto &edges:Edges){
            graph_adjM[edges[0]-1].push_back(edges[1]-1);
            graph_adjM[edges[1]-1].push_back(edges[0]-1);
        }
        for(int i=0;i<N;i++){
            if(dfs(graph_adjM,i,visited,1))return true;
        }
        return false;
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends