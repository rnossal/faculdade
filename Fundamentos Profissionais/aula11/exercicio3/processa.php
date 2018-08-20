<?php
//Faça um programa que calcula o estoque médio de uma peça, para isso solicite ao usuário que informe o estoque mínimo e o estoque máximo da mesma e o nome da peça.

$peca = $_POST['peca'];
$estMin = $_POST['estMin'];
$estMax = $_POST['estMax'];

echo "Estoque médio da peça $peca: " . ($estMin + $estMax) / 2;
?>
