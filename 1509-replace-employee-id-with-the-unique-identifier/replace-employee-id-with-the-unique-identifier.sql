# Write your MySQL query statement below
SELECT unique_id , name
FROM employees as em
LEFT JOIN employeeuni as emu
ON emu.id = em.id;