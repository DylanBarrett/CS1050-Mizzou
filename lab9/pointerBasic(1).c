/*******
 *******
  	"*Pointers are variables whose value are *memory address*. Normally, a variable directly contains
	  a specific value(so, if we were to do such: int x = 4;. This variable 'x' directly contains the
	  specific value 4). A *Pointer, on the other hand, contains an *address of a variable that contains
	  a value(so, if we were to stick with the example above, adding such: int x = 4;  int *xPtr = &x;. 
	  This declared pointer 'xPtr' contains the address of the variable 'x' such that 'x' contains the
	  specific value 4). In this sense, a variable name directly references a value, and a pointer indirectly
	  references a value(so, if we stick with our example above, such that 'x' directly refers to the specific
	  value 4, where the pointer indirectly refers to that value 4). 

	
		Let's pop the hood and see whats going on:

									   x
									*******
									*     *	This variable name 'x' directly
									*  4  *  references a variable that 
									*     *  contains the value 4.
			 				 	    *******		
		
			  xPtr			     	   x
 			*******					*******
			* **  *					*     *	This pointer 'xPtr' indirectly
			* ********************>>*  4  *  references a variable that 
			* **  *					*     *  contains the value 4.
			*******  				*******					
									

	******				~Common Programming Error 7.1~					******
	******	The asterisk (*) notation used to declare pointer variables ******
			 does not distribute to all variable names in a declaration.
			 Each Pointer must be declared with * prefixed to the name;
			 e.g. if you wish to declare 'xPtr' and 'yPtr', use:
			 	int *xPtr, *yPtr;. 
	******																******
	******																******

	

	******				~Common Programming Pratice 7.1~				******
	******	We prefer to include the letters 'Ptr' in Pointer variable  ******
			 names to make it clear that these variables are pointers
 			 and thus need to be handled appropriately.
 	******																******
	******																******
	
	******				~Error-Prevention Tip 7.1~						******	
	******	Initialize Pointers to prevent unexpected results.			******
	******																******		
	******																******

	The above information was taken from: ~"C How to Program" by -Paul Deitel -Harvey Deitel .	

	
	Lets take a look at some code.....
*******
*******/

#include <stdio.h> /*We declare our standard output/input
					 library so we can use the printf
					 function */

#define SIZE 5 /*We declare a macro(technical term), titled 'SIZE'.
				 i.e. 'SIZE' is a symbolic constant */
				 
int main(void)
{
	int a[SIZE] = {44, 8, 16, 42, 22};
	int *bPtr; /*This statement declares a pointer of 'int'
				 data type */  

	bPtr = a; /*We assign 'a' to 'b'. i.e. 'a' is an array of
			 type 'int', where 'a' is pointing to the first element
			 in its array (this value being 44), we do this assignment
			 (b = a), so b will be pointing to 'a'('b' only containing the
			 address of 'a'). */

	printf("*bPtr:%d\n", *bPtr); /*This will print off the whatever 'b' is pointing to,
						  where 'b' points to 'a' >>>> 'a' points to the first
						  element. The asterisk (*) used in this statement is 
						  called a the deference operator, where in this statement
						  DEreferences(indirectly references) 'a' first value. */

	printf("a[0]%d\n", a[0]); /* Straight forward */
	
	printf("a[2]:%d\n", a[2]);  /* Straight forward */
	
	printf("*(bPtr+1):%d\n", *(bPtr+1)); /* Now, what is happening here is 'b', which points to the
							   first element in array 'a', will bump to the next value.
							   TAKE NOTE: Say integer takes up 4 bytes in memory, 
							   what is really happening behind the scene is
							   (b + 1 * 4), where 4 is the value of an integer in bytes
							   in memory.
							   TAKE NOTE: Because we did not assign this addition operation
							   back to 'b', after this line executes, say when we continue from
							   line 90, 'b' will still be pointing to 'a', which points to the first
							   element in its array. */

	printf("a[1]:%d\n", a[1]); /* Straight forward */
	
	printf("address of bPtr:%p\n(b/c 'b' is pointing to 'a')\n", bPtr); 	/* The conversion specifier '%p' is used to output the memory location of that 
						 	particular variable (prints off as a hexadecimal). */
	printf("address of a[0]%p\n", &a[0]); /* Take a look, notice how the statement above and this one are the same(b/c b is 
							  pointing at 'a'). */

	bPtr += 3;			/*Now, we are assigning something to b. What is happenning behind the scene, assuming that
					  an integer takes up 4 bytes in memory. */

	printf("*bPtr:%d\n", *bPtr); 
	
	printf("address of bPtr:%p\n(b/c 'b' is pointing to a[3] after the 'b += 3;' statement)\n", bPtr);

	printf("Address of a[3]:%p\n", &a[3]); /* Notice how the statement above prints off the same as this statement */

	printf("a[0]:%d\n", *&a[0]); /* Notice that this two statements are the exact same. */
	printf("a[1]:%d\n", *&a[1]); /* The & and * operators are complement to each other */ 

	return 0;
}

