<?php
//Faça um algoritmo que leia 4 notas e informa a média delas.

$nota1 = $_POST['nota1'];
$nota2 = $_POST['nota2'];
$nota3 = $_POST['nota3'];
$nota4 = $_POST['nota4'];

echo 'Média: ' . ($nota1 + $nota2 + $nota3 + $nota4) / 4;
?>
