#include "Music_collection.h"
#include <string>

using namespace std;

int main()
{
	Tune t1("Mona Lisas and Mad Hatters");
	Tune t2("The Arrow Killed the Beast");
	Tune t3("Only for You");
	Tune t4("Valerie");

	Music_collection m1;

	m1.add_tune(t1);
	m1.add_tune(t2);
	m1.add_tune(t3);

	m1.set_tune(1, t4);

	Music_collection b(m1);

	m1.add_tune(t2);

	cout << m1 << endl << b << endl;

}
