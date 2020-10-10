#include "Recognizer.h"

Recognizer::Recognizer() {
	m_model = make_unique<RecognizerModel>();
	training_thread = make_shared<thread>(&RecognizerModel::train_with_latest_data, m_model.get()); 
}

Recognizer::~Recognizer() {
	training_thread->join();
	m_model.release();
}

void Recognizer::queue_retrain(Person new_person) {
	m_model->retrain_queue.push(new_person);
}

Person Recognizer::identify_person(Person info) {
	return m_model->identify_person(info);
}

int Recognizer::get_latest_model() {
	return m_model->latest_model;
}
