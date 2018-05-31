//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<4>/Message.h
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

#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

using std::string;

class Message
{
	private:
		std::string author;
		std::string subject;
		std::string body;
	
	public:
		Message();
		Message(const string&, const string&, const string&);

		void display() const;
};
#endif
