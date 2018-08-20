<?php
/*
Criar um script em PHP para mostrar o fatorial de um número lido (POST). O cálculo do fatorial é feito da seguinte forma: n! = 1 x ... x n-1 x n Exemplo: 5! = 1 x 2 x 3 x 4 x 5 = 120. Mostrar mensagem de erro para números lidos que sejam menores que 0
*/
echo '<meta http-equiv="content-type" content="text/html; charset=UTF-8" />';

$num = $_POST['num'];
$fatorial = 1;

if ($num <= 0) {
	echo 'Valor informado é inválido';
} else {
	for($i = $num; $i > 0; $i--) {
		$fatorial *= $i;
	}
	echo "$num! = $fatorial";
}
?>