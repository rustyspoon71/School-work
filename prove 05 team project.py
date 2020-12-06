"""The speed module contains the classes for playing the Speed action game. 

Author(s):      Jonathan Smith, Jessica Johnson , Russell Roberts
Email(s):       smi19107@byui.edu, joh19009@byui.edu, rob17096@byui.edu
"""
import curses
import curses.ascii
import os
import random
import sys

from curses import wrapper

PATH = os.path.dirname(os.path.abspath(__file__))
LIBRARY = open(PATH + "/words.txt").read().splitlines()
WORDS = 5
MAX_X = 60
MAX_Y = 20

class Game:
    """A game to play. 
    
    The responsibility of Game is to use the other classes in the system to 
    control the sequence of play.

    Stereotype:
        Controller
    """
    def __init__(self, input_service, output_service):
        # TODO: Create private attributes containing your new objects 
        self._words = Words()
        self._buffer = Buffer()
        self._score = Score()
        self._input_service = input_service
        self._output_service = output_service
        
    def play(self):
        while True:
            self._get_inputs()
            self._update_words()
            self._update_score()
            self._do_outputs()
            
    def _get_inputs(self):
        letter = self._input_service.get_letters()
        if letter == "*": 
            self._buffer.clear_letter()
        else:
            self._buffer.add_letter(letter)

    def _update_words(self):
        # TODO: Move each word. If one has reached the end of the screen 
        # then remove it and start another word out at the begining.
        for word in self.words.get_all():
            word.move_next()
            if word.is_expired():
                self._words.remove_word(word)
                text = random.choice(LIBRARY)
                replacement = word(text)
                self._words.add_word(replacement)
    def _update_score(self):
        # TODO: Get the letters from the buffer. For each word, check if it is 
        # found in the letters. If it is, remove it and start another word out 
        # at the begining. Make sure to give the player some points!
        letters = self._buffer.get_letters()
        word = self._words.get_word_for_letters(letters)
        if word is not None:
            points = word.get_points()
            self._score.add_points(points)
            self._words.remove_word(word)
            text = random.choice(LIBRARY)
            replacement = words(text)
            self._words.add_word(replacement)


    def _do_outputs(self):
        # TODO: Send a list of the actors in the program to the output_service 
        # for drawing on the screen.
        self._output_service.draw_actors(actors)
        list_actors = [self._buffer,self._score]
        list_actors.extend(self._words.get_all())


# ------------------------------------------------------------------------------
# Domain Classes
# ------------------------------------------------------------------------------
class Actor:
    """A visible, moveable thing that participates in the game.
    
    The responsibility of Actor is to keep track of its appearance, position 
    and velocity in 2d space.

    Stereotype:
        Information Holder
    """
    def __init__(self):
        self._text = ""
        self._position = (0, 0)
        self._velocity = (0, 0)
        
    def get_position(self):
        return self._position
    
    def get_text(self):
        return self._text

    def get_velocity(self):
        return self._velocity
    
    def move_next(self):
        x = 1 + (self._position[0] + self._velocity[0] - 1) % (MAX_X - 2)
        y = 1 + (self._position[1] + self._velocity[1] - 1) % (MAX_Y - 2)
        self._position = (x, y)
    
    def set_position(self, position):
        self._position = position
    
    def set_text(self, text):
        self._text = text

    def set_velocity(self, velocity):
       self._velocity = velocity


# ------------------------------------------------------------------------------
# Application Classes
# ------------------------------------------------------------------------------

# TODO: Consider creating a Buffer class that inherits from Actor. This class 
# could provides methods for 1) adding a letter, 2) clearing all the letters, 
# 3) and getting all the letters.
class Buffer(Actor):

    def __init__(self):
        super().__init__()
        self.letters = ""
        self.set_text(f'Buffer:{self._letters}')
        self.set_position((1, MAX_Y - 1))
        self.set_velocity((0,0))
    def add_letter(self, letter):
        self._letters += letter
        self.set_text(f"Buffer: {self._letters}")
    def get_letters(self):
        return self._letters
    def clear_letter(self):
        self._letters = ""


# TODO: Consider creating a Score class that inherits from Actor. This class 
# could provides methods for adding points (see Snake solution).
class Score(Actor):
    def __init__(self):
        super().__init__()
        self._points = 0 
        self.set_text (f'Score: {self._points}')
        self.set_position( (1,0) )
        self.set_velocity( (0,0) )
    def add_points(self,points):
        self._points += points

# TODO: Consider creating a Word class that inherits from Actor. This class 
# could provides methods for 1) getting the points it's worth (or it's length), 
# and 2) finding out if it is expired (or reached the right hand side of the 
# screen). You might just check the object's position as follows:
class word(Actor):
    def __init__(self,text):
        super().__init__()
        self.set_text(text)
        self.set_position((1, random.randint(1, MAX_Y - 1)))
        self.set_velocity((1,0))

    def get_points(self):
        text = self.get_text()
        return len(text)
#   
    def is_Expired(self):
        text = self.get_text()
        limit = MAX_X - (len(text) - 1)
        x, y = self.get_position()
        return x >= limit

# TODO: Feel free to use the following class if you'd like to. It may be 
# helpful for compelting the main game loop. Note that it makes a few 
# assumptions about the Word class. This can be helpful though.

class Words():
    """A collection of Word instances.
    
    The responsibility of Words is to keep track of the words a player is 
    trying to type. Words can also find those that match a group of letters.

    Stereotype:
        Structurer
    """
    def __init__(self):
        super().__init__()
        self._words = []
        for _ in range(WORDS):
            text = random.choice(LIBRARY)
            word = Word(text)
            self.add_word(word)

    def get_all(self):
        return self._words

    def get_word_for_letters(self, letters):
        result = None
        for word in self._words:
            text = word.get_text()
            if text in letters:
                result = word
                break
        return result

    def add_word(self, word):
        self._words.append(word)

    def remove_word(self, word):
        if word in self._words:
            self._words.remove(word)


# ------------------------------------------------------------------------------
# Infrastructure Classes
# ------------------------------------------------------------------------------
class InputService:
    """Detects player input.

    An InputService is responsible for detecting input from the keyboard and 
    providing the letters that were typed.

    Stereotype: 
        Service Provider
    """
    def __init__(self, window):
        self._window = window
         
    def get_letter(self):
        result = ""
        key = self._window.getch()
        if key == curses.ascii.ESC: 
            sys.exit()
        elif key == curses.ascii.NL: 
            result = "*"
        elif curses.ascii.isgraph(key): 
            result = chr(key)
        return result


class OutputService:
    """Outputs the game state.

    An OutputService is responsible for drawing the game state on the terminal. 
    
    Stereotype: 
        Service Provider
    """
    def __init__(self, window):
        self._window = window
    
    def draw_actors(self, actors):
        self._window.clear()
        self._window.border(0)
        for actor in actors:
            column, row = actor.get_position()
            text = actor.get_text()
            self._window.addstr(row, column, text)
        self._window.refresh()


# ------------------------------------------------------------------------------
# Entry Point
# ------------------------------------------------------------------------------
if __name__ == "__main__":
    curses.initscr()
    curses.curs_set(0)

    window = curses.newwin(MAX_Y, MAX_X, 0, 0)
    window.timeout(80)
    window.keypad(1)

    input_service = InputService(window)
    output_service = OutputService(window)
    game = Game(input_service, output_service)
    game.play()

    curses.endwin()