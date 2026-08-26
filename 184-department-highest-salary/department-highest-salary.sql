SELECT Department , Employee ,Salary 
FROM (
    SELECT d.name as Department ,
           e.name as Employee ,
           e.salary,
           DENSE_RANK() OVER (
            PARTITION BY d.id
            ORDER BY e.salary DESC
           ) AS rnk
    FROM Department d
    JOIN Employee e
         ON d.id=e.departmentId
) t
WHERE rnk=1;