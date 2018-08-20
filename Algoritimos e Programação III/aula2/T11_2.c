main() {
	// Exercício 1
	printf("Exercício 1\n\n");
	// Com int
	int a = 4;
	a = ++a + ++a;
	printf("A) %i\n", a);

	int b = 5;
	b = ++b + b++;
	printf("B) %i\n", b);

	int c = 33;
	c = c-- + --c;
	printf("C) %i\n", c);

	int d = 30;
	d = --d + d++;
	printf("D) %i\n", d);

	int x = 3;
	int y = 5;
	x = x^y;
	y = x^y;
	x = x^y;
	printf("E)\n");
	printf("  x = %i\n", x);
	printf("  y = %i\n", y);

	printf("\n----------------------\n\n");

	// Com char
	char a1 = 4;
	a1 = ++a1 + ++a1;
	printf("A) %i\n", a1);

	char b2 = 5;
	b2 = ++b2 + b2++;
	printf("B) %i\n", b2);

	char c2 = 33;
	c2 = c2-- + --c2;
	printf("C) %i\n", c2);

	char d2 = 30;
	d2 = --d2 + d2++;
	printf("D) %i\n", d2);

	char x2 = 3;
	char y2 = 5;
	x2 = x2^y2;
	y2 = x2^y2;
	x2 = x2^y2;
	printf("E)\n");
	printf("  x = %i\n", x2);
	printf("  y = %i\n", y2);

	// Exercício 2
	printf("\nExercício 2\n\n");
	// Com char
	char a3, b3, c3, d3, e3, r3;

	a3 = 13; b3 = 30; c3 = 2; d3 = 0; e3 = 3;
	r3 = a3 | b3;
	printf("A) %i\n", r3);

	a3 = 13; b3 = 30; c3 = 2; d3 = 0; e3 = 3;
	r3 = c3-- | (~d3);
	printf("B) %i\n", r3);

	a3 = 13; b3 = 30; c3 = 2; d3 = 0; e3 = 3;
	r3 = a3 & b3;
	printf("C) %i\n", r3);

	a3 = 13; b3 = 30; c3 = 2; d3 = 0; e3 = 3;
	r3 = --a3 - --c3;
	printf("D) %i\n", r3);

	a3 = 13; b3 = 30; c3 = 2; d3 = 0; e3 = 3;
	r3 = (b3 >> --e3) | b3;
	printf("E) %i\n", r3);

	a3 = 13; b3 = 30; c3 = 2; d3 = 0; e3 = 3;
	r3 = (a3 + c3--) << (1499 / 500);
	printf("F) %i\n", r3);

	a3 = 13; b3 = 30; c3 = 2; d3 = 0; e3 = 3;
	r3 = (b3 / e3) * 2;
	printf("G) %i\n", r3);

	a3 = 13; b3 = 30; c3 = 2; d3 = 0; e3 = 3;
	r3 = ((a3 ^ b3) * (c3-- | d3) + 1 + e3) << 2;
	printf("H) %i\n", r3);

	a3 = 13; b3 = 30; c3 = 2; d3 = 0; e3 = 3;
	r3 = ~c3 + 1;
	printf("I) %i\n", r3);

	a3 = 13; b3 = 30; c3 = 2; d3 = 0; e3 = 3;
	r3 = (a3 > b3) == d3;
	printf("J) %i\n", r3);

	printf("\n----------------------\n\n");

	//Com int
	int a4, b4, c4, d4, e4, r4;

	a4 = 13; b4 = 30; c4 = 2; d4 = 0; e4 = 3;
	r4 = a4 | b4;
	printf("A) %i\n", r4);

	a4 = 13; b4 = 30; c4 = 2; d4 = 0; e4 = 3;
	r4 = c4-- | (~d4);
	printf("B) %i\n", r4);

	a4 = 13; b4 = 30; c4 = 2; d4 = 0; e4 = 3;
	r4 = a4 & b4;
	printf("C) %i\n", r4);

	a4 = 13; b4 = 30; c4 = 2; d4 = 0; e4 = 3;
	r4 = --a4 - --c4;
	printf("D) %i\n", r4);

	a4 = 13; b4 = 30; c4 = 2; d4 = 0; e4 = 3;
	r4 = (b4 >> --e4) | b4;
	printf("E) %i\n", r4);

	a4 = 13; b4 = 30; c4 = 2; d4 = 0; e4 = 3;
	r4 = (a4 + c4--) << (1499 / 500);
	printf("F) %i\n", r4);

	a4 = 13; b4 = 30; c4 = 2; d4 = 0; e4 = 3;
	r4 = (b4 / e4) * 2;
	printf("G) %i\n", r4);

	a4 = 13; b4 = 30; c4 = 2; d4 = 0; e4 = 3;
	r4 = ((a4 ^ b4) * (c4-- | d4) + 1 + e4) << 2;
	printf("H) %i\n", r4);

	a4 = 13; b4 = 30; c4 = 2; d4 = 0; e4 = 3;
	r4 = ~c4 + 1;
	printf("I) %i\n", r4);

	a4 = 13; b4 = 30; c4 = 2; d4 = 0; e4 = 3;
	r4 = (a4 > b4) == d4;
	printf("J) %i\n", r4);

	// Exercício 3-A
	printf("\nExercício 3-A\n\n");
	int a5;
	a5 = 200;
	a5 = (a5 * 0.7) + a5;
	printf("%i\n", a5);

	// Exercício 3-B
	printf("\nExercício 3-B\n\n");
	float k;
	for (k = 0.01; k!=0.7; k=k+0.01){
		printf("k = %f\n",k);
	}
}
