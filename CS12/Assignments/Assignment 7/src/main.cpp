//  ============== BEGIN ASSESSMENT HEADER ===============
/// @file assn<7>/main.cpp
/// @brief Assignment <7> for CS 12 <Fall 2015>
///
/// @author <Evan Wilbur> [ewilb001@ucr.edu]
/// @date <11/29/2015>
///
/// @par Enrollment Notes
///	 Lecture Section: <21>
/// @par
///	 Lab Section: <1>
/// @par
///	 TA: <Entezari>
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER ===============

#include <string>
#include <iostream>
#include <fstream>
#include "Message.h"
#include "Topic.h"
#include "Reply.h"
#include "BBoard.h"


using namespace std;

int main(int argc, char **argv)
{
	if(argc != 3)
	{
		cout << "ERROR: Invalid program call."            << endl
		     << "Usage: <program_name> userfile datafile" << endl;
	}

	string userfile(argv[1]);
	string datafile(argv[2]);

	BBoard bb("CS12 Bulletin Board");

	if(!bb.load_users(userfile))
	{
		cout << "ERROR: Cannot load users from " << userfile << endl;
		return 1;
	}

	if(!bb.load_messages(datafile))
	{
		cout << "ERROR: Cannot load messages from " << datafile << endl;
		return 1;
	}

	bb.login();
	bb.run();

	if(!bb.save_messages(datafile))
	{
		cout << "ERROR: Cannot save messages to " << datafile << endl;
		return 1;
	}

	return 0;
}

/******************************************************************************
 ******************************* TEST HARNESS *********************************
 ******************************************************************************


	if(argc != 3)
	{
		cout << "ERROR: Invalid program call."            << endl
		     << "Usage: <program_name> userfile datafile" << endl;
	}

	string userfile(argv[1]);
	string datafile(argv[2]);

	BBoard bb("CS12 Bulletin Board");

	if(!bb.load_users(userfile))
	{
		cout << "ERROR: Cannot load users from " << userlive << endl;
		return 1;
	}

	if(!bb.load_messages(datafile))
	{
		cout << "ERROR: Cannot load messages from " << datafile << endl;
		return 1;
	}

	bb.login();
	bb.run();

	if(!bb.save_messages(datafile))
	{
		cout << "ERROR: Cannot save messages to " << datafile << endl;
		return 1;
	}

	return 0;

 ******************************************************************************
 ******************************************************************************
 *****************************************************************************/
