#Sprint 2 Reflection
##Gabe Butterick

###Written Reflection
Over the course of sprint 2, I learned about server/client implementation and communication. This sprint mostly consisted of large amounts of debugging and combing every inch of server and client code, which led to an increase in understanding of both how the code worked and how it could possibly go wrong. Some specifics were the importance of character array sizes, the difference between close and fclose, and a large amount of intricacy contained in the unp.h header file. Although we only managed to implement a tcp server/client relationship this sprint, when we anticipated getting through http, I learned a lot about debugging over a network and what all the functions involved in ftp do, return, and how they can fail.


###Head First C
https://github.com/buttegab/ExercisesInC/tree/master/exercises/ex03


###ThinkOS
https://github.com/buttegab/ExercisesInC/blob/master/reading_questions/thinkos.md

###Exam Question(s)

Question: What is the importance of leaving enough space in an data structure to store an integer? What can go wrong if there isn't enough?

Answer: The importance lies in how the bytes are stored. Because the bytes are stored from right to left, the left-most bytes will be lost. In this case, the most significant bits will be left out. Things that can go wrong consist of inadvertant negative values, completely wrong values, or temporarily working code that is a ticking time-bomb, just waiting to error.

Source: Head First C 163 (Geek Bits)