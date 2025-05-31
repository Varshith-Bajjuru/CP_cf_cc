#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class SegmentTree {
private:
    vector<T> tree;
    vector<T> arr;
    int n;
    T (*merge)(T, T);

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void update(int node, int start, int end, int idx, T val) {
        if (start == end) {
            arr[idx] = val;
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node, start, mid, idx, val);
            } else {
                update(2 * node + 1, mid + 1, end, idx, val);
            }
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }
    }

    T query(int node, int start, int end, int L, int R) {
        if (R < start || L > end) return 0; // Adjust based on operation (e.g., INF for min queries)
        if (L <= start && end <= R) return tree[node];
        int mid = (start + end) / 2;
        T left = query(2 * node, start, mid, L, R);
        T right = query(2 * node + 1, mid + 1, end, L, R);
        return merge(left, right);
    }

public:
    SegmentTree(vector<T>& inputArr, T (*mergeFunc)(T, T)) {
        arr = inputArr;
        n = arr.size();
        tree.resize(4 * n);
        merge = mergeFunc;
        build(1, 0, n - 1);
    }

    void update(int idx, T val) {
        update(1, 0, n - 1, idx, val);
    }

    T query(int L, int R) {
        return query(1, 0, n - 1, L, R);
    }
};

int sumMerge(int a, int b) {
    return a + b;
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree<int> segTree(arr, sumMerge);

    cout << "Sum of range [1,4]: " << segTree.query(1, 4) << endl;

    segTree.update(2, 10);
    cout << "After update, sum of range [1,4]: " << segTree.query(1, 4) << endl;

    return 0;
}
