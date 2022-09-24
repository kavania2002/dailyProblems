//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int swapBitGame(long long N)
    {
        // code here

        // we will count the number of set bits
        // in the number N
        // we will count it by running a while loop
        // till N becomes 0
        int cnt = 0;
        while (N)
        {
            // if the LSB is 1 then cnt++;
            if (N & 1)
                cnt++;

            // right shift by 1 bit therefore dividing by 2
            N >>= 1;
        }

        // if cnt is even return 2 else 1
        return cnt % 2 ? 1 : 2;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.swapBitGame(N) << endl;
    }
    return 0;
}
// } Driver Code Ends