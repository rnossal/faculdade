<?php
//Construa um algoritmo para pagamento de comissão de vendedores de peças, levando em Consideração que sua comissão será de 5% do total da venda e que você tem os seguintes dados que deverão ser fornecidos pelo usuário: preço unitário das peças e a quantidade de peças vendidas.

$preco = $_POST['preco'];
$qtd = $_POST['qtd'];

echo 'Valor da comissão no total da venda: R$' . ($preco * $qtd) * 0.05;
?>
