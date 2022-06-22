// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
 public:
   
   string longestCommonPrefix (string arr[], int N)
   {
       string rez = ""; // solution variable
       int minim = INT_MAX; // variable to store the minimum length of strings
       int minimIndex = -1; // the minimum length string index
       for(int i=0; i<N; i++)
           if(arr[i].size() < minim){
               minim = arr[i].size();
               minimIndex = i;
           }
       //above function search for the minimum string (as length)
       for(int i=0; i<minim; i++){
           bool found = true;
           for(int j=0; j<N - 1; j++){
               if(arr[j][i] != arr[j+1][i])
                   found = false;
           }
           //the above function verify if all the strings in the array has the same letter on position i
           if(found == true)
               rez += arr[0][i]; // if the above condition was fulfilled we store the char found in all the strings
       }
       if(rez.size() > 0)
           return rez;
       return "-1";
   }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends