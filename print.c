

void print_key(int k[K], int c) {
    for (int i = 0; i < K; i++) {
        cursor_to(2 + i / 32, c + 3 + i % 32 );
        switch (k[i]) {
            case 0 : rgb(255,255,255);printf("O");break;
            case 1 : rgb(255,255,255);printf("|");break;
            case 2 : rgb(255,255,255);printf("2");break;
            default : printf("?");break;
        }

    }
}

void print_v(int* v, int L) {
    for (int i = 0; i < L; i++) {
        switch (v[i]) {
            case 0 : rgb(255,255,255);printf("O");break;
            case 1 : rgb(255,255,255);printf("|");break;
            case 2 : rgb(255,255,255);printf("2");break;
            default : printf("?");break;
        }

    }
}
void print_bit(int b) {
        switch (b) {
            case 0 : rgb(255,255,255);printf("O");break;
            case 1 : rgb(255,255,255);printf("|");break;
            case 2 : rgb(255,255,255);printf("2");break;
            default : printf("?");break;
        }
}
