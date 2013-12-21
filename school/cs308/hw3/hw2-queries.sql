select id,name from instructor where salary > 90000;
select id,name from instructor natural join teaches where course_id='CS-101';

select id from student where dept_name='Comp. Sci.';
select id,name from student where dept_name='Comp. Sci.' and tot_cred < 60;
select id from takes where course_id='Cs-101' and grade='A';
select id from takes where course_id='Cs-101' and grade='A' and semester='Fall' and year=2009;
select id,name from student natural join takes where course_id='CS-101' and grade='A';
select id,name from student natural join takes where course_id='CS-101' or course_id='CS-190' and grade='A';

