<?php
/*
Implemente um Programa em PHP, que leia um valor e guarde em um vetor os proximos 12 numeros. Após informe:
	- A media dos valores
	- Quantos números primos existem na sequência de 12 números.
*/
echo '<meta http-equiv="content-type" content="text/html; charset=UTF-8" />';

$val1 = $_POST['val1'];
$nums = array();
$soma = 0;
$primos = 0;

for ($i = 0; $i < 12; $i++) {
	$novoVal = $val1 + $i + 1;
	$soma += $novoVal;
	$nums[$i] = $novoVal;

	$divisivel = 0;
	for ($j = $novoVal; $j > 0; $j--) {
		if ($novoVal % $j == 0) {
			$divisivel++;
		}
	}
	if ($divisivel == 2) {
		$primos++;
	}
}

echo 'Média dos valores: ' . ($soma / 12).'.<br />';
echo "Existem $primos números primos entre essa sequência.";
?>
