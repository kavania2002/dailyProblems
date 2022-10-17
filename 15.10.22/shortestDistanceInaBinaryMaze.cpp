  
  //https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1
  
  class Solution{
  public:

    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,

                     pair<int, int> destination) {

        

        int n = grid.size();

        int m = grid[0].size();

        

        int x1 = source.first;

        int y1 = source.second;

        

        int x2 = destination.first;

        int y2 = destination.second;

        

        if(grid[x1][y1] == grid[x2][y2] == 1 && n==1 && m==1) return 0;

        

        if(x1 == x2 && y1 == y2) return 0;

        queue<pair<pair<int,int>,int>> q;

        q.push({{x1,y1},0});

        

        vector<vector<int>> vis(n, vector<int> (m,0));

        vis[x1][y1] = 1;

        

        while(!q.empty()){

            pair<int,int> p = q.front().first;

            int x = p.first;

            int y = p.second;

            

            int lengthOfPath = q.front().second;

            q.pop();

            

            vector<pair<int,int>> neighbours = {{0,1},{0,-1},{1,0},{-1,0}};

            

            for(pair<int,int> neighbour : neighbours){

                int newx = neighbour.first + x;

                int newy = neighbour.second + y;

                
                

                if(newx >= 0 && newy>=0 && newx < n && newy<m && grid[newx][newy] == 1 && !vis[newx][newy]){

                    {

                        q.push({{newx,newy},lengthOfPath+1});

                        vis[newx][newy] = 1;


                        if(newx == x2 && newy == y2){


                            return lengthOfPath+1;

                        }

                    }

                }

             

        }

        return -1;

    }

};