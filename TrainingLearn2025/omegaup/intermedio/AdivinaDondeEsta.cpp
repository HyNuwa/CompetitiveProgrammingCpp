#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M, Q;
    cin >> N >> M >> Q;
    
    // glass_position[i] represents where glass i is currently located
    vector<int> glass_position(N + 1);
    for (int i = 1; i <= N; i++) {
        glass_position[i] = i;
    }
    
    // Process M swaps
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        
        // Find which glasses are at positions a and b
        int glass_a = -1, glass_b = -1;
        for (int j = 1; j <= N; j++) {
            if (glass_position[j] == a) glass_a = j;
            if (glass_position[j] == b) glass_b = j;
        }
        
        // Update their positions
        glass_position[glass_a] = b;
        glass_position[glass_b] = a;
    }
    
    // Answer Q queries
    for (int i = 0; i < Q; i++) {
        int p;
        cin >> p;
        cout << glass_position[p] << "\n";
    }
    
    return 0;
}