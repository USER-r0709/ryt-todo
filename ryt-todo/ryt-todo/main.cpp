#include"TodoManager.hpp"
#include"TodoItem.hpp"
#include<vector>
#include<string>
#include<iostream>
using namespace std;

int main() {
	TodoManager list;
	bool out = false;
	while (!out) {
		cout << "————————菜单栏————————" << endl;
		cout << "a.添加待办" << "\n"
			<< "b.标记完成" << "\n"
			<< "c.删除待办" << "\n"
			<< "d.展示全部待办" << "\n"
			<< "e.退出" << "\n" 
			<< "————————————————————";
		cout << endl;
		cout << "请输入选项前的字母" << " ";
		string choice;
		cin >> choice;
		if (choice == "a") {
			cout << "请输入待办事项：" << endl;
			string con;
			cin.ignore();
			getline(cin, con);
			list.add(con);
			cout << endl;
			list.show();
		}
		else if (choice == "b") {
			cout << "请输入准备标记完成的待办事项前数字编号：";
			int id;
			cin >> id;
			if (list.find(id) != -1) {
				list.markFinished(id);
			}
			else {
				cout << "不存在此待办项" << endl;
			}
		}
		else if (choice == "c") {
			cout << "请输入准备删除的待办事项前数字编号：";
			int id;
			cin >> id;
			if (list.find(id) != -1) {
				list.remove(id);
			}
			else {
				cout << "不存在此待办项" << endl;
			}
		}
		else if (choice == "d") {
			cout << endl;
			list.show();
		}
		else if (choice == "e") {
			out = true;
		}
		else {
			cout << "无效输入，请重试！";
		}
		cout << "\n" << endl;
	}
	return 0;
}