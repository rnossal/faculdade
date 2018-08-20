<?php
/*
Criar um script em PHP capaz de verificar se um número lido (POST) é primo ou não
*/
echo '<meta http-equiv="content-type" content="text/html; charset=UTF-8" />';

$num = $_POST['num'];
$divisivel;

for ($i = $num; $i > 0; $i--) {
	if ($num % $i == 0) {
		$divisivel++;
	}
}
if ($divisivel == 2) {
	echo "$num é primo";
} else {
	echo "$num não é primo";
}
?>