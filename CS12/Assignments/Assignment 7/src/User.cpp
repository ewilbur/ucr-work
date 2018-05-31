//  ============== BEGIN ASSESSMENT HEADER ===============
/// @file assn<7>/User.cpp
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


#include "User.h"
#include <string>

using namespace std;

User::User()
{
	username = password = "";
}

User::User(const string &uname, const string &pass)
{
	username = uname;
	password = pass;
}

string User::get_username() const
{
	return username;
}

bool User::check(const string &uname, const string &pass) const
{
	if(uname == "" || pass == "")
		return false;

	else if(uname == username && pass == password)
		return true;

	else
		return false;
}

bool User::set_password(const string &oldpass, const string &newpass)
{
	if(username == "")
		return false;

	else if(oldpass == password)
	{
		password = newpass;
		return true;
	}

	else
		return false;
}
