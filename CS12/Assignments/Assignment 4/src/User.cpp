//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<4>/User.cpp
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

#include "User.h"
using namespace std;

User::User()
: username(""), password("")
{}

User::User(const string &uname, const string &pass)
: username(uname), password(pass)
{}

string User::get_username() const
{
	return username;
}

bool User::check(const string &uname, const string &pass) const
{
	if(uname == "" || pass == "")
		return false;
	
	else if(username == uname && password == pass)
		return true;
	
	else
		return false;
}

bool User::set_password(const string &oldpass, const string &newpass)
{
	if(oldpass == password && get_username() != "")
	{
		password = newpass;
		return true;
	}
	else
		return false;
}
