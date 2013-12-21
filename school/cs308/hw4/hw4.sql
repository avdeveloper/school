-- Problem 1:
-- 1.
select id
    from takes
    where grade='A' and course_id='CS-101'
    and id in (select id from takes where grade='A' and course_id='CS-319')
-- 2.
select id,name
    from takes
    natural join student
    where grade='A' and course_id='CS-101'
    and id in (select id from takes where grade='A' and course_id='CS-319')
-- 3.
select id
    from takes
    where grade='A' and course_id='CS-101'
    and id in (select id from takes where grade<>'A' and course_id='CS-319')
