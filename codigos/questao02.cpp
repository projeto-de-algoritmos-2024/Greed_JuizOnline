#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int atual = 0;
        int inicio = 0;

        for (int i = 0; i < gas.size(); i++) {
            int dif = gas[i] - cost[i];
            total += dif;
            atual += dif;

            if (atual < 0) {
                inicio = i + 1;
                atual = 0;
            }
        }

    if (total >= 0)
        return inicio;
    else
        return -1;

    }
};