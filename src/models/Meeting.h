#ifndef MEETING_H
#define MEETING_H
#include <iostream>
using namespace std;

class Meeting {
  protected:
    int id = 0;
    int teacher_id;
    string status;
    string type;
    string start;
    string end;
    string date;

  public:
    // Constructor
    Meeting() {};
    Meeting(const int &nteacher_id, const string &nstatus, const string &ntype, const string &nstart,
            const string &nend, const string &ndate)
        : teacher_id(nteacher_id), status(nstatus), type(ntype), start(nstart), end(nend), date(ndate) {}

    // Getter
    int getId() const { return id; }
    int getTeacherId() const { return teacher_id; }
    string getStatus() const { return status; }
    string getType() const { return type; }
    string getStart() const { return start; }
    string getEnd() const { return end; }
    string getDate() const { return date; }

    // Setter
    void setId(const int &newId) { id = newId; }
    void setTeacherId(const int &newTeacherId) { teacher_id = newTeacherId; }
    void setStatus(const string &newStatus) { status = newStatus; }
    void setType(const string &newType) { type = newType; }
    void setStart(const string &newStart) { start = newStart; }
    void setEnd(const string &newEnd) { end = newEnd; }
    void setDate(const string &newDate) { date = newDate; }

    void show() {
        cout << "Meeting, Id: " << id << " ,teacher_id: " << teacher_id << " ,status: " << status << " ,type: " << type
             << " ,start: " << start << " ,end: " << end << " ,date: " << date << endl;
    }
};

#endif
