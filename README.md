# 20-Questions
20 questions game


Vision for the game:  
User starts the game by thinking of an animal (possibility to expand to future "decks").  The user then is asked a series of yes/no questions by the computer.  Based upon the responses by the user, the computer narrows down the list of possible anmials.  The computer is limited to 20 questions, hence the name of the game, and at the conclusion of 20 questions or when all but one options are exhausted the computer will make a guess.  If the user has selected an animal which the computer doesn't know about, the user is granted the option to add the animal to the "deck".  If they opt to they will have to anwser yes/no questions about all the qualities the computer stores. 


Back-end/How the Program works:
There will be a struct which contains a string of the name of the animal and then a long list of boolean values pertaining to attributes in the Animal Kingdom.  The struct will also include pointers for the purposes of a linked list.  This will be in individual boolean's in the struct rather than a sort of array of 1's and 0's for ease of access.  When the program is started it will read in all the information about the animals from ___________.  It will save this into a linked list. It will begin by asking the user a random question, and then cycle through the linked list removing those animals who dont satisfy the user's response.  The computer will then analyze the list and see the most common trait amongst the remaining animals.  It will then ask the user about that trait.  This process will cycle forward until either a) the computer narrows down the linked list to size 1, in which case it has its guess or b)the computer uses all 20 questions, in which case it takes a random guess from the remaining list.  
If the user has selected an animal not in the deck and opts yes for adding it to the deck, the computer will ask a long series of questions which give it the name of the animal and all the boolean operators pertaining to the animal.  This will have the effect of dynamically expanding the deck size through user interaction rather than developer hard coding.
