
void apply_key(int k[K], int key_start, int x[X], int y[X]) {
	int val;
	for (int b = 0; b < X; b++) {
		val = 0;
		for (int i = 0 ; i < X ; i++) val += place_value[i]*x[(b + i)%X];
		y[b] = k[(key_start + val)%K];
	}
}

void copy_x(int src[X],int tar[X]) {
	for (int i = 0; i < X; i++) tar[i] = src[i];
}

void apply_mask(int x[X], int y[X], int z[X]) {
	for (int i = 0; i < X; i++) z[i] = (x[i] + y[i])%2;
}
int parity(int x[X]) {
	int s = 0;
	for (int i = 0; i < X; i++) s += x[i];
	return s%2;
}

void encode_symbol(int k[K], int key_start, int p,  int l[X], int x[X] ) {
	int r[X], s[X],t[X], loud = 1, val = 0;;
	for (int i = 0; i < 100; i++) {
		randomize_x(r);
		apply_key(k, key_start, r, s);	
		apply_mask(s, l, t);
		if (parity(t) == p) {
			if (loud) {
				printf("  rand = ");print_v(r, X);printf("\n");
				printf("  key  = ");print_v(s, X);printf("\n");
				printf("  last = ");print_v(l, X);printf("\n");
				printf("  xor  = ");print_v(t, X);printf("\n");
				for (int i = 0 ; i < X ; i++) val += place_value[i]*t[i%X];
				printf("  val  = %d\n", val);
				printf("  par  = ");print_bit(p);printf("\n\n");

			}
			copy_x(r,x);
			copy_x(t, l);
			return;
		}
	}
	printf("failure to encode");
	return;
}


void encode_plaintext(int k[K], int key_start, int p[P], int c[C]) {
	int l[X] = {0};int val = 0; int key_pos = key_start;
	int x[X];
	for (int i = 0; i < P; i++) {
		encode_symbol(k, key_pos, p[i], l, x);
		for (int j = 0 ; j < X; j++) c[8*i + j] = x[j];
		for (int i = 0 ; i < X ; i++) val += place_value[i]*x[i%X];
		key_pos = (key_pos + val)%K;
	}

}
void decode_ciphertext(int k[K], int key_start, int c[C], int d[P]) {
	int l[X] = {0};int val = 0;int key_pos = key_start;
	int x[X], y[X], z[X];
	for (int i = 0; i < P; i++) {
		for (int j = 0 ; j < X; j++) x[j] = c[X*i + j];
		apply_key(k, key_pos, x, y);
		apply_mask(y, l, z);
		d[i] = parity(z);
		copy_x(z,l);
		for (int i = 0 ; i < X ; i++) val += place_value[i]*x[i%X];
		key_pos = (key_pos + val)%K;
	}
}





