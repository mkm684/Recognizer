#include <time.h>
#include <unistd.h>
#include <thread>
#include <cstdlib>
#include <iostream>
#include <mutex>

#include "Recognizer.h"
#include "person.h"

using namespace std;

void camera_thread(int camera_num);

Recognizer *engine = new Recognizer();
int latest_id = 0; 
mutex id_lock;

int main()
{
	thread camera1(camera_thread, 1);
	thread camera2(camera_thread, 2);
	thread camera3(camera_thread, 3);
 		
 	camera1.join();
 	camera2.join();
 	camera3.join();

 	cout << "latest_mode (aka average) : " 
 			<< engine->get_latest_model() << endl;
 	free(engine);
}
	
void camera_thread(int camera_num)
{	 
	Person new_person = {0,0};
	/* (for testing purposes) given data can only == 1-10,
		 we can train for 10 times max 
	*/
	for (int i = 0; i < 10; i++) 
	{
		cout << "- Person detected at " << camera_num << endl;		
		// generate random number 1-10 to simulate recongiation data
		new_person.recog_data= (rand() % 10) + 1;
		new_person = engine->identify_person(new_person);

		if (new_person.Id != 0) {
			cout << "	Person is found on DB " << endl ; 
		} else {
			cout << "	Person not found (retrains) " << endl ; 
			id_lock.lock();
			new_person.Id = ++latest_id;
			engine->queue_retrain(new_person);
			id_lock.unlock();
		}
		sleep(4); // assume a new person come every 4 seconds.
	}
}