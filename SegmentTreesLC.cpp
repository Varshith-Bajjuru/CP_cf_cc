#include <bits/stdc++.h>
using namespace std;

class NumArray {
public:
    int n;
    vector<int> tree;

    int merge(int x,int y){
        return x+y;
    }

    void buildTree(vector<int> &nums,int l,int r,int node){
        if (l == r){
            tree[node] = nums[l];
            return;
        }
        int mid = l + (r-l)/2;
        buildTree(nums,l,mid,2*node);
        buildTree(nums,mid+1,r,2*node+1);
        tree[node] = merge(tree[2*node],tree[2*node + 1]);
    }

    void updateTree(int l,int r,int node,int idx,int val){
        if (l == r) {
            tree[node] = val;
            return;
        }

        int mid = l + (r-l)/2;
        if (idx <= mid){
            updateTree(l,mid,2*node,idx,val);
        }else updateTree(mid+1,r,2*node+1,idx,val);

        tree[node] = merge(tree[2*node],tree[2*node + 1]);
    }

    int query(int start,int end,int node,int l,int r){
        if (l == start && r == end){
            return tree[node];
        }
        if (l > r) return 0;

        int mid = start + (end - start)/2;
        int lsum = query(start,mid,2*node,l, min(r,mid));
        int rsum = query(mid+1,end,2*node+1,max(l,mid+1),r);

        return lsum + rsum;
    }

    NumArray(vector<int>& nums) {
        n = (int)nums.size();
        tree.resize(4*n+1,0);
        buildTree(nums,0,n-1,1);
    }

    void update(int index, int val) {
        return updateTree(0,n-1,1,index,val);
    }

    int sumRange(int left, int right) {
        return query(0,n-1,1,left,right);
    }
};
