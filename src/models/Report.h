#ifndef REPORT_H
#define REPORT_H
#include <iostream>
using namespace std;

class Report {
  protected:
    int id = 0;
    int meeting_id;
    string content;

  public:
    // Constructor
    Report() {};
    Report(const int &nid, const int &nmeeting_id, const string &ncontent)
        : id(nid), meeting_id(nmeeting_id), content(ncontent) {}

    // Getters
    int getId() const { return id; }
    int getMeetingId() const { return meeting_id; }
    string getContent() const { return content; }

    // Setters
    void setId(const int &newId) { id = newId; }
    void setMeetingId(const int &newMeetingId) { meeting_id = newMeetingId; }
    void setContent(const string &newContent) { content = newContent; }

    void show() { cout << "Report, Id: " << id << " ,meeting_id: " << meeting_id << " ,content: " << content << endl; }
};

#endif
