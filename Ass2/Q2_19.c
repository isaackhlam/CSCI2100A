#include <stdio.h>
#include <string.h>

#define MAXN 1002

int p[MAXN];
int F[MAXN];
int bipartite[MAXN];
int adjm[MAXN][MAXN];
int N;
int noSolution = 0;

void reset(void);
void color(int i, int c);
void dye(void);
void initial(void);

void color(int i, int c) {
    bipartite[i] = c;
    int j;
    for (j = 1; j <= N; j++) {
        if (adjm[i][j]) {
            if (bipartite[j] == c){
                noSolution = 1;
                return;
            }
            if (!bipartite[j])
                color(j, 3 - c); // color the opposite color 1<->2
        }
    }
}

void dye(void) {
    int i, j;
    F[0] = -1;
    for (i = 1; i <= N; i++) {
        F[i] = p[i];
        if (F[i - 1] > F[i])
            F[i] = F[i - 1];
    }
    for (i = 1; i <= N - 1; i++) 
        for (j = i + 1; j <= N; j++) 
            if (p[i] < p[j] && F[i - 1] > p[j])
                adjm[i][j] = adjm[j][i] = 1;
            
    for (i = 1; i <= N; i++)
        if (!bipartite[i] && !noSolution) 
            color(i, 1);
}

void reset(void) {
    memset(adjm, 0, sizeof(adjm));
    memset(bipartite, 0, sizeof(bipartite));
    memset(p, 0, sizeof(p));
    memset(F, 0, sizeof(F));
    N = 0;
    noSolution = 0;
}

int main(void) {
    int n;
    scanf("%d", &n);
    while(n--){
        int i;
        scanf("%d", &N);
        for (i = 1; i <= N; i++) 
            scanf("%d", &p[i]);

        dye();
        if (!noSolution) 
            printf("Yes\n");
        else
            printf("No\n");
        reset();
    }

    return 0;
}
