void create_key(int f[K]) {
    for (int i = 0; i < K/2; i++) f[i] = 1;
    for (int i = K/2; i < K; i++) f[i] = 0;
    shuffle(f, K);
}