#Sprint 1 Reflection
##Gabe Butterick

###Written Reflection
Over the course of sprint 1, I learned a large amount about how servers work on a programatic level and the theory behind communication over the internet. My learning goals for sprint 1 were to get a better understanding of servers, the theory behind them, and feel comfortable implementing my own server to do more complex procedures than basic text communication. Though I did very little actual coding over sprint 1, the knowledge I gained from reading guides and blog posts helped me feel comfortable reading professional server code. I feel like sprint 1 contributed substantially to my learning goals, and I believe that sprint 2 will be more about active coding and implementing of ideas I read about.
The team continues to follow eduscrum pretty closely, having standups and retrospectives as required. Our work over the sprint prepared us for the sprint review in a mainly theoretical way, which proved to be the most useful for our team because we were able to have enlightening and discussion heavy conversation with the teaching team to clarify or reassure ourselves of our knowledge. Over the sprint, we slowly moved from theory to preparing for putting our thoughts and ideas into practice. Overall I think we handled our time well and effectively progressed through the sprint towards our goal of having an effective http server/client.


###Head First C
https://github.com/buttegab/ExercisesInC/tree/master/exercises/ex01
https://github.com/buttegab/ExercisesInC/tree/master/exercises/ex02
https://github.com/buttegab/ExercisesInC/tree/master/exercises/ex02.5


###ThinkOS
https://github.com/buttegab/ExercisesInC/blob/master/reading_questions/thinkos.md

###Exam Question(s)

Question: Explain why "include"s and helper functions traditionally go above main() in C.
Answer: The compiler works from the top down when going through the code, and if main were, perhaps, at the top, the compiler would attempt to use functions or macros that it hadn't seen declared, and would throw errors. Having main() be the last thing in a file keeps the compiler from missing anything important on the way down. In fact, any function that calls another function must be below that function or the compiler will throw an error.
Source: Head First C chapter 1 exercises. I found this particular facet of C while making smaller functions out of the larger main() and did a little research into why to come up with this understanding.