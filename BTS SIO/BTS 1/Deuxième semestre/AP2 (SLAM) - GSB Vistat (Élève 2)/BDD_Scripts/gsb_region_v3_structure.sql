-- phpMyAdmin SQL Dump
-- version 3.4.10.1
-- http://www.phpmyadmin.net
--
-- Client: localhost
-- Généré le : Dim 06 Octobre 2013 à 13:23
-- Version du serveur: 5.5.8
-- Version de PHP: 5.3.5

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Base de données: `region_v3`
--

-- --------------------------------------------------------

--
-- Structure de la table `tb_departement`
--

CREATE TABLE IF NOT EXISTS `tb_departement` (
  `DPR_NUM` int(11) NOT NULL,
  `DPR_NOM` varchar(30) NOT NULL,
  `DPR_RGN_ID` int(11) NOT NULL,
  PRIMARY KEY (`DPR_NUM`),
  KEY `FK_DPR_RGN_ID` (`DPR_RGN_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `tb_region`
--

CREATE TABLE IF NOT EXISTS `tb_region` (
  `RGN_ID` int(11) NOT NULL,
  `RGN_LIBELLE` varchar(30) NOT NULL,
  `RGN_RESP_NOM` varchar(30) NOT NULL,
  `RGN_RESP_PRENOM` varchar(30) NOT NULL,
  `RGN_SCT_NUM` int(11) NOT NULL,
  PRIMARY KEY (`RGN_ID`),
  KEY `FK_RGN_SCT_NUM` (`RGN_SCT_NUM`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `tb_secteur`
--

CREATE TABLE IF NOT EXISTS `tb_secteur` (
  `SCT_NUM` int(11) NOT NULL,
  `SCT_LIBELLE` varchar(30) NOT NULL,
  `SCT_METROPOLE` tinyint(1) NOT NULL,
  `SCT_RESP_NOM` varchar(30) NOT NULL,
  `SCT_RESP_PRENOM` varchar(30) NOT NULL,
  PRIMARY KEY (`SCT_NUM`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Structure de la table `tb_visiteur`
--

CREATE TABLE IF NOT EXISTS `tb_visiteur` (
  `VST_ID` varchar(5) NOT NULL,
  `VST_NOM` varchar(30) NOT NULL,
  `VST_PRENOM` varchar(30) NOT NULL,
  `VST_DATE_EMBAUCHE` date NOT NULL,
  `VST_TEL_PORTABLE` varchar(15) DEFAULT NULL,
  `VST_DPR_NUM` int(11) NOT NULL,
  PRIMARY KEY (`VST_ID`),
  KEY `FK_VST_DPR_NUM` (`VST_DPR_NUM`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
