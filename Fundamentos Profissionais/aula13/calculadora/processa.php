<?php
/*
Deve-se implementar uma calculadora em PHP onde são informadas as operações básicas de adição, subtração, divisão e multiplicação para dois valores. Todas as informações solicitadas deve ser informada pelo usuário através de um formulário.
Ao final da operação a calculadora irá imprimir na tela no seguinte formato:
[ valor 1 ] [ operação ] [ valor 2 ] = [ resultado ]
*/
echo '<meta http-equiv="content-type" content="text/html; charset=UTF-8" />';

$val1 = $_POST['val1'];
$val2 = $_POST['val2'];
$operacao = $_POST['operacao'];

switch ($operacao) {
	case 'adicao':
		echo "$val1 + $val2 = " . ($val1 + $val2);
		break;
	case 'subtracao':
		echo "$val1 - $val2 = " . ($val1 - $val2);
		break;
	case 'divisao':
		echo "$val1 / $val2 = " . ($val1 / $val2);
		break;
	case 'multiplicacao':
		echo "$val1 * $val2 = " . ($val1 * $val2);
		break;
	default:
		echo 'Algo deu errado.';
}
?>
