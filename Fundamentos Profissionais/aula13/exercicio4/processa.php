<?php
/*
Um usuário deseja um programa em que possa escolher o tipo de média a ser aplicada em suas 3 notas. Faça um programa que leia as notas, a opção escolhida pelo usuário, calcule e escreva a média. As opções devem conter as médias: aritmética e ponderada (pesos: 3,3,4).
*/
echo '<meta http-equiv="content-type" content="text/html; charset=UTF-8" />';

$nota1 = $_POST['nota1'];
$nota2 = $_POST['nota2'];
$nota3 = $_POST['nota3'];
$media = $_POST['media'];

switch ($media) {
	case 'arit':
		echo 'Média aritmética: ' . (($nota1 + $nota2 + $nota3) / 3);
		break;
	case 'pond':
		echo'Média ponderada: ' . (($nota1 * 3 + $nota2 * 3 + $nota3 * 4) / (3 + 3 + 4));
		break;
	default:
		echo 'Houve algum erro.';
}
?>
