Consider the following relational database name  :
Employees (employee_id, name, salary, email, department_id, designation_id)
Departments (department_id, department_name, location_id)
Designations (designation_id, title)
Locations (location_id, country_name)


## Create a database name “employee_management”.
```

create database employee_management;
```
## Create above four tables with appropriate primary key and foreign key.
```
create table Employees(
employee_id int NOT NULL,
    name varchar(255),
    salary float,
    email varchar(255),
    department_id int,
    designation_id int,
    PRIMARY KEY (employee_id),
    FOREIGN key (department_id) REFERENCES departments(department_id),
    FOREIGN key (department_id) REFERENCES designations(designation_id)
);
```
```
CREATE table Designations(
    designation_id int not null,
    title varchar(255),
    PRIMARY KEY (designation_id)
    );
```
```
create table Locations(
    location_id int not null,
    country_name varchar(255),
    PRIMARY KEY (location_id)
    );
```
```
create table Departments ( 
    department_id int not null,
    department_name varchar(255),
    location_id int,
     PRIMARY KEY (department_id),
       FOREIGN key (location_id) REFERENCES Locations(location_id)
   );
```

## Insert at least five values to all tables.
```
INSERT INTO locations(location_id, country_name)
VALUES(1,"Dhaka"),(2,"Rangpur"),(3,"Kurigram"),(4,"Faridpur"),(5,"Mymensigh")
```
```
INSERT INTO designations(designation_id, title)
VALUES(1,"Lecturer"),(2,"Asistant Professor"),(3,"Professor"),(4,"Asosiate Professor"),(5,"Lab Asistant")
```
```
INSERT INto departments(department_id,department_name,location_id)
VALUES(1,"CSE",2),(2,"EEE",1),(3,"ME",4),(4,"ECE",5),(5,"Mechanical",3)
```
```
INSERT into employees(employee_id,name,salary,email,department_id,designation_id)
VALUES (1, "Sumon Reza", 35000, "reza.sumon@gmail.com", 1, 1), (2, "Rasel Ahmed", 30000, "rasel.ju@gmail.com", 2, 4), (3, "Sameya Akter", 25000, "samiaakter@gmail.com", 3, 1), (4, "Tuhin Reza", 55000, "tuhinjust@gmail.com", 5, 1), (5, "Rony", 20000, "ahroni65@gmail.com", 5, 5)
```

## Display all the fields of employee table.
```
select * from employees;
```
## Retrieve employee name, salary, designation title and department name.
```
select employees.name, employees.salary, departments.department_name,designations.title
FROM employees
LEFT JOIN departments ON employees.department_id=departments.department_id LEFT JOIN designations ON employees.designation_id=designations.designation_id;

```
## Display all the employees located at “Bangladesh”.
```
select employees.name, locations.country_name
FROM employees
LEFT JOIN departments ON employees.department_id=departments.department_id
LEFT join locations ON locations.location_id=departments.location_id
WHERE locations.country_name="Dhaka"
```

## Display maximum salary from employee table.
```
SELECT name, MAX(salary)
from employees
```
## Display all the department name along with no of employees.

```
SELECT department_name, COUNT(employees.employee_id) 
FROM departments 
JOIN employees 
ON departments.department_id = employees.department_id 
GROUP BY department_name;
```

## Display all the employee who works in IT or HR department.
```
select employees.name, employees.salary, departments.department_name
FROM employees
LEFT JOIN departments ON employees.department_id=departments.department_id
where departments.department_name in ("IT","HR")
```

## Write a SQL statement to change the email column of employees table with 'not available' for those employees with department id 3.

```
update employees
SET email="Not Available"
where employees.department_id=3
```

## Write a SQL statement to add a column “contact_no” to employees table.
```
alter TABLE employees
add contact_no varchar(255) DEFAULT NULL
```

## Write a query to delete those employees from employees table with salary less than 10000.
```
DELETE from employees
WHERE employees.salary<=20000;
```



































