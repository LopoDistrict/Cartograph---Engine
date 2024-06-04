#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Sep  3 14:58:09 2020

@author: magali
"""

""" Snake
"""

import tkinter as tk
import random as rd
from math import isclose

class AppliSnake(tk.Tk):
    def __init__(self):
        """Constructeur de l'application."""
        tk.Tk.__init__(self)

        self.Largeur = 400 # taille de la fenêtre Hauteur
        self.Hauteur = 400 # taille de la fenêtre largeur
        self.PosX =   230 # Position X de la tête du serpent 
        self.PosY =  150 # Position Y de la tête du serpent 
        self.Rayon = 8 # Rayon des ovales du serpent
        self.direction = 'h' # Premier sens de déplacement du 
        self.Taille = 1 # Taille du 
        self.serpent = 1
        


        self.canv = tk.Canvas(self,  height= self.Hauteur,  width=self.Largeur)
        # La tête de couleur différente
        
        self.canv.focus_set()

        # Appel de la méthode gestionClavier lors de l'appui sur une touche
        self.canv.bind('<Key>',self.gestionClavier)

        self.canv.pack(padx =5, pady =5)
        ## Création d'un widget Button (bouton Quitter)
        
        # Création du texte Direction donnant la direction du serpent
        self.text = tk.StringVar()
        self.text.set("Direction : "+ self.direction )
        self.label = tk.Label(self, textvariable=self.text)
        self.label['fg']='black'  # Création du texte "Direction  de couleur noire
        self.label.pack(side=tk.RIGHT,padx=5,pady=5) # Insère le texte dans la fenêtre

        self.x0=rd.randint(0, 380)
        self.y0=rd.randint(0, 380)
        self.x1= self.x0+15
        self.y1 = self.y0+15

        self.bouton = tk.Button(self, text="Quitter", command=self.destroy)
        self.bouton.pack()
        

        self.tete= self.canv.create_oval(self.PosX-self.Rayon,self.PosY-self.Rayon, self.PosX+self.Rayon, self.PosY+self.Rayon,width=2,outline='black',fill='dark green')

        

        #Ajout V3
        self.apple()

        
    def gestionClavier(self,event):

        """ Gestion de l'événement Appui sur une touche du clavier """
        touche = event.keysym
        print(touche)
        # déplacement vers le haut
        if touche == 'z':
            self.direction = 'h'
        # déplacement vers le bas
        if touche == 's':
            self.direction = 'b'
        # déplacement vers la droite
        if touche == 'd':
            self.direction = 'd'
        # déplacement vers la gauche
        if touche == 'q':
             self.direction = 'g'
        if touche == "m":
            self.direction = 's'
        self.text.set("Direction : "+ self.direction )
        
        #Ajout V3

        

    def move(self):
        for i in range(self.Taille):
            self.tete = self.canv.create_oval((self.PosX + 10 )-self.Rayon,(self.PosY + 10)-self.Rayon, self.PosX+self.Rayon, self.PosY+self.Rayon,width=2,outline='black',fill='dark green')
        

        # déplacement vers le haut
        if self.direction == 'h':
            self.PosY -= 15
        #Compléter pour les autres directions

        if self.direction == 'b':
            self.PosY += 15

        if self.direction == 'd':
            self.PosX += 15

        if self.direction == 'g':
            self.PosX -= 15
        
        if self.direction == "s":
            self.PosX = 0
            self.PosY = 0
        
        #self.PosX == self.x0 and self.PosY == self.y0
        if  isclose(self.PosX, self.x0, abs_tol=20) and isclose(self.PosY, self.y0, abs_tol=20):
            self.canv.delete(self.rond)
            print("delete")
            self.Taille += 1
            self.apple()


        # Compléter pour revenir en bas lors de la sortie de la fenêtre 
        self.canv.coords(self.tete, self.PosX-self.Rayon,  self.PosY -self.Rayon,  self.PosX +self.Rayon,  self.PosY +self.Rayon)
        # Rappel de move après 200ms
        self.after(200, self.move)


    def apple(self):
        """Constructeur de l'application."""
        self.x0=rd.randint(0, 380)
        self.y0=rd.randint(0, 380)
        self.x1= self.x0+15
        self.y1 = self.y0+15

        
        self.rond = self.canv.create_oval(self.x0,self.y0,self.x1,self.y1, fill="red")
        #ajout de la zone de dessin "canv" à la fenêtre "self"
        self.canv.pack(padx =5, pady =5) #
        
        self.move()


        

if __name__ == "__main__":
    myapp = AppliSnake()
    myapp.mainloop()