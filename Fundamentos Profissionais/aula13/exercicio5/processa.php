<?php
/*
Um vendedor necessita de um programa que calcule o preço total devido por um cliente. O algoritmo deve receber o código de um produto e a quantidade comprada e calcular o preço total, usando a tabela abaixo:
	Código do Produto 		Preço unitário
	1001 				5,32
	1324 				6,45
	6524 				2,37
	1987 				5,32
	7623 				6,45
*/
echo '<meta http-equiv="content-type" content="text/html; charset=UTF-8" />';

$cod = $_POST['cod'];
$qtd = $_POST['qtd'];

switch ($cod) {
	case 1001:
		echo 'Total: R$' . ($qtd * 5.32);
		break;
	case 1324:
		echo 'Total: R$' . ($qtd * 6.45);
		break;
	case 6524:
		echo 'Total: R$' . ($qtd * 2.37);
		break;
	case 1987:
		echo 'Total: R$' . ($qtd * 5.32);
		break;
	case 7623:
		echo 'Total: R$' . ($qtd * 6.45);
		break;
	default:
		echo 'Código incorreto.';
}
?>
