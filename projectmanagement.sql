-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1:3306
-- Generation Time: Aug 28, 2023 at 04:40 AM
-- Server version: 10.4.28-MariaDB
-- PHP Version: 8.2.4

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `projectmanagement`
--

-- --------------------------------------------------------

--
-- Table structure for table `admin`
--

CREATE TABLE `admin` (
  `username` varchar(45) NOT NULL,
  `password` varchar(45) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `admin`
--

INSERT INTO `admin` (`username`, `password`) VALUES
('admin', '1234'),
('admin1', '1234');

-- --------------------------------------------------------

--
-- Table structure for table `faculty`
--

CREATE TABLE `faculty` (
  `FacultyID` varchar(10) NOT NULL,
  `FirstName` varchar(50) DEFAULT NULL,
  `LastName` varchar(50) DEFAULT NULL,
  `Email` varchar(100) DEFAULT NULL,
  `Department` varchar(50) DEFAULT NULL,
  `ContactNumber` varchar(15) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `faculty`
--

INSERT INTO `faculty` (`FacultyID`, `FirstName`, `LastName`, `Email`, `Department`, `ContactNumber`) VALUES
('F1', 'Santhosh', 'B', 'santhose@mail.com', 'CSE', '6575676454'),
('F2', 'Yakoob', 'SK', 'yakoob@mail.com', 'CSE', '4656756456');

-- --------------------------------------------------------

--
-- Table structure for table `participants`
--

CREATE TABLE `participants` (
  `ParticipantID` int(10) NOT NULL,
  `ProjectID` varchar(10) DEFAULT NULL,
  `StudentID` varchar(10) DEFAULT NULL,
  `batch` varchar(10) NOT NULL,
  `Role` varchar(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `participants`
--

INSERT INTO `participants` (`ParticipantID`, `ProjectID`, `StudentID`, `batch`, `Role`) VALUES
(46, '23', '21C51A0522', 'A1', 'Leader'),
(47, '23', '21C51A0520', 'A1', 'Member'),
(48, '23', '21C51A0529', 'A1', 'Member');

-- --------------------------------------------------------

--
-- Table structure for table `projects`
--

CREATE TABLE `projects` (
  `ProjectID` varchar(11) NOT NULL,
  `ProjectTitle` text DEFAULT NULL,
  `ProjectType` varchar(45) DEFAULT NULL,
  `FacultyAdvisorID` varchar(10) DEFAULT NULL,
  `Branch` varchar(4) NOT NULL,
  `AcademicYear` varchar(8) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `projects`
--

INSERT INTO `projects` (`ProjectID`, `ProjectTitle`, `ProjectType`, `FacultyAdvisorID`, `Branch`, `AcademicYear`) VALUES
('21CS01', 'dsfdsf', 'MIni', 'F1', 'CS', '2021-22'),
('22ME01', 'Hgfhgf', 'Mini Project', 'F1', 'ME', '2024-25'),
('23', 'Advanced Multi-Dimentional Structural Neural Network Over Academic student student performence Prediction', 'fdfdfgdfg', 'F2', '', ''),
('2301', 'muraliRRRRRR RRRRRRRRRRRRRRRGGG RRRRRRRRRR RRRRRRR RRRRRRRRRRRRRRR RRRRRRRRRRRRR RRRRRRRRRRRRRR RRRRRRRRRRRRR RRRRRRRRRR  ', 'MIni', 'F1', '', ''),
('23CM01', 'Test CM', 'MK', 'F1', 'CM', '2023-24'),
('23CS02', 'HelloRRRRRRRRRRRRRRRRRRRRRRRRRR RRRRRRRRR RRRRRRRR RRRRRRRRRRRR RRRRRRRRRRRR RRR RRR RRRR  RRRRRRRRRRRRR RRRRR RRRRRRR ', 'MIni', 'F1', '', ''),
('23CS03', 'TESTING  RRRGGGGGGG GGGGGGGG GGGGGGGGG GGGGGGGGGGG GGGGGGG ', 'MAJOR', 'f1', '', ''),
('23CS04', 'EFSEFSD', 'SFDFF', 'f1', '', ''),
('23CS05', 'SDFDSFSDSDF', 'DGDFGDFG', 'F2', 'CS', '2023-24'),
('23CS06', 'DFDGFGDFG', 'DFGDFG', 'F1', '', ''),
('23CS07', 'SFDSDFSDF', 'SDFDFF', 'F1', '', ''),
('23CS08', 'FSDFSDF', 'SDFF', 'f1', '', ''),
('23CS09', 'EREWRERER', 'ERWEREWR', 'F2', '', ''),
('23CS10', 'FERRDDFGF', 'DFFGDFG', 'F1', '', ''),
('23EC01', 'Deep Learning', 'mani', 'F2', 'EC', '2023-24'),
('23EC02', ' Development Project', 'Major Project Stage-I', 'F2', 'EC', '2023-24'),
('23EC03', 'Test Year Input', 'Major Project Stage-I', 'F2', 'EC', '2023-24'),
('23EE01', 'Test EE', 'mini', 'F1', 'EE', ''),
('23EE02', 'Test EE', 'mini', 'F1', 'EE', ''),
('23EE11', 'ddddd', 'mini', 'F1', 'EE', ''),
('24EC01', 'dfdfgfg', 'MIni', 'F1', 'EC', '2024-25'),
('P2', 'Development Project rrr', 'developing a responsive website for an online', 'F2', '', '');

--
-- Triggers `projects`
--
DELIMITER $$
CREATE TRIGGER `before_project_insert` BEFORE INSERT ON `projects` FOR EACH ROW BEGIN
    DECLARE current_year INT;
    DECLARE next_counter INT;
    DECLARE branch_code VARCHAR(2); -- Change this to the actual branch code

    SET current_year = SUBSTRING_INDEX(NEW.AcademicYear, '-', 1); -- Extracting the year part from AcademicYear
     SET branch_code = NEW.branch; -- Assuming 'branch' is the field name

    SELECT counter INTO next_counter FROM project_sequence WHERE year = current_year AND branch = branch_code;

    IF next_counter IS NULL THEN
        INSERT INTO project_sequence (year, branch, counter) VALUES (current_year, branch_code, 1);
        SET NEW.projectID = CONCAT(RIGHT(current_year, 2), branch_code, LPAD(1, 2, '0'));
    ELSE
        SET NEW.projectID = CONCAT(RIGHT(current_year, 2), branch_code, LPAD(next_counter + 1, 2, '0'));
        UPDATE project_sequence SET counter = counter + 1 WHERE year = current_year AND branch = branch_code;
    END IF;
END
$$
DELIMITER ;

-- --------------------------------------------------------

--
-- Table structure for table `project_sequence`
--

CREATE TABLE `project_sequence` (
  `sr_no` int(11) NOT NULL,
  `year` int(11) NOT NULL,
  `counter` int(11) DEFAULT NULL,
  `branch` varchar(5) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `project_sequence`
--

INSERT INTO `project_sequence` (`sr_no`, `year`, `counter`, `branch`) VALUES
(1, 2023, 1, 'CM'),
(2, 2021, 1, 'CS'),
(3, 2024, 1, 'EC'),
(4, 2023, 2, 'EE'),
(5, 2022, 1, 'ME'),
(6, 2023, 3, 'EC');

-- --------------------------------------------------------

--
-- Table structure for table `reviews`
--

CREATE TABLE `reviews` (
  `reviewID` int(11) NOT NULL,
  `studentID` varchar(10) DEFAULT NULL,
  `reviewPoints` int(11) DEFAULT NULL,
  `remarks` text DEFAULT NULL,
  `reviewedDate` varchar(15) DEFAULT NULL,
  `reviewedFaculty` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `reviews`
--

INSERT INTO `reviews` (`reviewID`, `studentID`, `reviewPoints`, `remarks`, `reviewedDate`, `reviewedFaculty`) VALUES
(6, '21C51A0520', 8, 'Well', '2023-08-12', 'Santhosh'),
(7, '21C51A0520', 9, 'Well Explained', '2023-08-26', 'Davud'),
(8, '21C51A0520', 8, 'werwerrer', '2023-08-20', 'murali');

-- --------------------------------------------------------

--
-- Table structure for table `studentlogin`
--

CREATE TABLE `studentlogin` (
  `studentID` varchar(10) NOT NULL,
  `password` varchar(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `studentlogin`
--

INSERT INTO `studentlogin` (`studentID`, `password`) VALUES
('student', '1234');

-- --------------------------------------------------------

--
-- Table structure for table `students`
--

CREATE TABLE `students` (
  `StudentID` varchar(10) NOT NULL,
  `Password` varchar(20) NOT NULL,
  `FirstName` varchar(50) DEFAULT NULL,
  `LastName` varchar(50) DEFAULT NULL,
  `Email` varchar(100) DEFAULT NULL,
  `Department` varchar(50) DEFAULT NULL,
  `Year` varchar(10) DEFAULT NULL,
  `ContactNumber` varchar(15) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `students`
--

INSERT INTO `students` (`StudentID`, `Password`, `FirstName`, `LastName`, `Email`, `Department`, `Year`, `ContactNumber`) VALUES
('21C51A0520', '1234', 'Hemanth Singh', 'Kshatriya', 'hemanth@gmail.com', 'CSE', '2021', '8878797774'),
('21C51A0522', '1234', 'Murali Krishna', 'Mallela', 'mmallela9@gmail.com', 'CSE', '2021', '8712377211'),
('21C51A0529', '1234', 'Jaya Chandra', 'Narakulla', 'jaya@mail.com', 'CSE', '2021', '8885465457');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `admin`
--
ALTER TABLE `admin`
  ADD PRIMARY KEY (`username`);

--
-- Indexes for table `faculty`
--
ALTER TABLE `faculty`
  ADD PRIMARY KEY (`FacultyID`);

--
-- Indexes for table `participants`
--
ALTER TABLE `participants`
  ADD PRIMARY KEY (`ParticipantID`),
  ADD KEY `ProjectID` (`ProjectID`),
  ADD KEY `StudentID` (`StudentID`);

--
-- Indexes for table `projects`
--
ALTER TABLE `projects`
  ADD PRIMARY KEY (`ProjectID`),
  ADD KEY `FacultyAdvisorID` (`FacultyAdvisorID`);

--
-- Indexes for table `project_sequence`
--
ALTER TABLE `project_sequence`
  ADD PRIMARY KEY (`sr_no`);

--
-- Indexes for table `reviews`
--
ALTER TABLE `reviews`
  ADD PRIMARY KEY (`reviewID`),
  ADD KEY `studentID` (`studentID`);

--
-- Indexes for table `studentlogin`
--
ALTER TABLE `studentlogin`
  ADD PRIMARY KEY (`studentID`);

--
-- Indexes for table `students`
--
ALTER TABLE `students`
  ADD PRIMARY KEY (`StudentID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `participants`
--
ALTER TABLE `participants`
  MODIFY `ParticipantID` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=49;

--
-- AUTO_INCREMENT for table `project_sequence`
--
ALTER TABLE `project_sequence`
  MODIFY `sr_no` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT for table `reviews`
--
ALTER TABLE `reviews`
  MODIFY `reviewID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `participants`
--
ALTER TABLE `participants`
  ADD CONSTRAINT `participants_ibfk_1` FOREIGN KEY (`ProjectID`) REFERENCES `projects` (`ProjectID`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `participants_ibfk_2` FOREIGN KEY (`StudentID`) REFERENCES `students` (`StudentID`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `projects`
--
ALTER TABLE `projects`
  ADD CONSTRAINT `projects_ibfk_1` FOREIGN KEY (`FacultyAdvisorID`) REFERENCES `faculty` (`FacultyID`) ON DELETE SET NULL ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
