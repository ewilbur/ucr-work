//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<4>/User.h
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

#ifndef USER_H
#define USER_H

#include <string>

class User
{
	private:
		std::string username;
		std::string password;
	public:
		User();
		User(const std::string&, const std::string&);
		std::string get_username() const;
		bool check(const std::string&, const std::string&) const;
		bool set_password(const std::string&, const std::string&);
};
#endif
