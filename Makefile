all:
	g++ my_test.cpp -lboost_thread -lboost_system -lpthread -std=c++11 -o my_test
