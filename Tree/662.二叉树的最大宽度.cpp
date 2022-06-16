#include "TreeNode.h"
#include <queue>
using namespace std;

//层次遍历解法
class Solution {
public:
    //由于官方更新了测试用例，导致用原本二叉树的val记录编号（int型）会造成溢出。
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode *, long long>> q; //队列记录二叉树的结点和一个对应的long long型编号
        int res = 0; //保存结果
        if(!root) return 0; //如果为空树，直接返回0；
        q.push(make_pair(root, 0)); //根节点入队，并记录对应编号
        while(!q.empty()){
            res = max(res, (int)(q.back().second-q.front().second+1)); //更新每层宽度最大值
            int len = q.size(); //每一层结点数
            int offset = q.front().second; //以每层第一个结点的值为偏移值，保持每层结点之间的相对关系，缩小索引
            for(int i=0;i<len;i++){
                root = q.front().first;
                long long val = q.front().second; //获取root结点对应的编号
                q.pop();
                val -= offset; //缩小编号索引
                if(root->left){
                    q.push(make_pair(root->left, val*2));//左孩子的编号为parent编号*2

                }
                if(root->right){
                    q.push(make_pair(root->right, val*2+1)); //右孩子的编号为parent编号*2+1
                }
            }
        }
        return res;
    }
};
