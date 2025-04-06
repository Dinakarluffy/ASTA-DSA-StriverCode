#include<bits/stdc++.h>

using namespace std;
class MyStack {
  deque<int> ans;
public:
MyStack() {
     ans = deque<int>(); // Initialize an empty deque
 }
 
 void push(int x) {
     ans.push_back(x);
 }
 
 int pop() {
     int topElement = ans.back();
     ans.pop_back();
     return topElement;
 }
 
 int top() {
     return ans.back();
 }
 
 bool empty() {
     return ans.empty();
 }
};

class Stack {
  queue < int > q;
  public:
    void Push(int x) {
      int s = q.size();
      q.push(x);
      for (int i = 0; i < s; i++) {

        q.push(q.front());
        q.pop();
      }
    }
  int Pop() {
    int n = q.front();
    q.pop();
    return n;
  }
  int Top() {
    return q.front();
  }
  int Size() {
    return q.size();
  }
};

int main() {
  Stack s;
  s.Push(3);
  s.Push(2);
  s.Push(4);
  s.Push(1);
  cout << "Top of the stack: " << s.Top() << endl;
  cout << "Size of the stack before removing element: " << s.Size() << endl;
  cout << "The deleted element is: " << s.Pop() << endl;
  cout << "Top of the stack after removing element: " << s.Top() << endl;
  cout << "Size of the stack after removing element: " << s.Size();

}
