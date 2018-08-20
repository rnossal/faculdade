<?php
/*
Foi realizada uma pesquisa na empresa e foram cadastrados os valores de um semestre, onde foram informados o valor e o mês correspondente ao rendimento. Guarde todas as informações em vetores, após liste:
	- o mês com maior rendimento
	- a media de rendimentos
	- lista dos meses e os respectivos rendimentos
*/
echo '<meta http-equiv="content-type" content="text/html; charset=UTF-8" />';

$meses = [
	$_POST['mes1'],
	$_POST['mes2'],
	$_POST['mes3'],
	$_POST['mes4'],
	$_POST['mes5'],
	$_POST['mes6']

];
$rendimentos = [
	$_POST['rend1'],
	$_POST['rend2'],
	$_POST['rend3'],
	$_POST['rend4'],
	$_POST['rend5'],
	$_POST['rend6']
];
$mesMaiorRend = 0;
$maiorRend = 0;
$somaRend = 0;

for($i = 0; $i < count($rendimentos); $i++) {
	if($i == 0) {
		$mesMaiorRend = $meses[$i];
		$maiorRend = $rendimentos[$i];
	} else if($rendimentos[$i] > $maiorRend) {
		$mesMaiorRend = $meses[$i];
		$maiorRend = $rendimentos[$i];
	}
	$somaRend += $rendimentos[$i];
}
echo "Mês com maior rendimento: Mês $mesMaiorRend - R$ $maiorRend <br />";
echo 'Média dos rendimentos: R$  ' . number_format($somaRend / 6, 2, ',', '') . '<br />';
$tab = '<table border="1" style="text-align: center">
		<thead style="font-weight: bold">
			<tr>
				<th>Mês</th>
				<th>Rendimento</th>
			</tr>
		</thead>
		<tbody>';
for($i = 0; $i < count($meses); $i++) {
	$tab .= "<tr>
				<td>$meses[$i]</td>
				<td>R$ $rendimentos[$i]</td>
			</tr>";
}
$tab .= '</tbody</table>';
echo $tab;
?>
