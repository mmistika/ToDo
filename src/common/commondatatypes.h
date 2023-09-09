#ifndef COMMONDATATYPES_H
#define COMMONDATATYPES_H

#include <vector>

#include <QString>

namespace Common
{
struct Task
{
    enum class State
    {
        Incompleted,
        Completed
    };

    int id;
    State state;
    QString text;
    bool isImportant;
    QString dueDate;
    int groupId;
};

using TaskList = std::vector<Task>;

struct Group
{
    int id;
    QString title;
};

using GroupList = std::vector<Group>;

struct Tag
{
    int id;
    QString title;
};

using TagList = std::vector<Tag>;
}

#endif // COMMONDATATYPES_H
