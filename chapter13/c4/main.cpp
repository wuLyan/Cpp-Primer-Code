#include "Message.h"
#include "Folder.h"

Message::Message(const Message &msg) : 
    contents(msg.contents), folders(msg.folders)
{
    add_to_Folders(msg);
}

Message::~Message()
{
    remove_from_Folders();
}

void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(this);
}

Message &Message::operator=(const Message &rhs)
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message &msg)
{
    for (auto f : msg.folders)
        f->addMsg(this);
}

void Message::remove_from_Folders()
{
    for (auto f : folders)
        f->remMsg(this);
}

void swap(Message &lhs, Message &rhs)
{
    using std::swap;
    for (auto f : lhs.folders)
        f->remMsg(&lhs);
    for (auto f : rhs.folders)
        f->remMsg(&rhs);
    swap(lhs.contents, rhs.contents);
    swap(lhs.folders, rhs.folders);
    for (auto f : lhs.folders)
        f->addMsg(&lhs);
    for (auto f : rhs.folders)
        f->addMsg(&rhs);
}

Folder::Folder(const Folder &f) : msgs(f.msgs)
{
    add_to_Messages(f);
}

Folder &Folder::operator=(const Folder &f)
{
    remove_from_Msgs();
    msgs = f.msgs;
    add_to_Messages(f);
    return *this;
}

Folder::~Folder()
{
    remove_from_Msgs();
}

void Folder::add_to_Messages(const Folder &f)
{
    for (auto msg : msgs)
        msg->addFldr(this);
}

void Folder::remove_from_Msgs()
{
    while (!msgs.empty())
        (*msgs.begin())->remove(*this);
}

int main()
{
    return 0;
}