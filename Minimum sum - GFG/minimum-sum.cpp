// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string solve(int arr[], int n) {
        // code here
        sort(arr,arr+n);
        string s1 = "",s2 = "";
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                s1 += (arr[i]+'0');
            }
            else
            {
                s2+= (arr[i]+'0');
            }
        }
        int j = s1.length()-1,k = s2.length()-1;
        int carry = 0;
        string ans = "";
        while(j>=0 && k>=0)
        {
            int sum = (s1[j]-'0') + (s2[k]-'0') + carry;
            ans += to_string(sum%10);
            carry=sum/10;
            k--;
            j--;
        }
        while(j>=0)
        {
            int sum = (s1[j]-'0') + carry;
            ans += to_string(sum%10);
            carry=sum/10;
            j--;
        }
        while(k>=0)
        {
            int sum = (s2[k]-'0') + carry;
            ans += to_string(sum%10);
            carry=sum/10;
            k--;
        }
        if(carry>=0)
        {
            ans+=to_string(carry);
        }
        while(!ans.empty() && ans.back()=='0')
        {
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends