<?php
/*
Escreva um programa que leia um valor para uma variável n e calcule a tabuada de 1 até n. Mostre a tabuada na forma:
1 x n = n
2 x n = 2n
3 x n = 3n
.......
n x n = n2
*/
$num = $_POST['num'];

for($i = 1; $i <= $num; $i++) {
	echo "$i x $num = " . ($i * $num) . '<br />';
}
?>