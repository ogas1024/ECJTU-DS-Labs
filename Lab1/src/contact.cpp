#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Contact
{
private:
    string name;
    string number;

public:
    Contact() {}
    Contact(string name, string phonenumber) : name(name), number(phonenumber) {}
    string getName() const { return name; }
    void setName(string name) { this->name = name; }
    string getPhonenumber() const { return number; }
    void setPhonenumber(string phonenumber) { this->number = phonenumber; }
};

class Telephone
{
public:
    static void main()
    {
        vector<Contact> list;
        while (true)
        {
            cout << "欢迎使用手机通讯录！" << endl;
            cout << "1.创建" << endl;
            cout << "2.插入" << endl;
            cout << "3.删除" << endl;
            cout << "4.显示" << endl;
            cout << "5.查找" << endl;
            cout << "6.求人数" << endl;
            cout << "7.退出应用" << endl;
            cout << "请输入您的选择：" << endl;
            int choose;
            cin >> choose;
            switch (choose)
            {
            case 1:
                create(list);
                break;
            case 2:
                insert(list);
                break;
            case 3:
                deleteContact(list);
                break;
            case 4:
                show(list);
                break;
            case 5:
                search(list);
                break;
            case 6:
                headcount(list);
                break;
            case 7:
                exit(0);
            default:
                cout << "输入了无效的选择哦，请重新输入：" << endl;
                break;
            }
            system("pause");
            system("cls");
        }
    }
    static void create(vector<Contact> &list)
    {
        Contact con;
        cout << "请输入要创建的联系人的名字" << endl;
        string createname;
        cin >> createname;
        cout << "请输入要创建的联系人的电话" << endl;
        string createnum;
        cin >> createnum;
        if (checkout(list, createname, createnum))
        {
            cout << "已存在相同的联系人和电话，请勿重复创建" << endl;
        }
        else
        {
            con.setName(createname);
            con.setPhonenumber(createnum);
            list.push_back(con);
            cout << "新的联系人创建成功！" << endl;
            cout << "当前通讯录内如下：" << endl;
            show(list);
        }
    }
    static void insert(vector<Contact> &list)
    {
        Contact con;
        cout << "请输入要插入的新联系人的名字" << endl;
        string insertname;
        cin >> insertname;
        cout << "请输入要插入的新联系人的电话" << endl;
        string insertenum;
        cin >> insertenum;
        if (checkout(list, insertname, insertenum))
        {
            cout << "已存在相同的联系人和电话" << endl;
            return;
        }
        con.setName(insertname);
        con.setPhonenumber(insertenum);
        cout << "请输入要插入的序号" << endl;
        int order;
        while (true)
        {
            cout << "请输入要插入的序号" << endl;
            cin >> order;
            if (order > list.size() + 1 || order < 1)
            {
                cout << "输入错误，请输入一个有效的序号：" << endl;
                continue;
            }
            break;
        }
        list.insert(list.begin() + order - 1, con);
        cout << "插入成功！" << endl;
        cout << "当前通讯录内如下：" << endl;
        show(list);
    }
    static void deleteContact(vector<Contact> &list)
    {
        if (list.empty())
        {
            cout << "联系人为空，无法删除" << endl;
        }
        else
        {
            cout << "当前通讯录内如下：" << endl;
            show(list);
            cout << "请输入要删除的联系人的名字" << endl;
            string deletename;
            cin >> deletename;
            int index = getIndex(list, deletename);
            if (index == -1)
            {
                cout << "该联系人不存在，无法删除" << endl;
            }
            else
            {
                list.erase(list.begin() + index);
                cout << "名字为" << deletename << "的联系人删除成功！" << endl;
            }
            cout << "当前通讯录内如下：" << endl;
            show(list);
        }
    }
    static void show(const vector<Contact> &list)
    {
        if (list.empty())
        {
            cout << "当前暂无联系人，请添加后再显示联系人列表" << endl;
            return;
        }
        else
        {
            cout << "序号" << "\t" << "联系人" << "\t" << "电话号码" << endl;
            for (int i = 0; i < list.size(); i++)
            {
                cout << i + 1 << "\t" << list[i].getName() << "\t" << list[i].getPhonenumber() << endl;
            }
        }
    }
    static void search(const vector<Contact> &list)
    {
        while (true)
        {
            cout << "请选择查找方式：" << endl;
            cout << "1.通过联系人名字查找" << endl;
            cout << "2.通过联系人电话查找" << endl;
            cout << "请输入您的选择：" << endl;
            int input;
            cin >> input;
            switch (input)
            {
            case 1:
                searchName(list);
                break;
            case 2:
                searchNumber(list);
                break;
            default:
            {
                cout << "没有该选择哦，请重新输入" << endl;
                continue;
            }
            }
            break;
        }
    }
    static void headcount(const vector<Contact> &list)
    {
        cout << "通讯录中一共有" << list.size() << "人" << endl;
    }

    static bool checkout(const vector<Contact> &list, const string &newname, const string &newnum)
    {
        for (const auto &contact : list)
        {
            if (contact.getName() == newname && contact.getPhonenumber() == newnum)
            {
                return true;
            }
        }
        return false;
    }
    static bool searchName(const vector<Contact> &list)
    {
        cout << "请输入您要查找的名字" << endl;
        string needname;
        cin >> needname;
        for (const auto &contact : list)
        {
            if (contact.getName() == needname)
            {
                cout << "查找成功" << endl;
                cout << contact.getName() << "\t" << contact.getPhonenumber() << endl;
                return true;
            }
        }
        cout << "通讯录中暂无该联系人" << endl;
        return false;
    }
    static bool searchNumber(const vector<Contact> &list)
    {
        cout << "请输入您要查找的号码" << endl;
        string neednum;
        cin >> neednum;
        for (const auto &contact : list)
        {
            if (contact.getPhonenumber() == neednum)
            {
                cout << "查找成功" << endl;
                cout << contact.getName() << "\t" << contact.getPhonenumber() << endl;
                return true;
            }
        }
        cout << "通讯录中暂无该电话" << endl;
        return false;
    }
    static int getIndex(const vector<Contact> &list, const string &name)
    {
        for (int i = 0; i < list.size(); i++)
        {
            if (list[i].getName() == name)
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    Telephone::main();
    return 0;
}
