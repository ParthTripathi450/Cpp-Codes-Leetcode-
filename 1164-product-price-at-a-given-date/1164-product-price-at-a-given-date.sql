# Write your MySQL query statement below
select p1.product_id,
coalesce(
    (
        select p2.new_price
        from products p2
        where p1.product_id = p2.product_id
        and change_date <= '2019-08-16'
        order by p2.change_date DESC
        limit 1
    )
    ,10
) as price
from products p1
group by p1.product_id;
