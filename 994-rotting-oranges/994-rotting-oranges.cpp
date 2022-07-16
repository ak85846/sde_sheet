class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;
        int n=grid.size();
        int m=grid[0].size();
        int count=0,orancount=0,minute=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0)
                    orancount++;
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        int di[4]={0,0,1,-1};
        int dj[4]={1,-1,0,0};
        while(!q.empty()){
            int qsize=q.size();
            count+=qsize;
            while(qsize--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                 int nx=x+di[i];
                 int ny=y+dj[i];
                    if(nx<0 || ny<0 || nx>=n || ny>=m || grid[nx][ny]!=1)
                        continue;
                    grid[nx][ny]=2;
                    q.push({nx,ny});
                }
            }
            if(!q.empty())
                minute++;
        }
        return count==orancount?minute:-1;
        
    }
};