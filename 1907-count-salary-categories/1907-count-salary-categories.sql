# Write your MySQL query statement below
SELECT 'High Salary' as category,
count(case when income > 50000 then 1 end) as accounts_count 
from accounts
union all
SELECT 'Low Salary' as category,
count(case when income <20000 then 1 end)
from accounts
union all
SELECT 'Average Salary' as category,
count(case when income >= 20000 and income <= 50000 then 1 end)
from accounts;