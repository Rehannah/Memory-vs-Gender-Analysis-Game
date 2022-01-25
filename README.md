# Memory-vs-Gender-Analysis-Game
*Visualises statistics to determine which gender has better memory (recall) and includes a memory game.* **Built with C++.**

Please feel free to 🌟**star**, **[fork](/LICENSE.txt)** or [**contribute to an issue**](/CONTRIBUTING.md) in this repository.
<br/><br/>

## Table of Content:
[ ✲ About](#about) <br/>
[ ✲ Case Study/Problem](#case-studyproblem) <br/>
[ ✲ Files Explained](#files-in-this-project) <br/>
[ ✲ Features Explained](#features-of-the-program) <br/>
[ ✲ TODO - things to implement later, bugs & issues](#todo) <br/>

<br/>

### About:
```
Name:	Rehannah Baptiste
Title: Memory vs. Gender Analysis Game
Description:  This program visualises statistics on which gender has better memory (recall) 
              and allows users to play a memory game which adds to the data. 	
Version 1.0: December 5th 2020
Current version: 1.5 (2022)
License: Open Source MIT
```
<br/>

### Case study/Problem:
**Do females have better memory than males?**
In a study it was found that women aged 45-55 years remember better than men of the same age range. It was also found that the average person’s short-term memory lasts 20-30 seconds and can remember 5-9 items in short term memory. These statistics were used to implement this program and test the accuracy of this claim.

<br/>

### Files in this project:
-	“highscores.txt” is the input/output data file listing the name, gender, number of words remembered and number of attempts by x number of users/players.
-	“words.txt” is a word list containing the words for the memory game, terminated by "END".

<br/>

### Features of the program:
-	Main Menu to aid in navigation in the program
-	Statistics:
1.	Finds the sum of words recalled by males and females (Menu option 1)
2.	Finds the average number of words recalled by males and females (Menu option 1)
3.	Finds and displays the total number of attempts and the percentage of attempts made by males and females (Menu option 2)
4.	Finds the top player, i.e., the person with the highest score in the least number of attempts (Menu option 3)
5.	Finds the highest male and female score (Menu option 4)
6.	Finds the number of players who recalled x words or more (Menu option 6)
-	Rename a player. (Menu option 5)
-	Generates a graph visualising all player data (Menu option 7)
-	View all saved highscores (Menu option 9)
-	**Surprise feature:** Memory game (Menu option 8)
The memory game tests players' ability to recall words. Their score is saved as a new value in the data file.
***How to play:***
When you start the game, words will flash on screen one by one. After all the words have been displayed, users must type as many as they can remember in any order. The score is the number of words remembered.
 
<br/>

## TODO
See more info on contribution guidelines in the [CONTRIBUTING.md](/CONTRIBUTING.md) file.
<br/>

### To be implemented:
- store male and female data in a struct - more efficient
- allow for a bigger word bank, so that the word list can be randomised.
- update README.md
<br/>

### Issues & Bugs:
- Menu option 5 does not work.
- Menu option 8 does not work.
- Menu option 9 does not work.
<br/><br/>


[Back to top ⬆ ](#table-of-content)
