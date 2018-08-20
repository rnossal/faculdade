<?php
/*
Criar 2 arrays através de uma página HTML com 5 números inteiros cada. Gerar e imprimir um array com:
	- Um array com todos os números comuns entre eles.
	- Um array todos os números diferentes entre eles.
	- Um array com todos os números pares dos dois arrays sem repetição
*/
echo '<meta http-equiv="content-type" content="text/html; charset=UTF-8" />';

$arr1 = [
	$_POST['arr1-1'],
	$_POST['arr1-2'],
	$_POST['arr1-3'],
	$_POST['arr1-4'],
	$_POST['arr1-5']
];
$arr2 = [
	$_POST['arr2-1'],
	$_POST['arr2-2'],
	$_POST['arr2-3'],
	$_POST['arr2-4'],
	$_POST['arr2-5']
];
$comuns = [];
$diferentes = [];
$pares = [];
$countC = 0;
$countD = 0;
$countP = 0;

for($i = 0; $i < count($arr1); $i++) {
	$comum = false;
	$par = false;
	for($j = 0; $j < count($arr1); $j++) {
		if($arr1[$i] == $arr2[$j]) {
			$comum = true;
		}//Verifica se o valor de arr1 é igual arr2
		if($arr1[$i] % 2 == 0) {
			$par = true;
		}//Verifica se o valor de arr1 é par
	}//Percorre arr1
	if($comum) {
		if($countC == 0) {
			$comuns[$countC] = $arr1[$i];
			$countC++;
		} else {
			$repet = 0;
			for($j = 0; $j < $countC; $j++) {
				if($arr1[$i] == $comuns[$j]) {
					$repet++;
				}
			}//Percorre para ver se já não está em comum
			if($repet == 0) {
				$comuns[$countC] = $arr1[$i];
				$countC++;
			}//Se não estiver coloca
		}//Se for o primeiro a ser colocado em comuns
	} else {
		if($countD == 0) {
			$diferentes[$countD] = $arr1[$i];
			$countD++;
		} else {
			$repet = 0;
			for($j = 0; $j < $countC; $j++) {
				if($arr1[$i] == $diferentes[$j]) {
					$repet++;
				}
			}//Percorre para ver se já não está em diferente
			if($repet == 0) {
				$diferentes[$countD] = $arr1[$i];
				$countD++;
			}//Se não estiver coloca
		}//Se for ou se não for o primeiro a ser colocado em diferentes
	}//Se for e se não for um némero comum entre arr1 e arr2
	if($par) {
		if($countP == 0) {
			$pares[$countP] = $arr1[$i];
			$countP++;
		} else {
			$repet = 0;
			for($j = 0; $j < $countP; $j++) {
				if($arr1[$i] == $pares[$j]) {
					$repet++;
				}
			}//Percorre para ver se já não está em pares
			if($repet == 0) {
				$pares[$countP] = $arr1[$i];
				$countP++;
			}//Se não estiver coloca
		}//Se for ou se não for o primeiro a ser colocado
	}
}//Percorre arr1

for($i = 0; $i < count($arr2); $i++) {
	$comum = false;
	$par = false;
	for($j = 0; $j < count($arr2); $j++) {
		if($arr2[$i] == $arr1[$j]) {
			$comum = true;
		}//Verifica se o valor de arr2 é igual arr1
		if($arr2[$i] % 2 == 0) {
			$par = true;
		}//Verifica se o valor de arr2 é par
	}//Percorre arr2
	if(!$comum) {
		$repet = 0;
		for($j = 0; $j < $countD; $j++) {
			if($arr2[$i] == $diferentes[$j]) {
				$repet++;
			}
		}//Percorre para ver se já não está em diferente
		if($repet == 0) {
			$diferentes[$countD] = $arr2[$i];
			$countD++;
		}//Se não estiver coloca
	}//Se não for comum
	if($par) {
		$repet = 0;
		for($j = 0; $j < $countP; $j++) {
			if($arr2[$i] == $pares[$j]) {
				$repet++;
			}
		}//Percorre para ver se já não está em pares
		if($repet == 0) {
			$pares[$countP] = $arr2[$i];
			$countP++;
		}//Se não estiver coloca
	}//Se for par
}//Percorre arr2

echo 'Todos os números em comum entre os dois arrays se dá por:<br />';
for($i = 0; $i < count($comuns); $i++) {
	echo "&nbsp;&nbsp;&nbsp;&nbsp;$comuns[$i]<br />";
}
echo '<br />Todos os números diferentes entre os dois arrays se dá por:<br />';
for($i = 0; $i < count($diferentes); $i++) {
	echo "&nbsp;&nbsp;&nbsp;&nbsp;$diferentes[$i]<br />";
}
echo '<br />Todos os números pares entre os dois arrays se dá por:<br />';
for($i = 0; $i < count($pares); $i++) {
	echo "&nbsp;&nbsp;&nbsp;&nbsp;$pares[$i]<br />";
}
?>
