#pragma once
#include"TodoItem.hpp"
#include<string>
#include<vector>

class TodoManager {
private:
	std::vector<TodoItem> items;
	int nextId = 1;
public:
	bool add(const std::string& con);
	int find(int id);
	bool markFinished(int id);
	bool remove(int id);
	void show();
};