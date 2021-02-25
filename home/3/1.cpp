#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>
using namespace std;

class Contact {
    string name;
    int prefix;
    int number;
    int calls;
public:
    Contact();
    void setContact(const string &name_, int prefix_, int number_);
    bool nameLike(const string &partOfName);
    bool numberLike(int numberSuffix);
    int getCalls(int calls);
    void newCall();
    void print();
    friend class PhoneBook;
};

Contact::Contact() {
    prefix = 0;
    number = 0;
    calls = 0;
    name = " ";
}

 void Contact::setContact(const string &name_, int prefix_, int number_) {
    name = name_;
    prefix = prefix_;
    number = number_;
 }

 bool Contact::nameLike(const string &partOfName) {
    
    const char *s1 = partOfName.c_str();
    string s2 = name.substr(0, strlen(s1));
    cout << name << endl;
    const char *s3 = s2.c_str();
    if(strcmp(s1, s3) == 0) {
        return 1;
    } else {
        return 0;
    }
 }
int Contact::getCalls(int calls) {
    return calls;
}

void Contact::newCall() {  
    calls++;
}

class PhoneBook {
    int abonentNumber;
    Contact names[10];
    void printHeader();
public:
    PhoneBook();
    void addAbonent(const string &name, int pref, int number);
    bool callAbonent(const string & prefixOfName);
    bool callAbonent(int suffixOfNumber);
    void print();
    void printTheMostCommon();
    friend class Contact;
    void printinfo(int counter, int index[]);
};
PhoneBook::PhoneBook() {
    abonentNumber = 0;
}
void PhoneBook::printHeader() {
    cout << std::setw(11) << "name" << std::setw(5) << "pref" << std::setw(8) <<
    "number" << std::setw(10) << "calls" << endl;
}
void PhoneBook::printinfo(int counter, int index[]) {
    if(counter != 0) {
        for(int i = 0; i < counter; ++i) {
                cout << std::setw(11) << names[index[i]].name 
                << std::setw(4)<< names[index[i]].prefix
                << std::setw(10) << names[index[i]].number <<
                std::setw(9) << names[index[i]].calls << endl;
            }
    } else {
        cout << std::setw(11) << names[index[0]].name 
        << std::setw(4)<< names[index[0]].prefix
        << std::setw(10) << names[index[0]].number <<
        std::setw(9) << names[index[0]].calls << endl;
    }
}
void PhoneBook::addAbonent(const string &name, int pref, int number) {
    const char *s1 = name.c_str();
    string str2 = to_string(number);
    const char *s2 = str2.c_str();
    if(strlen(s1) > 10 && strlen(s2) > 9 && abonentNumber > 9) {
        cout << "FAIL: incorrect name or number format" << endl;
    } else {
        names[abonentNumber].name = name;
        names[abonentNumber].number = number;
        names[abonentNumber].prefix = pref;
        cout << "ADD: " << names[abonentNumber].name << " " << names[abonentNumber].prefix <<
        "-" << names[abonentNumber].number << endl;
        abonentNumber++;
    }
}
bool PhoneBook::callAbonent(const string &prefixOfName) {
    const char *s1 = prefixOfName.c_str();
    string name[10];
    const char *name_[10];
    int matchedIndex[10];
    int nameCounter = 0, nameCounter1 = 0;
    for(int i = 0; i < abonentNumber; ++i) {
        name[i] = names[i].name.substr(0, strlen(s1));
        name_[i] = name[i].c_str();
        if(strcmp(s1, name_[i]) == 0) {
            matchedIndex[nameCounter] = i;
            nameCounter++;
        } 
    }
    printHeader();
    if(nameCounter == 1) {
        printinfo(0, matchedIndex);
        names[matchedIndex[0]].newCall();
        cout << "CALL" << endl;
        return 1;
    }
    if(nameCounter > 1) {
        printinfo(nameCounter, matchedIndex);
        cout << "FAIL: choose unique" << endl;
        return 0;
    }
    if(nameCounter == 0) {
        cout << "No such abonent";
        return 0;
    }
}
void PhoneBook::printTheMostCommon() {
    int maximum = 0;
    int matchedIndex[10];
    int counter = 0;
    maximum = names[0].calls;
    for(int i = 0; i < abonentNumber; ++i) {
        if(names[i].calls > maximum) {
            maximum = names[i].calls;
        }  
    }
    printHeader();
    for(int i = 0; i < abonentNumber; ++i) {
        if(names[i].calls == maximum) {
            matchedIndex[counter] = i;
            counter++;
        }
    }
    printinfo(counter, matchedIndex);
}
bool PhoneBook::callAbonent(int suffixOfNumber) {
    int number = 0, numbers = 0, counter = 0;
    int matchedIndex[10];
    bool okay;
    for(int i = 0; i < abonentNumber; ++i) {
        number = suffixOfNumber;
        numbers = names[i].number; 
        okay = true;
        while(number != 0 && numbers != 0) {  
            if((numbers % 10) != (number % 10)) {
                okay = false;
                break;
            } 
            number /= 10;
            numbers /= 10;
        }
        if(okay == true) {
            matchedIndex[counter] = i;
            counter++;
        } 
    }
    printHeader();
    if(counter == 1) {
        printinfo(0, matchedIndex);
        names[matchedIndex[0]].newCall();
        cout << "CALL" << endl;
        return 1;
    }
    if(counter > 1) {
        printinfo(counter, matchedIndex);
        cout << "FAIL: choose unique" << endl;
        return 0;
    }
    if(counter == 0) {
        cout << "FAIL: No such abonent" << endl;
        return 0;
    }
}
void PhoneBook::print() {
    printHeader();
    for(int i = 0; i < abonentNumber; ++i) {
        cout << std::setw(11) << names[i].name << std::setw(4)<< names[i].prefix
         << std::setw(10) << names[i].number << std::setw(9) << names[i].calls << endl;
    }  
}
 int main() {
    Contact A;
    PhoneBook B;
    char command;
    string name;
    int num = 0;
    int number, prefix;
    cin >> command;
    do {
        if(command == '+') {
            int nameCounter = 0;
            cin >> name >> prefix >> number;
            A.setContact(name, prefix, number);
            B.addAbonent(name, prefix, number);
        }
        if(command == '#') {
            cin >> num;
            if(num == 1) {
                cin >> name;
                B.callAbonent(name);
            }
            if(num == 2) {
                cin >> number;
                B.callAbonent(number);
            }
        }
        if(command == '?') {
            B.print();
        }
        if(command == '*') {
            B.printTheMostCommon();
        }
        command = ' ';
        cin >> command;
    } while(command != '.');
    return 0;
 }
 /*
+ Eva 705 6462464
+ Alexey 926 1434947
+ Alexander 705 1439947
 */