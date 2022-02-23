# Memory vs Gender Analysis Game
*Visualises statistics to determine which gender has better memory (recall) and includes a memory game.* **Built with C++.**

Please feel free to 🌟**star**, **[fork](/LICENSE)** or [**contribute to an issue**](https://github.com/Rehannah/Memory-vs-Gender-Analysis-Game/issues) in this repository.
<br/>

## Table of Contents:
[ ✲ About](#about) <br/>
[ ✲ Case Study/Problem](#case-studyproblem) <br/>
[ ✲ Files Explained](#files-in-this-project) <br/>
[ ✲ Features Explained](#features-of-the-program) <br/>
[ ✲ TODO - things to implement later, bugs & issues](#todo) <br/>
<br/>

### About:
```
Name:            Rehannah Baptiste
Title:           Memory vs Gender Analysis Game
Description:     This program visualises statistics on which gender has better memory (recall) 
                 and allows users to play a memory game which adds to the data. 	
Version 1.0:     December 5th 2020
Current version: 1.5 (2022)
License:         Open Source MIT
```
<br/>

### Case study/Problem:
* **Do females have better memory than males?**
- In one [study](https://www.sciencedaily.com/releases/2016/11/161109112447.htm), it was found that [women aged 45-55 years remember better than men of the same age range](https://www.medicalnewstoday.com/articles/313998). Other studies have found that [the average person’s short-term memory lasts 15-30 seconds and is able to store 5-9 items at a time](https://www.simplypsychology.org/short-term-memory.html).
- Statistics from these studies were used to implement this program and test whether these claims can be replicated.
<br/>

### Files in this project:
-	``“highscores.txt”`` is the input data file listing the name, gender, number of words remembered and number of attempts by x number of users/players, terminated by "-1".
-	``“words.txt”`` is a word list containing the words for the memory game, terminated by "END".
-	``“newhighscores.txt”`` is the output data file containing all high scores for all players, which includes any new data and is terminated by "-1".

<br/>

### Features of the program:
-	Main Menu to aid in navigation in the program.
-	Statistics:
    1.	Find the sum of words recalled by males and females. (Menu option 1)
    2.	Find the average number of words recalled by males and females. (Menu option 1)
    3.	Find the total number of attempts and the percentage of attempts made by males and females. (Menu option 2)
    4.	Find the top player, i.e., the person with the highest score in the least number of attempts. (Menu option 3)
    5.	Find the highest male and female score. (Menu option 4)
    6.	Find the number of players who recalled x words or more. (Menu option 6)
-	Rename a player. (Menu option 5)
-	Generate a graph visualising all player data. (Menu option 7)
-	View all saved high scores. (Menu option 9)
-	**Surprise feature:** Play a memory game. (Menu option 8) <br/>
    The memory game tests the player's ability to recall words. Their score is saved as a new value in the data file. <br/> <br/>
    ***How to play:*** <br/>
    1.  When you start the game, words will flash on-screen one by one. <br/>
    2.  After all the words have been displayed, enter as many of those words as you can remember in any order. <br/>
    3.  Your score will be equal to the number of words you correctly recalled. <br/>

## TODO
See more info on contribution guidelines in the [CONTRIBUTING.md](/CONTRIBUTING.md) file.
<br/>

### To be implemented:
- more efficient data structures for storing the data.
- allow for a bigger word bank, so that the word list can be randomised.
- include a larger data set of player data.
- update [README.md](/README.md)

### Issues & Bugs:
- Menu option 5 does not work.
- Menu option 8 does not work.
- Menu option 9 does not work.
<br/>

[Back to top ⬆ ](#table-of-content)
