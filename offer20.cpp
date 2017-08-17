/*
定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数
*/
class Solution {
public:
    void push(int value) {
        if(minData.empty()){
            minData.push(value);
        }
        else{
            if(minData.top()<value)
            minData.push(minData.top());
            else minData.push(value);
        }
        data.push(value);
    }
    void pop() {
        data.pop();
        minData.pop();
    }
    int top() {
        return data.top();
    }
    int min() {
        return minData.top();
    }
private:
    //int a[]
    stack<int> data,minData;
     
};
