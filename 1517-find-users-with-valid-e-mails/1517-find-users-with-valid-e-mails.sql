# Write your MySQL query statement below
select user_id,name,mail
from users
where REGEXp_like(mail, '^[a-zA-Z][a-zA-Z0-9_.-]*@leetcode\\.com$'
,'c');

-- SELECT user_id, name, mail
-- FROM Users
-- WHERE REGEXP_LIKE(
--     mail,
--     '^[a-zA-Z][a-zA-Z0-9_.-]*@leetcode\\.com$',
--     'c'
-- );