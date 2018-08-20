<?php
/*
Criar um script em PHP para mostrar 20 números da sequência de Fibonacci (0, 1, 1, 2, 3, 5, 8, 13,... (cada termo subsequente corresponde a soma dos dois anteriores). 
*/

$seq = 0;
$fib = 0;
$num = 1;

echo "$fib <br />";

while ($seq != 19) {
	$fib = $fib + $num;
	$num = $fib - $num;

	echo $fib . '<br />';

	$seq++;
}
?>