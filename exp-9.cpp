// Problem - 1 - No. Of Islands
class Solution { 
public: 
    void dfs(vector<vector<char>>& grid, int i, int j) { 
        int m = grid.size(), n = grid[0].size(); 
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0') { 
            return; 
        } 
        grid[i][j] = '0'; 
        dfs(grid, i + 1, j); 
        dfs(grid, i - 1, j); 
        dfs(grid, i, j + 1); 
        dfs(grid, i, j - 1); 
    } 
    int numIslands(vector<vector<char>>& grid) { 
        if (grid.empty()) return 0; 
        int m = grid.size(), n = grid[0].size(), count = 0; 
        for (int i = 0; i < m; ++i) { 
            for (int j = 0; j < n; ++j) { 
                if (grid[i][j] == '1') { 
		    ++count; 
                    dfs(grid, i, j); 
                } 
            } 
        } 
        return count; 
    } 
}; 

// Problem - 2 - Surrounded Regions
class Solution {
public:
    void dfs(vector<vector<char>> board, int sr, int sc,  vector<vector<bool>> &vis){
        int m = board.size();
        int n = board[0].size();

        queue<pair<int, int>> q;
        q.push({sr, sc});   vis[sr][sc] = true;

        int dirX[] = {1, 0, -1, 0};
        int dirY[] = {0, 1, 0, -1};

        while(!q.empty()){
            auto e = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int newX = e.first + dirX[i];
                int newY = e.second + dirY[i];

                if(newX >= 0 && newX < m && newY >= 0 && newY < n && board[newX][newY] == 'O' && !vis[newX][newY]){
                    q.push({newX, newY});
                    vis[newX][newY] = true;
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        // Top Row i = 0
        for(int j = 0; j < n; j++){
            if(board[0][j] == 'O' && !vis[0][j])    dfs(board, 0, j, vis);
        }

        // Bottom Row i = m - 1
        for(int j = 0; j < n; j++){
            if(board[m - 1][j] == 'O' && !vis[m - 1][j])    dfs(board, m - 1, j, vis);
        }

        // Left Cloumn j = 0
        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O' && !vis[i][0])    dfs(board, i, 0, vis);
        }

        // Right Column j = n - 1
        for(int i = 0; i < m; i++){
            if(board[i][n - 1] == 'O' && !vis[i][n - 1])    dfs(board, i, n - 1, vis);
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if (!vis[i][j] && board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};

// Problem - 3 - Lowest Common Ancestor of a Binary Tree 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left != nullptr && right != nullptr) {
            return root;
        }

        return left != nullptr ? left : right;        
    }
};
