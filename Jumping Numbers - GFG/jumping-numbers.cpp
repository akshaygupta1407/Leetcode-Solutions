// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
  long long ans = 0;
  void bfs(long long X,long long num)
  {
      queue<long long>q;
      q.push(num);
      while(!q.empty())
      {
          num = q.front();
          q.pop();
          if(num<=X)
          {
              ans = max(ans,num);
              int lastdigit = num%10;
              if(lastdigit==0)
              {
                  q.push(num*10 + (lastdigit+1));
              }
              else if(lastdigit==9)
              {
                  q.push(num*10 + (lastdigit-1));
              }
              else
              {
                  q.push(num*10 + (lastdigit-1));
                  q.push(num*10 + (lastdigit+1));
              }
          }
      }
  }
    long long jumpingNums(long long X) {
        // code here
        for(long long i=1;i<=9 && i<=X;i++)
        {
            bfs(X,i);
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    }
    return 0;
}  // } Driver Code Ends