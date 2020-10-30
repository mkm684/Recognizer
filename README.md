# Recognizer C++ Code challenge

I have implemented the whole application. Including the RecognizerModel. 
I wanted to make sure my solution is correct and works. so there is no better way to check that than implementing it. 

compile: make
run : ./main
clean: make clean

Note: 
	For simulation. I assumed every person recognition result data is an integer, 
	and the latest training mode is just an average. Recognition result data were randomly generated numbers. if the same number were generated again then it was found on the last and no further training needed. Every new data (number) generated gets an ID.  

Question 2 Answer :

	1- the for statement should be in an else statement, because if(!p) is true then p.tags will
	an invalid value and the if statement in the for loop will always be and tag_types elements won't be printed
	
	2- Assuming tag_types.size == 200 as commented eventually "uint64_t(pow(2,i)))" will overflow and the catch 
	statement would through an exception. So only the first 64 elements of the tag_types will be printed if p is valid. 
	
	
