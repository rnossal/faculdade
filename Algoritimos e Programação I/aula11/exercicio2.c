/*
Implemente um Programa em C, que escreve os 100 primeiros números primos existentes. Lembre-se que um número primo é aquele que é divisível apenas por 1 e ele mesmo.

Referência dos 100 primeiros primos:
	2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 101
	103 107 109 113 127 131 137 139 149 151 157 163 167 173 179 181 191 193 197
	199 211 223 227 229 233 239 241 251 257 263 269 271 277 281 283 293 307 311
	313 317 331 337 347 349 353 359 367 373 379 383 389 397 401 409 419 421 431
	433 439 443 449 457 461 463 467 479 487 491 499 503 509 521 523 541
*/

#include <stdio.h>
#include <stdlib.h>

main() {
	int primos = 0,
		divisivel = 0,
		contPrimo = 0,
		cont;

	for(cont = 0; primos < 100; cont++) {
		for(contPrimo = cont; contPrimo > 0; contPrimo--) {
			if(cont % contPrimo == 0) {
				divisivel++;
			}
		}
		if (divisivel == 2) {
			primos++;
			printf("%i ", cont);
		}
		divisivel = 0;
	}

	printf("\n");
	system("pause");
}