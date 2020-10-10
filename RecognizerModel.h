#include <unistd.h>
#include <vector> 
#include <queue>
#include <iostream>
#include <semaphore.h> 

#include "person.h"

using namespace std;

#ifndef __RECOGNIZERMODEL_H__
#define __RECOGNIZERMODEL_H__

class RecognizerModel 
{
	public:
		RecognizerModel();
		~RecognizerModel();

		void train_with_latest_data();
		Person identify_person(Person info);

		vector<Person> data;
		queue<Person> retrain_queue;

		// consider existing model as an average of already trained persons  
		int latest_model; 
};

#endif