#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "constant.c"
#include "text.c"
#include "print.c"
#include "random.c"
#include "key.c"
#include "compute.c"



int main() {
    int k[K];int x[X];int l[X];int key_start = 0;int p[P];int c[C];int d[P];
    hide_cursor();
    cls();
    for (int s = 0; s < 100; s++ ) {
        cls();
        create_key(k); 
        printf("\n\n");
        print_key(k,0);
        printf("\n\n");
        for (int i = 0; i < 1; i++ )  {
            randomize_p(p);
            encode_plaintext(k, key_start, p, c );
            decode_ciphertext(k, key_start, c, d);
            printf("  f");print_v(p, P); printf(" = "); print_v(c,C);printf("\n");
            printf("  g");print_v(c, C); printf(" = "); print_v(d,P);printf("\n\n");
        }
        //usleep(20000000);

    }
}
      