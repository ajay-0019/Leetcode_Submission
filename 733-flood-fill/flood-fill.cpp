class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color){
            return image;
        }
        int n=image.size();
        int m=image[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int oldcolor=image[sr][sc];
        image[sr][sc]=color;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while(!q.empty()){
            pair<int, int> temp = q.front();
            q.pop();

            int i = temp.first;
            int j = temp.second;

            for (int k = 0; k < 4; k++) {

                int newRow = i + dr[k];
                int newCol = j + dc[k];

                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && image[newRow][newCol]==oldcolor){
                    image[newRow][newCol]=color;
                    q.push({newRow,newCol});
                }
            }
        }
        return image;
    }
};