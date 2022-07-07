// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution{
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        sort(arr.begin(), arr.end());
        int abd = 999999;
        int ans;
        for (int f = 0; f <= arr.size() - 3; f++)
        {
            int i = f + 1;
            int j = arr.size() - 1;
            while (i < j)
            {
                int tsum = arr[f] + arr[i] + arr[j];
                if (tsum <= target)
                {
                    if(abs(tsum - target) == abd)
                    {
                        ans = max(tsum,ans);
                    }
                    else if (abs(tsum - target) < abd)
                    {
                        abd = abs(tsum - target);
                        ans = tsum;
                    }
                    i++;
                }
                else if (tsum > target)
                {
                    if(abs(tsum - target) == abd)
                    {
                        ans = max(tsum,ans);
                    }
                    else if (abs(tsum - target) < abd)
                    {
                        abd = abs(tsum - target);
                        ans = tsum;
                    }
                    j--;
                }
            }
        }
        return ans;
    }
};



// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while(t--) {
        
        int n,target;
        cin >> n >> target;
        
        vector<int> vec(n);
        
        for(int i = 0 ; i < n ; ++ i ) 
            cin >> vec[i];
        Solution obj;
        cout << obj.threeSumClosest(vec, target) << "\n";
    }
}

//Position this line where user code will be pasted.
  // } Driver Code Ends