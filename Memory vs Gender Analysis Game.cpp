/*	Name:	Rehannah Baptiste
	Program Title: Memory vs Gender Analysis Game
	Program description:   This program visualises statistics to determine which gender has better memory (recall)
						   and allows users to play a memory game which adds to the data. 	
*/

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <cmath>

using namespace std;

#define QUIT 10					// QUIT constant
#define filename "highscores.txt"
#define wordlist "words.txt"
#define newfile "newhighscores.txt"

struct Player {
	int score; //player highscore
	string name; //Player name
	char gender; //player gender
	int attempt; //number of games played
};

//Menu function
int menu () {
	int choice;
	bool validChoice;
	
	validChoice = false;
	
	while (!validChoice) {
		system("cls");
		cout << "                   M E N U" << endl;
		cout << endl;
		cout << "  1.  Sum and average words remembered by males vs. females." << endl;
		cout << "  2.  Percentage of attempts made by males vs. females" << endl;
		cout << "  3.  List the top player(s) - highest number of words recalled in the least attempts." << endl;
		cout << "  4.  Male and female players with the highest and lowest number of words." << endl;
		cout << "  5.  Rename a player and save new data to file." << endl;
		cout << "  6.  Search for the number of occurrences where players remembered x words or more." << endl;
		cout << "  7.  Generate a graph showing all players' scores." << endl;
		cout << "  8.  Surprise feature: Play the memory game and add new data to file." << endl;
		cout << "  9.  Highscores" << endl;
		cout << "  10. Quit" << endl;
		cout << endl;
		cout << "  Please choose an option or " << QUIT << " to quit: ";
		cin  >> choice;
	
		if (choice >= 1 && choice <= QUIT)	// Ensures choice is within the range of menu options
			validChoice = true;
		else
			cout << "Invalid selection. Try again." <<endl;
			Sleep(2500);
			system("cls");
		if (choice==QUIT) {
			exit(1);
		}				
	}								
	
	return choice;
} //end of menu function



//printStars function
void printStars (int numStars) {
    int i;

    for(i = 1; i<= numStars; i= i+1)
        cout << "*";

    cout << endl;
}//end of printStars function



//Countdown Timer
void Timer(string timermsg, int numOfseconds) {
	int t;
	system("CLS");
	for (t=numOfseconds;t>0;t--) {
		cout << timermsg << t <<endl;
		Sleep(1000);
		system("CLS");
	}
} //end of Timer function


//Memory Game Menu
int MG () {
	int choice;
	bool validChoice;
	
	validChoice = false;
	
	while (!validChoice) {
		system("cls");
		cout << "Please make a selection from the menu below." <<endl <<endl;
		cout << "                   MEMORY GAME" << endl;
		cout << endl;
		cout << "  1.  Play game and save your score." << endl;
		cout << "  2.  How to play?" << endl;
		cout << "  3.  Return to Main Menu." << endl;
		cout << endl;
		cin  >> choice;
	
		if (choice >= 1 && choice <=4)	// Ensures choice is within the range of menu options
			validChoice = true;
		else
			while (validChoice==false) {
				cout << "Invalid selection. Try again: ";
				cin  >> choice;
				cout << endl;
				if (choice >= 1 && choice <=4)
					validChoice = true;
			}
			Sleep(2500);
			system("cls");					
	}
	
	return choice;
} //end of Memory Game menu function


void Rename(Player player, string newName) { // renames a player
	bool found = false;
	int i=0;
	
	ofstream out;
	out.open (newfile);

	cout << "Changing name..." <<endl;
	player.name=newName;
	cout << player.score << " " << player.name << " " << player.gender << " " << player.attempt << endl; 		
	cout << "Saving changes..." <<endl;
	
	Sleep(1000);
	cout << "Successfully changed player name. " <<endl;
}


//initialises data values upon each new game
void Init(Player player[], int stars[]) {
	//Initialising Highscore struct
	int i=0;
	for (i=0;i<100;i++) {
		player[i].score = 0;
		player[i].name =" ";
		player[i].gender =' ';
		player[i].attempt=0;
	}
	
	for (i=0;i<100;i++) {
		stars[i]=0;
	}
}


//read player data from the high scores list
int readPlayer (Player player[]) {
//opening files:
	cout << "Opening file..." << endl<<endl;
	ifstream in;
	in.open(filename);
	
	if (!in.is_open()) {
		Sleep(500);
		cout << "Input file could not open - No highscores found." << endl <<endl;
		return 404; //ERROR 404 - File not found
	}
	else {
		Sleep(500);
		cout << "Input file opened - Highscores retrieved." << endl<<endl;
	}
	
	int i=0;
	int score=0;
	in >> score;
	//while not -1 and within range
	while (score>=0 && i<100) {
		player[i].score = score;
		in >>player[i].name;
		in >>player[i].gender;
		in >>player[i].attempt;
		i++;
		in >> score;
	}//end of While storing data in the array
	
	cout << i << " players' data stored in array." <<endl <<endl;
	return i;
}



//read player data from the high scores list
int readWords (string Words[]) {
	//Word lists
	ifstream wordsin;
	wordsin.open(wordlist);
	
	if (!wordsin.is_open()) {
		Sleep(500);
		cout << "Word list could not be retrieved!" << endl <<endl;
		return 404; //ERROR 404 - File not found
	}
	else {
			cout << "Word list retrieved." << endl<<endl;
	}
	
	int i=0;
	string w;
	wordsin >> w;
	while (w!="END") { //words list
		Words[i]=w; // store it in array
		wordsin >> w;
		i++;
	}
	cout << i << " words retrieved." <<endl;
	return i;
}



//Main function
int main() {
	//Variables:
	int i, sel;
	int icurrent; // position in the array of the current player;
	bool found=false;
	string searchName=" ";
	
	string name=" ", word=" ", ans;
	int score=0, check=0;
	char gender=' ';
	int numOfdata=0;
	
	//Data Structures:
	Player player[100];
	string words[20];
	int stars[9];
	
	ofstream out;
	out.open(newfile);
	
	//Program execution
	cout << "  \t\tMEMORY GAME" << endl;
	cout << "  ================================================" << endl;
	cout << endl;
	
	//Initialise data structures and arrays
	Init(player,stars);
	
	//Storing data
	cout << "Storing data..." <<endl <<endl;
	
	numOfdata = readPlayer(player);

	cout << "Launching main menu..."<<endl <<endl;
	Sleep(2000);
	
	
	//Main Menu options
	
	while (sel!=QUIT) {
	sel = menu();
		//Selection 1 - Sum and Average words remembered by each gender
		if (sel==1) {
			//variables for this selection 1
			int sum_males=0, sum_females=0;
			int numOfmales=0, numOffemales=0;
			float avgscore_males,avgscore_females;
			
			//traversing array to find the sum of males and sum of female players
			for (i=0;i<numOfdata;i++) {
				if (player[i].gender=='M') {
					numOfmales++;
					sum_males+= player[i].score;
				}
				else {
					if (player[i].gender=='F') {
						numOffemales++;
						sum_females+=player[i].score;	
					}
				}
			}
			
			//Calculating averages
			avgscore_males=ceil (sum_males*1.0/numOfmales);
			avgscore_females=ceil (sum_females*1.0/numOffemales);
			
			//Outputs
			cout << "Total sum of words remembered by men = " << sum_males << " words." <<endl;
			cout << "Total sum of words remembered by women = " << sum_females << " words." <<endl <<endl;	
			
			cout << "Average number of words remembered by men = " << avgscore_males << " out of 20"<<endl;
			cout << "Average number of words remembered by women = " << avgscore_females << " out of 20"<< endl <<endl;	
			
			//Which gender remembered more words
			if (avgscore_males > avgscore_females) {
				cout << "Men remembered more words than Women." <<endl <<endl;
			}
			else {
				if (avgscore_males < avgscore_females) {
				cout << "Women remembered more words than Men." <<endl <<endl;
				}
				else {
					if (avgscore_males = avgscore_females) {
						cout << "Men and Women remembered approx. the same amount of words." <<endl <<endl;
					}
				}
			}
			system("pause");
		} //end of selection 1
	

		//Selection 2 - Percentage of attempts of males to females
		if (sel==2) {
			//Variables for this section
			int attempts_males=0, attempts_females=0; //sum of the attempts for males and females respectively
			float pAttempts_males=0, pAttempts_females=0; //percentage of those attempts for each gender
			
			//traversing the array to find the sum of all the attempts for both genders
			for (i=0;i<numOfdata;i++) {
				if (player[i].gender=='M') {
					attempts_males+= player[i].attempt;
				}
				else {
					if (player[i].gender=='F') {
						attempts_females+= player[i].attempt;
					}
				}
			}
			
			//calculating the percentage of attempts for each gender
			pAttempts_males=attempts_males*100.0/(attempts_males+attempts_females);
			pAttempts_females = 100 - pAttempts_males;
			
			cout << "Total attempts by all players: " << (attempts_females+attempts_males) <<endl;
			cout << fixed << setprecision(2) << "Percentage of attempts taken by males = " << pAttempts_males << "%" << endl <<endl;
			cout << fixed << setprecision(2) << "Percentage of attempts taken by females = " << pAttempts_females << "%" <<endl <<endl;
			
		
			//who played more attempts		
			if (pAttempts_males>pAttempts_females){
				cout << "Therefore the males took more attempts." <<endl <<endl;
			}
			else {
				if (pAttempts_males<pAttempts_females){
					cout << "Therefore the females took more attempts." <<endl <<endl;
				}
				else {
					if (pAttempts_males==pAttempts_females){
						cout << "Therefore the males and females took the same amount of attempts." <<endl <<endl;
					}
				}
			}
			
			system("pause");
		} //end of Selection 2
	
	
	
		//Selection 3 - Top players
		if (sel==3) {
			//Variables for this selection
			int topScore=player[0].score;
			int min_attempts = player[0].attempt;
			
			cout << "The top player is the player who remembered the most words with the least attempts: " <<endl;
			cout << "Top player(s): " <<endl;
			
			//Finding the top player(s)
			for (i=0;i<numOfdata;i++) {
				if ((player[i].score>topScore) && (player[i].attempt<min_attempts)) {
					topScore=player[i].score;
					min_attempts = player[i].attempt;
				}
			}
			//taking into account who has the least number of attempts as well as the highest number of words recalled
			for (i=0;i<numOfdata;i++) {
				if ((player[i].score==topScore) && (player[i].attempt==min_attempts)) {
					cout << player[i].name << " remembered " << topScore << " words in " <<min_attempts << " attempts." <<endl;	
				}
			}		

			system("pause");
		} //end of Selection 3
	
	
		
		//Selection 4 - Highest and lowest word count by both genders
		if (sel==4) {
			//Variables for this selection
			int max_males, max_females;
			int min_males, min_females;
			max_males = max_females= min_males = min_females = player[0].score;
			
			//finding the highest and lowest score for males and females
			for (i=0;i<numOfdata;i++) {
				if (player[i].score>=max_males && player[i].gender=='M') {
					max_males=player[i].score;
				}
				else{
					if (player[i].score>=max_females && player[i].gender=='F') {
					max_females=player[i].score;
					}
				}
				if (player[i].score<min_males && player[i].gender=='M') {
					min_males=player[i].score;
				}
				else {
					if (player[i].score<min_females && player[i].gender=='F') {
					min_females=player[i].score;
					}
				}
			}
			
			cout << "The highest number of words recalled by a woman is: " << max_females << endl;
			cout << "The highest number of words recalled by a man is: " << max_males << endl<<endl;
			cout << "The lowest number of words recalled by a woman is: " << min_females << endl;
			cout << "The lowest number of words recalled by a man is: " << min_males << endl<<endl;
			system("pause");
		} //end of Selection 4
		
				
		//Selection 5 - Renaming a player and saving it to the output file
		if (sel==5) {
			//Variables for this selection
			string OGname=" ",newName=" ";
			cout << "Renaming process..."<<endl;
			cout << "Please enter the original player name which you would like to change: ";
			cin >> OGname;
			bool found=false;
			i=0;
			while (found == false && i<numOfdata) {
				if (OGname==player[i].name) {
					found = true;
					break;
				}
				found = false;
				if (i>=numOfdata&&found==false) {
					i=0;
					cout << "No player found with that name."<<endl;
					cout << "Please enter the original player name which you would like to change: ";
					cin >> OGname;
				}
				i++;
			}
			cout << "Please enter the new player name to replace " << OGname << ": ";
			cin >> newName;
	
			
			Rename(player[i],newName); //using Rename function to change the player name
			//Saving changes
			
			for (i=0;i<numOfdata;i++) {
				out << player[i].score << " " << player[i].name << " " << player[i].gender << " " << player[i].attempt << endl; 		
			}
			out << "-1" <<endl;
			system("pause");
		}//end of selection 5
		
		
		//Selection 6 - Number of players who remembered x words or more
		if (sel==6) {
			//Variables for this selection
			i=0; //resetting i
			int x=0, xCount=0;
			
			cout << "Please enter a number, x. This will check the number of players who scored x or more." <<endl;
			cin >> x;
			while (x>=numOfdata) {
				cout << "Sorry. Only up to " << numOfdata << " were tested. Enter a valid number: ";
				cin >> x;
			}
			//counting the number of players who scored above the user-enetered variable, x
			for (i=0;i<numOfdata;i++) {
				if (player[i].score>=x) {
					xCount++;
				}
			}
			
			cout << xCount << " players scored " << x << " or more." <<endl;
			
			system("pause");
		} //end of Selection 6
		
		
		//Selection 7 - Graph of all player's scores
		if (sel==7) {
			for (i=0;i<9;i++) {
				stars[i]=0;
			}
			
			for (i=0;i<numOfdata;i++) {

				//Finding values for graph		
				if (player[i].score<=4) {
					stars[0]++;
				}
				if (player[i].score>=5 && player[i].score<=6) {
					stars[1]++;
				}
				if (player[i].score>=7 && player[i].score<=8) {
					stars[2]++;
				}
				if (player[i].score>=9 && player[i].score<=10) {
					stars[3]++;
				}
				if (player[i].score>=11 && player[i].score<=12) {
					stars[4]++;
				}
				if (player[i].score>=13 && player[i].score<=14) {
					stars[5]++;
				}
				if (player[i].score>=15 && player[i].score<=16) {
					stars[6]++;
				}
				if (player[i].score>=17 && player[i].score<=18) {
					stars[7]++;
				}
				if (player[i].score>=19 && player[i].score<=20) {
					stars[8]++;
				}
			}//end of for loop
		
		
			//Outputting the graph
			cout << "~ Graph showing the number of words (scores) for all players: ~ "<< endl <<endl;
			cout << "Words   | Stars"<<endl;
			cout << "19-20:\t|";
			printStars(stars[8]);
			cout << "17-18:\t|";
			printStars(stars[7]);
			cout << "15-16:\t|";
			printStars(stars[6]);
			cout << "13-14:\t|";
			printStars(stars[5]);
			cout << "11-12:\t|";
			printStars(stars[4]);
			cout << "9-10:\t|";
			printStars(stars[3]);
			cout << "7-8:\t|";
			printStars(stars[2]);
			cout << "5-6:\t|";
			printStars(stars[1]);
			cout << "<=4:\t|";
			printStars(stars[0]);
			cout << endl << endl;
				
			system("pause");
		}//end of selection 7
		
		
		//Selection 8 - Surprise Feature! - Memory Game
		if (sel==8) {
			sel=MG (); //launches game menu for the Memory Game
			if (sel==1) { //first selection in game menu
				found=false;
				cout << "Please enter your name in lowercase letters only: ";
				cin >> name;
				cout << "Please enter your gender using capital M/F: ";
				cin >>gender;				
				
				//Faulty code - it is correct because I ran it before and it was fully functioning but i dont know why it doesnt work now
				//The code works but the program does not :(
				//search to see if it is a previous player. if it is, it adds an attempt to their file
				while (!found && i<numOfdata) {
					for (i=0;i<numOfdata;i++) {
						if (name==player[i].name && gender==player[i].gender){ // accounts for unisex names. eg:Alex (M) is stored differently from Alex (F)
							found=true;
							player[i].attempt++;//add attempt
							icurrent=i;
						}
					}
					if (!found) { //if not found it searches for a new location in the array to store the data
						if (player[i].name==" ") {
							icurrent=i;
							player[icurrent].name=name;
							player[icurrent].gender=gender;
							player[icurrent].attempt=1;
							i=0;
						}
					}
				}//end of while
				int numOfwords = readWords(words);
				
				
				//game start
				cout << "Try to remember as much words as you can!";
				Sleep(2500);
				Timer("Game starts in: ", 3); //Timer function
							
				for (i=0;i<numOfwords;i++) {
					cout << endl;
					cout << "\t" << words[i];
					Sleep(3000);
					system("CLS");
				}				
				
				cout << "What words do you remember? Type them here in any order.\n Type 0 to check your answers!" <<endl <<endl;
				cin >>ans;
				check = 0;
				
				//checking how many you got correct
				while (check <=20 && ans!="0") {
					for (i=0;i<20;i++) {
						if (ans==words[i])  {
							words[i]="correct";
							score++;
							check++;
						}
					}
					if (i>20) {
					i=0;
					}
					cin>>ans;
				}//end of while
				
				cout << "You remembered " <<score <<" words!" <<endl;
				cout << "Saving game data to file..." <<endl; //saving new data
				
				out << player[icurrent].score << " " << player[icurrent].name << " "  << player[icurrent].gender << " "  << player[icurrent].attempt <<endl;
				
				Sleep (1500);
				cout << "Saved!" <<endl;
				
				
				system("pause");
			}//end of sel2 ==1
			
			if (sel==2) {
				cout << "\t How to play the memory game: " <<endl;
				cout << "When you start the game, words will flash on screen one by one." << endl;
				cout << "After all " << numOfdata << " words have been displayed, type as many as you can remember in any order." <<endl;
				cout << "Your score is the number of words remembered out of the " << numOfdata << "." << endl;
				cout << "Enjoy. Your game data is automatically saved after each attempt." <<endl;
				system("pause");
				sel=MG();
			} //end of 2nd selection in game menu
			else { //return to main menu
			
			}//end of 3rd selection from game menu
			
		}//end of selection 8
		
		
		if (sel==9) { //save data to files & view data
			cout << "Data saved to '" << newfile << endl;
			int player_score;
			string player_name;
			char player_gender;
			int player_attempt;
			for (i=0;i<numOfdata;i++) {
				score = player[i].score;
				name = player[i].name;
				gender = player[i].gender;
				attempt=player[i].attempt;
				out <<  player_score << " " << player_name << " "  << player_gender << " "  << player_attempt << endl;
				cout << player_score << " " << player_name << " "  << player_gender << " "  << player_attempt << endl;
			}
			out << -1;
		
			system("pause");
		}//end of selection 9
	
	
	} //end of all Selections
}
