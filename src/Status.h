// File: Status.h
#ifndef STATUS_H
#define STATUS_H

enum class Status {
    SUCCESS = 0,
    USER_NOT_FOUND = 1,
    WRONG_PASSWORD = 2,
    USERNAME_EXISTS = 3,
    DATABASE_ERROR = 4,
    CONNECTION_FAILED = 5,
    TIME_SLOT_CONFLICT = 6,
    UNAUTHORIZED = 7,
    UNKNOWN_ERROR = 99
};

#endif
