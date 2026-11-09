#pragma once
#include"TodoItem.hpp"
#include<string>
#include<vector>

class TodoManager {
private:
	std::vector<TodoItem> items;
	int nextId = 1;
public:
	TodoManager();
	bool add(const std::string& con);
	int find(int id);
	bool markFinished(int id);
	bool remove(int id);
	void show();
	void loadFromFile(const std::string path);
	void saveToFile(const std::string path);
	friend std::ostream& operator<<(std::ostream& os, const TodoItem& t);
};