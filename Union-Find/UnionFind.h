//
// Created by 杨挹 on 1/13/22.
//

#ifndef LEETCODE_SOLUTION_UNIONFIND_H
#define LEETCODE_SOLUTION_UNIONFIND_H

#include<vector>
using namespace std;

class UnionFind {
public:
    UnionFind(vector<vector<char>>& grid);
    int find(int x);
    void merge(int x, int y);
    int getCount();

private:
    vector<int> parent_;
    vector<int> rank_;
    int cnt;
};


#endif //LEETCODE_SOLUTION_UNIONFIND_H
