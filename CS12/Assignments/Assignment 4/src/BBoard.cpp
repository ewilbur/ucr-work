//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<4>/BBoard.cpp
/// @brief Assignment <4> for CS 12 <Fall 2015>
///
/// @author <Evan Wilbur> [ewilb001@ucr.edu]
/// @date <10/28/2015>
///
/// @par Enrollment Notes
///     Lecture Section: <001>
/// @par
///     Lab Section: <023>
/// @par
///     TA: <Entezari N>
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER ===============

#include "BBoard.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int NUM_DASHES = 47;
const int MAX_SUBJECT = 256;
const int MAX_BODY = 1024;

using namespace std;

void printDashes()
{
	for(int i = 0; i < NUM_DASHES; i++)
	{
	    std::cout << '-';
	}
}

BBoard::BBoard()
{
	//Initializes BBoard with the title of the episode of Archer I was 
	//watching when I made this method. All these constructors are meant 
	//to do is give
	
	//the BBoard a title and a current user.
	title = "The Man From Jupiter";
	current_user = User();
}

BBoard::BBoard(const string &ttl)
{
	//See the above constructor if you want to know what this does. Only the
	//title is specified
	title = ttl;
	current_user = User();
}

bool BBoard::user_exists(const string &name, const string &pass) const
{
	//Returns true if the Username and password is in the database, 
	//otherwise returns false.

	for(int i = 0; i < user_list.size(); i++)
	    if(user_list[i].check(name, pass))
	        return true;

	return false;
}

void BBoard::setup(const string &inputFile)
{
	ifstream userShit(inputFile.c_str());
	char inputChar;
	char username[30];
	char password[30];
	int i = 0;
	int j = 0;
	bool isPass = false;


	while(userShit.get(inputChar))
	{
		if(inputChar == ' ' || inputChar == '\t')
		{
			isPass = true;
			i = 0;
		}
		else if(inputChar == '\n')
		{
			isPass = false;
			j = 0;
			
			user_list.push_back(User(username, password));
		}
		else if(isPass)
		{
			password[j] = inputChar;
			j++;
			password[j] = '\0';
		}
		else
		{
			username[i] = inputChar;
			i++;
			username[i] = '\0';
		}
	}

}

void BBoard::display() const
{
	//This is meant to display all stored messages. The formatting requires
	//that I have these dashes between messages so thats what that 
	//printDashes function does. I don't know, blame CS12 at UCR for 
	//this unnecessary stuff.
	if(message_list.size() == 0)
	{
		cout << "\nNothing to Display.\n";
	}
	else
	{
		for(int i = 0; i < message_list.size(); i++)
		{
			printDashes();
			cout << "\nMessage #" << i + 1 << ": ";
			message_list[i].display();
		}
		printDashes();
	}
	cout << endl;
}

void BBoard::login()
{
	//Will login to account if password and username are both correct.
	//Otherwise it will keep asking for login info until asked to stop with
	//Q or q.
	string username, password;

	cout << "Welcome to " << title << endl;
	
	while(true)
	{
		cout << "Enter your username('Q' or 'q' to quit): ";
		cin  >> username;
		if(username == "Q" || username == "q")
	    	{
	    		cout << "Bye!";
		    	return;
	    	}
	    
	    	cout << "Enter your password: ";
	    	cin  >> password;
	    
	    	if(user_exists(username, password))
	    	{
			cout << "\nWelcome back " << username << "!\n\n";
	        	current_user = User(username, password);
	        	return;
	    	}
	    	cout << "Invalid username or password!" << endl << endl;
	}
}

void BBoard::add_message()
{
	//Meant to add a Message instance to the message_list.
	string author = current_user.get_username();
	char subject[MAX_SUBJECT], body[MAX_BODY];

	cin.getline(subject, MAX_SUBJECT + 1);
	cout << "Enter Subject: ";
	cin.getline(subject, MAX_SUBJECT + 1);
	cout << "Enter Body: ";
	cin.getline(body, MAX_BODY + 1);
	message_list.push_back(Message(author, subject, body));
	cout << "Message Recorded!";
}

void BBoard::run()
{
	char userInput;

	for(int i = 0; i < user_list.size(); i++)
	{
		if(user_list[i].get_username() == current_user.get_username())
		{
			break;
		}
		else if(i + 1 == user_list.size())
		{
			return;
		}
	}

	do
	{
		cout << "Menu" << endl;
		cout << "\t- Display Messages (\'D\' or \'d\')" << endl;
		cout << "\t- Add New Message (\'N\' or \'n\')"  << endl;
		cout << "\t- Quit (\'Q\' or \'q\')"	        << endl;
		cout << "Choose an action: ";
		cin  >> userInput;
		if(userInput == 'd' || userInput == 'D')
		{
			display();
		}
		else if(userInput == 'N' || userInput == 'n')
		{
			cout << endl;
			add_message();
			cout << endl << endl;
		}
		else
		{
			return;
		}
	}while(userInput != 'q' || userInput == 'Q');
	
	cout << "Bye!" << endl;
}
