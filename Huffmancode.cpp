//2013012085_À¯º´¹Î_A
//Huffmancode.cpp

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>

using namespace std;

class Element {

public:
   int idx;
   int cnt;
   int left;
   int right;

   const bool operator < (const Element& Element) const {
      return (cnt > Element.cnt);
   }
};

int ROOT = 0;
priority_queue<Element> PQ;
Element arr[666666];
int sum = 0;

void dfs(int now, int depth) {
   if (now == -1) return;
   if (arr[now].left == -1 && arr[now].right == -1) {
      sum += depth*arr[now].cnt;
      return;
   }

   if (arr[now].left != -1) dfs(arr[now].left, depth + 1);
   if (arr[now].right != -1) dfs(arr[now].right, depth + 1);
}


int main() {

   int N;
   cin >> N;

   int mul = 1;

   for (; mul < N; mul *= 2);
   int digit = 0;
   while (mul > 1) {
      digit++;
      mul /= 2;
   }
   if (digit == 0) digit++;

   for (int i = 0; i < N; i++) {
      string str;
      int num;
      cin >> str >> num;

      Element temp;
      temp.idx = ++ROOT;
      temp.cnt = num;
      temp.left = -1;
      temp.right = -1;

      PQ.push(temp);
      arr[ROOT] = temp;
   }

   int CNT;
   cin >> CNT;

   while (PQ.size() > 1) {

      Element LEFT = PQ.top(); PQ.pop();
      Element RIGHT = PQ.top(); PQ.pop();

      Element TEMP;
      TEMP.idx = ++ROOT;
      TEMP.left = LEFT.idx;
      TEMP.right = RIGHT.idx;
      TEMP.cnt = LEFT.cnt + RIGHT.cnt;
      PQ.push(TEMP);
      arr[ROOT] = TEMP;
   }

   dfs(PQ.top().idx, 0);
   cout << CNT * digit << endl;
   if (ROOT == 1) cout << CNT << endl;
   else cout << sum << endl;

   return 0;
}
