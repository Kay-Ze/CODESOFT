#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void Banner() {
    cout << "\t==================================" << endl;
    cout << "\t\tMY TODO LIST" << endl;
    cout << "\t==================================" << endl;
}

void Display();
void Update();
void deleteTask();
void add();
int searchTask();

struct toDoList {
    int id;
    string task;
};

int ID = 0;

void initializeID() {
    toDoList todo;
    ifstream fin("todo.txt");
    while (fin >> todo.id) {
        fin.ignore();
        getline(fin, todo.task);
        if (todo.id > ID) {
            ID = todo.id;
        }
    }
    fin.close();
}

int main() {
    cout << "\t=========>> WELCOME <<=========\n" << endl;
    cout << "\t*To Do List For Your Daily Tasks*" << endl;

    initializeID();

    bool loop = true;

    while (loop) {
        cout << "\t Select The Task You Want To Perform:-" << endl;
        cout << "\t\t1.) Add Task" << endl;
        cout << "\t\t2.) Delete Task" << endl;
        cout << "\t\t3.) Update Task" << endl;
        cout << "\t\t4.) Display Tasks" << endl;
        cout << "\t\t5.) Exit" << endl;
        cout << "\n\tEnter Your Choice (1-5): ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            add();
            break;
        case 2:
            deleteTask();
            break;
        case 3:
            Update();
            break;
        case 4:
            Display();
            break;
        case 5:
            loop = false;
            break;
        default:
            cout << "\n\tInvalid Choice. Please Try Again." << endl;
            break;
        }
    }

    cout << "\n\tThank You For Using Our To Do List Program. Goodbye!" << endl;
    return 0;
}

void add() {
    Banner();
    toDoList newTask;
    cout << "\n\tEnter New Task ::  ";
    cin.ignore();
    getline(cin, newTask.task);
    char save;
    cout << "\n *Do You Want To Save (y/n) : ";
    cin >> save;
    if (save == 'y') {
        ID++;
        ofstream fout("todo.txt", ios::app);
        fout << ID << "\n" << newTask.task << endl;
        fout.close();
        cout << "\n\tAdded Successfully....." << endl;
    }
}

void Display() {
    Banner();
    toDoList todo;
    ifstream fin("todo.txt");
    bool empty = true;
    while (fin >> todo.id) {
        fin.ignore();
        getline(fin, todo.task);
        if (!todo.task.empty()) {
            cout << "\t" << todo.id << ". " << todo.task << endl;
            empty = false;
        }
    }
    fin.close();
    if (empty) {
        cout << "\n\t >> E M P T Y <<" << endl;
    }
}

int searchTask() {
    int id;
    cout << "\n\tEnter Task ID: ";
    cin >> id;
    toDoList todo;
    ifstream fin("todo.txt");
    while (fin >> todo.id) {
        fin.ignore();
        getline(fin, todo.task);
        if (todo.id == id) {
            cout << "\t" << todo.id << ": " << todo.task << endl;
            return id;
        }
    }
    fin.close();
    cout << "\n\tNot Found..." << endl;
    return 0;
}

void deleteTask() {
    int id = searchTask();
    if (id != 0) {
        char del;
        cout << "\t\tDelete(y/n) : ";
        cin >> del;
        if (del == 'y') {
            toDoList todo;
            ofstream tempfile("temp.txt");
            ifstream fin("todo.txt");
            while (fin >> todo.id) {
                fin.ignore();
                getline(fin, todo.task);
                if (todo.id != id) {
                    tempfile << todo.id << "\n" << todo.task << endl;
                }
            }
            fin.close();
            tempfile.close();
            remove("todo.txt");
            rename("temp.txt", "todo.txt");
            cout << "\n\tDeleted Successfully....." << endl;
        }
    }
}

void Update() {
    int id = searchTask();
    if (id != 0) {
        char update;
        cout << "\t\tUpdate(y/n) : ";
        cin >> update;
        if (update == 'y') {
            toDoList todo;
            ofstream tempfile("temp.txt");
            ifstream fin("todo.txt");
            while (fin >> todo.id) {
                fin.ignore();
                getline(fin, todo.task);
                if (todo.id == id) {
                    cout << "\tEnter New Task: ";
                    cin.ignore();
                    getline(cin, todo.task);
                }
                tempfile << todo.id << "\n" << todo.task << endl;
            }
            fin.close();
            tempfile.close();
            remove("todo.txt");
            rename("temp.txt", "todo.txt");
            cout << "\n\tUpdated Successfully....." << endl;
        }
    }
}
