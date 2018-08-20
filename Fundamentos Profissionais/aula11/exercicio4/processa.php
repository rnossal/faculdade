<?php
//Construa um algoritmo com uma função que leia a cotação do dólar, leia 3 valores em dólar, converta esses valores para real e mostre o resultado.

$cotacao = $_POST['cotacao'];
$val1 = $_POST['val1'];
$val2 = $_POST['val2'];
$val3 = $_POST['val3'];

echo 'Primeiro valor em reais: R$' . $val1 * $cotacao . '<br />';
echo 'Segundo valor em reais: R$' . $val2 * $cotacao . '<br />';
echo 'Terceiro valor em reais: R$' . $val3 * $cotacao;
?>
