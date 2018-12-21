-- https://leetcode-cn.com/problems/duplicate-emails/

select t.Email From (
select Email, count(1) as cnt From Person group by Email
) as t where cnt >1;