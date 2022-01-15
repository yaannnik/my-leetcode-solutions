//
// Created by 杨挹 on 1/13/22.
//

#include "UnionFind.h"

UnionFind::UnionFind(vector<vector<char>> &grid) {
    cnt = 0;
    int m = grid.size(), n = grid[0].size();
    rank_ = vector<int>((m+1) * (n+1), 0);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == '1') {
                parent_.emplace_back(i * n + j);
                cnt++;
            } else {
                parent_.emplace_back(-1);
            }
        }
    }
}

int UnionFind::find(int x) {
    if(parent_[x] != x) {
        parent_[x] = find(parent_[x]);
    }
    return parent_[x];
}

void UnionFind::merge(int x, int y) {
    int rootx = find(x);
    int rooty = find(y);
    if (rootx != rooty) {
        if (rank_[rootx] < rank_[rooty]) {
            swap(rootx, rooty);
        }
        parent_[rooty] = rootx;
        if (rank_[rootx] == rank_[rooty]) rank_[rooty] += 1;
        cnt--;
    }
}

int UnionFind::getCount() {
    return cnt;
}