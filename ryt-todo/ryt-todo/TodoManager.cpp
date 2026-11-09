#include"TodoManager.hpp"
#include"TodoItem.hpp"
#include<vector>
#include<iostream>
#include<fstream>
#include<sstream>

TodoManager::TodoManager() {
	loadFromFile("todo.txt");
}

bool TodoManager::add(const std::string& con) {
	TodoItem newitem;
	newitem.content = con;
	newitem.id = nextId++;
	items.push_back(newitem);
	saveToFile("todo.txt");
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
	saveToFile("todo.txt");
	return true;
}

bool TodoManager::remove(int id) {
	int found = find(id);
	if (found == -1) { return false; }
	items.erase(items.begin() + found);
	saveToFile("todo.txt");
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

std::ostream& operator<<(std::ostream& os, const TodoItem& t) {
	os << t.id << "|" << t.content << "|" << t.is_finished;
	return os;
}

void TodoManager::loadFromFile(const std::string path) {
	std::ifstream ifs(path);
	if (!ifs) {
		std::cerr << "打开文件失败" << std::endl;
		return;
	}
	std::string line;
	while (std::getline(ifs, line)) {
		if (line.empty()) { continue; }
		std::stringstream ss(line);
		std::string idStr, content, finStr;
		std::getline(ss, idStr, '|');
		std::getline(ss, content, '|');
		std::getline(ss, finStr, '|');

		int id = std::stoi(idStr);
		items.push_back(TodoItem(id, content, finStr == "1"));
		if (id >= nextId) nextId = id + 1;
	}
}

void TodoManager::saveToFile(const std::string path) {
	std::ofstream ofs(path, std::ios::out);
	if (!ofs) {
		std::cerr << "保存文件失败" << std::endl;
		return;
	}
	for (auto& item : items) {
		ofs << item << std::endl;
	}
}