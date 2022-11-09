#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

int main() {
    shared_ptr<string> pJack(new string("jack"),
                             [](string *p) {
                                 cout << "Deleting " << *p << endl;
                                 delete p;
                             });
    {
        shared_ptr<string> pKate(new string("kate"),
                                 [](string *p) {
                                     cout << "Deleting " << *p << endl;
                                     delete p;
                                 });
        cout << *pJack << endl;
        cout << *pKate << endl;
        cout << "use_count(): " << pJack.use_count() << endl;
        cout << "use_count(): " << pKate.use_count() << endl;
        {
            vector<shared_ptr<string>> v;
            v.push_back(pKate);
            v.push_back(pKate);
            v.push_back(pJack);
            v.push_back(pJack);
            v.push_back(pKate);
            v.push_back(pJack);
            cout << "for loop:" << endl;
            for (auto &p: v) {
                cout << *p << endl;
            }
            cout << "use_count(): " << pJack.use_count() << endl;
            cout << "use_count(): " << pKate.use_count() << endl;
            v.resize(3);
            cout << "use_count(): " << pJack.use_count() << endl;
            cout << "use_count(): " << pKate.use_count() << endl;
        }
        cout << "use_count(): " << pJack.use_count() << endl;
        cout << "use_count(): " << pKate.use_count() << endl;
    }

}