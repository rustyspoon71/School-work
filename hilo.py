

import random

class dealer:
    # declare score to use within the class
    def __init__(self):
        self.score = 0 
    # Generate random cards
    def deal_cards(self):
        self.card = random.randint(0,52)
        self.card2 = random.randint(0,52)
    def compare(self):
        # compare the different values with input from the user
        # case 1 user inputs Y or y to guess the card code will check if it is true
        Hilo = input("Do you think the next card will be higher? Y/N? ")
        if Hilo == "Y" or Hilo == "y": 
            if self.card2 >= self.card:
                print("You are right! You've won 100 points! The card was ", self.card2)
                self.score = self.score + 100
            else:
                print("Sorry you were wrong you lost 75 points! The card was ", self.card2)
                self.score = self.score - 75 
        # case 2 user inputs n or N compute their answer
        if Hilo == "N" or Hilo == "n":
            if self.card2 <= self.card:
                print("You are right! You've won 100 points! The card was ", self.card2)
                self.score = self.score + 100
            else:
                print("Sorry you were wrong you lost 75 points! The card was ", self.card2)
                self.score = self.score - 75 
    def score_method(self):
        # print their score out easier to make own method
        print("Youre score is: " , self.score)
def run_games():
    # the driver of the program will run the game
    # define the class
    deal = dealer()
    # initialize play_again variable 
    play_again = True 
    # the code that runs the game
    while play_again == True:
        # deal them their cards
        deal.deal_cards()
        print("You were dealt a ",deal.card)
        # compare their card to the hilo variable
        deal.compare()
        # print their score
        deal.score_method()
        # get input on whether they would like to play again or not
        play_y_n = input("Would you like to play again? Y/N ")
        # if they would like to play again they will not enter this if statement
        if play_y_n == "N" or play_y_n == "n":
            play_again = False 
run_games()
            


        


        
