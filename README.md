# Sokoban
This project was made during my first year at Epitech Nantes.
It aims to recreate the Sokoban game in the terminal using the ncurses librairy.

# How to run ?

### Compile
Run ```make``` to compile the project.

### Run
Run ```./my_sokoban``` to run the project.

You must add maps as arguments for the game to start, you can add any number of maps as long as they follow these rules : 
 - ```#``` are walls.
 - ```P``` is the player.
 - ```X``` are boxes.
 - ```O``` are storage locations.

5 maps are provided in the project, you can lauch them all with :
```./my_sokoban maps/map_1.txt maps/map_2.txt maps/map_3.txt maps/map_4.txt maps/map_5.txt```

### Controls
You can move the character with the arrow keys and access the menu by pressing ```A```.
```SPACEBAR``` refreshes the actual level.

### Objective
The goal of the game is to place all of the boxes in storage locations.
If you get stuck, you can refresh the current level using ```SPACEBAR```.

**Have fun !**
