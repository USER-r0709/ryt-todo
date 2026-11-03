#pragma once
#include<string>

struct TodoItem{
	int id; //用id查找
	std::string content;
	bool is_finished = false;

	TodoItem() = default;
	TodoItem(int id_, const std::string& c, bool f = false)
		:id(id_), content(c), is_finished(f) {
	}
	TodoItem(const TodoItem& other) = default;
	~TodoItem() = default;
};