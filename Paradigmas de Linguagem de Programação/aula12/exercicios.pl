come(urso, peixe).
come(peixe,peixinho).
come(peixinho,alga).
come(peixe,alga).
come(urso,raposa).
come(veado,grama).
come(peixe,minhoca).
come(urso,guaxinim).
come(raposa,coelho).
come(urso,veado).
come(lince,veado).
come(planta_carnivora,mosca).
come(veado,planta_carnivora).

animal(urso).
animal(peixe).
animal(raposa).
animal(veado).
animal(minhoca).
animal(lince).
animal(coelho).
animal(guaxinim).
animal(mosca).
animal(peixinho).
animal(gato).
animal(rato).
animal(baleia).
animal(golfinho).
animal(morcego).
animal(ornitorrinco).
animal(jacare).

planta(grama).
planta(alga).
planta(planta_carnivora).

mamifero(urso).
mamifero(raposa).
mamifero(veado).
mamifero(lince).
mamifero(coelho).
mamifero(guaxinim).
mamifero(gato).
mamifero(rato).
mamifero(baleia).
mamifero(golfinho).
mamifero(morcego).
mamifero(ornitorrinco).

terrestre(urso).
terrestre(raposa).
terrestre(veado).
terrestre(minhoca).
terrestre(lince).
terrestre(coelho).
terrestre(guaxinim).
terrestre(gato).
terrestre(rato).
terrestre(ornitorrinco).
terrestre(jacare).

aquatico(peixe).
aquatico(peixinho).
aquatico(baleia).
aquatico(ornitorrinco).
aquatico(jacare).

oviparo(ornitorrinco).
oviparo(jacare).

reptil(jacare).

voador(mosca).
voador(morcego).

inseto(mosca).

anelideo(minhoca).

carnivoro(X) :-
	come(X, Y),
	animal(Y).
herbivoro(X) :-
	come(X, Y),
	planta(Y).
predador(X) :-
	carnivoro(x),
	animal(X).
presa(X):-
	come(Y, X),
	animal(Y),
	animal(X).
cacador(X):-
	presa(X).
cadeia(X, Y):-
	come(Y, X).
onivoro(X):-
	animal(X),
	carnivoro(X),
	herbivoro(X).

mamifero_aquatico(X):-
	animal(X),
	mamifero(X),
	aquatico(X).

semiaquatico(X):-
	animal(X),
	aquatico(X),
	terrestre(X).
