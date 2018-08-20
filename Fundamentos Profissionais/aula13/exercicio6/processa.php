<?php
/*
Uma empresa concederá um aumento de salário aos seus funcionários, variável de acordo com o cargo, conforme a tabela abaixo. Faça um programa que leia o salário e o cargo de um funcionário e calcule o novo salário. Se o cargo do funcionário não estiver na tabela, ele deverá, então, receber 3,5% de aumento. Mostre o salário antigo, o novo salário e a diferença.
	Código 		Cargo 			Percentual de Aumento
	101 		Gerente 		10%
	102 		Engenheiro 		7,5%
	103 		Técnico 		5,5%
*/
echo '<meta http-equiv="content-type" content="text/html; charset=UTF-8" />';

$salario = $_POST['salario'];
$cargo = $_POST['cargo'];
$aumento = 0;

switch ($cargo) {
	case 101:
		$aumento = $salario * 0.1;
		break;
	case 102:
		$aumento = $salario * 0.075;
		break;
	case 103:
		$aumento = $salario * 0.055;
		break;
	default:
		$aumento = $salario * 0.035;
}
echo "Salário antigo: R$ $salario <br />";
echo "Salário novo: R$ " . ($salario + $aumento);
echo "<br /> Diferença: R$ $aumento";
?>
