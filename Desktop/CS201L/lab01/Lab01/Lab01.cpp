// Alexander Arbuckle
// ala2q6@mail.umkc.edu
// 8/20/19
// CS201L Lab 01

#include <iostream>
using namespace std;

int main() {

	float distance, time, velocity;

	cout << "Enter how many miles you are traveling " << endl;
	cin >> distance;

	cout << "How fast are you traveling in mph? " << endl;
	cin >> velocity;

	time = distance / velocity;

	cout << endl << "At " << velocity << " mph it will take " << time << " hours to travel " << distance << " miles." << endl;
	
	return 0;

}