#include <iostream>

using namespace std;

int N, M, K;
int numbers_2d[100][100];

bool Bomb()
{
    bool isBombed = false;

    for(int c = 0; c < N; c++)
    {
        int tmp[100] = {0, };
        int tmpIdx = N-1;

        int sameNum = numbers_2d[N-1][c];
        int sameNumIdx = N-1;
        for(int r = N-2; r >= 0; r--)
        {
            if(sameNum != numbers_2d[r][c])
            {
                int sameNumCount = sameNumIdx - r;
                if(sameNumCount >= M)
                {
                    if(sameNum != 0) isBombed = true;
                }
                else
                {
                    for(int i = sameNumIdx; i > r; i--)
                    {
                        tmp[tmpIdx--] = numbers_2d[i][c];
                    }
                }
                
                sameNum = numbers_2d[r][c];
                sameNumIdx = r;
            }
        }

        int sameNumCount = sameNumIdx + 1;
        if(sameNumCount < M)
        {        
            for(int i = sameNumIdx; i >= 0; i--)
            {
                tmp[tmpIdx--] = numbers_2d[i][c];
            }
        }
        else if(sameNum != 0) { isBombed = true; }

        for(int r = N-1; r >= 0; r--)
        {
            numbers_2d[r][c] = tmp[r];
        }
    }

    return isBombed;
}

void Rotate()
{   
    int tmp[100][100] = {0, };

    for (int i = N-1; i >= 0; i--) 
    {
        int tmpIdx = N-1;
        for (int j = N-1; j >= 0; j--) 
        {
            if(numbers_2d[i][j] == 0) continue;
            tmp[tmpIdx--][N-1-i] = numbers_2d[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            numbers_2d[i][j] = tmp[i][j];
        }
    }
}

int main() {
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> numbers_2d[i][j];
        }
    }

    for(int i = 0; i < K; i++)
    {
        bool isBombed = false;
        do
        {
            isBombed = Bomb();
        }while(isBombed);
        Rotate();
    }

    bool isBombed = false;
    do
    {
        isBombed = Bomb();
    }while(isBombed);
    
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            //cout << numbers_2d[i][j] << ' ';
            if(numbers_2d[i][j]) ans++;
        } //cout << '\n';
    }

    cout << ans;
    return 0;
}
