// C++ program to implement Cache Hits
#include <iostream>
using namespace std;
 
// Function to find the next multiplier
int findnextmultiplier(int i, int b)
{
    for (int j = i; j <= i * b; j++) {
        if (j % b == 0)
            return j;
    }
}
 
// Function to find the cache hits
int ans(int n, int b, int m, int user[])
{
   // Initially cache miss occurs
   int start, cacheMiss = 1, nextmultiplier;
 
    // Find next multiplier for ith user and start
    nextmultiplier= findnextmultiplier(user[0] + 1, b);
    start = nextmultiplier - b + 1;
 
    for (int i = 1; i < m; i++) {
        // If ith user is greater than nextmultiplier or lesser
        // than start then cache miss occurs
        if (user[i] + 1 > nextmultiplier || user[i] + 1 < start) {
            cacheMiss++;
            nextmultiplier= findnextmultiplier(user[i] + 1, b);
            start = nextmultiplier - b + 1;
        }
    }
 
    // Printing cache hits
    cout << cacheMiss << endl;
 return 0;
}
 
// Driver code
int main()
{
    int n=5, b=3, m=3;
    int user[3] = {0, 3, 4};
    ans(n, b, m, user);
   return 0;
}