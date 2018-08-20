<?php
/*
Foi realizada uma pesquisa de audiência de canais de TV em 6 casas de uma cidade, num determinado dia. De cada casa visitada, foi coletado o canal de TV (considerar apenas os canais 2, 4, 5, 10, 12 e 48) e o número de pessoas que o estavam assistindo. Faça um programa que leia os dados e calcule:
	Utilize vetores para guardar as informações
	O canal da emissora e o seu percentual de audiência;
	O canal de maior audiência;
	O canal de menor audiência;
	Todos os canais deve ser escrito no resultado com o nome da emissora
*/
echo '<meta http-equiv="content-type" content="text/html; charset=UTF-8" />';

$canaisCasas = [
	$_POST['canal1'],
	$_POST['canal2'],
	$_POST['canal3'],
	$_POST['canal4'],
	$_POST['canal5'],
	$_POST['canal6']

];
$pessoasCasas = [
	$_POST['pess1'],
	$_POST['pess2'],
	$_POST['pess3'],
	$_POST['pess4'],
	$_POST['pess5'],
	$_POST['pess6']
];
$emissoraAudiencia = [
	'Record' => 0,
	'Pampa' => 0,
	'SBT' => 0,
	'Band' => 0,
	'Globo' => 0,
	'UlbraTV' => 0
];
$totalPessoas = 0;
$maiorAudiencia = $valMaiorAudiencia = '';
$menorAudiencia = $valMenorAudiencia = '';

for($i = 0; $i < count($canaisCasas); $i++) {
	switch ($canaisCasas[$i]) {
		case '2':
			$emissoraAudiencia['Record'] += $pessoasCasas[$i];
			break;
		case '3':
			$emissoraAudiencia['Pampa'] += $pessoasCasas[$i];
			break;
		case '5':
			$emissoraAudiencia['SBT'] += $pessoasCasas[$i];
			break;
		case '10':
			$emissoraAudiencia['Band'] += $pessoasCasas[$i];
			break;
		case '12':
			$emissoraAudiencia['Globo'] += $pessoasCasas[$i];
			break;
		case '48':
			$emissoraAudiencia['UlbraTV'] += $pessoasCasas[$i];
			break;
		default:
			break;
	}
	$totalPessoas += $pessoasCasas[$i];
}
echo 'Lista de canais e sua respectiva audiência:<br/>';
foreach($emissoraAudiencia as $indice => $valor) {
	echo str_repeat('&nbsp;', 5) . $indice . ': ' . number_format(($valor * 100) / $totalPessoas, 2, '.', '') . '%<br />';
	if($valor != 0) {
		if($valMaiorAudiencia == '' && $valMenorAudiencia == '') {
			$valMaiorAudiencia = $valor;
			$maiorAudiencia = $indice;
			$valMenorAudiencia = $valor;
			$menorAudiencia = $indice;
		} else if($valor > $valMaiorAudiencia) {
			$valMaiorAudiencia = $valor;
			$maiorAudiencia = $indice;
		} else if($valor < $valMenorAudiencia) {
			$valMenorAudiencia = $valor;
			$menorAudiencia = $indice;
		}
	}
}
echo "<br />Canal com maior audiência: $maiorAudiencia <br />
	Canal com menor audiência: $menorAudiencia";
?>
