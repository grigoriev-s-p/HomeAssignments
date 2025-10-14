/*
	 * Sergey Grigoriev
 * st142081@student.spbu.ru
 * Assignment 2a
*/

#include"assignment2a.h"

#include<iostream>
#include<string>
#include<fstream>
#include<filesystem>
void myproject::solution(){
    std::ifstream binfile;
    binfile.open("source.pdf", std::ios::binary|std::ios::in);
    std::uintmax_t size = std::filesystem::file_size("source.pdf");
    char* buffer=new char[size];
    binfile.read(buffer,size);
    std::cout<<std::endl<<"------------"<<std::endl;
    for(int i=0;i<size/2;i++){
        char temp=buffer[i];
        buffer[i]=buffer[size-1-i];
        buffer[size-1-i]=temp;
    }
    std::ofstream file;
    file.open("temppdf.pdf",std::ios::binary|std::ios::out);
    file.write(buffer,size);
    binfile.close();
    file.close();
    delete[] buffer;
}
