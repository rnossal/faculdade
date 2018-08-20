<?php
/*
Criar um script em PHP para ler 2 números (POST) e mostrar todos os números pares entre eles (inclusive). Os números devem ser mostrados em ordem decrescente. 
*/
echo '<meta http-equiv="content-type" content="text/html; charset=UTF-8" />';
$menor;
$maior;

if ($_POST['val1'] <= $_POST['val2']) {
	$menor = $_POST['val1'];
	$maior = $_POST['val2'];
} else {
	$menor = $_POST['val2'];
	$maior = $_POST['val1'];
}

for ($i = $maior; $i >= $menor; $i--) {
	if ($i % 2 == 0) {
		echo $i . '<br />';
	}
}
?>
