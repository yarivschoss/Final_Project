
From part 1 we have:
* Add a researcher to a research institute - 
we need to create a class of type Researcher with the field Article 
(a string that will be dynamically assigned) that will be derived from the Employee database
* Add a method to print all patients within the department class
(In my opinion, the most convenient is to implement an operator () that,
depending on the string you entered,
will output some output, for example,
if you created an object d of type department and called d("patients"), 
then it will print all the patients it holds, I did this in hospital as well, you can take a look).
* Add the same method to a research institute that displays all the researchers in it.
* ⁠ Add a search method by thesis that accepts an int id and returns a pointer to the 
patient and then prints his details (name and the department he is in).

Part 2:
* Add operator += to hospital and department which adds a doctor and a nurse (overloading operator +=)
* Add operator > which compares researchers according to the number of their articles
(In my opinion, the best thing is to create a field of an array of article strings that is dynamically allocated - each cell in the array is also an article string that needs to be dynamically allocated.
Then create a field of the number of articles in the researcher department which is simply the size of the array of strings, which will be updated all the time and then the operator will be much easier to compare).

Of course, the menu needs to be adapted to everything