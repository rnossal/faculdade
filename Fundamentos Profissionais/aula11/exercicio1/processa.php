<?php
//Faça um programa que solicita ao usuário 4 valores, calcule o quadrado de cada um, some todos os resultados e mostre o resultado final.

$val1 = $_POST['val1'];
$val2 = $_POST['val2'];
$val3 = $_POST['val3'];
$val4 = $_POST['val4'];

echo 'Resultado: ' . (pow($val1, 2) + pow($val2, 2) + pow($val3, 2) + pow($val4, 2));
?>
