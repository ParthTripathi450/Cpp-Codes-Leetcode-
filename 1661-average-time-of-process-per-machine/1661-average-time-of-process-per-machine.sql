# Write your MySQL query statement below
/* Write your T-SQL query statement below */
SELECT machine_id,
       ROUND(
           SUM(
               CASE
                   WHEN activity_type = 'start' THEN -1.00 * timestamp
                   ELSE 1.00 * timestamp
               END
           ) / COUNT(DISTINCT process_id), 
           3
       ) AS processing_time
FROM Activity
GROUP BY machine_id;