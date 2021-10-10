class Solution {
    public:
        //LEETCODE -- 130
        void DFS(vector < vector < char >> & board, int i, int j, int m, int n) {
            if (i < 0 or j < 0 or i >= m or j >= n or board[i][j] != 'O') return;
            board[i][j] = '#';
            DFS(board, i - 1, j, m, n);
            DFS(board, i + 1, j, m, n);
            DFS(board, i, j - 1, m, n);
            DFS(board, i, j + 1, m, n);
        }

    void solve(vector < vector < char >> & board) {

        //We will use boundary DFS to solve this problem

        // Let's analyze when an 'O' cannot be flipped,
        // if it has atleast one 'O' in it's adjacent, AND ultimately this chain of adjacent 'O's is connected to some 'O' which lies on boundary of board

        //consider these two cases for clarity :
        /*
          O's won't be flipped          O's will be flipped
          [X O X X X]                   [X X X X X]     
          [X O O O X]                   [X O O O X]
          [X O X X X]                   [X O X X X] 
          [X X X X X]                   [X X X X X]
        
        So we can conclude if a chain of adjacent O's is connected some O on boundary then they cannot be flipped
        
        */

        //Steps to Solve :
        //1. Move over the boundary of board, and find O's 
        //2. Every time we find an O, perform DFS from it's position
        //3. In DFS convert all 'O' to '#'      (why?? so that we can differentiate which 'O' can be flipped and which cannot be)   
        //4. After all DFSs have been performed, board contains three elements,#,O and X
        //5. 'O' are left over elements which are not connected to any boundary O, so flip them to 'X'
        //6. '#' are elements which cannot be flipped to 'X', so flip them back to 'O'
        //7. finally, Upvote the solution😊   

        int m = board.size();

        if (m == 0) return;

        int n = board[0].size();

        //Moving over firts and last column   
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O')
                DFS(board, i, 0, m, n);
            if (board[i][n - 1] == 'O')
                DFS(board, i, n - 1, m, n);
        }

        //Moving over first and last row   
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O')
                DFS(board, 0, j, m, n);
            if (board[m - 1][j] == 'O')
                DFS(board, m - 1, j, m, n);
        }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
    }
};
