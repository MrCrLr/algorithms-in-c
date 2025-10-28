#include <stdio.h>

int main(void) {
    int M, N;
    printf("|****** PLAY PIG DEATH CULT *******|\n");
    printf("| Enter two positive digits with a |\n");
    printf("| space in between & press enter.  |\n");
    printf("\n");
    scanf("%d %d", &M, &N);
    printf("Countdown: %d\n", M);
    printf("Cult membership: %d\n", N);

    int death_array[N] = {};
    int dead[N] = {};
    int remaining = N;
    int index = 0;

    for (int i = 0; i < N; i++) {
        int count = 0;
        while (count < M) {
            if (!dead[index]) count++;
            if (count == M) break;
            index = (index + 1) % N;
        }

        dead[index]++;
        death_array[i] = index + 1;
        remaining--;
        printf("Death #%2d: member %2d\n", i + 1, index + 1);
        
        index = (index + 1) % N;
        
        while (remaining > 0 && dead[index]) {
            index = (index + 1) % N;
        }
    }
    printf("\n");
    printf("Death order:\n");
    for (int i = 0; i < N - 1; i++) {
        printf("%d ", death_array[i]);
    }
    printf("?\n");
    printf("Last member left alive... %d\n", death_array[N - 1]);
    printf("\n");
    printf("    (\\____/)\n");
    printf("    / @__@ \\\n");
    printf("   (  (oo)  )      OINK! OINK!\n"); 
    printf("    `-.~~.-'\n");
    printf("____// :: \\\\___________________________\n");
    printf("   (!)=[]=(!)\n");    
    printf("== _\\__/\\__/_== == == == == == == == ==\n");   
    printf("__[___∞)(∞___]_________________________\n");
    printf("^” ^”^^”^ ^””^ ^^””^^ ^”^”^^” ””^^”^ ^^\n");
    printf("\n");
    
    return 0;
}