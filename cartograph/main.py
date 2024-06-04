import os
import cmd
from random import randint
import time
from pynput import keyboard
import sys
import aaventure
from termcolor import colored







os.system('cls')

print(""" ▄██████▄   ▄████████    ▄████████    ▄████████ ███▄▄▄▄           ▄████████    ▄███████▄    ▄██████▄  
███    ███ ███    ███   ███    ███   ███    ███ ███▀▀▀██▄        ███    ███   ███    ███   ███    ███ 
███    ███ ███    █▀    ███    █▀    ███    ███ ███   ███        ███    ███   ███    ███   ███    █▀  
███    ███ ███         ▄███▄▄▄       ███    ███ ███   ███       ▄███▄▄▄▄██▀   ███    ███  ▄███        
███    ███ ███        ▀▀███▀▀▀     ▀███████████ ███   ███      ▀▀███▀▀▀▀▀   ▀█████████▀  ▀▀███ ████▄  
███    ███ ███    █▄    ███    █▄    ███    ███ ███   ███      ▀███████████   ███          ███    ███ 
███    ███ ███    ███   ███    ███   ███    ███ ███   ███        ███    ███   ███          ███    ███ 
 ▀██████▀  ████████▀    ██████████   ███    █▀   ▀█   █▀         ███    ███  ▄████▀        ████████▀  
                                                                 ███    ███                                 """)




class Main:

    def __init__(self, gold=0, life=20, mana=10, inventory_place=6, exp=0, level=1, dmg_atk=randint(3,6), name=""):
        #Global Var
        self.gold = gold
        self.life = life
        self.mana  = mana 
        self.inventory_place = inventory_place
        self.exp = exp
        self.level = level
        self.dmg_atk = dmg_atk
        self.name = ""
        #self.attack(0)
        self.begin()
        




    #UI
    def menu(self):
        print(f"""
              ________/‾‾‾‾‾‾‾ ɸ STATS ɸ‾‾‾‾‾‾‾\_______
              │                                       │
              │ Life: {self.life}                     │
              │ Gold: {self.gold}                     │
              │ Experience: {self.exp}                │
              │ Level: {self.level}                   │
              │ mana:  {self.mana}                    │
              │                                       │
              └───────────────────────────────────────┘


        """)
        




    #write letter by letter 
    def write(self, write):
        # Repeats for each letter.
        for i in write:
            # sys.stdout.write doesn't create a new line for each print
            sys.stdout.write(i)
            sys.stdout.flush()
            time.sleep(.005)
        next = input()




    #start of the adventure
    def start(self):
        with open(f"{self.name}/database.txt", "w", encoding="utf-8") as file:
            file.write(str(self.life))
            file.write(str(self.gold))
            file.write(str(self.exp))
            file.write(str(self.level))
            file.write(str(self.mana))
            file.write(str(self.name))
            file.write(str(self.dmg_atk))
            file.write(str(self.level))
            file.write(str(self.inventory_place))
            
            
        os.system('cls')
        self.menu()
        self.write("You are waking up on a beach, you dont remember anything about your past. You look around you see a Woods what do you do")
        print("1.Enter In the Woods")
        print("2.Look around You")
        print("3.Do nothing")
        instruction = input(">")
        if instruction == "1":
            self.write("you start going throught the Woods")

        elif instruction == "2":
            self.write("You start looking. All around you there is dust and sand, the sea is calm and blue. Good time to swim")
            time.sleep(2)
            self.start()

        elif instruction == "3":
            self.write("Are you stupid or what do something.")
            time.sleep(2)
            self.start()


        os.system("cls")
        self.menu()
        self.write("After passing some trees you see an old man, is look like searching for something.")

        self.write("What do you do?")
        self.write("1.Go talk to the old man")
        option = input(">")
        if option == "1":
            self.write(colored("Hello! [look on a parchment] but you are the hero it is exactly you that I have been waiting for years to approach embrace your destiny", 'blue'))
            self.write("He hands you an object! You can't figure out what it is")
            self.write(colored("It's an old damaged wooden sword covered with leaves [+1attack]", 'green'))
            #Update stats et inventory
            self.dmg_atk += 3
            self.write("The wooden sword is auto-equiped")

            #
            with open(f"{self.name}/inventory.txt", "w", encoding="utf-8") as file_in:
                file_in.write("wooden sword,3" + '\n')


        os.system('cls')
        self.menu()
        self.write("After this meeting you continue your way on path of porous earth")
        self.write("On this way there is a goblin is blocking the way")
        self.write("He looks angry and is holding a dagger.")
        time.sleep(1)
        print("He start attacking you!!!")
        time.sleep(1)
        self.attack(0)


    #Beginning of the second part after the goblin walk away
    def second_part(self):
        self.write("after this little altercation you go on your way. ")
        self.write("But you're lost. What do you want to do (North(n) black fir forest, East(e) strange wisp of smoke dissipating from the trees, Look around(l))")
        choice = input(">")
        if choice == "l" or choice == "Look around":
            self.write("There's nothing special except the dead goblin, you're in an imposing wood of trees, it's cool and a little foggy.")
            self.second_part()
        
        elif choice == "e" or choice == "East":
            self.write("While keeping your eye on the direction of this suspicious smoke, you hear small sounds coming from your destination. You don't even understand the language it's being pronounced in.")
            self.write("What do you do? (Continue(g), go back(b))")
            choice = input(">")

            if choice == "b":
                self.second_part()
            
            elif choice == "g":
                self.write("you keep going despite the sounds that are starting to get louder, and between some leaves you see that it's a camp, with humans and some orcs. They're all in armor, and some are wearing halberds.")

            else:
                self.write("Sorry you cant do that")
                self.second_part()


        
        elif choice == "n" or choice == "North":
            self.write("you try to make your way through the forest ")
            self.write("Suddenly you see a river in the distance What do you do (Go for a drink of water (g), look around (l), continue on your way)")
        
        else:
            self.write("Sorry you cant do that")
            self.second_part()

        




    #Beginning
    def begin(self):
        print("Welcome to Ocean Rpg.")
        print("1. Start a new game")
        print("2. Quit the Game")
        print("3. Load a game")
        choice = input("> ")
        if choice == "1":
            print(" ")
            self.name = input("What is you name Adventurer: ")
            os.mkdir(self.name)


            self.start()


    def reading_file(self, file, line):
        fp = open(file)
        lines=fp.readlines()
        fp.close()
        return (lines[line])

        






    #attack not yet finished
    def attack(self, ennemy_id):
        
        """with open("ennemies.txt") as file_ennemy:
        v = str(file_ennemy.readline(ennemy_id))
        print(v)

        temp_val_ennemy = [i for i in v.split(";")]"""

        temp_val_ennemy = self.reading_file("ennemies.txt", ennemy_id).split(";")

        ennemy_name = temp_val_ennemy[0]
        ennemy_life = temp_val_ennemy[1]
        ennemy_dmg = temp_val_ennemy[2]
        ennemy_dmg = int(ennemy_dmg)
        ennemy_life = int(ennemy_life)

        turn = 1

        while True:
            os.system("cls")
            #turn sys
            self.menu()
            
            #check à chaque debut de tour la vie de l'ennemi
            if ennemy_life <= 0:
                self.write("After a final hit, the creature fall")
                xp_won = randint(0,50)
                self.exp += xp_won
                self.write(f"You won {xp_won} experience points")
                self.second_part()

            #check pour les tours
            elif turn == 1:
                print("                  Your Turn")

            elif turn == 2:
                print("                  ennemy's turn")

            print("______________________________________________")
            print(ennemy_name, "Ennemy's health:", ennemy_life)
            print("______________________________________________")

            if turn == 1: 
                print("1. attack")
                print("2. Use magic")
                print("3. go to inventory")
                option = input("> ")
                if option == '1':
                    ennemy_life -= self.dmg_atk
                    self.write(f"You attack the {ennemy_name} for {self.dmg_atk}")

                    time.sleep(1)
                    turn = 2       

                elif option == '2':
                    print("no magic")
                    #faire la magie
                    turn = 1
                    time.sleep(1)  

                elif option == '3':
                    print("____/‾‾‾‾‾‾‾ ɸ INVENTORY ɸ‾‾‾‾‾‾‾\____")
                    with open(f"{self.name}/inventory.txt", "r", encoding="utf-8") as file_in:                        
                        print(file_in.read())
                    turn = 1
                    time.sleep(2)       
                else:
                    
                    print("invalid command")
                    time.sleep(0.5)
                    turn = 1

            elif turn == 2:
                print(f"{ennemy_name}","'s Turn", '\n')
                self.life -= int(ennemy_dmg)
                self.write(f"The {ennemy_name} attack you for {ennemy_dmg}")
                time.sleep(1)
                turn = 1


Main()

"""
#game over 
if self.life <= 0:
    print("You are dead")
    time.sleep(3)
    begin()
"""

