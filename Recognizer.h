#include <thread>
#include <iostream>

#include "RecognizerModel.h"
#include "person.h"

#ifndef __RECOGNIZER_H__
#define __RECOGNIZER_H__

class Recognizer 
{
	public:
		Recognizer();
		~Recognizer();

		void queue_retrain(Person new_person);
		Person identify_person(Person info);
		int get_latest_model();

	private:
		unique_ptr<RecognizerModel> m_model;
		shared_ptr<thread> training_thread;
};
#endif