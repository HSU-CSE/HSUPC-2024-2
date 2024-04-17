#include <iostream>
#include <vector>
using namespace std;
struct G {
    int diff, idx;
};
int main() {
    cin.tie(0)->ios::sync_with_stdio(0);
    int n, p, q;
    cin >> n >> p >> q;
    vector<int> A(n), B(n);

    for (auto& i : A) cin >> i;
    for (auto& i : B) cin >> i;

    vector<G> result(n);
    for (int i = 0; i < n; i++) {
        result[i] = {B[i] - A[i], i};
    }

    sort(result.begin(), result.end(), [](G& front, G& back) { return front.diff < back.diff; });

    int output{};
    for (int i = 0; i < q; i++) {
        output += B[result[i].idx];
    }
    for (int i = q; i < n; i++) {
        output += A[result[i].idx];
    }
    cout << output;

    return 0;
}