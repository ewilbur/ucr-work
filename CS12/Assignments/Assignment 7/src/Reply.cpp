//  ============== BEGIN ASSESSMENT HEADER ===============
/// @file assn<7>/Reply.cpp
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


#include "Reply.h" 

using namespace std;

Reply::Reply()
: Message()
{}

Reply::Reply(const string& athr,
	     const string& sbjct,
	     const string& body,
	     unsigned id)
: Message(athr, sbjct, body, id)
{}

string Reply::to_formatted_string() const
{
	stringstream formatted_ss;
	formatted_ss << "<begin_reply>"      << endl
		     << ":id: "      << id       << endl
		     << ":subject: " << subject  << endl
		     << ":from: "    << author   << endl;

	if(child_list.size() != 0)
	{
		formatted_ss << ":children:";
		for(unsigned i = 0; i < child_list.size(); i++)
		{
			formatted_ss << " " << child_list[i]->get_id();
		}
		formatted_ss << endl;

	}
	
	formatted_ss << ":body: " << body;
	if(body.at(body.length() - 1) != '\n')
		formatted_ss << '\n';
	formatted_ss << "<end>" << endl;

	return formatted_ss.str();
}
