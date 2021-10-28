#include <stdio.h>
#include <string.h>

#define MAX_SIZE 50

int w, h;
int NumberOfLand = 0;
int map[MAX_SIZE][MAX_SIZE];
int visit[MAX_SIZE][MAX_SIZE];

int dw[8] = { 1, 0, -1, 0 , 1 , 1,-1,-1 };
int dh[8] = { 0, 1, 0 , -1, -1, 1,-1, 1 };

void dfs(int h, int w)
{
    visit[h][w] = 1;

    for (int i = 0; i < 8; i++)
    {
        int nh = h + dh[i];
        int nw = w + dw[i];

        if (0 <= nw && 0 <= nh && nw < MAX_SIZE && nh < MAX_SIZE)
            if (map[nh][nw] && !visit[nh][nw])
	    {
                visit[nh][nw] = 1;
                dfs(nh, nw);
            }
    }
}

int main() {
    while (1) {
        scanf("%d %d", &w, &h);
        if (!w && !h)
	      break;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                scanf("%1d", &map[i][j]);
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (map[i][j] && !visit[i][j]) {
                    NumberOfLand++;
                    dfs(i, j);
                }
            }
        }

        printf("%d\n", NumberOfLand);

	memset(map, 0, sizeof(map));
        memset(visit, 0, sizeof(visit));
        NumberOfLand = 0;
    }
    return 0;
}

