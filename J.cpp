#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

const int MAXN = 200005;
int arr[MAXN];
int leftLimit[MAXN], rightLimit[MAXN];
int result[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; 
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    stack<int> st;

    // Find the next smaller element to the left
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        leftLimit[i] = st.empty() ? 0 : st.top();
        st.push(i);
    }

    while (!st.empty()) st.pop();

    // Find the next smaller element to the right
    for (int i = n; i >= 1; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        rightLimit[i] = st.empty() ? n + 1 : st.top();
        st.push(i);
    }

    // Initialize result array
    for (int i = 1; i <= n; i++) {
        result[i] = 0;
    }

    // Fill result array with the maximum of minimums for every length
    for (int i = 1; i <= n; i++) {
        int length = rightLimit[i] - leftLimit[i] - 1;
        result[length] = max(result[length], arr[i]);
    }

    // Fill the empty entries by taking the maximum from the right
    for (int i = n - 1; i >= 1; i--) {
        result[i] = max(result[i], result[i + 1]);
    }

    // Output the result
    for (int i = 1; i <= n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
