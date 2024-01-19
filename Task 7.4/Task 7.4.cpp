#include <iostream>
#include <string>

using namespace std;

class Task
{
private:
    string first;
    string second;
public:
    Task() : Task("abracadabra", "ab") {}
    Task(string first, string second)
    {
        set_first(first);
        set_second(second);
    }
    void set_first(string first) { this->first = { first }; }
    void set_second(string second) { this->second = { second }; }
    string get_first() { return first; }
    string get_second() { return second; }
    void do_magic()
    {
        string temp = second;
        temp.insert(temp.begin(), '(');
        temp.push_back(')');
        int index = 0;
        while ((index = first.find(second, index)) != string::npos)
        {
            first.replace(index, second.length(), temp);
            index += temp.length();
        }
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    Task task;
    cout << task.get_first() << "\t" << task.get_second() << endl;
    task.do_magic();
    cout << task.get_first() << "\t" << task.get_second() << endl;

    return 0;
}
