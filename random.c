void shuffle(int* f, int l) {
    int j = 0;int t = 0;
    for (int i = l - 1; i > 0; i -= 1) {
        j = arc4random_uniform(i+1);
        t = f[i];f[i] = f[j];f[j] = t;
    }
}

void randomize_x(int v[X]) {
    for (int i = 0; i < X; i++) 
            v[i] = arc4random_uniform(B);
}
void randomize_p(int v[P]) {
    for (int i = 0; i < P; i++) 
            v[i] = arc4random_uniform(B);
}