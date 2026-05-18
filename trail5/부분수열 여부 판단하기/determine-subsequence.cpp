#include <iostream>
using namespace std;

int main() {
    int N, M; cin >> N >> M;

    int A[100000] = {}, B[100000] = {};
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < M; i++)
    {
        cin >> B[i];
    }

    int j = 0;
    for (int i = 0; i < N; i++)
    {
        if (A[i] == B[j])
        {
            j++;
        }

        if (j == M) break;
    }

    cout << (j == M ? "Yes" : "No");
    return 0;
}