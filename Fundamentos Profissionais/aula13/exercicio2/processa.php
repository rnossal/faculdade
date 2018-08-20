<?php
/*
Tendo como dados de entrada a altura e o sexo de uma pessoa (1 para masculino e 2 para feminino), construa um programa que calcule seu peso ideal, utilizando as seguintes fórmulas:
	para homens: (72.7*h)-58
	para mulheres: (62.1*h)-44.7
*/
echo '<meta http-equiv="content-type" content="text/html; charset=UTF-8" />';

$altura = $_POST['altura'];
$sexo = $_POST['sexo'];

switch ($sexo) {
	case 1:
		echo 'Peso ideal: ' . ((72.7 * $altura) - 58);
		break;
	case 2:
		echo 'Peso ideal: ' . ((62.1 * $altura) - 44.7);
		break;
	
	default:
		echo 'Parâmetros inválidos';
		break;
}
?>