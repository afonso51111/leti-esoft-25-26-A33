#ifndef HTTPRESULT_H
#define HTTPRESULT_H

#include <string>

enum HttpStatus {
    HTTP_OK = 200,
    HTTP_CREATED = 201,
    HTTP_BAD_REQUEST = 400,
    HTTP_NOT_FOUND = 404,
    HTTP_SERVER_ERROR = 500
};

class HttpResult {
private:
    int status;
    std::string body;

public:
    HttpResult() : status(HTTP_OK), body("") {}

    void setHttpStatus(int s) { status = s; }
    void setResult(std::string res) { body = res; }

    int getStatus() const { return status; }
    std::string getBody() const { return body; }
};

#endif