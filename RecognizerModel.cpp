#include "RecognizerModel.h"

RecognizerModel::RecognizerModel() {}
RecognizerModel::~RecognizerModel(){}

void RecognizerModel::train_with_latest_data() {
	Person new_person;
	while(1) {
		if (!retrain_queue.empty()){
			cout << "will start train_with_latest_data" << endl;
			new_person = retrain_queue.front();
			retrain_queue.pop();
			if (data.size() == 0) {
				latest_model = new_person.recog_data;
			} else {	// train new_set (aka calculate new average);
				latest_model *= data.size(); 
				latest_model += new_person.recog_data;
				latest_model = latest_model/data.size() + 1;
			}
			sleep(2); //assuming training takes 2 seconds
			data.push_back(new_person); // for future record	
		}
	}
}

Person RecognizerModel::identify_person(Person info) {
	for(std::vector<Person>::iterator it = data.begin(); it != data.end(); ++it) 
	    if (info.recog_data == it->recog_data) 
	    	return *it;
	return {0,info.recog_data}; // dumpy person Id
}