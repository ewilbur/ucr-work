//  ============== BEGIN ASSESSMENT HEADER ===============
/// @file assn<7>/Reply.h
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


#ifndef REPLY_H_
#define REPLY_H_

#include "Message.h"

class Reply : public Message
{
	public:
		Reply();
		Reply(const std::string&,
		      const std::string&,
		      const std::string&,
		      unsigned id);

		virtual bool is_reply() const {return true;};
		virtual std::string to_formatted_string() const;
};
#endif	// REPLY_H_
