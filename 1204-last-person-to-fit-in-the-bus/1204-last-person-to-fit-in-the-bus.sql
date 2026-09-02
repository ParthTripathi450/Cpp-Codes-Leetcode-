select person_name
from queue
where(
    select sum(q2.weight)
    from queue q2
    where q2.turn <= queue.turn
)<=1000
order by turn desc
limit 1