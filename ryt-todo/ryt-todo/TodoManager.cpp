#include"TodoManager.hpp"
#include"TodoItem.hpp"
#include<vector>
#include<iostream>

bool TodoManager::add(const std::string& con) {
	TodoItem newitem;
	newitem.content = con;
	newitem.id = nextId++;
	items.push_back(newitem);
	return true;
}

int TodoManager::find(int id) {
	for (int i = 0; i < items.size(); ++i) {
		if (items[i].id == id) {
			return i;
		}
	}
	return -1;
}

bool TodoManager::markFinished(int id) {
	int found = find(id);
	if (found == -1) { return false; }
	items[found].is_finished = true;
	return true;
}

bool TodoManager::remove(int id) {
	int found = find(id);
	if (found == -1) { return false; }
	items.erase(items.begin() + found);
	return true;
}

void TodoManager::show() {
	for (int i = 0; i < items.size(); ++i) {
		std::cout << items[i].id << "." << items[i].content << "：";
		if (items[i].is_finished) {
			std::cout << "已完成" << std::endl;
		}
		else {
			std::cout << "待完成" << std::endl;
		}
	}
}