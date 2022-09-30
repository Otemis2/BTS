<?php
/**
 * La configuration de base de votre installation WordPress.
 *
 * Ce fichier est utilisé par le script de création de wp-config.php pendant
 * le processus d’installation. Vous n’avez pas à utiliser le site web, vous
 * pouvez simplement renommer ce fichier en « wp-config.php » et remplir les
 * valeurs.
 *
 * Ce fichier contient les réglages de configuration suivants :
 *
 * Réglages MySQL
 * Préfixe de table
 * Clés secrètes
 * Langue utilisée
 * ABSPATH
 *
 * @link https://fr.wordpress.org/support/article/editing-wp-config-php/.
 *
 * @package WordPress
 */

// ** Réglages MySQL - Votre hébergeur doit vous fournir ces informations. ** //
/** Nom de la base de données de WordPress. */
define( 'DB_NAME', 'hucksylvain_wordpress' );

/** Utilisateur de la base de données MySQL. */
define( 'DB_USER', '220142' );

/** Mot de passe de la base de données MySQL. */
define( 'DB_PASSWORD', '2fpvb88S' );

/** Adresse de l’hébergement MySQL. */
define( 'DB_HOST', 'mysql-hucksylvain.alwaysdata.net' );

/** Jeu de caractères à utiliser par la base de données lors de la création des tables. */
define( 'DB_CHARSET', 'utf8mb4' );

/**
 * Type de collation de la base de données.
 * N’y touchez que si vous savez ce que vous faites.
 */
define( 'DB_COLLATE', '' );

/**#@+
 * Clés uniques d’authentification et salage.
 *
 * Remplacez les valeurs par défaut par des phrases uniques !
 * Vous pouvez générer des phrases aléatoires en utilisant
 * {@link https://api.wordpress.org/secret-key/1.1/salt/ le service de clés secrètes de WordPress.org}.
 * Vous pouvez modifier ces phrases à n’importe quel moment, afin d’invalider tous les cookies existants.
 * Cela forcera également tous les utilisateurs à se reconnecter.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',         'C}:(fptF[g;M+oj5O8,/q5fS$Y{NWf^TGhfWtD;G;-[O)0`X:fg TzHn>wA|pmkK' );
define( 'SECURE_AUTH_KEY',  'W0o$@,lMsB!V<K;[ub{.mE;_r3pL-w|Fh^5=7;mEPY?`RA}v%bWqxyvukKNryP,I' );
define( 'LOGGED_IN_KEY',    'v:[,wzZe_m{^38V?[Tr)OJ`|LqA![`nd1l7TenlcGp%~|E]8xb^Lvd5[<YXCr)d`' );
define( 'NONCE_KEY',        '9*5+N7m_%Td<Sc2is,/UT=}`7ru>O$&5vMskeU0ASI^)5Dngvg]*B>P0(pNuSVh%' );
define( 'AUTH_SALT',        'gOxBg3p/!Wd_4.zW(ciI:7A,-e]O8W}ZT{-h.:Nl@r#!OF+c^Iiqfi~CqpIFBmTS' );
define( 'SECURE_AUTH_SALT', 'LXE7[.!U*r+.G=Lq^6EoCzgc]=h;-{0,wm>8]Z<#bd{|(8/o3]RBI+SYlFs+/}w@' );
define( 'LOGGED_IN_SALT',   '#=xEht5l>05v0t1=g]5V+QV2Z_%e#Ei*Q`>LZ?Xb@M9Zl~*Spd]J4][#I(.{UUHb' );
define( 'NONCE_SALT',       'EkN.wWV?abPNZUNf(7nvS9%d`K8@,a5@aTXe.EZM08Ft`A}VCMgaivvz+^]=oIE-' );
/**#@-*/

/**
 * Préfixe de base de données pour les tables de WordPress.
 *
 * Vous pouvez installer plusieurs WordPress sur une seule base de données
 * si vous leur donnez chacune un préfixe unique.
 * N’utilisez que des chiffres, des lettres non-accentuées, et des caractères soulignés !
 */
$table_prefix = 'hucksylvain1_';

/**
 * Pour les développeurs : le mode déboguage de WordPress.
 *
 * En passant la valeur suivante à "true", vous activez l’affichage des
 * notifications d’erreurs pendant vos essais.
 * Il est fortement recommandé que les développeurs d’extensions et
 * de thèmes se servent de WP_DEBUG dans leur environnement de
 * développement.
 *
 * Pour plus d’information sur les autres constantes qui peuvent être utilisées
 * pour le déboguage, rendez-vous sur le Codex.
 *
 * @link https://fr.wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* C’est tout, ne touchez pas à ce qui suit ! Bonne publication. */

/** Chemin absolu vers le dossier de WordPress. */
if ( ! defined( 'ABSPATH' ) )
  define( 'ABSPATH', dirname( __FILE__ ) . '/' );

/** Réglage des variables de WordPress et de ses fichiers inclus. */
require_once( ABSPATH . 'wp-settings.php' );
