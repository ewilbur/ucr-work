//  ============== BEGIN ASSESSMENT HEADER ===============
/// @file assn<7>/User.h
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


#ifndef USER_H_
#define USER_H_

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
		bool set_password(const std::string&, const std::string&);
		bool check(const std::string&, const std::string&) const;
};


#endif	// USER_H_
