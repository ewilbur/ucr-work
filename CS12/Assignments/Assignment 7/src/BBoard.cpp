//  ============== BEGIN ASSESSMENT HEADER ===============
/// @file assn<7>/BBoard.cpp
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


#include "BBoard.h"

using namespace std;


void printDashes()
{
	for(int i = 0; i < 47; i++)
	{
		cout << "-";
	}
}


BBoard::BBoard()
: title(""),
  current_user(0)
{}

BBoard::BBoard(const string &ttl)
: title(ttl),
  current_user(0)
{}

BBoard::~BBoard()
{
	for(unsigned i = 0; i < message_list.size(); i++)
		delete message_list.at(i);
}

bool BBoard::load_users(const string &userfile)
{

	string username, password;
	ifstream userShit;
	userShit.open(userfile.c_str());

	if(!userShit.is_open())
		return false;

	else
	{
		while(true)
		{
			userShit >> username;
			if(username == "end")
				break;

			else
			{
				userShit >> password;
				add_user(username, password);
			}
		}
		userShit.close();
		return true;
	}
}

bool BBoard::load_messages(const string& datafile)
{
	struct msg
	{
		public:
			string author;
			string subject;
			string body;
			bool isReply;
			unsigned id;
			vector<unsigned> children;
	};

	unsigned numMessages = 0;
	string line;

	ifstream fuckingMessages;
	fuckingMessages.open(datafile.c_str());

	if(!fuckingMessages.is_open())
	{
		fuckingMessages.close();
		return false;
	}

	fuckingMessages >> numMessages;
	msg * shittyMessage = new msg[numMessages];

	fuckingMessages >> line;
	for(unsigned i = 0; i < numMessages; i++)
	{
		if(line == "<begin_topic>")
		{
			shittyMessage[i].isReply = false;
		}

		else
		{
			shittyMessage[i].isReply = true;
		}

		while(line != "<end>")
		{
			fuckingMessages >> line;
			
			if(line == ":id:")
			{
				fuckingMessages >> shittyMessage[i].id;
			}

			else if(line == ":subject:")
			{
				getline(fuckingMessages, shittyMessage[i].subject);
				shittyMessage[i].subject = shittyMessage[i].subject.substr(1);
			}

			else if(line == ":from:")
			{
				fuckingMessages >> shittyMessage[i].author;
				
			}

			else if(line == ":children:")
			{
				string childLine;
				int temp;

				getline(fuckingMessages, childLine);
				childLine = childLine.substr(1);
				stringstream ss(childLine);

				while(ss >> temp)
					shittyMessage[i].children.push_back(temp);
			}

			else if(line == ":body:")
			{
				getline(fuckingMessages, line);
				line = line.substr(1);
				while(line != "<end>")
				{
					shittyMessage[i].body += (line + "\n");
					getline(fuckingMessages, line);
				}
			}
		}
		fuckingMessages >> line;

		

		string athr = shittyMessage[i].author;
		string sbj = shittyMessage[i].subject;
		string bdy = shittyMessage[i].body;
		unsigned id = shittyMessage[i].id;

		if(shittyMessage[i].isReply)
		{
			message_list.push_back(new Reply(athr, sbj, bdy, id));
		}

		else
		{
			message_list.push_back(new Topic(athr, sbj, bdy, id));
		}
	}

	for(unsigned i = 0; i < numMessages; i++)
	{
		unsigned numChildren;
		if((numChildren = shittyMessage[i].children.size()) != 0)
		{
			for(unsigned child = 0; child < numChildren; child++)
			{
				unsigned child_index = shittyMessage[i].children.at(child) - 1;
				Message * child_message = message_list.at(child_index);
				message_list.at(i)->add_child(child_message);
			}
		}
	}

	fuckingMessages.close();
	delete[] shittyMessage;
	return true;
}


bool BBoard::save_messages(const string& datafile)
{
	ofstream cunt;
	cunt.open(datafile.c_str());

	if(!cunt.is_open())
	{
		return false;
	}

	cunt << message_list.size() << endl;
	for(unsigned i = 0; i < message_list.size(); i++)
	{
		string frmt = message_list.at(i)->to_formatted_string();
		if((i + 1) == message_list.size())
			frmt = frmt.substr(0, frmt.length() - 1);

		cunt << frmt;
	}

	cunt.close();
	return true;
}


void BBoard::login()
{
	string username, password;
	cout << endl << "Welcome to " << title << endl;
	while (true)
	{
		cout << "Enter your username (\'Q\' or \'q\' to quit): ";
		cin >> username;
		if(username == "Q" || username == "q")
		{
			cout << "Bye!";
			return;
		}
		cout << "Enter your password: ";
		cin  >> password;

		const User * person = get_user(username, password);

		if(person == 0)
			cout << "Invalid username or Password!" << endl << endl;
		else
		{
			current_user = person;
			cout << endl << "Welcome back " << current_user->get_username();
			cout << "!" << endl << endl;
			return;
		}

	}
}

void BBoard::run()
{
	char userInput;
	
	for(unsigned i = 0; i < user_list.size(); i++)
	{
		if(current_user == &user_list.at(i))
		{
			break;
		}
		else
			return;
	}

	while(true)
	{
		cout << "Menu" << endl;
		cout << "\t- Display Messages (\'D\' or \'d\')" << endl;
		cout << "\t- Add New Topic (\'N\' or \'n\')"  << endl;
		cout << "\t- Add New Reply (\'R\' or \'r\')" << endl;
		cout << "\t- Quit (\'Q\' or \'q\')"	        << endl;
		cout << "Choose an action: ";
		cin  >> userInput;
		if(userInput == 'd' || userInput == 'D')
		{
			cout << endl;
			display();
			printDashes();
			cout << endl << endl;
		}
		else if(userInput == 'N' || userInput == 'n')
		{
			cout << endl;
			add_topic();
		}
		else if(userInput == 'R' || userInput == 'r')
		{
			cout << endl;
			add_reply();
		}
		else if(userInput == 'q' || userInput == 'Q')
		{
			cout << "Bye!" << endl;
			return;
		}
	}
	
}

void BBoard::add_user(const string &name, const string &pass)
{
	User *person = new User(name, pass);
	user_list.push_back(*person);
}

const User * BBoard::get_user(const string &name, const string &pw) const
{
	int i = -1;
	while((unsigned) ++i < user_list.size() && !user_list.at(i).check(name, pw));

	if((unsigned) i == user_list.size())
		return 0;

	else
		return &user_list.at(i);
}

void BBoard::display() const
{
	for(unsigned i = 0; i < message_list.size(); i++)
	{ 
		if(!(message_list.at(i)->is_reply()))
		{
			printDashes();
			cout << endl;
			message_list.at(i)->print(0);
		}
	}
}

void BBoard::add_topic()
{
	cin.clear();
	fflush(stdin);
	string sbjct, body, line, athr = current_user->get_username();
	cout << "Subject: ";
	getline(cin, sbjct);
	cout << "\nBody: ";
	while(true)
	{
		getline(cin, line);
		if(line.empty())
			break;
		else
		{
			body += line;
			body += "\n";
		}
	}

	Topic * pTopic = new Topic(athr, sbjct, body, message_list.size() + 1);
	message_list.push_back(pTopic);	
}

void BBoard::add_reply()
{
	cin.clear();
	fflush(stdin);
	int id;
	string body, line, sbjct, athr = current_user->get_username();
	do
	{
		cout << "Enter Message ID (-1 for Menu): ";
		cin  >> id;

		if(id < 0)
			return;
		else if((unsigned) id == 0 || (unsigned) id > message_list.size())
			cout << "Invalid Message ID!!" << endl;

	} while((unsigned) id > message_list.size() || id == 0);

	cin.clear();
	fflush(stdin);

	Message *parent = message_list.at(id - 1);

	sbjct = "Re: " + message_list.at(id - 1)->get_subject();

	cout << "Body: ";
	while(true)
	{
		getline(cin, line);
		if(line.empty())
			break;
		else
		{
			body += line;
			body += "\n";
		}
	}

	Reply * pTopic = new Reply(athr, sbjct, body, message_list.size() + 1);
	message_list.push_back(pTopic);
	parent->add_child(pTopic);

}
