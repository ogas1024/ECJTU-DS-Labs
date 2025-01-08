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
            cout << "��ӭʹ���ֻ�ͨѶ¼��" << endl;
            cout << "1.����" << endl;
            cout << "2.����" << endl;
            cout << "3.ɾ��" << endl;
            cout << "4.��ʾ" << endl;
            cout << "5.����" << endl;
            cout << "6.������" << endl;
            cout << "7.�˳�Ӧ��" << endl;
            cout << "����������ѡ��" << endl;
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
                cout << "��������Ч��ѡ��Ŷ�����������룺" << endl;
                break;
            }
            system("pause");
            system("cls");
        }
    }
    static void create(vector<Contact> &list)
    {
        Contact con;
        cout << "������Ҫ��������ϵ�˵�����" << endl;
        string createname;
        cin >> createname;
        cout << "������Ҫ��������ϵ�˵ĵ绰" << endl;
        string createnum;
        cin >> createnum;
        if (checkout(list, createname, createnum))
        {
            cout << "�Ѵ�����ͬ����ϵ�˺͵绰�������ظ�����" << endl;
        }
        else
        {
            con.setName(createname);
            con.setPhonenumber(createnum);
            list.push_back(con);
            cout << "�µ���ϵ�˴����ɹ���" << endl;
            cout << "��ǰͨѶ¼�����£�" << endl;
            show(list);
        }
    }
    static void insert(vector<Contact> &list)
    {
        Contact con;
        cout << "������Ҫ���������ϵ�˵�����" << endl;
        string insertname;
        cin >> insertname;
        cout << "������Ҫ���������ϵ�˵ĵ绰" << endl;
        string insertenum;
        cin >> insertenum;
        if (checkout(list, insertname, insertenum))
        {
            cout << "�Ѵ�����ͬ����ϵ�˺͵绰" << endl;
            return;
        }
        con.setName(insertname);
        con.setPhonenumber(insertenum);
        cout << "������Ҫ��������" << endl;
        int order;
        while (true)
        {
            cout << "������Ҫ��������" << endl;
            cin >> order;
            if (order > list.size() + 1 || order < 1)
            {
                cout << "�������������һ����Ч����ţ�" << endl;
                continue;
            }
            break;
        }
        list.insert(list.begin() + order - 1, con);
        cout << "����ɹ���" << endl;
        cout << "��ǰͨѶ¼�����£�" << endl;
        show(list);
    }
    static void deleteContact(vector<Contact> &list)
    {
        if (list.empty())
        {
            cout << "��ϵ��Ϊ�գ��޷�ɾ��" << endl;
        }
        else
        {
            cout << "��ǰͨѶ¼�����£�" << endl;
            show(list);
            cout << "������Ҫɾ������ϵ�˵�����" << endl;
            string deletename;
            cin >> deletename;
            int index = getIndex(list, deletename);
            if (index == -1)
            {
                cout << "����ϵ�˲����ڣ��޷�ɾ��" << endl;
            }
            else
            {
                list.erase(list.begin() + index);
                cout << "����Ϊ" << deletename << "����ϵ��ɾ���ɹ���" << endl;
            }
            cout << "��ǰͨѶ¼�����£�" << endl;
            show(list);
        }
    }
    static void show(const vector<Contact> &list)
    {
        if (list.empty())
        {
            cout << "��ǰ������ϵ�ˣ�����Ӻ�����ʾ��ϵ���б�" << endl;
            return;
        }
        else
        {
            cout << "���" << "\t" << "��ϵ��" << "\t" << "�绰����" << endl;
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
            cout << "��ѡ����ҷ�ʽ��" << endl;
            cout << "1.ͨ����ϵ�����ֲ���" << endl;
            cout << "2.ͨ����ϵ�˵绰����" << endl;
            cout << "����������ѡ��" << endl;
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
                cout << "û�и�ѡ��Ŷ������������" << endl;
                continue;
            }
            }
            break;
        }
    }
    static void headcount(const vector<Contact> &list)
    {
        cout << "ͨѶ¼��һ����" << list.size() << "��" << endl;
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
        cout << "��������Ҫ���ҵ�����" << endl;
        string needname;
        cin >> needname;
        for (const auto &contact : list)
        {
            if (contact.getName() == needname)
            {
                cout << "���ҳɹ�" << endl;
                cout << contact.getName() << "\t" << contact.getPhonenumber() << endl;
                return true;
            }
        }
        cout << "ͨѶ¼�����޸���ϵ��" << endl;
        return false;
    }
    static bool searchNumber(const vector<Contact> &list)
    {
        cout << "��������Ҫ���ҵĺ���" << endl;
        string neednum;
        cin >> neednum;
        for (const auto &contact : list)
        {
            if (contact.getPhonenumber() == neednum)
            {
                cout << "���ҳɹ�" << endl;
                cout << contact.getName() << "\t" << contact.getPhonenumber() << endl;
                return true;
            }
        }
        cout << "ͨѶ¼�����޸õ绰" << endl;
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
