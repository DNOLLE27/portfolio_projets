-- phpMyAdmin SQL Dump
-- version 3.4.10.1
-- http://www.phpmyadmin.net
--
-- Client: localhost
-- Généré le : Dim 06 Octobre 2013 à 13:24
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

--
-- Contenu de la table `tb_departement`
--

INSERT INTO `tb_departement` (`DPR_NUM`, `DPR_NOM`, `DPR_RGN_ID`) VALUES
(4, 'Alpes de haute Provence', 8),
(5, 'Hautes-Alpes', 8),
(6, 'Alpes-Maritimes', 8),
(13, 'Bouches-du-Rhone', 8),
(22, 'Cote d''Armor', 2),
(27, 'Eure', 1),
(29, 'Finistère', 2),
(35, 'Ille et Vilaine', 2),
(44, 'Loire-Atlantique', 3),
(49, 'Maine et Loire', 3),
(53, 'Mayenne', 3),
(56, 'Morbihan', 2),
(63, 'Puy de Dôme', 9),
(72, 'Sarthe', 3),
(76, 'Seine-Maritime', 1),
(83, 'Var', 8),
(84, 'Vaucluse', 8),
(85, 'Vendée', 3);

--
-- Contenu de la table `tb_region`
--

INSERT INTO `tb_region` (`RGN_ID`, `RGN_LIBELLE`, `RGN_RESP_NOM`, `RGN_RESP_PRENOM`, `RGN_SCT_NUM`) VALUES
(1, 'Haute-Normandie', 'PERSONNAZ', 'Bruno', 1),
(2, 'Bretagne', 'HAUTOT', 'Charles', 1),
(3, 'Pays de la Loire', 'MANGUIN', 'Valentine', 1),
(4, 'Corse', 'LAMARI', 'Emmanuelle', 4),
(5, 'Lorraine', 'HERZOG', 'Thierry', 3),
(6, 'Martinique', 'PETITBON', 'Alain', 5),
(7, 'Guadeloupe', 'MARCHAL', 'Mireille', 5),
(8, 'Provence Alpes Côtes d''Azur', 'LEMIEGRE', 'Louis', 4),
(9, 'Auvergne', 'CALLENS', 'Jacques', 6);

--
-- Contenu de la table `tb_secteur`
--

INSERT INTO `tb_secteur` (`SCT_NUM`, `SCT_LIBELLE`, `SCT_METROPOLE`, `SCT_RESP_NOM`, `SCT_RESP_PRENOM`) VALUES
(1, 'OUEST', 1, 'PRIGENT', 'Paul'),
(2, 'NORD', 1, 'GUERARD', 'Alain'),
(3, 'EST', 1, 'MINNIER', 'C?line'),
(4, 'SUD', 1, 'CRAVENT', 'Sheila'),
(5, 'DTOM', 0, 'PIROS', 'Jacques'),
(6, 'PARIS-CENTRE', 1, 'LOUVEL', 'Didier');

--
-- Contenu de la table `tb_visiteur`
--

INSERT INTO `tb_visiteur` (`VST_ID`, `VST_NOM`, `VST_PRENOM`, `VST_DATE_EMBAUCHE`, `VST_TEL_PORTABLE`, `VST_DPR_NUM`) VALUES
('a131', 'Villechalane', 'Louis', '1992-12-11', '0611692543', 63),
('a17', 'Andre', 'David', '1991-08-26', '0673918246', 76),
('a55', 'Bedos', 'Christian', '1987-07-17', '0617934625', 27),
('a93', 'Tusseau', 'Louis', '1999-01-02', '0628391782', 5),
('b13', 'Bentot', 'Pascal', '1996-03-11', '0631236456', 6),
('b16', 'Bioret', 'Luc', '1997-03-21', '0698786545', 63),
('b19', 'Bunisset', 'Francis', '1999-01-31', '0654875689', 83),
('b25', 'Bunisset', 'Denise', '1994-07-03', NULL, 83),
('b28', 'Cacheux', 'Bernard', '2000-08-02', '0611526321', 22),
('b34', 'Cadic', 'Eric', '1993-12-06', '0622778833', 5),
('b4', 'Charoze', 'Catherine', '1997-09-25', '0695243896', 6),
('b50', 'Clepkens', 'Christophe', '1998-01-18', '0648239654', 35),
('b59', 'Cottin', 'Vincenne', '1995-10-21', '0621736985', 35),
('c14', 'Daburon', 'François', '1989-02-01', '0698316454', 35),
('c3', 'De', 'Philippe', '1992-05-05', '0685965214', 22),
('c54', 'Debelle', 'Michel', '1991-04-09', '0652376183', 44),
('d13', 'Debelle', 'Jeanne', '1991-12-05', '0683145696', 44),
('d51', 'Debroise', 'Michel', '1997-11-18', '0792518563', 5),
('e22', 'Desmarquest', 'Nathalie', '1989-03-24', '0731628912', 6),
('e24', 'Desnost', 'Pierre', '1993-05-17', '0625853691', 44),
('e39', 'Dudouit', 'Frédéric', '1988-04-26', '0685215247', 44),
('e49', 'Duncombe', 'Claude', '1996-02-19', '0623871963', 22),
('e5', 'Enault-Pascreau', 'Céline', '1990-11-27', '0633224485', 29),
('e52', 'Eynde', 'Valérie', '1991-10-31', NULL, 85),
('f21', 'Finck', 'Jacques', '1993-06-08', '0695751535', 63),
('f39', 'Frémont', 'Fernande', '1997-02-15', '0628731912', 85),
('f4', 'Gest', 'Alain', '1994-05-03', '0646982685', 83),
('g19', 'Gheysen', 'Galassus', '1996-01-18', '0632851697', 27),
('g30', 'Girard', 'Yvon', '1999-03-27', NULL, 53),
('g53', 'Gombert', 'Luc', '1985-10-02', '0652638596', 84),
('g7', 'Guindon', 'Caroline', '1996-01-13', '0679632145', 53),
('h13', 'Guindon', 'François', '1993-05-08', '0671568316', 53),
('h30', 'Igigabel', 'Guy', '1998-04-26', '0782394123', 53),
('h35', 'Jourdren', 'Pierre', '1993-08-26', '0723685147', 29),
('h40', 'Juttard', 'Pierre-Raoul', '1992-11-01', '0682937182', 49),
('j45', 'Labouré-Morel', 'Saout', '1998-02-25', '0642359512', 49),
('j50', 'Landré', 'Philippe', '1992-12-16', '0685216912', 49),
('j8', 'Langeard', 'Hugues', '1998-06-18', '0685236415', 49),
('k4', 'Lanne', 'Bernard', '1996-11-21', '0785321459', 49),
('k53', 'Le', 'Noël', '1983-03-23', '0621548756', 72),
('l14', 'Le', 'Jean', '1995-02-02', '0636925871', 72),
('l23', 'Leclercq', 'Servane', '1995-06-05', '0619875633', 72),
('l46', 'Lecornu', 'Jean-Bernard', '1997-01-24', '0673918525', 72),
('t45', 'Tiphagne', 'Patrick', '2011-03-15', '0652445533', 63);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
