# Write your MySQL query statement below
SELECT machine_id, round(
    (SELECT avg(a1.timestamp) FROM activity as a1 WHERE a1.activity_type = 'end' 
        AND a1.machine_id = a.machine_id)
     - (SELECT avg(a1.timestamp) FROM activity as a1 WHERE a1.activity_type = 'start'
        AND a1.machine_id = a.machine_id), 3)as processing_time
FROM activity as a
GROUP BY a.machine_id;
