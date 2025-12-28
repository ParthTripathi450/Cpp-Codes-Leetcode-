/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* build(vector<vector<int>>& grid,int row,int col,int size){
        int first = grid[row][col];
        bool same = true;

        for(int i=row;i<row+size;i++){
            for(int j=col;j<col+size;j++){
                if(grid[i][j]!=first){
                    same = false;
                    break;
                }
            }
            if(!same)break;
        }

        if(same){
            return new Node(first==1,true);
        }
        int half = size/2;
        Node* topleft =build(grid,row,col,half);
        Node* topright = build(grid,row,half+col,half);
        Node* bottomleft = build(grid,half+row,col,half);
        Node* bottomright =build(grid,half+row,half+col,half);

        return new Node(true,false,topleft,topright,bottomleft,bottomright);
    }
    Node* construct(vector<vector<int>>& grid) {
        return build(grid,0,0,grid.size());
    }
};