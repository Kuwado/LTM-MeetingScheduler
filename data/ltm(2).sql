-- phpMyAdmin SQL Dump
-- version 5.1.1deb5ubuntu1
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Generation Time: Dec 30, 2024 at 09:44 PM
-- Server version: 8.0.40-0ubuntu0.22.04.1
-- PHP Version: 8.1.2-1ubuntu2.20

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

--
-- Dumping data for table `attendances`
--

INSERT INTO `attendances` (`id`, `meeting_id`, `student_id`) VALUES
(2, 2, 5),
(3, 2, 1),
(4, 2, 4),
(5, 3, 2),
(6, 4, 5),
(7, 5, 5),
(8, 5, 3),
(9, 6, 1),
(10, 7, 5),
(11, 8, 5),
(12, 9, 5),
(13, 10, 5),
(15, 11, 5),
(16, 13, 5),
(17, 14, 5),
(18, 2, 5),
(20, 2, 5),
(21, 2, 5),
(22, 17, 5),
(23, 18, 5);

-- --------------------------------------------------------

--
-- Table structure for table `meetings`
--

CREATE TABLE `meetings` (
  `id` bigint UNSIGNED NOT NULL,
  `timeslot_id` bigint UNSIGNED NOT NULL,
  `status` enum('pending','confirmed','canceled','doing','completed') CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT 'pending',
  `type` enum('personal','group') COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT 'personal',
  `report` longtext COLLATE utf8mb4_unicode_ci
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `meetings`
--

INSERT INTO `meetings` (`id`, `timeslot_id`, `status`, `type`, `report`) VALUES
(2, 2, 'pending', 'group', 'helo anh em\naa'),
(3, 3, 'doing', 'personal', NULL),
(4, 4, 'confirmed', 'personal', NULL),
(5, 5, 'completed', 'group', 'hoan\nhao\nqua\n'),
(6, 6, 'completed', 'personal', 'van\nban\ncuoc hop\nnay hay qua\nhoant òaoirahaoivjol\n'),
(7, 7, 'confirmed', 'personal', 'van\nban\ncuoc\nhop'),
(8, 8, 'pending', 'personal', ''),
(9, 9, 'pending', 'personal', ''),
(10, 10, 'doing', 'group', 'Hoan\nhòaojoia\nfjheiwj'),
(11, 16, 'pending', 'personal', NULL),
(12, 16, 'pending', 'personal', NULL),
(13, 17, 'pending', 'personal', NULL),
(14, 18, 'pending', 'personal', NULL),
(15, 2, 'pending', 'group', NULL),
(16, 1, 'pending', 'group', NULL),
(17, 14, 'pending', 'group', NULL),
(18, 19, 'pending', 'personal', NULL);

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
(2, '03:30:00', '06:00:00', '2025-01-20', 'group', 'free', 6),
(3, '06:32:00', '07:10:00', '2024-11-05', 'both', 'free', 6),
(4, '15:50:12', '16:30:00', '2024-11-05', 'group', 'free', 6),
(5, '06:20:00', '06:45:00', '2024-11-05', 'both', 'busy', 6),
(6, '15:20:00', '15:30:00', '2024-11-05', 'personal', 'busy', 6),
(7, '15:25:00', '15:40:00', '2024-11-05', 'group', 'free', 6),
(8, '16:00:00', '16:20:00', '2024-11-05', 'group', 'free', 6),
(9, '15:35:00', '15:50:00', '2024-11-05', 'group', 'free', 6),
(10, '05:12:00', '06:13:00', '2024-12-03', 'personal', 'busy', 6),
(11, '09:10:00', '10:00:00', '2024-12-03', 'personal', 'busy', 6),
(12, '05:10:00', '07:20:00', '2024-12-03', 'group', 'free', 11),
(13, '10:10:00', '11:11:00', '2024-12-10', 'personal', 'free', 11),
(14, '05:15:00', '07:12:00', '2024-12-16', 'group', 'free', 6),
(15, '08:20:00', '10:10:00', '2024-12-18', 'personal', 'free', 6),
(16, '07:00:00', '09:00:00', '2025-01-10', 'personal', 'busy', 6),
(17, '07:00:00', '08:00:00', '2025-12-30', 'personal', 'busy', 6),
(18, '07:00:00', '08:00:00', '2025-12-29', 'personal', 'busy', 6),
(19, '07:00:00', '08:00:00', '2024-12-30', 'personal', 'busy', 6);

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
(11, 'giaovien1234', '123', 'teacher', 'giao', 'vien'),
(12, 'vhvh', '123', 'student', 'll', 'vv'),
(13, 'ha189', '123', 'teacher', 'cao', 'ha'),
(14, 'hanoi123', '123', 'teacher', 'cao', 'hoan'),
(15, 'haha125', '123', 'student', 'nam', 'ha'),
(16, 'hoannuheoia', '123', 'teacher', 'hoan', 'liu'),
(17, 'hoanhuiraiahu', '123', 'teacher', 'haon', 'uho'),
(18, 'giaouhaiuh', '123456', 'student', 'ghuah', 'faifhoia'),
(19, 'hrioaejo', '123', 'teacher', 'uugh', 'uhryei'),
(20, 'jj', '123\'', 'student', '2s', 'dd'),
(21, 'hoaohfuorha', '123', 'teacher', 'hyeiw', 'hriha'),
(22, 'hahaih', '123456', 'student', 'nam', 'ha'),
(23, 'rhaf', 'uih', 'teacher', 'fvhi', 'ẳfeư'),
(24, 'fgaiuuifa', 'rdidue', 'teacher', 'reghhi', 'rua');

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
  ADD KEY `fk_meetings_timeslot_id_users` (`timeslot_id`);

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
  MODIFY `id` bigint UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=24;

--
-- AUTO_INCREMENT for table `meetings`
--
ALTER TABLE `meetings`
  MODIFY `id` bigint UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=19;

--
-- AUTO_INCREMENT for table `timeslots`
--
ALTER TABLE `timeslots`
  MODIFY `id` bigint UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=20;

--
-- AUTO_INCREMENT for table `users`
--
ALTER TABLE `users`
  MODIFY `id` bigint UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=25;

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
  ADD CONSTRAINT `fk_meetings_timeslot_id_users` FOREIGN KEY (`timeslot_id`) REFERENCES `timeslots` (`id`) ON DELETE CASCADE ON UPDATE RESTRICT;

--
-- Constraints for table `timeslots`
--
ALTER TABLE `timeslots`
  ADD CONSTRAINT `fk_teacher_id_users` FOREIGN KEY (`teacher_id`) REFERENCES `users` (`id`) ON DELETE RESTRICT ON UPDATE RESTRICT;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
