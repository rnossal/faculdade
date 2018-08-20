<?php
/*
Um banco concederá um crédito especial aos seus clientes, variável com o saldo médio no último ano. Faça um programa que leia o saldo médio de um cliente e calcule o valor do crédito de acordo com a tabela abaixo. Mostre uma mensagem informando o saldo médio e o valor do crédito.
	Saldo Médio 			Crédito
	de 0 a 200 			nenhum
	de 201 a 400 		10% do valor do saldo médio
	de 401 a 600 		20% do valor do saldo médio
	acima de 601 		30% do valor do saldo médio
*/
echo '<meta http-equiv="content-type" content="text/html; charset=UTF-8" />';

$saldo = $_POST['saldo'];

echo "Saldo médio: $saldo <br />";
if ($saldo >= 0 && $saldo <= 200) {
	echo 'Nenhum crédito disponível';
} else if ($saldo >= 201 && $saldo <= 400) {
	echo 'Crédito: R$' . ($saldo * 0.1);
} else if ($saldo >= 401 && $saldo <= 600) {
	echo 'Crédito: R$' . ($saldo * 0.2);
} else if ($saldo >= 601) {
	echo 'Crédito: R$' . ($saldo * 0.3);
}
?>
