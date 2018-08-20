<?php
$notas = array();

$notas[0] = 10;
$notas[1] = 8;
$notas[2] = 7;
$notas[3] = 9;

//print_r($notas);

$tam = count($notas);
$soma = 0;

for ($i = 0; $i < $tam; $i++) {
	$soma += $notas[$i];
}

echo $soma;
?>
