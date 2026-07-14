class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        //edge cases ko dekhte hai 
        // starting or end  blocked toh nhi hai
        if(grid[0][0]==1 || grid[n-1][n-1]==1){
            return -1;
        }
         // sirf single cell ho toh
         if(n==1)
         {
            return 1;
         }
        
        // main code implementation
        queue<pair<int,int>> q ;
        q.push({0,0});  // starting node ko push kar do 
        grid[0][0]= 1; // visited mark bhe kar do turant;
        int distance =1;
        
        // striver trick of making direction array
        int drow[8] = {-1,-1,-1,0,0,1,1,1};
        int dcol[8] = {-1,0,1,-1,1,-1,0,1};

        //conditons checking 
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                auto[r,c]=q.front();
                q.pop();
                
                // agar destination mil jaye toh
                if(r == n-1 && c == n-1)
                {
                    return distance;
                }

                // varna neigbour ko visit karo

                for(int i=0; i<8 ; i++)
                {
                    int neighrow = r + drow[i];
                    int neighcol = c + dcol[i];

                    // out of boundary / grid condition and blocked  bhe nhi hona chaiye toh vo bhe conditon checking
                    if( neighrow >= 0 && neighrow < n && neighcol >= 0  && neighcol < n && grid[neighrow][neighcol] == 0)
                    {
                        q.push({neighrow, neighcol});
                        grid[neighrow][neighcol]= 1;

                    }
                    
                }
            }
            distance ++;
        }
        return -1;
    }
};