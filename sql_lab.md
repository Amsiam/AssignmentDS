    1. Create a database name “library_management”.
    
       ```
       CREATE DATABASE library_managment;
       ```
   
    ## 2. Create above five tables with appropriate primary key and foreign key.
       ```
	CREATE TABLE books(
	    books_id int(11) AUTO_INCREMENT,
	    book_title varchar(255),
	    author varchar(255),
	   
	    price int,
	    publisher_name varchar(255),
	    
	    PRIMARY KEY(books_id)
	    
	    );
	CREATE TABLE member(
	    member_id INT(11) AUTO_INCREMENT,
	    NAME VARCHAR(255),
	    address TEXT,
	    phone VARCHAR(11),
	    PRIMARY KEY(member_id)
	); CREATE TABLE designations(
	    designation_id INT(11) AUTO_INCREMENT,
	    title VARCHAR(50),
	    
	    PRIMARY KEY(designation_id)
	); CREATE TABLE ISSUER(
	    issuer_id INT(11) AUTO_INCREMENT,
	    issuer_name VARCHAR(255),
	    designation_id INT(11),
	    PRIMARY KEY(issuer_id),
	    FOREIGN KEY(designation_id) REFERENCES designations(designation_id)
	); CREATE TABLE books_lend(
	    id INT(11) AUTO_INCREMENT,
	    member_id INT(11),
	    issuer_id INT(11),
	    book_id INT(11),
	    issue_date DATE,
	    return_date DATE,
	    PRIMARY KEY(id),
	    FOREIGN KEY(member_id) REFERENCES member(member_id),
	    FOREIGN KEY(issuer_id) REFERENCES ISSUER(issuer_id),
	    FOREIGN KEY(book_id) REFERENCES books(book_id)
	);
  ```
    ##3. Insert at least five values to all tables.
    ```
    INSERT INTO designations(title) VALUES("A"),("B"),("C"),("D"),("E");
    INSERT INTO ISSUER(issuer_name,designation_id) VALUES("A",1),("B",1),("BA",2),("AB",2),("ACD",3);
    INSERT INTO member(name,address,phone) VALUES("A","abc","01700823600"),("AB","abc","01700823604"),("AC","abc","01700823603"),("AD","abc","01700823602"),("AE","abc","01700823601");
    INSERT INTO books(book_title,author,price,publisher_name) VALUES("book1","abc",100,"pub1"),("book2","abc",120,"pub1"),("book3","abc",130,"pub2"),("book4","abc1",105,"pub12"),("book5","def",100,"pub1");
    INSERT INTO books_lend(member_id,issuer_id,book_id,issue_date,return_date) VALUES
    (1,2,1,"2022-12-13","2022-12-20"),
    (1,1,3,"2022-12-11","2022-12-21"),
    (2,2,1,"2022-12-12","2022-12-22"),
    (3,1,2,"2022-12-14","2022-12-23"),
    (2,3,4,"2022-12-15","2022-12-24");
    ```
    ##4. Display all the fields of Books table.
    ```
    SELECT * FROM books;
    ```
    ##5. Display all the books where price greater 1200.
    ```
    SELECT * FROM books WHERE price>1200;
    ```
    ##6. Display all the members and issue date who lended books.
    ```
    SELECT name,issue_date FROM books_lend 
	JOIN member 
	ON member.member_id = books_lend.member_id;
  ```
    ##7. Display issuer name and designation who have issued books before 10-10-2021.
  ```
	SELECT issuer_name,designations.title FROM books_lend 
	JOIN ISSUER 
	ON ISSUER.issuer_id = books_lend.issuer_id
	join designations
	on ISSUER.designation_id= designations.designation_id
	where issue_date<"2022-10-10"
  ```
    ##8. Display total number of books lended.
    ```
    SELECT count(*) as total_book FROM books_lend
    ```
    ##9. Display all the members with expired return_date.
    ```
    SELECT member.* FROM books_lend 
	join member
	on member.member_id = books_lend.member_id
	where return_date < now();
  ```
    ##10. Write a SQL statement to change the publisher_name column of books table with 'not applicable' for those books where price greater than 1200 .
    ```
    UPDATE books SET publisher_name = 'not applicable' where price>1200
    ```
    ##11. Write a SQL statement to add a column “contact_no” to member table.
    ```
    ALTER TABLE member ADD contact_no varchar(11);
    ```
    ##12. Write a query to delete those employees from books table with publisher “not applicable”.
    ```
    DELETE FROM books where publisher_name = "not applicable"
    ```
