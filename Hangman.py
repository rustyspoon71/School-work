  
import random 

# All aspects of the image will be defined here.
class jumper:
    def __init__(self):
        
        # initalize the jumper image.

        self.chute = []
        self.chute.append(r"  ___  ")
        self.chute.append(r" /___\ ")
        self.chute.append(r" \   / ")
        self.chute.append(r"  \ /  ")
        self.chute.append(r"   0   ")
        self.chute.append(r"  /|\  ")
        self.chute.append(r"  / \  ")
        self.chute.append(r"       ")
        self.chute.append(r"^^^^^^^")
        self.guess = 0

    # Cut the line and pop out the top line of the list.
 
    def cut_line(self):
        self.chute.pop(0)

    # Check if he still has his parachute. 

    def is_alive(self):
        if len(self.chute) < 6:
            print("Jumper is dead game over.")
            self.guess = self.guess + 1
            return False
        if self.guess == 0:
            print("                                                                              ")
            print("Welcome to the game! All the words in the game will be related to cars. Enjoy!")
            self.guess = self.guess + 1
        if self.guess >= 1 and len(self.chute) != 5: 
            print("Your jumper is still alive. Guess again! ")
            self.guess = self.guess + 1
            return True 

    # Print out his Chute in the terminal.

    def print_chute(self):
       for self.o in range(len(self.chute)):
           print(self.chute[self.o])
    
# The target class will be all the interactions with the user.

class target:
    def __init__(self):
        
        # initialize member variables and the words that may be used.

        self.word = []
        self.word.append(r"car")
        self.word.append(r"mustang")
        self.word.append(r"camry")
        self.word.append(r"bmw")
        self.word.append(r"chevy")
        self.word.append(r"kia")
        self.word_letters=[]
        self.word_letters = list(self.word[random.randint(0,5)])
        self.num_letters = 0
        self.list_of_spaces = []

        # initialize the num letters we will have.

        for self.i in self.word_letters:
            self.num_letters = self.num_letters + 1 
        
        # initalize the spots showing how many letters there will be.

        for self.z in range(self.num_letters):
            self.list_of_spaces.append(r"_")

    # Get the guess from the user.

    def get_guess(self):
        self.guess = str(input("What letter would you like to guess? ")) 
    
    # Check if the letter is found and if it is display it.

    def is_found(self):
        self.x = 0
        for self.x in range(self.num_letters): 
            if self.word_letters[self.x] == self.guess:
                self.list_of_spaces[self.x] = self.guess 
                return True
        return False

    # Display the letter with the list of spaces.
        
    def has_letter(self): 
        print(self.list_of_spaces)

    # Check if the word matches.
        
    def has_won(self):
        if self.list_of_spaces == self.word_letters:
            return True 
        return False 
    
    # Display the win message.

    def win_message(self):
        print("Congrats you won!")

# initalize two class objects.

jump = jumper()
targ = target()

# This is the main gain loop and will contain all game logic.

while jump.is_alive() == True:
    targ.get_guess()
    if targ.is_found() == False:
        jump.cut_line()
    targ.has_letter()
    jump.is_alive()
    jump.print_chute()
    if targ.has_won() == True:
        targ.win_message()
        quit()