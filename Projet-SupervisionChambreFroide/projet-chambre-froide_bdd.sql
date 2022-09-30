-- phpMyAdmin SQL Dump
-- version 5.0.4deb2
-- https://www.phpmyadmin.net/
--
-- Hôte : localhost:3306
-- Généré le : lun. 30 mai 2022 à 12:37
-- Version du serveur :  10.5.15-MariaDB-0+deb11u1
-- Version de PHP : 7.4.28

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `projet-chambre-froide_bdd`
--

-- --------------------------------------------------------

--
-- Structure de la table `alerte`
--

CREATE TABLE `alerte` (
  `id_alerte` int(11) NOT NULL,
  `ID_Chambre` int(11) NOT NULL,
  `code_alerte` tinyint(2) NOT NULL DEFAULT 0,
  `dateAlerte` date NOT NULL DEFAULT '0000-00-00',
  `heureAlerte` time NOT NULL DEFAULT '00:00:00',
  `acquitement` tinyint(1) NOT NULL DEFAULT 0,
  `dateAcquitement` date NOT NULL DEFAULT '0000-00-00',
  `heureAcquitement` time NOT NULL DEFAULT '00:00:00'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Structure de la table `chambre_froide`
--

CREATE TABLE `chambre_froide` (
  `id_chambre` int(11) NOT NULL,
  `nom_chambre` text NOT NULL,
  `Type` text DEFAULT NULL,
  `statut` tinyint(1) NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `chambre_froide`
--

INSERT INTO `chambre_froide` (`id_chambre`, `nom_chambre`, `Type`, `statut`) VALUES
(1, 'Chambre1', 'positive', 1);

-- --------------------------------------------------------

--
-- Structure de la table `compte`
--

CREATE TABLE `compte` (
  `mail` varchar(255) NOT NULL,
  `mdp` varchar(255) NOT NULL,
  `prenom` varchar(255) NOT NULL,
  `nom` varchar(255) NOT NULL,
  `idRole` tinyint(4) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Déchargement des données de la table `compte`
--

INSERT INTO `compte` (`mail`, `mdp`, `prenom`, `nom`, `idRole`) VALUES
('a@gmail.com', '$6Z5Ds0.8KraA', 'a', 'a', 3),
('utilisateur@gmail.com', '$63ZNzvCt7LNU', 'utilisateur', 'utilisateur', 2);

-- --------------------------------------------------------

--
-- Structure de la table `etatPorte`
--

CREATE TABLE `etatPorte` (
  `id_etatPorte` tinyint(1) NOT NULL,
  `nomEtatPorte` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `etatPorte`
--

INSERT INTO `etatPorte` (`id_etatPorte`, `nomEtatPorte`) VALUES
(0, 'ouverte'),
(1, 'fermée'),
(2, '--');

-- --------------------------------------------------------

--
-- Structure de la table `reglageAlerte`
--

CREATE TABLE `reglageAlerte` (
  `id_reglageAlerte` int(11) NOT NULL,
  `id_Chambre` int(11) NOT NULL,
  `temperatureMini` float NOT NULL,
  `temperatureMax` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `reglageAlerte`
--

INSERT INTO `reglageAlerte` (`id_reglageAlerte`, `id_Chambre`, `temperatureMini`, `temperatureMax`) VALUES
(1, 1, -16, 30);

-- --------------------------------------------------------

--
-- Structure de la table `releverPorte`
--

CREATE TABLE `releverPorte` (
  `id_releverPorte` int(11) NOT NULL,
  `id_Chambre` int(11) NOT NULL,
  `date` date NOT NULL DEFAULT '0000-00-00',
  `heure` time NOT NULL DEFAULT '00:00:00',
  `etatPorte` tinyint(1) NOT NULL DEFAULT 3
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Structure de la table `releverTemperature`
--

CREATE TABLE `releverTemperature` (
  `id_releverTemperature` int(11) NOT NULL,
  `id_Chambre` int(11) NOT NULL,
  `date` date NOT NULL DEFAULT '0000-00-00',
  `heure` time NOT NULL DEFAULT '00:00:00',
  `temperature` float NOT NULL DEFAULT 99
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Structure de la table `role`
--

CREATE TABLE `role` (
  `idRole` tinyint(4) NOT NULL,
  `nomRole` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `role`
--

INSERT INTO `role` (`idRole`, `nomRole`) VALUES
(2, 'Chef de service'),
(3, 'Technicien');

-- --------------------------------------------------------

--
-- Structure de la table `statut`
--

CREATE TABLE `statut` (
  `idStatut` tinyint(1) NOT NULL,
  `nomStatut` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `statut`
--

INSERT INTO `statut` (`idStatut`, `nomStatut`) VALUES
(0, 'Hors Service'),
(1, 'En Service');

-- --------------------------------------------------------

--
-- Structure de la table `typeAlerte`
--

CREATE TABLE `typeAlerte` (
  `id_codeAlerte` tinyint(2) NOT NULL,
  `nomAlerte` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Déchargement des données de la table `typeAlerte`
--

INSERT INTO `typeAlerte` (`id_codeAlerte`, `nomAlerte`) VALUES
(1, 'porte'),
(2, 'température');

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `alerte`
--
ALTER TABLE `alerte`
  ADD PRIMARY KEY (`id_alerte`),
  ADD KEY `ID_Chambre` (`ID_Chambre`),
  ADD KEY `code_alerte` (`code_alerte`);

--
-- Index pour la table `chambre_froide`
--
ALTER TABLE `chambre_froide`
  ADD PRIMARY KEY (`id_chambre`),
  ADD KEY `idStatus` (`statut`);

--
-- Index pour la table `compte`
--
ALTER TABLE `compte`
  ADD PRIMARY KEY (`mail`),
  ADD KEY `idRole` (`idRole`);

--
-- Index pour la table `etatPorte`
--
ALTER TABLE `etatPorte`
  ADD PRIMARY KEY (`id_etatPorte`);

--
-- Index pour la table `reglageAlerte`
--
ALTER TABLE `reglageAlerte`
  ADD PRIMARY KEY (`id_reglageAlerte`),
  ADD KEY `id_Chambre` (`id_Chambre`);

--
-- Index pour la table `releverPorte`
--
ALTER TABLE `releverPorte`
  ADD PRIMARY KEY (`id_releverPorte`),
  ADD KEY `id_Chambre` (`id_Chambre`),
  ADD KEY `etatPorte` (`etatPorte`);

--
-- Index pour la table `releverTemperature`
--
ALTER TABLE `releverTemperature`
  ADD PRIMARY KEY (`id_releverTemperature`),
  ADD KEY `id_Chambre` (`id_Chambre`);

--
-- Index pour la table `role`
--
ALTER TABLE `role`
  ADD PRIMARY KEY (`idRole`);

--
-- Index pour la table `statut`
--
ALTER TABLE `statut`
  ADD PRIMARY KEY (`idStatut`);

--
-- Index pour la table `typeAlerte`
--
ALTER TABLE `typeAlerte`
  ADD PRIMARY KEY (`id_codeAlerte`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `alerte`
--
ALTER TABLE `alerte`
  MODIFY `id_alerte` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `chambre_froide`
--
ALTER TABLE `chambre_froide`
  MODIFY `id_chambre` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT pour la table `etatPorte`
--
ALTER TABLE `etatPorte`
  MODIFY `id_etatPorte` tinyint(1) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT pour la table `reglageAlerte`
--
ALTER TABLE `reglageAlerte`
  MODIFY `id_reglageAlerte` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT pour la table `releverPorte`
--
ALTER TABLE `releverPorte`
  MODIFY `id_releverPorte` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `releverTemperature`
--
ALTER TABLE `releverTemperature`
  MODIFY `id_releverTemperature` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT pour la table `role`
--
ALTER TABLE `role`
  MODIFY `idRole` tinyint(4) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT pour la table `statut`
--
ALTER TABLE `statut`
  MODIFY `idStatut` tinyint(1) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT pour la table `typeAlerte`
--
ALTER TABLE `typeAlerte`
  MODIFY `id_codeAlerte` tinyint(2) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- Contraintes pour les tables déchargées
--

--
-- Contraintes pour la table `alerte`
--
ALTER TABLE `alerte`
  ADD CONSTRAINT `alerte_ibfk_1` FOREIGN KEY (`ID_Chambre`) REFERENCES `chambre_froide` (`id_chambre`),
  ADD CONSTRAINT `alerte_ibfk_2` FOREIGN KEY (`code_alerte`) REFERENCES `typeAlerte` (`id_codeAlerte`);

--
-- Contraintes pour la table `chambre_froide`
--
ALTER TABLE `chambre_froide`
  ADD CONSTRAINT `chambre_froide_ibfk_1` FOREIGN KEY (`statut`) REFERENCES `statut` (`idStatut`);

--
-- Contraintes pour la table `reglageAlerte`
--
ALTER TABLE `reglageAlerte`
  ADD CONSTRAINT `reglageAlerte_ibfk_1` FOREIGN KEY (`id_Chambre`) REFERENCES `chambre_froide` (`id_chambre`);

--
-- Contraintes pour la table `releverPorte`
--
ALTER TABLE `releverPorte`
  ADD CONSTRAINT `releverPorte_ibfk_2` FOREIGN KEY (`etatPorte`) REFERENCES `etatPorte` (`id_etatPorte`),
  ADD CONSTRAINT `releverPorte_ibfk_3` FOREIGN KEY (`id_Chambre`) REFERENCES `chambre_froide` (`id_chambre`);

--
-- Contraintes pour la table `releverTemperature`
--
ALTER TABLE `releverTemperature`
  ADD CONSTRAINT `releverTemperature_ibfk_1` FOREIGN KEY (`id_Chambre`) REFERENCES `chambre_froide` (`id_chambre`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
