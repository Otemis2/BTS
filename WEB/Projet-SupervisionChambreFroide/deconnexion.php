<?php
session_start();
?>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="refresh" content="0.5;URL=./index.php">
        <meta charset="utf-8" />
    </head>
    <body>
    <?php
        require ('./script/fonctions.php');
        deconnexion();//appel la fonction deconnexion
    ?>
        <p><h2><center>Déconnexion en cours ...</center></h2></p>
    </body>
</html>