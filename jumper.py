import random 

class jumper:
    def __init__(self):
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
    def cut_line(self):
        self.chute.pop(0)
    def is_alive(self):
        if len(self.chute) < 6:
            print("Jumper is dead game over")
            return False
        print("Your jumper is still alive")
        return True 
    def print_chute(self):
       for self.o in range(len(self.chute)):
           print(self.chute[self.o])
    

class target:
    def __init__(self):
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
        for self.i in self.word_letters:
            self.num_letters = self.num_letters + 1 
        for self.z in range(self.num_letters):
            self.list_of_spaces.append(r"_")

    def get_guess(self):
        self.guess = str(input("What letter would you like to guess? ")) 
    def is_found(self):
        self.x = 0
        for self.x in range(self.num_letters): 
            if self.word_letters[self.x] == self.guess:
                self.list_of_spaces[self.x] = self.guess 
                return True
        return False
    def has_letter(self): 
        print(self.list_of_spaces)
    def has_won(self):
        if self.list_of_spaces == self.word_letters:
            return True 
        return False 
    def win_message(self):
        print("congrats you won!")

jump = jumper()
targ = target()

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







        
                
    


          