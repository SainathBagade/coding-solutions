# Write your MySQL query statement below
select s1.student_id,
s1.student_name,
sub.subject_name,
count(e.subject_name) as attended_exams
from Students s1
cross join Subjects sub
left join Examinations e
  ON s1.student_id = e.student_id
      AND sub.subject_name = e.subject_name
      group by s1.student_id,s1.student_name,sub.subject_name
order by s1.student_id,s1.student_name
