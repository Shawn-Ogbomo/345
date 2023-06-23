# Workshop 2: Move and Copy Semantics

In this workshop, you work with a large dynamically allocated array of C++ Standard Library strings and compare the performance of copy and move operations on that collection.



## Learning Outcomes

Upon successful completion of this workshop, you will have demonstrated the abilities to:

- retrieve records from a text file using an input file stream  object
- count the number of records in a text file
- monitor the time spent on a particular task using the `std::chrono` library
- implement **copy semantics** for a class with a resource
- implement **move semantics** for a class with a resource
- identify the processing-intensive operations in copy and move assignments

## Submission Policy

The workshop is divided into two coding parts and one non-coding part:

- *Part 1*: worth 0% of the workshop's total mark, is optional and designed to assist you in completing the second part.
- *Part 2*: worth 100% of the workshop's total mark, is due on **Sunday at 23:59:59** of the week of your scheduled lab.  Submissions of *Part 2* that do not contain the *reflection* are not considered valid submissions and are ignored.
- *reflection*: non-coding part, to be submitted together with *Part 2*. The reflection does not have marks associated to it, but can incur a **penalty of max 40% of the whole workshop's mark** if your professor deems it insufficient (you make your marks from the code, but you can lose some on the reflection).

The workshop should contain ***only work done by you this term*** or provided by your professor.  Work done in another term (by you or somebody else), or work done by somebody else and not **clearly identified/cited** is considered plagiarism, in violation of the Academic Integrity Policy.

Every file that you submit must contain (as a comment) at the top **your name**, **your Seneca email**, **Seneca Student ID** and the **date** when you completed the work.

- If the file contains only your work, or work provided to you by your professor, add the following message as a comment at the top of the file:

    > I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

- If the file contains work that is not yours (you found it online or somebody provided it to you), **write exactly which parts of the assignment are given to you as help, who gave it to you, or which source you received it from.**  By doing this you will only lose the mark for the parts you got help for, and the person helping you will be clear of any wrong doing.

## Compiling and Testing Your Program

All your code should be compiled using this command on `matrix`:

```bash
/usr/local/gcc/10.2.0/bin/g++ -Wall -std=c++17 -g -o ws file1.cpp file2.cpp ...
```

- `-Wall`: compiler will report all warnings
- `-std=c++17`: the code will be compiled using the C++17 standard
- `-g`: the executable file will contain debugging symbols, allowing *valgrind* to create better reports
- `-o ws`: the compiled application will be named `ws`

After compiling and testing your code, run your program as following to check for possible memory leaks (assuming your executable name is `ws`):

```bash
valgrind ws
```

To check the output, use a program that can compare text files.  Search online for such a program for your platform, or use *diff* available on `matrix`.





## Part 1 (0%)

This workshop consists of two modules:
- `w2_p1` (supplied)
- `TennisLog`

Enclose all your source code within the `sdds` namespace and include the necessary guards in each header file.



### `w2_p1` Module (supplied)

**Do not modify this module!**  Look at the code and make sure you understand it.



### `TennisLog` Module

The `TennisLog` module will contain two struct/classes:
- `TennisMatch`: contains data about a single match between two players
- `TennisLog`: manages a collection of matches

A **TennisMatch** is defined with a *struct* containing the following attributes:

- a string representing the *Tournament ID*
- a string representing the *Tournament Name*
- a positive integer representing the *Match ID*
- a string representing the *Winner* of the match 
- a string representing the *Loser* of the match 

Select appropriate data types and empty states for each attribute.

Overload the insertion operator to output a `TennisMatch` object to an output stream. If a given `TennisMatch` object is in an empty state then this overload will print out:

  ```
  Empty Match
  ```

  If the object is not in an empty state then it will insert into the stream the content of the object in the following format:

  ```
  Tourney ID : <tourney_id>
  Match ID : <match_id>
  Tourney : <tourney_name>
  Winner : <winner>
  Loser : <loser>
  ```

  The formatting details for the attributes printed out are:

  - All labels will be aligned to the right, on a field of **exactly** 20 characters wide
  - All values will be aligned to the left, on a field of **exactly** 30 characters wide
  - the label is separated from the value by ` : ` (space-colon-space)
  - the filling character is a dot (`.`)

  Review the `sample_output.txt` for hints.


A `TennisLog` is a *class* that will manage a dynamic array of `TennisMatches` and keep a count of how many are being stored. This class will define the following member functions:

- Default constructor
- A one argument constructor that receives a filename as a parameter (review the file `tennis-data.csv` to understand its format) from which we will populate the current object. This function will:

  - read the file to count the number of matches in the file (note the heading line in the file is not describing an actual match so do not count that line)
  - allocate dynamic memory for the array of matches based on the number found
  - reread the file from the beginning to load the actual match data into the array

- `addMatch()` is a modifier that receives a `TennisMatch` object and returns nothing. `addMatch` will attempt to append the parameter to the dynamic array of matches held by the current object. Resize the array appropriately to accommodate the new object and avoid memory leaks.

- `findMatches()` is a query that receives a name of a player as a parameter and returns a `TennisLog` object. `findMatches` will return a `TennisLog` that contains all of the matches where either the winner or loser's name matches the parameter.

- `operator[](size_t)` a query that will return the `TennisMatch` in the dynamic array at the index provided. If the array isn't populated then return an *empty* `TennisMatch` instead.

- `operator size_t()` is a casting operator that will convert the current object to a `size_t` value. The return value for this will be the size of the dynamic array of `TennisMatches` held by the current object.
    
To review the syntax for reading from a text file using an `std::ifstream` object see the chapter in your notes entitled [Custom File Operators](https://ict.senecacollege.ca/~btp200/pages/content/custo.html).

Add any other private members that your design requires (without changing the specs above)!



### Sample Output

When the program is started with the command:
```
ws tennis-data.csv
```
the output should look like the one from the `sample_output.txt` file.



### Test Your Code

To test the execution of your program, use the same data as shown in the output example above.

Upload your source code to your `matrix` account. Compile and run your code using the latest version of the `g++` compiler (available at `/usr/local/gcc/10.2.0/bin/g++`) and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 345_w2_p1
```
and follow the instructions.

***This part represents a milestone in completing the workshop and is not marked!***





## Part 2 (100%)

For this part of the workshop, upgrade the `TennisLog` class to include the Rule-of-5 and its associated functions. 

Also, add a new class called `Timer`, that will be useful in measuring how much time an operation takes. This class should have the following public members:
- `start()`: a modifier that starts the timer (takes the current timestamp and stores it in an attribute).
- `stop()`: a modifier that stops the timer (takes the current timestamp) and returns how many nanoseconds passed since the timer has started as a `long long` value.

Refer to the following reference documents on `std::chrono` to get started (there are examples in these pages that show exactly how to take a timestamp, calculate a duration between two timestamps, and print that duration to screen):

- [time point](https://en.cppreference.com/w/cpp/chrono/time_point)
- [duration](https://en.cppreference.com/w/cpp/chrono/duration)
- [duration_cast](https://en.cppreference.com/w/cpp/chrono/duration_cast)
- [now()](https://en.cppreference.com/w/cpp/chrono/steady_clock/now)





### Sample Output

When the program is started with the command:
```
ws tennis-data.csv
```
the output should look like the one from the `sample_output.txt` file.

**Note:** *Move operations* are **many orders of magnitude** faster than the *copy operations*.  If your experiments don't show such a significant difference in times, keep working on your implementation (the actual numbers will be different every time you run the application).




### Reflection

Study your final solution, reread the related parts of the course notes, and make sure that you have understood the concepts covered by this workshop. **This should take no less than 30 minutes of your time and the result is suggested to be at least 150 words in length.**

Create a **text** file named `reflect.txt` that contains your detailed description of the topics that you have learned in completing this particular workshop and mention any issues that caused you difficulty and how you solved them. Include in your explanation—**but do not limit it to**—the following points:
- the reason for the significant time difference between the copy and move operations.
- describe approach taken to read the input file (`tennis-data.csv`) in the `TennisLog` constructor and populate the dynamic array. Is there any way to avoid rereading the file?
- in the links above to `chrono` library, you were directed to use a `steady_clock` to take a timestamp.  Do some research and explain the difference between a `steady_clock` and a `system_clock`.  Are they the same? When should each one be used?

To avoid deductions, refer to code in your solution as examples to support your explanations.



### Submission

To test and demonstrate execution of your program use the same data as shown in the output example above.

Upload the source code and the reflection file to your `matrix` account. Compile and run your code using the latest version of the `g++` compiler (available at `/usr/local/gcc/10.2.0/bin/g++`) and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 345_w2_p2
```
and follow the instructions.

**:warning:Important:** Please note that a successful submission does not guarantee full credit for this workshop. If the professor is not satisfied with your implementation, your professor may ask you to resubmit. Re-submissions will attract a penalty.
