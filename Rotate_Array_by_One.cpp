class Solution {
  public:
    void rotate(vector<int> &arr) {
        int last = arr.back();
        arr.pop_back();
        arr.insert(arr.begin(), last);
    }
};
