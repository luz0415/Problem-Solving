#include <iostream>

using namespace std;

int n;
int blocks[100];
int s1, e1;
int s2, e2;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> blocks[i];
    }
    cin >> s1 >> e1;
    cin >> s2 >> e2;

    // Please write your code here.
    s1--; e1--; s2--; e2--;

    int length = 0;
    int tmp[100] = {0,};
    for(int i = 0; i < n; i++)
    {
        if(i >= s1 && i <= e1) continue;
        tmp[length++] = blocks[i];
    }

    int length2 = 0;
    int tmp2[100] = {0,};
    for(int i = 0; i < length; i++)
    {
        if(i >= s2 && i <= e2) continue;
        tmp2[length2++] = tmp[i];
    }

    cout << length2 << endl;
    for(int i = 0; i < length2; i++)
    {
        cout << tmp2[i] << endl;
    }
    return 0;
}
