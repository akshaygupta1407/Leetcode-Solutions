class Solution {
public:
    
  int sub(vector<int>&res , int x)
  {
      int l=0;
      int h =res.size()-1;
      while(l<=h)
      {
          int mid = (l+h)/2;
          
          if(res[mid]<=x)
          {
              l=mid+1;
          }
          else
          {
              h =mid-1;
          }
          
          
      }
      
      return l;
  }
    int matrixMedian(vector<vector<int>>& matrix) {
        int l=0,h=1e6+1,r=matrix.size(),c=matrix[0].size();
          while(l<=h)
       {
           int mid =(l+h)/2;
           
           int cnt =0;
           
           for( int i=0;i<r;i++)
           {
               cnt += sub(matrix[i],mid);
           }
           if((r*c)/2 >=cnt)
           {
               l=mid+1;
           }
           else
           {
               h =mid-1;
           }
       }
       return l;
    }
};