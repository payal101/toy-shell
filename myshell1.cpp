#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<fstream>

std::vector<std::string> _splitByPipe(const std::string& input)
{
    std::vector<std::string>parts;
    std::stringstream ss(input);
    std::string segment;
    while(std::getline(ss,segment,'|'))
    {
size_t start= segment.find_first_not_of("\t");
size_t end= segment.find_last_not_of("\t");
if(start !=std::string ::npos)
{
    parts.push_back(segment.substr(start,end-start +1));

}

    }
    return parts;
}
int main()
{
    std::string input;
    while(true)
    {
        std::cout<<"myshell> ";
        std::getline(std::cin,input);
        if(input.empty())
        {
            continue;
        }
        if(input=="exit")
        {
            std::cout<<"Exiting myshell"<<std::endl;
            break;
        }

    }
    auto commands=_splitByPipe(input);
    if(commands.size()==1)
    {
        int ret= system(commands[0].c_str());
        if(ret!=0)
        {
            std::cerr<<"Command failed"<<"std::endl";
        }
    }
    else if(commands.size()==2)
    {
        FILE* pipe=_popen(commands[0].c_str(),"r");
        if(!pipe)
        {
            std::cerr<<"Failed to open pipe for "<<commands[0]<<std::endl;
            continue;
        }
        char buffer[256];
        std::string output;
        while(fgets(buffer,sizeof(buffer),pipe)!=nullptr)
        {
            output+=buffer;
        }
        _pclose(pipe);

        std::string tempFile="pipe_temp.txt";
        std::ofstream out(tempFile);
        out<<output;
        out.close();
 
        std::string nextCmd=commands[1]+ " < "+ tempFile;
        int ret=system(nextCmd.c_str());
        if(ret!=0)
        {
            std::cerr<<"Command Failed"<<commands[1]<<std::endl;
        }
        std::remove(tempFile.c_str());
    else
        {
        std::cerr<<"Currently only supports one pipe (two commands)"<<std::endl;
    }
    }
   return 0;



}

