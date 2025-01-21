#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int total = 0;
        
        vector<int> doces(n, 1);

        for (int i = 1; i < n; i++)
            if (ratings[i] > ratings[i - 1])
                doces[i] = doces[i - 1] + 1;
        
        for (int i = n - 2; i >= 0; i--)
            if (ratings[i] > ratings[i + 1])
                doces[i] = max(doces[i], doces[i + 1] + 1);
        
        for (int i = 0; i < n; i++) {
            total += doces[i];
        }
        
        return total;
    }
};