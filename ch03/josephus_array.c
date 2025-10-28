#include <stdio.h>

int main(void) {
    int i, M, N;
    scanf("%d %d", &M, &N);
    printf("First suicide: %d\n", M);
    printf("Cult members: %d\n", N);

    int death_order[N] = {};
    
    for (int j = 0, i = M; j < N; j++) {
        if (j == 0) {
            death_order[j] = M;
        } else if (i > N) {
            death_order[j] = i - N;
            i = i - N;
        } else {
            death_order[j] = i;
        }
        i = i + M;
    }
    
    printf("Death order:\n");
    for (int j = 0; j < N - 1; j++) {
        printf("%d ", death_order[j]);
    }
    printf("?\n");
    printf("Last member left... %d\n", death_order[N - 1]);
    
    return 0;
}