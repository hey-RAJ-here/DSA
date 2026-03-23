#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solve(int N, int K, long long* A) {
    if (N == 0) return 0;
    
    long long low_bound = 0;
    long long min_val = A[0];
    long long max_val = A[0];
    
    for (int i = 0; i < N; ++i) {
        if (A[i] < min_val) min_val = A[i];
        if (A[i] > max_val) max_val = A[i];
    }
    
    long long high_bound = max_val - min_val;
    long long optimal_instability = high_bound;
    
    while (low_bound <= high_bound) {
        long long mid_limit = low_bound + (high_bound - low_bound) / 2;
        
        int window_count = 1;
        long long current_min = A[0];
        long long current_max = A[0];
        
        for (int i = 1; i < N; ++i) {
            long long next_min = (A[i] < current_min) ? A[i] : current_min;
            long long next_max = (A[i] > current_max) ? A[i] : current_max;
            
            if (next_max - next_min <= mid_limit) {
                current_min = next_min;
                current_max = next_max;
            } else {
                window_count++;
                current_min = A[i];
                current_max = A[i];
            }
        }
        
        if (window_count <= K) {
            optimal_instability = mid_limit;
            high_bound = mid_limit - 1;
        } else {
            low_bound = mid_limit + 1;
        }
    }
    
    return optimal_instability;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    if (!(cin >> N >> K)) return 0;
    
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    cout << solve(N, K, A.data()) << endl;
    
    return 0;
}