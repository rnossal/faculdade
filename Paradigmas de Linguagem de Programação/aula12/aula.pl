/* FATOS */

cidade(porto_alegre).
cidade(florianopolis).
cidade(gravatai).
cidade(brasilia).
cidade(buenos_aires).
cidade(curitiba).

pais(brasil).
pais(argentina).
pais(paraguai).
pais(alemanha).

estado(rs).
estado(sc).
estado(pr).
estado(sp).
estado(rj).

capital(brasilia, brasil).
capital(porto_alegre, rs).
capital(buenos_aires, argentina).

distancia(porto_alegre, florianopolis, 458).
distancia(porto_alegre, curitiba, 741).
distancia(gravatai, porto_alegre, 45).

/* REGRAS */

capital_pais(P, C):-
	pais(P),
	cidade(C),
	capital(C, P).

capital_estado(C, E):-
	cidade(C),
	estado(E),
	capital(C, E).

dist_cidade(Consumo, CidadeA, CidadeB):-
	cidade(CidadeA),
	cidade(CidadeB),
	distancia(CidadeA, CidadeB, Qtd),
	Gasto is Qtd / Consumo,
	write(Gasto).

