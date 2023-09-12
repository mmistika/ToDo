#ifndef IDATABASE_H
#define IDATABASE_H

#include "../../../common/commondatatypes.h"

template <typename T>
struct DBResult
{
    bool success;
    T result;
};

class IDatabase
{
public:
    IDatabase(const QString &databaseName);
    virtual ~IDatabase();

public:
    // Database connection management methods
    virtual DBResult<void> openConnection();
    virtual DBResult<void> closeConnection();

    // Transaction management methods
    virtual DBResult<void> transaction();
    virtual DBResult<void> commit();

    // Task operations (CRUD)
    virtual DBResult<void> createTask(const Common::Task &task);
    virtual DBResult<Common::Task> getTask(int id);
    virtual DBResult<Common::TaskList> getAllTasks();
    virtual DBResult<void> updateTaskState(int id, Common::Task::State state, bool isImportant);
    virtual DBResult<void> updateTaskText(int id, const QString &text);
    virtual DBResult<void> updateTaskDueDate(int id, const QString &date);
    virtual DBResult<void> deleteTask(int id);

    // Group operations (CRUD)
    virtual DBResult<void> createGroup(const Common::Group &group);
    virtual DBResult<Common::Group> getGroup(int id);
    virtual DBResult<Common::GroupList> getGroups();
    virtual DBResult<void> updateGroup(int id, const Common::Group &group);
    virtual DBResult<void> deleteGroup(int id);

    // Tag operations (CRUD)
    virtual DBResult<void> createTag(const Common::Tag &tag);
    virtual DBResult<Common::Tag> getTag(int id);
    virtual DBResult<Common::TagList> getTags();
    virtual DBResult<void> updateTag(int id, const Common::Tag &tag);
    virtual DBResult<void> deleteTag(int id);

    // Misc queries
    virtual DBResult<void> addTaskToGroup(int taskId, int groupId);
    virtual DBResult<void> updateTaskTags(int id, const Common::TagList &tags);
    virtual DBResult<Common::TaskList> getTasksByDueDate(const QString &date);
    virtual DBResult<Common::TaskList> getTasksWithNoDueDate();
    virtual DBResult<Common::TaskList> getTasksWithDueDate();
    virtual DBResult<Common::TaskList> getImportantTasks();
    virtual DBResult<Common::TaskList> getTasksInGroup(int groupId);
};

#endif // IDATABASE_H
