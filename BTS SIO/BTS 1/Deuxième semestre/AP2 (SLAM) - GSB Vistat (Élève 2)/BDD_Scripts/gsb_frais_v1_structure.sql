-- phpMyAdmin SQL Dump
-- version 5.0.2
-- https://www.phpmyadmin.net/
--
-- Hôte : 127.0.0.1:3306
-- Généré le : lun. 18 jan. 2021 à 14:29
-- Version du serveur :  8.0.21
-- Version de PHP : 7.3.21

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `gsb_frais_v1`
--

-- --------------------------------------------------------

--
-- Structure de la table `tb_etat`
--

DROP TABLE IF EXISTS `tb_etat`;
CREATE TABLE IF NOT EXISTS `tb_etat` (
  `ETT_ID` varchar(2) NOT NULL,
  `ETT_LIBELLE` varchar(255) NOT NULL,
  PRIMARY KEY (`ETT_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `tb_fichefrais`
--

DROP TABLE IF EXISTS `tb_fichefrais`;
CREATE TABLE IF NOT EXISTS `tb_fichefrais` (
  `FCH_NUM` int NOT NULL,
  `FCH_MOIS` varchar(6) NOT NULL,
  `FCH_NBJUSTIFICATIFS` int NOT NULL,
  `FCH_DATEMODIF` date NOT NULL,
  `FCH_VST_ID` varchar(5) NOT NULL,
  `FCH_ETT_ID` varchar(2) NOT NULL,
  PRIMARY KEY (`FCH_NUM`),
  KEY `FK_FCH_VST_ID` (`FCH_VST_ID`),
  KEY `FK_FCH_ETT_ID` (`FCH_ETT_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `tb_fraisforfait`
--

DROP TABLE IF EXISTS `tb_fraisforfait`;
CREATE TABLE IF NOT EXISTS `tb_fraisforfait` (
  `FRS_ID` varchar(3) NOT NULL,
  `FRS_LIBELLE` varchar(255) NOT NULL,
  `FRS_MONTANT` decimal(10,2) NOT NULL,
  PRIMARY KEY (`FRS_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `tb_lignefraisforfait`
--

DROP TABLE IF EXISTS `tb_lignefraisforfait`;
CREATE TABLE IF NOT EXISTS `tb_lignefraisforfait` (
  `LFF_FCH_NUM` int NOT NULL,
  `LFF_FRS_ID` varchar(3) NOT NULL,
  `LFF_QUANTITE` int NOT NULL,
  PRIMARY KEY (`LFF_FCH_NUM`,`LFF_FRS_ID`),
  KEY `FK_LFF_FCH_NUM` (`LFF_FCH_NUM`),
  KEY `FK_LFF_FRS_ID` (`LFF_FRS_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `tb_lignefraishorsforfait`
--

DROP TABLE IF EXISTS `tb_lignefraishorsforfait`;
CREATE TABLE IF NOT EXISTS `tb_lignefraishorsforfait` (
  `LFH_NUM` int NOT NULL,
  `LFH_LIBELLE` varchar(255) NOT NULL,
  `LFH_DATE` date NOT NULL,
  `LFH_MONTANT` decimal(10,2) NOT NULL,
  `LFH_FCH_NUM` int NOT NULL,
  PRIMARY KEY (`LFH_NUM`),
  KEY `FK_LFH_FCH_NUM` (`LFH_FCH_NUM`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `tb_visiteur`
--

DROP TABLE IF EXISTS `tb_visiteur`;
CREATE TABLE IF NOT EXISTS `tb_visiteur` (
  `VST_ID` varchar(5) NOT NULL,
  `VST_NOM` varchar(30) NOT NULL,
  `VST_PRENOM` varchar(30) NOT NULL,
  `VST_DATE_EMBAUCHE` date NOT NULL,
  `VST_TEL_PORTABLE` varchar(15) DEFAULT NULL,
  `VST_DPR_NUM` int NOT NULL,
  PRIMARY KEY (`VST_ID`),
  KEY `FK_VST_DPR_NUM` (`VST_DPR_NUM`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
