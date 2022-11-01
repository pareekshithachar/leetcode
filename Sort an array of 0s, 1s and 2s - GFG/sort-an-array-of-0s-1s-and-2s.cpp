//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int arr[], int n)
    {
        // code here 
        int start = 0;
        int end = n-1;
        for(int i = 0;i<n;i++){
            if(arr[i] == 0){
                int temp = arr[start];
                arr[start] = 0;
                arr[i] = temp;
                start++;
            }
        }
        for(int i = start;i<n;i++){
            if(arr[i] == 1){
                int temp = arr[start];
                arr[start] = 1;
                arr[i] = temp;
                start++;
            }
        }
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends