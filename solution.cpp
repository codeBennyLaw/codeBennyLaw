#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long calculate_sum(const vector<int>& a, const vector<int>& b) {
    long long sum = 0;
    for (int i = 0; i < a.size(); i++) {
        sum += (a[i] | b[i]);
    }
    return sum;
}

pair<long long, vector<int>> solve_small(int l, int r) {
    vector<int> a, b;
    for (int i = l; i <= r; i++) {
        a.push_back(i);
        b.push_back(i);
    }
    
    vector<int> best_a = a;
    long long best_sum = calculate_sum(a, b);
    
    // Try all permutations for small ranges
    sort(a.begin(), a.end());
    do {
        long long current_sum = calculate_sum(a, b);
        if (current_sum > best_sum) {
            best_sum = current_sum;
            best_a = a;
        }
    } while (next_permutation(a.begin(), a.end()));
    
    return {best_sum, best_a};
}

pair<long long, vector<int>> solve_large(int l, int r) {
    int n = r - l + 1;
    vector<int> a, b;
    
    for (int i = l; i <= r; i++) {
        a.push_back(i);
        b.push_back(i);
    }
    
    vector<int> result_a(n);
    vector<bool> used(n, false);
    
    // Greedy approach: for each position in b, find the best remaining element from a
    for (int i = 0; i < n; i++) {
        int best_idx = -1;
        int best_or = -1;
        
        // Try each unused element
        for (int j = 0; j < n; j++) {
            if (used[j]) continue;
            
            int or_val = a[j] | b[i];
            if (or_val > best_or) {
                best_or = or_val;
                best_idx = j;
            }
        }
        
        result_a[i] = a[best_idx];
        used[best_idx] = true;
    }
    
    long long total_sum = calculate_sum(result_a, b);
    return {total_sum, result_a};
}

pair<long long, vector<int>> solve(int l, int r) {
    int n = r - l + 1;
    
    // For small ranges, try all permutations to find optimal solution
    // For larger ranges, use greedy heuristic
    if (n <= 10) {
        return solve_small(l, r);
    } else {
        return solve_large(l, r);
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int l, r;
        cin >> l >> r;
        
        auto [max_sum, reordered_a] = solve(l, r);
        
        cout << max_sum << "\n";
        for (int i = 0; i < reordered_a.size(); i++) {
            if (i > 0) cout << " ";
            cout << reordered_a[i];
        }
        cout << "\n";
    }
    
    return 0;
}