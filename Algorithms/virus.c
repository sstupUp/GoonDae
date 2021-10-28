#include <stdio.h>
 
int map[101][101] = {0};
int visit[101] = {0};
int result = 0;
int total_num = 0;
  
 void dfs(int v)
 {
          ++result;
          visit[v] = 1;
 
          for(int i = 1; i <= total_num; i++)
                  if(map[v][i] && !visit[i])
                          dfs(i);
  }
 
 int main()
  {
          int n = 0;
          int x, y;
 
          scanf("%d %d", &total_num, &n);
 
          for(int i = 0; i <n; i++)
        {
                  scanf("%d %d", &x, &y);
                  map[x][y] = map[y][x] = 1;
          }
 
          dfs(1);
 
         printf("%d", result - 1);
 
          return 0;
  }

