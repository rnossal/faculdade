<?php
/*
Reproduza o sistema de um caixa eletronico, onde sera informado um valor inteiro e como resultado deve retornar a quantidade que deve ser devolvida para o cliente.
Sabe-se que as notas disponiveis são as de 2, 5, 10 e 50.
*/
echo '<meta http-equiv="content-type" content="text/html; charset=UTF-8" />';

$valor = $_POST['valor'];
$qtdNotas = [
	'50' => 0,
	'10' => 0,
	'5' => 0,
	'2' => 0];

while($valor != 0) {
	if($valor - 50 >= 0) {
		$valor -= 50;
		$qtdNotas['50']++;
	} else if($valor - 10 >= 0) {
		$valor -= 10;
		$qtdNotas['10']++;
	} else if($valor - 5 - 2 >= 0 && $valor - 5 - 2 != 1 || $valor - 5 == 0) {
		$valor -= 5;
		$qtdNotas['5']++;
	} else if($valor - 2 >= 0) {
		$valor -= 2;
		$qtdNotas['2']++;
	} else {
		$valor = $_POST['valor'];
		break;
	}
}

if($valor == 0) {
	echo "Dinheiro sacado!<br /><br />
		Foram entregues as seguintes notas e suas respectivas quantidades:<br />";
	foreach($qtdNotas as $key => $value) {
		if($value != 0) {
			echo "R$ $key: $value <br />";
		}
	}
} else {
	echo "O valor em dinheiro de R$ $valor não é um valor válido para ser sacado.<br />
		Tente outro valor clicando " . '<a href="index.html">aqui</a>';
}
?>
