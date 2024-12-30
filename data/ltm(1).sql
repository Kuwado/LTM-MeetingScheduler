-- phpMyAdmin SQL Dump
-- version 5.1.1deb5ubuntu1
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Generation Time: Dec 16, 2024 at 03:30 PM
-- Server version: 8.0.40-0ubuntu0.22.04.1
-- PHP Version: 8.1.2-1ubuntu2.19

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `ltm`
--

-- --------------------------------------------------------

--
-- Table structure for table `attendances`
--

CREATE TABLE `attendances` (
  `id` bigint UNSIGNED NOT NULL,
  `meeting_id` bigint UNSIGNED NOT NULL,
  `student_id` bigint UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- --------------------------------------------------------

--
-- Table structure for table `meetings`
--

CREATE TABLE `meetings` (
  `id` bigint UNSIGNED NOT NULL,
  `teacher_id` bigint UNSIGNED NOT NULL,
  `status` enum('pending','confirmed','canceled') COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT 'pending',
  `type` enum('personal','group') COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT 'personal',
  `report` longtext COLLATE utf8mb4_unicode_ci,
  `start` datetime NOT NULL,
  `end` datetime NOT NULL,
  `date` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- --------------------------------------------------------

--
-- Table structure for table `timeslots`
--

CREATE TABLE `timeslots` (
  `id` bigint UNSIGNED NOT NULL,
  `start` time NOT NULL,
  `end` time NOT NULL,
  `date` date NOT NULL,
  `type` enum('personal','group','both') CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT 'personal',
  `status` enum('busy','free') COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT 'free',
  `teacher_id` bigint UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `timeslots`
--

INSERT INTO `timeslots` (`id`, `start`, `end`, `date`, `type`, `status`, `teacher_id`) VALUES
(1, '07:50:00', '09:15:00', '2024-11-15', 'both', 'free', 6),
(2, '03:30:00', '06:00:00', '2024-11-20', 'group', 'free', 6),
(3, '06:32:00', '07:10:00', '2024-11-05', 'both', 'free', 6),
(4, '15:50:12', '16:30:00', '2024-11-05', 'group', 'free', 6),
(5, '06:20:00', '06:45:00', '2024-11-05', 'both', 'free', 6),
(6, '15:20:00', '15:30:00', '2024-11-05', 'personal', 'free', 6),
(7, '15:25:00', '15:40:00', '2024-11-05', 'group', 'free', 6),
(8, '16:00:00', '16:20:00', '2024-11-05', 'group', 'free', 6),
(9, '15:35:00', '15:50:00', '2024-11-05', 'group', 'free', 6),
(10, '05:12:00', '06:13:00', '2024-12-03', 'personal', 'free', 6),
(11, '09:10:00', '10:00:00', '2024-12-03', 'personal', 'free', 6),
(12, '05:10:00', '07:20:00', '2024-12-03', 'group', 'free', 11),
(13, '10:10:00', '11:11:00', '2024-12-10', 'personal', 'free', 11);

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE `users` (
  `id` bigint UNSIGNED NOT NULL,
  `username` varchar(50) COLLATE utf8mb4_unicode_ci NOT NULL,
  `password` varchar(50) COLLATE utf8mb4_unicode_ci NOT NULL,
  `role` varchar(20) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT 'student',
  `first_name` varchar(50) COLLATE utf8mb4_unicode_ci NOT NULL,
  `last_name` varchar(50) COLLATE utf8mb4_unicode_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`id`, `username`, `password`, `role`, `first_name`, `last_name`) VALUES
(1, 'haha', '123', 'student', 'Viet', 'Hoan'),
(2, 'haha', '123', 'student', 'Viet', 'Hoan'),
(3, 'haha', '123', 'student', 'Viet oxiro', 'Hoan'),
(4, 'haha123', '123', 'student', 'Viet ox', 'Hoan oy'),
(5, 'kuwado', '123', 'student', 'Tanashi', 'Kuwado'),
(6, 'giaovien', '123456', 'teacher', 'Giao', 'Vien'),
(7, 'giaovien2', '123', 'teacher', 'Giao', 'Vien2'),
(8, 'giaovienmoi', '123', 'teacher', 'giao', 'vien'),
(9, 'giaovien22', '123', 'teacher', 'le', 'le'),
(10, 'giaovien123', '123', 'teacher', 'll', 'ss'),
(11, 'giaovien1234', '123', 'teacher', 'giao', 'vien');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `attendances`
--
ALTER TABLE `attendances`
  ADD UNIQUE KEY `id` (`id`),
  ADD KEY `fk_attendances_student_id_users` (`student_id`),
  ADD KEY `fk_attendances_meeting_id_meetings` (`meeting_id`);

--
-- Indexes for table `meetings`
--
ALTER TABLE `meetings`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `id` (`id`),
  ADD KEY `fk_meetings_teacher_id_users` (`teacher_id`);

--
-- Indexes for table `timeslots`
--
ALTER TABLE `timeslots`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `id` (`id`),
  ADD KEY `fk_teacher_id_users` (`teacher_id`);

--
-- Indexes for table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `id` (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `attendances`
--
ALTER TABLE `attendances`
  MODIFY `id` bigint UNSIGNED NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `meetings`
--
ALTER TABLE `meetings`
  MODIFY `id` bigint UNSIGNED NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `timeslots`
--
ALTER TABLE `timeslots`
  MODIFY `id` bigint UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=14;

--
-- AUTO_INCREMENT for table `users`
--
ALTER TABLE `users`
  MODIFY `id` bigint UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=12;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `attendances`
--
ALTER TABLE `attendances`
  ADD CONSTRAINT `fk_attendances_meeting_id_meetings` FOREIGN KEY (`meeting_id`) REFERENCES `meetings` (`id`) ON DELETE CASCADE ON UPDATE RESTRICT,
  ADD CONSTRAINT `fk_attendances_student_id_users` FOREIGN KEY (`student_id`) REFERENCES `users` (`id`) ON DELETE CASCADE ON UPDATE RESTRICT;

--
-- Constraints for table `meetings`
--
ALTER TABLE `meetings`
  ADD CONSTRAINT `fk_meetings_teacher_id_users` FOREIGN KEY (`teacher_id`) REFERENCES `users` (`id`) ON DELETE CASCADE ON UPDATE RESTRICT;

--
-- Constraints for table `timeslots`
--
ALTER TABLE `timeslots`
  ADD CONSTRAINT `fk_teacher_id_users` FOREIGN KEY (`teacher_id`) REFERENCES `users` (`id`) ON DELETE RESTRICT ON UPDATE RESTRICT;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
