//
//  main.cpp
//  Ekzamen
//
//  Created by Pavel Ronaldo on 6/10/20.
//  Copyright © 2020 Pavel. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Server
{
private:
    string ip;
    unsigned short port;
public:
    Server();
    Server(string ip, unsigned short port);
    ~Server();
    void setIP(string ip){
        this->ip = ip;
    }
    void setPort(unsigned short port){
        this->port = port;
    }

    string getIP(){
        return ip;
    }

    unsigned short getPort(){
        return port;
    }
};

Server::Server(string ip, unsigned short port)
{
    this->ip = ip;
    this->port = port;
}

Server::Server()
{
    this->ip = "localhost";
    this->port = 8800;
}

Server::~Server()
{

}

class Rack : public Server
{
private:
    
public:
    Rack();
    Rack(string ip, unsigned short port);
    ~Rack();
};

Rack::Rack(string ip, unsigned short port) : Server(ip, port)
{
}

Rack::Rack(/* args */) : Server()
{
}

Rack::~Rack()
{
}

class DataCenter
{
private:
    vector<Rack> servers;
public:
    DataCenter(int serversCount);
    DataCenter();
    void addServer(string ip, unsigned short port);
    void removeServer(int idx);
    void getServerInformation(int idx);
    int getServersCount(){
        return servers.size();
    }
    Rack getServer(int pos){
        return servers[pos];
    }
    ~DataCenter();
};

DataCenter::DataCenter(int serversCount)
{
    servers.reserve(serversCount);
}

DataCenter::DataCenter()
{
    servers.reserve(1);
}

DataCenter::~DataCenter()
{
}

void DataCenter::addServer(string ip, unsigned short port){
    this->servers.push_back(Rack(ip, port));
}
void DataCenter::removeServer(int idx){
    this->servers.erase(servers.begin() + idx);
}
void DataCenter::getServerInformation(int idx){
    cout << "IP: " << servers[idx].getIP() << endl;
    cout << "Port: " << servers[idx].getPort() << endl;
}

class Company
{
private:
    vector<DataCenter> centers;
public:
    Company();
    ~Company();
    DataCenter & operator [](int pos){
        return centers[pos];
    }

};

Company::Company(/* args */)
{
    DataCenter center;
    centers.push_back(center);
}

Company::~Company()
{
}




int main(int argc, char const *argv[])
{
    Company company;
    company[0].addServer("localhost", 8800);
    company[0].addServer("128.0.0.1", 8800);
    company[0].addServer("168.0.0.1", 8800);
    company[0].getServerInformation(0);
    company[0].getServerInformation(1);
    company[0].getServerInformation(2);
    return 0;
}
