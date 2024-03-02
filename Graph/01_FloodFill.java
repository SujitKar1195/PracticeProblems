
// Problem Link
// https://www.geeksforgeeks.org/problems/flood-fill-algorithm1856/1

class Pair{
    int row;
    int col;
    public Pair(int r, int c)
    {
        row = r;
        col = c;
    }
}

class Solution
{
    public void bfs(int [][]image, int [][]vis, int r, int c, 
    int sr, int sc,int initColor ,int newColor)
    {
        Queue<Pair> q = new LinkedList<>();
        q.offer(new Pair(sr,sc));
        while(!q.isEmpty())
        {
            int row = q.peek().row;
            int col = q.peek().col;
            q.poll();
            if(vis[row][col] == 1) continue;
            image[row][col] = newColor;
            vis[row][col] = 1;
            
            if(row > 0 && image[row-1][col] == initColor && vis[row-1][col] == 0 )
            {
                
                q.offer(new Pair(row-1, col));
            }
            if(col>0 && image[row][col-1] == initColor && vis[row][col-1] == 0)
            {
                
                q.offer(new Pair(row, col-1));
            }
            
            if(row<r-1 && image[row+1][col]==initColor && vis[row+1][col] == 0)
            {
                
                q.offer(new Pair(row+1,col));
            }
            
            if(col<c-1 && image[row][col+1]==initColor && vis[row][col+1] == 0)
            {
        
                q.offer(new Pair(row,col+1));
            }
            
        }
        
        
    }
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor)
    {
        int initColor = image[sr][sc];
        int r = image.length;
        int c = image[0].length;
        int [][]vis = new int[r][c];
        
        bfs(image, vis, r, c, sr, sc,initColor,newColor);
        return image;
    }
}