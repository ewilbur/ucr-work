//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<4>/Message.cpp
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

#include "Message.h"
//#include <string>
#include <iostream>

using namespace std;

Message::Message()
: author(""), subject(""), body("")
{}

Message::Message(const string &athr, const string &sbjct, const string &body)
: author(athr), subject(sbjct), body(body)
{}

void Message::display() const
{
	std::cout << subject << std::endl;
	std::cout << "from " << author << ": " << body << std::endl;
}
