#pragma once

class Test {
    protected:

    Stream* stream;

    public:

    virtual void setup();
    virtual void loop();

    void setOutStream(Stream* printout) {
        this->stream = stream;
    }
};