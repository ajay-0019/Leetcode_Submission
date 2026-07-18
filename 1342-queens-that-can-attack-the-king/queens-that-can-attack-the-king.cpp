class Solution {
public:
    void check(vector<vector<int>> &ans,vector<vector<bool>> &isqueen,int row, int col){
        int x=row;
        int y=col;
        while(x>0){
            if(isqueen[x-1][y]==true){
                ans.push_back({x-1,y});
                break;
            }
            x--;
        }
        x=row;
        while(x<7){
            if(isqueen[x+1][y]==true){
                ans.push_back({x+1,y});
                break;
            }
            x++;
        }
        x=row;
        while(y>0){
            if(isqueen[x][y-1]==true){
                ans.push_back({x,y-1});
                break;
            }
            y--;
        }
        x=row;
        while(y<7){
            if(isqueen[x][y+1]==true){
                ans.push_back({x,y+1});
                break;
            }
            y++;
        }
        y=col;x=row;
        while(x>0 && y<7){
            if(isqueen[x-1][y+1]==true){
                ans.push_back({x-1,y+1});
                break;
            }
            x--;
            y++;
        }
        x=row;y=col;
        while(x<7 && y>0){
            if(isqueen[x+1][y-1]==true){
                ans.push_back({x+1,y-1});
                break;
            }
            x++;
            y--;
        }
        x=row;y=col;
        while(x>0 && y>0){
            if(isqueen[x-1][y-1]==true){
                ans.push_back({x-1,y-1});
                break;
            }
            x--;
            y--;
        }
        x=row;y=col;
        while(x<7 && y<7){
            if(isqueen[x+1][y+1]==true){
                ans.push_back({x+1,y+1});
                break;
            }
            x++;
            y++;
        }

    }
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> ans;
        vector<vector<bool>> isqueen(8,vector<bool>(8,false));
        for(const auto& x:queens){
            isqueen[x[0]][x[1]]=true;
        }
        check(ans,isqueen,king[0],king[1]);
        return ans;
    }
};