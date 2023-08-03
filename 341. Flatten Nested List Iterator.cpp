/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    int it=0;
    vector<int> ans;

    void rec(vector<NestedInteger> &nestedlist){
        for(int i=0;i<nestedlist.size();i++){
            if(nestedlist[i].isInteger()){
                ans.push_back(nestedlist[i].getInteger());
            }else{
                rec(nestedlist[i].getList());
            }
        }
    }
    NestedIterator(vector<NestedInteger> &nestedlist) {
         rec(nestedlist);
    }
    
    int next() {
        int x=ans.at(it);
        it++;
        return x;
    }
    
    bool hasNext() {
        return it<ans.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
