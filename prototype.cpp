#include <iostream>
using namespace std;

// abstract prototype //
class IMessage {
public:
    virtual IMessage* clone() const = 0;
    virtual void show() const = 0;
    virtual ~IMessage() = default;
};

// concrete prototype//
class HelloMessage : public IMessage {
private:
    string text;
public:
    HelloMessage(const string& t) : text(t) {}

    IMessage* clone() const override {
        return new HelloMessage(text);
    }

    void show() const override {
        cout << "Message: " << text << endl;
    }
};

int main() {
    HelloMessage original("Hello, world!");
    IMessage* copy = original.clone();

    original.show();
    copy->show();

    delete copy;
    return 0;
}