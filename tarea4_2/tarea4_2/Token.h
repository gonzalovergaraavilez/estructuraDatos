//
//  Token.h
//  tarea4_2
//
//  Created by Gonzalo Vergara on 3/29/15.
//  Copyright (c) 2015 Gonzalo Vergara. All rights reserved.
//

#ifndef tarea4_2_Token_h
#define tarea4_2_Token_h
#include "CircularLinkedList.h"

class Token {
    std::string status = "Free"; //Free (No messages sent), Sent (Message sent, not yet received by recipient), Received (Recipient got message, sender hasn't freed the token)
    int from = 0;
    int to = 0;
    int current = 0;
    std::string message = "";
    
public:
    Token() {}
    virtual ~Token();

    Token(std::string _status, int _from, int _to, int _current, std::string _message) : status(_status), from(_from), to(_to), current(_current), message(_message) {}
    
    std::string getStatus() const { return status; }
    int getFrom() const { return from; }
    int getTo() const { return to; }
    int getCurrent() const { return current; }
    std::string getMessage() const { return message; }
    
    void setStatus(std::string value) { status = value; }
    void setFrom(int value) { from = value; }
    void setTo(int value) { to = value; }
    void setCurrent(int value) { current = value; }
    void setMessage(std::string value) { message = value; }
    
    template <class T>
    bool send(int _from, int _to, std::string _message, CircularLinkedList<T> *clist);
    
    friend std::ostream & operator << (std::ostream & os, Token  & token);
    
};

Token::~Token()
{
    from = 0;
    status = "Free";
    to = 0;
    current = 0;
    message = "";
}

template <class T>
bool Token::send(int _from, int _to, std::string _message, CircularLinkedList<T> *clist){
    Node<T> * tmp = clist->find(_to);
    if (tmp == nullptr){
        return false;
    }
    tmp = clist->find(_from);
    if (tmp == nullptr){
        return false;
    }
    
    this->setCurrent(_from);
    this->setStatus("Sent");
    this->setFrom(_from);
    this->setTo(_to);
    this->setMessage(_message);
        
    do {
        if(_to==tmp->getInfo()){
            this->setStatus("Received");
        }
        this->setCurrent(tmp->getInfo());
        std::cout << *this;
        tmp = tmp->getNext();

    } while (this->status == "Sent");
    
    do {
        if(_from==tmp->getInfo()){
            this->setStatus("Free");
        }
        this->setCurrent(tmp->getInfo());
        std::cout << *this;
        tmp = tmp->getNext();
        
    } while (this->status == "Received");
    return true;
}

std::ostream & operator << (std::ostream & os, Token & token)
{
    os << "From: " << token.from << ", ";
    os << "To: " << token.to << ", ";
    os << "Current: " << token.current << ", ";
    os << "Message: " << token.message << ", ";
    os << "Token status: " << token.status << std::endl;
    
    return os;
}


#endif
