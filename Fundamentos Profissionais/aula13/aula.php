<?php
	echo '<meta http-equiv="content-type" content="text/html; charset=UTF-8" />';
	/*
	Operadores:
		=	- Atribuição
		<	- Menor que
		>	- Maior que
		<=	- Menor ou igual que
		>=	- Maior ou igual que
		!=	- Diferente
		==	- Comparar igualdade de valores
		===	- Comparativo de igualdade de valores e tipos
	*/
	$valor = 10;

	if($valor > 10) {
		echo 'Valor maior que 10.';
	} else if($valor == 10) {
		echo 'Valor igual a 10.';
	} else {
		echo 'Valor menor que 10.';
	}

	//========================================
	echo '<hr />';

	$a = 10;
	$b = '10';

	if($a === $b) {
		echo 'Valores iguais.';
	} else {
		echo 'Valores diferentes.';
	}

	//========================================
	echo '<hr />';

	if($a % 2 == 0) {
		echo 'Valor par.';
	} else {
		echo 'Valor ímpar.';
	}

	//========================================
	echo '<hr />';

	$num = 3;

	switch ($num) {
		case 1:
			echo 'Um.';
			break;
		case 2:
			echo 'Dois.';
			break;
		default:
			echo 'Número desconhecido';
			break;
	}

	//========================================
	echo '<hr />';

	$uf = 'RS';

	switch ($uf) {
		case 'RS':
		case 'SC':
			echo 'Região sul.';
			break;
		case 'RJ':
		case 'S':
			echo 'Região sudeste.';
			break;
		default:
			echo 'Região desconhecida';
			break;
	}
?>