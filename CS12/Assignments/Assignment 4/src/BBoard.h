//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<4>/BBoard.h
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

#ifndef BBOARD_H
#define BBOARD_H

#include <string>
#include <vector>
#include <fstream>
#include "User.h"
#include "Message.h"



class BBoard
{
	private:
		std::string title;
		User current_user;
		std::vector<User> user_list;
		std::vector<Message> message_list;

	    bool user_exists(const std::string &name,
						 const std::string &pass) const;
 
		void display() const;
		void add_message();
	    
	public:
		BBoard();
		BBoard(const std::string &ttl);
		void setup(const std::string &input_file);
		void login();
		void run();

};
#endif

