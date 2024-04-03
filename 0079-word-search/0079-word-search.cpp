class Solution {
public:
    vector<pair<int, int>> directions={{0,1},{0,-1},{1,0},{-1,0}};
    bool searchdfs(vector<vector<char>>& board,vector<vector<bool>>& visited,int i,int j,string word,int idx){
      //  cout<<idx<<" "<<word[idx]<<endl;
        
        
        if(idx==word.size()-1) return true;
        for(auto direction: directions){
            int targetI=i+direction.first;
            int targetJ=j+direction.second;
            if(targetI < board.size()
               && targetJ < board[0].size()
               && targetI >=0
               && targetJ >=0
               && !visited[targetI][targetJ]
               && board[targetI][targetJ]==word[idx+1]
               ){
                visited[targetI][targetJ]=true;
                if(searchdfs(board,visited, targetI, targetJ, word, idx+1)) return true;
                visited[targetI][targetJ]=false;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),false));
                    visited[i][j]=true;
                    if(searchdfs(board,visited,i,j,word,0)) return true;
                    visited[i][j]=false;
                }
            }
        }
        return false;
    }
};