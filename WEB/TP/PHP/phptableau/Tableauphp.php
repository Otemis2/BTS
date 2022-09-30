<html>
	<head>
		<meta charset ="UTF-8">
		<meta name="viewport" content="width=device.width, initial-scale=1.0">
		<link href="Tableauphp.css" rel="stylesheet" type="text/css">
		<meta http-equiv="Refresh" content="0.1" url="index.html">
		<title>
		</title>
	</head>
	<body>
	<table>
		<tr>
			<td>Nom du script</td>
			<td><?php printf ($_SERVER['SCRIPT_NAME']); ?></td>
		</tr>
		<tr>
			<td>Ip client</td>
			<td><?php printf ($_SERVER['REMOTE_ADDR']); ?></td>
		</tr>
		<tr>
			<td>Port serveur</td>
			<td><?php printf ($_SERVER['SERVER_PORT']);   ?></td>
		</tr>
	</table>
	<br>
	<li><u><a href="../tphtml.html">Retour à l'index TP :</a></u></li>
	</body>
</html>