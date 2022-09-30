-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Hôte : mysql-hucksylvain.alwaysdata.net
-- Généré le : jeu. 18 nov. 2021 à 10:18
-- Version du serveur : 10.5.11-MariaDB
-- Version de PHP : 7.4.19

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `hucksylvain_serrehorticole`
--

-- --------------------------------------------------------

--
-- Structure de la table `DonneesSerre`
--

CREATE TABLE `DonneesSerre` (
  `ID_DONNEES` int(11) NOT NULL,
  `Date` date NOT NULL,
  `Heure` time NOT NULL,
  `Jour` varchar(20) NOT NULL,
  `TemperatureSerre` float NOT NULL,
  `HygrometrieAir` float NOT NULL,
  `HumiditeTerre` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `DonneesSerre`
--
ALTER TABLE `DonneesSerre`
  ADD PRIMARY KEY (`ID_DONNEES`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `DonneesSerre`
--
ALTER TABLE `DonneesSerre`
  MODIFY `ID_DONNEES` int(11) NOT NULL AUTO_INCREMENT;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
